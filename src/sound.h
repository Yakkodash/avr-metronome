#pragma once

#include <stdint.h>
#include <avr/io.h>

#include "notes.h"

#define SOUND_FREQ_MIN  ( F_CPU / ( 2 * 256 ) / ( 256 + 1 ) ) + 1
#define SOUND_FREQ_MAX  ( F_CPU / ( 2 * 256 ) ) - 1

#define SOUND_PORT_DIR  DDRD
#define SOUND_PIN       PD6

void sound_init( void );

void sound_start( uint16_t freq );
void sound_stop( void );

