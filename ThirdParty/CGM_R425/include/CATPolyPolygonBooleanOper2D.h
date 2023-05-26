// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonBooleanOper2D.h
// Header definition of CATPolyPolygonBooleanOper2D
//
//===================================================================
// March 2008 Creation: ndo
//===================================================================
#ifndef CATPolyPolygonBooleanOper2D_H
#define CATPolyPolygonBooleanOper2D_H

#include "PolygonalBoolean.h"
#include "CATPolyBooleanOper2D.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.

class CATPolyExactArithmetic;
class CATPolySpatialPartition2D;
class CATPolyPolygon2D;


/**
 Boolean operator for objects of types CATPolyPolygon2D.
 It performs the union, intersection or subtraction between two operands.
 The result is returned in a new CATPolyPolygon2D instance.
*/
class ExportedByPolygonalBoolean CATPolyPolygonBooleanOper2D
{

public:

  CATPolyPolygonBooleanOper2D (const CATPolyExactArithmetic& iExactArithmetic,
                               const CATPolySpatialPartition2D* iSpatialPartition = 0);

  ~CATPolyPolygonBooleanOper2D ();

public:

  /**
   * Enumerator that specifies the binary operation.
   */
  enum BooleanOperation
  {
    /** Extract the part of Operand 1 in Operand 0
        (preserves all operands loops) */                       eBooleanOperand1InOperand0 = CATPolyBooleanOper2D::eBooleanOperand1InOperand0,
    /** Extract the part of Operand 0 in Operand 1
        (preserves all operands loops) */                       eBooleanOperand0InOperand1 = CATPolyBooleanOper2D::eBooleanOperand0InOperand1,
    /** Do the union of the two operands. */                    eBooleanUnion = CATPolyBooleanOper2D::eBooleanUnion,
    /** Do the intersection of the two operands. */             eBooleanIntersection = CATPolyBooleanOper2D::eBooleanIntersection,
    /** Do the subtraction of Operand 1 from Operand 0. */      eBooleanSubtraction = CATPolyBooleanOper2D::eBooleanSubtraction,
  };

  /**
   * Sets a flag to keep full vertices during the boolean operation.
   * By default full (or free) vertices are removed during the boolean operation.
   */
  inline void KeepFullVertices (CATBoolean iDoKeep);

  /**
   * Sets a flag to keep wires during the boolean operation.
   * By default full (or free) wires are removed during the boolean operation.
   */
  inline void KeepWires (CATBoolean iDoKeep);

  /**
   * Runs a boolean operation between the two operands.  Upon successful completion of the
   * operation, it creates a new instance of a CATPolyPolygon2D representing the boolean result.
   * This instance must be deleted.
   */
  HRESULT Run (const CATPolyPolygon2D& iOperand0, const CATPolyPolygon2D& iOperand1,
               const BooleanOperation iOperation,
               CATPolyPolygon2D*& oResult);

  /**
   * Returns <tt>TRUE</tt> if the result is a equivalent to Operand <tt>iOperand</tt>.
   */
  inline CATBoolean IsResultEquivalentToOperand (const int iOperand);

private:

  const CATPolyExactArithmetic& _ExactArithmetic;
  const CATPolySpatialPartition2D* _SpatialPartition;

  CATBoolean _KeepFullVertices;
  CATBoolean _KeepWires;

  // Flag set to "1" if the result is equivalent to operand 0 and 1 respectively.
  CATBoolean _ResultIsEquivalentToOperand[2];

};


inline void CATPolyPolygonBooleanOper2D::KeepFullVertices (CATBoolean iDoKeep)
{
  _KeepFullVertices = iDoKeep;
}

inline void CATPolyPolygonBooleanOper2D::KeepWires (CATBoolean iDoKeep)
{
  _KeepWires = iDoKeep;
}

inline CATBoolean CATPolyPolygonBooleanOper2D::IsResultEquivalentToOperand (const int iOperand)
{
  switch (iOperand)
  {
    case 0: return _ResultIsEquivalentToOperand[0];
    case 1: return _ResultIsEquivalentToOperand[1];
  }
  return FALSE;
}

#endif
