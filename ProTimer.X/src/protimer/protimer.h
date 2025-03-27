/* 
 * File:   protimer.h
 * Author: User
 *
 * Created on 2025年2月11日, 上午 12:24
 */

#ifndef PROTIMER_H
#define	PROTIMER_H


#ifdef	__cplusplus
extern "C" {
#endif
#include <stdint.h>
#include "../../main.h"
#include "../lcd/lcd.h"
#include "../../mcc_generated_files/system/system.h"
#include <stdint.h>
#include <stdio.h>

    extern volatile uint32_t protimer_millisCount;
   
    typedef enum:uint8_t{
        Protimer_None = 0,
        ProTimer_Idle = 1,
        ProTimer_TimeSet = 2,
        ProTimer_Stat = 3,
        ProTimer_CountDown = 4,
        ProTimer_Pause = 5
    }ProTimer_State;
    
    typedef enum:uint8_t{
        State_Entry = 0,
        State_During = 1,
        State_Exit = 2
    }State_t;

    typedef struct{
        ProTimer_State currState;
        ProTimer_State prevState;
        uint32_t curTime, elapsedTime;
    }ProTimer_t;
    
    void ProTimer_Task(void);
    void ProTimer_Millis(void);
    void ProTimer_Initialize(void);
    
    
    

#ifdef	__cplusplus
}
#endif

#endif	/* PROTIMER_H */

