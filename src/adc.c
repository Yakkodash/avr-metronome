#include "adc.h"
#include <avr/io.h>

void adc_init( void ) {
  // AREF = AVcc
  //ADMUX = _BV( REFS0 );


  // ADC Enable and prescaler of 128
  // 16000000/128 = 125000
  //ADCSRA = _BV( ADEN ) | _BV( ADPS0 ) | _BV( ADPS1 );
  //ADMUX &= ~(0<<REFS0)|~(0<<REFS1);
  ADMUX = 0;
  ADCSRA |= (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

inline uint16_t adc_read( uint8_t ch ) { // channel 4 -- power fail capture

  // select the corresponding channel 0~7
  // ANDing with '7' will always keep the value
  // of 'ch' between 0 and 7
  ch &= 0b00000111;
  ADMUX = ( ADMUX & 0xF8 ) | ch; // clears the bottom 3 bits before ORing

  // start single conversion
  ADCSRA |= _BV( ADSC );

  // wait for conversion to complete
  while( ADCSRA & _BV( ADSC ) );

  return ADC;
}
