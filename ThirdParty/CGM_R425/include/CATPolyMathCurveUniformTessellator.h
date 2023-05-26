// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMathCurveUniformTessellator.h
//
//===================================================================
//
// February 2009  Creation: ndo
//===================================================================
#ifndef CATPolyMathCurveUniformTessellator_h
#define CATPolyMathCurveUniformTessellator_h

#include "PolyVizRefiners.h"
#include "CATErrorDef.h"  // HRESULT definition.

class CATPolyMathCurve;


class ExportedByPolyVizRefiners CATPolyMathCurveUniformTessellator 
{

public:

  inline CATPolyMathCurveUniformTessellator (const unsigned int iLevel);
  ~CATPolyMathCurveUniformTessellator () {}

public:

  inline unsigned int ComputeSizeBuffer () const;

  // Tessellate the curve uniformly and store the result in the buffer.
  // The size of the buffer should be greater or equal than 3 * ComputeSizeBuffer ().
  HRESULT Tessellate (const CATPolyMathCurve& iCurve, double buffer[]) const;
  HRESULT Tessellate (const CATPolyMathCurve& iCurve, float buffer[]) const;

private:

  unsigned int _Level;  // Level of refinement.
  double _StepSize;

private:

  inline double ComputeStepSize () const;

};


inline CATPolyMathCurveUniformTessellator::CATPolyMathCurveUniformTessellator (const unsigned int iLevel) :
  _Level (iLevel)
{
  _StepSize = ComputeStepSize ();
}

inline unsigned int CATPolyMathCurveUniformTessellator::ComputeSizeBuffer () const
{
  return _Level + 2;
}

inline double CATPolyMathCurveUniformTessellator::ComputeStepSize () const
{
  return 1 / double (_Level + 1);
}

#endif
