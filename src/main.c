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
#include "adc.h"
#include "powerloss.h"
#include "notes.h"

volatile struct mtrnm_p_s gl_mtrnm_p = {0};
volatile struct ctrl_s gl_ctrl_p = {0};

static void change_mode_main( void ) {
  mtrnm_change_mode( MTRNM_MODE_CONST );
  menu_change_menu( MENU_MAIN );
}

static void change_mode_prog( void ) {
  mtrnm_change_mode( MTRNM_MODE_PROG );
  menu_change_menu( MENU_PROG );
}

void nothing( void ) {}

static void init_dflt_mtrnm( void ) {

  gl_mtrnm_p.beep_ms = MTRNM_MIN_BEEP_MS;

  gl_mtrnm_p.note_strong = G7;
  gl_mtrnm_p.note_weak = Ab6;
  gl_mtrnm_p.note_subdiv = A4;

  gl_mtrnm_p.beats = 4;
  gl_mtrnm_p.subdivs = 1;

  gl_mtrnm_p.swing_en = 0;
  gl_mtrnm_p.accent_en = 1;
  gl_mtrnm_p.cntdwn_en = 1;
  gl_mtrnm_p.led_en = 1;

  gl_mtrnm_p.target_bpm = 260;
  gl_mtrnm_p.start_bpm = gl_mtrnm_p.active_bpm = 120;

  gl_mtrnm_p.inc_bar = 1;
  gl_mtrnm_p.inc_bpm = 5;

  gl_mtrnm_p.mode = MTRNM_MODE_CONST;
}

static void init_ctrl_clbks( void ) {
  gl_ctrl_p.ctrl_enc_btn_clbk = menu_forward_item;
  gl_ctrl_p.ctrl_enc_a_btn_clbk = menu_forward_item;
  gl_ctrl_p.ctrl_enc_b_btn_clbk = menu_back_item;
  gl_ctrl_p.ctrl_btn1_long_clbk = nothing; // smol button

  gl_ctrl_p.ctrl_btn0_clbk = nothing; // big button

  gl_ctrl_p.ctrl_swt_off_clkb = change_mode_main;
  gl_ctrl_p.ctrl_swt_on_clkb = change_mode_prog;
}

int main( void ) {
  cli( );

  CLKPR = ( 1 << CLKPCE );
  CLKPR = 0;

  adc_init( );
  spi_init( );
  sound_init( );
  led_init( );
  display_init( );
  powerloss_detect_init( eeprom_save_mtrnm_set );

  timer_start( );
  mtrnm_start( );

  init_dflt_mtrnm( );

  eeprom_load_mtrnm_set( );

  //init_ctrl_clbks( );
  //controls_init( );

  sei( );

  while( 1 ) { // happens about every 12-13ms
#ifndef DISABLE_EEPROM
    if( powerloss_detect_tick( ) ) break;
#endif
    menu_tick( );
    //if( timer_get_ms( ) - gl_ctrl_p.btn_tim >= 2000 && gl_ctrl_p.btn_pressed ) 
    //  gl_ctrl_p.ctrl_btn1_long_clbk( );
  }

  return 0;
}
