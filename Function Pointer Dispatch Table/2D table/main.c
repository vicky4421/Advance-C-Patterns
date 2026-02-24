#include "microwave.h"

// This file implements the microwave state machine using a 2D function pointer
// dispatch table.
int main() {
  // Create a microwave instance
  Microwave* oven = Microwave_create();

  // Imagine the user pressing buttons
  Microwave_press_button(oven, EVENT_START);       // Output: -> HEATING ON
  Microwave_press_button(oven, EVENT_STOP);        // Output: -> HEATING PAUSED
  Microwave_press_button(oven, EVENT_START);       // Output: -> HEATING ON
  Microwave_press_button(oven, EVENT_TIMER_DONE);  // Output: -> BEEP! DONE!

  // Clean up
  Microwave_destroy(oven);
  return 0;
}
