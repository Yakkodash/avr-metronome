// Setting
void menu_bpm_inc( void ) {
  if( gl_mtrnm_p.active_bpm < MTRNM_MAX_BPM ) gl_mtrnm_p.active_bpm++;
}

void menu_bpm_dec( void ) {
  if( gl_mtrnm_p.active_bpm > MTRNM_MIN_BPM ) gl_mtrnm_p.active_bpm--;
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

  output_buf[0] = 'd'; // division
  output_buf[1] = '.';
  output_buf[2] = ' ';

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
  output_buf[2] = '.';
  output_buf[3] = ' ';

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
