// COPYRIGHT DASSAULT SYSTEMES 2019, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuBoolean.h
//
//===================================================================
// November 2019 - Creation NDO
//===================================================================
#ifndef CATPolyVisuBoolean_H
#define CATPolyVisuBoolean_H

#include "PolyVisuBoolOper.h"
#include "CATErrorDef.h" // Definition of HRESULT
#include "CATPolyBoolean.h"

class CATPolyBodyBooleanOptions;
class CAT3DRep;
class CAT4x4Matrix;
class CATPolyBody;
class CATMathTransformation;


/*
 * Boolean operator calculating the union, intersection or subtraction between
 * two solid reps of type: CAT3DRep.
 */
class ExportedByPolyVisuBoolOper CATPolyVisuBoolean
{

public :

  /**
   * Constructor of the boolean operator.
   * @param iOptions
   *   @see CATPolyBodyBooleanOptions
   */
  CATPolyVisuBoolean (const CATPolyBodyBooleanOptions* iOptions = 0);

  ~CATPolyVisuBoolean ();

public:

  /**
   * Computes a boolean operation between two operands.
   * @param iRep0
   *   The rep to parse for extraction of the first operands.  
   *   For a hierarchy of reps, the boolean operation will be performed between each leaf rep in the hierarchy and the
   *   second operand.
   * @param iRep1
   *   The second operand (should contain just a leaf rep).
   * @param iOperation
   *   A solid boolean operation:
   *     * CATPolyBoolean::eUnion
   *     * CATPolyBoolean::eIntersection
   *     * CATPolyBoolean::eSubtraction
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> A valid result (may be null if it is empty) is computed.
   *   <li> <tt>S_FALSE</tt> A result cannot be computed.
   *   <li> <tt>E_FAIL</tt> An error occurred.
   * </ul>
   */
  HRESULT Run (const CAT3DRep& iRep0, const CAT4x4Matrix* iRepPosition0,
               const CAT3DRep& iRep1, const CAT4x4Matrix* iRepPosition1,
               const CATPolyBoolean::BooleanOperation iOperation,
               CAT3DRep*& oResult);

  /**
   * Computes a boolean operation between two operands.
   * @param iRep0
   *   The rep to parse for extraction of the first operands.  
   *   For a hierarchy of reps, the boolean operation will be performed between each leaf rep in the hierarchy and the
   *   second operand.
   * @param iOperand1
   *   The second operand.
   * @param iOperation
   *   A solid boolean operation:
   *     * CATPolyBoolean::eUnion
   *     * CATPolyBoolean::eIntersection
   *     * CATPolyBoolean::eSubtraction
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> A valid result (may be null if it is empty) is computed.
   *   <li> <tt>S_FALSE</tt> A result cannot be computed.
   *   <li> <tt>E_FAIL</tt> An error occurred.
   * </ul>
   */
  HRESULT Run (const CAT3DRep& iRep0, const CAT4x4Matrix* iRepPosition0,
               const CATPolyBody& iOperand1, const CATMathTransformation* iPosition1,
               const CATPolyBoolean::BooleanOperation iOperation,
               CAT3DRep*& oResult);

private:

  class Operator;
  Operator* _Operator;

};

#endif
