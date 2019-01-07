#pragma once

#include <stdint.h>

#define TIMER_TICKS_PER_SEC ( F_CPU / 256 )

void timer_start( void );
void timer_stop( void );

uint64_t timer_get_us( void );
uint64_t timer_get_ms( void );
