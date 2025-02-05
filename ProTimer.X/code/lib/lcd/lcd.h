/* 
 * File:   lcd.h
 * Author: user
 *
 * Created on January 14, 2025, 3:02 PM
 */

#ifndef LCD_H
#define	LCD_H


#ifdef	__cplusplus
extern "C" {
#endif
    
#include "../../../mcc_generated_files/system/system.h" // Include MCC


#define LCD_Data LATD                           // Setting LCD Byte Data Port
#define LCD_RS IO_RC0_LAT                       // Setting LCD RS
#define LCD_EN IO_RC1_LAT                       // Setting LCD EN
#define LCD_RS_SetLow()     IO_RC0_SetLow()
#define LCD_RS_SetHigh()    IO_RC0_SetHigh()
#define LCD_EN_SetLow()     IO_RC1_SetLow()
#define LCD_EN_SetHigh()    IO_RC1_SetHigh()

    
#define LCD_CLEAR            0x01  // 清屏
#define LCD_RETURN_HOME      0x02  // 返回起始位置
#define LCD_ENTRY_MODE       0x06  // 輸入模式: 光標右移
#define LCD_DISPLAY_ON       0x0C  // 開啟顯示，關閉光標
#define LCD_DISPLAY_OFF      0x08  // 關閉顯示
#define LCD_FUNCTION_SET     0x38  // 功能設置: 8-bit 模式, 2 行, 5x8 點陣
#define LCD_SET_DDRAM_ADDR   0x80  // 設置 DDRAM 地址（光標位置基礎地址）

// 光標地址基礎位置
#define LCD_ROW_0            0x00  // 第一行起始地址
#define LCD_ROW_1            0x40  // 第二行起始地址
        
    enum LCD_State: unsigned char{
        LCD_IDLE = 0,
        LCD_SENDING = 1,
        LCD_DELAYING = 2
    } ;
    
    typedef struct LCD_t{
        volatile bool busyflag;
        volatile LCD_State currState;
        unsigned char data;
        volatile unsigned int timer_tick; 
    };
    
    extern volatile LCD_t LCD_Module;
    
    void LCD_Init(void);
    void LCD_Command(unsigned char cmd);
    void LCD_Char(unsigned char data);
    void LCD_String(const char *msg);
    void LCD_SetCursor(unsigned char row, unsigned char col);
    void Delay_x_mS(unsigned int N_ms);
    void LCD_SendByte(unsigned char byte, unsigned char mode);
    void LCD_Pulse(void);
    void LCD_Task(void);

    
    
    
#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

