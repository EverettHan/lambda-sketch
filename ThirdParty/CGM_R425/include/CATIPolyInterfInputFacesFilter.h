// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATIPolyInterfInputFacesFilter.h
//
//===================================================================
//
// Usage notes:
// Interface defining a filter used to avoid/allow faces couples
// to be treated by the collision detection process.
//
//===================================================================
//
// May 2011 Creation: JXO
//===================================================================

#ifndef CATIPolyInterfInputFacesFilter_h
#define CATIPolyInterfInputFacesFilter_h

#include "CATPolyBoundingVolumeOperators.h"
#include "CATPolyRefCounted.h"

// System
#include "CATBoolean.h"

/**
 * Parent class for operators detecting interferences between visu reps.
 */
class ExportedByCATPolyBoundingVolumeOperators CATIPolyInterfInputFacesFilter : public CATPolyRefCounted
{
public:

  /**
   * Destructor.
   */
  virtual ~CATIPolyInterfInputFacesFilter() {}

  /**
   * Returns TRUE if the faces couple referenced by their id is NOT to be taken into account, FALSE otherwise.
   */
  virtual CATBoolean Filter(int objectId1, int objectId2, unsigned int CGMId1, unsigned int CGMId2) = 0;

protected:

  /**
   * Constructor
   */
  CATIPolyInterfInputFacesFilter() {}

};

#endif /* CATIPolyInterfInputFacesFilter_h */
