#include <stdint.h>
#include <string.h>
#include "taptempo.h"
#include "timer.h"
#include "metronome.h"

#define TAP_MIN_INTERVAL ( 60e6 / MTRNM_MIN_BPM )
#define TAP_ARR_SIZ 16

static uint8_t tap_cnt = 0;
static uint32_t cur_time = 0;
static uint32_t last_time = 0;

static uint32_t intervals[128] = { 0 };
static uint32_t interval = 0;

static uint32_t avg_weighted( uint32_t a[], uint8_t len ) {
  uint8_t i = 0;
  double avg_denom = 0;
  double avg_nom = 0;
  for( i = 0; i < len; i++ ) {
    avg_denom += ( i + 1 ) / len;
    avg_nom += ( ( i + 1 ) / len ) * a[i];
  }

  return (uint32_t) ( avg_nom / avg_denom );
}

void tap( ) {
  cur_time = timer_get_us( );
  if( cur_time - last_time >= TAP_MIN_INTERVAL ) {
    tap_cnt = 0;
    last_time = 0;
    memset( intervals, 0, sizeof( intervals ) );
  } 

  if( tap_cnt > 0 ) {
    intervals[tap_cnt - 1] = cur_time - last_time;
  }

  interval = avg_weighted( intervals, tap_cnt );
  last_time = cur_time;
  tap_cnt++;

  if( tap_cnt > 1 ) {
    gl_mtrnm_p.active_bpm = (60e6 / interval) > MTRNM_MAX_BPM ? MTRNM_MAX_BPM : 60e6 / interval;
    gl_mtrnm_p.start_bpm = (60e6 / interval) > MTRNM_MAX_BPM ? MTRNM_MAX_BPM : 60e6 / interval;
  }
}

