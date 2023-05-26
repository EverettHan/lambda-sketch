//===================================================================
// COPYRIGHT Dassault Systemes 2016/05/06
//===================================================================
// CATIHideShowNotDirty.cpp
// Header definition of class CATIHideShowNotDirty
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2016/05/06 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIHideShowNotDirty_H
#define CATIHideShowNotDirty_H

#include "CATVisItf.h"
#include "CATBaseUnknown.h"


extern ExportedByCATVisItf  IID IID_CATIHideShowNotDirty ;


class ExportedByCATVisItf CATIHideShowNotDirty : public CATBaseUnknown
{
CATDeclareInterface;

public:
  virtual HRESULT UseNotDirtyAttributes(CATBoolean &oUseNotDirtyAttributes)=0;
//
// TODO: Add your methods for this interface here.
//

};

//-----------------------------------------------------------------------
CATDeclareHandler( CATIHideShowNotDirty, CATBaseUnknown );

#endif
