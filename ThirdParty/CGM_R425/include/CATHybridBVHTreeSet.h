// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATHybridBVHTreeSet.h
//
//===================================================================
//
// Usage notes:
// This class gather and arrange input PolyBodies and CGMTessBodies 
// in an efficient way to be used by the interference operators.
// Moreover, this class act as cache for these operators and can be
// slightly modified between calls to the operator.
//
//===================================================================
//
// March 2011 Creation: DPS
//===================================================================

#ifndef CATHybridBVHTreeSet_h
#define CATHybridBVHTreeSet_h

#include "BVHTools.h"

// PolyMathematics
#include "CATPolyBodyBVHTreeSet.h"

// Polyhedral
#include "CATMapOfPtrToPtr.h"

class CATMathTransformation;
class CATCGMTessBody;


/**
 * This class gather and arrange input Polybodies and CGMTessBodies in an efficient
 * way to be used by the interference operators.
 * Moreover, this class act as cache for these operators and can be
 * slightly modified between calls to the operator.
 */

/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByBVHTools CATHybridBVHTreeSet : public CATPolyBodyBVHTreeSet
{
public:

  /**
  * Constructor and destructor
  */
  CATHybridBVHTreeSet();
  virtual ~CATHybridBVHTreeSet();


  /**
  * Add a TessBody in the set at a certain position.
  * @return S_OK if the object could be correctly registers, E_FAIL otherwise.
  */
  HRESULT AddTessBody(int objectId, CATCGMTessBody * object, const CATMathTransformation * pos = NULL, EntityType iType = eFaceEntities);


  /**
  * Removes given GMTessBody
  */
  HRESULT RemoveTessBody(int objectId);



protected:

  CATMapOfPtrToPtr _MapOfBodyToTrees;
};

#endif /* CATPolyVisuInterfBVHTreeSet_h */
