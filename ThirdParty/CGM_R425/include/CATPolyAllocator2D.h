#ifndef CATPolyAllocator2D_H
#define CATPolyAllocator2D_H

#include "CATRefCounted.h"

class CATPolyAllocator2D : public CATRefCounted
{
public:
  static const int BlockSize = 4096;

  virtual void* Allocate() = 0;
  virtual void Deallocate(void*) = 0;
};

#endif // !CATPolyAllocator2D_H
