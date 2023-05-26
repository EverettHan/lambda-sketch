//===================================================================
// COPYRIGHT Dassault Systemes 2010/04/14
//===================================================================
// CATIAfrWindowId.cpp
// Header definition of class CATIAfrWindowId
//===================================================================
//
// Usage notes: Do not use, reserved for ApplicationFrame internal use
//
//===================================================================
//  2010/04/14 Creation: ERS
//===================================================================
#ifndef CATIAfrWindowId_H
#define CATIAfrWindowId_H

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"


extern ExportedByCATAfrItf  IID IID_CATIAfrWindowId ;


class ExportedByCATAfrItf CATIAfrWindowId: public CATBaseUnknown
{
CATDeclareInterface;

public:

  virtual void SetWindowId (const int iId) = 0;
  virtual int GetWindowId () = 0;

};

//-----------------------------------------------------------------------

#endif
