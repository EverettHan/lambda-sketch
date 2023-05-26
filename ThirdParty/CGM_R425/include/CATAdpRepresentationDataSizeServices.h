/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005
/**
* @level Protected
* @usage U1  
*/

#ifndef __CATAdpRepresentationDataSizeServices__
#define __CATAdpRepresentationDataSizeServices__

#include "CATAdpProtectedDataSizeServices.h"

/**
* Class of services to get the size of representations stored in vault and in cache.
**/
class ExportedByCATPLMIntegrationAccess CATAdpRepresentationDataSizeServices
{
public:
 
  /** 
  * Gets the size in vault of representations.
  * @param iIdentifiers [in]
  *   The identifiers of representations.
  * @param oAdpDataSizes [out]
  *   The hash table containing the size of each representation.
  *
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise E_FAIL.
  */
  static HRESULT GetRepDataSize(CATLISTP(CATIAdpPLMIdentificator)& iIdentifiers, CATAdpDataSizes& oAdpDataSizes);
};

#endif //__CATAdpRepresentationDataSizeServices__

