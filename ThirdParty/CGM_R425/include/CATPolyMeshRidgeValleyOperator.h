#ifndef CATPolyMeshRidgeValleyOperator_H_
#define CATPolyMeshRidgeValleyOperator_H_
//===================================================================
// COPYRIGHT Dassault Systemes 2017
//===================================================================
// CATPolyMeshRidgeValleyOperator.h
// Header definition of class CATPolyMeshRidgeValleyOperator
//===================================================================
//
// Usage notes: Determine the edges on ridges and valley
//
//===================================================================
// HISTORIQUE :
// 18/02/2017 : NUA : Creation
//===================================================================

#include "CATSysErrorDef.h" // pour HRESULT

// export
#include "CATPolyMeshWatershedOperators.h"

// STL
#ifdef _WINDOWS_SOURCE 
#include <array>
#include <functional>
#endif
#include <vector>

class CATIPolyMesh;
class CATTolerance;
class CATPolyMeshSteepestSlopeOperator;
struct CATPolyMeshWatershedCallback;

/*
1 - Instanciate operator 
2 - Call run method
3 - Get the result as a vector of polylines (see below)
*/

class ExportedByCATPolyMeshWatershedOperators CATPolyMeshRidgeValleyOperator
{
public:

  struct ElemEdge_t
  {
#ifdef _WINDOWS_SOURCE 
    std::array<int, 2> m_Vertices;
    std::array<int, 2> m_NeighborTriangles;
#else
    int m_Vertices[2];
    int m_NeighborTriangles[2];
#endif

    ElemEdge_t(int i1, int i2) { m_Vertices[0] = i1; m_Vertices[1] = i2; }
  };
  typedef std::vector<ElemEdge_t> Polyline_t;

  //------------------ creation of the operator
  static CATPolyMeshRidgeValleyOperator * CreateInstance(const CATIPolyMesh & iMesh, const CATTolerance & iTolObject);
  
  virtual ~CATPolyMeshRidgeValleyOperator() {}
  
  // Enable to use an existing instance of CATPolyMeshSteepestSlopeOperator
  virtual void SetSteepestSlopeOperator(CATPolyMeshSteepestSlopeOperator * iOpe) = 0;

  // Enable to know the current computation state 
  virtual void SetProgressCallback(CATPolyMeshWatershedCallback * iCB) = 0;

  virtual HRESULT Run() = 0;

#ifdef _WINDOWS_SOURCE 
  typedef std::function<bool(const ElemEdge_t &)> EdgeFilter_t;
#endif

  virtual HRESULT GetRidges(std::vector<Polyline_t> & oRidges
#ifdef _WINDOWS_SOURCE 
    , const EdgeFilter_t & = [](const ElemEdge_t) {return true; }
#endif
  ) const = 0;
  virtual HRESULT GetValley(std::vector<Polyline_t> & oValley
#ifdef _WINDOWS_SOURCE 
    , const EdgeFilter_t & = [](const ElemEdge_t) {return true; }
#endif
  ) const = 0;

#ifdef _WINDOWS_SOURCE 
  virtual bool IsOnRidge(const std::array<int, 2> & iEdge) const = 0;
  virtual bool IsOnValley(const std::array<int, 2> &iEdge) const = 0;
#endif
};
#endif // CATPolyMeshRidgeValleyOperator_H_

