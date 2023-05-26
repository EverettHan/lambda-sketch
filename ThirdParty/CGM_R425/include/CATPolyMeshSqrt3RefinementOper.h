#ifndef CATPolyMeshSqrt3RefinementOper_H
#define CATPolyMeshSqrt3RefinementOper_H

#ifdef _WINDOWS_SOURCE

//===================================================================
// COPYRIGHT Dassault Systemes 17/11/2016
//===================================================================
// CATPolyMeshSqrt3RefinementOpe.h
// Header definition of class CATMRSBSPConvexComplex
//===================================================================
//
// Usage notes: Naive implementation of sqrt(3) subdivision scheme (Kobbelt, 2000)
//
//===================================================================
// HISTORIQUE :
// 17/11/2016 : NUA : Creation
//===================================================================

#include "CATPolyModOperators.h"
#include "CATSysErrorDef.h" // pour HRESULT

#include <vector>

class CATIPolyMesh;

class ExportedByCATPolyModOperators CATPolyMeshSqrt3RefinementOper
{
public:
  CATPolyMeshSqrt3RefinementOper(CATIPolyMesh & iMesh) ;
  virtual ~CATPolyMeshSqrt3RefinementOper() ;

  // run on whole mesh
  HRESULT Run();

  // run on selected triangles
  HRESULT Run(const std::vector<int> & iTriangles);

private:

  // methods
  HRESULT SubdivideTriangle( int iTriangle);

  // members
  CATIPolyMesh & m_Mesh;
};

#endif // _WINDOWS_SOURCE
#endif // CATPolyMeshSqrt3RefinementOper_H
