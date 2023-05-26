// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATBVHNodePairDescent.h
//
//===================================================================
// October 2013  Creation: NDO
//===================================================================
#ifndef CATBVHNodePairDescent_H
#define CATBVHNodePairDescent_H

#include "PolyBVH.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
//#include "CATIAV5Level.h"

class CATBVHNodeConst;
class CATMathTransformation;
class CATPolyBoundingVolume;


/*
 * This operator performs a descent through the nodes of a pair of BVH trees and calls
 * a processor for each pair of clashing nodes through which the descent should not continue.
 * The processor is an interface that must be implemented by the caller.
 *
 * @see CATBVHTree
 * @see CATBVHNodeConst
 */
class ExportedByPolyBVH CATBVHNodePairDescent
{

public:

  /**
   * Interface defining a processor of a pair of BVH nodes clashing.
   */
  class BVHNodePairProcessor
  {

  public:

    virtual ~BVHNodePairProcessor () {}

  public:

    /**
     * Checks whether the descent should continue through the given pair of nodes.
     * @return
     *   <ul>
     *     <li> <tt>TRUE</tt> if the descent should continue through the nodes.
     *     <li> <tt>FALSE</tt> if the descent should not continue through the nodes.
     *   </ul>
     */
    virtual CATBoolean ContinueDescent (CATBVHNodeConst& iNode0, CATBVHNodeConst& iNode1) = 0;

    /**
     * Callback made for each pair of clashing nodes through which the descent should not continue.
     * @param iNode0
     *   The node from the first tree.
     * @param iNodePosition0
     *   An optional position matrix for Node 0.
     * @param iNode1
     *   The node from the second tree.
     * @param iNodePosition1
     *   An optional position matrix for Node 1.
     * @return
     *   <ul>
     *     <li> S_OK to continue processing other pairs of nodes.
     *     <li> S_FALSE to stop processing other pairs of nodes.
     *   </ul>
     */
    virtual HRESULT Process (CATBVHNodeConst& iNode0, const CATMathTransformation* iNodePosition0,
                             CATBVHNodeConst& iNode1, const CATMathTransformation* iNodePosition1) = 0;

  };

public:

  /**
   * Constructs an instance to descend through a pair of BVH nodes.
   * @param iPositionNode0
   *   An optional position matrix for the nodes of the first tree.
   * @param iPositionNode1
   *   An optional position matrix for the nodes of the second tree.
   * @param iClearance
   *   A clearance between the bounding volumes of the nodes to respect.
   */
  CATBVHNodePairDescent (const CATMathTransformation* iPositionNode0, const CATMathTransformation* iPositionNode1,
                         const double iClearance);

  ~CATBVHNodePairDescent ();

public:

  inline const CATMathTransformation* GetPositionNode0 () const;

  inline const CATMathTransformation* GetPositionNode1 () const;

  inline const CATMathTransformation* GetFromNode1ToNode0Transformation () const;

public:

  /**
   * Returns <tt>TRUE</tt> if the bounding volumes of the two nodes clash.
   */
  CATBoolean Clash (const CATBVHNodeConst& iNode0, const CATBVHNodeConst& iNode1) const;

  /**
   * Scans the nodes and calls back the processor with pair of nodes that are clashing and 
   * through which the descent should not continue.
   * @param iSkipClash
   *   Disables the call to the clash and descend systematically through all pairs of nodes if
   *   this argument is set to <tt>TRUE</tt>
   * @return
   *   <ul>
   *     <li> S_OK when the parsing of both CATBVHNodeConst was complete.
   *     <li> S_FALSE when the parsing of the CATBVHNodeConst was interrupted by the node pair processor.
   *   </ul>
   * 
   */
  HRESULT Descend (CATBVHNodeConst& iNode0, CATBVHNodeConst& iNode1, BVHNodePairProcessor& iProcessor, 
                   const CATBoolean iSkipClash = FALSE) const;

  /**
   * Descends exclusively through Node 0.
   */
  HRESULT DescendNode0 (CATBVHNodeConst& iNode0, CATBVHNodeConst& iNode1, BVHNodePairProcessor& iProcessor, 
                        const CATBoolean iSkipClash = FALSE) const;

  /**
   * Descends exclusively through Node 1.
   */
  HRESULT DescendNode1 (CATBVHNodeConst& iNode0, CATBVHNodeConst& iNode1, BVHNodePairProcessor& iProcessor, 
                        const CATBoolean iSkipClash = FALSE) const;

private:

  CATMathTransformation* _PositionNode0;
  CATMathTransformation* _PositionNode1;
  CATMathTransformation* _LocalAxisFrom1To0;

  double _Clearance;

};

inline const CATMathTransformation* CATBVHNodePairDescent::GetPositionNode0 () const
{
  return _PositionNode0;
}

inline const CATMathTransformation* CATBVHNodePairDescent::GetPositionNode1 () const
{
  return _PositionNode1;
}

inline const CATMathTransformation* CATBVHNodePairDescent::GetFromNode1ToNode0Transformation () const
{
  return _LocalAxisFrom1To0;
}

#endif
