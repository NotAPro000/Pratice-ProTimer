#include "./protimer.h"
#include <stdint.h>
#include <stdio.h>


static void ProTimer_Handle_Idle(State_t s);
static void ProTimer_Handle_TimeSet(State_t s);
static void ProTimer_Handle_Stat(State_t s);
static void ProTimer_Handle_CountDown(State_t s);
static void ProTimer_Handle_Pause(State_t s);
static void DisplayTime(uint32_t time);
static void DisplayMessage(char *msg, uint8_t column, uint8_t row);
static void DisplayClear(void);

static ProTimer_t proTimer_Module;
unsigned long protimer_millisCount = 0;

void ProTimer_Initialize(void){
    proTimer_Module.currState = ProTimer_Idle;
    proTimer_Module.prevState = ProTimer_Idle;
    proTimer_Module.curTime = 0;
    proTimer_Module.elapsedTime = 0;
}

void ProTimer_Millis(void){
    protimer_millisCount++;
}

void ProTimer_Task(void){
    switch (proTimer_Module.currState) {
        case ProTimer_Idle:
            // Entry 
            if(proTimer_Module.currState != proTimer_Module.prevState) ProTimer_Handle_Idle(State_Entry);
            // During 
            if (proTimer_Module.currState == proTimer_Module.prevState) ProTimer_Handle_Idle(State_During);
            // Exit 
            if (proTimer_Module.currState != proTimer_Module.prevState) ProTimer_Handle_Idle(State_Exit);
            break;
        case ProTimer_TimeSet:{
            // Entry
            if(proTimer_Module.currState != proTimer_Module.prevState) ProTimer_Handle_Idle(State_Entry);
            // During 
            if (proTimer_Module.currState == proTimer_Module.prevState) ProTimer_Handle_Idle(State_During);
            // Exit 
            if (proTimer_Module.currState != proTimer_Module.prevState) ProTimer_Handle_Idle(State_Exit);
            break;
        }
        case ProTimer_Stat:
            // ProTimer_Handle_Stat();
            break;
        case ProTimer_CountDown:
            // ProTimer_Handle_CountDown();
            break;
        case ProTimer_Pause:
            // ProTimer_Handle_Pause();
            break;
        default:
            break;
    }
    return;
}

static void ProTimer_Handle_Idle(State_t s){
    switch (s) {
        case State_Entry:{
            proTimer_Module.curTime = 0;
            proTimer_Module.elapsedTime = 0;
            DisplayTime(0);
            DisplayMessage("Set", 0, 0);
            DisplayMessage("Time", 0, 1);
            proTimer_Module.prevState = proTimer_Module.currState;
            break;
        }
        case State_During:

            break;
        case State_Exit:
            DisplayClear();
            break;
        default:
           break;
    }
}

static void ProTimer_Handle_TimeSet(State_t s){
    switch (s) {
        case State_Entry:{
            proTimer_Module.prevState = proTimer_Module.currState;
            break;
        }
        case State_During:
            break;
        case State_Exit:
            break;
        default:
            break;
    }
    
}
static void ProTimer_Handle_Stat(State_t s){
    
}
static void ProTimer_Handle_CountDown(State_t s){
    
}

static void ProTimer_Handle_Pause(State_t s){
    
}

static void DisplayTime(uint32_t time){
    char buf[7];
    uint16_t m = (uint16_t)(time/60);
    uint8_t s = (uint8_t)(time%60);
    sprintf(buf, "%03d:%02d", m, s);
    LCD_SetCursor(5, 0);
    LCD_String(buf);
}

static void DisplayMessage(char *msg, uint8_t column, uint8_t row){
    LCD_SetCursor(column, row);
    LCD_String(msg);
}

static void DisplayClear(void){
    LCD_Clear();
}