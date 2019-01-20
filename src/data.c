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
/**
 * @file data.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "data.h"
#include <stdio.h>
#define ASCII_DIGIT_OFFSET    (48)
#define ASCII_HEX_OFFSET      (65)
#define ASCII_SPACE           (32)
#define MAX_NEEDED_BUFFER     (33)

void reverse_string(uint8_t *ptr, uint32_t len);

/***********************************************************
 Function Definitions
***********************************************************/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
    uint8_t* tmp_ptr = ptr; // go to end of max needed buffer
    uint32_t len = 0;
    uint32_t digit = 0;
    uint32_t is_minus = 0;

    if (data < 0)
    {
        data = data*(-1);
        is_minus = 1;
    }

    while(data)
    {

        digit = (data % base);
        if (digit < 9 )
        {
            *tmp_ptr = digit + ASCII_DIGIT_OFFSET;
        }
        else
        {
            *tmp_ptr = (digit - 10) + ASCII_HEX_OFFSET;
        }

        data /= base;
        tmp_ptr++;
        len++;
    }
    if(is_minus)
    {
        *tmp_ptr = '-';
        tmp_ptr++;
    }

    // place strig termination at end
    *tmp_ptr = '\0';

    reverse_string(ptr, (len+is_minus));

    return len;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
    uint8_t* tmp_ptr = ptr; // go to end of max needed buffer
    uint32_t digit = 0;
    uint32_t is_minus = 0;
    uint32_t base_power = 1;
    int32_t digit_count = 1;

    for (; digit_count < digits; digit_count++)
    {
        base_power *=  base;
    }

    if (*tmp_ptr == '-')
    {
        tmp_ptr++;
        is_minus = 1;
    }

    while(digit_count != 0)
    {
        if ((*tmp_ptr >= ASCII_DIGIT_OFFSET) &&
            (*tmp_ptr < ASCII_DIGIT_OFFSET + 10))
        {
            digit += (*tmp_ptr - ASCII_DIGIT_OFFSET)*base_power;
        }
        else if ((*tmp_ptr >= ASCII_HEX_OFFSET) &&
                 (*tmp_ptr < ASCII_HEX_OFFSET + 6))

        {
            digit += (*tmp_ptr + ASCII_HEX_OFFSET + 10)*base_power ;
        }
        tmp_ptr++;
        base_power /= base;
        digit_count --;
    }

    if(is_minus)
    {
        digit *= (-1);
    }
    return digit;
}


/*********
 * Helper funciotns
 **/

void reverse_string(uint8_t *ptr, uint32_t len)
{
    uint8_t tmp = 0;
    uint32_t counter= 0;

    for(counter = 0; counter < len/2; counter++)
    {
        tmp = *(ptr + counter);
        *(ptr + counter) = *(ptr + (len - 1) - counter);
        *(ptr + (len - 1) - counter) = tmp;
    }

}
