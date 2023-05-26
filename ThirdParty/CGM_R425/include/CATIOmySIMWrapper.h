//===================================================================
// COPYRIGHT Dassault Systemes 2016/03/16
//===================================================================
// CATIOmySIMWrapper.cpp
// Header definition of class CATIOmySIMWrapper
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2016/03/16 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIOmySIMWrapper_H
#define CATIOmySIMWrapper_H

#include "CATOMYBaseSession.h"
#include "CATBaseUnknown.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOMYBaseSession IID IID_CATIOmySIMWrapper;
#else
extern "C" const IID IID_CATIOmySIMWrapper ;
#endif

extern ExportedByCATOMYBaseSession  IID IID_CATIOmySIMWrapper ;


class ExportedByCATOMYBaseSession CATIOmySIMWrapper: public CATBaseUnknown
{
CATDeclareInterface;

public:

  virtual HRESULT Open() = 0;

};

//-----------------------------------------------------------------------

#endif