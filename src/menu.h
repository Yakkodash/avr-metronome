#pragma once
#include <stdint.h>

#define MENU_OUTPUT_BUF_LEN 8
#define MENU_OUTPUT_DIG_LEN 4

typedef enum {
  MENU_CONST = 0,
  MENU_PROG,
  MENU_SETT,
  MENU_CNT
} menu_type_t;

typedef struct menu_item_s {
  void (*left_clbk)(void);   // do on left turn of encoder
  void (*left_pushed_clbk)(void);   // do on left turn of encoder

  void (*right_clbk)(void);  // do on right turn of encoder
  void (*right_pushed_clbk)(void);  // do on right turn of encoder

  void (*print_clbk)(void);  // print while not turning encoder
} menu_item_t;

typedef struct menu_s {
  void (*do_on_entry_clbk)(void);
  void (*do_on_btn_clbk)(void);
  const menu_item_t *items;
} menu_t;

void menu_tick( void );

void menu_forward_item( void );
void menu_backward_item( void );

void menu_change_menu( menu_type_t m );
void menu_forward_menu( void );

void menu_rot_left( void );
void menu_rot_right( void );

void menu_rot_left_pushed( void );
void menu_rot_right_pushed( void );

void menu_btn( void );

void menu_change_mode_main( void );
void menu_change_mode_prog( void );
void menu_change_mode_sett( void );
