// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBVHSetOverlayOperator.h
//
//===================================================================
// July 2014 Creation: ndo
//===================================================================
#ifndef CATPolyBVHSetOverlayOperator_H
#define CATPolyBVHSetOverlayOperator_H

#include "PolyBodyBoolean.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.

#include "CATPolyBVHOverlayOperator.h"

class CATBVHTree;
class CATBVHTreeSet;


/**
* Overlay operator for BVH Tree Sets: CATBVHTreeSet.
* This operators clashes CATPolyBody operands from the BVH trees and edits the operands to make 
* them conformal along their intersections.  Observer calls are made for capture of the conformal
* operands and their intersection curves.
*
* @see CATPolyBVHOverlayOperator
*/
class ExportedByPolyBodyBoolean CATPolyBVHSetOverlayOperator
{

public:

  /**
   * Constructs an instance of CATPolyBVHSetOverlayOperator operator.
   * @param iDTolerance
   *   Distance tolerance.
   *   Topological cells and sub-elements closer than this distance will be considered coincident and merged.
   */
  CATPolyBVHSetOverlayOperator (const CATPolyBodyOverlayOptions* iOptions = 0);

  ~CATPolyBVHSetOverlayOperator () {}

  /**
   * Sets the operator options.
   */
  inline void SetOptions (const CATPolyBodyOverlayOptions& iOptions);

public:

  /**
   * Observer interface.
   */
  class ExportedByPolyBodyBoolean Observer
  {
  public:

    Observer (CATPolyBVHOverlayOperator::Observer& obs) : _BVHObserver (obs) {}
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

    CATPolyBVHOverlayOperator::Observer& GetObserver () {return _BVHObserver;}

  private:

    CATPolyBVHOverlayOperator::Observer& _BVHObserver;

  };

public:

  /**
   * Runs the overlay operator between the two BVH tree set operands.  
   * Observer calls are made for each pair of CATPolyBody operands processed by the operator.
   */
  HRESULT Run (const CATBVHTreeSet& iBVHTreeSetOperand0, const CATBVHTreeSet& iBVHTreeSetOperand1,
               Observer& iObserver);

private:

  CATPolyBVHOverlayOperator _BVHOperator;

};

inline void CATPolyBVHSetOverlayOperator::SetOptions (const CATPolyBodyOverlayOptions& iOptions)
{
  _BVHOperator.SetOptions (iOptions);
}

#endif
