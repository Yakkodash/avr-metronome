#include <stdio.h>

// Setting
void menu_active_bpm_inc( void ) {
  if( gl_mtrnm_p.active_bpm < MTRNM_MAX_BPM ) gl_mtrnm_p.active_bpm++;
  gl_mtrnm_p.start_bpm = gl_mtrnm_p.active_bpm;
}

void menu_active_bpm_inc_fast( void ) {
  if( gl_mtrnm_p.active_bpm < MTRNM_MAX_BPM ) gl_mtrnm_p.active_bpm += 10;
  if( gl_mtrnm_p.active_bpm > MTRNM_MAX_BPM ) gl_mtrnm_p.active_bpm = MTRNM_MAX_BPM;
  gl_mtrnm_p.start_bpm = gl_mtrnm_p.active_bpm;
}

void menu_active_bpm_dec( void ) {
  if( gl_mtrnm_p.active_bpm > MTRNM_MIN_BPM ) gl_mtrnm_p.active_bpm--;
  gl_mtrnm_p.start_bpm = gl_mtrnm_p.active_bpm;
}

void menu_active_bpm_dec_fast( void ) {
  if( gl_mtrnm_p.active_bpm > MTRNM_MIN_BPM ) gl_mtrnm_p.active_bpm -= 10;
  if( gl_mtrnm_p.active_bpm < MTRNM_MIN_BPM ) gl_mtrnm_p.active_bpm = MTRNM_MIN_BPM;
    gl_mtrnm_p.start_bpm = gl_mtrnm_p.active_bpm;
}

void menu_inc_bpm_inc( void ) {
  if( gl_mtrnm_p.inc_bpm < MTRNM_MAX_BPM ) gl_mtrnm_p.inc_bpm++;
}

void menu_inc_bpm_inc_fast( void ) {
  if( gl_mtrnm_p.inc_bpm < MTRNM_MAX_BPM ) gl_mtrnm_p.inc_bpm += 10;
  if( gl_mtrnm_p.inc_bpm > MTRNM_MAX_BPM ) gl_mtrnm_p.inc_bpm = MTRNM_MAX_BPM;
}

void menu_inc_bpm_dec( void ) {
  if( gl_mtrnm_p.inc_bpm > 1 ) gl_mtrnm_p.inc_bpm--;
}

void menu_inc_bpm_dec_fast( void ) {
  if( gl_mtrnm_p.inc_bpm > 1 ) gl_mtrnm_p.inc_bpm -= 10;
  if( gl_mtrnm_p.inc_bpm > MTRNM_MAX_BPM || gl_mtrnm_p.inc_bpm < MTRNM_MIN_BPM ) 
    gl_mtrnm_p.inc_bpm = 1;
}

void menu_inc_bar_inc( void ) {
  if( gl_mtrnm_p.inc_bar < MTRNM_MAX_BEATS ) gl_mtrnm_p.inc_bar++;
}

void menu_inc_bar_inc_fast( void ) {
  if( gl_mtrnm_p.inc_bar < MTRNM_MAX_BEATS ) gl_mtrnm_p.inc_bar += 4;
  if( gl_mtrnm_p.inc_bar > MTRNM_MAX_BEATS ) gl_mtrnm_p.inc_bar = MTRNM_MAX_BEATS;
}

void menu_inc_bar_dec( void ) {
  if( gl_mtrnm_p.inc_bar > MTRNM_MIN_BEATS ) gl_mtrnm_p.inc_bar--;
}

void menu_inc_bar_dec_fast( void ) {
  if( gl_mtrnm_p.inc_bar > MTRNM_MIN_BEATS ) gl_mtrnm_p.inc_bar -= 4;
  if( gl_mtrnm_p.inc_bar < MTRNM_MIN_BEATS || gl_mtrnm_p.inc_bar > MTRNM_MAX_BEATS ) 
    gl_mtrnm_p.inc_bar = MTRNM_MIN_BEATS;
}

void menu_target_bpm_inc( void ) {
  if( gl_mtrnm_p.target_bpm < MTRNM_MAX_BPM ) gl_mtrnm_p.target_bpm++;
}

void menu_target_bpm_inc_fast( void ) {
  if( gl_mtrnm_p.target_bpm < MTRNM_MAX_BPM ) gl_mtrnm_p.target_bpm += 10;
  if( gl_mtrnm_p.target_bpm > MTRNM_MAX_BPM ) gl_mtrnm_p.target_bpm = MTRNM_MAX_BPM;
}

void menu_target_bpm_dec( void ) {
  if( gl_mtrnm_p.target_bpm > MTRNM_MIN_BPM ) gl_mtrnm_p.target_bpm--;
}

void menu_target_bpm_dec_fast( void ) {
  if( gl_mtrnm_p.target_bpm > MTRNM_MIN_BPM ) gl_mtrnm_p.target_bpm -= 10;
  if( gl_mtrnm_p.target_bpm < MTRNM_MIN_BPM || gl_mtrnm_p.target_bpm > MTRNM_MAX_BPM ) 
    gl_mtrnm_p.target_bpm = MTRNM_MIN_BPM;
}

void menu_beat_inc( void ) {
  if( gl_mtrnm_p.beats < MTRNM_MAX_BEATS ) gl_mtrnm_p.beats++;
}

void menu_beat_inc_fast( void ) {
  if( gl_mtrnm_p.beats < MTRNM_MAX_BEATS ) gl_mtrnm_p.beats += 4;
  if( gl_mtrnm_p.beats > MTRNM_MAX_BEATS ) gl_mtrnm_p.beats = MTRNM_MAX_BEATS;
}

void menu_beat_dec( void ) {
  if( gl_mtrnm_p.beats > MTRNM_MIN_BEATS ) gl_mtrnm_p.beats--;
}

void menu_beat_dec_fast( void ) {
  if( gl_mtrnm_p.beats > MTRNM_MIN_BEATS ) gl_mtrnm_p.beats -= 4;
  if( gl_mtrnm_p.beats < MTRNM_MIN_BEATS || gl_mtrnm_p.beats > MTRNM_MAX_BEATS ) 
    gl_mtrnm_p.beats = MTRNM_MIN_BEATS;
}

void menu_subdivs_inc( void ) {
  if( gl_mtrnm_p.subdivs < MTRNM_MAX_SUBDIVS ) gl_mtrnm_p.subdivs++;
}

void menu_subdivs_inc_fast( void ) {
  if( gl_mtrnm_p.subdivs < MTRNM_MAX_SUBDIVS ) gl_mtrnm_p.subdivs += 3;
  if( gl_mtrnm_p.subdivs > MTRNM_MAX_SUBDIVS ) gl_mtrnm_p.subdivs = MTRNM_MAX_SUBDIVS;
}

void menu_subdivs_dec( void ) {
  if( gl_mtrnm_p.subdivs > MTRNM_MIN_SUBDIVS ) gl_mtrnm_p.subdivs--;
}

void menu_subdivs_dec_fast( void ) {
  if( gl_mtrnm_p.subdivs > MTRNM_MIN_SUBDIVS ) gl_mtrnm_p.subdivs -= 3;
  if( gl_mtrnm_p.subdivs < MTRNM_MIN_SUBDIVS || gl_mtrnm_p.subdivs > MTRNM_MAX_SUBDIVS ) 
    gl_mtrnm_p.subdivs = MTRNM_MIN_SUBDIVS;
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
  sprintf( output_buf, "t.%3d", gl_mtrnm_p.active_bpm );
}

void menu_print_beats( void ) {
  if( gl_mtrnm_p.beats > 9 || gl_mtrnm_p.cur_beat > 9 ) {
    sprintf( output_buf, "%2d.%2d", gl_mtrnm_p.beats, gl_mtrnm_p.cur_beat );
  } else {
    sprintf( output_buf, "b. %d.%d", gl_mtrnm_p.beats, gl_mtrnm_p.cur_beat );
  }
}

void menu_print_subdivs( void ) {
  sprintf( output_buf, "Sd.%d.%d", gl_mtrnm_p.subdivs, gl_mtrnm_p.cur_subdiv );
}

void menu_print_accent( void ) {
  sprintf( output_buf, "Acc.%d", gl_mtrnm_p.accent_en );
}

void menu_print_swing( void ) {
  sprintf( output_buf, "%s%s%sd", 
  gl_mtrnm_p.subdivs % 2 == 0 ? "d" : " ",
  gl_mtrnm_p.subdivs % 2 == 0 && gl_mtrnm_p.swing_en ? " " : "d",
  gl_mtrnm_p.swing_en ? " " : "d" );
}

void print_cntdw_prog( void ) {
  sprintf( output_buf, "%4d", -gl_mtrnm_p.cur_cntdwn );
}

void menu_print_led_sett( void ) {
  sprintf( output_buf, "Led.%d", gl_mtrnm_p.led_en );
}

void menu_print_start_prog( void ) {

  if( gl_mtrnm_p.cur_cntdwn ) {
    print_cntdw_prog( );
    return;
  }

  sprintf( output_buf, "%3d-", gl_mtrnm_p.active_bpm );
}

void menu_print_end_prog( void ) {

  if( gl_mtrnm_p.cur_cntdwn ) {
    print_cntdw_prog( );
    return;
  }

  sprintf( output_buf, "-%3d", gl_mtrnm_p.target_bpm );
}

void menu_print_inc_bpm_prog( void ) {

  if( gl_mtrnm_p.cur_cntdwn ) {
    print_cntdw_prog( );
    return;
  }

  if( gl_mtrnm_p.inc_bpm < 99 ) {
    sprintf( output_buf, "-%2d-", gl_mtrnm_p.inc_bpm );
  } else {
    sprintf( output_buf, " %3d", gl_mtrnm_p.inc_bpm );
  }
}

void menu_print_inc_bar_prog( void ) {

  if( gl_mtrnm_p.cur_cntdwn ) {
    print_cntdw_prog( );
    return;
  }

  if( gl_mtrnm_p.inc_bar > 9 || gl_mtrnm_p.cur_bar > 9 ) {
    sprintf( output_buf, "%2d.%2d", gl_mtrnm_p.inc_bar, gl_mtrnm_p.cur_bar );
  } else {
    sprintf( output_buf, "[%d.%d]", gl_mtrnm_p.inc_bar, gl_mtrnm_p.cur_bar );
  }
}

void print_cntdw_en_prog( void ) {

  if( gl_mtrnm_p.cur_cntdwn ) {
    print_cntdw_prog( );
    return;
  }

  sprintf( output_buf, "Cnt.%d", gl_mtrnm_p.cntdwn_en );
}

void menu_print_strong_note_sett( void ) {
  sprintf( output_buf, "1.%s", note2str( gl_mtrnm_p.note_strong ) );
}

void menu_print_weak_note_sett( void ) {
  sprintf( output_buf, "2.%s", note2str( gl_mtrnm_p.note_weak ) );
}

void menu_print_subdiv_note_sett( void ) {
  sprintf( output_buf, "3.%s", note2str( gl_mtrnm_p.note_subdiv ) );
}

void menu_print_beep_ms_sett( void ) {
  sprintf( output_buf, "b.%3d", gl_mtrnm_p.beep_ms );
}

void menu_main_entry( void ) {
  mtrnm_change_mode( MTRNM_MODE_CONST );
}

void menu_prog_entry( void ) {
  mtrnm_change_mode( MTRNM_MODE_PROG );
}
