#ifdef __WINDOWS__
#pragma execution_character_set("utf-8")
#endif
#include "FileBrowerDLG.h"
WM_HWIN setupFileBrower(WM_HWIN parent)
{
	WM_HWIN handle =  CreateFileBrower(parent);
	WM_HWIN pathText = WM_GetDialogItem(parent, ID_TEXT_0);
	WM_DisableWindow(pathText);
	TEXT_SetBkColor(pathText, GUI_WHITE);
#ifndef __WINDOWS__
	WM_HideWindow(WM_GetDialogItem(parent, ID_BUTTON_6));
	WM_HideWindow(WM_GetDialogItem(parent, ID_BUTTON_7));
#endif
	return handle;
}