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
#ifndef __COURSE1_H__
#define __COURSE1_H__

/******************************************************************************
 Platform - MSP432
******************************************************************************/
#if defined (MSP432)
/******************************************************************************
 Platform - HOST
******************************************************************************/
#elif defined (HOST)
/******************************************************************************
 Platform - Unsupported
******************************************************************************/
#else
#error "Platform provided is not supported in this Build System"
#endif

#endif /* __COURSE1_H__ */

