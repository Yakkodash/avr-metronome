#pragma once

#include <stdint.h>

#define MTRNM_MAX_BPM 500
#define MTRNM_MIN_BPM 15

#define MTRNM_MAX_BEATS 99
#define MTRNM_MIN_BEATS 1

#define MTRNM_MAX_SUBDIVS 9
#define MTRNM_MIN_SUBDIVS 1

#define MTRNM_MAX_BEEP_MS 20
#define MTRNM_MIN_BEEP_MS 7

#define MTRNM_MAX_INC_BAR 99
#define MTRNM_MIN_INC_BAR 1

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

struct mtrnm_p_s {

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

  uint16_t  freq_weak;
  uint16_t  freq_strong;
  uint16_t  freq_subdiv;

  uint8_t   swing_en;
  uint8_t   accent_en;
  uint8_t   cntdwn_en;

  uint8_t   inc_bar; // bar increment
  uint16_t  inc_bpm; // bpm increment

} gl_mtrnm_p;

void mtrnm_change_mode( mtrnm_mode_t mode );
void mtrnm_start( void );
void mtrnm_stop( void );
void mtrnm_reset( void );
