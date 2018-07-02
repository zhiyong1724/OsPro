#include "led.h"
#include "def.h"
#include "2440addr.h"
void led_init()
{
	rGPBCON &= 0xfffd57ff;
	rGPBCON |= 0x00015400;
	rGPBDAT |= 0x0f << 5;
}

void led_on(int led_type)
{
	switch(led_type)
	{
	case LED_1:
	{
		rGPBDAT &= 0xffffffdf;
		break;
	}
	case LED_2:
	{
		rGPBDAT &= 0xffffffbf;
		break;
	}
	case LED_3:
	{
		rGPBDAT &= 0xffffff7f;
		break;
	}
	case LED_4:
	{
		rGPBDAT &= 0xfffffeff;
		break;
	}
	}
}
void led_off(int led_type)
{
	switch (led_type)
	{
	case LED_1:
	{
		rGPBDAT |= 0x00000020;
		break;
	}
	case LED_2:
	{
		rGPBDAT |= 0x00000040;
		break;
	}
	case LED_3:
	{
		rGPBDAT |= 0x00000080;
		break;
	}
	case LED_4:
	{
		rGPBDAT |= 0x00000100;
		break;
	}
	}
}
