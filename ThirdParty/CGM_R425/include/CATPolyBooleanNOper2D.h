// COPYRIGHT DASSAULT SYSTEMES 2016, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBooleanNOper2D.h
//
//===================================================================
// April 2016 Creation: JXO
// September 2021 : JXO : added a constructor with options
//===================================================================
#ifndef CATPolyBooleanNOper2D_H
#define CATPolyBooleanNOper2D_H
#include "CATIAV5Level.h"
#if (defined(_WINDOWS_SOURCE) || (defined(CATIAR419) && defined(_LINUX_SOURCE)))

#include "CATPolyBooleanOper2DBase.h"
#include "PolygonalBoolean.h"
#include "CATPolyPolygonOverlay2D.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATBoolean.h"

class CATPolyExactArithmetic;
class CATMathTransformation2D;
class CATPolySpatialPartition2D;
class CATPolyBarIntersector2D;
class CATPolyPolygon2D;
class CATPolyBooleanNOperLayer2D;
class CATPolyPolygonBarSplitter2D;
class CATPolyPolygonSplitBarsObserver2D;

class CATPolyFace2D;
class CATPolyBar2D;
class CATPolyVertex2D;

class CATMathPoint2D;

class CATPolyPolygonOverlayOptions2D;

#include <unordered_map>

/**
 Boolean operator for N objects of types CATPolyPolygon2D.
 Currently it can only perform the union of N operands.

 The input data must satisfy the following condition:
 The input operands must be closed.  A operand is closed when at each vertex the number of incoming
 edges is equal to the number of outgoing edges counting the edge multiplicities.  This is a purely combinatorial test that
 does not involve any geometry restrictions.  Edges can be intersecting and vertices don't need to be defined at the
 intersections.
*/

class ExportedByPolygonalBoolean CATPolyBooleanNOper2D : public CATPolyBooleanOper2DBase
{

public:

  /**
   * Constructs a boolean operator from an instance of exact arithmetic.
   * There are two optional arguments: a spatial partition and a bar intersector.
   * The bar intersector enables custom handling of intersecting bars and custom computation of
   * the intersection points.
   */
  CATPolyBooleanNOper2D(const CATPolyExactArithmetic& iExactArithmetic,
    const CATPolySpatialPartition2D* iSpatialPartition = 0,
    CATPolyBarIntersector2D* iBarIntersector = 0);
  /**
   * Constructs a tolerant boolean operator
   */
  CATPolyBooleanNOper2D(CATPolyPolygonOverlayOptions2D & iOptions);

  ~CATPolyBooleanNOper2D ();

  /**
   * Sets a flag to keep full vertices during the boolean operation.
   * By default full (or free) vertices are removed.
   */
  inline void KeepFullVertices (CATBoolean iDoKeep);

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
   * @param iObserver
   *   An optional observer for the notification of the split-bar events.
   */
  void Set (CATPolyPolygon2D& ioResult, CATPolyPolygonSplitBarsObserver2D* iObserver = 0);

  /**
   * Returns the result polygon. This is the polygon initially set into this operator.
   */
  CATPolyPolygon2D* GetPolygon () const;

public:
  using CATPolyBooleanOper2DBase::AddOperand;

  /**
   * Adds a vertex to any operand.
   * The coordinates of the vertex should be gridded by the instance of exact arithmetic if applicable.
   * A CATPolyPolygon2D instance must be provided to the operator prior to adding new data (see Set method).
   */
  HRESULT AddVertex (const int iOperand, const CATMathPoint2D& iPoint, CATPolyVertex2D* &oVertex);

  /**
   * Adds a bar defined by two vertices from one operand.
   * Set the multiplicity of the bar to 0, if the bar belongs to a wire.
   */
  HRESULT AddBar (const int iOperand, CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1,
                  CATPolyBar2D* &oBar, const int iMultiplicity = 1);

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

public:

  /**
   * Sets the orientation of the operands.
   * By default, the operands are assumed oriented in the CCW direction.
   */
  void SetOrientation (const int iOperand, const OrientationOperand iOrientation);

public:

  /**
   * Performs the boolean operation.
   * @param iOperation
   *   The boolean operation to compute. Currently only union is supported.
   * @return
   *   The method returns S_OK when it runs successfully and E_FAIL otherwise.
   */
  HRESULT Run (const BooleanOperation iOperation);


private:
  CATPolyBooleanNOperLayer2D* _BooleanLayer;

  std::unordered_map<int, int> _OperandOrientation;  // Orientation of the operands.
  
  CATBoolean _KeepFullVertices;

private:

  void Clear ();

  HRESULT ProcessOverlay ();

  // Set all faces as hole faces.
  void ProcessFacesOnFailure ();

  // Replace facets that do not belong to the result by hole faces.
  void ProcessFaces ();

  // Remove bars that do not belong to the result.
  void ProcessBars ();

  // Remove vertices that do not belong to the result.
  void ProcessVertices ();
};

inline void CATPolyBooleanNOper2D::KeepFullVertices (CATBoolean iDoKeep)
{
  _KeepFullVertices = iDoKeep;
  _OverlayOper.KeepFullVertices (iDoKeep ? true : false);
}

#endif
#endif
