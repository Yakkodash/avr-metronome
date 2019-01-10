#pragma once

#include <avr/io.h>

#define PWRLOSS_DET_PORT_DIR DDRC
#define PWRLOSS_DET_PORT     PORTC
#define PWRLOSS_DET_INPUT    PC5
#define PWRLOSS_DET_ADC_CHAN 5

#define PWRLOSS_THRESH_LOW  850
#define PWRLOSS_THRESH_HIGH 1020
#define PWRLOSS_DELAY_MS    1000

void powerloss_detect_init( void (*clbk)(void) );
uint8_t powerloss_detect_tick( void );
