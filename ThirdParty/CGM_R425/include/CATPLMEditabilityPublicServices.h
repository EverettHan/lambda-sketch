// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATPLMEditabilityPublicServices.h
// Public services for Editability
//
//===================================================================

/**
* @CAA2Level L1
* @CAA2Usage U1
*/

#ifndef CATPLMEditabilityPublicServices_H
#define CATPLMEditabilityPublicServices_H

#include "CATBaseUnknown.h"
#include "CATPLMComponentInterfaces.h"

class CATIPLMComponent;
class ExportedByCATPLMComponentInterfaces CATPLMEditabilityPublicServices
{
public:  
 /** 
  * Check the edit ability of a PLMComponent.
  * This method does not chat with the server. Saving component editions in base is not always garanteed and depends
  * on the Editability mode of the session: 
  * - Full Edit. All PLMComponents in session are always editable. Saving their modification in base may fail.
  * - Optimist Locking. Prior to the call, the user has turned on the editibility of the PLMComponent. He has been warned
  *                     if it was already known at that time that the PLMComponent won't be savable in base. And even if
  *                     at that point in time the element was savable, it may occur that saving it will fail because of concurrent 
  *                     edition (nl lock in base on the component)
  * - Pessimist locking (LA). The PLMComponent has been locked in base. Saving its modification is garanteed.
  * 
  * @param iPLMObject
  * The PLM object to check edit ability
  * @return
  *  S_OK : The PLM object is editable.
  *  S_FALSE : The PLM object is not editable.
  *  E_INVALIDARG : Error cases, ipiComp is not a pointer to a PLMComponent open in session
  *                 
  */

  static HRESULT GetEditabilityStatus(CATIPLMComponent *ipiComp);
};
#endif
