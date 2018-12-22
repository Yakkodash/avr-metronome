#pragma once

#include <avr/io.h>

#define LED_DIR_PORT  DDRB

#define LED_PORT  PORTB

typedef enum {
  LED0 = PB0,
  LED1 = PB1,
  LED2 = PB2
} led_t;

void led_init( void );

void set_led( led_t led, uint8_t state );

