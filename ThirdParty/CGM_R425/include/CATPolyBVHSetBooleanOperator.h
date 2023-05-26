// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBVHSetBooleanOperator.h
//
//===================================================================
// July 2014 Creation: ndo
//===================================================================
#ifndef CATPolyBVHSetBooleanOperator_H
#define CATPolyBVHSetBooleanOperator_H

#include "PolyBodyBoolean.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.

#include "CATPolyBoolean.h"
#include "CATPolyBVHBooleanOperator.h"

class CATBVHTree;
class CATBVHTreeSet;
class CATPolyBodyBooleanOptions;
class CATPolyBodyBinaryObserver;


/**
* Boolean operator for BVH Tree Sets: CATBVHTreeSet
* It performs the union, intersection or subtraction between two volume operands.
*
* @see CATPolyBVHBooleanOperator
*/
class ExportedByPolyBodyBoolean CATPolyBVHSetBooleanOperator
{

public:

  /**
   * Constructs an instance of CATPolyBVHSetBooleanOperator operator.
   * @param iOptions
   *   @see CATPolyBodyBooleanOptions
   *   @see CATPolyBodyOverlayOptions
   */
  CATPolyBVHSetBooleanOperator (const CATPolyBodyBooleanOptions* iOptions = 0);

  ~CATPolyBVHSetBooleanOperator () {}

  /**
   * Sets the operator options.
   */
  inline void SetOptions (const CATPolyBodyBooleanOptions& iOptions);

  // DEPRECATED (To get rid of.)
  CATPolyBVHSetBooleanOperator (const double iDTolerance);

public:

  /**
   * Observer interface.
   */
  class ExportedByPolyBodyBoolean Observer
  {
  public:

    Observer (CATPolyBodyBinaryObserver& obs) : _BVHObserver (obs) {}
    virtual ~Observer () {}

  public:

    /**
     * Observer call made when at the beginning of a descent through the BVH tree
     * @param id
     *   The ID of the BVH Tree.
     * @param op
     *   The index of the operand: 0 or 1.
     */
    virtual void DescendingThrough (CATBVHTree& iBVHTree, const int id, const unsigned int op) {}

  public:

    CATPolyBodyBinaryObserver& GetObserver () {return _BVHObserver;}

  private:

    CATPolyBodyBinaryObserver& _BVHObserver;

  };

public:

  /**
   * Runs a boolean operator between the two BVH tree set operands.  
   * Observer calls are made for each pair of CATPolyBody operands processed by the operator.
   */
  HRESULT Run (const CATBVHTreeSet& iBVHTreeSetOperand0, const CATBVHTreeSet& iBVHTreeSetOperand1,
               const CATPolyBoolean::BooleanOperation iOperation,
               Observer& iObserver);

private:

  CATPolyBVHBooleanOperator _BVHOperator;

  double _DTolerance;  // Distance tolerance.

};

inline void CATPolyBVHSetBooleanOperator::SetOptions (const CATPolyBodyBooleanOptions& iOptions)
{
  _BVHOperator.SetOptions (iOptions);
}

#endif
