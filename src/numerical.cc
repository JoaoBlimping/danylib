#include "danylib.hh"

#include <stdint.h>


#define BYTE 8
#define BYTE_MASK 0xFF


template<typename T> uint8_t * danylib_valueToBytes(T in)
{
  uint8_t * out = new uint8_t[sizeof(T)];

  for (int i = 0;i < sizeof(T);i++)
  {
    out[i] = in & BYTE_MASK;
    in >> BYTE;
  }
  return out;
}


template<typename T> T * danylib_bytesToValue(uint8_t * in)
{
  T out = 0;

  for (int i = 0;i < sizeof(T);i++)
  {
    out |= in[i] << BYTE * i;
  }
  return out;
}


template<typename T> void danylib_readFromBytes(uint8_t * output,int nItems,FILE * input)
{
  for (int item = 0;item < nItems;item++)
  {

  }
}


template<typename T> void danylib_writeToBytes(uint8_t * input,int nItems,FILE * output)
{

}
