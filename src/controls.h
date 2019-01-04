#pragma once

#include <avr/io.h>
#include <avr/interrupt.h>

extern struct ctrl_s {
  void (*ctrl_enc_a_callback)(void);
  void (*ctrl_enc_b_callback)(void);
  void (*ctrl_enc_btn_callback)(void);

  void (*ctrl_btn0_callback)(void);
  void (*ctrl_btn1_callback)(void);
} gl_ctrl_p;

void controls_init( void );

