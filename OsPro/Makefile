CC := arm-none-eabi-gcc
LD := arm-none-eabi-ld
CP := arm-none-eabi-objcopy
LIBS_PATH := -static --start-group -L/opt/EmbedSky/4.3.3/lib/gcc/arm-none-linux-gnueabi/4.3.3/armv4t -lgcc -L/opt/EmbedSky/4.3.3/armv4t/lib -lc -lm -lnosys --end-group
CFLAGS := -mfloat-abi=soft -march=armv4t -g -c 
INCLUDE_PATH := -I/opt/EmbedSky/4.3.3/armv4t/include -I../vtos/port/ -I../vtos/src/ -I../other/driver/inc/ -IUCGUI/Start/GUI/WM/ -IUCGUI/Start/GUI/Widget/ -IUCGUI/Start/GUI/Core/ -IUCGUIStart/JPEG/ -IUCGUI/Start/Config/
OBJS_PATH := objs/
ELF := vtos.elf
TARGET := vtos.bin
SRCS_S := 
OBJS_S := $(patsubst %.S, %.o, $(SRCS_S))
SRCS_C := UCGUI/Sample/GUI_X/GUI_X.c \
UCGUI/Start/AntiAlias/GUIAAArc.c \
UCGUI/Start/AntiAlias/GUIAAChar.c \
UCGUI/Start/AntiAlias/GUIAAChar2.c \
UCGUI/Start/AntiAlias/GUIAAChar4.c \
UCGUI/Start/AntiAlias/GUIAACircle.c \
UCGUI/Start/AntiAlias/GUIAALib.c \
UCGUI/Start/AntiAlias/GUIAALine.c \
UCGUI/Start/AntiAlias/GUIAAPoly.c \
UCGUI/Start/AntiAlias/GUIAAPolyOut.c \
UCGUI/Start/GUI/ConvertColor/LCDP111.c \
UCGUI/Start/GUI/ConvertColor/LCDP222.c \
UCGUI/Start/GUI/ConvertColor/LCDP233.c \
UCGUI/Start/GUI/ConvertColor/LCDP323.c \
UCGUI/Start/GUI/ConvertColor/LCDP332.c \
UCGUI/Start/GUI/ConvertColor/LCDP444_12.c \
UCGUI/Start/GUI/ConvertColor/LCDP444_12_1.c \
UCGUI/Start/GUI/ConvertColor/LCDP444_16.c \
UCGUI/Start/GUI/ConvertColor/LCDP555.c \
UCGUI/Start/GUI/ConvertColor/LCDP556.c \
UCGUI/Start/GUI/ConvertColor/LCDP565.c \
UCGUI/Start/GUI/ConvertColor/LCDP655.c \
UCGUI/Start/GUI/ConvertColor/LCDP666.c \
UCGUI/Start/GUI/ConvertColor/LCDP8666.c \
UCGUI/Start/GUI/ConvertColor/LCDP8666_1.c \
UCGUI/Start/GUI/ConvertColor/LCDP888.c \
UCGUI/Start/GUI/ConvertColor/LCDPM233.c \
UCGUI/Start/GUI/ConvertColor/LCDPM323.c \
UCGUI/Start/GUI/ConvertColor/LCDPM332.c \
UCGUI/Start/GUI/ConvertColor/LCDPM444_12.c \
UCGUI/Start/GUI/ConvertColor/LCDPM444_16.c \
UCGUI/Start/GUI/ConvertColor/LCDPM555.c \
UCGUI/Start/GUI/ConvertColor/LCDPM556.c \
UCGUI/Start/GUI/ConvertColor/LCDPM565.c \
UCGUI/Start/GUI/ConvertColor/LCDPM655.c \
UCGUI/Start/GUI/ConvertColor/LCDPM666.c \
UCGUI/Start/GUI/ConvertColor/LCDPM888.c \
UCGUI/Start/GUI/ConvertMono/LCDP0.c \
UCGUI/Start/GUI/ConvertMono/LCDP2.c \
UCGUI/Start/GUI/ConvertMono/LCDP4.c \
UCGUI/Start/GUI/Core/GUI2DLib.c \
UCGUI/Start/GUI/Core/GUIAlloc.c \
UCGUI/Start/GUI/Core/GUIArc.c \
UCGUI/Start/GUI/Core/GUIChar.c \
UCGUI/Start/GUI/Core/GUICharLine.c \
UCGUI/Start/GUI/Core/GUICharM.c \
UCGUI/Start/GUI/Core/GUICharP.c \
UCGUI/Start/GUI/Core/GUICirc.c \
UCGUI/Start/GUI/Core/GUIColor2Index.c \
UCGUI/Start/GUI/Core/GUICore.c \
UCGUI/Start/GUI/Core/GUICurs.c \
UCGUI/Start/GUI/Core/GUIEncJS.c \
UCGUI/Start/GUI/Core/GUIIndex2Color.c \
UCGUI/Start/GUI/Core/GUIPolyE.c \
UCGUI/Start/GUI/Core/GUIPolyM.c \
UCGUI/Start/GUI/Core/GUIPolyR.c \
UCGUI/Start/GUI/Core/GUIRealloc.c \
UCGUI/Start/GUI/Core/GUIStream.c \
UCGUI/Start/GUI/Core/GUITask.c \
UCGUI/Start/GUI/Core/GUITime.c \
UCGUI/Start/GUI/Core/GUITimer.c \
UCGUI/Start/GUI/Core/GUIUC0.c \
UCGUI/Start/GUI/Core/GUIVal.c \
UCGUI/Start/GUI/Core/GUIValf.c \
UCGUI/Start/GUI/Core/GUI_AddBin.c \
UCGUI/Start/GUI/Core/GUI_AddDec.c \
UCGUI/Start/GUI/Core/GUI_AddDecMin.c \
UCGUI/Start/GUI/Core/GUI_AddDecShift.c \
UCGUI/Start/GUI/Core/GUI_AddHex.c \
UCGUI/Start/GUI/Core/GUI_AddKeyMsgHook.c \
UCGUI/Start/GUI/Core/GUI_ALLOC_AllocInit.c \
UCGUI/Start/GUI/Core/GUI_ALLOC_AllocZero.c \
UCGUI/Start/GUI/Core/GUI_BMP.c \
UCGUI/Start/GUI/Core/GUI_BMP_Serialize.c \
UCGUI/Start/GUI/Core/GUI_CalcColorDist.c \
UCGUI/Start/GUI/Core/GUI_ClearRectEx.c \
UCGUI/Start/GUI/Core/GUI_Color2VisColor.c \
UCGUI/Start/GUI/Core/GUI_CursorArrowL.c \
UCGUI/Start/GUI/Core/GUI_CursorArrowLI.c \
UCGUI/Start/GUI/Core/GUI_CursorArrowLPx.c \
UCGUI/Start/GUI/Core/GUI_CursorArrowM.c \
UCGUI/Start/GUI/Core/GUI_CursorArrowMI.c \
UCGUI/Start/GUI/Core/GUI_CursorArrowMPx.c \
UCGUI/Start/GUI/Core/GUI_CursorArrowS.c \
UCGUI/Start/GUI/Core/GUI_CursorArrowSI.c \
UCGUI/Start/GUI/Core/GUI_CursorArrowSPx.c \
UCGUI/Start/GUI/Core/GUI_CursorCrossL.c \
UCGUI/Start/GUI/Core/GUI_CursorCrossLI.c \
UCGUI/Start/GUI/Core/GUI_CursorCrossLPx.c \
UCGUI/Start/GUI/Core/GUI_CursorCrossM.c \
UCGUI/Start/GUI/Core/GUI_CursorCrossMI.c \
UCGUI/Start/GUI/Core/GUI_CursorCrossMPx.c \
UCGUI/Start/GUI/Core/GUI_CursorCrossS.c \
UCGUI/Start/GUI/Core/GUI_CursorCrossSI.c \
UCGUI/Start/GUI/Core/GUI_CursorCrossSPx.c \
UCGUI/Start/GUI/Core/GUI_CursorHeaderM.c \
UCGUI/Start/GUI/Core/GUI_CursorHeaderMI.c \
UCGUI/Start/GUI/Core/GUI_CursorHeaderMPx.c \
UCGUI/Start/GUI/Core/GUI_CursorPal.c \
UCGUI/Start/GUI/Core/GUI_CursorPalI.c \
UCGUI/Start/GUI/Core/GUI_DispBin.c \
UCGUI/Start/GUI/Core/GUI_DispCEOL.c \
UCGUI/Start/GUI/Core/GUI_DispChar.c \
UCGUI/Start/GUI/Core/GUI_DispChars.c \
UCGUI/Start/GUI/Core/GUI_DispHex.c \
UCGUI/Start/GUI/Core/GUI_DispString.c \
UCGUI/Start/GUI/Core/GUI_DispStringAt.c \
UCGUI/Start/GUI/Core/GUI_DispStringAtCEOL.c \
UCGUI/Start/GUI/Core/GUI_DispStringHCenter.c \
UCGUI/Start/GUI/Core/GUI_DispStringInRect.c \
UCGUI/Start/GUI/Core/GUI_DispStringInRectEx.c \
UCGUI/Start/GUI/Core/GUI_DispStringInRectWrap.c \
UCGUI/Start/GUI/Core/GUI_DispStringLen.c \
UCGUI/Start/GUI/Core/GUI_DrawBitmap.c \
UCGUI/Start/GUI/Core/GUI_DrawBitmapEx.c \
UCGUI/Start/GUI/Core/GUI_DrawBitmapExp.c \
UCGUI/Start/GUI/Core/GUI_DrawBitmapMag.c \
UCGUI/Start/GUI/Core/GUI_DrawBitmap_555.c \
UCGUI/Start/GUI/Core/GUI_DrawBitmap_565.c \
UCGUI/Start/GUI/Core/GUI_DrawBitmap_888.c \
UCGUI/Start/GUI/Core/GUI_DrawFocusRect.c \
UCGUI/Start/GUI/Core/GUI_DrawGraph.c \
UCGUI/Start/GUI/Core/GUI_DrawGraphEx.c \
UCGUI/Start/GUI/Core/GUI_DrawHLine.c \
UCGUI/Start/GUI/Core/GUI_DrawLine.c \
UCGUI/Start/GUI/Core/GUI_DrawPie.c \
UCGUI/Start/GUI/Core/GUI_DrawPixel.c \
UCGUI/Start/GUI/Core/GUI_DrawPoint.c \
UCGUI/Start/GUI/Core/GUI_DrawPolygon.c \
UCGUI/Start/GUI/Core/GUI_DrawPolyline.c \
UCGUI/Start/GUI/Core/GUI_DrawRectEx.c \
UCGUI/Start/GUI/Core/GUI_DrawVLine.c \
UCGUI/Start/GUI/Core/GUI_ErrorOut.c \
UCGUI/Start/GUI/Core/GUI_Exec.c \
UCGUI/Start/GUI/Core/GUI_FillPolygon.c \
UCGUI/Start/GUI/Core/GUI_FillRect.c \
UCGUI/Start/GUI/Core/GUI_FillRectEx.c \
UCGUI/Start/GUI/Core/GUI_GetBitmapPixelColor.c \
UCGUI/Start/GUI/Core/GUI_GetBitmapPixelIndex.c \
UCGUI/Start/GUI/Core/GUI_GetClientRect.c \
UCGUI/Start/GUI/Core/GUI_GetColor.c \
UCGUI/Start/GUI/Core/GUI_GetDispPos.c \
UCGUI/Start/GUI/Core/GUI_GetDrawMode.c \
UCGUI/Start/GUI/Core/GUI_GetFont.c \
UCGUI/Start/GUI/Core/GUI_GetFontInfo.c \
UCGUI/Start/GUI/Core/GUI_GetFontSizeY.c \
UCGUI/Start/GUI/Core/GUI_GetLineStyle.c \
UCGUI/Start/GUI/Core/GUI_GetOrg.c \
UCGUI/Start/GUI/Core/GUI_GetStringDistX.c \
UCGUI/Start/GUI/Core/GUI_GetTextAlign.c \
UCGUI/Start/GUI/Core/GUI_GetTextExtend.c \
UCGUI/Start/GUI/Core/GUI_GetTextMode.c \
UCGUI/Start/GUI/Core/GUI_GetVersionString.c \
UCGUI/Start/GUI/Core/GUI_GetYSizeOfFont.c \
UCGUI/Start/GUI/Core/GUI_GIF.c \
UCGUI/Start/GUI/Core/GUI_Goto.c \
UCGUI/Start/GUI/Core/GUI_InitLUT.c \
UCGUI/Start/GUI/Core/GUI_InvertRect.c \
UCGUI/Start/GUI/Core/GUI_IsInFont.c \
UCGUI/Start/GUI/Core/GUI_Log.c \
UCGUI/Start/GUI/Core/GUI_MergeRect.c \
UCGUI/Start/GUI/Core/GUI_MOUSE.c \
UCGUI/Start/GUI/Core/GUI_MOUSE_DriverPS2.c \
UCGUI/Start/GUI/Core/GUI_MoveRect.c \
UCGUI/Start/GUI/Core/GUI_OnKey.c \
UCGUI/Start/GUI/Core/GUI_Pen.c \
UCGUI/Start/GUI/Core/GUI_PID.c \
UCGUI/Start/GUI/Core/GUI_RectsIntersect.c \
UCGUI/Start/GUI/Core/GUI_SaveContext.c \
UCGUI/Start/GUI/Core/GUI_ScreenSize.c \
UCGUI/Start/GUI/Core/GUI_SelectLayer.c \
UCGUI/Start/GUI/Core/GUI_SelectLCD.c \
UCGUI/Start/GUI/Core/GUI_SetClipRect.c \
UCGUI/Start/GUI/Core/GUI_SetColor.c \
UCGUI/Start/GUI/Core/GUI_SetColorIndex.c \
UCGUI/Start/GUI/Core/GUI_SetDecChar.c \
UCGUI/Start/GUI/Core/GUI_SetDefault.c \
UCGUI/Start/GUI/Core/GUI_SetDrawMode.c \
UCGUI/Start/GUI/Core/GUI_SetFont.c \
UCGUI/Start/GUI/Core/GUI_SetLBorder.c \
UCGUI/Start/GUI/Core/GUI_SetLineStyle.c \
UCGUI/Start/GUI/Core/GUI_SetLUTColor.c \
UCGUI/Start/GUI/Core/GUI_SetLUTColorEx.c \
UCGUI/Start/GUI/Core/GUI_SetLUTEntry.c \
UCGUI/Start/GUI/Core/GUI_SetOrg.c \
UCGUI/Start/GUI/Core/GUI_SetPixelIndex.c \
UCGUI/Start/GUI/Core/GUI_SetTextAlign.c \
UCGUI/Start/GUI/Core/GUI_SetTextMode.c \
UCGUI/Start/GUI/Core/GUI_SetTextStyle.c \
UCGUI/Start/GUI/Core/GUI_SIF.c \
UCGUI/Start/GUI/Core/GUI_SIF_Prop.c \
UCGUI/Start/GUI/Core/GUI_TOUCH.c \
UCGUI/Start/GUI/Core/GUI_TOUCH_DriverAnalog.c \
UCGUI/Start/GUI/Core/GUI_TOUCH_StoreState.c \
UCGUI/Start/GUI/Core/GUI_TOUCH_StoreUnstable.c \
UCGUI/Start/GUI/Core/GUI_UC.c \
UCGUI/Start/GUI/Core/GUI_UC_ConvertUC2UTF8.c \
UCGUI/Start/GUI/Core/GUI_UC_ConvertUTF82UC.c \
UCGUI/Start/GUI/Core/GUI_UC_DispString.c \
UCGUI/Start/GUI/Core/GUI_UC_EncodeNone.c \
UCGUI/Start/GUI/Core/GUI_UC_EncodeUTF8.c \
UCGUI/Start/GUI/Core/GUI_WaitEvent.c \
UCGUI/Start/GUI/Core/GUI_WaitKey.c \
UCGUI/Start/GUI/Core/GUI_Warn.c \
UCGUI/Start/GUI/Core/GUI__AddSpaceHex.c \
UCGUI/Start/GUI/Core/GUI__Arabic.c \
UCGUI/Start/GUI/Core/GUI__CalcTextRect.c \
UCGUI/Start/GUI/Core/GUI__DivideRound.c \
UCGUI/Start/GUI/Core/GUI__DivideRound32.c \
UCGUI/Start/GUI/Core/GUI__DrawBitmap16bpp.c \
UCGUI/Start/GUI/Core/GUI__GetCursorPos.c \
UCGUI/Start/GUI/Core/GUI__GetFontSizeY.c \
UCGUI/Start/GUI/Core/GUI__GetNumChars.c \
UCGUI/Start/GUI/Core/GUI__HandleEOLine.c \
UCGUI/Start/GUI/Core/GUI__IntersectRect.c \
UCGUI/Start/GUI/Core/GUI__IntersectRects.c \
UCGUI/Start/GUI/Core/GUI__memset.c \
UCGUI/Start/GUI/Core/GUI__memset16.c \
UCGUI/Start/GUI/Core/GUI__Read.c \
UCGUI/Start/GUI/Core/GUI__ReduceRect.c \
UCGUI/Start/GUI/Core/GUI__SetText.c \
UCGUI/Start/GUI/Core/GUI__strcmp.c \
UCGUI/Start/GUI/Core/GUI__strlen.c \
UCGUI/Start/GUI/Core/GUI__Wrap.c \
UCGUI/Start/GUI/Core/LCD.c \
UCGUI/Start/GUI/Core/LCDAA.c \
UCGUI/Start/GUI/Core/LCDColor.c \
UCGUI/Start/GUI/Core/LCDGetP.c \
UCGUI/Start/GUI/Core/LCDInfo.c \
UCGUI/Start/GUI/Core/LCDInfo0.c \
UCGUI/Start/GUI/Core/LCDInfo1.c \
UCGUI/Start/GUI/Core/LCDL0Delta.c \
UCGUI/Start/GUI/Core/LCDL0Mag.c \
UCGUI/Start/GUI/Core/LCDP1.c \
UCGUI/Start/GUI/Core/LCDP565_Index2Color.c \
UCGUI/Start/GUI/Core/LCDP888_Index2Color.c \
UCGUI/Start/GUI/Core/LCDPM565_Index2Color.c \
UCGUI/Start/GUI/Core/LCDPM888_Index2Color.c \
UCGUI/Start/GUI/Core/LCDRLE16.c \
UCGUI/Start/GUI/Core/LCDRLE4.c \
UCGUI/Start/GUI/Core/LCDRLE8.c \
UCGUI/Start/GUI/Core/LCD_API.c \
UCGUI/Start/GUI/Core/LCD_DrawVLine.c \
UCGUI/Start/GUI/Core/LCD_GetColorIndex.c \
UCGUI/Start/GUI/Core/LCD_GetEx.c \
UCGUI/Start/GUI/Core/LCD_GetNumDisplays.c \
UCGUI/Start/GUI/Core/LCD_GetPixelColor.c \
UCGUI/Start/GUI/Core/LCD_Index2ColorEx.c \
UCGUI/Start/GUI/Core/LCD_L0_Generic.c \
UCGUI/Start/GUI/Core/LCD_Mirror.c \
UCGUI/Start/GUI/Core/LCD_MixColors256.c \
UCGUI/Start/GUI/Core/LCD_ReadRect.c \
UCGUI/Start/GUI/Core/LCD_Rotate180.c \
UCGUI/Start/GUI/Core/LCD_RotateCCW.c \
UCGUI/Start/GUI/Core/LCD_RotateCW.c \
UCGUI/Start/GUI/Core/LCD_SelectLCD.c \
UCGUI/Start/GUI/Core/LCD_SetAPI.c \
UCGUI/Start/GUI/Core/LCD_SetClipRectEx.c \
UCGUI/Start/GUI/Core/LCD_UpdateColorIndices.c \
UCGUI/Start/GUI/Font/F08_1.c \
UCGUI/Start/GUI/Font/F08_ASCII.c \
UCGUI/Start/GUI/Font/F10S_1.c \
UCGUI/Start/GUI/Font/F10S_ASCII.c \
UCGUI/Start/GUI/Font/F10_1.c \
UCGUI/Start/GUI/Font/F10_ASCII.c \
UCGUI/Start/GUI/Font/F13B_1.c \
UCGUI/Start/GUI/Font/F13B_ASCII.c \
UCGUI/Start/GUI/Font/F13HB_1.c \
UCGUI/Start/GUI/Font/F13HB_ASCII.c \
UCGUI/Start/GUI/Font/F13H_1.c \
UCGUI/Start/GUI/Font/F13H_ASCII.c \
UCGUI/Start/GUI/Font/F13X13_CN.c \
UCGUI/Start/GUI/Font/F13_1.c \
UCGUI/Start/GUI/Font/F13_ASCII.c \
UCGUI/Start/GUI/Font/F16B_1.c \
UCGUI/Start/GUI/Font/F16B_ASCII.c \
UCGUI/Start/GUI/Font/F16_1.c \
UCGUI/Start/GUI/Font/F16_1HK.c \
UCGUI/Start/GUI/Font/F16_ASCII.c \
UCGUI/Start/GUI/Font/F16_HK.c \
UCGUI/Start/GUI/Font/F24B_1.c \
UCGUI/Start/GUI/Font/F24B_ASCII.c \
UCGUI/Start/GUI/Font/F24_1.c \
UCGUI/Start/GUI/Font/F24_ASCII.c \
UCGUI/Start/GUI/Font/F32B_1.c \
UCGUI/Start/GUI/Font/F32B_ASCII.c \
UCGUI/Start/GUI/Font/F32_1.c \
UCGUI/Start/GUI/Font/F32_ASCII.c \
UCGUI/Start/GUI/Font/F4x6.c \
UCGUI/Start/GUI/Font/F6x8.c \
UCGUI/Start/GUI/Font/F8x10_ASCII.c \
UCGUI/Start/GUI/Font/F8x12_ASCII.c \
UCGUI/Start/GUI/Font/F8x13_1.c \
UCGUI/Start/GUI/Font/F8x13_ASCII.c \
UCGUI/Start/GUI/Font/F8x15B_1.c \
UCGUI/Start/GUI/Font/F8x15B_ASCII.c \
UCGUI/Start/GUI/Font/F8x16.c \
UCGUI/Start/GUI/Font/F8x8.c \
UCGUI/Start/GUI/Font/FComic18B_1.c \
UCGUI/Start/GUI/Font/FComic18B_ASCII.c \
UCGUI/Start/GUI/Font/FComic24B_1.c \
UCGUI/Start/GUI/Font/FComic24B_ASCII.c \
UCGUI/Start/GUI/Font/FD24x32.c \
UCGUI/Start/GUI/Font/FD32.c \
UCGUI/Start/GUI/Font/FD36x48.c \
UCGUI/Start/GUI/Font/FD48.c \
UCGUI/Start/GUI/Font/FD48x64.c \
UCGUI/Start/GUI/Font/FD60x80.c \
UCGUI/Start/GUI/Font/FD64.c \
UCGUI/Start/GUI/Font/FD80.c \
UCGUI/Start/GUI/LCDDriver/LCDDummy.c \
UCGUI/Start/GUI/Widget/BUTTON.c \
UCGUI/Start/GUI/Widget/BUTTON_Bitmap.c \
UCGUI/Start/GUI/Widget/BUTTON_BMP.c \
UCGUI/Start/GUI/Widget/BUTTON_Create.c \
UCGUI/Start/GUI/Widget/BUTTON_CreateIndirect.c \
UCGUI/Start/GUI/Widget/BUTTON_Default.c \
UCGUI/Start/GUI/Widget/BUTTON_Get.c \
UCGUI/Start/GUI/Widget/BUTTON_GetBitmap.c \
UCGUI/Start/GUI/Widget/BUTTON_IsPressed.c \
UCGUI/Start/GUI/Widget/BUTTON_SelfDraw.c \
UCGUI/Start/GUI/Widget/BUTTON_SetFocusColor.c \
UCGUI/Start/GUI/Widget/BUTTON_SetTextAlign.c \
UCGUI/Start/GUI/Widget/BUTTON_StreamedBitmap.c \
UCGUI/Start/GUI/Widget/BUTTON__SetBitmapObj.c \
UCGUI/Start/GUI/Widget/CHECKBOX.c \
UCGUI/Start/GUI/Widget/CHECKBOX_Create.c \
UCGUI/Start/GUI/Widget/CHECKBOX_CreateIndirect.c \
UCGUI/Start/GUI/Widget/CHECKBOX_Default.c \
UCGUI/Start/GUI/Widget/CHECKBOX_GetState.c \
UCGUI/Start/GUI/Widget/CHECKBOX_GetText.c \
UCGUI/Start/GUI/Widget/CHECKBOX_Image.c \
UCGUI/Start/GUI/Widget/CHECKBOX_IsChecked.c \
UCGUI/Start/GUI/Widget/CHECKBOX_SetBkColor.c \
UCGUI/Start/GUI/Widget/CHECKBOX_SetBoxBkColor.c \
UCGUI/Start/GUI/Widget/CHECKBOX_SetDefaultImage.c \
UCGUI/Start/GUI/Widget/CHECKBOX_SetFocusColor.c \
UCGUI/Start/GUI/Widget/CHECKBOX_SetFont.c \
UCGUI/Start/GUI/Widget/CHECKBOX_SetImage.c \
UCGUI/Start/GUI/Widget/CHECKBOX_SetNumStates.c \
UCGUI/Start/GUI/Widget/CHECKBOX_SetSpacing.c \
UCGUI/Start/GUI/Widget/CHECKBOX_SetState.c \
UCGUI/Start/GUI/Widget/CHECKBOX_SetText.c \
UCGUI/Start/GUI/Widget/CHECKBOX_SetTextAlign.c \
UCGUI/Start/GUI/Widget/CHECKBOX_SetTextColor.c \
UCGUI/Start/GUI/Widget/DIALOG.c \
UCGUI/Start/GUI/Widget/DROPDOWN.c \
UCGUI/Start/GUI/Widget/DROPDOWN_AddString.c \
UCGUI/Start/GUI/Widget/DROPDOWN_Create.c \
UCGUI/Start/GUI/Widget/DROPDOWN_CreateIndirect.c \
UCGUI/Start/GUI/Widget/DROPDOWN_Default.c \
UCGUI/Start/GUI/Widget/DROPDOWN_DeleteItem.c \
UCGUI/Start/GUI/Widget/DROPDOWN_GetNumItems.c \
UCGUI/Start/GUI/Widget/DROPDOWN_InsertString.c \
UCGUI/Start/GUI/Widget/DROPDOWN_ItemSpacing.c \
UCGUI/Start/GUI/Widget/DROPDOWN_SetAutoScroll.c \
UCGUI/Start/GUI/Widget/DROPDOWN_SetBkColor.c \
UCGUI/Start/GUI/Widget/DROPDOWN_SetColor.c \
UCGUI/Start/GUI/Widget/DROPDOWN_SetFont.c \
UCGUI/Start/GUI/Widget/DROPDOWN_SetScrollbarColor.c \
UCGUI/Start/GUI/Widget/DROPDOWN_SetScrollbarWidth.c \
UCGUI/Start/GUI/Widget/DROPDOWN_SetTextAlign.c \
UCGUI/Start/GUI/Widget/DROPDOWN_SetTextColor.c \
UCGUI/Start/GUI/Widget/DROPDOWN_SetTextHeight.c \
UCGUI/Start/GUI/Widget/EDIT.c \
UCGUI/Start/GUI/Widget/EDITBin.c \
UCGUI/Start/GUI/Widget/EDITDec.c \
UCGUI/Start/GUI/Widget/EDITFloat.c \
UCGUI/Start/GUI/Widget/EDITHex.c \
UCGUI/Start/GUI/Widget/EDITUlong.c \
UCGUI/Start/GUI/Widget/EDIT_Create.c \
UCGUI/Start/GUI/Widget/EDIT_CreateIndirect.c \
UCGUI/Start/GUI/Widget/EDIT_Default.c \
UCGUI/Start/GUI/Widget/EDIT_GetCursorPixelPos.c \
UCGUI/Start/GUI/Widget/EDIT_GetCursorPos.c \
UCGUI/Start/GUI/Widget/EDIT_GetNumChars.c \
UCGUI/Start/GUI/Widget/EDIT_SetCursorAtChar.c \
UCGUI/Start/GUI/Widget/EDIT_SetFocussable.c \
UCGUI/Start/GUI/Widget/EDIT_SetInsertMode.c \
UCGUI/Start/GUI/Widget/EDIT_SetpfAddKeyEx.c \
UCGUI/Start/GUI/Widget/EDIT_SetpfUpdateBuffer.c \
UCGUI/Start/GUI/Widget/EDIT_SetSel.c \
UCGUI/Start/GUI/Widget/EDIT_SetTextMode.c \
UCGUI/Start/GUI/Widget/FRAMEWIN.c \
UCGUI/Start/GUI/Widget/FRAMEWIN_AddMenu.c \
UCGUI/Start/GUI/Widget/FRAMEWIN_Button.c \
UCGUI/Start/GUI/Widget/FRAMEWIN_ButtonClose.c \
UCGUI/Start/GUI/Widget/FRAMEWIN_ButtonMax.c \
UCGUI/Start/GUI/Widget/FRAMEWIN_ButtonMin.c \
UCGUI/Start/GUI/Widget/FRAMEWIN_Create.c \
UCGUI/Start/GUI/Widget/FRAMEWIN_CreateIndirect.c \
UCGUI/Start/GUI/Widget/FRAMEWIN_Default.c \
UCGUI/Start/GUI/Widget/FRAMEWIN_Get.c \
UCGUI/Start/GUI/Widget/FRAMEWIN_IsMinMax.c \
UCGUI/Start/GUI/Widget/FRAMEWIN_MinMaxRest.c \
UCGUI/Start/GUI/Widget/FRAMEWIN_SetBorderSize.c \
UCGUI/Start/GUI/Widget/FRAMEWIN_SetColors.c \
UCGUI/Start/GUI/Widget/FRAMEWIN_SetFont.c \
UCGUI/Start/GUI/Widget/FRAMEWIN_SetResizeable.c \
UCGUI/Start/GUI/Widget/FRAMEWIN_SetTitleHeight.c \
UCGUI/Start/GUI/Widget/FRAMEWIN_SetTitleVis.c \
UCGUI/Start/GUI/Widget/FRAMEWIN__UpdateButtons.c \
UCGUI/Start/GUI/Widget/GRAPH.c \
UCGUI/Start/GUI/Widget/GRAPH_CreateIndirect.c \
UCGUI/Start/GUI/Widget/GRAPH_DATA_XY.c \
UCGUI/Start/GUI/Widget/GRAPH_DATA_YT.c \
UCGUI/Start/GUI/Widget/GRAPH_SCALE.c \
UCGUI/Start/GUI/Widget/GUI_ARRAY.c \
UCGUI/Start/GUI/Widget/GUI_ARRAY_DeleteItem.c \
UCGUI/Start/GUI/Widget/GUI_ARRAY_InsertItem.c \
UCGUI/Start/GUI/Widget/GUI_ARRAY_ResizeItem.c \
UCGUI/Start/GUI/Widget/GUI_DRAW.c \
UCGUI/Start/GUI/Widget/GUI_DRAW_BITMAP.c \
UCGUI/Start/GUI/Widget/GUI_DRAW_BMP.c \
UCGUI/Start/GUI/Widget/GUI_DRAW_Self.c \
UCGUI/Start/GUI/Widget/GUI_DRAW_STREAMED.c \
UCGUI/Start/GUI/Widget/GUI_EditBin.c \
UCGUI/Start/GUI/Widget/GUI_EditDec.c \
UCGUI/Start/GUI/Widget/GUI_EditFloat.c \
UCGUI/Start/GUI/Widget/GUI_EditHex.c \
UCGUI/Start/GUI/Widget/GUI_EditString.c \
UCGUI/Start/GUI/Widget/GUI_HOOK.c \
UCGUI/Start/GUI/Widget/HEADER.c \
UCGUI/Start/GUI/Widget/HEADER_Bitmap.c \
UCGUI/Start/GUI/Widget/HEADER_BMP.c \
UCGUI/Start/GUI/Widget/HEADER_Create.c \
UCGUI/Start/GUI/Widget/HEADER_CreateIndirect.c \
UCGUI/Start/GUI/Widget/HEADER_GetSel.c \
UCGUI/Start/GUI/Widget/HEADER_SetDragLimit.c \
UCGUI/Start/GUI/Widget/HEADER_StreamedBitmap.c \
UCGUI/Start/GUI/Widget/HEADER__SetDrawObj.c \
UCGUI/Start/GUI/Widget/LISTBOX.c \
UCGUI/Start/GUI/Widget/LISTBOX_Create.c \
UCGUI/Start/GUI/Widget/LISTBOX_CreateIndirect.c \
UCGUI/Start/GUI/Widget/LISTBOX_Default.c \
UCGUI/Start/GUI/Widget/LISTBOX_DeleteItem.c \
UCGUI/Start/GUI/Widget/LISTBOX_Font.c \
UCGUI/Start/GUI/Widget/LISTBOX_GetItemText.c \
UCGUI/Start/GUI/Widget/LISTBOX_GetNumItems.c \
UCGUI/Start/GUI/Widget/LISTBOX_GetTextAlign.c \
UCGUI/Start/GUI/Widget/LISTBOX_InsertString.c \
UCGUI/Start/GUI/Widget/LISTBOX_ItemDisabled.c \
UCGUI/Start/GUI/Widget/LISTBOX_ItemSpacing.c \
UCGUI/Start/GUI/Widget/LISTBOX_MultiSel.c \
UCGUI/Start/GUI/Widget/LISTBOX_ScrollStep.c \
UCGUI/Start/GUI/Widget/LISTBOX_SetAutoScroll.c \
UCGUI/Start/GUI/Widget/LISTBOX_SetBkColor.c \
UCGUI/Start/GUI/Widget/LISTBOX_SetOwner.c \
UCGUI/Start/GUI/Widget/LISTBOX_SetOwnerDraw.c \
UCGUI/Start/GUI/Widget/LISTBOX_SetScrollbarColor.c \
UCGUI/Start/GUI/Widget/LISTBOX_SetScrollbarWidth.c \
UCGUI/Start/GUI/Widget/LISTBOX_SetString.c \
UCGUI/Start/GUI/Widget/LISTBOX_SetTextAlign.c \
UCGUI/Start/GUI/Widget/LISTBOX_SetTextColor.c \
UCGUI/Start/GUI/Widget/LISTVIEW.c \
UCGUI/Start/GUI/Widget/LISTVIEW_Create.c \
UCGUI/Start/GUI/Widget/LISTVIEW_CreateIndirect.c \
UCGUI/Start/GUI/Widget/LISTVIEW_Default.c \
UCGUI/Start/GUI/Widget/LISTVIEW_DeleteAllRows.c \
UCGUI/Start/GUI/Widget/LISTVIEW_DeleteColumn.c \
UCGUI/Start/GUI/Widget/LISTVIEW_DeleteRow.c \
UCGUI/Start/GUI/Widget/LISTVIEW_DisableRow.c \
UCGUI/Start/GUI/Widget/LISTVIEW_GetBkColor.c \
UCGUI/Start/GUI/Widget/LISTVIEW_GetFont.c \
UCGUI/Start/GUI/Widget/LISTVIEW_GetHeader.c \
UCGUI/Start/GUI/Widget/LISTVIEW_GetItemText.c \
UCGUI/Start/GUI/Widget/LISTVIEW_GetNumColumns.c \
UCGUI/Start/GUI/Widget/LISTVIEW_GetNumRows.c \
UCGUI/Start/GUI/Widget/LISTVIEW_GetSel.c \
UCGUI/Start/GUI/Widget/LISTVIEW_GetTextColor.c \
UCGUI/Start/GUI/Widget/LISTVIEW_InsertRow.c \
UCGUI/Start/GUI/Widget/LISTVIEW_SetAutoScroll.c \
UCGUI/Start/GUI/Widget/LISTVIEW_SetBkColor.c \
UCGUI/Start/GUI/Widget/LISTVIEW_SetColumnWidth.c \
UCGUI/Start/GUI/Widget/LISTVIEW_SetFont.c \
UCGUI/Start/GUI/Widget/LISTVIEW_SetGridVis.c \
UCGUI/Start/GUI/Widget/LISTVIEW_SetItemColor.c \
UCGUI/Start/GUI/Widget/LISTVIEW_SetItemText.c \
UCGUI/Start/GUI/Widget/LISTVIEW_SetLBorder.c \
UCGUI/Start/GUI/Widget/LISTVIEW_SetRBorder.c \
UCGUI/Start/GUI/Widget/LISTVIEW_SetRowHeight.c \
UCGUI/Start/GUI/Widget/LISTVIEW_SetSel.c \
UCGUI/Start/GUI/Widget/LISTVIEW_SetSort.c \
UCGUI/Start/GUI/Widget/LISTVIEW_SetTextAlign.c \
UCGUI/Start/GUI/Widget/LISTVIEW_SetTextColor.c \
UCGUI/Start/GUI/Widget/LISTVIEW_UserData.c \
UCGUI/Start/GUI/Widget/MENU.c \
UCGUI/Start/GUI/Widget/MENU_Attach.c \
UCGUI/Start/GUI/Widget/MENU_CreateIndirect.c \
UCGUI/Start/GUI/Widget/MENU_Default.c \
UCGUI/Start/GUI/Widget/MENU_DeleteItem.c \
UCGUI/Start/GUI/Widget/MENU_DisableItem.c \
UCGUI/Start/GUI/Widget/MENU_EnableItem.c \
UCGUI/Start/GUI/Widget/MENU_GetItem.c \
UCGUI/Start/GUI/Widget/MENU_GetItemText.c \
UCGUI/Start/GUI/Widget/MENU_GetNumItems.c \
UCGUI/Start/GUI/Widget/MENU_InsertItem.c \
UCGUI/Start/GUI/Widget/MENU_Popup.c \
UCGUI/Start/GUI/Widget/MENU_SetBkColor.c \
UCGUI/Start/GUI/Widget/MENU_SetBorderSize.c \
UCGUI/Start/GUI/Widget/MENU_SetFont.c \
UCGUI/Start/GUI/Widget/MENU_SetItem.c \
UCGUI/Start/GUI/Widget/MENU_SetTextColor.c \
UCGUI/Start/GUI/Widget/MENU__FindItem.c \
UCGUI/Start/GUI/Widget/MESSAGEBOX.c \
UCGUI/Start/GUI/Widget/MULTIEDIT.c \
UCGUI/Start/GUI/Widget/MULTIEDIT_Create.c \
UCGUI/Start/GUI/Widget/MULTIEDIT_CreateIndirect.c \
UCGUI/Start/GUI/Widget/MULTIPAGE.c \
UCGUI/Start/GUI/Widget/MULTIPAGE_Create.c \
UCGUI/Start/GUI/Widget/MULTIPAGE_CreateIndirect.c \
UCGUI/Start/GUI/Widget/MULTIPAGE_Default.c \
UCGUI/Start/GUI/Widget/PROGBAR.c \
UCGUI/Start/GUI/Widget/PROGBAR_Create.c \
UCGUI/Start/GUI/Widget/PROGBAR_CreateIndirect.c \
UCGUI/Start/GUI/Widget/PROGBAR_SetBarColor.c \
UCGUI/Start/GUI/Widget/PROGBAR_SetFont.c \
UCGUI/Start/GUI/Widget/PROGBAR_SetMinMax.c \
UCGUI/Start/GUI/Widget/PROGBAR_SetText.c \
UCGUI/Start/GUI/Widget/PROGBAR_SetTextAlign.c \
UCGUI/Start/GUI/Widget/PROGBAR_SetTextColor.c \
UCGUI/Start/GUI/Widget/PROGBAR_SetTextPos.c \
UCGUI/Start/GUI/Widget/RADIO.c \
UCGUI/Start/GUI/Widget/RADIO_Create.c \
UCGUI/Start/GUI/Widget/RADIO_CreateIndirect.c \
UCGUI/Start/GUI/Widget/RADIO_Default.c \
UCGUI/Start/GUI/Widget/RADIO_GetText.c \
UCGUI/Start/GUI/Widget/RADIO_Image.c \
UCGUI/Start/GUI/Widget/RADIO_SetBkColor.c \
UCGUI/Start/GUI/Widget/RADIO_SetDefaultImage.c \
UCGUI/Start/GUI/Widget/RADIO_SetFocusColor.c \
UCGUI/Start/GUI/Widget/RADIO_SetFont.c \
UCGUI/Start/GUI/Widget/RADIO_SetGroupId.c \
UCGUI/Start/GUI/Widget/RADIO_SetImage.c \
UCGUI/Start/GUI/Widget/RADIO_SetText.c \
UCGUI/Start/GUI/Widget/RADIO_SetTextColor.c \
UCGUI/Start/GUI/Widget/SCROLLBAR.c \
UCGUI/Start/GUI/Widget/SCROLLBAR_Create.c \
UCGUI/Start/GUI/Widget/SCROLLBAR_CreateIndirect.c \
UCGUI/Start/GUI/Widget/SCROLLBAR_Defaults.c \
UCGUI/Start/GUI/Widget/SCROLLBAR_GetValue.c \
UCGUI/Start/GUI/Widget/SCROLLBAR_SetColor.c \
UCGUI/Start/GUI/Widget/SCROLLBAR_SetWidth.c \
UCGUI/Start/GUI/Widget/SLIDER.c \
UCGUI/Start/GUI/Widget/SLIDER_Create.c \
UCGUI/Start/GUI/Widget/SLIDER_CreateIndirect.c \
UCGUI/Start/GUI/Widget/SLIDER_Default.c \
UCGUI/Start/GUI/Widget/SLIDER_SetFocusColor.c \
UCGUI/Start/GUI/Widget/TEXT.c \
UCGUI/Start/GUI/Widget/TEXT_Create.c \
UCGUI/Start/GUI/Widget/TEXT_CreateIndirect.c \
UCGUI/Start/GUI/Widget/TEXT_Default.c \
UCGUI/Start/GUI/Widget/TEXT_SetBkColor.c \
UCGUI/Start/GUI/Widget/TEXT_SetFont.c \
UCGUI/Start/GUI/Widget/TEXT_SetText.c \
UCGUI/Start/GUI/Widget/TEXT_SetTextAlign.c \
UCGUI/Start/GUI/Widget/TEXT_SetTextColor.c \
UCGUI/Start/GUI/Widget/TEXT_SetWrapMode.c \
UCGUI/Start/GUI/Widget/WIDGET.c \
UCGUI/Start/GUI/Widget/WIDGET_Effect_3D.c \
UCGUI/Start/GUI/Widget/WIDGET_Effect_3D1L.c \
UCGUI/Start/GUI/Widget/WIDGET_Effect_3D2L.c \
UCGUI/Start/GUI/Widget/WIDGET_Effect_None.c \
UCGUI/Start/GUI/Widget/WIDGET_Effect_Simple.c \
UCGUI/Start/GUI/Widget/WIDGET_FillStringInRect.c \
UCGUI/Start/GUI/Widget/WIDGET_SetEffect.c \
UCGUI/Start/GUI/Widget/WIDGET_SetWidth.c \
UCGUI/Start/GUI/Widget/WINDOW.c \
UCGUI/Start/GUI/Widget/WINDOW_Default.c \
UCGUI/Start/GUI/WM/WM.c \
UCGUI/Start/GUI/WM/WMMemDev.c \
UCGUI/Start/GUI/WM/WMTouch.c \
UCGUI/Start/GUI/WM/WM_AttachWindow.c \
UCGUI/Start/GUI/WM/WM_BringToBottom.c \
UCGUI/Start/GUI/WM/WM_BringToTop.c \
UCGUI/Start/GUI/WM/WM_Broadcast.c \
UCGUI/Start/GUI/WM/WM_CheckScrollPos.c \
UCGUI/Start/GUI/WM/WM_CriticalHandle.c \
UCGUI/Start/GUI/WM/WM_DIAG.c \
UCGUI/Start/GUI/WM/WM_EnableWindow.c \
UCGUI/Start/GUI/WM/WM_ForEachDesc.c \
UCGUI/Start/GUI/WM/WM_GetBkColor.c \
UCGUI/Start/GUI/WM/WM_GetCallback.c \
UCGUI/Start/GUI/WM/WM_GetClientRect.c \
UCGUI/Start/GUI/WM/WM_GetClientWindow.c \
UCGUI/Start/GUI/WM/WM_GetDesktopWindow.c \
UCGUI/Start/GUI/WM/WM_GetDesktopWindowEx.c \
UCGUI/Start/GUI/WM/WM_GetDiagInfo.c \
UCGUI/Start/GUI/WM/WM_GetDialogItem.c \
UCGUI/Start/GUI/WM/WM_GetFirstChild.c \
UCGUI/Start/GUI/WM/WM_GetFlags.c \
UCGUI/Start/GUI/WM/WM_GetFocussedWindow.c \
UCGUI/Start/GUI/WM/WM_GetId.c \
UCGUI/Start/GUI/WM/WM_GetInsideRect.c \
UCGUI/Start/GUI/WM/WM_GetInsideRectExScrollbar.c \
UCGUI/Start/GUI/WM/WM_GetInvalidRect.c \
UCGUI/Start/GUI/WM/WM_GetNextSibling.c \
UCGUI/Start/GUI/WM/WM_GetOrg.c \
UCGUI/Start/GUI/WM/WM_GetParent.c \
UCGUI/Start/GUI/WM/WM_GetPrevSibling.c \
UCGUI/Start/GUI/WM/WM_GetScrollbar.c \
UCGUI/Start/GUI/WM/WM_GetScrollPartner.c \
UCGUI/Start/GUI/WM/WM_GetScrollPos.c \
UCGUI/Start/GUI/WM/WM_GetScrollState.c \
UCGUI/Start/GUI/WM/WM_GetWindowRect.c \
UCGUI/Start/GUI/WM/WM_GetWindowSize.c \
UCGUI/Start/GUI/WM/WM_HasCaptured.c \
UCGUI/Start/GUI/WM/WM_HasFocus.c \
UCGUI/Start/GUI/WM/WM_Hide.c \
UCGUI/Start/GUI/WM/WM_InvalidateArea.c \
UCGUI/Start/GUI/WM/WM_IsCompletelyVisible.c \
UCGUI/Start/GUI/WM/WM_IsEnabled.c \
UCGUI/Start/GUI/WM/WM_IsFocussable.c \
UCGUI/Start/GUI/WM/WM_IsVisible.c \
UCGUI/Start/GUI/WM/WM_IsWindow.c \
UCGUI/Start/GUI/WM/WM_MakeModal.c \
UCGUI/Start/GUI/WM/WM_Move.c \
UCGUI/Start/GUI/WM/WM_MoveChildTo.c \
UCGUI/Start/GUI/WM/WM_NotifyParent.c \
UCGUI/Start/GUI/WM/WM_OnKey.c \
UCGUI/Start/GUI/WM/WM_Paint.c \
UCGUI/Start/GUI/WM/WM_PaintWindowAndDescs.c \
UCGUI/Start/GUI/WM/WM_PID__GetPrevState.c \
UCGUI/Start/GUI/WM/WM_ResizeWindow.c \
UCGUI/Start/GUI/WM/WM_Screen2Win.c \
UCGUI/Start/GUI/WM/WM_SendMessageNoPara.c \
UCGUI/Start/GUI/WM/WM_SendToParent.c \
UCGUI/Start/GUI/WM/WM_SetAnchor.c \
UCGUI/Start/GUI/WM/WM_SetCallback.c \
UCGUI/Start/GUI/WM/WM_SetCapture.c \
UCGUI/Start/GUI/WM/WM_SetCaptureMove.c \
UCGUI/Start/GUI/WM/WM_SetCreateFlags.c \
UCGUI/Start/GUI/WM/WM_SetDesktopColor.c \
UCGUI/Start/GUI/WM/WM_SetFocus.c \
UCGUI/Start/GUI/WM/WM_SetFocusOnNextChild.c \
UCGUI/Start/GUI/WM/WM_SetFocusOnPrevChild.c \
UCGUI/Start/GUI/WM/WM_SetId.c \
UCGUI/Start/GUI/WM/WM_SetpfPollPID.c \
UCGUI/Start/GUI/WM/WM_SetScrollbar.c \
UCGUI/Start/GUI/WM/WM_SetScrollPos.c \
UCGUI/Start/GUI/WM/WM_SetScrollState.c \
UCGUI/Start/GUI/WM/WM_SetSize.c \
UCGUI/Start/GUI/WM/WM_SetTrans.c \
UCGUI/Start/GUI/WM/WM_SetTransState.c \
UCGUI/Start/GUI/WM/WM_SetUserClipRect.c \
UCGUI/Start/GUI/WM/WM_SetWindowPos.c \
UCGUI/Start/GUI/WM/WM_SetXSize.c \
UCGUI/Start/GUI/WM/WM_SetYSize.c \
UCGUI/Start/GUI/WM/WM_Show.c \
UCGUI/Start/GUI/WM/WM_SIM.c \
UCGUI/Start/GUI/WM/WM_StayOnTop.c \
UCGUI/Start/GUI/WM/WM_Timer.c \
UCGUI/Start/GUI/WM/WM_TimerExternal.c \
UCGUI/Start/GUI/WM/WM_UpdateWindowAndDescs.c \
UCGUI/Start/GUI/WM/WM_UserData.c \
UCGUI/Start/GUI/WM/WM_Validate.c \
UCGUI/Start/GUI/WM/WM_ValidateWindow.c \
UCGUI/Start/GUI/WM/WM__ForEachDesc.c \
UCGUI/Start/GUI/WM/WM__GetFirstSibling.c \
UCGUI/Start/GUI/WM/WM__GetFocussedChild.c \
UCGUI/Start/GUI/WM/WM__GetLastSibling.c \
UCGUI/Start/GUI/WM/WM__GetOrg_AA.c \
UCGUI/Start/GUI/WM/WM__GetPrevSibling.c \
UCGUI/Start/GUI/WM/WM__IsAncestor.c \
UCGUI/Start/GUI/WM/WM__IsChild.c \
UCGUI/Start/GUI/WM/WM__IsEnabled.c \
UCGUI/Start/GUI/WM/WM__NotifyVisChanged.c \
UCGUI/Start/GUI/WM/WM__Screen2Client.c \
UCGUI/Start/GUI/WM/WM__SendMessage.c \
UCGUI/Start/GUI/WM/WM__SendMessageIfEnabled.c \
UCGUI/Start/GUI/WM/WM__SendMessageNoPara.c \
UCGUI/Start/GUI/WM/WM__UpdateChildPositions.c \
UCGUI/Start/JPEG/GUI_JPEG.c \
UCGUI/Start/JPEG/jcomapi.c \
UCGUI/Start/JPEG/jdapimin.c \
UCGUI/Start/JPEG/jdapistd.c \
UCGUI/Start/JPEG/jdcoefct.c \
UCGUI/Start/JPEG/jdcolor.c \
UCGUI/Start/JPEG/jddctmgr.c \
UCGUI/Start/JPEG/jdhuff.c \
UCGUI/Start/JPEG/jdinput.c \
UCGUI/Start/JPEG/jdmainct.c \
UCGUI/Start/JPEG/jdmarker.c \
UCGUI/Start/JPEG/jdmaster.c \
UCGUI/Start/JPEG/jdmerge.c \
UCGUI/Start/JPEG/jdphuff.c \
UCGUI/Start/JPEG/jdpostct.c \
UCGUI/Start/JPEG/jdsample.c \
UCGUI/Start/JPEG/jdtrans.c \
UCGUI/Start/JPEG/jerror.c \
UCGUI/Start/JPEG/jfdctflt.c \
UCGUI/Start/JPEG/jfdctfst.c \
UCGUI/Start/JPEG/jfdctint.c \
UCGUI/Start/JPEG/jidctflt.c \
UCGUI/Start/JPEG/jidctfst.c \
UCGUI/Start/JPEG/jidctint.c \
UCGUI/Start/JPEG/jidctred.c \
UCGUI/Start/JPEG/jmemmgr.c \
UCGUI/Start/JPEG/jquant1.c \
UCGUI/Start/JPEG/jquant2.c \
UCGUI/Start/JPEG/jutils.c \
FileBrower.c \
main.c
OBJS_C := $(patsubst %.c, %.o, $(SRCS_C))
VTOS_MODULE_PATH := ../vtos/
OTHER_MODULE_PATH := ../other/
all : $(OBJS_PATH) make_sub $(ELF)
	@echo "CP $(ELF)"
	@$(CP) -O binary $(OBJS_PATH)$(ELF) $(OBJS_PATH)$(TARGET)
$(OBJS_PATH) :
	@echo "build obj path"
	@mkdir $(OBJS_PATH)
	
make_sub :
	@cd $(VTOS_MODULE_PATH) && make
	@cd $(OTHER_MODULE_PATH) && make
	
$(ELF) : $(OBJS_C) $(VTOS_MODULE_PATH)$(OBJS_PATH)*.o $(OTHER_MODULE_PATH)$(OBJS_PATH)*.o
	@echo "LD $^"
	@$(LD) -Tvtos.lds $^ -o $(OBJS_PATH)$(ELF) $(LIBS_PATH)
	
%.o : %.c
	@echo "CC $<"
	@$(CC) $(CFLAGS) $< -o $@ $(INCLUDE_PATH)
.PHONY : clean
clean :
	@rm -rf $(OBJS_PATH) $(OBJS_C)
	@cd $(VTOS_MODULE_PATH) && make clean
	@cd $(OTHER_MODULE_PATH) && make clean
	
.PHONY : clean_other
clean_other :
	@cd $(OTHER_MODULE_PATH) && make clean
	
.PHONY : clean_vtos
clean_vtos :
	@cd $(VTOS_MODULE_PATH) && make clean