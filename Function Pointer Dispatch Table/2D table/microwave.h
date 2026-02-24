#ifndef MICROWAVE_H
#define MICROWAVE_H

// define the Microwave struct
typedef struct Microwave Microwave;

// define the events that can occur in the microwave
typedef enum {
  EVENT_START,
  EVENT_STOP,
  EVENT_TIMER_DONE,
  MAX_EVENTS
} MicrowaveEvent;

// function prototypes for the microwave
Microwave* Microwave_create();
void Microwave_destroy(Microwave* m);
void Microwave_press_button(Microwave* m, MicrowaveEvent e);

#endif