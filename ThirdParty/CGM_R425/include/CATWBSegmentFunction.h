// COPYRIGHT Dassault Systemes 2018
//===================================================================
//
// CATWBSegmentFunction.h
// Header definition of CATWBSegmentFunction
//
//===================================================================
//
// Usage notes: A list of CATWBSegmentFunctionInterval classes
//
//===================================================================
//
// 04/04/18 Q48  Creation
// 01/04/19 Q48  Change AddInterval signature for memory management
//===================================================================

#ifndef CATWBSegmentFunction_h
#define CATWBSegmentFunction_h

// System
#include "CATCDSVirtual.h"
#include "WhiteBoxData.h"

// Data
#include "CATCDSBoolean.h"

// WBx
#include "CATWBSegmentFunctionInterval.h" // includes declaration of list

// Debug
#include "CATWBDebug.h"


// -------------------------------------------------------------------------------------------------------------
class ExportedByWhiteBoxData CATWBSegmentFunction 
{
public:

  CATWBSegmentFunction();
  ~CATWBSegmentFunction();

public:

  // The list stores a copy of the interval passed in
  CATCDSBoolean AddInterval(const CATWBSegmentFunctionInterval & iInterval);

  int GetNumIntervals() const;
  const CATWBSegmentFunctionInterval* GetInterval(const int iIndex) const;

private:

  CATCDSLISTP(CATWBSegmentFunctionInterval) _ListIntervals;
};
#endif // CATWBSegmentFunction_h
