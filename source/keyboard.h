/*
 *  Open HR20
 *
 *  target:     ATmega169 @ 4 MHz in Honnywell Rondostat HR20E
 *
 *  compiler:   WinAVR-20071221
 *              avr-libc 1.6.0
 *              GCC 4.2.2
 *
 *  copyright:  2008 Jiri Dobry (jdobry-at-centrum-dot-cz)
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
 * \file       keyboard.h
 * \brief      Keyboard driver header
 * \author     Jiri Dobry <jdobry-at-centrum-dot-cz>
 * \date       $Date$
 * $Rev$
 */

extern uint16_t kb_events;

#define KB_EVENT_WHEEL_PLUS		(1 << 0)
#define KB_EVENT_WHEEL_MINUS	(1 << 1)
#define KB_EVENT_PROG			(1 << 2)
#define KB_EVENT_C				(1 << 3)
#define KB_EVENT_AUTO			(1 << 4)
#define KB_EVENT_PROG_REWOKE	(1 << 5)
#define KB_EVENT_C_REWOKE		(1 << 6)
#define KB_EVENT_AUTO_REWOKE	(1 << 7)
#define KB_EVENT_PROG_LONG		(1 << 8)
#define KB_EVENT_C_LONG			(1 << 9)
#define KB_EVENT_AUTO_LONG		(1 << 10)
#define KB_EVENT_LOCK_LONG		(1 << 11)
#define KB_EVENT_ALL_LONG		(1 << 12)
#define KB_EVENT_NONE_LONG		(1 << 13)

#define LONG_PRESS_THLD 4
#define LONG_QUIET_THLD 10

#define KEYBOARD_NOISE_CANCELATION 50 //!< unit is 1/256s depend to RTC

// names for keys
#define KBI_MONT 	(1 << 0)
#define KBI_C		(1 << 1)
#define KBI_PROG	(1 << 2)
#define KBI_AUTO	(1 << 3)
#define KBI_ROT1	(1 << 5)
#define KBI_ROT2	(1 << 6)

void task_keyboard(void);
void task_keyboard_long_press_detect(void);
bool mont_contact_pooling(void);
