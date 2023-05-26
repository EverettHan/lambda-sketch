// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATIPolyInterfInputNodeProcessor.h
//
//===================================================================
//
// Usage notes:
// Interface called each time two input nodes are found in a BVH descent.
//
//===================================================================
//
// Oct 2009 Creation: JS9
//===================================================================

#ifndef CATIPolyInterfInputNodeProcessor_h
#define CATIPolyInterfInputNodeProcessor_h

#include "CATPolyBoundingVolumeOperators.h"
#include "CATErrorDef.h"

// Other
class CATMathTransformation;

// Polyhedral
class CATBVHTree;

/**
 * Interface called each time two input nodes are found in a BVH descent.
 */
class ExportedByCATPolyBoundingVolumeOperators CATIPolyInterfInputNodeProcessor
{
public:

  /**
   * Destructor.
   */
  virtual ~CATIPolyInterfInputNodeProcessor() {}


  /**
   * Called when the BVH Descent starts.
   * By default do nothing.
   */
  virtual void StartProcessing() {};

  /**
   * Function called each time a pair of contacting input nodes is found.
   * @param tree1 first tree whose bounding volume is intersecting with the second.
   * @param tree2 the second one.
   * @param pos1 additional position of the first tree.
   * @param pos2 additional position of the second tree.
   * @param object1Id id of the first tree.
   * @param object2Id id of the second tree.
   * @param bvTolerance the two trees are considered to be contacting at this tolerance.
   * @return S_OK if evertyhing went OK, S_FALSE to skip the pair for the other processors (should not be used),
   *              or an error code if something went wrong. If an error code is used, the descent terminates immediately.
   */
  virtual HRESULT ProcessInputNodes(CATBVHTree & tree1, const CATMathTransformation & pos1, int object1Id,
                                    CATBVHTree & tree2, const CATMathTransformation & pos2, int object2Id,
                                    double bvTolerance) = 0;

  /**
   * Call at the end of the process.
   * By default do nothing.
   */
  virtual void EndProcessing() {};

protected:

  /**
   * Constructor
   */
  CATIPolyInterfInputNodeProcessor() {}

};

#endif /* CATIPolyInterfInputNodeProcessor_h */
