#ifndef _CATVizGarbageCollector_
#define _CATVizGarbageCollector_

#include "CATVizHeap.h"
#include "CATDataType.h"
#include "CATMutex.h"

struct ExportedBySGInfra CATVizGCItem
{
   void *_ptr;
   unsigned int _refCount;

   CATVizGCItem()
   {
      _ptr = NULL;
      _refCount = 0;
   }

   CATVizGCItem(void *iPtr)
   {
      _ptr = iPtr;
      _refCount = 0;
   }
};

int ExportedBySGInfra CompareGCItem(const CATVizGCItem *item1, const CATVizGCItem *item2);

class ExportedBySGInfra CATVizGarbageCollector : public CATVizHeap<CATVizGCItem>
{
public:
   // singleton constructor
   static CATVizGarbageCollector *GetInstance()
   {
	   return &_singleton;
   }

   // singleton destructor
   static void kill(){
   }

   // should be private
   CATVizGarbageCollector( int (*compareFunc)(const CATVizGCItem *elem1, const CATVizGCItem *elem2) );
   ~CATVizGarbageCollector();

   bool Insert(void *iPtr, unsigned int iRefCount);
   bool Remove(void *iPtr);
   unsigned int AddRef(void *iPtr);
   unsigned int Release(void *iPtr);
   unsigned int GetRefCount(void *iPtr);

private:

   unsigned int AddRef(CATVizBinaryNode *iNode);
   unsigned int Release(CATVizBinaryNode *iNode);
   unsigned int GetRefCount(CATVizBinaryNode *iNode);
   CATMutex* _pMutex;

   static CATVizGarbageCollector _singleton;
};

#define CATVizDeclareTinyRefCount(iSizeInBits )        \
   virtual unsigned int AddRef();                      \
   virtual unsigned int Release();                     \
   virtual unsigned int GetRefCount();                 \
   protected:                                          \
   unsigned int _refCount:iSizeInBits;

#define CATVizInitTinyRefCount()                       \
   _refCount = 0;                                      \
   AddRef();

#define CATVizImplementTinyRefCount(iClass,iSizeInBits )               \
                                                                       \
unsigned int iClass::AddRef()                                          \
{                                                                      \
   CATVizGarbageCollector *pGC = CATVizGarbageCollector::GetInstance();\
   if( !pGC ) return 0;                                                \
                                                                       \
   if( _refCount == ((1 << iSizeInBits)-1) )                           \
      return pGC->AddRef(this);                                        \
   else{                                                               \
      ++_refCount;                                                     \
      if( _refCount == ((1 << iSizeInBits)-1) )                        \
         pGC->Insert(this, _refCount);                                 \
      return _refCount;                                                \
   }                                                                   \
}                                                                \
unsigned int iClass::Release()                                         \
{                                                                      \
   CATVizGarbageCollector *pGC = CATVizGarbageCollector::GetInstance();\
   if( !pGC ) return 0;                                                \
                                                                       \
   if( _refCount == ((1 << iSizeInBits)-1) ){                          \
      unsigned int ref = pGC->Release(this);                           \
      if( ref >= ((1 << iSizeInBits)-1) )                              \
         return ref;                                                   \
      pGC->Remove(this);                                               \
   }                                                                   \
   if(!--_refCount){                                                   \
      this->Destroy();                                                 \
      return 0;                                                        \
   }                                                                   \
   return _refCount;                                                   \
}                                                                \
unsigned int iClass::GetRefCount()                                     \
{                                                                      \
   CATVizGarbageCollector *pGC = CATVizGarbageCollector::GetInstance();\
   if( !pGC ) return 0;                                                \
                                                                       \
   if( _refCount == ((1 << iSizeInBits)-1) )                           \
      return pGC->GetRefCount(this);                                   \
   else                                                                \
      return _refCount;                                                \
}

#endif
