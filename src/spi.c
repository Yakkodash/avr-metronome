#include "spi.h"
#include <util/delay.h>

static void spi_clear( void ) {
  spi_transmit( 0 );
}

void spi_init( void ) {
  SPI_PORT_DIR |= _BV( SPI_SS ) | _BV( SPI_MOSI ) | _BV( SPI_SCK ); // setup SPI pins (no MISO)
  SPI_PORT &= ~( _BV( SPI_SS ) | _BV( SPI_MOSI ) | _BV( SPI_SCK ) ); // set SPI pins to 0

	SPCR = ( _BV( SPE ) | _BV( MSTR ) ); // init bus, set master

  spi_clear( );
}

static void spi_commit( void ) {
	while ( !( SPSR & ( _BV( SPIF ) ) ) );
  // Generate signal fall for storage register
	SPI_PORT |= _BV( SPI_SS );
	SPI_PORT &= ~( _BV( SPI_SS ) );
}

// There are two shift registers giving 16bit output register, but SPDR is only 8bit
void spi_transmit( uint8_t val ) {
	SPDR = val;

  spi_commit( );
}
