#include <avr/io.h>

#include "sound.h"
#include "metronome.h"
#include "spi.h"
#include "display.h"
#include "led.h"
#include "controls.h"
#include "menu.h"

#include "timer.h"
#include "util.h"

struct mtrnm_s gl_mtrnm_p = {0};
struct ctrl_s gl_ctrl_p = {0};

uint64_t balls = 0;
void nothing( void ) {
  return;
}


int main( void ) {
  cli( );

  gl_ctrl_p.ctrl_enc_btn_clbk = menu_forward_item;
  gl_ctrl_p.ctrl_enc_a_btn_clbk = menu_forward_item;
  gl_ctrl_p.ctrl_enc_b_btn_clbk = menu_back_item;

  gl_ctrl_p.ctrl_btn0_clbk = nothing;
  gl_ctrl_p.ctrl_btn1_clbk = mtrnm_reset;

  CLKPR = ( 1 << CLKPCE );
  CLKPR = 0;

  spi_init( );
  sound_init( );
  led_init( );
  display_init( );
  controls_init( );

  mtrnm_start( );

  gl_mtrnm_p.beep_ms = 5;

  gl_mtrnm_p.freq_strong = 3135;
  gl_mtrnm_p.freq_weak = 1661;
  gl_mtrnm_p.freq_subdiv = 440;

  gl_mtrnm_p.subdivs = 4; // 8 max

  gl_mtrnm_p.swing_en = 0; // subdiv must be odd
  gl_mtrnm_p.accent_en = 1;

  gl_mtrnm_p.beats = 4;

  gl_mtrnm_p.target_bpm = MTRNM_MAX_BPM;
  gl_mtrnm_p.start_bpm = gl_mtrnm_p.active_bpm = 120;

  gl_mtrnm_p.inc_bar = 1;
  gl_mtrnm_p.inc_bpm = 5;

  gl_mtrnm_p.mode = MTRNM_MODE_CONST;

timer_start( );
  sei( );

  while( 1 ) {
    menu_tick( );
    /*
    char t[4];
    dig_itoa16(t, (uint16_t)(timer_get_ms( )) );
    display_set_digs( t, 4 );
    display_tick( );
    */
  }

  return 0;
}

