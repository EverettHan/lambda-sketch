// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATIPolyBodyBVHInputFilter.h
//
//===================================================================
//
// Usage notes:
// Interface defining a filter used to avoid/allow objects
// to be treated by the interference / BVH descent process.
//
//===================================================================
//
// March 2012 Creation: JXO
//===================================================================

#ifndef CATIPolyBodyBVHInputFilter_h
#define CATIPolyBodyBVHInputFilter_h

// Poly
#include "CATPolyRefCounted.h"

// ExportedBy
#include "PolyBodyBVHOperators.h"

// System
#include "CATBoolean.h"

/**
 * Parent class for filters on input bodies
 */
class ExportedByPolyBodyBVHOperators CATIPolyBodyBVHInputFilter : public CATPolyRefCounted
{
public:
  /**
   * Destructor.
   */
  virtual ~CATIPolyBodyBVHInputFilter() {}

  /**
   * Returns TRUE if the object referenced by its id is NOT to be taken into account, FALSE otherwise.
   */
  virtual CATBoolean Filter(int objectId) = 0;


protected:
  /**
   * Constructor
   */
  CATIPolyBodyBVHInputFilter() {}

};

#endif /* CATIPolyBodyBVHInputFilter_h */
