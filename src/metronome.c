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
  TCCR1B = 0;
}

static double bpm2ms( double bpm ) {
  return 60000 / bpm;
}

static void mtrnm_set_period( double ms ) {
  TCNT1 = 65535 - ms * F_CPU / 1024 / 1000; // set output compare register
}

void mtrnm_reset( void ) {
  gl_mtrnm_p.cur_beat = 0;
  gl_mtrnm_p.cur_subdiv = 0;
  gl_mtrnm_p.cur_bar = 0;
  gl_mtrnm_p.state = STRONG_BEAT_START;
  mtrnm_stop( );
  mtrnm_start( );
}

static void mtrnm_calc_next_bpm( ) {

  if( gl_mtrnm_p.mode == MTRNM_MODE_PROG ) {

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
  }

  gl_mtrnm_p.cur_bar++;
}

ISR( TIMER1_OVF_vect ) {

  gl_mtrnm_p.beat_ms = bpm2ms( gl_mtrnm_p.active_bpm * gl_mtrnm_p.subdiv );

  switch( gl_mtrnm_p.state ) {
    case STRONG_BEAT_START:
      mtrnm_calc_next_bpm( );

      sound_set_freq( gl_mtrnm_p.accent_en ? gl_mtrnm_p.freq_strong : gl_mtrnm_p.freq_weak );
      sound_start( );

      led_set( 0, 1 );
      led_set( 1, 1 );
      led_set( 2, 1 );

      gl_mtrnm_p.cur_beat = 1;
      gl_mtrnm_p.cur_subdiv = 1;

      mtrnm_set_period( gl_mtrnm_p.beep_ms );
      gl_mtrnm_p.state = BEAT_END;
      break;

    case WEAK_BEAT_START:
      sound_set_freq( gl_mtrnm_p.freq_weak );
      sound_start( );

      led_set( 1, 1 );

      // Do not trigger subdiv LED if no subdivision is used
      if( gl_mtrnm_p.subdiv > 1 )
        led_set( 2, 1 );

      gl_mtrnm_p.cur_subdiv = 1;

      mtrnm_set_period( gl_mtrnm_p.beep_ms );
      gl_mtrnm_p.state = BEAT_END;
      break;

    case SUBDIV_BEAT_START:
      gl_mtrnm_p.cur_subdiv++;

      if( gl_mtrnm_p.swing_en ) {
        if( gl_mtrnm_p.cur_subdiv == 1 || gl_mtrnm_p.cur_subdiv == gl_mtrnm_p.subdiv ) {

          sound_set_freq( gl_mtrnm_p.freq_subdiv );
          sound_start( );

          led_set( 2, 1 );
        }

      } else {
        sound_set_freq( gl_mtrnm_p.freq_subdiv );
        sound_start( );

        led_set( 2, 1 );
      }

      mtrnm_set_period( gl_mtrnm_p.beep_ms );
      gl_mtrnm_p.state = BEAT_END;
      break;

    case BEAT_END:
      sound_stop( );

      led_set( 0, 0 );
      led_set( 1, 0 );
      led_set( 2, 0 );

      mtrnm_set_period( gl_mtrnm_p.beat_ms - gl_mtrnm_p.beep_ms );

      if( gl_mtrnm_p.subdiv > 1 && gl_mtrnm_p.cur_subdiv < gl_mtrnm_p.subdiv ) {
        gl_mtrnm_p.state = SUBDIV_BEAT_START;

      }
      else if( gl_mtrnm_p.cur_beat == gl_mtrnm_p.beats ) {
        gl_mtrnm_p.cur_beat = 1;
        gl_mtrnm_p.state = STRONG_BEAT_START;
      }
      else {
        gl_mtrnm_p.cur_beat++;
        gl_mtrnm_p.state = WEAK_BEAT_START;
      }
      break;

    default:
      break;
  }

}


