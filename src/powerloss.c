#include "powerloss.h"
#include "adc.h"
#include "timer.h"

#include <avr/interrupt.h>
#include <stdint.h>

void (*powerloss_clbk)( void );

void powerloss_detect_init( void (*clbk)(void) ) {
  PWRLOSS_DET_PORT_DIR &= ~( _BV( PWRLOSS_DET_INPUT ) );
  PWRLOSS_DET_PORT &= ~( _BV( PWRLOSS_DET_INPUT ) );
  powerloss_clbk = clbk;
}

static uint16_t cur_adc = 0;
void powerloss_detect_tick( void ) {

  cur_adc = adc_read( 5 );
  if( cur_adc < PWRLOSS_THRESH_LOW ) {
    PWRLOSS_DET_PORT_DIR |= _BV( PWRLOSS_DET_INPUT );
    PWRLOSS_DET_PORT |= ( _BV( PWRLOSS_DET_INPUT ) );
    return;
  }

  PWRLOSS_DET_PORT_DIR &= ~( _BV( PWRLOSS_DET_INPUT ) );
  PWRLOSS_DET_PORT &= ~( _BV( PWRLOSS_DET_INPUT ) );

  if( cur_adc > PWRLOSS_THRESH_HIGH && timer_get_ms( ) > PWRLOSS_DELAY_MS ) { // ignore first second after power on
    cli( );
    powerloss_clbk( );
  };

}
