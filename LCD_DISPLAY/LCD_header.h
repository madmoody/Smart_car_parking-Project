/*
 * LCD_header.h
 *
 * Created: 24/04/2023 15:17:23
 *  Author: Abhishek
 */ 

#ifndef LCD_HEADER_H_
#define LCD_HEADER_H_

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <stdint.h>
/*******************************************	COMMANDS	**************************************************/

#define RETURN_HOME 0x02					/*	Return home					*/
#define CLEAR_DISPLAY 0x01					/*	Clears the display			*/
#define DECREMENT_CURSOR 0x04				/*	Decrement cursor to left	*/
#define INCREMENT_CURSOR 0x06				/*	Increment cursor to right	*/
#define LCD_MATRIX 0x38						/*	2 lines and 5×7 matrix		*/
#define ROW1 0x80							/*	Force cursor to the beginning ( 1st line)	*/
#define ROW2 0xc0							/*	Force cursor to the beginning ( 2nd line)	*/

/*******************************************	SHIFT COMMANDS	***********************************************/

#define DISPLAY_RIGHT 0x05					/*	Shift display right			*/
#define DISPLAY_LEFT 0x07					/*	Shift display left			*/
#define CURSOR_POS_TO_LEFT 0x10				/*	Shift cursor position to left	*/
#define CURSOR_POS_TO_RIGHT 0x14			/*	Shift cursor position tO right	*/
#define DISPLAY_TO_LEFT 0x18				/*	Shift the entire display to the left	*/
#define DISPLAY_TO_RIGHT 0x1c				/*	Shift the entire display to the right	*/

/*******************************************	DISPLAY COMMANDS	*******************************************/

#define DISPLAY_OFF_CURSOR_OFF 0x08			/*	Display off, cursor off		*/
#define DISPLAY_OFF_CURSOR_ON 0x0a			/*	Display off, cursor on		*/
#define DISPLAY_ON_CURSOR_OFF 0x0c			/*	Display on, cursor off		*/
#define DISPLAY_ON_CURSOR_BLINKING 0x1e		/*	Display on, cursor blinking	*/
//#define DISPLAY_ON_CURSOR_BLINKING 0x1f	/*	Display on, cursor blinking	*/

void LCD_SCROLL(uint8_t a);
void LCD_INITIALIZE(void);
void LCD_CMD(uint8_t cmd);
void LCD_DATA(uint8_t data);
void LCD_WRITE(const uint8_t *string);
void LCD_SET_POSITION(uint8_t row, uint8_t position, uint8_t* str);
void LCD_SPECIAL_CHAR(uint8_t row, uint8_t position, uint8_t spChar);
void LCD_CUSTOM_CHAR(uint8_t row, uint8_t position);

#endif /* LCD_HEADER_H_ */