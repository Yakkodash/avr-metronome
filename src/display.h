#pragma once

#include <avr/io.h>

#define DISP_CS_DIR_PORT DDRC // character select
#define DISP_CS_PORT PORTC

#define DIG_NUM 4
#define DOTS_NUM 4

#define DISP_REFRESH_STABLE_MS 3
#define DISP_REFRESH_FAST_FLICKER_MS 15
#define DISP_REFRESH_SLOW_FLICKER_MS 55

typedef enum {
  DISP_MODE_STABLE,
  DISP_MODE_FAST_FLICKER,
  DISP_MODE_SLOW_FLICKER
} disp_mode_t;

static const uint8_t display_digs[DIG_NUM] = { PC0, PC1, PC2, PC3 };

void display_init( void );
void display_set_chars( char *data, uint8_t len );
void display_set_mode( disp_mode_t mode );
void display_tick( void );
