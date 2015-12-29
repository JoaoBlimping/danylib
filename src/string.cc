#include "danylib.hh"

#include <stdint.h>


char * danylib_fit(char * data)
{
  //find the length of the data
  int length = 0;
  while (data[length] != '\0')
  {
    length++;
  }
  length++;

  //put it into an array that fits it
  char * fittedData = new char[length];
  for (int i = 0;i < length - 1;i++)
  {
    fittedData[i] = data[i];
  }
  fittedData[length - 1] = '\0';

  return fittedData;
}


char const * danylib_findNextString(char const * data)
{
	while(*data != '\0') data++;
	data++;
	return data;
}
