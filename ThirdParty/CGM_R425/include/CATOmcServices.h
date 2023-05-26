#ifndef __CATOmcServices_H
#define __CATOmcServices_H

#include "AC0CATPL.h"
#include "CATBaseUnknown.h"
/**
 * returns S_OK if the stream/storage for this container has not been found during unstream.
 */
extern "C" ExportedByAC0CATPL HRESULT CATOmcContainerHasNoStorage(const CATBaseUnknown* iContainer);


/**
* Register the container provided for a deletion at next save.
* The container is not destroyed immediately but it will be during the next save.
* If the session is closed without save after a call to this method, no deletion will occur.
* @param iContainer
*   a pointer to the container to delete
* @return
*   S_OK : deletion order well recorded
*   S_FALSE : container already registered for deletion
*   E_XXX : an error occurred during deletion registration. Container will not be removed.
**/
ExportedByAC0CATPL HRESULT CATOmbRegisterContainerForRemove(CATBaseUnknown* iContainer);

#endif
