#include "controls.h"
#include "timer.h"

static int8_t enc_state = 0;

static uint8_t enc_a = 0;
static uint8_t enc_b = 0;

static int8_t enc_btn_check = 0;

static uint8_t enc_rot_check = 0; // indicate that encoder was turned while being pressed

// Encoder button check
static int8_t check_enc_btn_release( void ) {
  return !( PIND & _BV( PIND7 ) );
}

static int8_t check_enc_btn_press( void ) {
  return PIND & _BV( PD7 );
}

void check_switch( void ) {
  if( PINC & _BV( PINC4 ) ) gl_ctrl_p.ctrl_swt_on_clkb( );
  else gl_ctrl_p.ctrl_swt_off_clkb( );
}

// Encoder rotation check
static int8_t check_enc_moved( void ) {
  enc_a = PINB & _BV( PB0 );
  enc_b = PINB & _BV( PB1 );

  if( !enc_a && enc_b ) enc_state = 1; // if falling edge appeared on line A and B is 1 then rotating right
  if( !enc_a && !enc_b ) enc_state = -1;  // if falling edge on line A and B is 0, rotating left

  return ( enc_state == 1 && !enc_b ) || ( enc_state == -1 && enc_b ); // if A is 1 again, then encoder has moved
}

// Encoder button
static void init_enc_btn( void ) {
  CTRL_ENC_BTN_PORT_DIR &= ~( _BV( CTRL_ENC_BTN_PIN ) );
  CTRL_ENC_BTN_PORT |= _BV( CTRL_ENC_BTN_PIN );

  CTRL_ENC_BTN_PCMSK |= _BV( CTRL_ENC_BTN_PCINT ); // encoder button
}

// Encoder rotation
static void init_enc_rot( void ) {
  CTRL_ENC_ROT_PORT_DIR &= ~( _BV( CTRL_ENC_ROT_A_PIN ) | _BV( CTRL_ENC_ROT_B_PIN ) ); // 0, 1 -- rotation, 4 -- button
  CTRL_ENC_ROT_PORT |= _BV( CTRL_ENC_ROT_A_PIN ) | _BV( CTRL_ENC_ROT_B_PIN );

  CTRL_ENC_ROT_PCMSK |= _BV( CTRL_ENC_ROT_A_PCINT ) | _BV( CTRL_ENC_ROT_B_PCINT ); // encoder and button1

  check_enc_moved( );
}

// Switch
static void init_switch( void ) {
  CTRL_SWT_PORT_DIR &= ~( _BV( CTRL_SWT_PIN ) );
  CTRL_SWT_PORT |= _BV( CTRL_SWT_PIN );

  CTRL_SWT_PCMSK |= _BV( CTRL_SWT_PCINT ); // switch

  check_switch( );
}

// Button0
static void init_btn0( void ) {
  CTRL_BTN0_PORT_DIR &= ~( _BV( CTRL_BTN0_PIN ) );
  CTRL_BTN0_PORT |= _BV( CTRL_BTN0_PIN );

  EIMSK |= _BV( CTRL_BTN0_INT );
  EICRA |= CTRL_BTN0_LOGIC; // rising edge
}

// Button1
static void init_btn1( void ) {
  CTRL_BTN1_PORT_DIR &= ~( _BV( CTRL_BTN1_PIN ) );
  CTRL_BTN1_PORT |= _BV( CTRL_BTN1_PIN );

  EIMSK |= _BV( CTRL_BTN1_INT );
  EICRA |= CTRL_BTN1_LOGIC; // rising edge
}

void ctrl_init( void ) {
  init_btn0( );
  init_btn1( );
  init_enc_btn( );
  init_enc_rot( );
  init_switch( );

  PCICR |= _BV( PCIE0 ) | _BV( PCIE1 ) | _BV( PCIE2 ); // enable all pin change interrupt vectors
}

// Encoder rotation interrupt
ISR( CTRL_ENC_ROT_PCINT_V ) {
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
}

ISR( CTRL_SWT_PCINT_V ) {
  check_switch( );
}

// Encoder button interrupt
ISR( CTRL_ENC_BTN_PCINT_V ) {
  if( check_enc_btn_release( ) ) {
    if( enc_rot_check ) enc_rot_check = 0;
    else gl_ctrl_p.ctrl_enc_btn_clbk( );
  }
}

// Button0 interrupt
ISR( CTRL_BTN0_INT_V ) {
  gl_ctrl_p.ctrl_btn0_clbk( );
}	

// Button1 interrupt
ISR( CTRL_BTN1_INT_V ) {
  gl_ctrl_p.ctrl_btn1_short_clbk( );
}	

