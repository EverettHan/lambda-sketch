// COPYRIGHT DASSAULT SYSTEMES 2016, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBooleanOper2DBase.h
//
//===================================================================
// April 2016 Creation: JXO
//===================================================================
#ifndef CATPolyBooleanOper2DBase_H
#define CATPolyBooleanOper2DBase_H

#include "PolygonalBoolean.h"
#include "CATPolyPolygonOverlay2D.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATBoolean.h"
#include "CATPolyPolygonOverlayOptions2D.h"
#include "CATPolyPolygonOverlay2D.h"

#ifndef _AIX_SOURCE
#include <memory>
#endif // !_AIX_SOURCE

class CATPolyExactArithmetic;
class CATPolySpatialPartition2D;
class CATPolyBarIntersector2D;
class CATPolyPolygon2D;
class CATPolyPolygonBarSplitter2D;
class CATMathTransformation2D;
class CATPolyBentleyOttmann;
class CATPolyBooleanOperLayerInterface2D;

/**
 Base class for Boolean operators
*/
class ExportedByPolygonalBoolean CATPolyBooleanOper2DBase
{
public:

  CATPolyBooleanOper2DBase (const CATPolyPolygonOverlayOptions2D& iOptions);

  ~CATPolyBooleanOper2DBase ();

public:

  /**
   * Orientation of the operands.
   */
  enum OrientationOperand
  {
    /** Operand has conflicting orientations (loops in both CW and CCW direction). */ eOrientationUnresolved   = -2,
    /** Operand is oriented in the CW direction. */                                   eOrientationCW           = -1,
    /** Operand has no orientation (wire). */                                         eOrientationNone         =  0,
    /** Operand is oriented in the CCW direction. */                                  eOrientationCCW          = +1
  };

  /**
   * Boolean operation to compute.
   */
  enum BooleanOperation
  {
    /** Do not perform any boolean operation but just construct a valid polygon
        with all intersections between bars and vertices resolved. */                eBooleanNone = 0,
    /** Extract all the vertices and bars of Operand 1 that are in Operand 0. */     eBooleanOperand1InOperand0,
    /** Extract all the vertices and bars of Operand 0 that are in Operand 1. */     eBooleanOperand0InOperand1,
    /** Compute the union of the two operands. */                                    eBooleanUnion,
    /** Compute the intersection of the two operands. */                             eBooleanIntersection,
    /** Subtract Operand 1 from Operand 0. */                                        eBooleanSubstraction,
                                                                                     eBooleanSubtraction = eBooleanSubstraction,
    /** Compute the symmetric difference between the two operands (TO DO.) */        eBooleanSymmetricDifference
  };

  /**
   * Adds a vertex to any operand.
   * The coordinates of the vertex should be gridded by the instance of exact arithmetic if applicable.
   * A CATPolyPolygon2D instance must be provided to the operator prior to adding new data (see Set method).
   */
  virtual HRESULT AddVertex (const int iOperand, const CATMathPoint2D& iPoint, CATPolyVertex2D* &oVertex) = 0;

  /**
   * Adds a bar defined by two vertices from one operand.
   * Set the multiplicity of the bar to 0, if the bar belongs to a wire.
   */
  virtual HRESULT AddBar (const int iOperand, CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1,
                          CATPolyBar2D* &oBar, const int iMultiplicity = 1) = 0;

  /**
   * Adds a bar defined by two vertices from one operand.
   * Set the multiplicity of the bar to 0, if the bar belongs to a wire.
   * @param iOperand
   *   n >= 0
   * @param iVertex0
   *   The first vertex defining the bar.
   * @param iVertex1
   *   The second vertex defining the bar.
   * @param iMultiplicity
   *   The multiplicity of the bar.
   */
  HRESULT AddBar (const int iOperand, CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1,
                          const int iMultiplicity = 1);


  /**
   * observer that allow for example to create a mapping between original operand and new vertex
   * */
  class ObserverAddOperand
  {
    public:
    virtual void AfterAddVertex(const CATPolyVertex2D & iOriginal,const CATPolyVertex2D & iNew ){};
    virtual void AfterAddBar(const CATPolyBar2D & iOriginal,const CATPolyBar2D & iNew ){};
  };

  /**
   * Sets the orientation of the operands.
   * By default, the operands are assumed oriented in the CCW direction.
   */
  virtual void SetOrientation (const int iOperand, const OrientationOperand iOrientation) = 0;

protected:
  HRESULT Set(CATPolyBooleanOperLayerInterface2D& ioBooleanLayer, CATBoolean iJointOperand);

  HRESULT AddOperand(const unsigned int iOperand, const CATPolyPolygon2D& polygon, const CATMathTransformation2D* posMatrix = 0,
    bool iPropagateVertexAttribute = false, bool iPropagateBarAttribute = false, ObserverAddOperand* obs = NULL);

  HRESULT AddBar(CATPolyBooleanOperLayerInterface2D& ioBooleanLayer, const int iOperand,
    CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1,
    CATPolyBar2D*& oBar, const int iMultiplicity);

  HRESULT AddBar(CATPolyBooleanOperLayerInterface2D& ioBooleanLayer, const int iOperand,
    CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1, CATMathPoint2D const& iPoint, bool iThroughPoint,
    CATPolyBar2D*& oBar, const int iMultiplicity);

  HRESULT AddVertex(CATPolyBooleanOperLayerInterface2D* ipBooleanLayer, const int iOperand,
    const CATMathPoint2D& iPoint, bool iKeepFullVertex, CATPolyVertex2D*& oVertex);

  HRESULT ComputeOverlay(CATPolyPolygonOverlayObserver2D& iOverlayObserver);

  // Set all faces as hole faces.
  HRESULT ProcessFacesOnFailure();

  void Clear ();

  CATPolyPolygonOverlayOptions2D _Options;
  int _Operation;
  CATPolyPolygon2D* _Polygon;
  CATPolyPolygonBarSplitter2D* _Splitter;
  CATPolyPolygonOverlay2D _OverlayOper;
#ifndef _AIX_SOURCE
  std::unique_ptr<CATPolyBentleyOttmann> _pBentleyOttmann;
#endif // !_AIX_SOURCE


  enum
  {
    eOverlayKO,
    eOverlayToDo,
    eOverlayOK,
    eOverlayOKPropagationFailed
  };

  int _OverlayStatus;

};

#endif
