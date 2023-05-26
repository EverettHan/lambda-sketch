// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATBVHVisuSimpleClashOper.h
//
//===================================================================
//
// Usage notes:
// Operator to compute clash.
//
//===================================================================
//
// Sep 2009 Creation: JXO
//===================================================================
#ifndef CATBVHVisuSimpleClashOper_h
#define CATBVHVisuSimpleClashOper_h

#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATPolyBodySimpleClashOper.h"

class CATBVHTree;
class CAT4x4Matrix;

#include "PolyVisuBVH.h"


/**
 * Computes clash between two BVH constructed from CAT3DReps.
 *
 * Note about memory: Temporary computation data is stored inside this
 * Operator. It can heavily be re-used in next computations for performance
 * purposes. So you just have to change operands and call Run method again.
 * To release memory, just delete the operator.
 */

class ExportedByPolyVisuBVH CATBVHVisuSimpleClashOper : public CATPolyBodySimpleClashOper
{
public:

  /**
   * Clash specification: see @CATPolyBodySimpleClashOper
   */

  /**
   * Clash result:  see @CATPolyBodySimpleClashOper
   */

public:

  /**
   * Constructor and destructor.
   */
  CATBVHVisuSimpleClashOper ();
  virtual ~CATBVHVisuSimpleClashOper ();

  /**
   * Run method. see @CATPolyBodySimpleClashOper
   */

  /**
   * Set the two operands. see @CATBVHTreeRepBuilder
   */
  void SetTrees(CATBVHTree * pTree1, CATBVHTree * pTree2, CAT4x4Matrix * pPos1 = NULL, CAT4x4Matrix * pPos2 = NULL);



};

#endif // CATBVHVisuSimpleClashOper_H

