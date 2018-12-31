#include <util/delay.h>
#include <string.h>

#include "display.h"
#include "spi.h"
#include "symbols.h"

static uint8_t display_buf[DIG_NUM];
static uint8_t display_buf_last[DIG_NUM] = "";
static uint8_t display_cur_dig = 0;

void display_init( void ) {
  for( uint8_t i = 0; i< DIG_NUM; i++ ) {
    DISP_CS_DIR_PORT |= _BV( display_digs[i] );
    DISP_CS_PORT |= _BV( display_digs[i] );
  }

  spi_master_set( );
}

static void display_clear( void ) {
  spi_master_reset( );
  spi_master_set( );
}

static void display_set_digit( uint8_t dig_num ) {
  for( uint8_t i = 0; i < DIG_NUM; i++ ) 
    DISP_CS_PORT |= _BV( display_digs[i] );

  DISP_CS_PORT &= ~( _BV( display_digs[dig_num] ) ); 
}

void display_set( uint8_t data[DIG_NUM] ) {
  memcpy( display_buf, data, DIG_NUM * sizeof( uint8_t ) );
}

void display_loop( void ) {
  if( strcmp( (const char*)display_buf_last, (const char*)display_buf ) == 0 ) return;

  memcpy( display_buf_last, display_buf, DIG_NUM * sizeof( uint8_t ) );

  display_clear( );
  display_set_digit( display_cur_dig );

  spi_transmit( char2segment( display_buf[display_cur_dig] ) );

  display_cur_dig++;
  if( display_cur_dig == DIG_NUM ) display_cur_dig = 0;
  _delay_us( REFRESH_US );
}

