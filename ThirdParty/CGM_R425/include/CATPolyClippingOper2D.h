// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyClippingOper2D.h
//
//===================================================================
// October 2006 Creation: ndo
//===================================================================
#ifndef CATPolyClippingOper2D_H
#define CATPolyClippingOper2D_H

#include "PolygonalBoolean.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATBoolean.h"

class CATPolyExactArithmetic;
class CATPolySpatialPartition2D;
class CATPolyPolygon2D;


/**
Clipping Operator.
It clips a polygon by another (clipping operand).
*/
class ExportedByPolygonalBoolean CATPolyClippingOper2D
{

public :

  CATPolyClippingOper2D (const CATPolyExactArithmetic& iExactArithmetic,
                         const CATPolySpatialPartition2D* iSpatialPartition = 0);

  ~CATPolyClippingOper2D ();

public:

  /**
   * Sets a flag to keep full vertices during the clipping operation.
   * By default full (or free) vertices are removed during the clipping operation.
   */
  inline void KeepFullVertices (CATBoolean iDoKeep);

  /**
   * Clips a polygon instance by a clipping operand.
   * @param oResult
   *   The result polygon.  It must be deleted.
   */
  HRESULT Run (const CATPolyPolygon2D& iOperand, const CATPolyPolygon2D& iClippingOperand,
               CATPolyPolygon2D*& oResult);

  /**
   * Clips a polygon instance by a clipping operand.
   * @param oResult
   *   The result polygon.  It must be deleted.
   * @param oIsResultIdenticalToOperand
   *   An output boolean set to <tt>TRUE</tt> when the result is identical to the input operand.
   *   If the input polygon is completely contained in the clipping operand then the boolean is set to <tt>TRUE</tt>
   *   (unless the polygon has self-intersections.)
   */
  HRESULT Run (const CATPolyPolygon2D& iOperand, const CATPolyPolygon2D& iClippingOperand,
               CATPolyPolygon2D*& oResult, CATBoolean& oIsResultIdenticalToOperand);

private:

  const CATPolyExactArithmetic& _ExactArithmetic;
  const CATPolySpatialPartition2D* _SpatialPartition;

  const CATPolyPolygon2D* _Polygon[2];  // Input and clipping polygons.
  CATPolyPolygon2D* _Result;            // Result.

  CATBoolean _KeepFullVertices;
  CATBoolean _IsInOtherPolygon[2];

private:

  void Clear ();

public:

  // DEPRECATED.
  enum ResultStatus
  {
    eResultAsFirstOperand = 1,
    eResultAsSecondOperand = 2,
    eResultDifferentFromOperands
  };

  // DEPRECATED.
  CATBoolean IsPolygonInOtherPolygon (const CATPolyPolygon2D* iPolygon) const;

  // DEPRECATED.
  HRESULT SetPolygons (const CATPolyPolygon2D* iPolygon0, const CATPolyPolygon2D* iPolygon1);

  // DEPRECATED.
  HRESULT Run ();

  // DEPRECATED.
  CATPolyPolygon2D* GetResult (ResultStatus* oResultStatus = 0);

};

inline void CATPolyClippingOper2D::KeepFullVertices (CATBoolean iDoKeep)
{
  _KeepFullVertices = iDoKeep;
}

#endif
