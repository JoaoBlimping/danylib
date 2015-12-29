/** \mainpage danylib documentation
 * danylib is Dany Burton's official C++ library. It is a very nice code library if you
 * want to do things with c strings or converting between bytes and other numerical types.
 *
 * Check out the page for danylib.hh to get started */

/** \file danylib.hh
 * Header file containing all of the standalone functions provided by danylib.
 * This file is contains the main interface of danylib, and at least at the moment
 * provides it's only interface.
 *
 * When installed normally, it is included as ```danylib/danylib.hh``` */


#ifndef DANYLIB_H
#define DANYLIB_H


#include <stdio.h>
#include <stdint.h>
#include <cstring>


#define BYTE 8
#define BYTE_MASK 0xFF


/** comparitor for use on string pointers */
typedef struct
{
  /** compares two string pointers.
   * determines if strings pointed to by two string pointers are equal */
  bool operator()(char const * a, char const * b)const
  {
    return strcmp(a, b) < 0;
  }
}
danylib_cmpstrptr;

/** puts a string into an array that fits it.
 * Iterates over the string until it reaches a null character, it then creates a new
 * array of the same length of the string data and copies the string into it.
 * It does not delete the old one. */
char * danylib_fit(char * data);


/** finds the next string in a sequence of strings
 * when you have a sequence of null terminated strings all in the same array, you can use
 * this to find the start of the next string */
char const * danylib_findNextString(char const * data);


/** puts a string into an array of set length.
 * Copies length characters from data to a new character array of length length.
 * Does not delete the old array. */
template<typename T> T * danylib_fitToLength(T * data,int length)
{
  T * fittedData = new T[length];
  for (int i = 0;i < length;i++)
  {
    fittedData[i] = data[i];
  }

  return fittedData;
}

/** writes a numerical value to an array of bytes.
 * takes a numerical value of type T, and inserts it into an array of bytes the same
 * size as type T. */
template<typename T> void danylib_valueToBytes(T in,uint8_t * out)
{
  for (int i = 0;i < sizeof(T);i++)
  {
    out[i] = in & BYTE_MASK;
    in = in >> BYTE;
  }
}


/** turns an array of bytes into a numerical type
 * takes an array of bytes and turns them into a single value of type T.
 * The length of the array and the size of type T must match. */
template<typename T> T danylib_bytesToValue(uint8_t * in)
{
  T out = 0;

  for (int i = 0;i < sizeof(T);i++)
  {
    out |= in[i] << BYTE * i;
  }
  return out;
}


/** reads non byte data from a file into an array of bytes.
 * reads any number of items of type T from a file, and places their data into an array
 * of bytes. */
template<typename T> void danylib_readFromBytes(uint8_t * output,int nItems,FILE * input)
{
  for (int item = 0;item < nItems;item++)
  {
    T block;
    fread(&block,sizeof(T),1,input);
    for (int i = 0;i < sizeof(T);i++)
    {
      output[item * sizeof(T) + i] = block & BYTE_MASK;
      block >> BYTE;
    }
  }
}


#endif
