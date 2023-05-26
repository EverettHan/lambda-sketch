
#ifndef __CATIUpdateProvider_h__
#define __CATIUpdateProvider_h__

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */


#include "CATBaseUnknown.h"
#include "CATBaseUnknown_var.h"
#include "CATCORBABoolean.h" // CATBoolean
#include "CATProviderItf.h" // ExportedByCATProviderItf

extern ExportedByCATProviderItf IID IID_CATIUpdateProvider;

/**
 * Interface used to include an additional object in the update process.
 * <b>Role:</b> overrides the default update behavior.
 * <br>Specific implementation rules are defined defined in the documentation of
 * each application that make use of providers to open their update process.
 */
class ExportedByCATProviderItf CATIUpdateProvider : public CATBaseUnknown
{
  CATDeclareInterface;

public:

 /**
  * Rebuilds the object (generates its result).
  * <b>Note:</b> the default update mechanism detects all objects that have been modified upstream from any
  * given object, rebuilds the rsults of all objects impacting the given object, and lastly rebuild
  * the final result.
  * @param iWorkingObj
  *     The object.
  * @param iDomain
  *     The application domain of the update (not used).
  * @return 
  *    0: the object has been updated.
  *    1: the object could not be updated.
  */
  virtual int	Update(CATBaseUnknown * iWorkingObj, CATBaseUnknown_var iDomain = NULL_var) = 0;

};

CATDeclareHandler(CATIUpdateProvider, CATBaseUnknown);


#endif //__CATIUpdateProvider_h__
