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
 * @file 	stats.c
 * @brief 	Implementation of stats lib
 *
 * @author 	Sylwester Szczepaniak
 * @date 	29.12.2018
 *
 */

#include <string.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)
#define MAX_ELEMENTS (255) // moment when overflow is possible inside the lib

#ifdef USE_TEST_DATA
static unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                    114, 88,   45,  76, 123,  87,  25,  23,
                                      200, 122, 150, 90,   92,  87, 177, 244,
                                      201,   6,  12,  60,   8,   2,   5,  67,
                                        7,  87, 250, 230,  99,   3, 100,  90};
#endif

/* Add other Implementation File Code Here */

void print_statistics(unsigned char* array, unsigned int len)
{
#if FIXME
    unsigned char   median = 0;
    unsigned char   mean = 0;
    unsigned char   min = 0;
    unsigned char   max = 0;

    median = find_median(array, len);
    mean   = find_mean(array, len);
    max    = find_maximum(array, len);
    min    = find_minimum(array, len);


    PRINTF("\n\n **** ARRAY STATISTICS ****");
    PRINTF("\n\t MEDIAN: %d", median);
    PRINTF("\n\t MEAN:   %d", mean);
    PRINTF("\n\t MAX:    %d", max);
    PRINTF("\n\t MIN:    %d\n", min);
#endif
}

void print_array(unsigned char* array, unsigned int len)
{
#ifdef VERBOSE
	if (array !=NULL)
	{
		for(unsigned int i = 0; i < len; i++)
		{
            if (!(i % 8)) // put 8 elements per line
            {
                PRINTF("\n");
            }
            PRINTF("[%4.0d] ",array[i]);
		}
	}
    printf("\n");
#endif
}

unsigned char find_median(unsigned char* array, unsigned int len)
{
    // make local copy, sort the array and then get median from sorted
    // for 256 bytes on host we probably will not overflow the stack
    unsigned char median = 0;

    if ((array != NULL) && (len < MAX_ELEMENTS))
    {
        unsigned char backup[SIZE];

        memcpy(backup, array, SIZE); //unsigned char is always bytes
        sort_array(backup, SIZE);

        median = backup[SIZE/2];
    }
	return median;
}


unsigned char find_mean(unsigned char* array, unsigned int len)
{
    unsigned char mean = 0;

	if ((array != NULL) && (len < MAX_ELEMENTS))
	{
	    unsigned int sum  = 0;

		for(unsigned int i = 0; i < len; i++)
		{
			sum += array[i];
		}
		mean = (unsigned char)(sum/len);
	}

	return mean;
}


unsigned char find_maximum(unsigned char* array, unsigned int len)
{
    unsigned char max = 0;

    if ((array != NULL) && (len < MAX_ELEMENTS))
    {
        for(unsigned int i = 0; i < len; i++)
        {
            if (array[i] > max)
            {
                max = array[i];
            }
        }
    }
	return max;
}


unsigned char find_minimum(unsigned char* array, unsigned int len)
{
    unsigned char min = 0xFF;

    if ((array != NULL) && (len < MAX_ELEMENTS))
    {
        for(unsigned int i = 0; i < len; i++)
        {
            if (array[i] < min)
            {
                min = array[i];
            }
        }
    }
    return min;
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(unsigned char* arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    unsigned char L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(unsigned char arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void sort_array(unsigned char* array, unsigned int len)
{
    mergeSort(array, 0, len - 1);
}
