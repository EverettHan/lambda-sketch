// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMathCurveAdaptiveTessellator.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// July 2007  Creation: ndo
//===================================================================
#ifndef CATPolyMathCurveAdaptiveTessellator_H
#define CATPolyMathCurveAdaptiveTessellator_H

#include "CATErrorDef.h"
#include "PolyVizRefiners.h"
#include "CATErrorDef.h"
#include "CATIAV5Level.h"

class CATPolyMathCurve;


class ExportedByPolyVizRefiners CATPolyMathCurveAdaptiveTessellator
{

public:

  /*
   * Construct a CATPolyMathCurve tessellator given a sag to meet and a level of refinement not to be
   * exceeded.  The level of refinement of the CATPolyMathCurve will adapt to these parameters.
   */
  CATPolyMathCurveAdaptiveTessellator (const double iSag, const unsigned int iMaxLevel);

  ~CATPolyMathCurveAdaptiveTessellator () {}

public:

  inline unsigned int ComputeSizeBuffer () const;

  // Tessellate the curve uniformly and store the result in the buffer.
  // The size of the buffer should be greater or equal than 3 * ComputeSizeBuffer ().
  // The number of samples stored in the buffer is returned in oNbSamples.
  // (Number of coordinates stored in the buffer is 3 * oNbSamples.)
#ifndef CATIAR213
  HRESULT Tessellate (const CATPolyMathCurve& iCurve, double buffer[], int& oNbSamples) const;
#endif
  HRESULT Tessellate (const CATPolyMathCurve& iCurve, float buffer[], int& oNbSamples) const;
#ifdef CATIAR213
  // Same as Tessellate but uses UV2 tessellation
  HRESULT Tessellate2 (const CATPolyMathCurve& iCurve, float buffer[], int& oNbSamples) const;
#endif

public:

  // Given a curve and a target sag, compute the level of a uniform refinement of the curve
  // to reach the sag.  The returned value will not exceed iMaxLevelOfRefinement.
  static unsigned int ComputeLevelOfRefinement (const CATPolyMathCurve& iCurve, const double iSag,
                                                const unsigned int iMaxLevelOfRefinement);
#ifdef CATIAR213
  static unsigned int ComputeLevelOfRefinement2 (const CATPolyMathCurve& iCurve, const double iSag,
                                                 const unsigned int iMaxLevelOfRefinement);
#endif

private:

  double _Sag;
  unsigned int _MaxLevel;  // Maximum level of refinement not to exceed.
  
};


inline CATPolyMathCurveAdaptiveTessellator::CATPolyMathCurveAdaptiveTessellator (const double iSag, const unsigned int iMaxLevel) :
  _Sag (iSag),
  _MaxLevel (iMaxLevel)
{
}

inline unsigned int CATPolyMathCurveAdaptiveTessellator::ComputeSizeBuffer () const
{
  return _MaxLevel + 2;
}


#endif
