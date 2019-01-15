// SPI for controlling 74hc595n chip
#pragma once

#include <avr/io.h>

#define SPI_PORT_DIR  DDRB

#define SPI_PORT      PORTB
#define SPI_NSS_PIN   PB2
#define SPI_MOSI_PIN  PB3
#define SPI_SCK_PIN   PB5

void spi_init( void );
void spi_transmit( uint8_t val );
