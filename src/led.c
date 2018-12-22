#include "led.h"

void led_init( void ) {
  LED_DIR_PORT |= _BV( LED0 );
  LED_DIR_PORT |= _BV( LED1 );
  LED_DIR_PORT |= _BV( LED2 );
}

void set_led( led_t led, uint8_t state ) {

  if( state ) {
    LED_PORT |= _BV( led );
  } else {
    LED_PORT &= ~(_BV( led ));
  }

}


