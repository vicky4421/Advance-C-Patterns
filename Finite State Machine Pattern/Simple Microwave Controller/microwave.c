#include "../microwave.h"

#include <stdio.h>
#include <stdlib.h>

// Microwave states
typedef enum { STATE_IDLE, STATE_HEATING, STATE_PAUSED } MicrowaveState;

// Microwave structure definition
struct Microwave {
  MicrowaveState current_state;
};

// Microwave constructor
Microwave* Microwave_Create() {
  Microwave* microwave = malloc(sizeof(Microwave));
  if (microwave) microwave->current_state = STATE_IDLE;
  return microwave;
}

// Microwave destructor
void Microwave_Destroy(Microwave* microwave) { free(microwave); }

// Microwave event processing
void Microwave_Process_Event(Microwave* microwave, MicrowaveEvent event) {
  switch (microwave->current_state) {
    case STATE_IDLE:
      if (event == EVENT_START) {
        printf("[IDLE -> HEATING] Starting microwave...");
        microwave->current_state = STATE_HEATING;
      }
      break;

    case STATE_HEATING:
      if (event == EVENT_STOP) {
        printf("[HEATING -> PAUSED] Suspending operations.\n");
        microwave->current_state = STATE_PAUSED;
      } else if (event == EVENT_TIMER_EXPIRED) {
        printf("[HEATING -> IDLE] Food finished! Beep!\n");
        microwave->current_state = STATE_IDLE;
      }
      break;

    case STATE_PAUSED:
      if (event == EVENT_START) {
        printf("[PAUSED -> HEATING] Resuming...\n");
        microwave->current_state = STATE_HEATING;
      } else if (event == EVENT_STOP) {
        printf("[PAUSED -> IDLE] Resetting timer.\n");
        microwave->current_state = STATE_IDLE;
      }
      break;

    default:
      break;
  }
}