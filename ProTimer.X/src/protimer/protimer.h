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

#include "../../main.h"

    extern unsigned long protimer_millisCount;
    
    typedef enum:unsigned char{
        ProTimer_Idle = 0,
        ProTimer_TimeSet = 1,
        ProTimer_Stat = 2,
        ProTimer_CountDown = 3,
        ProTimer_Pause = 4
    }ProTimer_State;
    
    typedef struct{
        ProTimer_State currState;
    }ProTimer_t;
    
    void ProTimer_Task(void);
    void ProTimer_Millis(void);
    
    
    static void ProTimer_Handle_Idle(void);
    static void ProTimer_Handle_TimeSet(void);
    static void ProTimer_Handle_Stat(void);
    static void ProTimer_Handle_CountDown(void);
    static void ProTimer_Handle_Pause(void);
    

#ifdef	__cplusplus
}
#endif

#endif	/* PROTIMER_H */

