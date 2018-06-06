#pragma execution_character_set("utf-8")
#include "OsPro.h"
#include "LCD_Private.h" 
#include "GUI.h"
#include "WM.h"
#include "FRAMEWIN.h"
#include "TEXT.h"
#include "BUTTON.h"
#include <stdio.h>
static PaintWidget *s_PaintWidget = NULL;
void LCD_L0_SetPixelIndex(int x, int y, int PixelIndex)
{
	s_PaintWidget->setPixelIndex(x, y, PixelIndex);
}

unsigned int LCD_L0_GetPixelIndex(int x, int y)
{
	return s_PaintWidget->getPixelIndex(x, y);
}

OsPro::OsPro(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	s_PaintWidget = ui.CentralWidget;
	GUI_Init(); //GUI ≥ı ºªØ
	GUI_SetFont(&GUI_FontF13X13_CN);
	GUI_UC_SetEncodeUTF8();

	FRAMEWIN_Handle hFrame = FRAMEWIN_Create("frame", NULL, WM_CF_SHOW, 0, 0, 400, 240);
	FRAMEWIN_SetActive(hFrame, 1);
	FRAMEWIN_SetMoveable(hFrame, 1);
	FRAMEWIN_AddMaxButton(hFrame, FRAMEWIN_BUTTON_RIGHT, 0);
	FRAMEWIN_AddMinButton(hFrame, FRAMEWIN_BUTTON_RIGHT, 1);
}
