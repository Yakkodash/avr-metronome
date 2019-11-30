#pragma once

#include <avr/io.h>

#define DISP_CS_DIR_PORT DDRC // character select
#define DISP_CS_PORT PORTC

#define DIG_NUM 4
#define DIG_NONE -1

#define DISP_DELAY_US 1000

static const uint8_t display_digs[DIG_NUM] = { PC1, PC2, PC3, PC0 };

void display_init( void );
void display_set_chars( char *data, uint8_t len );
void display_tick( void );
