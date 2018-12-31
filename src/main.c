#include <avr/interrupt.h>
#include <util/delay.h>

#include "sound.h"
#include "metronome.h"
#include "spi.h"
#include "display.h"
#include "led.h"

struct mtrnm_s gl_mtrnm_p   = {0};

ISR( INT0_vect ) {
  mtrnm_reset( );
}	

int main( void ) {
  cli( );

  CLKPR = ( 1 << CLKPCE );
  CLKPR = 0;

  spi_init( );
  sound_init( );
  mtrnm_start( );
  led_init( );
  display_init( );

  gl_mtrnm_p.beep_ms = 5;

  gl_mtrnm_p.strong_freq = 3135;
  gl_mtrnm_p.weak_freq = 1661;
  gl_mtrnm_p.subdiv_freq = 440;

  gl_mtrnm_p.subdiv = 1; // 8 max
  
  gl_mtrnm_p.swing = 0; // subdiv must be 3
  gl_mtrnm_p.accent_en = 1;

  gl_mtrnm_p.beats = 4;

  gl_mtrnm_p.bpm = 60;

  gl_mtrnm_p.cur_bpm = 200;
  gl_mtrnm_p.target_bpm = MTRNM_MAX_BPM;
  gl_mtrnm_p.inc_bar = 1;
  gl_mtrnm_p.inc_bpm = 5;

  gl_mtrnm_p.mode = MTRNM_PROGRESSIVE;

	DDRD &= ~( 1<<PD2 );		// Set PD2 as input (Using for interupt INT0)
	PORTD |= 1<<PD2;		// Enable PD2 pull-up resistor

	EIMSK |= 1<<INT0;					// Enable INT0
  EICRA |= _BV( ISC01 ); 

  sei( );

  while( 1 ) {
    display_loop( );
  }

  return 0;
}

