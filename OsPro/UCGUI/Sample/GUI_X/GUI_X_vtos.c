/*
*********************************************************************************************************
*                                             uC/GUI V3.98
*                        Universal graphic software for embedded applications
*
*                       (c) Copyright 2002, Micrium Inc., Weston, FL
*                       (c) Copyright 2002, SEGGER Microcontroller Systeme GmbH
*
*              µC/GUI is protected by international copyright laws. Knowledge of the
*              source code may not be used to write a similar product. This file may
*              only be used in accordance with a license and should not be redistributed
*              in any way. We appreciate your understanding and fairness.
*
----------------------------------------------------------------------
File        : GUI_X.C
Purpose     : Config / System dependent externals for GUI
---------------------------END-OF-HEADER------------------------------
*/

#include "GUI.h"
#include "GUI_X.h"

/**** Init ****/
void GUI_X_Init(void)
{

}

/**** ExecIdle - called if nothing else is left to do ****/
void GUI_X_ExecIdle(void)
{

}

/**** Timing routines - required for blinking ****/
int  GUI_X_GetTime(void)
{
	return 0;
}

void GUI_X_Delay(int Period)
{

}

/**** Multitask routines - required only if multitasking is used (#define GUI_OS 1) ****/
void GUI_X_Unlock(void)
{

}

void GUI_X_Lock(void)
{

}

U32  GUI_X_GetTaskId(void)
{
	return 0;
}

void GUI_X_InitOS(void)
{

}

/****      Event driving (optional with multitasking)  ****/
void GUI_X_WaitEvent(void)
{

}

void GUI_X_SignalEvent(void)
{

}

/**** Recording (logs/warnings and errors) - required only for higher levels ****/
void GUI_X_Log(const char *s)
{

}

void GUI_X_Warn(const char *s)
{

}

void GUI_X_ErrorOut(const char *s)
{

}
	 	 			 		    	 				 	  			   	 	 	 	 	 	  	  	      	   		 	 	 		  		  	 		 	  	  			     			       	   	 			  		    	 	     	 				  	 					 	 			   	  	  			 				 		 	 	 			     			 
