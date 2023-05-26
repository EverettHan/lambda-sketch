// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBVHSplitterOperator.h
//
//===================================================================
// January 2017 Creation: ndo
//===================================================================
#ifndef CATPolyBVHSplitterOperator_H
#define CATPolyBVHSplitterOperator_H

#include "PolyBodyBoolean.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.

#include "CATPolyBodySplitter.h"
#include "CATPolyBodyOverlayOptions.h"

class CATBVHTree;
class CATBVHNodeConst;
class CATPolyBody;
class CATPolyBodyBinaryObserver;
class CATMathTransformation;
class CATPolyOverlaySplitterOperator;


/**
 * Splitter operator for BVH trees: CATBVHTree.
 * This operators splits two CATPolyBody instances from a BVH tree along their intersection curves
 * and extracts from the split samples from the operands.
 * The results are returned in new CATPolyBody instances.
 *
 * @see CATPolyBodyBinaryObserver
 * @see CATPolyBodySplitter
*/
class ExportedByPolyBodyBoolean CATPolyBVHSplitterOperator
{

public:

  /**
   * Constructs an instance of CATPolyBVHSplitterOperator operator.
   * @param iOptions
   *   @see CATPolyBodyOverlayOptions
   */
  CATPolyBVHSplitterOperator (const CATPolyBodyOverlayOptions* iOptions = 0);

  ~CATPolyBVHSplitterOperator ();

  // DEPRECATED (To get rid of.)
  CATPolyBVHSplitterOperator (const double iDTolerance, const CATPolyBodyOverlayOptions* iOptions = 0);

public:

  /**
   * Adds an operation to split the instances of CATPolyBody operands found in the BVH tree.
   * Up to 4 distinct operations can be added.
   * @param iIndexSplit
   *   The index of the operand to split: 0 or 1.
   * @param iSide
   *   Specifies the extracted side of the split entities (wires, surfaces or volumes.)
   *   <ul>
   *     <li> eLHS:    Extracts the left-hand side of the entities ("inside").
   *     <li> eRHS:    Extracts the right-hand side of the entities ("outside").
   *     <li> eOnPos:  Extracts the part of the entities in contact (overlapping) with the other operand and having the same orientation.
   *     <li> eOnNeg:  Extracts the part of the entities in contact (overlapping) with the other operand and having the opposite orientation.
   *   </ul>
   * @param iObserver
   *   The binary observer required to capture the results of the split operation.
   */
  void AddOperation (unsigned int iIndexSplit, const CATPolyBodySplitter::Side iSide, CATPolyBodyBinaryObserver& iObserver);

  /**
   * Runs the operator after the setting of operations.
   */
  HRESULT Run (CATBVHTree& iBVHTreeOperand0, const CATMathTransformation* iTreePosition0, 
               CATBVHTree& iBVHTreeOperand1, const CATMathTransformation* iTreePosition1);

  /**
   * Flushes the operations set into the operator.
   */
  void FlushOperations ();

public:

  /**
   * Runs a split operator between the two BVH tree operands.
   * The first operand if the operand whose CATPolyBody instances are split.
   * The second operand is the splitter operand.
   * Observer calls are made for each pair of CATPolyBody operands processed by the operator.
   * @param iSide
   *   Specifies the extracted side of the split entities (wires, surfaces or volumes.)
   *   <ul>
   *     <li> eLHS:    Extracts the left-hand side of the entities ("inside").
   *     <li> eRHS:    Extracts the right-hand side of the entities ("outside").
   *     <li> eOnPos:  Extracts the part of the entities in contact (overlapping) with the other operand and having the same orientation.
   *     <li> eOnNeg:  Extracts the part of the entities in contact (overlapping) with the other operand and having the opposite orientation.
   *   </ul>
   */
  HRESULT Run (CATBVHTree& iBVHTreeOperand0, const CATMathTransformation* iTreePosition0, 
               CATBVHTree& iBVHTreeOperand1, const CATMathTransformation* iTreePosition1,
               const CATPolyBodySplitter::Side iSide,
               CATPolyBodyBinaryObserver& iObserver);

private:

  double _DTolerance;  // Distance tolerance.
  CATPolyBodyOverlayOptions _Options;

  CATPolyOverlaySplitterOperator* _Operator;

  // Optional nodes.
  CATBVHNodeConst* _Node0;  // The root BVH Node for Operand 0.
  CATBVHNodeConst* _Node1;  // The root BVH Node for Operand 1.

};

#endif
