// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBVHBooleanOperator.h
//
//===================================================================
// August 2013 Creation: ndo
//===================================================================
#ifndef CATPolyBVHBooleanOperator_H
#define CATPolyBVHBooleanOperator_H

#include "PolyBodyBoolean.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATPolyBoolean.h"
#include "CATPolyBodyBooleanOptions.h"

class CATBVHTree;
class CATBVHNodeConst;
class CATPolyBody;
class CATPolyBodyBinaryObserver;
class CATMathTransformation;
class CATMapOfIntToInt;


/**
Boolean operator for BVH Trees: CATBVHTree
It performs the union, intersection or subtraction between two operands.
The result is returned in a new CATPolyBody instance.
*/
class ExportedByPolyBodyBoolean CATPolyBVHBooleanOperator
{

public:

  /**
   * Constructs an instance of CATPolyBVHBooleanOperator operator.
   * @param iOptions
   *   @see CATPolyBodyBooleanOptions
   *   @see CATPolyBodyOverlayOptions
   */
  inline CATPolyBVHBooleanOperator (const CATPolyBodyBooleanOptions* iOptions = 0);

  ~CATPolyBVHBooleanOperator () {_Node0 = 0; _Node1 = 0;}

  /**
   * Sets the operator options.
   */
  inline void SetOptions (const CATPolyBodyBooleanOptions& iOptions);

  /**
   * Optional BVH nodes for optimization (when there is no clash) for propagation of the winding numbers.
   */
  inline void SetNodes (CATBVHNodeConst* iNode0, CATBVHNodeConst* iNode1);

public:

  /**
   * Runs a boolean operation between the two BVH tree operands.
   * Observer calls are made for each pair of CATPolyBody operands processed by the operator.
   */
  HRESULT Run (CATBVHTree& iBVHTreeOperand0, const CATMathTransformation* iTreePosition0, 
               CATBVHTree& iBVHTreeOperand1, const CATMathTransformation* iTreePosition1,
               const CATPolyBoolean::BooleanOperation iOperation,
               CATPolyBodyBinaryObserver& iObserver);

private:

  CATPolyBodyBooleanOptions _Options;

  // Optional nodes.
  CATBVHNodeConst* _Node0;  // The root BVH Node for Operand 0.
  CATBVHNodeConst* _Node1;  // The root BVH Node for Operand 1.

private:

  HRESULT RunWithOverlay (CATBVHTree& iBVHTreeOperand0, const CATMathTransformation* iTreePosition0, 
                          CATBVHTree& iBVHTreeOperand1, const CATMathTransformation* iTreePosition1,
                          const CATPolyBoolean::BooleanOperation iOperation,
                          CATPolyBodyBinaryObserver& iObserver);

  // To get rid of.
  HRESULT DescendAndRunWithPolyBodyOperator (CATBVHTree& iBVHTreeOperand0, const CATMathTransformation* iTreePosition0, 
                                             CATBVHTree& iBVHTreeOperand1, const CATMathTransformation* iTreePosition1,
                                             const CATPolyBoolean::BooleanOperation iOperation,
                                             CATPolyBodyBinaryObserver& iObserver);

};

inline CATPolyBVHBooleanOperator::CATPolyBVHBooleanOperator (const CATPolyBodyBooleanOptions* iOptions)
{
	_Node0 = 0;
	_Node1 = 0;
  if (iOptions)
    _Options = *iOptions;
}

inline void CATPolyBVHBooleanOperator::SetOptions (const CATPolyBodyBooleanOptions& iOptions)
{
  _Options = iOptions;
}

inline void CATPolyBVHBooleanOperator::SetNodes (CATBVHNodeConst* iNode0, CATBVHNodeConst* iNode1)
{
  _Node0 = iNode0;
  _Node1 = iNode1;
}

#endif
