/* 
 * File:   main.h
 * Author: User
 *
 * Created on 2025年2月9日, 下午 9:45
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "../mcc_generated_files/system/system.h" 
#include "lcd/lcd.h"
#include "protimer/protimer.h"


#define DEBOUNCE_TIME 200     // Button Debounce Time
#define LONG_PRESS_TIME 500   // Button Long Press

typedef enum : uint8_t {
    Switch_None_Press = 0,
    Switch_Short_Press = 1,
    Switch_Long_Press = 2
} Switch_Press_State;

typedef struct {
    Switch_Press_State state;
    uint16_t press_time;
}Switch_t;


void Main_Initilaize(void);
void Timer_Task(void);
void Switch_Pressed();
Switch_Press_State Switch1PressState(void);
Switch_Press_State Switch2PressState(void);

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

