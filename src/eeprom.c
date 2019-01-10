#include "eeprom.h"
#include "metronome.h"

static uint16_t e_bpm EEMEM;
static uint16_t e_target_bpm EEMEM;

static uint8_t  e_beats EEMEM;
static uint8_t  e_subdivs EEMEM;

static uint8_t  e_accent_en EEMEM;
static uint8_t  e_swing_en EEMEM;

static uint16_t e_inc_bpm EEMEM;
static uint8_t  e_inc_bar EEMEM;
static uint8_t  e_cntdwn_en EEMEM;

static uint8_t  e_note_strong EEMEM;
static uint8_t  e_note_weak EEMEM;
static uint8_t  e_note_subdiv EEMEM;

static uint8_t  e_led_en EEMEM;
static uint8_t  e_beep_ms EEMEM;

void eeprom_save_mtrnm_set( void ) {
  eeprom_write_word( &e_bpm, gl_mtrnm_p.start_bpm );
  eeprom_write_word( &e_target_bpm, gl_mtrnm_p.target_bpm );

  eeprom_write_byte( &e_subdivs, gl_mtrnm_p.subdivs );
  eeprom_write_byte( &e_beats, gl_mtrnm_p.beats );

  eeprom_write_byte( &e_accent_en, gl_mtrnm_p.accent_en );
  eeprom_write_byte( &e_swing_en, gl_mtrnm_p.swing_en );

  eeprom_write_word( &e_inc_bpm, gl_mtrnm_p.inc_bpm );
  eeprom_write_byte( &e_inc_bar, gl_mtrnm_p.inc_bar );
  eeprom_write_byte( &e_cntdwn_en, gl_mtrnm_p.cntdwn_en );
}

void eeprom_save_sound_set( void ) {
  eeprom_write_byte( &e_note_strong, gl_mtrnm_p.note_strong );
  eeprom_write_byte( &e_note_weak, gl_mtrnm_p.note_weak );
  eeprom_write_byte( &e_note_weak, gl_mtrnm_p.note_weak );

  eeprom_write_byte( &e_led_en, gl_mtrnm_p.led_en );
  eeprom_write_byte( &e_beep_ms, gl_mtrnm_p.beep_ms );
}

void eeprom_load_mtrnm_set( void ) {

  uint16_t var16;
  uint8_t var8;

  var16 = eeprom_read_word( &e_bpm );
  if( var16 >= MTRNM_MIN_BPM && var16 <= MTRNM_MAX_BPM ) gl_mtrnm_p.active_bpm = gl_mtrnm_p.start_bpm = var16;

  var16 = eeprom_read_word( &e_target_bpm );
  if( var16 >= MTRNM_MIN_BPM && var16 <= MTRNM_MAX_BPM ) gl_mtrnm_p.target_bpm = var16;

  var8 = eeprom_read_byte( &e_subdivs );
  if( var8 >= MTRNM_MIN_SUBDIVS && var8 <= MTRNM_MAX_SUBDIVS ) gl_mtrnm_p.subdivs = var8;

  var8 = eeprom_read_byte( &e_beats );
  if( var8 >= MTRNM_MIN_BEATS && var8 <= MTRNM_MAX_BEATS ) gl_mtrnm_p.beats = var8;

  var8 = eeprom_read_byte( &e_accent_en );
  if( var8 == 0 || var8 == 1 ) gl_mtrnm_p.accent_en = var8;

  var8 = eeprom_read_byte( &e_swing_en );
  if( var8 == 0 || var8 == 1 ) gl_mtrnm_p.swing_en = var8;

  var16 = eeprom_read_word( &e_inc_bpm );
  if( var16 >= 1 && var16 <= MTRNM_MAX_BPM ) gl_mtrnm_p.inc_bpm = var16;

  var8 = eeprom_read_byte( &e_inc_bar );
  if( var8 >= MTRNM_MIN_BEATS && var8 <= MTRNM_MAX_BEATS ) gl_mtrnm_p.inc_bar = var8;

  var8 = eeprom_read_byte( &e_cntdwn_en );
  if( var8 == 0 || var8 == 1 ) gl_mtrnm_p.cntdwn_en = var8;

  var8 = eeprom_read_byte( &e_note_strong );
  if( var8 >= 0 && var8 < NOTES_CNT ) gl_mtrnm_p.note_strong = var8;

  var8 = eeprom_read_byte( &e_note_weak );
  if( var8 >= 0 && var8 < NOTES_CNT ) gl_mtrnm_p.note_weak = var8;

  var8 = eeprom_read_byte( &e_note_subdiv );
  if( var8 >= 0 && var8 < NOTES_CNT ) gl_mtrnm_p.note_subdiv = var8;

  var8 = eeprom_read_byte( &e_led_en );
  if( var8 == 0 || var8 == 1 ) gl_mtrnm_p.led_en = var8;

  var8 = eeprom_read_byte( &e_beep_ms );
  if( var8 >= MTRNM_MIN_BEEP_MS && var8 <= MTRNM_MAX_BEEP_MS ) gl_mtrnm_p.beep_ms = var8;
 // eeprom_write_byte( &e_led_en, gl_mtrnm_p.led_en );
//  eeprom_write_byte( &e_beep_ms, gl_mtrnm_p.beep_ms );
}
