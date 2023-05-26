#ifndef CATPolyVertexGradientOperator_h__
#define CATPolyVertexGradientOperator_h__
// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVertexGradientOperator.h
// Header definition of CATPolyVertexGradientOperator
//
//===================================================================
//
// Usage notes: Compute slope extremum around mesh vertices
//
//===================================================================
//
// 29/03/2018 : Creation
//===================================================================



// Math
#include "CATMathVector2D.h"
#include "CATMathVector.h"

// export
#include "ExportedByCATPolyWatershedOperators.h"

#include "CATPolyDropPathOnTerrainOperator.h"

class CATIPolyMesh;
class CATTolerance;

// STL
#include <vector>

class ExportedByCATPolyWatershedOperators CATPolyVertexGradientOperator
{
public:

  // create ope instance
  static CATPolyVertexGradientOperator * CreateInstance(const CATIPolyMesh & iMesh, const CATTolerance & iTolObject);

  virtual ~CATPolyVertexGradientOperator() {}

  // compute the gradients around all vertices
  virtual HRESULT Run() = 0;
    
  //// enum to specify is the slope reach a min or a max 
  //enum class KindOfExtremum
  //{
  //  K_Min,
  //  K_Max,
  //  K_Undef
  //};

  // struct to specify a slope extremum
  struct Extremum_t
  {
    //KindOfExtremum m_ExtremKind; // min ou max 
    CATMathVector m_Grad3D; // vecteur 3d norme representant le gradient sur un element du ring d'un sommet
    CATPolyDropPathOnTerrainOperator::KindOfPath m_PathKind; // type de primitive sur laquelle se trouve l'extremum : edge ou triangle
    int m_Ind; // indice du sommet (si extremum sur une edge du ring) ou indice du triangle si extremum dans l'interieur d'un triangle du ring
    Extremum_t(CATPolyDropPathOnTerrainOperator::KindOfPath iPathKind, int iNum, const CATMathVector & iVec3D) 
      : m_PathKind(iPathKind)
      , m_Grad3D(iVec3D)
      , m_Ind(iNum)
    {}
  };

  struct GradRingDecomposition_t
  {
    std::vector< Extremum_t > m_LocalMin, m_LocalMax;
  };


  virtual GradRingDecomposition_t GetGradientsAtVertex(int iV) const = 0;
  
};


#endif // CATPolyVertexGradientOperator_h__
