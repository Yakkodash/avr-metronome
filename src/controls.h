#pragma once

#include <avr/io.h>
#include <avr/interrupt.h>

extern volatile struct ctrl_s {
  void (*ctrl_enc_a_clbk)(void);
  void (*ctrl_enc_b_clbk)(void);
  void (*ctrl_enc_btn_clbk)(void);

  void (*ctrl_enc_a_btn_clbk)(void); // if encoder is rotated with button being hold
  void (*ctrl_enc_b_btn_clbk)(void);

  void (*ctrl_btn0_clbk)(void);

  void (*ctrl_btn1_short_clbk)(void);
  void (*ctrl_btn1_long_clbk)(void);

  void (*ctrl_swt_on_clkb)(void); // switch callback
  void (*ctrl_swt_off_clkb)(void); // switch callback
} gl_ctrl_p;

void ctrl_init( void );
