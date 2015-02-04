#include <pic12f675.h>

static __code int __at(_CONFIG) 
	config = _FOSC_INTRCIO
	        & _WDT_OFF
	        & _PWRTE_ON
	        & _MCLRE_OFF;

void main() {
	int t;
	int t_on  = 1000;
	int t_off = 4000; 

	// reset
	OPTION_REG = 0;
	ANSEL      = 0;
	CMCON      = 0x07;
	TRISIO     = 0;
	GPIO       = 0;

#define LED GP5
	
	for (;;) {
		LED = 1;
		for (t = 0; t < t_on;  ++t) ;
		LED = 0;
		for (t = 0; t < t_off; ++t) ;
	}

}

