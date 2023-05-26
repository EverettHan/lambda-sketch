#ifndef CATPolyWatershedFlowGraphOpe_h__
#define CATPolyWatershedFlowGraphOpe_h__

//===================================================================
// COPYRIGHT Dassault Systemes 2018
//===================================================================
// CATPolyWatershedFlowGraphOpe.h
//===================================================================
// Produce the flow graph accross the terrain triangles and the valley edges
//===================================================================
// HISTORIQUE :
// 30/10/2018 : NUA : Creation
//===================================================================



#include "CATErrorDef.h"

class CATIPolyMesh;

// Watershed ope
#include "CATPolyDropPathOnTerrainOperator.h"

#include "ExportedByCATPolyWatershedOperators.h"

// STL
#include <map>
#include <array>
#include <vector>
#include <memory>

class CATPolySteepestSlopeOperator;
class CATPolyRidgeValleyOperator;
class CATPolyRingOperator;
class CATTolerance;

class CATPolyWatershedFlowGraph;

class ExportedByCATPolyWatershedOperators CATPolyWatershedFlowGraphOpe
{
public:

  // set ope
  virtual void SetSteepestSlopeOpe(CATPolySteepestSlopeOperator * iOpe) = 0;
  virtual void SetRidgeAndValleyOpe(CATPolyRidgeValleyOperator * iOpe) = 0;
  virtual void SetRingOpe(CATPolyRingOperator * iOpe) = 0;
  virtual void SetFlowOpe(CATPolyDropPathOnTerrainOperator * iOpe) = 0;

  

  // attribution de l'eau en un sommet 
  // VARIANTE 1 : pour chaque edge descendante, la contribution est calculee a prorata de la pente
  // VARIANTE 2 : l'edge la plus pentue recupere toute l'eau
  // par defaut : @K_OnlySteepestPolicy
  enum KindOfOutputFlowAtVertexPolicy
  {
    K_OnlySteepestPolicy,
    K_ProportionalToSlopePolicy
  };

  virtual void SetOfOutputFlowAtVertexPolicy(KindOfOutputFlowAtVertexPolicy k) = 0;

  // creation 
  static CATPolyWatershedFlowGraphOpe * CreateInstance(const CATIPolyMesh & iMesh, const CATTolerance & iTolerance);

  virtual ~CATPolyWatershedFlowGraphOpe() {}

  virtual HRESULT Run( std::shared_ptr<CATPolyWatershedFlowGraph>  & oResult) = 0;
};


#endif // CATPolyWatershedFlowGraphOpe_h__
