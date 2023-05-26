// COPYRIGHT DASSAULT SYSTEMES 2020, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBooleanHeterogeneousOper2D.h
//
//===================================================================
// June 2020 Creation: te9
//===================================================================

#ifndef CATPolyBooleanHeterogeneousOper2D_H
#define CATPolyBooleanHeterogeneousOper2D_H

#ifndef _AIX_SOURCE
#include "CATPolyBooleanOper2DBase.h"

#include <vector>
#include <memory>

class CATPolyExactArithmetic;
class CATPolySpatialPartition2D;
class CATPolyBarIntersector2D;
class CATPolyPolygonOverlayOptions2D;
template<bool> class CATPolyBooleanNOperZ2Layer2D;
class CATPolyPolygonObserver2D;
template<class, class> class CATPolyElementMap;

/**
 Boolean operator for objects of types CATPolyPolygon2D.
 It can perform 3 kinds of operation :
 - Subtraction between one operand P (considered as closed) and another Q (considered as openned).
 - Intersection between between two closed operand P and Q.
 - Union between between two opened operands P and Q. The result is the border of the union.
 The results of the 3 operations can have heterogeneous elements : solid face, wires, isolated vertices 

 The input data must satisfy the following condition:
 The input operands (Operand 0 and Operand 1) must be closed.  A operand is closed when at each vertex the number of incoming
 edges is equal to the number of outgoing edges counting the edge multiplicities.  This is a purely combinatorial test that
 does not involve any geometry restrictions.  Edges can be intersecting and vertices don't need to be defined at the
 intersections.
*/

class ExportedByPolygonalBoolean CATPolyBooleanHeterogeneousOper2D final : private CATPolyBooleanOper2DBase
{
public:
  CATPolyBooleanHeterogeneousOper2D(const CATPolyPolygonOverlayOptions2D& iOptions);

  /*
   * Specify the number of polygons in operands 0 and 1
   * For AddOperand, AddVertex, AddBar operands 0 are indexed in [0, inOperand0[
   * and operands 1 are indexed in [inOperand0, inOperand0 + inOperand1[
   */
  CATPolyBooleanHeterogeneousOper2D(const CATPolyPolygonOverlayOptions2D& iOptions, int inOperand0, int inOperand1);

  using CATPolyBooleanOper2DBase::BooleanOperation;

  CATPolyBooleanHeterogeneousOper2D() = delete;
  CATPolyBooleanHeterogeneousOper2D(CATPolyBooleanHeterogeneousOper2D const&) = delete;
  CATPolyBooleanHeterogeneousOper2D& operator=(CATPolyBooleanHeterogeneousOper2D const&) = delete;
  ~CATPolyBooleanHeterogeneousOper2D();

  void Set(CATPolyPolygon2D& ioResult);

  void SetNbOperands(int inOperand0, int inOperand1);

  HRESULT AddVertex(const int iOperand, const CATMathPoint2D& iPoint, CATPolyVertex2D*& oVertex) override;
  HRESULT AddBar(const int iOperand, CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1, CATPolyBar2D*& oBar, const int iMultiplicity = 1) override;
  HRESULT AddBar(const int iOperand, CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1, const int iMultiplicity = 1);

  HRESULT AddOperand(const unsigned int iOperand, const CATPolyPolygon2D& polygon, const CATMathTransformation2D* posMatrix = nullptr,
    bool iPropagateVertexAttribute = false, bool iPropagateBarAttribute = false);
  
  CATPolyPolygon2D* GetPolygon() const;

  void SetOrientation(const int iOperand, const OrientationOperand iOrientation) override {}

  /**
   * Performs the boolean substraction.
   * @return
   *   The method returns S_OK when it runs successfully and E_FAIL otherwise.
   */
  HRESULT Run(BooleanOperation const iOperation);

public:
  template<bool IsRange>
  void InitializeBooleanLayer();

  template<bool IsRange>
  HRESULT Run();

  template<bool IsRange>
  HRESULT AddOperand(const unsigned int iOperand, const CATPolyPolygon2D& polygon, const CATMathTransformation2D* posMatrix,
    bool iPropagateVertexAttribute, bool iPropagateBarAttribute);

  template<bool IsRange>
  HRESULT ProcessOverlay();
 
  template<bool IsRange>
  CATPolyBooleanNOperZ2Layer2D<IsRange>* GetBooleanLayer() const;

  std::unique_ptr<CATPolyBooleanNOperZ2Layer2D<true>> _RangeBooleanLayer;
  std::unique_ptr<CATPolyBooleanNOperZ2Layer2D<false>> _IntegerBooleanLayer;

  int _nOperand0 = 1;
  int _nOperand1 = 1;

  std::unique_ptr<CATPolyElementMap<CATPolyVertex2D, CATPolyVertex2D*>> _mVertex;

  // Enable test infra to use not exposed methods KeepWires, ...
  friend class CATPolyBooleanOper2DODT;
};

inline HRESULT CATPolyBooleanHeterogeneousOper2D::AddBar(const int iOperand, CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1, const int iMultiplicity)
{
  return CATPolyBooleanOper2DBase::AddBar(iOperand, iVertex0, iVertex1, iMultiplicity);
}

inline CATPolyPolygon2D* CATPolyBooleanHeterogeneousOper2D::GetPolygon() const
{
  return _Polygon;
}

template<bool IsRange>
CATPolyBooleanNOperZ2Layer2D<IsRange>* CATPolyBooleanHeterogeneousOper2D::GetBooleanLayer() const
{
  if constexpr (IsRange)
  {
    return _RangeBooleanLayer.get();
  }
  else
  {
    return _IntegerBooleanLayer.get();
  }
}

#endif
#endif
