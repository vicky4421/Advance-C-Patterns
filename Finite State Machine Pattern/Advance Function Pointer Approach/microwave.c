#include "../microwave.h"

#include <stdio.h>
#include <stdlib.h>

struct Microwave;

typedef void (*StateFunc)(struct Microwave* m, MicrowaveEvent e);

struct Microwave {
  StateFunc current_state;
};

static void state_idle(struct Microwave* m, MicrowaveEvent e);
static void state_heating(struct Microwave* m, MicrowaveEvent e);
static void state_paused(struct Microwave* m, MicrowaveEvent e);

static void state_idle(struct Microwave* m, MicrowaveEvent e) {
  if (e == EVENT_START) {
    printf("[IDLE] -> Switching to HEATING\n");
    m->current_state = state_heating;
  }
}

static void state_heating(struct Microwave* m, MicrowaveEvent e) {
  if (e == EVENT_STOP) {
    printf("[HEATING] -> Switching to PAUSED\n");
    m->current_state = state_paused;
  } else if (e == EVENT_TIMER_EXPIRED) {
    printf("[HEATING] -> Timer finished. IDLE.\n");
    m->current_state = state_idle;
  }
}

static void state_paused(struct Microwave* m, MicrowaveEvent e) {
  if (e == EVENT_START) {
    printf("[PAUSED] -> Resuming to HEATING\n");
    m->current_state = state_heating;
  }
}

Microwave* Microwave_Create() {
  Microwave* microwave = malloc(sizeof(struct Microwave));
  if (microwave) microwave->current_state = state_idle;
  return microwave;
}

void Microwave_Process_Event(Microwave* microwave, MicrowaveEvent event) {
  if (microwave->current_state) microwave->current_state(microwave, event);
}

void Microwave_Destroy(Microwave* microwave) { free(microwave); }