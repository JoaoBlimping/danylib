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

//writes a numerical value to an array of characters
template<typename T> char * danylib_valueToChars(T in);

//turns four characters into a 32 bit integer
template<typename T> T * danylib_charsToValue(char * chars);


#endif
