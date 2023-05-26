#ifndef CATPolyMeshScalarDerivativeOpe_h__
#define CATPolyMeshScalarDerivativeOpe_h__

// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshScalarDerivativeOpe.h : compute of mesh gradient at vertices

//
//===================================================================
// January 2020  Creation DCU3
//===================================================================

#include "CATMath3x3Matrix.h"
#include "CATMath2x2Matrix.h"
#include "CATMathVector2D.h"
#include "CATMathVector.h"
#include "CATMathPoint.h"


// export
#include "ExportedByCATPolyFeatureLineOperator.h"

// mesh
#include "CATPolyVertexCurvatureAttributeOpe.h"
#include "CATPolyVertexNormalAttributeOpe.h"
#include "CATPolyVoronoiWeighting.h"

// math


// stl
#include <vector>
#include <map>
#include <array>

class CATIPolyMesh;


class ExportedByCATPolyFeatureLineOperator CATPolyMeshScalarDerivativeOpe
{
public:

    
  CATPolyMeshScalarDerivativeOpe(const CATIPolyMesh & iMesh, const std::vector<double> & ifunction) 
    : m_function(ifunction)
    , m_Mesh(iMesh)
  {}

  HRESULT Run();
  double Get(const int i) { return m_function[i]; } //i=0->n
  CATMathVector GetVector(const int i) { return m_derivative[i]; }//i = 0->n
  static void readMESH(const CATIPolyMesh & m_Mesh, std::vector<CATMathPoint > & V, std::vector < std::array<int, 3>> & F);
 

private:

  HRESULT ComputeGradient(std::vector<CATMathPoint >  V, std::vector < std::array<int, 3>>  F, std::vector<CATMathVector >  &out);

  const CATIPolyMesh & m_Mesh;
  std::vector<double> m_function;
  std::vector<CATMathVector> m_derivative;

  
};


#endif // CATPolyMeshScalarDerivativeOpe_h__
