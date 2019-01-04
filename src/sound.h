#pragma once

#include <stdint.h>
#include <avr/io.h>

#define SOUND_FREQ_MIN  ( F_CPU / ( 2 * 256 ) / ( 256 + 1 ) )
#define SOUND_FREQ_MAX  ( F_CPU / ( 2 * 256 ) )

#define SOUND_PORT_DIR  DDRD
#define SOUND_PIN_DIR   PD6

void sound_init( void );

int16_t sound_set_freq( uint16_t freq );

void sound_start( void );
void sound_stop( void );

