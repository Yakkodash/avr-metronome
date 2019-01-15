#include "util.h"
#include "display.h"

uint16_t pow16( uint16_t x, uint8_t y ) {
  if( y == 0 ) return 1;
  if( y % 2 == 0 ) return pow16( x, y / 2 ) * pow16( x, y / 2 );
  return x * pow16( x, y / 2 ) * pow16( x, y / 2 );
}

void dig_itoa16( char *dst, uint16_t val ) {
  uint8_t i = 0;

  if( val == 0 ) {
    dst[DIG_NUM-1] = '0';
    i++;
  }

  for( ; i < DIG_NUM; i++ ) {
    dst[DIG_NUM-1-i] = val < pow16( 10, i ) ? ' ' : '0' + ( val / ( pow16( 10, i ) ) ) % 10;
  }
}
