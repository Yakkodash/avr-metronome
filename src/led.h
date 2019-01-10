#pragma once

#include <avr/io.h>

#define LED_DIR_PORT DDRD
#define LED_PORT PORTD

#define LED_NUM 3

static const uint8_t leds[LED_NUM] = { PD3, PD4, PD5 };

void led_init( void );
void led_deinit( void );

void led_set( uint8_t led_num, uint8_t state );
