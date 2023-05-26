//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2016/04/19
//===================================================================

#ifndef CATSYPAbstractPool_H
#define CATSYPAbstractPool_H

#include <UIVCoreTools.h>
#include <CATSYPArray.h>

class ExportedByUIVCoreTools CATSYPAbstractPool
{
public:
  /** Gets an unused item*/
  void* UseItem();
  /** Gives back an item to the pool*/
  void ReleaseItem(void* i_pItemToRelease);
protected:
  virtual void* CreateItem()=0;
  virtual void DestroyItem(void * i_pItem)=0;
  virtual void InitItem(void * i_pItem)=0;
protected:
  CATSYPArray<void*> _unusedItems;
};

#define CAT_SYP_POOL_NEW_DELETE(Class, ExportedBy)\
class Class;\
class ExportedBy CATSYPPool_##Class : public CATSYPAbstractPool\
{\
public:\
  ~CATSYPPool_##Class()\
  {\
    int index=0;\
    for (index=0; index<_unusedItems.GetLength();index++) {\
      delete _unusedItems.QuickGet(index);\
    }\
    _unusedItems.RemoveAll();\
  }\
protected:\
  virtual void* CreateItem(){\
    return new Class();\
  }\
  virtual void DestroyItem(void * i_pItem){\
    delete i_pItem;\
  }\
  virtual void InitItem(void * i_pItem){}\
};


#endif
