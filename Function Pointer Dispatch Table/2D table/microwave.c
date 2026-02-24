#include "microwave.h"

#include <stdio.h>
#include <stdlib.h>

// Define the states of the microwave
typedef enum {
  STATE_IDLE,
  STATE_HEATING,
  STATE_PAUSED,
  MAX_STATES
} MicrowaveState;

// Define the Microwave struct
struct Microwave {
  MicrowaveState current_state;
};

// Define the function pointer type for actions
typedef void (*ActionFunc)(Microwave* m);

// Action functions for doing nothing (for invalid transitions)
static void do_nothing(Microwave* m) {}

// Action function for starting the heat
static void start_heat(Microwave* m) {
  printf("Heating ON\n");
  m->current_state = STATE_HEATING;
}

// Action function for pausing the heat
static void pause_heat(Microwave* m) {
  printf("Heating PAUSED\n");
  m->current_state = STATE_PAUSED;
}

// Action function for finishing the cook
static void finish_cook(Microwave* m) {
  printf("BEEP! DONE!\n");
  m->current_state = STATE_IDLE;
}

// Action function for resetting to idle from paused state
static void reset_idle(Microwave* m) {
  printf("Reset to IDLE!\n");
  m->current_state = STATE_IDLE;
}

// 2D Array representing the state transition table
static ActionFunc microwave_grid[MAX_STATES][MAX_EVENTS] = {
    [STATE_IDLE] = {start_heat, do_nothing, do_nothing},
    [STATE_HEATING] = {do_nothing, pause_heat, finish_cook},
    [STATE_PAUSED] = {start_heat, reset_idle, do_nothing}};

// Function implementations
Microwave* Microwave_create() {
  Microwave* m = malloc(sizeof(struct Microwave));
  if (m) m->current_state = STATE_IDLE;
  return m;
}

void Microwave_press_button(Microwave* m, MicrowaveEvent e) {
  if (e >= MAX_EVENTS) return;
  ActionFunc action = microwave_grid[m->current_state][e];
  action(m);
}

void Microwave_destroy(Microwave* m) { free(m); }