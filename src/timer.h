// General purpose timer to count time since the device power-up

#pragma once

#include <stdint.h>

#define TIMER_TICKS_PER_SEC ( F_CPU / 256 ) // timer precision is 16 us

void timer_start( void );
void timer_stop( void );

uint32_t timer_get_us( void );
uint32_t timer_get_ms( void );
