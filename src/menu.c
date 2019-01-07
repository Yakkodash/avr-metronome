#include "menu.h"
#include "metronome.h"
#include "display.h"
#include "util.h"
#include "controls.h"

#define MENU_ITEMS_CNT 5

static char output_buf[8];
static char dig_buf[4];
static uint8_t output_len = 0;

static uint8_t cur_item_buf = 1;
static uint8_t cur_item = 0;

#include "menu_clbks.h"

static menu_item_t main_menu[MENU_ITEMS_CNT] = {
  { .menu_enc_left_clbk = menu_bpm_inc,       .menu_enc_rigth_clbk = menu_bpm_dec,        .menu_print_clbk = menu_print_tempo   },
  { .menu_enc_left_clbk = menu_beat_inc,      .menu_enc_rigth_clbk = menu_beat_dec,       .menu_print_clbk = menu_print_beats   },
  { .menu_enc_left_clbk = menu_subdivs_inc,   .menu_enc_rigth_clbk = menu_subdivs_dec,    .menu_print_clbk = menu_print_subdivs },
  { .menu_enc_left_clbk = menu_toggle_accent, .menu_enc_rigth_clbk = menu_toggle_accent,  .menu_print_clbk = menu_print_accent  },
  { .menu_enc_left_clbk = menu_toggle_swing,  .menu_enc_rigth_clbk = menu_toggle_swing,   .menu_print_clbk = menu_print_swing   },
};

void menu_forward_item( void ) {
  if( cur_item == MENU_ITEMS_CNT - 1 ) cur_item = 0;
  else cur_item++;
}

void menu_back_item( void ) {
  if( cur_item == 0 ) cur_item = MENU_ITEMS_CNT - 1;
  else cur_item--;
}

void menu_tick( void ) {
  if( cur_item != cur_item_buf ) {
    cur_item_buf = cur_item;
    gl_ctrl_p.ctrl_enc_a_clbk = main_menu[cur_item_buf].menu_enc_left_clbk;
    gl_ctrl_p.ctrl_enc_b_clbk = main_menu[cur_item_buf].menu_enc_rigth_clbk;
  }
  main_menu[cur_item].menu_print_clbk( );
  display_set_digs( output_buf, output_len );
  display_tick( );
}
