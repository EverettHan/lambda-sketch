#ifndef CATPolyWatershedTriangleAroundPathOpe_h__
#define CATPolyWatershedTriangleAroundPathOpe_h__

//===================================================================
// COPYRIGHT Dassault Systemes Provence 2019
//===================================================================
// CATPolyWatershedTriangleAroundPathOpe.h
//===================================================================
//
// Usage notes: Retrieve the set of horizontal triangle around a water path
//
//===================================================================
// HISTORIQUE :
// 30/07/2019 : NUA : Creation
//===================================================================

#include "ExportedByCATPolyWatershedOperators.h"

#include "CATSysErrorDef.h"

#include "CATPolyDropPathOnTerrainOperator.h"

class CATTolerance;
class CATIPolyMesh;

#include <set>

class ExportedByCATPolyWatershedOperators CATPolyWatershedTriangleAroundPathOpe
{
public:

  static CATPolyWatershedTriangleAroundPathOpe * CreateInstance ( const CATTolerance & iTol, const CATIPolyMesh & iMesh, double iTolForHCheckOnNormal);

  virtual ~CATPolyWatershedTriangleAroundPathOpe() {}

  virtual HRESULT Run(const CATPolyDropPathOnTerrainOperator::WaterFlow_t & iPath, std::set<int> & TrianglesAround) const = 0;
};
#endif // CATPolyWatershedTriangleAroundPathOpe_h__
