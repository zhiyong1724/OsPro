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

	rADCDLY = 50000; //��ʱʱ��                 
	rADCCON = (ADCPRS << 6) | (1 << 14); // A/Dת����Ԥ��ƵֵΪ 19+1 ʹ��Ԥ��Ƶ��   
	rADCTSC = 0xd3;////YM���������ʹ�� YP���������ʹ��  XP����ʹ�� �ȴ��ж�    
	rINTMSK &= ~(BIT_ADC); //����ADC�ж�   ADC�жϰ�����ͨADC�ʹ������ж�      
	rINTSUBMSK &= ~(BIT_SUB_TC);//����������Դ�ж�         
	rINTSUBMSK &= ~(BIT_SUB_ADC);//���� ADC��Դ�ж�  

}


void __irq AdcTsAuto(void)
{
	static unsigned long ulSaveAdcdly;
	rSRCPND |= 1 << 31; //���ADCԴ�����жϱ�־λ        
	rINTPND |= 1 << 31; //����жϱ�־λ 
	if (rSUBSRCPND & (1 << 10))//�ж��ǲ��� ADC�ж� 
	{
		rSUBSRCPND |= 1 << 10;//���ADC�ж�
		while (!(rADCCON & 0x8000));//�ȴ�ADCת�����
		_touch_xdata = (rADCDAT0 & 0x3ff); //ȡxdata 
		_touch_ydata = (rADCDAT1 & 0x3ff); //ȡydata  
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
	if (rSUBSRCPND & (1 << 9))//�ж��ǲ��Ǵ��� �ж�  
	{
		rSUBSRCPND |= 1 << 9;//��������ж�
		if ((!(rADCDAT0 & 0x8000)) && (!(rADCDAT1 & 0x8000))) //���� �����ʰ��µ�״̬ 
		{
			rADCTSC = (1 << 3) | (1 << 2);//XP������ֹ �Զ�˳��X�����Y�������  
			ulSaveAdcdly = rADCDLY;
			rADCDLY = 40000;
			rADCCON |= 0x1; //����ADC���� 
			while (rADCCON & 0x1);//�ȴ��������    
		}
		else//�ʼ�̧��״̬  
		{
			rADCDLY = ulSaveAdcdly;
			rADCTSC = 0xd3; //YM���������ʹ�� YP���������ʹ��  XP����ʹ�� �ȴ��ж�
			GUI_PID_STATE state;
			state.x = _touch_ydata;
			state.y = _touch_xdata;
			state.Pressed = 0;
			GUI_MOUSE_StoreState(&state);
			//Uart_Printf("2count=%d  XP=%d, YP=%d\n", _touch_count++, _touch_ydata, _touch_xdata);    //X-position Conversion data
		}
	}   
}
