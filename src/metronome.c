#include <avr/interrupt.h>

#include "metronome.h"
#include "sound.h"
#include "led.h"
#include "display.h"

void mtrnm_start( void ) {
  TCCR1B |= _BV( CS12 ) | _BV( CS10 ); // prescaler 1024 selected
  TIMSK1 |= _BV( TOIE1 ); // enable Timer overflow interrupt
  TCNT1 = 65535;
}

void mtrnm_stop( void ) {
  led_set( 0, 0 );
  led_set( 1, 0 );
  led_set( 2, 0 );
  sound_stop( );
  TCCR1B = 0;
}

static double bpm2ms( double bpm ) {
  return 60e3 / bpm;
}

static void mtrnm_set_period( double ms ) {
  TCNT1 = 65535 - ms * F_CPU / 1024 / 1000; // set output compare register
}

void mtrnm_change_mode( uint8_t mode ) {
  if( mode == MTRNM_MODE_CONST ) {
    gl_mtrnm_p.active_bpm = gl_mtrnm_p.start_bpm;
  }
  gl_mtrnm_p.mode = mode;
}

static void mtrnm_reset( void ) {
  gl_mtrnm_p.active_bpm = gl_mtrnm_p.start_bpm;
  gl_mtrnm_p.cur_beat = 0;
  gl_mtrnm_p.cur_subdiv = 0;
  gl_mtrnm_p.cur_bar = 0;
  gl_mtrnm_p.state = STRONG_BEAT_START;
}

void mtrnm_reset_const( void ) {
  mtrnm_stop( );
  mtrnm_reset( );
  mtrnm_start( );
}

void mtrnm_reset_prog( void ) {
  mtrnm_stop( );
  mtrnm_reset( );
  if( gl_mtrnm_p.cntdwn_en && gl_mtrnm_p.mode == MTRNM_MODE_PROG ) {
    gl_mtrnm_p.cntdwn_en = 1;
    gl_mtrnm_p.cur_cntdwn = gl_mtrnm_p.beats + 1;
  }
  mtrnm_start( );

}

void mtrnm_reset_sett( void ) {
  gl_mtrnm_p.beep_ms = DFLT_BEEP_MS;
  gl_mtrnm_p.note_strong = DFLT_STRONG_NOTE;
  gl_mtrnm_p.note_weak = DFLT_WEAK_NOTE;
  gl_mtrnm_p.note_subdiv = DFLT_SUBDIV_NOTE;
  gl_mtrnm_p.led_en = DFLT_LED_EN;
  gl_mtrnm_p.cntdwn_en = DFLT_CNTDWND_EN;
}

static void mtrnm_calc_next_bpm( ) {

  if( gl_mtrnm_p.cur_bar % gl_mtrnm_p.inc_bar == 0 && gl_mtrnm_p.cur_bar ) {
    if( gl_mtrnm_p.active_bpm > gl_mtrnm_p.target_bpm ) {
      gl_mtrnm_p.active_bpm -= gl_mtrnm_p.inc_bpm;
      if( gl_mtrnm_p.active_bpm < gl_mtrnm_p.target_bpm ) gl_mtrnm_p.active_bpm = gl_mtrnm_p.target_bpm;
    }

    else if( gl_mtrnm_p.active_bpm < gl_mtrnm_p.target_bpm ) {
      gl_mtrnm_p.active_bpm += gl_mtrnm_p.inc_bpm;
      if( gl_mtrnm_p.active_bpm > gl_mtrnm_p.target_bpm ) gl_mtrnm_p.active_bpm = gl_mtrnm_p.target_bpm;
    }

    gl_mtrnm_p.cur_bar = 0;
  }

  gl_mtrnm_p.cur_bar++;

}

ISR( TIMER1_OVF_vect ) {

  sound_stop( );

  if( gl_mtrnm_p.mode == MTRNM_MODE_CONST ) gl_mtrnm_p.cur_cntdwn = 0;
  if( gl_mtrnm_p.cur_cntdwn && gl_mtrnm_p.state != BEAT_END ) {
    gl_mtrnm_p.beat_ms = bpm2ms( gl_mtrnm_p.start_bpm  );
    gl_mtrnm_p.state = STRONG_BEAT_START;
    gl_mtrnm_p.cur_cntdwn--;
  } else if( !gl_mtrnm_p.cur_cntdwn ) {
    gl_mtrnm_p.beat_ms = bpm2ms( gl_mtrnm_p.active_bpm * gl_mtrnm_p.subdivs );
  }

  switch( gl_mtrnm_p.state ) {
    case STRONG_BEAT_START:
      if( !gl_mtrnm_p.cur_cntdwn ) {
        if( gl_mtrnm_p.mode == MTRNM_MODE_PROG )
          mtrnm_calc_next_bpm( );
      }

      sound_start( note2freq( gl_mtrnm_p.accent_en ? gl_mtrnm_p.note_strong : gl_mtrnm_p.note_weak ) );

      if( gl_mtrnm_p.led_en ) {
        if( gl_mtrnm_p.accent_en ) led_set( 0, 1 );
        led_set( 1, 1 );
        if( gl_mtrnm_p.accent_en || gl_mtrnm_p.subdivs > 1 ) led_set( 2, 1 );
      }

      gl_mtrnm_p.cur_beat = 1;
      gl_mtrnm_p.cur_subdiv = 1;

      mtrnm_set_period( gl_mtrnm_p.beep_ms );
      gl_mtrnm_p.state = BEAT_END;
      break;

    case WEAK_BEAT_START:
      gl_mtrnm_p.cur_beat++;

      sound_start( note2freq( gl_mtrnm_p.note_weak ) );

      if( gl_mtrnm_p.led_en ) {
        led_set( 1, 1 );

        // Do not trigger subdiv LED if no subdivision is used
        if( gl_mtrnm_p.subdivs > 1 )
          led_set( 2, 1 );
      }

      gl_mtrnm_p.cur_subdiv = 1;

      mtrnm_set_period( gl_mtrnm_p.beep_ms );
      gl_mtrnm_p.state = BEAT_END;
      break;

    case SUBDIV_BEAT_START:
      gl_mtrnm_p.cur_subdiv++;

      if( gl_mtrnm_p.swing_en ) {
        if( gl_mtrnm_p.cur_subdiv == 1 || gl_mtrnm_p.cur_subdiv == gl_mtrnm_p.subdivs ) {

          sound_start( note2freq( gl_mtrnm_p.note_subdiv ) );

          if( gl_mtrnm_p.led_en ) led_set( 2, 1 );
        }

      } else {
        sound_start( note2freq( gl_mtrnm_p.note_subdiv ) );

        if( gl_mtrnm_p.led_en ) led_set( 2, 1 );
      }

      mtrnm_set_period( gl_mtrnm_p.beep_ms );
      gl_mtrnm_p.state = BEAT_END;
      break;

    case BEAT_END:
      sound_stop( );

      if( gl_mtrnm_p.led_en ) {
        led_set( 0, 0 );
        led_set( 1, 0 );
        led_set( 2, 0 );
      }

      mtrnm_set_period( gl_mtrnm_p.beat_ms - gl_mtrnm_p.beep_ms );

      if( gl_mtrnm_p.subdivs > 1 && gl_mtrnm_p.cur_subdiv < gl_mtrnm_p.subdivs ) {
        gl_mtrnm_p.state = SUBDIV_BEAT_START;
      }
      else if( gl_mtrnm_p.cur_beat >= gl_mtrnm_p.beats ) {
        gl_mtrnm_p.state = STRONG_BEAT_START;
      }
      else {
        gl_mtrnm_p.state = WEAK_BEAT_START;
      }
      break;

    default:
      break;
  }

}
