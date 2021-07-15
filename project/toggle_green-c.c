#include <msp430.h>
#include "led.h"

void toggle_green()
{
  green_on ^= 1;
  led_changed = 1;
  led_update();
}
