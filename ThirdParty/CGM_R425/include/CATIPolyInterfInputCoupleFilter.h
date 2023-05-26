// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATIPolyInterfInputCoupleFilter.h
//
//===================================================================
//
// Usage notes:
// Interface defining a filter used to avoid/allow object couples
// to be treated by the interference process.
//
//===================================================================
//
// Aug 2009 Creation: JS9
//===================================================================

#ifndef CATIPolyInterfInputCoupleFilter_h
#define CATIPolyInterfInputCoupleFilter_h

#include "CATPolyBoundingVolumeOperators.h"

// System
#include "CATBoolean.h"

// Interference
#include "CATIPolyInterfInputNodeProcessor.h"

/**
 * Parent class for operators detecting interferences between visu reps.
 */
class ExportedByCATPolyBoundingVolumeOperators CATIPolyInterfInputCoupleFilter
  : public CATIPolyInterfInputNodeProcessor
{
public:


  /**
   * Destructor.
   */
  virtual ~CATIPolyInterfInputCoupleFilter() {}

  /**
   * Returns TRUE if the object couple referenced by their id is NOT to be taken into account, FALSE otherwise.
   */
  virtual CATBoolean Filter(int object1Id, int object2Id) = 0;

  /**
   * Don't modify this function.
   */
  virtual HRESULT ProcessInputNodes(CATBVHTree & tree1, const CATMathTransformation & pos1, int object1Id,
                                    CATBVHTree & tree2, const CATMathTransformation & pos2, int object2Id,
                                    double bvTolerance);

protected:

  /**
   * Constructor
   */
  CATIPolyInterfInputCoupleFilter() {}

};

#endif /* CATIPolyInterfInputCoupleFilter_h */
