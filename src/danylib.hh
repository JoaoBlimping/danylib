/**
 * \mainpage danylib documentation
 * danylib is Dany Burton's official C++ library. It is a very nice code library if you
 * want to do things with c strings or converting between bytes and other numerical types.
 *
 * Check out the page for danylib.hh to get started
 */

/**
 * \file danylib.hh
 * Header file containing all of the standalone functions provided by danylib.
 * This file is contains the main interface of danylib, and at least at the moment
 * provides it's only interface.
 *
 * When installed normally, it is included as ```danylib/danylib.hh```
 */


#ifndef DANYLIB_H
#define DANYLIB_H


#include <stdio.h>
#include <stdint.h>
#include <cstring>


/**
 * comparitor for use on string pointers
 */
typedef struct
{
  /**
   * compares two string pointers.
   * determines if strings pointed to by two string pointers are equal
   */
  bool operator()(char const * a, char const * b)const
  {
    return strcmp(a, b) < 0;
  }
}
danylib_cmpstrptr;

/**
 * puts a string into an array that fits it.
 * Iterates over the string until it reaches a null character, it then creates a new
 * array of the same length of the string data and copies the string into it.
 * It does not delete the old one.
 */
char * danylib_fit(char * data);

/**
 * puts a string into an array of set length.
 * Copies length characters from data to a new character array of length length.
 * Does not delete the old array.
 */
char * danylib_fitToLength(char * data,int length);

/**
 * writes a numerical value to an array of bytes.
 * takes a numerical value of type T, and inserts it into an array of bytes the same
 * size as type T.
 */
template<typename T> uint8_t * danylib_valueToBytes(T in);

/**
 * turns an array of bytes into a numerical type
 * takes an array of bytes and turns them into a single value of type T.
 * The length of the array and the size of type T must match. TODO: enforce this
 */
template<typename T> T * danylib_bytesToValue(uint8_t * in);

/**
 * reads non byte data from a file into an array of bytes.
 * reads any number of items of type T from a file, and places their data into an array
 * of bytes.
 */
template<typename T> void danylib_readFromBytes(uint8_t * output,int nItems,FILE * input);

#endif
