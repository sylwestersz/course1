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
 * @file 	stats.h
 * @brief 	Interface to the statistics lib
 *
 * A simple lib to refresh some C programming.
 *
 * @author 	Sylwester Szczepaniak
 * @date 	<Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Function Declarations */

/**
 * @brief Prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * @param 	array 	pointer to usinged char data
 * @param 	len 	length of the data
 *
 * @return None - all return values are redirected to output stream
 */
void print_statistics(unsigned char* array, unsigned int len);

/**
 * @brief Given an array of data and a length, prints the array to the screen
 *
 * @param 	array 	pointer to usinged char data
 * @param 	len 	length of the data
 *
 * @return	None - all return values are redirected to output stream
 */
void print_array(unsigned char* array, unsigned int len);

/**
 * @brief Given an array of data and a length, returns the median value
 *
 * @param array pointer to usinged char data
 * @param len length of the data
 *
 * @return The median of the input array
 */
unsigned int find_median(unsigned char* array, unsigned int len);

/**
 * @brief Given an array of data and a length, returns the mean value
 *
 * @param array pointer to usinged char data
 * @param len length of the data
 *
 * @return The median of the input array
 */
unsigned int find_mean(unsigned char* array, unsigned int len);

/**
 * @brief Given an array of data and a length, returns the maximum value
 *
 * @param array pointer to usinged char data
 * @param len length of the data
 *
 * @return The median of the input array
 */
unsigned int find_maximum(unsigned char* array, unsigned int len);

/**
 * @brief Given an array of data and a length, returns the minimum value
 *
 * @param array pointer to usinged char data
 * @param len length of the data
 *
 * @return The median of the input array
 */
unsigned int find_minimum(unsigned char* array, unsigned int len);

/**
 * @brief Given an array of data and a length, sorts the array from largest to smallest.
 *
 * The zeroth Element is the largest value, and the last element (n-1) is the smallest value.
 *
 * @param array pointer to usinged char data
 * @param len length of the data
 *
 * @return The median of the input array
 */
unsigned int sort_array(unsigned char* array, unsigned int len);

#endif /* __STATS_H__ */
