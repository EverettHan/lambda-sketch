// COPYRIGHT DASSAULT SYSTEMES 2021, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuOptimizedBVHTreeSet.h
//
//===================================================================
//
// Usage notes:
// This class gather and arrange input representations in an efficient
// way to be used by the interference operators.
// See CATPolyVisuBVHTreeSet for details.
//
//===================================================================
//
// Sep 2021 Creation: JXO
//===================================================================

#ifndef CATPolyVisuOptimizedBVHTreeSet_h
#define CATPolyVisuOptimizedBVHTreeSet_h

#include "PolyVisuClash.h"

// Other
#include "CATMathTransformation.h"

// Visualization
class CAT3DRep;

// PolyMathematics
#include "CATPolyVisuBVHTreeSet.h"

// Polyhedral
#include "CATBVHTreeRepBuilder.h"

/**
 * This class gather and arrange input representations in an efficient
 * way to be used by the interference operators.
 * Moreover, this class act as cache for these operators and can be
 * slightly modified between calls to the operator.
 * All AddVisuRep calls will create optimized BVH trees.
 */
class ExportedByPolyVisuClash CATPolyVisuOptimizedBVHTreeSet : public CATPolyVisuBVHTreeSet
{
public:


  /**
   * Constructor
   */
  CATPolyVisuOptimizedBVHTreeSet();
  /**
   * Copy
   */
  CATPolyVisuOptimizedBVHTreeSet(const CATPolyVisuBVHTreeSet& iOther);

  /**
   * Destructor
   */
  virtual ~CATPolyVisuOptimizedBVHTreeSet();

};

#endif /* CATPolyVisuInterfBVHTreeSet_h */
