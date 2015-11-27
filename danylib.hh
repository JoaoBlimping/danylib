#ifndef DANYLIB_H
#define DANYLIB_H


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


#endif
