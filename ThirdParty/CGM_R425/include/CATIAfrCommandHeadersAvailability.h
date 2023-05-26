//===================================================================
// COPYRIGHT Dassault Systemes 2010/04/14
//===================================================================
// CATIAfrCommandHeadersAvailability.cpp
// Header definition of class CATIAfrCommandHeadersAvailability
//===================================================================
//
// Usage notes: Do not use, reserved for ApplicationFrame internal use
//
//===================================================================
//  2010/04/14 Creation: ERS
//===================================================================
#ifndef CATIAfrCommandHeadersAvailability_H
#define CATIAfrCommandHeadersAvailability_H

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATAfrAvailabilityType.h"


extern ExportedByCATAfrItf  IID IID_CATIAfrCommandHeadersAvailability ;


class ExportedByCATAfrItf CATIAfrCommandHeadersAvailability: public CATBaseUnknown
{
CATDeclareInterface;

public:

  virtual void ApplyCommandHeadersAvailability (CATAfrAvailabilityType iAvailabilityMode) = 0;

};

//-----------------------------------------------------------------------

#endif
