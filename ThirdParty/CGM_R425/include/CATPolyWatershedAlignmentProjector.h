#ifndef CATPolyWatershedAlignmentProjector_h__
#define CATPolyWatershedAlignmentProjector_h__

//===================================================================
// COPYRIGHT Dassault Systemes 2019
//===================================================================
// CATPolyWatershedContributionsOperator.h
//===================================================================
//
// Usage notes: construit un chemin (ne representant pas forcement un trajet d'eau) a partir d'une sequence de points
//===================================================================
// HISTORIQUE :
// 19/02/2019 : NUA : Creation
//===================================================================



#include "ExportedByCATPolyWatershedOperators.h"
#include "CATPolyDropPathOnTerrainOperator.h"
#include "CATErrorDef.h"

class CATIPolyMesh;
class CATPolyWatershedFlowGraph;
class CATTolerance;

#include <vector>
#include <memory>
#include <map>

//////////
// - call "init" method
// - call "run" method to retrieve the mesh corresponding to the terrain part which flow to the given vertex 
//////////
class ExportedByCATPolyWatershedOperators CATPolyWatershedAlignmentProjector
{
public:
  static CATPolyWatershedAlignmentProjector * CreateInstance(const CATIPolyMesh & iMesh, const CATTolerance & iTol);
  virtual ~CATPolyWatershedAlignmentProjector() {}

  virtual HRESULT Init() = 0;

  // on construit un chemin (ne representant pas forcement un trajet d'eau) a partir d'une sequence de points
  virtual HRESULT Run(std::vector<CATMathPoint> & iPolylinePoints, CATPolyDropPathOnTerrainOperator::WaterFlow_t & oResult) = 0;
};


#endif // CATPolyWatershedAlignmentProjector_h__
