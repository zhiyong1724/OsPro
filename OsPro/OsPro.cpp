#include "OsPro.h"
#include "LCD_Private.h" 
#include "GUI.h"
#include "WM.h"
#include "FRAMEWIN.h"
#include "TEXT.h"
#include "BUTTON.h"
#include <stdio.h>
#include "vtos.h"
#include "FileBrower.h"
#include "EDIT.h"
#include "BUTTON.h"
static PaintWidget *s_PaintWidget = NULL;
void LCD_L0_SetPixelIndex(int x, int y, int PixelIndex)
{
	s_PaintWidget->setPixelIndex(x, y, PixelIndex);
}

unsigned int LCD_L0_GetPixelIndex(int x, int y)
{
	return s_PaintWidget->getPixelIndex(x, y);
}

static DWORD task(LPVOID lpThreadParameter)
{
	os_sys_start();
	return 0;
}

static void updateUI(void *p_arg)
{
	for (;;)
	{
		GUI_Exec();
		s_PaintWidget->updateUI();
		os_sleep(30);
	}
}

OsPro::OsPro(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	s_PaintWidget = ui.CentralWidget;
	connect(s_PaintWidget, SIGNAL(updateUI()), s_PaintWidget, SLOT(doUpdateUI()));
	
	if (0 == os_sys_init())
	{
		mHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)task, NULL, 0, NULL);
		SetThreadPriority(mHandle, THREAD_PRIORITY_TIME_CRITICAL);

		GUI_Init(); //GUI 初始化
		GUI_SetFont(&GUI_FontF13X13_CN);
		EDIT_SetDefaultFont(&GUI_FontF13X13_CN);
		BUTTON_SetDefaultFont(&GUI_FontF13X13_CN);
		GUI_UC_SetEncodeUTF8();
		
		setupFileBrower(WM_GetDesktopWindow());

		os_thread_create(updateUI, NULL, "updateUI");
	}
}

OsPro::~OsPro()
{
	os_sys_uninit();
	CloseHandle(mHandle);
}
