#include "danylib.hh"


#define BYTE 8
#define BYTE_MASK 0xFF


template<typename T> char * danylib_valueToChars(T in)
{
  char * out = new char[sizeof(T)];

  for (int i = 0;i < sizeof(T);i++)
  {
    out[i] = in & BYTE_MASK;
    in >> BYTE;
  }
  return out;
}


template<typename T> T * danylib_charsToValue(char * in)
{
  T out = 0;

  for (int i = 0;i < sizeof(T);i++)
  {
    out |= in[i] << BYTE * i;
  }
  return out;
}
