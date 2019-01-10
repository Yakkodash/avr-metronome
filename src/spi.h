// SPI for controlling 74hc595n chip
#pragma once

#include <avr/io.h>

#define SPI_PORT_DIR  DDRB

#define SPI_PORT  PORTB
#define SPI_SS    PB2
#define SPI_MOSI  PB3
#define SPI_SCK   PB5

void spi_init( void );
void spi_transmit( uint8_t val );
