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

uint16_t pwr_adc_val = 0;

inline static void change_mode_main( void ) {
  menu_change_menu( MENU_MAIN );
}

inline static void change_mode_prog( void ) {
  menu_change_menu( MENU_PROG );
}

volatile struct mtrnm_p_s gl_mtrnm_p = {
  .beep_ms = MTRNM_MIN_BEEP_MS,

  .note_strong = G7,
  .note_weak = Ab6,
  .note_subdiv = A4,

  .beats = 4,
  .subdivs = 1,

  .swing_en = 0,
  .accent_en = 1,
  .cntdwn_en = 1,
  .led_en = 1,

  .target_bpm = 260,
  .start_bpm = 120,
  .active_bpm = 120,

  .inc_bar = 1,
  .inc_bpm = 5,

  .mode = MTRNM_MODE_CONST,
};

volatile struct ctrl_s gl_ctrl_p = {
  .ctrl_enc_a_clbk = NULL,
  .ctrl_enc_b_clbk = NULL,
  .ctrl_enc_btn_clbk = menu_forward_item,

  .ctrl_enc_a_btn_clbk = menu_forward_item,
  .ctrl_enc_b_btn_clbk = menu_backward_item,

  .ctrl_btn1_clbk = menu_forward_item,

  .ctrl_btn2_clbk = menu_backward_item,

  .ctrl_swt_on_clkb = change_mode_main,
  .ctrl_swt_off_clkb = change_mode_prog,
};

void powerloss_clbk( void ) {
  cli( );
  for( uint8_t i = 0; i < LED_NUM; i++ ) led_set( i, 0 );
  //eeprom_save_mtrnm_set( );
}

#if 1
#include "util.h"
#endif

int main( void ) {
  cli( );

  CLKPR = ( 1 << CLKPCE );
  CLKPR = 0;

  adc_init( );
  spi_init( );
  sound_init( );
  led_init( );
  display_init( );
  powerloss_detect_init( powerloss_clbk );

  timer_start( );
  mtrnm_start( );

  //eeprom_load_mtrnm_set( );

  ctrl_init( );

  sei( );

  char output_buf[4];
  while( 1 ) { // happens about every 12-13ms
    if( powerloss_detect_tick() ) break; // try to die gracefully
    char output_buf1[4];
    dig_itoa16(output_buf1, 1);
  display_set_chars( output_buf1, 4 );
  display_tick( );

  //  menu_tick( );
  }

  return 0;
}
