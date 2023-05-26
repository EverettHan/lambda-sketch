// COPYRIGHT DASSAULT SYSTEMES 2016, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBooleanStepOper2D.h
//
//===================================================================
// March 2016 Creation: ndo
//===================================================================
#ifndef CATPolyBooleanStepOper2D_H
#define CATPolyBooleanStepOper2D_H

#include "PolygonalBoolean.h"
#include "CATPolyPolygonOverlayOptions2D.h"
#include "CATPolyPolygonBarSplitter2D.h"
#include "CATPolyBooleanOper2D.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATBoolean.h"
#include "CATSetOfPtr.h"
#include "CATSetOfInt.h"
#include "CATListPV.h"

class CATPolyExactArithmetic;
class CATPolySpatialPartition2D;
class CATPolyBarIntersector2D;
class CATPolyPolygon2D;
class CATPolyBooleanOperLayer2D;
class CATPolyBooleanOperPolygonObserver2D;
class CATPolyPolygonSplitBarsObserver2D;
class CATPolyBitSet;

class CATPolyFace2D;
class CATPolyBar2D;
class CATPolyVertex2D;
class CATPolyCoBar2D;

class CATMathPoint2D;
class CATMathTransformation2D;


/**
 Boolean operator for objects of types CATPolyPolygon2D.
 It can perform, the union, intersection or subtraction between two operands (binary operator).

 It can also work in a unary mode to process a complex polygon with intersection points between edges not necessarily 
 defined as input vertices.  The boolean result is then computed according to the winding number.
 
 The input data must satisfy the following condition:
 The input operands (Operand 0 and Operand 1) must be closed.  A operand is closed when at each vertex the number of incoming 
 edges is equal to the number of outgoing edges counting the edge multiplicities.  This is a purely combinatorial test that
 does not involve any geometry restrictions.  Edges can be intersecting and vertices don't need to be defined at the 
 intersections.
*/
class ExportedByPolygonalBoolean CATPolyBooleanStepOper2D
{

public:

  /**
   * Constructs a boolean pixel-operator from an instance of exact arithmetic and a spatial partition.
   * There are two optional arguments: a spatial partition and a bar intersector.
   * The bar intersector enables custom handling of intersecting bars and custom computation of 
   * the intersection points.
   * @param polygon
   *   The polygon that will be constructed with the result of the Boolean operations.
   *   This polygon is edited by this operator.
   *   The polygon represents the first operand (Operand 0) in the Boolean operation.
   * @param iObserver
   *   An optional observer for the notification of the split-bar events.
   */
  CATPolyBooleanStepOper2D (const CATPolyExactArithmetic& iExactArithmetic,
                             const CATPolySpatialPartition2D& iSpatialPartition,
                             CATPolyPolygon2D& polygon,
                             CATPolyBarIntersector2D* iBarIntersector = 0,
                             CATPolyPolygonSplitBarsObserver2D* iObserver = 0);

  CATPolyBooleanStepOper2D (const CATPolyPolygonOverlayOptions2D& iOptions);
                            
  ~CATPolyBooleanStepOper2D ();

public:

  /**
   * Adds a vertex from the second Operand to the operator.
   * The coordinates of the vertex should be gridded by the instance of exact arithmetic.
   */
  HRESULT AddVertex (const CATMathPoint2D& iPoint, CATPolyVertex2D*& oVertex);

  /**
   * Adds a bar defined by two vertices.
   * @param iMultiplicity
   *   The multiplicity of the bar oriented from iVertex0 to iVertex1.
   */
  HRESULT AddBar (CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1,
                  CATPolyBar2D*& oBar, const int iMultiplicity = 1);

  HRESULT AddOperand (const CATPolyPolygon2D& polygon, const CATMathTransformation2D* posMatrix = 0);

public:

  /**
   * Boolean operation to compute.
   */
  enum BooleanOperation
  {
    /** Do not perform any boolean operation but just construct a valid polygon
        with all intersections between bars and vertices resolved. */                eBooleanNone = CATPolyBooleanOper2D::eBooleanNone,
    /** Do the union of the two operands. */                                         eBooleanUnion = CATPolyBooleanOper2D::eBooleanUnion,
    /** Do the intersection of the two operands. */                                  eBooleanIntersection = CATPolyBooleanOper2D::eBooleanIntersection,
    /** Do the subtraction of Operand 1 from Operand 0. */                           eBooleanSubtraction = CATPolyBooleanOper2D::eBooleanSubtraction
  };

  /** 
   * Performs the boolean operation after addition of vertices and bars to the Operand 1 (if any.)
   * This method may be called several times (iteratively.)
   * @param iOperation
   *   The boolean operation to compute.
   * @return
   *   The method returns S_OK when it runs successfully and E_FAIL otherwise.
   */
  HRESULT Run (const BooleanOperation iOperation);

  /**
   * Returns the polygon result after a successful run of the method Run ().
   * This method must be called after a successful run of the operation to get a fully constructed polygon.
   */
  const CATPolyPolygon2D* GetResult ();

private:

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

private:

  CATPolyPolygonOverlayOptions2D _Options;

  CATPolyPolygon2D& _Polygon;
  CATPolyBooleanOperLayer2D* _BooleanLayer;
  CATPolyBooleanOperPolygonObserver2D* _PolygonObserver;
  //CATPolyPolygonBarSplitter2D::Observer* _PixelObserver;
  //unsigned char* _PixelWN;

  CATPolyPolygonBarSplitter2D _Splitter;
  CATSetOfPtr _Bars;      // Set of visited bars.
  CATSetOfPtr _Vertices;  // Set of visited vertices.
  //CATSetOfInt _Pixels;    // Set of visited pixels.

  unsigned int _VertexCount;
  int _Operation;
  int _OverlayStatus;
  int _OperandOrientation[2];  // Orientation of the two operands.

  enum 
  {
    eOverlayKO,
    eOverlayFlushFaces,
    eOverlayToDo,
    eOverlayOK
  };

private:

  void FlushFaces ();
  void Initialize ();

  CATPolyBar2D* GetBarBelow (CATPolyVertex2D& V) const;

  HRESULT LinkBars ();
  HRESULT LinkBarsAroundVertex (CATPolyVertex2D& V, CATListPV& barsWS);

  HRESULT PropagateWindingNumbers ();
  HRESULT PropagateWindingNumbers (CATPolyVertex2D& V, CATPolyBar2D* barBelow, CATPolyBitSet& vertexFlags);
  HRESULT PropagateAroundVertex (CATPolyBar2D& B, CATPolyVertex2D& V, CATSetOfPtr& stackBars);

  // Remove bars that do not belong to the result.
  void ProcessBars ();
  void ProcessBarUnion (CATPolyBar2D& B);
  void ProcessBarIntersection (CATPolyBar2D& B);
  void ProcessBarSubtraction (CATPolyBar2D& B);

private:

  HRESULT AddNewLoop (CATPolyFace2D& outerFace, CATPolyCoBar2D* cobar);
  HRESULT GetFace (CATPolyFace2D& outerFace, CATPolyCoBar2D* cobar, CATPolyFace2D*& oFace);

};

#endif
