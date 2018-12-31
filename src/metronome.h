#pragma once

#include <stdint.h>

#define MTRNM_MAX_BPM 300
#define MTRNM_MIN_BPM 15

#define MTRNM_MAX_SUBDIV 8

#define MTRNM_MAX_BEEP_MS 20
#define MTRNM_MIN_BEEP_MS 5

void mtrnm_start( void );
void mtrnm_stop( void );
void mtrnm_reset( void );

typedef enum {
  STRONG_BEAT_START,
  WEAK_BEAT_START,
  SUBDIV_BEAT_START,
  BEAT_END
} mtrnm_fsm_t;

typedef enum {
  MTRNM_CONST,
  MTRNM_PROGRESSIVE
} mtrnm_mode_t;

extern struct mtrnm_s {

  mtrnm_fsm_t   state;
  mtrnm_mode_t  mode;

  uint16_t  bpm;
  uint16_t  beat_ms;
  uint8_t   beats;
  uint8_t   subdiv;

  uint8_t   beep_ms;

  uint16_t  weak_freq;
  uint16_t  strong_freq;
  uint16_t  subdiv_freq;
  
  uint8_t   cur_beat;
  uint8_t   cur_subdiv;

  uint8_t   swing;
  uint8_t   accent_en;

  // For progressive mode
  uint16_t  target_bpm;
  uint16_t  inc_bar;
  uint16_t  inc_bpm;
  uint16_t  cur_inc_bar;
  uint16_t  cur_bpm;

} gl_mtrnm_p;

