//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2013/04/22
//===================================================================
// CATIAfrSpecialTransitionPrivate.cpp
// Header definition of class CATIAfrSpecialTransitionPrivate
//===================================================================
//
// Usage notes: ONE implementation only, do not implement
//
//===================================================================
//  2013/04/22 Creation: ers
//===================================================================
#ifndef CATIAfrSpecialTransitionPrivate_H
#define CATIAfrSpecialTransitionPrivate_H

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"


extern ExportedByCATAfrItf  IID IID_CATIAfrSpecialTransitionPrivate ;


class ExportedByCATAfrItf CATIAfrSpecialTransitionPrivate: public CATBaseUnknown
{
CATDeclareInterface;

public:

  virtual int ExecuteTransition () = 0;
};

//-----------------------------------------------------------------------

#endif
