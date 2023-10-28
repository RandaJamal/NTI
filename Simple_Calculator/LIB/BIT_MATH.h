/*
 * BIT_MATH.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Lenovo
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_



#define SET_BIT(VAR,BITNO)      (VAR) |=  (1 << (BITNO))  // for on
#define CLR_BIT(VAR,BITNO)      (VAR) &= ~(1 << (BITNO))   // for off
#define TOG_BIT(VAR,BITNO)      (VAR) ^=  (1 << (BITNO))   // toggle
#define GET_BIT(VAR,BITNO)      (((VAR) >> (BITNO)) & 0x01)


#endif
