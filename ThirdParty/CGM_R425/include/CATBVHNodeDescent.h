// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//===================================================================
//
// CATBVHNodeDescent.h
//
//===================================================================
// June 2014  Creation: NDO
//===================================================================
#ifndef CATBVHNodeDescent_H
#define CATBVHNodeDescent_H

#include "PolyBVH.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
//#include "CATIAV5Level.h"

class CATBVHNodeConst;


/*
 * This operator performs a descent through the nodes of a BVH tree and calls
 * a processor for each pair of clashing nodes through which the descent should not continue.
 * The processor is an interface that must be implemented by the caller.
 *
 * @see CATBVHTree
 * @see CATBVHNodeConst
 * @see CATBVHNodePairDescent
 */
class ExportedByPolyBVH CATBVHNodeDescent
{

public:

  /**
   * Interface used for two purposes:
   * <ul>
   *   <li> To test if there is a clash with the bounding volumes of a node.
   *   <li> When there is a clash, to check if the descend should continue through the node or
   *        instead the node should be processed.
   * </ul>
   */
  class BVHNodeProcessor
  {

  public:

    virtual ~BVHNodeProcessor () {}

  public:

    /**
     * Returns <tt>TRUE</tt> if there is a clash with the bounding volumes of the node.
     */
    virtual CATBoolean Clash (const CATBVHNodeConst& iNode) const = 0;

  public:

    /**
     * Checks whether the descent should continue through the node for which there is a BV clash.
     * @return
     *   <ul>
     *     <li> <tt>TRUE</tt> if the descent should continue through the node.
     *     <li> <tt>FALSE</tt> if the descent should not continue through the node.
     *   </ul>
     */
    virtual CATBoolean ContinueDescent (CATBVHNodeConst& iNode) = 0;

    /**
     * Callback made for a node through which the descent should not continue.
     * @param iNode
     *   The node from the tree.
     * @param iNodePosition
     *   An optional position matrix for the node.
     * @return
     *   <ul>
     *     <li> S_OK to continue processing other nodes.
     *     <li> S_FALSE to stop processing other nodes.
     *   </ul>
     */
    virtual HRESULT Process (CATBVHNodeConst& iNode) = 0;

  };

public:

  /**
   * Constructs an instance to descend through the nodes of a BVH tree.
   */
  CATBVHNodeDescent () {}

  ~CATBVHNodeDescent () {}

public:

  /**
   * Scans the nodes and calls back the processor for each node (1) to test if there is a clash; (2) to check if the descent should 
   * continue though this node or otherwise the node should be processed.
   * @return
   *   <ul>
   *     <li> S_OK when the parsing of both CATBVHNodeConst was complete.
   *     <li> S_FALSE when the parsing of the CATBVHNodeConst was interrupted by the node pair processor.
   *   </ul>
   * 
   */
  HRESULT Descend (CATBVHNodeConst& iNode, BVHNodeProcessor& iProcessor) const;

};

#endif
