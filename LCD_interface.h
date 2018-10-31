/*
 * LCD_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: shehab
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


extern void LCD_voidInit(void);

extern void LCD_voidWriteCommand(u8);

extern void LCD_voidWriteData(u8);
extern void LCD_voidWriteNonAscii(void);
extern void LCD_voidWriteString(u8* Copy_u8PtrToString);
extern void LCD_voidWriteName(void);
extern void LCD_voidClearSceen(void);


#define Function_Set_8_bit_1_Line   0x30	
#define Function_Set_8_bit_2_Line	0x38
#define Function_Set_4_bit_1_Line	0x20
#define Function_Set_4_bit_2_Line   0x28	
#define Entry_Mode	                0x06
#define Display_on_Cursor_on 	    0x0E
#define Display_on Cursor_off	    0x0C	
#define Display on Cursor blinking	0x0F	
#define Shift_left	                0x18	
#define Shift_right	                0x1C	
#define Clear_Display            	0x01

#endif /* LCD_INTERFACE_H_ */
