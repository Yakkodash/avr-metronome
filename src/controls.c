#include "controls.h"

void controls_init( void ) {
  // Button0
  DDRD &= ~( _BV( PD2 ) );
  PORTD |= _BV( PD2 );
  EIMSK |= _BV( INT0 );
  EICRA |= _BV( ISC01 ) | _BV( ISC00 ); // rising edge

  // Button1
  DDRD &= ~( _BV( PD7 ) );
  PORTD |= _BV( PD7 );

  // Encoder
  DDRB &= ~( _BV( PB4 ) | _BV( PB0 ) | _BV( PB1 ) ); // 0, 1 -- rotation, 4 -- button
  PORTB |= _BV( PB4 ) | _BV( PB0 ) | _BV( PB1 );

  // Enable pin change interrupts for encoder and button1
  PCICR |= _BV( PCIE0 ) | _BV( PCIE2 ); // enable pin change interrupt

  // Pin change interrupts masks
  PCMSK0 |= _BV( PCINT0 ) | _BV( PCINT1 ) | _BV( PCINT4 ); // encoder
  PCMSK2 |= _BV( PCINT23 ); // button1
}

static int enc_state = 0;
static int enc_a = 0;
static int enc_b = 0;

// Encoder interrupt
ISR( PCINT0_vect ) {
  // Encoder button
  if( PINB & _BV( PINB4 ) ) {
    gl_ctrl_p.ctrl_enc_btn_callback( );
  }

  // Encoder rotation
  enc_a = PINB & _BV( PINB0 );
  enc_b = PINB & _BV( PINB1 );

  if( !enc_a && enc_b ) enc_state = 1; // if falling edge appeared on line A and B is 1 then rotating right
  if( !enc_a && !enc_b ) enc_state = -1;  // if falling edge on line A and B is 0, rotating left
  if( ( enc_state == 1 && !enc_b ) || ( enc_state == -1 && enc_b ) ) { // if A is 1 again, then encoder has moved
    if( enc_state == 1 )  gl_ctrl_p.ctrl_enc_a_callback( ); // right
    if( enc_state == -1 ) gl_ctrl_p.ctrl_enc_b_callback( ); // left
    enc_state = 0;
  }
}

// Button0 interrupt
ISR( INT0_vect ) {
  gl_ctrl_p.ctrl_btn0_callback( );
}	

// Button1 interrupt
ISR( PCINT2_vect ) {
  if( PIND & _BV( PIND7 ) ) {
    gl_ctrl_p.ctrl_btn1_callback( );
  }
}

