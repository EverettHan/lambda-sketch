#ifndef CATPolyVoronoiWeighting_h__
#define CATPolyVoronoiWeighting_h__

// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshVertexCurvatureAttributeOpe.h : calcul du poids associe a un sommet pour l'estimation de la courbure
// @see http://www.geometry.caltech.edu/pubs/DMSB_III.pdf
// Discrete Differential-Geometry Operators for Triangulated 2 - Manifolds
//===================================================================
// December 2017  Creation NUA
//===================================================================

#include <vector>

// error handling
#include "CATSysErrorDef.h"

#include <array>

class CATIPolyMesh;
class CATTolerance;

// export
#include "ExportedByCATPolyFeatureLineOperator.h"

class ExportedByCATPolyFeatureLineOperator CATPolyVoronoiWeighting
{
public:

  CATPolyVoronoiWeighting(const CATIPolyMesh & iMesh, const CATTolerance & iTol);

  HRESULT Run() ;

  // get the contribution of the weight of the vertex whose local index is LocalVertexInd in the triangle NumTriangle
  double Get(int NumTriangle, int LocalVertexInd) const;

private:

  const CATIPolyMesh & m_Mesh;

  std::vector< std::array<double,3> > m_WeightByTriangles;


  const CATTolerance & m_Tol;
};

#endif // CATPolyVoronoiWeighting_h__
