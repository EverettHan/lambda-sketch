#ifndef IVisCPUBufferPool_H
#define IVisCPUBufferPool_H

#include "CATVisFoundation.h"

#include <memory>

class ExportedByCATVisFoundation IVisCPUBufferPool
{

public:

  virtual ~IVisCPUBufferPool();

  static std::unique_ptr<IVisCPUBufferPool> Create();

  // When this allocated buffer is not needed anymore, the shared_ptr must be set to nullptr
  virtual std::shared_ptr<void> AllocateBuffer(size_t iSize) = 0;

  // Unused buffers are kept allocated for some time, in case an allocation request of the same size happens.
  // You should call this method regularly (typically once each frame) such that those unused buffers 
  // finally get released at some point.
  virtual void DecreaseLifetime() = 0;


};



#endif // IVisCPUBufferPool_H
