// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATIPolyBodyBVHInputFaceFilter.h
//
//===================================================================
//
// Usage notes:
// Interface defining a filter used to avoid/allow face
// to be treated by the collision detection process.
//
//===================================================================
//
// March 2012 Creation: JXO
//===================================================================

#ifndef CATIPolyBodyBVHInputFaceFilter_h
#define CATIPolyBodyBVHInputFaceFilter_h

#include "CATPolyRefCounted.h"

// ExportedBy
#include "PolyBodyBVHOperators.h"

// System
#include "CATBoolean.h"

/**
 * Parent class for filters on input faces.
 */
class ExportedByPolyBodyBVHOperators CATIPolyBodyBVHInputFaceFilter : public CATPolyRefCounted
{
public:

  /**
   * Destructor.
   */
  virtual ~CATIPolyBodyBVHInputFaceFilter() {}

  /**
   * Returns TRUE if the face referenced by its id is NOT to be taken into account, FALSE otherwise.
   */
  virtual CATBoolean Filter(int objectId, unsigned int CGMId) = 0;

protected:

  /**
   * Constructor
   */
  CATIPolyBodyBVHInputFaceFilter() {}

};

#endif /* CATIPolyBodyBVHInputFaceFilter_h */
