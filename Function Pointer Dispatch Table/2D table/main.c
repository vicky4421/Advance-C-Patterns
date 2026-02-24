#include "microwave.h"

int main() {
  Microwave* oven = Microwave_create();

  // Imagine the user pressing buttons
  Microwave_press_button(oven, EVENT_START);       // Output: -> HEATING ON
  Microwave_press_button(oven, EVENT_STOP);        // Output: -> HEATING PAUSED
  Microwave_press_button(oven, EVENT_START);       // Output: -> HEATING ON
  Microwave_press_button(oven, EVENT_TIMER_DONE);  // Output: -> BEEP! DONE!

  Microwave_destroy(oven);
  return 0;
}
