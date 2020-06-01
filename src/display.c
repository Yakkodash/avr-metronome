#include <util/delay.h>
#include <string.h>

#include "display.h"
#include "spi.h"
#include "symbols.h"

static uint8_t display_buf[DIG_NUM];
static uint8_t display_cur_dig = 0;

void display_init( void ) {
  for( uint8_t i = 0; i < DIG_NUM; i++ ) {
    DISP_CS_DIR_PORT |= _BV( display_digs[i] );
    DISP_CS_PORT |= _BV( display_digs[i] );
  }
}

static void display_set_digit_active( int8_t dig_num ) {
  DISP_CS_PORT = dig_num == DIG_NONE ? 0 : _BV( display_digs[dig_num] );
}

void display_set_chars( char *data, uint8_t len ) {
  uint8_t c = 0, j = 0;

  for( uint8_t i = 0; i < len; i++ ) {
    if( data[i+1] == '.' && data[i] != '.' && i+1 < len ) {
      c = char2segment( data[i] ) | char2segment( '.' );
      i++;
    } else {
      c = char2segment( data[i] );
    }
    display_buf[j] = c;
    j++;
  }

}

void display_tick( void ) {

  spi_transmit( display_buf[display_cur_dig] );

  display_set_digit_active( display_cur_dig );

  display_cur_dig++;
  if( display_cur_dig == DIG_NUM ) display_cur_dig = 0;

  _delay_us( DISP_DELAY_US );
  display_set_digit_active( DIG_NONE );
}
