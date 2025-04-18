/* 
 * File:   lcd.c
 * Author: user
 *
 * Created on January 14, 2025, 3:02 PM
 */

#include "lcd.h"

/*
 * 
 */

volatile LCD_t LCD_Module;

void LCD_Initialize(void){
    LCD_Module.currState = LCD_IDLE;
    LCD_Module.timer_tick = 0;
    LCD_RS_SetLow();
    LCD_EN_SetLow();
    LCD_Command(LCD_FUNCTION_SET);
    LCD_Command(LCD_RETURN_HOME);
    LCD_Command(LCD_CLEAR);
    LCD_Command(LCD_DISPLAY_ON);
    LCD_Command(LCD_ENTRY_MODE);
}

void LCD_Command(unsigned char cmd){
    LCD_SendByte(cmd, 0);
}

void LCD_Char(unsigned char data){
    LCD_SendByte(data, 1);
}

void LCD_String(const char *msg){
    while((*msg != '\0')){
        LCD_Char(*msg);
        msg++;
    }
}

void LCD_SetCursor(unsigned char row, unsigned char col){
    unsigned char address = (row == 1) ? LCD_ROW_1 : LCD_ROW_0;
    address += col;
    LCD_Command(LCD_SET_DDRAM_ADDR | address);
}

void LCD_SendByte(unsigned char byte, unsigned char mode){
    LCD_Data = byte;
    LCD_RS = mode;  // 0=Command 1=Write Data
    LCD_Pulse();
}

void LCD_Pulse(void){
    LCD_EN= 1;
    __delay_ms(1);    // 脈衝高電平時間
    LCD_EN = 0;
    __delay_ms(3);    // 等待 LCD 處理指令
}



// // For Furture Operation
// void LCD_Task(void){
//     switch(LCD_Module.currState){
//         case LCD_IDLE:
//             if(LCD_Module.sendFlag){
//                 LCD_Module.currState = LCD_SENDING;
//             }
//             break;
//         case LCD_SENDING:
//             break;
//         case LCD_DELAYING:
//             break;
//         default:
//             break;
//     }
// }

void LCD_Clear(void){
    LCD_Command(LCD_CLEAR);
    __delay_ms(2);
}