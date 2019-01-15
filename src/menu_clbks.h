static void (*resets[MENU_CNT])(void) = {
  [MENU_MAIN] = mtrnm_reset_const,
  [MENU_PROG] = mtrnm_reset_prog,
  [MENU_SETT] = mtrnm_reset_sett
};

// Setting
void menu_active_bpm_inc( void ) {
  if( gl_mtrnm_p.active_bpm < MTRNM_MAX_BPM ) gl_mtrnm_p.active_bpm++;
  gl_mtrnm_p.start_bpm = gl_mtrnm_p.active_bpm;
}

void menu_active_bpm_dec( void ) {
  if( gl_mtrnm_p.active_bpm > MTRNM_MIN_BPM ) gl_mtrnm_p.active_bpm--;
  gl_mtrnm_p.start_bpm = gl_mtrnm_p.active_bpm;
}

void menu_inc_bpm_inc( void ) {
  if( gl_mtrnm_p.inc_bpm < MTRNM_MAX_BPM ) gl_mtrnm_p.inc_bpm++;
}

void menu_inc_bpm_dec( void ) {
  if( gl_mtrnm_p.inc_bpm > 1 ) gl_mtrnm_p.inc_bpm--;
}

void menu_inc_bar_inc( void ) {
  if( gl_mtrnm_p.inc_bar < MTRNM_MAX_BEATS ) gl_mtrnm_p.inc_bar++;
}

void menu_inc_bar_dec( void ) {
  if( gl_mtrnm_p.inc_bar > MTRNM_MIN_BEATS ) gl_mtrnm_p.inc_bar--;
}

void menu_target_bpm_inc( void ) {
  if( gl_mtrnm_p.target_bpm < MTRNM_MAX_BPM ) gl_mtrnm_p.target_bpm++;
}

void menu_target_bpm_dec( void ) {
  if( gl_mtrnm_p.target_bpm > MTRNM_MIN_BPM ) gl_mtrnm_p.target_bpm--;
}

void menu_beat_inc( void ) {
  if( gl_mtrnm_p.beats < MTRNM_MAX_BEATS ) gl_mtrnm_p.beats++;
}

void menu_beat_dec( void ) {
  if( gl_mtrnm_p.beats > MTRNM_MIN_BEATS ) gl_mtrnm_p.beats--;
}

void menu_subdivs_inc( void ) {
  if( gl_mtrnm_p.subdivs < MTRNM_MAX_SUBDIVS ) gl_mtrnm_p.subdivs++;
}

void menu_subdivs_dec( void ) {
  if( gl_mtrnm_p.subdivs > MTRNM_MIN_SUBDIVS ) gl_mtrnm_p.subdivs--;
}

void menu_toggle_accent( void ) {
  gl_mtrnm_p.accent_en = gl_mtrnm_p.accent_en ? 0 : 1;
}

void menu_toggle_swing( void ) {
  gl_mtrnm_p.swing_en = gl_mtrnm_p.swing_en ? 0 : 1;
}

void menu_toggle_cntdwn( void ) {
  gl_mtrnm_p.cntdwn_en = gl_mtrnm_p.cntdwn_en ? 0 : 1;
}

void menu_toggle_led( void ) {
  gl_mtrnm_p.led_en = gl_mtrnm_p.led_en ? 0 : 1;
}

void menu_note_weak_inc( void ) {
  if( gl_mtrnm_p.note_weak < NOTES_CNT - 1 ) gl_mtrnm_p.note_weak++;
}

void menu_note_weak_dec( void ) {
  if( gl_mtrnm_p.note_weak > 0 ) gl_mtrnm_p.note_weak--;
}

void menu_note_strong_inc( void ) {
  if( gl_mtrnm_p.note_strong < NOTES_CNT - 1 ) gl_mtrnm_p.note_strong++;
}

void menu_note_strong_dec( void ) {
  if( gl_mtrnm_p.note_strong > 0 ) gl_mtrnm_p.note_strong--;
}

void menu_note_subdiv_inc( void ) {
  if( gl_mtrnm_p.note_subdiv < NOTES_CNT - 1 ) gl_mtrnm_p.note_subdiv++;
}

void menu_note_subdiv_dec( void ) {
  if( gl_mtrnm_p.note_subdiv > 0 ) gl_mtrnm_p.note_subdiv--;
}

void menu_beep_ms_inc( void ) {
  if( gl_mtrnm_p.beep_ms < MTRNM_MAX_BEEP_MS ) gl_mtrnm_p.beep_ms++;
}

void menu_beep_ms_dec( void ) {
  if( gl_mtrnm_p.beep_ms > MTRNM_MIN_BEEP_MS ) gl_mtrnm_p.beep_ms--;
}

// Printing
void menu_print_tempo( void ) {

  // t. for tempo prefix
  output_buf[0] = 't';
  output_buf[1] = '.';

  dig_itoa16( dig_buf, gl_mtrnm_p.active_bpm );
  output_buf[2] = dig_buf[1];
  output_buf[3] = dig_buf[2];
  output_buf[4] = dig_buf[3];

  output_len = 5;
}

void menu_print_beats( void ) {

  if( gl_mtrnm_p.beats > 9 || gl_mtrnm_p.cur_beat > 9 ) {
    dig_itoa16( dig_buf, gl_mtrnm_p.beats );
    output_buf[0] = dig_buf[2];
    output_buf[1] = dig_buf[3];
    output_buf[2] = '.';

    dig_itoa16( dig_buf, gl_mtrnm_p.cur_beat );
    output_buf[3] = dig_buf[2];
    output_buf[4] = dig_buf[3];

    output_len = 5;
  } else {
    output_buf[0] = 'b'; // beat
    output_buf[1] = '.';
    output_buf[2] = ' ';

    dig_itoa16( dig_buf, gl_mtrnm_p.beats );
    output_buf[3] = dig_buf[3];
    output_buf[4] = '.';

    dig_itoa16( dig_buf, gl_mtrnm_p.cur_beat );
    output_buf[5] = dig_buf[3];

    output_len = 6;
  }
}

void menu_print_subdivs( void ) {

  output_buf[0] = 'S'; // division
  output_buf[1] = 'd';
  output_buf[2] = '.';

  dig_itoa16( dig_buf, gl_mtrnm_p.subdivs );
  output_buf[3] = dig_buf[3];
  output_buf[4] = '.';

  dig_itoa16( dig_buf, gl_mtrnm_p.cur_subdiv );
  output_buf[5] = dig_buf[3];

  output_len = 6;
}

void menu_print_accent( void ) {

  output_buf[0] = 'A'; // accent
  output_buf[1] = 'c';
  output_buf[2] = 'c';
  output_buf[3] = '.';

  dig_itoa16( dig_buf, gl_mtrnm_p.accent_en );
  output_buf[4] = dig_buf[3];

  output_len = 5;
}

void menu_print_swing( void ) {

  output_buf[0] = gl_mtrnm_p.subdivs % 2 == 0 ? 'd' : ' '; // to somehow indicate tuplet
  output_buf[1] = gl_mtrnm_p.subdivs % 2 == 0 && gl_mtrnm_p.swing_en ? ' ' : 'd';
  output_buf[2] = gl_mtrnm_p.swing_en ? ' ' : 'd';
  output_buf[3] = 'd';

  output_len = 4;
}

void print_cntdw_prog( void ) {
  dig_itoa16( dig_buf, gl_mtrnm_p.cur_cntdwn );
  output_buf[0] = '-';
  output_buf[1] = dig_buf[1];
  output_buf[2] = dig_buf[2];
  output_buf[3] = dig_buf[3];

  output_len = 4;
}

void menu_print_led_sett( void ) {

  dig_itoa16( dig_buf, gl_mtrnm_p.led_en );
  output_buf[0] = 'L';
  output_buf[1] = 'e';
  output_buf[2] = 'd';
  output_buf[3] = '.';
  output_buf[4] = dig_buf[3];

  output_len = 5;
}
void menu_print_start_prog( void ) {

  if( gl_mtrnm_p.cur_cntdwn ) {
    print_cntdw_prog( );
    return;
  }

  dig_itoa16( dig_buf, gl_mtrnm_p.active_bpm );
  output_buf[0] = dig_buf[1];
  output_buf[1] = dig_buf[2];
  output_buf[2] = dig_buf[3];
  output_buf[3] = '-';

  output_len = 4;
}

void menu_print_end_prog( void ) {

  if( gl_mtrnm_p.cur_cntdwn ) {
    print_cntdw_prog( );
    return;
  }

  dig_itoa16( dig_buf, gl_mtrnm_p.target_bpm );
  output_buf[0] = '-';
  output_buf[1] = dig_buf[1];
  output_buf[2] = dig_buf[2];
  output_buf[3] = dig_buf[3];

  output_len = 4;
}

void menu_print_inc_bpm_prog( void ) {

  if( gl_mtrnm_p.cur_cntdwn ) {
    print_cntdw_prog( );
    return;
  }

  if( gl_mtrnm_p.inc_bpm < 99 ) {
    output_buf[0] = '-'; // bar

    dig_itoa16( dig_buf, gl_mtrnm_p.inc_bpm );
    output_buf[1] = dig_buf[2];
    output_buf[2] = dig_buf[3];

    output_buf[3] = '-';

    output_len = 4;
  } else {

    dig_itoa16( dig_buf, gl_mtrnm_p.inc_bpm );
    output_buf[0] = ' ';
    output_buf[1] = dig_buf[1];
    output_buf[2] = dig_buf[2];
    output_buf[3] = dig_buf[3];

  }
}

void menu_print_inc_bar_prog( void ) {

  if( gl_mtrnm_p.cur_cntdwn ) {
    print_cntdw_prog( );
    return;
  }

  if( gl_mtrnm_p.inc_bar > 9 || gl_mtrnm_p.cur_bar > 9 ) {
    dig_itoa16( dig_buf, gl_mtrnm_p.inc_bar );
    output_buf[0] = dig_buf[2];
    output_buf[1] = dig_buf[3];
    output_buf[2] = '.';

    dig_itoa16( dig_buf, gl_mtrnm_p.cur_bar );
    output_buf[3] = dig_buf[2];
    output_buf[4] = dig_buf[3];

    output_len = 5;
  } else {
    output_buf[0] = '|'; // like a bar on a music sheet

    dig_itoa16( dig_buf, gl_mtrnm_p.inc_bar );
    output_buf[1] = dig_buf[3];
    output_buf[2] = '.';

    dig_itoa16( dig_buf, gl_mtrnm_p.cur_bar );
    output_buf[3] = dig_buf[3];
    output_buf[4] = '1';

    output_len = 5;
  }
}

void print_cntdw_en_prog( void ) {

  if( gl_mtrnm_p.cur_cntdwn ) {
    print_cntdw_prog( );
    return;
  }

  output_buf[0] = 'C';
  output_buf[1] = 'n';
  output_buf[2] = 't';
  output_buf[3] = '.';

  dig_itoa16( dig_buf, gl_mtrnm_p.cntdwn_en );
  output_buf[4] = dig_buf[3];

  output_len = 5;
}

void menu_print_strong_note_sett( void ) {

  note2string( dig_buf, gl_mtrnm_p.note_strong );
  output_buf[0] = '1';
  output_buf[1] = '.';
  output_buf[2] = dig_buf[0];
  output_buf[3] = dig_buf[1];
  output_buf[4] = dig_buf[2];

  output_len = 5;
}

void menu_print_weak_note_sett( void ) {

  note2string( dig_buf, gl_mtrnm_p.note_weak );
  output_buf[0] = '2';
  output_buf[1] = '.';
  output_buf[2] = dig_buf[0];
  output_buf[3] = dig_buf[1];
  output_buf[4] = dig_buf[2];

  output_len = 5;
}

void menu_print_subdiv_note_sett( void ) {

  note2string( dig_buf, gl_mtrnm_p.note_subdiv );
  output_buf[0] = '3';
  output_buf[1] = '.';
  output_buf[2] = dig_buf[0];
  output_buf[3] = dig_buf[1];
  output_buf[4] = dig_buf[2];

  output_len = 5;
}

void menu_print_beep_ms_sett( void ) {

  dig_itoa16( dig_buf, gl_mtrnm_p.beep_ms );
  output_buf[0] = 'b'; // as in beep ms
  output_buf[1] = '.';
  output_buf[2] = ' ';
  output_buf[3] = dig_buf[2];
  output_buf[4] = dig_buf[3];

  output_len = 5;
}

void menu_main_entry( void ) {
  mtrnm_change_mode( MTRNM_MODE_CONST );
}

void menu_prog_entry( void ) {
  mtrnm_change_mode( MTRNM_MODE_PROG );
}
