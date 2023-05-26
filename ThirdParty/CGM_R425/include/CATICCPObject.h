// COPYRIGHT DASSAULT SYSTEMES 2007
//===================================================================
//
// CATICCPObject.h
//		Access to Cut/Copy/Paste/Delete federating "container"
//
//===================================================================
//
// Usage notes:
//    Implementation of this interface "overrides" implementation of CATIObjectToContainer interface for Cut/Copy¨/Paste/Delete capabilities
//
//===================================================================
//
//===================================================================
#ifndef CATICCPObject_H
#define CATICCPObject_H

/**
 * @level Protected
 * @usage U3 CATECCPObject
 */

#include "CP0CLIP.h"
#include "CATBaseUnknown.h"

extern ExportedByCP0CLIP IID IID_CATICCPObject ;

//------------------------------------------------------------------

/**
 * Access to Cut/Copy/Paste/Delete federating "container"
 * <p>
 * Implementation of this interface "overrides" implementation of CATIObjectToContainer interface for Cut/Copy¨/Paste/Delete capabilities.
 * As of end 2007, a full migration to this interface instead of CATIObjectToContainer is not launched, but you will notice that when using this interface, 
 * your federator object does not need to implement CATIContainer any more for CCP support.
 */
class ExportedByCP0CLIP CATICCPObject: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /**
  * Retrieves the federator object from a given implementation object.
  * This federator object is the object (persistent or volatile) that has the knowledge for management of Cut, Copy, Paste and Delete
  * capabilities for a given set of obects. This knowledge is expressed (as of 2007) through CATICutAndPastable interface implementation.
  * <br>Please notice that this may evolve in the future.
  * @param oFederator [out, CATBaseUnknown#Release]
  * the federator object, implementing CATICutAndPastable interface (as of 2007)
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  *
  */
  virtual HRESULT GetCCPContainer(CATBaseUnknown*& oFederator) = 0;
};

#endif
