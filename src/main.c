#include <avr/io.h>
#include <util/delay.h>

#include "sound.h"
#include "metronome.h"
#include "spi.h"
#include "display.h"
#include "led.h"
#include "controls.h"
#include "menu.h"
#include "timer.h"
#include "eeprom.h"
#include "notes.h"
#include "taptempo.h"

volatile struct mtrnm_p_s gl_mtrnm_p = {
  .beep_ms = DFLT_BEEP_MS,

  .note_strong = DFLT_STRONG_NOTE,
  .note_weak = DFLT_WEAK_NOTE,
  .note_subdiv = DFLT_SUBDIV_NOTE,

  .beats = DFLT_BEATS,
  .subdivs = DFLT_SUBDIVS,

  .swing_en = DFLT_SWING_EN,
  .accent_en = DFLT_ACC_EN,
  .cntdwn_en = DFLT_CNTDWND_EN,
  .led_en = DFLT_LED_EN,

  .target_bpm = 260,
  .start_bpm = 120,

  .active_bpm = 260,

  .inc_bar = DFLT_INC_BAR,
  .inc_bpm = DFLT_INC_BPM,

  .mode = MTRNM_MODE_CONST,
};

volatile struct ctrl_s gl_ctrl_p = {
  .ctrl_enc_a_clbk = menu_rot_right,
  .ctrl_enc_b_clbk = menu_rot_left,

  .ctrl_enc_btn_clbk = menu_btn,

  .ctrl_enc_a_btn_clbk = menu_rot_right_pushed,
  .ctrl_enc_b_btn_clbk = menu_rot_left_pushed,

  .ctrl_btn0_clbk = menu_forward_item,
  .ctrl_btn1_clbk = tap,
  .ctrl_btn2_clbk = menu_backward_item,

  .ctrl_btn012_clbk = menu_change_mode_sett,

  .ctrl_swt_on_clkb = menu_change_mode_main,
  .ctrl_swt_off_clkb = menu_change_mode_prog,
};

void powerloss_clbk( void ) {
  cli( );
  mtrnm_stop( );
  eeprom_save_mtrnm_set( );
}

int main( void ) {
  cli( );

  CLKPR = ( 1 << CLKPCE );
  CLKPR = 0;

  spi_init( );
  sound_init( );
  //led_init( );
  display_init( );

  timer_start( );
  mtrnm_start( );

  //eeprom_load_mtrnm_set( );

  //ctrl_init( );

  sei( );

  while( 1 ) { // happens about every 12-13ms
    menu_tick( );
  }

  return 0;
}
