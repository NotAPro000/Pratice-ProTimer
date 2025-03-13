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
#include <stdint.h>


/*
    Main application
*/

static volatile Switch_t sw1, sw2;
static uint32_t millisCounter = 0;

ButtonConfig buttonList[BUTTON_COUNT] = {
    {&LATE, 0, 0, false, false, false},
    {&LATE, 1, 0, false, false, false}
};

int main(void)
{
    SYSTEM_Initialize();
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    //INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Enable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptEnable(); 

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 
    
    Main_Initilaize();
    LCD_Initialize();
    TMR0_PeriodMatchCallbackRegister(Timer_Task);
    
    while(1)
    {
        ProTimer_Task();
    }    
}

void Main_Initilaize(void){
    
}

void Timer_Task(void){
    ProTimer_Millis();
    millisCounter++;
}

void CheckButtonState(ButtonConfig *btn){
    // Check Current Button State
    bool isPressed = (*btn->latch & (1<<btn->pin)) == 0;

    if(isPressed != btn->lastButtonState){
        btn->lastDebounceTime = GetMillis(); // Start Recording Deounce Time
    }

    if((GetMillis() - btn->lastDebounceTime) > DEBOUNCE_TIME){
        if( isPressed == false && btn->lastButtonState == true){
            btn->pressStartTime = GetMillis();
            btn->buttonPressed = true;
        }
        else if(  isPressed== true && btn->lastButtonState == false){
            uint16_t pressDuration = GetMillis()-btn->pressStartTime;
            btn->buttonPressed = false;

            if (pressDuration > LONG_PRESS_TIME) {
                btn->longPressed = true;
            }
            else{
                btn->shortPressed = true;
            }
        }
    }
    btn->lastButtonState = isPressed;

}

uint32_t GetMillis(){
    return millisCounter;
}




