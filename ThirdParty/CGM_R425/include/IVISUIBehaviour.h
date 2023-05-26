//===================================================================
// COPYRIGHT Dassault Systemes 2017/01/04
//===================================================================
// IVISUIBehaviour.cpp
// Header definition of class IVISUIBehaviour
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2017/01/04 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef IVISUIBehaviour_H
#define IVISUIBehaviour_H

#include "IVInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

extern ExportedByIVInterfaces  IID IID_IVISUIBehaviour ;


class ExportedByIVInterfaces IVISUIBehaviour: public CATBaseUnknown
{
CATDeclareInterface;

public:

  virtual CATUnicodeString GetName() = 0;

  virtual HRESULT Activate() = 0;
  virtual HRESULT Deactivate() = 0;

  virtual bool IsActivated() = 0;

  virtual void Step(double iElapsedTime) = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler( IVISUIBehaviour, CATBaseUnknown );

#endif
