#include <msp430.h>
#include "led.h"

	.arch msp430g2553
	.p2align 1,0
	.text
	
	.extern green_on
	.extern led_changed
	.extern led_update
	.global toggle_green()

	.data
	
toggle_green:
	xor 1, green_on
	mov 1, led_changed
	call led_update
