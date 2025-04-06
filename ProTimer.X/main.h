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

#include "./mcc_generated_files/system/system.h" 
#include "./src/lcd/lcd.h"
#include "./src/protimer/protimer.h"


#define DEBOUNCE_TIME 20     // Button Debounce Time 20ms
#define LONG_PRESS_TIME 500   // Button Long Press 500ms
#define BUTTON_COUNT 2

typedef enum : uint8_t {
    Switch_None_Press = 0,
    Switch_Short_Press = 1,
    Switch_Long_Press = 2
} Button_State;

typedef struct{
    volatile uint8_t *port;                     // Button Port
    uint8_t pin;                                // Button Pin Of Port
    uint32_t pressStartTime, lastDebounceTime;  // Record PressTime And Debounce Time 
    bool lastRead;                              // Button Read for Debounce
    bool isPressed, shortPressed, longPressed;
}ButtonConfig;

typedef struct {
    Button_State state;
    uint16_t press_time;
}Switch_t;

extern ButtonConfig buttonList[BUTTON_COUNT];
extern ButtonConfig btn1;
extern uint8_t testList[2];

uint32_t GetMillis();
void Main_Initilaize(void);
void Timer_Task(void);
void Switch_Pressed();
void CheckButtonState(ButtonConfig *btn);
// void CheckButton(ButtonConfig *btn);
void ClearButtonFlag(ButtonConfig *btn);

uint8_t TestListGetNum(uint8_t *num);

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

