#include "./protimer.h"


static void ProTimer_Handle_Idle(State_t s);
static void ProTimer_Handle_TimeSet(void);
static void ProTimer_Handle_Stat(void);
static void ProTimer_Handle_CountDown(void);
static void ProTimer_Handle_Pause(void);

static ProTimer_t proTimer_Module;
unsigned long protimer_millisCount = 0;

void ProTimer_Initialize(){
    proTimer_Module.currState = ProTimer_Idle;
}

void ProTimer_Millis(void){
    protimer_millisCount++;
}

void ProTimer_Task(void){
    switch (proTimer_Module.currState) {
        case ProTimer_Idle:
            if(proTimer_Module.currState != proTimer_Module.prevState){
                ProTimer_Handle_Idle(State_Entry);
            }
            if (proTimer_Module.currState == proTimer_Module.prevState) {
                ProTimer_Handle_Idle(State_During);
            }
            if (proTimer_Module.currState != proTimer_Module.prevState) {
                ProTimer_Handle_Idle(State_Exit);
            }
            break;
        case ProTimer_TimeSet:
            ProTimer_Handle_TimeSet();
            break;
        case ProTimer_Stat:
            ProTimer_Handle_Stat();
            break;
        case ProTimer_CountDown:
            ProTimer_Handle_CountDown();
            break;
        case ProTimer_Pause:
            ProTimer_Handle_Pause();
            break;
        default:
            break;
    }
    return;
}

static void ProTimer_Handle_Idle(State_t s){
    switch (s) {
        case State_Entry:
            break;
        case State_During:
            break;
        case State_Exit:
            break;
        default:
           break;
    }
}

static void ProTimer_Handle_TimeSet(void){
    
}
static void ProTimer_Handle_Stat(void){
    
}
static void ProTimer_Handle_CountDown(void){
    
}

static void ProTimer_Handle_Pause(void){
    
}