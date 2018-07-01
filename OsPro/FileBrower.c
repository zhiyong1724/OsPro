#ifdef __WINDOWS__
#pragma execution_character_set("utf-8")
#endif
#include "FileBrowerDLG.h"
WM_HWIN setupFileBrower(WM_HWIN parent)
{
	WM_HWIN handle = CreateFileBrower(parent);
	WM_HWIN pathText = WM_GetDialogItem(parent, ID_TEXT_0);
	TEXT_SetBkColor(pathText, GUI_WHITE);
	return handle;
}