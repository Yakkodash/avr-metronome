#pragma once

#include <avr/io.h>
#include <avr/interrupt.h>

#define CTRL_ENC_BTN_PORT_DIR DDRD
#define CTRL_ENC_BTN_PORT     PORTD
#define CTRL_ENC_BTN_PIN      PD7
#define CTRL_ENC_BTN_INPINS   PIND
#define CTRL_ENC_BTN_PCINT    PCINT23
#define CTRL_ENC_BTN_PCMSK    PCMSK2
#define CTRL_ENC_BTN_PCINT_V  PCINT2_vect

#define CTRL_ENC_ROT_PORT_DIR DDRB
#define CTRL_ENC_ROT_PORT     PORTB
#define CTRL_ENC_ROT_A_PIN    PB0
#define CTRL_ENC_ROT_B_PIN    PB1
#define CTRL_ENC_ROT_INPINS   PINB
#define CTRL_ENC_ROT_A_PCINT  PCINT0
#define CTRL_ENC_ROT_B_PCINT  PCINT1
#define CTRL_ENC_ROT_PCMSK    PCMSK0
#define CTRL_ENC_ROT_PCINT_V  PCINT0_vect

#define CTRL_SWT_PORT_DIR DDRC
#define CTRL_SWT_PORT     PORTC
#define CTRL_SWT_PIN      PC4
#define CTRL_SWT_PCINT    PCINT12
#define CTRL_SWT_PCMSK    PCMSK1
#define CTRL_SWT_PCINT_V  PCINT1_vect

#define CTRL_BTN1_PORT_DIR  DDRD
#define CTRL_BTN1_PORT      PORTD
#define CTRL_BTN1_PIN       PD2
#define CTRL_BTN1_INT       INT0
#define CTRL_BTN1_LOGIC     ( _BV( ISC01 ) | _BV( ISC00 ) ) // rising edge
#define CTRL_BTN1_INT_V     INT0_vect

#define CTRL_BTN2_PORT_DIR  DDRD
#define CTRL_BTN2_PORT      PORTD
#define CTRL_BTN2_PIN       PD3
#define CTRL_BTN2_INT       INT1
#define CTRL_BTN2_LOGIC     ( _BV( ISC11 ) ) // falling edge
#define CTRL_BTN2_INT_V     INT1_vect

extern volatile struct ctrl_s {
  void (*ctrl_enc_a_clbk)(void);
  void (*ctrl_enc_b_clbk)(void);
  void (*ctrl_enc_btn_clbk)(void);

  void (*ctrl_enc_a_btn_clbk)(void); // if encoder is rotated with button being hold
  void (*ctrl_enc_b_btn_clbk)(void);

  void (*ctrl_btn0_clbk)(void);

  void (*ctrl_btn1_clbk)(void);

  void (*ctrl_btn2_clbk)(void);

  void (*ctrl_swt_on_clkb)(void); // switch callback
  void (*ctrl_swt_off_clkb)(void); // switch callback
} gl_ctrl_p;

void ctrl_init( void );
