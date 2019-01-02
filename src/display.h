#pragma once

#include <avr/io.h>

#define DISP_CS_DIR_PORT DDRC // character select
#define DISP_CS_PORT PORTC

#define DIG_NUM 4
#define REFRESH_US 3000 // better to keep as low as possible to avoid bleed
                        // effect and save battery

static const uint8_t display_digs[DIG_NUM] = { PC0, PC1, PC2, PC3 };

void display_init( void );
void display_set( char *data, uint8_t len );
void display_loop( void );

