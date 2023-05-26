// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATBVHTreeSetPairDescent.h
//
//===================================================================
// August 2013  Creation: NDO
//===================================================================
#ifndef CATBVHTreeSetPairProcessor_H
#define CATBVHTreeSetPairProcessor_H

#include "PolyBVH.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
//#include "CATIAV5Level.h"

class CATBVHTree;
class CATBVHTreeSet;
class CATBVHNodeConst;
class CATMathTransformation;
class CATPolyBoundingVolume;


/**
 * This operator descends through the nodes of a pair of BVH tree sets and calls
 * a processor for each pair of (terminal) trees that are clashing.
 * The processor is an interface that must be implemented by the caller.
 */
class ExportedByPolyBVH CATBVHTreeSetPairDescent
{

public:

  /**
   * Interface defining a processor of a pair of BVH tree clashing.
   */
  class BVHTreePairProcessor
  {

  public:

    virtual ~BVHTreePairProcessor () {}

  public:

    /**
     * Callback with a pair of trees with optional positions to process.
     * @return
     *   <ul>
     *     <li> S_OK to continue processing other pairs of trees.
     *     <li> S_FALSE to stop processing other pairs of trees.
     *   </ul>
     */
    virtual HRESULT Process (CATBVHTree& iTree0, const CATMathTransformation* iTreePosition0,
                             CATBVHTree& iTree1, const CATMathTransformation* iTreePosition1) = 0;

  };

public:

  /**
   * Constructs an instance to descend through a pair of BVH tree sets.
   * @param iClearance
   *   A clearance between the bounding volumes of the trees to respect.
   */
  CATBVHTreeSetPairDescent (const CATBVHTreeSet& iBVHTreeSet0, const CATBVHTreeSet& iBVHTreeSet1, const double iClearance);

  ~CATBVHTreeSetPairDescent () {}

public:

  /**
   * Returns <tt>TRUE</tt> if the bounding volumes of the two nodes clash.
   */
  CATBoolean Clash (const CATBVHNodeConst& iNode0, const CATBVHNodeConst& iNode1) const;

  /**
   * Scans the trees and calls back the processor with the trees that are clashing.
   * @return
   *   <ul>
   *     <li> S_OK when the parsing of both CATBVHTreeSet was complete.
   *     <li> S_FALSE when the parsing of the CATBVHTreeSet was interrupted by the tree pair processor.
   *   </ul>
   * 
   */
  HRESULT Descend (BVHTreePairProcessor& iProcessor);

private:

  const CATBVHTreeSet& _BVHTreeSet0;
  const CATBVHTreeSet& _BVHTreeSet1;

  double _Clearance;

private:

  HRESULT DescendThroughNodes (CATBVHNodeConst& iNode0, CATBVHNodeConst& iNode1, BVHTreePairProcessor& iProcessor) const;

};

#endif
