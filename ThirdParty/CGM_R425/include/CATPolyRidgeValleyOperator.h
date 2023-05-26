#ifndef CATPolyRidgeValleyOperator_H_
#define CATPolyRidgeValleyOperator_H_
//===================================================================
// COPYRIGHT Dassault Systemes 2017
//===================================================================
// CATPolyRidgeValleyOperator.h
// Header definition of class CATPolyRidgeValleyOperator
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
#include "ExportedByCATPolyWatershedOperators.h"

// STL
 
#include <array>
#include <functional>

#include <vector>

class CATIPolyMesh;
class CATTolerance;
class CATPolySteepestSlopeOperator;
struct CATPolyWatershedCallback;

/*
1 - Instanciate operator 
2 - Call run method
3 - Get the result as a vector of polylines (see below)
*/

class ExportedByCATPolyWatershedOperators CATPolyRidgeValleyOperator
{
public:

  struct ElemEdge_t
  {
 
    std::array<int, 2> m_Vertices;
    std::array<int, 2> m_NeighborTriangles;

    ElemEdge_t(int i1, int i2) { m_Vertices[0] = i1; m_Vertices[1] = i2; }
  };
  typedef std::vector<ElemEdge_t> Polyline_t;

  //------------------ creation of the operator
  static CATPolyRidgeValleyOperator * CreateInstance(const CATIPolyMesh & iMesh, const CATTolerance & iTolObject);
  
  virtual ~CATPolyRidgeValleyOperator() {}
  
  // Enable to use an existing instance of CATPolySteepestSlopeOperator
  virtual void SetSteepestSlopeOperator(CATPolySteepestSlopeOperator * iOpe) = 0;

  // Enable to know the current computation state 
  virtual void SetProgressCallback(CATPolyWatershedCallback * iCB) = 0;

  virtual HRESULT Run() = 0;

 
  typedef std::function<bool(const ElemEdge_t &)> EdgeFilter_t;


  virtual HRESULT GetRidges(std::vector<Polyline_t> & oRidges
    , const EdgeFilter_t & = [](const ElemEdge_t) {return true; }
  ) const = 0;

  virtual HRESULT GetValley(std::vector<Polyline_t> & oValley
    , const EdgeFilter_t & = [](const ElemEdge_t) {return true; }
  ) const = 0;

 
  virtual bool IsOnRidge(const std::array<int, 2> & iEdge) const = 0;
  virtual bool IsOnValley(const std::array<int, 2> &iEdge) const = 0;

  // helper functions for progress bar display
 
  virtual size_t GetNbRidges() const = 0;
  virtual size_t GetNbValleys() const = 0;

};
#endif // CATPolyRidgeValleyOperator_H_

