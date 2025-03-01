/* 
 * File:   protimer.h
 * Author: User
 *
 * Created on 2025年2月11日, 上午 12:24
 */

#ifndef PROTIMER_H
#define	PROTIMER_H

#include <stdint.h>
#ifdef	__cplusplus
extern "C" {
#endif

#include "../lcd/lcd.h"

    extern uint32_t protimer_millisCount;
   
    typedef enum:uint8_t{
        ProTimer_Idle = 0,
        ProTimer_TimeSet = 1,
        ProTimer_Stat = 2,
        ProTimer_CountDown = 3,
        ProTimer_Pause = 4
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
    
    
    
    

#ifdef	__cplusplus
}
#endif

#endif	/* PROTIMER_H */

