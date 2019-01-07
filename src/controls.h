#pragma once

#include <avr/io.h>
#include <avr/interrupt.h>

extern struct ctrl_s {
  void (*ctrl_enc_a_clbk)(void);
  void (*ctrl_enc_b_clbk)(void);
  void (*ctrl_enc_btn_clbk)(void);

  void (*ctrl_enc_a_btn_clbk)(void); // if encoder is rotated with button being hold
  void (*ctrl_enc_b_btn_clbk)(void);

  void (*ctrl_btn0_clbk)(void);
  void (*ctrl_btn1_clbk)(void);
} gl_ctrl_p;

void controls_init( void );

