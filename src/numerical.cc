#include "danylib.hh"

#include <stdint.h>


#define BYTE 8
#define BYTE_MASK 0xFF


template<typename T> uint8_t * danylib_valueToChars(T in)
{
  uint8_t * out = new uint8_t[sizeof(T)];

  for (int i = 0;i < sizeof(T);i++)
  {
    out[i] = in & BYTE_MASK;
    in >> BYTE;
  }
  return out;
}


template<typename T> T * danylib_charsToValue(uint8_t * in)
{
  T out = 0;

  for (int i = 0;i < sizeof(T);i++)
  {
    out |= in[i] << BYTE * i;
  }
  return out;
}
