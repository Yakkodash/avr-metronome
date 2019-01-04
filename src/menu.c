#include "menu.h"
#include "metronome.h"
#include "display.h"

static char output_buf[4];

uint16_t pow16( uint16_t val, uint8_t pow ) {
  if( pow == 0 ) return 1;
  for( uint8_t i = 0; i < pow; i++ ) {
    val *= val;
  }
  return val;
}

void dig_itoa( char *dst, uint16_t val ) {

  for( uint8_t i = 0; i < DIG_NUM; i++ ) {
    dst[i] = '0' + ( val / ( pow16( 10, i ) ) ) % 10;
  }

}

void menu_fsm( void ) {
  // Cause itoa is broken

  // t. for tempo prefix
/*  output_buf[0] = 't';
  output_buf[1] = '.';

  // Hundreds digit
  output_buf[2] = gl_mtrnm_p.active_bpm < 100 ? ' ' : '0' + ( ( gl_mtrnm_p.active_bpm / 100UL ) % 10UL );


  // Tens digit
  output_buf[3] = '0' + ( ( gl_mtrnm_p.active_bpm / 10UL ) % 10UL );

  // Ones digit
  output_buf[4] = '0' + ( gl_mtrnm_p.active_bpm % 10UL );
*/
  dig_itoa( output_buf, gl_mtrnm_p.active_bpm );

  display_set( output_buf, 4 );
}

