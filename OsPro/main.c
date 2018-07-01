#include "2440lib.h"
#include "timer.h"
#include "LCD_TFT.h"
#include "led.h"
#include "vtos.h"
#include "GUI.h"
#include "FRAMEWIN.h"
#include "SD_MMC.h"
#include "FileBrower.h"
#include "EDIT.h"
#include "BUTTON.h"
static void task_a(void *p_arg)
{
	int s_state = 0;
	for (;;)
	{
		if (0 == s_state)
		{
			s_state = 1;
			led_on(LED_4);
		}
		else
		{
			s_state = 0;
			led_off(LED_4);
		}
		os_sleep(500);
	}
}

static void ui_thread(void *p_arg)
{
	os_set_prio(15);
	for (;;)
	{
		GUI_Exec();
		LCD_copy_to_screen();
		os_sleep(30);
	}
}

int main()
{
	led_init();
	Port_Init();
	Uart_Select(0);
	Uart_Init(0, 115200);
	Test_SDI();
	Init_Touchpanel();
	Lcd_TFT_Init();
	GUI_Init(); //GUI ≥ı ºªØ
	GUI_SetFont(&GUI_FontF13X13_CN);
	EDIT_SetDefaultFont(&GUI_FontF13X13_CN);
	BUTTON_SetDefaultFont(&GUI_FontF13X13_CN);
	GUI_UC_SetEncodeUTF8();
	setupFileBrower(WM_GetDesktopWindow());

	timer4_init();
	if (os_sys_init() == 0)
	{
		os_thread_create(task_a, NULL, "task_a");
		os_thread_createEX(ui_thread, NULL, "ui_thread", 1024 * 1024);
		os_sys_start();
	}
	return 0;
}

