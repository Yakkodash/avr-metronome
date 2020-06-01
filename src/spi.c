#include "spi.h"
#include <util/delay.h>

static void spi_clear( void ) {
  spi_transmit( 0 );
}

void spi_init( void ) {
  SPI_PORT_DIR |= _BV( SPI_NSS_PIN ) | _BV( SPI_MOSI_PIN ) | _BV( SPI_SCK_PIN ); // does not work without NSS
  SPI_PORT &= ~( _BV( SPI_NSS_PIN ) | _BV( SPI_MOSI_PIN ) | _BV( SPI_SCK_PIN ) ); 

	SPCR = ( _BV( SPE ) | _BV( MSTR ) ); // init bus, set master

  spi_clear( );
}

// There are two shift registers giving 16bit output register, but SPDR is only 8bit
void spi_transmit( uint8_t val ) {
	SPDR = val;

	while ( !( SPSR & ( _BV( SPIF ) ) ) );
}
