#include <iostream>
#include <string>
using namespace std;

#include "PArray.h"

PArray::PArray() : size(0)
{ 
  for (int i=0; i<MAX_PIRATES; ++i)
    elements[i] = 0;
}

PArray::~PArray() 
{
  for (int i=0; i<size; ++i) 
    delete elements[i];
}

int PArray::add(Pirate *pirate)
{
  if (size == MAX_PIRATES)
    return C_NOK;

  elements[size] = pirate;
  size++;
  return C_OK;
}

Pirate* PArray::getWithId(int id)
{
  for (int i=0; i<size; ++i) {
    if (elements[i] == 0)
      continue;
    if (elements[i]->getId() == id)
      return elements[i];
  }

  return(0);
}

Pirate* PArray::get(int index)
{
  if (index >= 0 && index < size)
    return elements[index];

  return 0;
}

int PArray::getSize() { return size; }

