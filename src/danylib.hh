#ifndef DANYLIB_H
#define DANYLIB_H


#include <stdint.h>
#include <cstring>


//lets you compare string pointers
typedef struct
{
  bool operator()(char const * a, char const * b)const
  {
    return strcmp(a, b) < 0;
  }
}
danylib_cmpstrptr;

//puts a string into an array that fits it
char * danylib_fit(char * data);

//puts an array of chars into an array of a set size
char * danylib_fitToLength(char * data,int length);

//writes a numerical value to an array of bytes
template<typename T> uint8_t * danylib_valueToChars(T in);

//turns an array of bytes into an integer type
//the array must be the same size as the type
template<typename T> T * danylib_charsToValue(uint8_t * in);

//reads non byte data from a file into an array of bytes
template<typename T> void danylib_readFromBytes(uint8_t * output,int nItems,FILE * input);

//reads non byte data from a file into an array of bytes
template<typename T> void danylib_writeToBytes(uint8_t * input,int nItems,FILE * output);

#endif
