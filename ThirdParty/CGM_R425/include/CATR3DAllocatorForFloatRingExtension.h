#ifndef CATR3DAllocatorForFloatRingExtension_H
#define CATR3DAllocatorForFloatRingExtension_H

#include <stdio.h>

class CATR3DAllocatorForFloatRingExtension
{

public:

  virtual ~CATR3DAllocatorForFloatRingExtension(){}

	////////////////////////////////////
	virtual void * Allocate ( size_t iSizeAlloc ) = 0;

	virtual void Desallocate ( void * iPtrObj )  = 0;

};

#endif
