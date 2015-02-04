#include <pic12f675.h>

static __code int __at(_CONFIG) 
	config = _FOSC_INTRCIO
	        & _WDT_OFF
	        & _PWRTE_ON
	        & _MCLRE_OFF;

void isr() __interrupt 0 {
	T0IF = 0;
	T0IE = 0;
}

void wait(int time_ms) {
	static unsigned char t_adj = 50;
	while (time_ms--) {
		TMR0 = t_adj;
		T0IE = 1;
		OPTION_REG = 1;
		while (T0IE) {
			__asm
				nop
				nop
				nop
				nop
			__endasm;
		}
		OPTION_REG = 0;
	}
}

void main() {

	// reset
	OPTION_REG = 0;
	ANSEL      = 0;
	CMCON      = 0x07;
	TRISIO     = 0;
	GPIO       = 0;
	GIE  = 1;

#define LED    GP5
#define BUZZER GP2

	// main loop
	for (;;) {
/*
		LED = 1;
		wait(100);
		LED = 0;
		wait(400);
*/
		BUZZER = 1;
		wait(1);
		BUZZER = 0;
		wait(1);
	}

}

