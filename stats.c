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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  unsigned char minimum = 0;
  unsigned char maximum = 0;
  float mean = 0;
  float median = 0;
  
  /* Statistics and Printing Functions Go Here */
  minimum = find_minimum(test, SIZE);
  maximum = find_maximum(test, SIZE);
  mean = find_mean(test, SIZE);
  median = find_median(test, SIZE);

  print_statistics(minimum, maximum, mean, median);
  printf("Array before sorting: \n");
  print_array(test, SIZE);
  
  printf("Array after sorting: \n");
  sort_array(test, SIZE);
  print_array(test, SIZE);

}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char minimum, unsigned char maximum, float mean, float median){

  printf("Minimum: %d\n", minimum);
  printf("Maximum: %d\n", maximum);
  printf("Mean: %f\n", mean);
  printf("Median: %f\n", median);

}

void print_array(unsigned char *arr, unsigned int size){

  for(int i = 0; i < size; i++){
    printf("%d\t", *(arr+i));
  }
  printf("\n");
}

float find_median(unsigned char *arr, unsigned int size){

  unsigned char new_arr[size];
  unsigned char tmp;
  for(int i = 0; i < size; i++)
    new_arr[i] = *(arr+i);

  for(int i = 0; i < size; i++){
      for(int j = i+1; j < size; j++){
	if( *(new_arr+i) > *(new_arr+j) ){
	  tmp = *(new_arr+i);
	  *(new_arr+i) = *(new_arr+j);
          *(new_arr+j) = tmp;
	}
      }
  }

  unsigned char median = 0;
  sort_array(new_arr, size);
  median = (*(new_arr + (size / 2) - 1) + *(new_arr + (size / 2)))/2;
  return median;

}

float find_mean(unsigned char *arr, unsigned int size){

  float mean = 0;
  for(int i = 0; i < size; i++){
    mean += *(arr+i);
  }
  mean /= size;
  return mean;

}

unsigned char find_minimum(unsigned char *arr, unsigned int size){

  unsigned char min = *arr;
  for(int i = 1; i < size; i++){
    if(*(arr+i) < min){
      min = *(arr+i);
    }
  }
  return min;

}

unsigned char find_maximum(unsigned char *arr, unsigned int size){

  unsigned char max = *arr;
  for(int i = 1; i < size; i++){
    if(*(arr+i) > max){
      max = *(arr+i);
    }
  }
  return max;

}

void sort_array(unsigned char *arr, unsigned int size){

  unsigned char tmp;
  for(int i = 0; i < size; i++){
    for(int j = i+1; j < size; j++){
      if(*(arr+i) < *(arr+j)){
        tmp = *(arr+i);
  	*(arr+i) = *(arr+j);
	*(arr+j) = tmp;
      }
    }
  }

}

