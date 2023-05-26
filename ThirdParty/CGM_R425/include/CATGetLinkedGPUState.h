#ifndef CATGetLinkedGPUState_h
#define CATGetLinkedGPUState_h

#include "CATVisFoundation.h"

struct LinkedGPU
{
  enum State
  {
    eUnknown = -1,
    eUnavailable = 0, // This device doesn't support linked GPUs
    eAvailable,       // This device support linked GPUs but it is not activated.
    eActive,
  };
};

ExportedByCATVisFoundation LinkedGPU::State CATGetLinkedGPUState();

#endif
