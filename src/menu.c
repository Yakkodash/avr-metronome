#include "menu.h"
#include "metronome.h"
#include "display.h"
#include "util.h"
#include "controls.h"
#include "notes.h"
#include "eeprom.h"

#define MENU_MAIN_ITEMS_CNT 5

static char output_buf[8];
static char dig_buf[4];
static uint8_t output_len = 0;

static uint8_t cur_item = 0;
static menu_t cur_menu = 0;

#include "menu_clbks.h"

#define MENU_MAIN_LEN 5
#define MENU_PROG_LEN 5
#define MENU_SETT_LEN 5

static const uint8_t menu_len[MENU_CNT] = {
  [MENU_MAIN] = MENU_MAIN_LEN,
  [MENU_PROG] = MENU_PROG_LEN,
  [MENU_SETT] = MENU_SETT_LEN
};

static menu_item_t menu_main[MENU_MAIN_LEN] = {
  { .menu_rigth_clbk = menu_active_bpm_inc,  .menu_left_clbk = menu_active_bpm_dec, .menu_print_clbk = menu_print_tempo   },
  { .menu_rigth_clbk = menu_beat_inc,        .menu_left_clbk = menu_beat_dec,       .menu_print_clbk = menu_print_beats   },
  { .menu_rigth_clbk = menu_subdivs_inc,     .menu_left_clbk = menu_subdivs_dec,    .menu_print_clbk = menu_print_subdivs },
  { .menu_rigth_clbk = menu_toggle_swing,    .menu_left_clbk = menu_toggle_swing,   .menu_print_clbk = menu_print_swing   },
  { .menu_rigth_clbk = menu_toggle_accent,   .menu_left_clbk = menu_toggle_accent,  .menu_print_clbk = menu_print_accent  },
};

static menu_item_t menu_prog[MENU_PROG_LEN] = {
  { .menu_rigth_clbk = menu_active_bpm_inc,  .menu_left_clbk = menu_active_bpm_dec, .menu_print_clbk = menu_print_start_prog    },
  { .menu_rigth_clbk = menu_target_bpm_inc,  .menu_left_clbk = menu_target_bpm_dec, .menu_print_clbk = menu_print_end_prog      },
  { .menu_rigth_clbk = menu_inc_bpm_inc,     .menu_left_clbk = menu_inc_bpm_dec,    .menu_print_clbk = menu_print_inc_bpm_prog  },
  { .menu_rigth_clbk = menu_inc_bar_inc,     .menu_left_clbk = menu_inc_bar_dec,    .menu_print_clbk = menu_print_inc_bar_prog  },
  { .menu_rigth_clbk = menu_toggle_cntdwn,   .menu_left_clbk = menu_toggle_cntdwn,  .menu_print_clbk = menu_print_cntdw_en_prog },
};

static menu_item_t menu_sett[MENU_SETT_LEN] = {
  { .menu_rigth_clbk = menu_note_strong_inc,  .menu_left_clbk = menu_note_strong_dec, .menu_print_clbk = menu_print_strong_note_sett  },
  { .menu_rigth_clbk = menu_note_weak_inc,    .menu_left_clbk = menu_note_weak_dec,   .menu_print_clbk = menu_print_weak_note_sett    },
  { .menu_rigth_clbk = menu_note_subdiv_inc,  .menu_left_clbk = menu_note_subdiv_dec, .menu_print_clbk = menu_print_subdiv_note_sett  },
  { .menu_rigth_clbk = menu_beep_ms_inc,      .menu_left_clbk = menu_beep_ms_dec,     .menu_print_clbk = menu_print_beep_ms_sett      },
  { .menu_rigth_clbk = menu_toggle_led,       .menu_left_clbk = menu_toggle_led,      .menu_print_clbk = menu_print_led_sett          },
};

static const menu_item_t *menus[MENU_CNT] = {
  [MENU_MAIN] = menu_main,
  [MENU_PROG] = menu_prog,
  [MENU_SETT] = menu_sett
};

void menu_do_on_sett_exit( ) {
  eeprom_save_sound_set( );
}

void menu_forward_item( void ) {
  if( cur_item == menu_len[cur_menu] - 1 ) cur_item = 0;
  else cur_item++;
}

void menu_back_item( void ) {
  if( cur_item == 0 ) cur_item = MENU_MAIN_ITEMS_CNT - 1;
  else cur_item--;
}

void menu_change_menu( menu_t m ) {
  if( m != MENU_SETT && cur_menu == MENU_SETT ) menu_do_on_sett_exit( );

  cur_menu = m;
  cur_item = 0;
}

void menu_forward_menu( void ) {
  if( cur_menu == MENU_SETT ) menu_do_on_sett_exit( );

  if( cur_menu == MENU_CNT - 1 ) cur_menu = 0;
  else cur_menu++;
  cur_item = 0;
};

void menu_tick( void ) {
  gl_ctrl_p.ctrl_enc_a_clbk = menus[cur_menu][cur_item].menu_rigth_clbk;
  gl_ctrl_p.ctrl_enc_b_clbk = menus[cur_menu][cur_item].menu_left_clbk;
  gl_ctrl_p.ctrl_btn1_short_clbk = resets[cur_menu];
  menus[cur_menu][cur_item].menu_print_clbk( );

  display_set_digs( output_buf, output_len );
  display_tick( );
}
