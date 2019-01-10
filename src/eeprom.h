#pragma once

#include <stdint.h>
#include <avr/eeprom.h>

void eeprom_save_mtrnm_set( void );
void eeprom_save_sound_set( void ); // save sound settings on exit from settings menu
void eeprom_load_mtrnm_set( void );
