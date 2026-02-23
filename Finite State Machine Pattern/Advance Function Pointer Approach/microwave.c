#include "../microwave.h"

#include <stdio.h>
#include <stdlib.h>

// Forward declaration of the Microwave struct
struct Microwave;

// Define a function pointer type for state functions
typedef void (*StateFunc)(struct Microwave* m, MicrowaveEvent e);

// Define the Microwave struct with a function pointer to the current state
struct Microwave {
  StateFunc current_state;
};

// State function prototypes
static void state_idle(struct Microwave* m, MicrowaveEvent e);
static void state_heating(struct Microwave* m, MicrowaveEvent e);
static void state_paused(struct Microwave* m, MicrowaveEvent e);

// State function for IDLE state
static void state_idle(struct Microwave* m, MicrowaveEvent e) {
  if (e == EVENT_START) {
    printf("[IDLE] -> Switching to HEATING\n");
    m->current_state = state_heating;
  }
}

// State function for HEATING state
static void state_heating(struct Microwave* m, MicrowaveEvent e) {
  if (e == EVENT_STOP) {
    printf("[HEATING] -> Switching to PAUSED\n");
    m->current_state = state_paused;
  } else if (e == EVENT_TIMER_EXPIRED) {
    printf("[HEATING] -> Timer finished. IDLE.\n");
    m->current_state = state_idle;
  }
}

// State function for PAUSED state
static void state_paused(struct Microwave* m, MicrowaveEvent e) {
  if (e == EVENT_START) {
    printf("[PAUSED] -> Resuming to HEATING\n");
    m->current_state = state_heating;
  }
}

// Public API functions
Microwave* Microwave_Create() {
  Microwave* microwave = malloc(sizeof(struct Microwave));
  if (microwave) microwave->current_state = state_idle;
  return microwave;
}

// Process events by calling the current state function
void Microwave_Process_Event(Microwave* microwave, MicrowaveEvent event) {
  if (microwave->current_state) microwave->current_state(microwave, event);
}

// Clean up the microwave instance
void Microwave_Destroy(Microwave* microwave) { free(microwave); }