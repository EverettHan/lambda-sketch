#ifndef CATPolyWatershedClosestSegmentOpe_h__
#define CATPolyWatershedClosestSegmentOpe_h__


//===================================================================
// COPYRIGHT Dassault Systemes 2019
//===================================================================
// CATPolyWatershedClosestSegmentOpe.h
//===================================================================
//
// Usage notes: operator to project a point on a set of segments (valleys)
//===================================================================
// HISTORIQUE :
// 21/02/2019 : NUA : Creation
//===================================================================

#include "ExportedByCATPolyWatershedOperators.h"
#include "CATMathPoint2D.h"
#include "CATMathPoint.h"
#include "CATMathBox.h"
#include "CATMathBox2D.h"

#include <memory>
#include <set>
#include <vector>
#include <array>

class CATIPolyMesh;

class ExportedByCATPolyWatershedOperators CATPolyWatershedClosestSegmentOpe
{
public:
  
  struct IntersectionPoint_t
  {
    CATMathPoint m_Point;
    std::array<int, 2> m_Indices{0,0};
    double m_Lambda = 0.;
    double m_Depth = 0.;
  };

  static CATPolyWatershedClosestSegmentOpe * CreateInstance(const CATIPolyMesh & iMesh, const std::vector<std::array<int,2> > & iEdges);
  
  // points d'intersection tries selon le vecteur P1P2 (iPointOnLine)
  virtual HRESULT GetClosestPoint(const std::array<CATMathPoint, 2> & iPointOnLine, IntersectionPoint_t & oResult) const = 0;

  virtual ~CATPolyWatershedClosestSegmentOpe(){}
  
protected:

};
#endif // CATPolyWatershedClosestSegmentOpe_h__
