#include "led.h"

void led_init( void ) {
  for( uint8_t i = 0; i < LED_NUM; i++ ) {
    LED_DIR_PORT |= _BV( leds[i] );
  }
}

void led_deinit( void ) {
  for( uint8_t i = 0; i < LED_NUM; i++ ) {
    LED_DIR_PORT &= ~( _BV( leds[i] ) );
    LED_PORT &= ~(_BV( leds[i] ));
  }
}

void led_set( uint8_t led_num, uint8_t state ) {

  if( state ) {
    LED_PORT |= _BV( leds[led_num] );
  } else {
    LED_PORT &= ~(_BV( leds[led_num] ));
  }

}


