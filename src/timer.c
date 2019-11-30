#include <avr/interrupt.h>
#include <math.h>

#include "timer.h"
#include "display.h"
#include "led.h"

static volatile uint32_t ticks = 0; // 1 tick == 16 us, will overflow after about 19 hours

ISR( TIMER2_OVF_vect ) {
  ticks++;
}

void timer_start( void ) {
  ticks = 0;

  TIMSK2 = _BV( TOIE2 );
  TCCR2B = _BV( CS20 ); // no prescaler, 16us precision
  TCNT2 = 255;
}

void timer_stop( void ) {
  TCCR2B = 0;
}

uint32_t timer_get_us( void ) {
  return (uint32_t)round( ticks / ( TIMER_TICKS_PER_SEC / 1e6 ) );
}

uint32_t timer_get_ms( void ) {
  return (uint32_t)round( ticks / ( TIMER_TICKS_PER_SEC / 1e3 ) );
}
