#include "powerloss.h"
#include "adc.h"
#include "timer.h"

#include <avr/interrupt.h>
#include <stdint.h>

static void (*powerloss_clbk)( void );
static uint16_t pwr_adc_val;

void powerloss_detect_init( void (*clbk)(void) ) {
  PWRLOSS_PORT_DIR &= ~( _BV( PWRLOSS_PIN ) );
  PWRLOSS_PORT &= ~( _BV( PWRLOSS_PIN ) );
  powerloss_clbk = clbk;
}

static uint16_t ret = 0;

uint8_t powerloss_detect_tick( void ) {
  ret = 0;

  PWRLOSS_PORT_DIR &= ~(_BV( PWRLOSS_PIN ));
  PWRLOSS_PORT &= ~( _BV( PWRLOSS_PIN ) );

  pwr_adc_val = adc_read( PWRLOSS_ADC_CHAN );

  if( pwr_adc_val < PWRLOSS_THRESH_LOW ) {
    PWRLOSS_PORT_DIR |= (_BV( PWRLOSS_PIN ));
    PWRLOSS_PORT |= ( _BV( PWRLOSS_PIN ) );
  }

  if( pwr_adc_val > PWRLOSS_THRESH_HIGH ) { // ignore first second after power on
    powerloss_clbk( );
    ret = 1;
  };

  return ret;
}
