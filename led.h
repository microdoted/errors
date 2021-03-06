/*
Copyright 2018 Yuki Rea <null-src.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef LED_H
#define LED_H
#include "stdint.h"
#include <stdbool.h>


/* keyboard LEDs */
#define USB_LED_NUM_LOCK                0
#define USB_LED_CAPS_LOCK               1


#ifdef __cplusplus
extern "C" {
#endif

void num_lock_led_on(void);    
void num_lock_led_off(void);   

void caps_lock_led_on(void);   
void caps_lock_led_off(void);  
    

void led_set(uint8_t usb_led);
#ifdef __cplusplus
}
#endif

#endif
