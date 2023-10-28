/*
 * LCD_config.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Lenovo
 */
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "config.h"


#define CLCD_DATA_PORT   PORT_B

#define CLCD_CTRL_PORT   PORT_A
#define CLCD_RS_PIN      PIN_3
#define CLCD_RW_PIN      PIN_1
#define CLCD_E_PIN       PIN_2

#define CLR_SCREEN                     0x01
#define CURSOR_ON_DISPLAY_ON           0x0e
#define CURSOR_OFF_DISPLAY_OFF         0x08
#define CURSOR_OFF_DISPLAY_ON          0x0c
#define CURSOR_BLINKING_DISPLAY_ON     0x0f
#define CURSOR_MOVE_LEFT               0x04
#define RETURN_HOME                    0x02
#define ENTRY_MODE                     0x06
#define FOUR_BITS                      0x28
#define EIGHT_BITS                     0x38

#endif

