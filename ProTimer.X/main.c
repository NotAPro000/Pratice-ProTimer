 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
*/

/*
? [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/


#include "main.h"
#include "src/lcd/lcd.h"
#include <builtins.h>
#include <stdbool.h>
#include <stdint.h>


/*
    Main application
*/

static volatile uint32_t millisCounter = 0;

ButtonConfig buttonList[BUTTON_COUNT];
ButtonConfig btn1;
uint8_t testList[2] = {0, 1};

int main(void)
{
    SYSTEM_Initialize();
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Enable the Peripheral Interrupts 
    INTERRUPT_PeripheralInterruptEnable(); 
    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable();    

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 
    
    Main_Initilaize();
    LCD_Initialize();
    TMR0_PeriodMatchCallbackRegister(Timer_Task);
    ProTimer_Initialize();
    

    while(1)
    {
        ProTimer_Task();
    }    
}

void Main_Initilaize(void){
    buttonList[0] = (ButtonConfig){&PORTE, 0, 0, false, false, false};
    buttonList[1] = (ButtonConfig){&PORTE, 1, 0, false, false, false};
    btn1 = (ButtonConfig){&PORTE, 0, 0, false, false, false};
}

void Timer_Task(void){
    ProTimer_Millis();
    millisCounter++;
}

void CheckButtonState(ButtonConfig *btn){
    if(btn == NULL) return;
    // Check Current Button State
    bool isPressed = (bool)(*(btn->port) & (1<<btn->pin))?0:1;
    uint32_t curTime = GetMillis();

    // Button Pressed
    if(isPressed != btn->lastRead ){ 
        btn->lastDebounceTime = GetMillis();        // Start Recording Deounce Time
        btn->lastRead = isPressed;
    }

    
    if((curTime - btn->lastDebounceTime) >= DEBOUNCE_TIME){
        if( isPressed !=  btn->isPressed){          // Button State Real Change
            btn->isPressed = isPressed;             // Update Button State

            if(btn->isPressed == true){             // Button Detect Press
                btn->pressStartTime = curTime;
            }
            else{                                   // Button Detect Release
                if(curTime - btn->pressStartTime > LONG_PRESS_TIME){
                    btn->longPressed = true;
                }
                else{
                    btn->shortPressed = true;
                }
            }

        }
    }

}

void ClearButtonFlag(ButtonConfig *btn){
    btn->longPressed = false;
    btn->shortPressed = false;
}

uint32_t GetMillis(){
    return millisCounter;
}

uint8_t TestListGetNum(uint8_t *num){
    return *num;
}


