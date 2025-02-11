#include "./protimer.h"

static ProTimer_t proTimer_Module;
unsigned long protimer_millisCount = 0;

void ProTimer_Initialize(){
    proTimer_Module.currState = ProTimer_Idle;
}

void ProTimer_Millis(void){
    protimer_millisCount++;
}

void ProTimer_Task(void){
    
}

static void ProTimer_Handle_Idle(void){
    
}

static void ProTimer_Handle_TimeSet(void){
    
}
static void ProTimer_Handle_Stat(void){
    
}
static void ProTimer_Handle_CountDown(void){
    
}

static void ProTimer_Handle_Pause(void){
    
}