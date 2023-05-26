#ifndef CATPolyPolylineMeshInserterOperator_h__
#define CATPolyPolylineMeshInserterOperator_h__

//===================================================================
// COPYRIGHT Dassault Systemes 2019
//===================================================================
// CATPolyPolylineMeshInserterOperator.h
//===================================================================
//
// Usage notes: Insert a polyline into a mesh (along the z axis)
//===================================================================
// HISTORIQUE :
// 12/12/2019 : NUA : Creation
//===================================================================

#include "ExportedByCATPolyWatershedOperators.h"
#include "CATErrorDef.h"

#include "CATMathPoint2D.h"

class CATIPolyMesh;
class CATMathSetOfPoints;
class CATTolerance;

#include <memory>
#include <map>
#include <vector>

//////////
// - call "init" method
// - call "run" method to retrieve the mesh corresponding to the terrain part which flow to the given vertex 
//////////
class ExportedByCATPolyWatershedOperators CATPolyPolylineMeshInserterOperator
{
public:

  static CATPolyPolylineMeshInserterOperator * CreateInstance(CATIPolyMesh & iMesh, const CATTolerance & iTol);

  virtual ~CATPolyPolylineMeshInserterOperator() {}

  virtual HRESULT Run(const std::vector<CATMathPoint2D> & iPolyline, std::vector<int> & oInsertedVertexIndice) = 0;
};

#endif // CATPolyPolylineMeshInserterOperator_h__
