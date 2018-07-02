/*****************************************
  NAME: Touchpanel.c
  DESC: ADC & Touch screen test
 *****************************************/
#include "def.h"
#include "2440addr.h"
#include "2440lib.h"
#include "LCD_TFT.h"
#include "WM.h"

#define REQCNT 30
#define ADCPRS 9
#define LOOP 1

int _touch_count=0;
volatile int _touch_xdata, _touch_ydata;
    
void Test_Touchpanel(void)
{
   
	rADCDLY=50000;                  //Normal conversion mode delay about (1/3.6864M)*50000=13.56ms
	rADCCON=(1<<14)+(ADCPRS<<6);   //ADCPRS En, ADCPRS Value

	Uart_Printf("\nTouch Screen test\n");

	rADCTSC=0xd3;  //Wfait,XP_PU,XP_Dis,XM_Dis,YP_Dis,YM_En

	//pISR_ADC = (int)AdcTsAuto;
	rINTMSK=~BIT_ADC;       //ADC Touch Screen Mask bit clear
	rINTSUBMSK=~(BIT_SUB_TC);

	Uart_Printf("\nPress any key to quit!\n");
	Uart_Printf("\nStylus Down, please...... \n");
	Uart_Getch();

	rINTSUBMSK|=BIT_SUB_TC;
	rINTMSK|=BIT_ADC;
	Uart_Printf("Touch Screen Test is Finished!!!\n");

}

void Init_Touchpanel(void)
{					 //pISR_ADC = (int)AdcTsAuto;
	rINTMSK &= ~BIT_ADC;       //ADC Touch Screen Mask bit clear
	rINTSUBMSK &= ~(BIT_SUB_TC);

	rADCDLY = 50000; //延时时间                 
	rADCCON = (ADCPRS << 6) | (1 << 14); // A/D转换器预分频值为 19+1 使能预分频器   
	rADCTSC = 0xd3;////YM输出驱动器使能 YP输出驱动器使能  XP开关使能 等待中断    
	rINTMSK &= ~(BIT_ADC); //允许ADC中断   ADC中断包括普通ADC和触摸屏中断      
	rINTSUBMSK &= ~(BIT_SUB_TC);//允许触摸屏子源中断         
	rINTSUBMSK &= ~(BIT_SUB_ADC);//允许 ADC子源中断  

}


void __irq AdcTsAuto(void)
{
	static unsigned long ulSaveAdcdly;
	rSRCPND |= 1 << 31; //清除ADC源挂起中断标志位        
	rINTPND |= 1 << 31; //清除中断标志位 
	if (rSUBSRCPND & (1 << 10))//判断是不是 ADC中断 
	{
		rSUBSRCPND |= 1 << 10;//清除ADC中断
		while (!(rADCCON & 0x8000));//等待ADC转换完成
		_touch_xdata = (rADCDAT0 & 0x3ff); //取xdata 
		_touch_ydata = (rADCDAT1 & 0x3ff); //取ydata  
		//Uart_Printf("0count=%d  XP=%d, YP=%d\n", _touch_count++, _touch_ydata, _touch_xdata);    //X-position Conversion data
		_touch_xdata = (_touch_xdata - 140) * 272 / (860 - 140);
		_touch_ydata = 950 - _touch_ydata;
		_touch_ydata = _touch_ydata * 480 / (950 - 80);
		rADCTSC = 0xd3;    //Waiting for interrupt   
		rADCTSC = rADCTSC | (1 << 8); // Detect stylus up interrupt signal.  
		GUI_PID_STATE state;
		state.x = _touch_ydata;
		state.y = _touch_xdata;
		state.Pressed = 1;
		GUI_MOUSE_StoreState(&state);
		//Uart_Printf("1count=%d  XP=%d, YP=%d\n", _touch_count++, _touch_ydata, _touch_xdata);    //X-position Conversion data
	}
	if (rSUBSRCPND & (1 << 9))//判断是不是触摸 中断  
	{
		rSUBSRCPND |= 1 << 9;//清除触摸中断
		if ((!(rADCDAT0 & 0x8000)) && (!(rADCDAT1 & 0x8000))) //当是 触摸笔按下的状态 
		{
			rADCTSC = (1 << 3) | (1 << 2);//XP上拉禁止 自动顺序X方向和Y方向测量  
			ulSaveAdcdly = rADCDLY;
			rADCDLY = 40000;
			rADCCON |= 0x1; //允许ADC启动 
			while (rADCCON & 0x1);//等待启动完成    
		}
		else//笔尖抬起状态  
		{
			rADCDLY = ulSaveAdcdly;
			rADCTSC = 0xd3; //YM输出驱动器使能 YP输出驱动器使能  XP开关使能 等待中断
			GUI_PID_STATE state;
			state.x = _touch_ydata;
			state.y = _touch_xdata;
			state.Pressed = 0;
			GUI_MOUSE_StoreState(&state);
			//Uart_Printf("2count=%d  XP=%d, YP=%d\n", _touch_count++, _touch_ydata, _touch_xdata);    //X-position Conversion data
		}
	}   
}
