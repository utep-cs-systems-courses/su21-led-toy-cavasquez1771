#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"


void state_advance()
{
  // Toggles green led and buzzer
  if (switch_state_down_1) {
    toggle_green();

    if (green_on)
      buzzer_set_period(2345);
    else
      buzzer_set_period(0);
  }

  // Toggles red led and buzzer
  else if (switch_state_down_2) {
    toggle_red();

    if (red_on)
      buzzer_set_period(3456);
    else
      buzzer_set_period(0);
  }
  
  // Turn lights and buzzer off
  else if (switch_state_down_4) {
    turn_off_rg();
    buzzer_set_period(0);
  }
}

void buzzer_advance()
{
  // Play descending sounds on buzzer
  if (switch_state_down_3) {
    buzzer_set_period(0);
    static int state = 0;

    switch (state) {
    case 0: buzzer_set_period(1000); state++; break;
    case 1: buzzer_set_period(1200); state++; break;
    case 2: buzzer_set_period(1400); state++; break;
    case 3: buzzer_set_period(1600); state++; break;
    case 4: buzzer_set_period(1800); state++; break;
    case 5: buzzer_set_period(2000); state++; break;
    case 6: buzzer_set_period(2200); state++; break;
    case 7: buzzer_set_period(2400); state++; break;
    case 8: buzzer_set_period(2600); state++; break;
    case 9: buzzer_set_period(2800); state++; break;
    case 10: buzzer_set_period(3000); state++; break;
    case 11: buzzer_set_period(3200); state++; break;
    case 12: buzzer_set_period(3400); state++; break;
    case 13: buzzer_set_period(3600); state++; break;
    case 14: buzzer_set_period(3800); state++; break;
    case 15: buzzer_set_period(4000); state++; break;
    default: state = 0;
    }
  }
}
void toggle_green();

void toggle_red()
{
  red_on ^= 1;
  led_changed = 1;
  led_update();
}

void turn_off_rg()
{
  green_on = 0;
  red_on = 0;
  led_changed = 1;
  led_update();
}

