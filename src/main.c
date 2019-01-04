#include <avr/io.h>

#include "sound.h"
#include "metronome.h"
#include "spi.h"
#include "display.h"
#include "led.h"
#include "controls.h"
#include "menu.h"

struct mtrnm_s gl_mtrnm_p = {0};
struct ctrl_s gl_ctrl_p = {0};

void inc( void ) {
  if( gl_mtrnm_p.active_bpm < MTRNM_MAX_BPM ) gl_mtrnm_p.active_bpm++;
}

void dec( void ) {
  if( gl_mtrnm_p.active_bpm > MTRNM_MIN_BPM ) gl_mtrnm_p.active_bpm--;
}

void chng_mode( void ) {
  gl_mtrnm_p.mode = gl_mtrnm_p.mode == MTRNM_MODE_CONST ? MTRNM_MODE_PROG : MTRNM_MODE_CONST;
}

int main( void ) {
  cli( );

  gl_ctrl_p.ctrl_enc_a_callback = inc;
  gl_ctrl_p.ctrl_enc_b_callback = dec;

  gl_ctrl_p.ctrl_enc_btn_callback = chng_mode;
  gl_ctrl_p.ctrl_btn1_callback = mtrnm_reset;

  CLKPR = ( 1 << CLKPCE );
  CLKPR = 0;

  spi_init( );
  sound_init( );
  mtrnm_start( );
  led_init( );
  display_init( );
  controls_init( );

  gl_mtrnm_p.beep_ms = 5;

  gl_mtrnm_p.freq_strong = 3135;
  gl_mtrnm_p.freq_weak = 1661;
  gl_mtrnm_p.freq_subdiv = 440;

  gl_mtrnm_p.subdiv = 4; // 8 max

  gl_mtrnm_p.swing_en = 0; // subdiv must be odd
  gl_mtrnm_p.accent_en = 1;

  gl_mtrnm_p.beats = 4;

  gl_mtrnm_p.active_bpm = MTRNM_MIN_BPM;
  gl_mtrnm_p.target_bpm = MTRNM_MAX_BPM;
  gl_mtrnm_p.inc_bar = 1;
  gl_mtrnm_p.inc_bpm = 5;

  gl_mtrnm_p.mode = MTRNM_MODE_CONST;

  sei( );

  while( 1 ) {
    menu_fsm( );
    display_loop( );
  }

  return 0;
}

