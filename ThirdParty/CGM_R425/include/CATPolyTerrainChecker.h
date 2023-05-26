#ifndef CATPolyTerrainChecker_h__
#define CATPolyTerrainChecker_h__

//===================================================================
// COPYRIGHT Dassault Systemes 2017
//===================================================================
// CATPolyTerrainChecker.h
// Header definition of class CATPolyTerrainChecker
//===================================================================
//
// Usage notes: Detect triangles overhanging triangle in terrain mesh  
//
//===================================================================
// HISTORIQUE :
// 28/04/2017 : NUA : Creation
//===================================================================


// export + error
#include "ExportedByCATPolyWatershedOperators.h"
#include "CATErrorDef.h"

// STL
#include <vector>

class CATIPolyMesh;

class ExportedByCATPolyWatershedOperators CATPolyTerrainChecker
{
public:

  CATPolyTerrainChecker(const CATIPolyMesh & iMesh);

  void IgnoreBoundaryTriangles()
  {
    m_DoIgnoreBoundaryTriangles = true;
  }

  HRESULT GetOverhangingTriangles(std::vector<int> & oRes);

private:

  const CATIPolyMesh & m_Mesh;
  bool m_DoIgnoreBoundaryTriangles;
};

#endif // CATPolyTerrainChecker_h__
