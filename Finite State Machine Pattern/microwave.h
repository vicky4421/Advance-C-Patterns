#ifndef MICROWAVE_H
#define MICROWAVE_H

// Microwave events
typedef enum {
  EVENT_START,
  EVENT_STOP,
  EVENT_TIMER_EXPIRED,
} MicrowaveEvent;

// Forward declaration of the Microwave struct
typedef struct Microwave Microwave;

// Function prototypes
Microwave* Microwave_Create();
void Microwave_Destroy(Microwave* microwave);
void Microwave_Process_Event(Microwave* microwave, MicrowaveEvent event);

#endif  // MICROWAVE_H