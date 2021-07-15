#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  if (++blink_count == 250) {         //every 1/4 of a second 
    state_advance();
    switch_interrupt_handler();
    blink_count = 0;
  }

  static char buzz_count = 0;
  if (++buzz_count == 12) {          //every 1/20 of a second so the buzzer advances fast
    buzzer_advance();
    buzz_count = 0;
  }
}

