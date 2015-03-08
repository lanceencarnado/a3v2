#ifndef PARRAY_H
#define PARRAY_H

#include "Pirate.h"

class PArray
{
  public:
    PArray();
    ~PArray();
    int     add(Pirate*);
    int     getSize();
    Pirate* getWithId(int);
    Pirate* get(int);
  private:
    int     size;
    Pirate* elements[MAX_PIRATES];
};

#endif
