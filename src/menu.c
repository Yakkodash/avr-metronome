#include "menu.h"
#include "metronome.h"
#include "display.h"
#include "util.h"
#include "controls.h"
#include "notes.h"
#include <stddef.h>

static char output_buf[MENU_OUTPUT_BUF_LEN];
static char dig_buf[MENU_OUTPUT_DIG_LEN];
static uint8_t output_len = 0;

static uint8_t cur_item = 0;
static menu_type_t cur_menu = 0;

#include "menu_clbks.h"

static const menu_item_t menu_main_items[] = {
  { .right_clbk = menu_active_bpm_inc,  .left_clbk = menu_active_bpm_dec, .print_clbk = menu_print_tempo   },
  { .right_clbk = menu_beat_inc,        .left_clbk = menu_beat_dec,       .print_clbk = menu_print_beats   },
  { .right_clbk = menu_subdivs_inc,     .left_clbk = menu_subdivs_dec,    .print_clbk = menu_print_subdivs },
  { .right_clbk = menu_toggle_swing,    .left_clbk = menu_toggle_swing,   .print_clbk = menu_print_swing   },
  { .right_clbk = menu_toggle_accent,   .left_clbk = menu_toggle_accent,  .print_clbk = menu_print_accent  },
  { 0 }
};

static const menu_item_t menu_prog_items[] = {
  { .right_clbk = menu_active_bpm_inc,  .left_clbk = menu_active_bpm_dec, .print_clbk = menu_print_start_prog     },
  { .right_clbk = menu_target_bpm_inc,  .left_clbk = menu_target_bpm_dec, .print_clbk = menu_print_end_prog       },
  { .right_clbk = menu_inc_bpm_inc,     .left_clbk = menu_inc_bpm_dec,    .print_clbk = menu_print_inc_bpm_prog   },
  { .right_clbk = menu_inc_bar_inc,     .left_clbk = menu_inc_bar_dec,    .print_clbk = menu_print_inc_bar_prog   },
  { .right_clbk = menu_toggle_cntdwn,   .left_clbk = menu_toggle_cntdwn,  .print_clbk = print_cntdw_en_prog       },
  { 0 }
};

static const menu_item_t menu_sett_items[] = {
  { .right_clbk = menu_note_strong_inc,  .left_clbk = menu_note_strong_dec, .print_clbk = menu_print_strong_note_sett  },
  { .right_clbk = menu_note_weak_inc,    .left_clbk = menu_note_weak_dec,   .print_clbk = menu_print_weak_note_sett    },
  { .right_clbk = menu_note_subdiv_inc,  .left_clbk = menu_note_subdiv_dec, .print_clbk = menu_print_subdiv_note_sett  },
  { .right_clbk = menu_beep_ms_inc,      .left_clbk = menu_beep_ms_dec,     .print_clbk = menu_print_beep_ms_sett      },
  { .right_clbk = menu_toggle_led,       .left_clbk = menu_toggle_led,      .print_clbk = menu_print_led_sett          },
  { 0 }
};

static const menu_t menus[] = {
  [MENU_MAIN] =
  { 
    .items = menu_main_items, 
    .do_on_entry_clbk = menu_main_entry, 
    .do_on_exit_clbk = NULL, 
    .do_on_btn_clbk = mtrnm_reset_const 
  },

  [MENU_PROG] =
  { 
    .items = menu_prog_items, 
    .do_on_entry_clbk = menu_prog_entry, 
    .do_on_exit_clbk = NULL, 
    .do_on_btn_clbk = mtrnm_reset_prog 
  },

  [MENU_SETT] =
  { 
    .items = menu_sett_items, 
    .do_on_entry_clbk = NULL, 
    .do_on_exit_clbk = NULL, 
    .do_on_btn_clbk = mtrnm_reset_sett 
  }
};

void menu_forward_item( void ) {
  if( menus[cur_menu].items[cur_item + 1].right_clbk == 0 ) cur_item = 0;
  else cur_item++;
}

void menu_backward_item( void ) {
  if( cur_item == 0 ) {
    // Getting total number of menu items
    while( menus[cur_menu].items[cur_item].right_clbk != 0 ) cur_item++;
  }
  cur_item--; // to get proper item index

}

void menu_change_menu( menu_type_t m ) {
  if( menus[cur_menu].do_on_exit_clbk != NULL ) menus[cur_menu].do_on_exit_clbk( );
  cur_menu = m;
  cur_item = 0;
  if( menus[cur_menu].do_on_entry_clbk != NULL ) menus[cur_menu].do_on_entry_clbk( );
}

void menu_forward_menu( void ) {
  if( cur_menu == MENU_CNT - 1 ) menu_change_menu( 0 );
  else menu_change_menu( cur_menu++ );
};

void menu_tick( void ) {
  gl_ctrl_p.ctrl_enc_a_clbk = menus[cur_menu].items[cur_item].right_clbk;
  gl_ctrl_p.ctrl_enc_b_clbk = menus[cur_menu].items[cur_item].left_clbk;
  gl_ctrl_p.ctrl_btn2_clbk = menus[cur_menu].do_on_btn_clbk;

  menus[cur_menu].items[cur_item].print_clbk( );

  display_set_chars( output_buf, output_len );
  display_tick( );
   /* uint8_t enc_1 = PIND & _BV( PD1 );
    uint8_t enc_2 = PIND & _BV( PD2 );
    uint8_t enc_3 = PIND & _BV( PD3 );
    uint32_t a = enc_1 | enc_2 << 1 | enc_3 <<2;
    dig_itoa16( output_buf, enc_1 | enc_2 | enc_3 );
    display_set_chars( output_buf, 4 );
    display_tick( );*/
}
