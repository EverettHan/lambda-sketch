// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATRepPointProjectionOperImpl
//
//===================================================================
//
// June 2012  Creation: JXO
//===================================================================
#ifndef CATRepPointProjectionOperImpl_H
#define CATRepPointProjectionOperImpl_H

// ExportedBy
#include "PolyVisuClash.h"

// Poly
#include "CATPolyBodyRayCastingIntersection.h"

// Visu
class CAT3DRep;
class CATRepWeakRef;

// Math
class CATTolerance;

class ExportedByPolyVisuClash CATRepPointProjectionOperImpl
{
public:
  CATRepPointProjectionOperImpl(CAT3DRep & iRep);
  ~CATRepPointProjectionOperImpl();

  virtual HRESULT ProjectPoint(const CATMathPoint & iPoint, CATPolyBodyRayCastingIntersection * & oResult);
  virtual HRESULT ProjectPointAlongDirection(const CATMathPoint & iPoint, const CATMathVector & iDir, CATPolyBodyRayCastingIntersection * & oResult, double iLambda = -1.);
private:
  CATRepWeakRef * m_ipRepWeakRef;
  const CATTolerance & m_Tol;
};

#endif
