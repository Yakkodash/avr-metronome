#include "powerloss.h"
#include "adc.h"
#include "timer.h"

#include <avr/interrupt.h>
#include <stdint.h>

static void (*powerloss_clbk)( void );

void powerloss_detect_init( void (*clbk)(void) ) {
  PWRLOSS_PORT_DIR &= ~( _BV( PWRLOSS_PIN ) );
  PWRLOSS_PORT &= ~( _BV( PWRLOSS_PIN ) );
  powerloss_clbk = clbk;
}

static uint16_t ret = 0;
//static uint32_t tim = 0;
//static uint32_t buf_tim = 0;

uint8_t powerloss_detect_tick( void ) {
  ret = 0;
 // buf_tim = timer_get_ms( );
/*
  if( buf_tim - tim < PWRLOSS_CHECK_MS ) return ret;
  else tim = buf_tim;
*/
  cli( );

  pwr_adc_val = adc_read( PWRLOSS_ADC_CHAN );

  if( pwr_adc_val < PWRLOSS_THRESH_LOW ) {
    //PWRLOSS_PORT_DIR |= _BV( PWRLOSS_PIN );
    //PWRLOSS_PORT |= ( _BV( PWRLOSS_PIN ) );
    return ret;
  }

  //PWRLOSS_PORT_DIR &= ~( _BV( PWRLOSS_PIN ) );
  //PWRLOSS_PORT &= ~( _BV( PWRLOSS_PIN ) );

  if( pwr_adc_val > PWRLOSS_THRESH_HIGH && timer_get_ms( ) > PWRLOSS_DELAY_MS ) { // ignore first second after power on
  //  powerloss_clbk( );
  //  ret = 1;
  };
  sei( ); // on powerloss interrupts are disabled so just in case of a capacitor hiccup enable them each tick

  return ret;
}
