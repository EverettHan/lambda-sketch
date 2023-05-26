// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPPTopologicalPoint.h
//
//===================================================================
//
// Usage notes: Abstract description of a point in a topological space
// for the nD Path Planning solver.
//
//===================================================================
//
// 2013-01-04 XXC: Creation
//===================================================================

#ifndef CATPolyPPTopologicalPoint_HH
#define CATPolyPPTopologicalPoint_HH

#include "CATBoolean.h"
#include "PolyPathPlanning.h"
#include "CATMathInline.h"
#include "CATPolyPPTopologicalSpace.h"

class ExportedByPolyPathPlanning CATPolyPPTopologicalPoint
{
public:
  CATPolyPPTopologicalPoint(const CATPolyPPTopologicalSpace & iSpace);
  CATPolyPPTopologicalPoint(const CATPolyPPTopologicalPoint & iPoint);
  ~CATPolyPPTopologicalPoint();

  CATPolyPPTopologicalPoint & operator = (const CATPolyPPTopologicalPoint & iPoint);

  /* INLINE double operator * (const CATPolyPPTopologicalPoint & iPoint2) const */
  /* { */
  /*   return _Space.SqDistance(*this, iPoint2); */
  /* } */

  INLINE double & operator [] (int idx)
  {
    return _Coords[idx];
  }

  INLINE const double & operator [] (int idx) const
  {
    return _Coords[idx];
  }

  INLINE CATBoolean IsInsideLimits() const
  {
    return _Space.IsInsideLimits(*this);
  }

  const CATPolyPPTopologicalSpace & GetSpace() const 
  {
    return _Space;
  }

protected:
  
  friend class CATPolyPPTopologicalSpace;
  friend class CATPolyPPTopologicalSpaceR2;
  friend class CATPolyPPTopologicalSpaceR3;
  friend class CATPolyPPTopologicalSpaceSO2;
  friend class CATPolyPPTopologicalSpaceSO3;

  const CATPolyPPTopologicalSpace & _Space;
  double * _Coords;
  double _staticCoords[3];//perf optimisation avoid new allocation for space with dimension <=3
};

#endif
