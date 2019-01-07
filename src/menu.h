#pragma once
#include <stdint.h>

typedef struct menu_item_s {
  void (*menu_enc_left_clbk)(void);   // do on left turn of encoder
  void (*menu_enc_rigth_clbk)(void);  // do on right turn of encoder
  void (*menu_print_clbk)(void); // print while not turning encoder
} menu_item_t;

void menu_tick( void );
void menu_forward_item( void );
void menu_back_item( void );
