#include "microwave.h"

int main() {
  Microwave* myOven = Microwave_Create();

  Microwave_Process_Event(myOven, EVENT_START);
  Microwave_Process_Event(myOven, EVENT_STOP);
  Microwave_Process_Event(myOven, EVENT_START);
  Microwave_Process_Event(myOven, EVENT_TIMER_EXPIRED);

  Microwave_Destroy(myOven);
  return 0;
}