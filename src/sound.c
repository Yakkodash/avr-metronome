#include "sound.h"

void sound_init( void ) {
  TCCR0A = _BV( COM0A0 ) | _BV( WGM01 ); // CTC mode
  TCCR0B = 0; // stop timer

	SOUND_PORT_DIR |=  _BV( SOUND_PIN_DIR );
}

void sound_start( void ) {
  TCCR0B = _BV( CS12 ); // start timer, 256 prescaler
}

void sound_stop( void ) {
  TCCR0B = 0; // stop timer
}

int16_t sound_set_freq( uint16_t freq ) {
  int16_t ret = 0;

  if( freq > SOUND_FREQ_MIN && freq < SOUND_FREQ_MAX ) {
    OCR0A = F_CPU / ( 2UL * 256UL ) / freq - 1; // set output compare register
  } else ret = 1;

  return ret;

}

