#include "timer.h"
#include "2440addr.h"
void irq_handler()
{
	switch (rINTOFFSET)
	{
	case 14:
	{
		//INT_TIMER4
		timer4_handler();
		break;
	}
	case 31:
	{
		//INT_ADC
		AdcTsAuto();
		break;
	}
	}
}

/*void swi_handler()
{
}*/

