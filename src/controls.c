#include "controls.h"
#include "metronome.h"
#include "timer.h"

#define CTRL_ENC_BTN_PORT_DIR
#define CTRL_ENC_BTN_PORT
#define CTRL_ENC_BTN_PIN
#define CTRL_ENC_BTN_PIN

static int8_t check_enc_moved( void );
void switch_handle( void );

void controls_init( void ) {
  // Button0
  DDRD &= ~( _BV( PD2 ) );
  PORTD |= _BV( PD2 );
  EIMSK |= _BV( INT0 );
  EICRA |= _BV( ISC01 ) | _BV( ISC00 ); // rising edge

  // Encoder button
  DDRD &= ~( _BV( PD7 ) );
  PORTD |= _BV( PD7 );

  // Switch
  DDRC &= ~( _BV( PC4 ) );
  PORTC |= _BV( PC4 );

  // Encoder and button1
  DDRB &= ~( _BV( PB4 ) | _BV( PB0 ) | _BV( PB1 ) ); // 0, 1 -- rotation, 4 -- button
  PORTB |= _BV( PB4 ) | _BV( PB0 ) | _BV( PB1 );

  // Enable pin change interrupts for encoder and button1
  PCICR |= _BV( PCIE0 ) | _BV( PCIE1 ) | _BV( PCIE2 ); // enable pin change interrupt

  // Pin change interrupts masks
  PCMSK0 |= _BV( PCINT0 ) | _BV( PCINT1 ) | _BV( PCINT4 ); // encoder and button1
  PCMSK1 |= _BV( PCINT12 );
  PCMSK2 |= _BV( PCINT23 ); // encoder button

  check_enc_moved( );
  switch_handle( );
}

static int8_t enc_state = 0;

static uint8_t enc_a = 0;
static uint8_t enc_b = 0;

static int8_t enc_btn_check = 0;

static uint8_t enc_rot_check = 0; // indicate that encoder was turned while being pressed

// Encoder rotation check
static int8_t check_enc_moved( void ) {
  enc_a = PINB & _BV( PINB0 );
  enc_b = PINB & _BV( PINB1 );

  if( !enc_a && enc_b ) enc_state = 1; // if falling edge appeared on line A and B is 1 then rotating right
  if( !enc_a && !enc_b ) enc_state = -1;  // if falling edge on line A and B is 0, rotating left

  return ( enc_state == 1 && !enc_b ) || ( enc_state == -1 && enc_b ); // if A is 1 again, then encoder has moved
}

// Encoder button check
static int8_t check_enc_btn_release( void ) {
  return !( PIND & _BV( PIND7 ) );
}

static int8_t check_enc_btn_press( void ) {
  return PIND & _BV( PIND7 );
}

// Encoder rotation and button1 interrupt
ISR( PCINT0_vect ) {
  enc_btn_check = check_enc_btn_press( );

  if( check_enc_moved( ) ) {
    if( enc_state == 1 ) {
      enc_btn_check ? gl_ctrl_p.ctrl_enc_a_btn_clbk( ) : gl_ctrl_p.ctrl_enc_a_clbk( ); // right
    }
    if( enc_state == -1 ) {
      enc_btn_check ? gl_ctrl_p.ctrl_enc_b_btn_clbk( ) : gl_ctrl_p.ctrl_enc_b_clbk( ); // left
    }
    enc_state = 0;
    enc_rot_check = enc_btn_check;
  }

  if( PINB & _BV( PINB4 ) ) {
      gl_ctrl_p.ctrl_btn1_short_clbk( );
  //  gl_ctrl_p.btn_tim = timer_get_ms( );
  //  gl_ctrl_p.btn_pressed = 1;
  } else {
  //  if( timer_get_ms( ) - gl_ctrl_p.btn_tim )
  //  gl_ctrl_p.btn_pressed = 0;
  }
  /*if( PINB & _BV( PINB4 ) ) {
    gl_ctrl_p.ctrl_btn1_clbk( );
  }*/
}

void switch_handle( void ) {
  if( PINC & _BV( PINC4 ) ) gl_ctrl_p.ctrl_swt_on_clkb( );
  else gl_ctrl_p.ctrl_swt_off_clkb( );
}

ISR( PCINT1_vect ) {
  switch_handle( );
}

// Encoder button interrupt
ISR( PCINT2_vect ) {
  if( check_enc_btn_release( ) ) {
    if( enc_rot_check ) enc_rot_check = 0;
    else gl_ctrl_p.ctrl_enc_btn_clbk( );
  }
}

// Button0 interrupt
ISR( INT0_vect ) {
  gl_ctrl_p.ctrl_btn0_clbk( );
}	
