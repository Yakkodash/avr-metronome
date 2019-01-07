#include <avr/interrupt.h>
#include <math.h>

#include "timer.h"

static uint64_t ticks = 0;

ISR( TIMER2_OVF_vect ) {
  ticks++;
}

void timer_start( void ) {
  ticks = 0;

  TIMSK2 = _BV( TOIE2 );
  TCCR2B = _BV( CS20 ); // no prescaler, 16us precision
}

void timer_stop( void ) {
  TCCR2B = 0;
}

uint64_t timer_get_us( void ) {
  return (uint64_t)round( ticks / ( TIMER_TICKS_PER_SEC * 1000 ) );
}

uint64_t timer_get_ms( void ) {
  return (uint64_t)round( ticks / TIMER_TICKS_PER_SEC );
}
