// COPYRIGHT Dassault Systemes 2018
//===================================================================
//
// CATWBSegmentFunctionDataPt.h
// Header definition of CATWBSegmentFunctionDataPt
//
//===================================================================
//
// Usage notes: A class to define a single data point for a segment function
//
//===================================================================
//
//  04/04/18 Q48 Creation
//===================================================================

#ifndef CATWBSegmentFunctionDataPt_h
#define CATWBSegmentFunctionDataPt_h

// System
#include "CATCDSVirtual.h"
#include "WhiteBoxData.h"

// Data
#include "CATCDSBoolean.h"

// WBx
#include "CATWBValue.h"

// Debug
#include "CATWBDebug.h"

// -------------------------------------------------------------------------------------------------------------
class ExportedByWhiteBoxData CATWBSegmentFunctionDataPt 
{
private:

  CATWBSegmentFunctionDataPt();

public:

  CATWBSegmentFunctionDataPt(const CATWBValue & iValueX,
                             const CATWBValue & iValueY);

  CATWBSegmentFunctionDataPt(const double iValueX,
                             const double iValueY);

  ~CATWBSegmentFunctionDataPt();

  inline const CATWBValue & GetX() const;
  inline const CATWBValue & GetY() const;

private:

  const CATWBValue _X;
  const CATWBValue _Y;
};

inline const CATWBValue & CATWBSegmentFunctionDataPt::GetX() const { return _X; }
inline const CATWBValue & CATWBSegmentFunctionDataPt::GetY() const { return _Y; }

#endif // CATWBSegmentFunctionDataPt_h
