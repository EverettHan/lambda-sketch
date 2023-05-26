#ifndef __CATOmxMemoryManager_h__
#define __CATOmxMemoryManager_h__

#include "CATOmxKernel.h"
#include "CATSysAllocator.h"
#include "IUnknown.h"
#include "CATOmxCxxPortability.h"

class ExportedByCATOmxKernel CATOmxMemoryManager
{
public:
  enum Strategy
  {

    Document,     //Document / Container lifetime object
    Modification, //Modification / Transaction lifetime object
    Transitory,   //do not use
    NoPool,       //Use malloc/free
    LAST          //Last item
  };
  static void *Alloc(Strategy, size_t size);
  static void Free(Strategy, void* ptr);
  /** manages out of memory: assert !*/
  OMX_Cxx11_NORETURN static void OutOfMemory();
private:
  CATOmxMemoryManager();
  CATOmxMemoryManager(const CATOmxMemoryManager&);
  CATOmxMemoryManager& operator=(const CATOmxMemoryManager&);
};

/*
* use this macro to implement allocator
* @param Class the target implementing class
* @param Strategy one of the following strategy Document|Modification|Transitory
*/
#define OMX_IMPLEMENT_NEW(Class,Strategy) \
void *Class::operator new(size_t iSize) {return CATOmxMemoryManager::Alloc(CATOmxMemoryManager::Strategy,iSize);} \
void Class::operator delete(void *iObject) { CATOmxMemoryManager::Free(CATOmxMemoryManager::Strategy,iObject); }
#endif
