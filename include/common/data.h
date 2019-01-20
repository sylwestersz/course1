/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
#ifndef __DATA_H__
#define __DATA_H__

#include "platform.h"

/******************************************************************************
 This lib does some very basic data manipulation.
******************************************************************************/

/**
 * @brief Integer-to-ASCII needs to convert data from a standard integer type into an ASCII string.
 *
 * @param data 32bit signed integer to be converted always assumed base 10
 * @param *prt ASCII string. Caller to provide suffient buffer length min 33 bytes!
 * @param base format of output string: supported BASE are <2,3...,15,16>
 *
    You must place a null terminator at the end of the converted c-string
    Function should return the length of the converted data (including a negative sign). Example my_itoa(ptr, 1234, 10) should return an ASCII string length of 5 (including the null terminator).
    This function needs to handle signed data.
    You may not use any string functions or libraries
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief     ASCII-to-Integer needs to convert data back from an ASCII represented string into an integer type.
    All operations need to be performed using pointer arithmetic, not array indexing
    The character string to convert is passed in as a uint8_t * pointer (ptr).
    The number of digits in your character set is passed in as a uint8_t integer (digits).
    You should be able to support bases 2 to 16.
    The converted 32-bit signed integer should be returned.
    This function needs to handle signed data.
    You may not use any string functions or libraries
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */

