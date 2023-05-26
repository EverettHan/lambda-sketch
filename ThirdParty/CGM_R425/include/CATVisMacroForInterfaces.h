#ifndef CATVISMACROFORINTERFACES_H
#define CATVISMACROFORINTERFACES_H

/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

// COPYRIGHT DASSAULT SYSTEMES 2009

//#include "CATVisFoundation.h"
#include "CATCmpGuid.h"

// permanent interfaces
class IVisSGObject;

/** @nodoc */
#define CATVisDeclarePublicInterfaceAdhesion(iClass, iInterface, iBOAExtension) \
public:                                                                         \
  void* operator new(size_t iSize);                                             \
  void operator delete(void *iAddr);                                            \
  virtual IVisSGObject* GetInterface() const;                                   \
  virtual HRESULT __stdcall QueryInterface(const IID &iIID, void **oPPV);       \
  INLINE iInterface* Get##iInterface() const { return (iInterface *)GetInterface();};

#endif
