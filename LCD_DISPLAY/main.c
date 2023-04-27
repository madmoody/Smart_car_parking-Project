/*
 * Project-car parking_LCD_Interfacing.c
 *
 * Created: 25/04/2023 10:35:14
 * Author : Abhishek
 */ 

/*---------------------------THIS IS APPLICATION LEVEL CODE OF LCD DISPLAY FOR SMART CAR PARKING SYSTEM-------------------------------*/

//#include <avr/io.h>
#include <stdlib.h>
#include "LCD_header.h"		//Library for LCD DRIVER D0:7->PORTB, RS->PORTD0, RW->PORTD1, EN->PORTD2

#define ROW1SIZE 14
#define SPCHAR1 13
#define SPCHAR2 15
#define OCCUPIED 0b01111100
#define EMPTY 0b10001111

void PrintOnDisplay(void);

int main(void)
{
	DDRA |= (~(1<<DDA0)) & (~(1<<DDA1));
	uint8_t SensorStatus;

	LCD_INITIALIZE();
	PrintOnDisplay();
	
	while (1) 
    {
		SensorStatus = PINA & 0b00000011;
		switch(SensorStatus)
		{
			case 0b00000001:	LCD_SPECIAL_CHAR(2,1,OCCUPIED);
								LCD_SPECIAL_CHAR(2,4,EMPTY);			
								break;
			case 0b00000010:	LCD_SPECIAL_CHAR(2,4,OCCUPIED);
								LCD_SPECIAL_CHAR(2,1,EMPTY);
								break;
			case 0b00000011:	LCD_SPECIAL_CHAR(2,1,OCCUPIED);
								LCD_SPECIAL_CHAR(2,4,OCCUPIED);				
								break;
			default:			LCD_SPECIAL_CHAR(2,1,EMPTY);
								LCD_SPECIAL_CHAR(2,4,EMPTY);
		}
    }
}

void PrintOnDisplay(void)
{
		uint8_t i,j;
		uint8_t str[8];
		
		/*	Numbering the parking space	*/
		for(i=1,j=1;i<ROW1SIZE;i+=3)
		{
			itoa(j,(char*)str,10);
			LCD_SET_POSITION(1,i,str);
			j++;
		}

		/*	Special character1 : [ 	*/
		for(i=0;i<SPCHAR1;i+=3)
		{
			LCD_SPECIAL_CHAR(2,i,0b01011011);
		}

		/*	Special character2 : ] 	*/
		for(i=2;i<SPCHAR2;i+=3)
		{
			LCD_SPECIAL_CHAR(2,i,0b01011101);
		}
}