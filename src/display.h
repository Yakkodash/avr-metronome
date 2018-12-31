#pragma once

#include <avr/io.h>

#define DISP_CS_DIR_PORT DDRC // character select
#define DISP_CS_PORT PORTC

#define DIG_NUM 4
#define REFRESH_US 2000

static const uint8_t display_digs[DIG_NUM] = { PC0, PC1, PC2, PC3 };

void display_init( void );
void display_set( uint8_t data[DIG_NUM] );
void display_loop( void );

