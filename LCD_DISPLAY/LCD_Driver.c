/*
 * LCD_Driver.c
 *
 * Created: 24/04/2023 15:17:00
 *  Author: Abhishek
 */ 

#include "LCD_header.h"
#define SIZE 8

void LCD_CMD(uint8_t cmd)
{
	PORTB = cmd;
	PORTD &= (~(1 << PORTD0));
	PORTD &= (~(1 << PORTD1));
	PORTD |= (1 << PORTD2);
	_delay_ms(10);
	PORTD &= (~(1 << PORTD2));
}

void LCD_DATA(uint8_t data)
{
	PORTB = data;
	PORTD |= (1 << PORTD0);
	PORTD &= (~(1 << PORTD1));
	PORTD |= (1 << PORTD2);
	_delay_ms(10);
	PORTD &= (~(1 << PORTD2));
}

void LCD_WRITE(const uint8_t *string)
{
	uint8_t i;
	for(i=0;string[i]!='\0';i++)
	{
		LCD_DATA(string[i]);
	}
}

void LCD_INITIALIZE(void)
{
	DDRB = 0xFF;
	DDRD |= (1<<DDD0) | (1<<DDD1) | (1<<DDD2);
	LCD_CMD(LCD_MATRIX);
	LCD_CMD(CLEAR_DISPLAY);
	LCD_CMD(INCREMENT_CURSOR);
	LCD_CMD(DISPLAY_ON_CURSOR_OFF);
}

void LCD_SCROLL(uint8_t a) //for scrolling
{
	while(a!=0)
	{
		LCD_CMD(DISPLAY_TO_LEFT); // shifting the entire display left.
		_delay_ms(50);
		a--;
	}
}

void LCD_SET_POSITION(uint8_t row, uint8_t position, uint8_t* str)
{
	if(row == 1)
	{
		LCD_CMD(ROW1 | (position & 0x0F));
	}
	else
	{
		LCD_CMD(ROW2 | (position & 0x0F));
	}
	LCD_WRITE(str);
}

void LCD_SPECIAL_CHAR(uint8_t row, uint8_t position, uint8_t spChar)
{
	if(row == 1)
	{
		LCD_CMD(ROW1 | (position & 0x0F));
	}
	else
	{
		LCD_CMD(ROW2 | (position & 0x0F));
	}
	LCD_DATA(spChar);
}

void LCD_CUSTOM_CHAR(uint8_t row, uint8_t position)
{
	uint8_t customChar[SIZE] = { 0b00000, 0b01010, 0b00000, 0b11111, 0b10001, 0b11111, 0b11011, 0b00000 };  /* Custom char set for alphanumeric LCD Module */ 
	uint8_t i;
	//LCD_SET_POSITION(row,position,(char*)"");
	if(row == 1)
	{
		LCD_CMD(ROW1 | (position & 0x0F));
	}
	else
	{
		LCD_CMD(ROW2 | (position & 0x0F));
	}
	
	for(i=0;i<SIZE;i++)
	{
		LCD_DATA(customChar[i]);
	}
}