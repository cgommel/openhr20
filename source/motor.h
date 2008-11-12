/*
 *  Open HR20
 *
 *  target:     ATmega169 @ 4 MHz in Honnywell Rondostat HR20E
 *
 *  compiler:   WinAVR-20071221
 *              avr-libc 1.6.0
 *              GCC 4.2.2
 *
 *  copyright:  2008 Dario Carluccio (hr20-at-carluccio-dot-de)
 *
 *  license:    This program is free software; you can redistribute it and/or
 *              modify it under the terms of the GNU Library General Public
 *              License as published by the Free Software Foundation; either
 *              version 2 of the License, or (at your option) any later version.
 *
 *              This program is distributed in the hope that it will be useful,
 *              but WITHOUT ANY WARRANTY; without even the implied warranty of
 *              MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *              GNU General Public License for more details.
 *
 *              You should have received a copy of the GNU General Public License
 *              along with this program. If not, see http:*www.gnu.org/licenses
 */

/*!
 * \file       motor.h
 * \brief      header file for motor.c, functions to control the HR20 motor
 * \author     Dario Carluccio <hr20-at-carluccio-dot-de>
 * \date       $Date$
 * $Rev$
 */


/*****************************************************************************
*   Macros
*****************************************************************************/

// How is the H-Bridge connected to the AVR?
#define MOTOR_HR20_PE3     PE3     //!< HR20: pin to activate photo eye
#define MOTOR_HR20_PE3_P   PORTE   //!< HR20: port to activate photo eye

static inline void MOTOR_H_BRIDGE_open(void) {
   PORTG  =  (1<<PG4);   // PG3 LOW, PG4 HIGH
   PORTB |=  (1<<PB7);   // PB7 HIGH
}
static inline void MOTOR_H_BRIDGE_close(void) {
   PORTG  =  (1<<PG3);   // PG3 HIGH, PG4 LOW
   PORTB &= ~(1<<PB7);   // PB7 LOW
}
static inline void MOTOR_H_BRIDGE_stop(void) {
   PORTG  =  0;          // PG3 LOW, PG4 LOW
   PORTB &= ~(1<<PB7);   // PB7 LOW
}


//! How many photoeye impulses maximal form one endposition to the other. <BR>
//! The value measured on a HR20 are 737 to 740 = so more than 1000 should
//! never occure if it is mounted
#define	MOTOR_MAX_IMPULSES 1000
#define	MOTOR_MIN_IMPULSES 100

#define EYE_TIMER_NOISE_PROTECTION 5 


/*****************************************************************************
*   Typedefs
*****************************************************************************/
//! motor direction
typedef enum {                                      
    close=-1, stop=0, open=1 
} motor_dir_t;

/*****************************************************************************
*   Prototypes
*****************************************************************************/
#define MOTOR_Init(void) (MOTOR_updateCalibration(1,0)) // Init motor control
bool MOTOR_Goto(uint8_t);                     // Goto position in percent
bool MOTOR_On(void);                          // is motor on
void MOTOR_Calibrate(uint8_t percent);        // calibrate the motor
bool MOTOR_IsCalibrated(void);                // is motor successful calibrated?
void MOTOR_updateCalibration(uint8_t cal_type, uint8_t percent);            // reset the calibration 
void MOTOR_SetMountStatus(bool);     // set status if is mounted or not
uint8_t MOTOR_GetPosPercent(void);  // get percental position of motor (0-100%)
void MOTOR_timer_stop(void);
void MOTOR_timer_pulse(void);

#define timer0_need_clock() (TCCR0A & ((1<<CS02)|(1<<CS01)|(1<<CS00)))

extern volatile uint16_t motor_diag;
extern int8_t MOTOR_calibration_step;

