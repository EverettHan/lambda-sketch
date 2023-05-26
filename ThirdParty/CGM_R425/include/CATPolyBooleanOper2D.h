// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBooleanOper2D.h
//
//===================================================================
// June 2007 Creation: ndo
// April 2016 Modification JXO: Now derives from CATPolyBooleanOper2DBase
// 30.11.2016 : RAQ : Implémentation différence symétrique + callback de classification des faces résultat
//===================================================================
#ifndef CATPolyBooleanOper2D_H
#define CATPolyBooleanOper2D_H

#include "PolygonalBoolean.h"
#include "CATPolyBooleanOper2DBase.h"
#include "CATPolyPolygonOverlay2D.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATBoolean.h"
#include "CATPolyDeprecatedM.h"

class CATPolyExactArithmetic;
class CATPolySpatialPartition2D;
class CATPolyBarIntersector2D;
class CATPolyPolygon2D;
class CATPolyBooleanOperLayer2D;
class CATPolyPolygonBarSplitter2D;
class CATPolyPolygonSplitBarsObserver2D;
class CATPolyBooleanOperPolygonObserver2D;

class CATPolyFace2D;
class CATPolyBar2D;
class CATPolyVertex2D;

class CATMathPoint2D;
class CATMathTransformation2D;

class CATPolyPolygonOverlayOptions2D;

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
class ExportedByPolygonalBoolean CATPolyBooleanOper2D : public CATPolyBooleanOper2DBase
{

public:

  /**
   * Constructs a boolean operator from an instance of exact arithmetic.
   * There are two optional arguments: a spatial partition and a bar intersector.
   * The bar intersector enables custom handling of intersecting bars and custom computation of
   * the intersection points.
   */
  CATPolyBooleanOper2D (const CATPolyExactArithmetic& iExactArithmetic,
                        const CATPolySpatialPartition2D* iSpatialPartition = 0,
                        CATPolyBarIntersector2D* iBarIntersector = 0);

  CATPolyBooleanOper2D (const CATPolyPolygonOverlayOptions2D & iOptions);

  ~CATPolyBooleanOper2D ();

  /**
   * Sets a flag to keep full vertices during the boolean operation.
   * By default full (or free) vertices are removed.
   */
  inline void KeepFullVertices (CATBoolean iDoKeep);

  /**
   * Sets a flag to keep wires during the boolean operation.
   * By default full (or free) wires are removed during the boolean operation.
   */
  inline void KeepWires (CATBoolean iDoKeep);

public:

  /**
   * Sets the working polygon for the operator.
   * This polygon is edited by the operator.
   *
   * By default this polygon is associated to Operand 0 (the first operand); it can also be associated to both operands
   * by setting the optional argument to <tt>TRUE</tt>.
   *
   * The polygon may be empty.  The operand data (vertex and bars) are added by calling directly the add methods from this
   * operator.
   *
   * A polygon must be set before adding any vertex and bar as operand data.

   * @param ioResult
   *   A polygon edited by the operator representing Operand 0 and at the end of a run, the result of the boolean operation.
   *   It may also contain data.
   * @param iJointOperand
   *   A flag set to <tt>TRUE</tt> if the input polygon data belong jointly to Operands 0 and 1.
   *   By default, the polygon data belong to Operand 0.
   * @param iObserver
   *   An optional observer for the notification of the split-bar events.
   */
  void Set (CATPolyPolygon2D& ioResult, CATBoolean iJointOperand = FALSE, CATPolyPolygonSplitBarsObserver2D* iObserver = 0);

  /**
   * Returns the result polygon. This is the polygon initially set into this operator.
   */
  CATPolyPolygon2D* GetPolygon () const;

public:

 /**
  * Adds a polygon as an operand to the operator.
  * The coordinates of the vertices from the polygon will be gridded as required for the computation with exact arithmetic.
  * @param posMatrix
  *   An optional position matrix.
  */
  HRESULT AddOperand(const unsigned int iOperand, const CATPolyPolygon2D& polygon, const CATMathTransformation2D* posMatrix = 0,
    bool iPropagateVertexAttribute = false, bool iPropagateBarAttribute = false, ObserverAddOperand* obs = 0);

  /**
   * Adds a vertex to the first operand (Operand 0) or to the second (Operand 1).
   * The coordinates of the vertex should be gridded by the instance of exact arithmetic if applicable.
   * A CATPolyPolygon2D instance must be provided to the operator prior to adding new data (see Set method).
   */
  HRESULT AddVertex (const int iOperand, const CATMathPoint2D& iPoint, CATPolyVertex2D* &oVertex);

  /**
   * Adds a bar defined by two vertices from one operand (Operand 0 or 1).
   * Set the multiplicity of the bar to 0, if the bar belongs to a wire.
   */
  HRESULT AddBar (const int iOperand, CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1,
                  CATPolyBar2D* &oBar, const int iMultiplicity = 1);

  /**
    * Adds a new arc between two vertices passing (or not) through point.
   */
  HRESULT AddBar(const int iOperand, CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1, CATMathPoint2D const& iPoint, bool iThroughPoint,
    CATPolyBar2D*& oBar, const int iMultiplicity = 1);

  /**
   * Adds a bar defined by two vertices from one operand (Operand 0 or 1).
   * Set the multiplicity of the bar to 0, if the bar belongs to a wire.
   * @param iOperand
   *   0 for the first operand and 1 for the second operand.
   * @param iVertex0
   *   The first vertex defining the bar.
   * @param iVertex1
   *   The second vertex defining the bar.
   * @param iMultiplicity
   *   The multiplicity of the bar.
   */
  HRESULT AddBar(const int iOperand, CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1,
    const int iMultiplicity = 1)
  {
    return CATPolyBooleanOper2DBase::AddBar(iOperand, iVertex0, iVertex1, iMultiplicity);
  }

public:

  /**
   * After adding all the vertices and bars to the operands, preprocess the data to determine
   * if the operands are oriented in the CCW or CW direction.
   * Orientations are equal to the above enums.
   */
  HRESULT Preprocess (int& oOrientation0, int& oOrientation1);

  /**
   * Sets the orientation of the operands.
   * By default, the operands are assumed oriented in the CCW direction.
   */
  void SetOrientation (const int iOperand, const OrientationOperand iOrientation);

public:

  /**
   * Observer to catch events during the boolean process.
   */
  class Observer
  {
  public:

    Observer() {}
    virtual ~Observer() {}

   /**
    * Callback to report the classification of a result non-hole face wrt the operands.
    * iIsInOperand0 is TRUE if the face is classified inside operand 0, the same for iIsInOperand1 and operand 1
    **/
    virtual void ReportFaceClassification(CATPolyFace2D* ipFace, const CATBoolean iIsInOperand0, const CATBoolean iIsInOperand1) {}
  };

  /**
   * Performs the boolean operation.
   * @param iOperation
   *   The boolean operation to compute.
   * @return
   *   The method returns S_OK when it runs successfully and E_FAIL otherwise.
   */
  HRESULT Run (const CATPolyBooleanOper2DBase::BooleanOperation iOperation, Observer* ipObserver = 0);

public:

  /**
   * Returns the winding number associated to a face for a given operand.
   * The operator should be run prior to a call to this method.
   * @param iOperand
   *   The index of the operand: 0 or 1.
   * @param face
   *   A face of the CATPolyPolygon2D.
   * @param oWindingNumber
   *   The output winding number w.r.t. an operand for the given face.
   * @return
   *   <ul>
   *     <li> <tt>S_OK</tt> A valid winding number is returned.
   *     <li> <tt>S_FALSE</tt> The winding number is not set for this face.
   *   </ul>
   */
  HRESULT GetWindingNumber (const int iOperand, const CATPolyFace2D* face, int& oWindingNumber) const;

  /**
   * Returns "TRUE" if the bar of the result is from an operand and FALSE otherwise.
   */
  int IsBarFromOperand (const CATPolyBar2D* bar, const int iOperand) const;

  /**
   * Only merge vertices and bars, do not compute intersections.
   */
  HRESULT RunMerge();

protected:
  CATPolyBooleanOperLayer2D* _BooleanLayer;
  CATPolyPolygonSplitBarsObserver2D* _SplitObserver;
  int _OperandOrientation[2];  // Orientation of the two operands.
  CATBoolean _KeepFullVertices;
  CATBoolean _KeepWires;

protected:
    CATPolyBooleanOperPolygonObserver2D* RegisterObserver();
    void UnregisterObserver(CATPolyBooleanOperPolygonObserver2D* obs);

private:
  class ProcessOverlayRule;

  void Clear ();

  HRESULT ProcessOverlay(Observer* ipObserver);

  // Replace facets that do not belong to the result by hole faces.
  void ProcessFaces(ProcessOverlayRule &iRule);

  // Remove bars that do not belong to the result.
  void ProcessBars(ProcessOverlayRule &iRule);

  // Remove vertices that do not belong to the result.
  HRESULT ProcessVertices(ProcessOverlayRule &iRule);

  // Replace facets that do not belong to the result by hole faces.
  void ProcessFace(CATPolyFace2D& face, ProcessOverlayRule& iRule, Observer* ipObserver);

  HRESULT ProcessVertex(CATPolyVertex2D& vertex, ProcessOverlayRule& iRule);

public:

  /**
   * @deprecated
   */
  POLY_DEPRECATED ("Replace by call to Set (CATPolyPolygon2D&)",
  inline void Set (CATPolyPolygon2D* ioResult););

  /**
   * @deprecated
   */
  POLY_DEPRECATED ("Replace by call to Set (CATPolyPolygon2D&, CATBoolean, CATPolyPolygonSplitBarsObserver2D*)",
  inline void SetObserver (CATPolyPolygonSplitBarsObserver2D* iObserver););

};


inline void CATPolyBooleanOper2D::KeepFullVertices (CATBoolean iDoKeep)
{
  _KeepFullVertices = iDoKeep;
  _OverlayOper.KeepFullVertices (iDoKeep ? true : false);
}

inline void CATPolyBooleanOper2D::KeepWires (CATBoolean iDoKeep)
{
  _KeepWires = iDoKeep;
}

inline void CATPolyBooleanOper2D::Set (CATPolyPolygon2D* ioResult)
{
  if (ioResult)
    Set (*ioResult);
}

inline void CATPolyBooleanOper2D::SetObserver (CATPolyPolygonSplitBarsObserver2D* iObserver)
{
  _SplitObserver = iObserver;
}

#endif
