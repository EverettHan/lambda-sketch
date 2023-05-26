// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCurveRefiner.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// May 2007  Creation: ndo
//===================================================================
#ifndef CATPolyCurveRefiner_h
#define CATPolyCurveRefiner_h

#include "PolyVizRefiners.h"
#include "CATErrorDef.h"  // HRESULT definition.
#include "CATBoolean.h"

#include "CATPolyCurveRefinerData.h"
#include "CATPolyUVRefinerParams.h"
#include "CATPolyUVRefiner.h"



class CATPolyUVRefiner;
class CATIPolyCurve;


// Refinement engine for CATIPolyCurve of any type.
class  ExportedByPolyVizRefiners CATPolyCurveRefiner 
{

public:

  /*
   * Constructor of a UV refiner engine for Curves. 
   * RefinementType, RefinementLevelMax and iSag should be set through
   * the Setters.
   */
  CATPolyCurveRefiner ();

  ~CATPolyCurveRefiner ();

public:

  INLINE void DoComputeTangents (CATBoolean iDoComputeTangents);
  INLINE void DoComputeWs (CATBoolean iDoComputeWs);
  INLINE void SetSag(double sag);
  INLINE void SetRefinementType(CATPolyUVRefiner::RefinementType iRefinementType);
  INLINE void SetRefinementLevel(unsigned int level);
  INLINE CATBoolean IsRefinementAdaptive () const;

public:

  HRESULT Refine (const CATIPolyCurve& iCurve);

  INLINE const CATPolyCurveRefinerData& GetRefinerData () const;

protected:

  CATPolyCurveRefinerData _OutputData;  // Buffers for output refiner data.

  double _Sag;
  unsigned int _RefinementLevel;
  CATPolyUVRefiner::RefinementType _RefinementType;
  CATBoolean _DoComputeTangents;
  CATBoolean _DoComputeWs;

protected:

  HRESULT RefinePTCurve (const CATIPolyCurve& iCurve);

  HRESULT InitializeRefinerData (const CATIPolyCurve& iCurve0);

};


inline void CATPolyCurveRefiner::DoComputeTangents (CATBoolean iDoComputeTangents)
{
  _DoComputeTangents = iDoComputeTangents;
}

inline void CATPolyCurveRefiner::DoComputeWs (CATBoolean iDoComputeWs)
{
  _DoComputeWs = iDoComputeWs;
}

inline const CATPolyCurveRefinerData& CATPolyCurveRefiner::GetRefinerData () const
{
  return _OutputData;
}
INLINE CATBoolean CATPolyCurveRefiner::IsRefinementAdaptive () const
{
  return _RefinementType == CATPolyUVRefiner::eAdaptive;
}
INLINE void CATPolyCurveRefiner::SetSag(double sag)
{
  _Sag = sag;
}
INLINE void CATPolyCurveRefiner::SetRefinementType(CATPolyUVRefiner::RefinementType iRefinementType)
{
  _RefinementType = iRefinementType;
}
INLINE void CATPolyCurveRefiner::SetRefinementLevel(unsigned int level)
{
  _RefinementLevel = level;
}

#endif
