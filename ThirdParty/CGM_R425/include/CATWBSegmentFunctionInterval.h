// COPYRIGHT Dassault Systemes 2018
//===================================================================
//
// CATWBSegmentFunctionInterval.h
// Header definition of CATWBSegmentFunctionInterval
//
//===================================================================
//
// Usage notes: A class to define a single interval for a segment function
//
//===================================================================
//
// 04/04/18 Q48  Creation
// 01/04/19 Q48  Add protected copy constructor
//===================================================================

#ifndef CATWBSegmentFunctionInterval_h
#define CATWBSegmentFunctionInterval_h

// System
#include "CATCDSVirtual.h"
#include "WhiteBoxData.h"

// Data
#include "CATCDSBoolean.h"

// WBx
#include "CATWBSegmentFunctionDataPt.h"

// Debug
#include "CATWBDebug.h"

// -------------------------------------------------------------------------------------------------------------
// Declaration of CDS-list of this class
class CATWBSegmentFunctionInterval;
CATCDSLISTP_DECLARE_EXPORTED(CATWBSegmentFunctionInterval, ExportedByWhiteBoxData);
// -------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------
class ExportedByWhiteBoxData CATWBSegmentFunctionInterval 
{
public:

  enum CATWBInterpolationType{ Unset = 0, Linear, Quadratic, Cubic, QuarterSin, QuarterCos };

  CATWBSegmentFunctionInterval(const CATWBSegmentFunctionDataPt & iValueStart,
                               const CATWBSegmentFunctionDataPt & iValueEnd,
                               const CATWBInterpolationType       iType);

  ~CATWBSegmentFunctionInterval();

private:
  CATWBSegmentFunctionInterval();

protected:

  friend class CATWBSegmentFunction;

  CATWBSegmentFunctionInterval(const CATWBSegmentFunctionInterval & iToCopy);

public:

  inline const CATWBSegmentFunctionDataPt * GetStart() const;
  inline const CATWBSegmentFunctionDataPt * GetEnd() const;

  inline CATWBInterpolationType GetType() const;
private:

  const CATWBSegmentFunctionDataPt _ValueStart;
  const CATWBSegmentFunctionDataPt _ValueEnd;

  CATWBInterpolationType _Type;

};

inline const CATWBSegmentFunctionDataPt * CATWBSegmentFunctionInterval::GetStart() const { return & _ValueStart; }
inline const CATWBSegmentFunctionDataPt * CATWBSegmentFunctionInterval::GetEnd() const { return & _ValueEnd; }

inline CATWBSegmentFunctionInterval::CATWBInterpolationType CATWBSegmentFunctionInterval::GetType() const { return _Type; }
#endif // CATWBSegmentFunctionInterval_h
