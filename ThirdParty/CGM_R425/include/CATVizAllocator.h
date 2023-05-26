#ifndef _CATVizAllocator_
#define _CATVizAllocator_

#include "SGInfra.h"
#include "CATSysAllocator.h"
#include "assert.h"


class ExportedBySGInfra CATVizObjectPool
{
public:
  static void *AllocateObject(size_t iSize);
  static void ReleaseObject(void *iObject,size_t iSize);
protected:
  static unsigned int _maxObjectSize;
  static void **_pool;
};

class ExportedBySGInfra CATVizAllocator
{
public:
  static inline void* GetVolatilePool(void)
  {
    return _volatilePool;
  }

  static inline void* GetPermanentPool(void)
  {
    return _permanentPool;
  }

  static void* VolatileAllocate(size_t iSize);
  static  void VolatileDeallocate(void* iPtr, size_t iSize = NULL);

  static  void* PermanentAllocate(size_t iSize); 
  static  void PermanentDeallocate(void* iPtr, size_t iSize = NULL);

  static void* _volatilePool;
  static void* _permanentPool;
};

#define CATVizDeclarePagedNewOverride(iClass )               \
   void *operator new(  size_t iSize);                       \
   void operator delete(void *iAddr );                       


#define CATVizImplementPagedNewOverride(iClass ,iType )      \
void *iClass::operator new(size_t iSize)                     \
{                                                            \
   if ((iType) & CATPool_Volatile)                         \
      return  CATVizAllocator::VolatileAllocate(iSize);     \
   else                                                      \
      return  CATVizAllocator::PermanentAllocate(iSize);      \
}                                                            \
void iClass::operator delete(void *iObject)                  \
{                                                            \
   if ((iType) & CATPool_Volatile)                            \
      CATVizAllocator::VolatileDeallocate(iObject);         \
   else                                                      \
      CATVizAllocator::PermanentDeallocate(iObject);          \
}      

#define CATVizDeclareVolatileObject(iClass )               \
   void *operator new(  size_t iSize);                     \
   void operator delete(void *iAddr );                    

#define CATVizImplementVolatileObject(iClass)                \
void *iClass::operator new(size_t iSize)                     \
{                                                            \
  return  CATVizObjectPool::AllocateObject(iSize);           \
}\
void iClass::operator delete(void *iObject)\
{\
  CATVizObjectPool::ReleaseObject(iObject,sizeof(iClass));   \
}      

#endif
