#pragma once

#include <stdint.h>

#include "notes.h"

#define MTRNM_MAX_BPM 500
#define MTRNM_MIN_BPM 15

#define MTRNM_MAX_BEATS 32
#define MTRNM_MIN_BEATS 1

#define MTRNM_MAX_SUBDIVS 9
#define MTRNM_MIN_SUBDIVS 1

#define MTRNM_MAX_BEEP_MS 20
#define MTRNM_MIN_BEEP_MS 5

#define MTRNM_MAX_INC_BAR 99
#define MTRNM_MIN_INC_BAR 1

#define DFLT_LED_EN       1
#define DFLT_BEEP_MS      7
#define DFLT_STRONG_NOTE  G7
#define DFLT_WEAK_NOTE    Ab6
#define DFLT_SUBDIV_NOTE  A4

typedef enum {
  STRONG_BEAT_START,
  WEAK_BEAT_START,
  SUBDIV_BEAT_START,
  BEAT_END
} mtrnm_fsm_t;

typedef enum {
  MTRNM_MODE_CONST,
  MTRNM_MODE_PROG
} mtrnm_mode_t;

extern volatile struct mtrnm_p_s {

  mtrnm_fsm_t   state;
  mtrnm_mode_t  mode;

  uint8_t   cur_bar;
  uint8_t   cur_beat;
  uint8_t   cur_subdiv;
  uint8_t   cur_cntdwn;

  uint16_t  target_bpm;
  uint16_t  active_bpm;
  uint16_t  start_bpm;

  uint16_t  beat_ms;

  uint8_t   beats;
  uint8_t   subdivs;

  uint8_t   beep_ms;

  note_t    note_weak;
  note_t    note_strong;
  note_t    note_subdiv;

  uint8_t   swing_en;
  uint8_t   accent_en;
  uint8_t   cntdwn_en;
  uint8_t   led_en;

  uint8_t   inc_bar; // bar increment
  uint16_t  inc_bpm; // bpm increment

} gl_mtrnm_p;

void mtrnm_change_mode( mtrnm_mode_t mode );
void mtrnm_start( void );
void mtrnm_stop( void );

void mtrnm_reset_const( void );
void mtrnm_reset_prog( void );
void mtrnm_reset_sett( void );
