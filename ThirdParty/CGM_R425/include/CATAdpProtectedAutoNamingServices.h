// COPYRIGHT DASSAULT SYSTEMES 2008
/**
* @level Protected
* @usage U1  
*/
#ifndef CATAdpProtectedAutoNamingServices_H
#define CATAdpProtectedAutoNamingServices_H

#include "CATPLMIntegrationAccess.h"

#include "CATCollec.h"
#include "CATErrorDef.h"
class CATLISTV(CATAdpAutoNamingInput);
class CATAdpAutoNamingInput;
class CATAdpAutoNamingOutput;
/**
* Services to retreive naming convention on a connected provider.
*/
class ExportedByCATPLMIntegrationAccess CATAdpProtectedAutoNamingServices
{
public:

  /**
  * Retreives a naming convention from a list of elements that are about to be created.
  *  Note : This method uses an automatic pool of result. Asking one element will fill the pool so 
  *         next calls to this method will take elements from the pool. 
  *         As it is an unitary method, it does not take into account the @see CATAdpAutoNamingInput.SetReservationNumber value.
  *         You can fill the pool with a specific number of elements with @see ReserveNames .
  *
  * @param iRepository[in]
  *   The provider from which the naming should be retreived. 
  * @param iInput [in]
  *   The input used to generate the name.
  * @param oName [in]
  *   The name of the element.
  * @return
  *   <ul>
  *   <li><tt>S_OK</tt> oOutput is usable. The repository provides an AutoNaming behavior shared on all clients.</li> 
  *   <li><tt>S_FALSE</tt> oOutput is usable. The repository does not provide an AutoNaming behavior and a session static is used.</li>
  *   <li><tt>E_FAIL</tt> oOutput is unusable.</li>
  *   </ul>
  */ 
  static HRESULT GenerateNames (const char *iRepository, const CATAdpAutoNamingInput &iInput, CATAdpAutoNamingOutput &oOutput);

  /**
  * Reserves a number of names beforehand.
  * Note : It is used to fill the pool with a specific number of elements by-passing the automatic pool size for the next use.
  * This number can be bigger than the pool size. But it doesn't change the pool size itself.
  * 
  * @param iRepository[in]
  *   The provider from which the naming should be retreived. 
  * @param iInputs [in]
  *   The list of inputs used to generate the names. 
  *   If several names should be retreived for the same type of inputs, use @see CATAdpAutoNamingInput.SetReservationNumber .
  * @return
  *   <ul>
  *   <li><tt>S_OK</tt> The repository provides an AutoNaming behavior shared on all clients.</li> 
  *   <li><tt>S_FALSE</tt> The repository does not provide an AutoNaming behavior and a session static is used.</li>
  *   <li><tt>E_FAIL</tt> Unexpected error.</li>
  *   </ul>
  */ 
  static HRESULT ReserveNames (const char *iRepository, const CATLISTV(CATAdpAutoNamingInput) &iInputs);

  /**
  * @deprecated
  * Retreives a naming convention from a list of elements that are about to be created.
  * WARNING : This method does not use a pool of results and retreives the exact number of requested names.
  * 
  * @param iRepository[in]
  *   The provider from which the naming should be retreived. 
  * @param iInputs [in]
  *   The list of inputs used to generate the names. 
  *   If several names should be retreived for the same type of inputs, use @see CATAdpAutoNamingInput.SetReservationNumber .
  * @param oOutput [in]
  *   The object used to retreive all results. Use it directly with the provided input list to retreive all results.
  * @return
  *   <ul>
  *   <li><tt>S_OK</tt> oOutput is usable. The repository provides an AutoNaming behavior shared on all clients.</li> 
  *   <li><tt>S_FALSE</tt> oOutput is usable. The repository does not provide an AutoNaming behavior and a session static is used.</li>
  *   <li><tt>E_FAIL</tt> oOutput is unusable.</li>
  *   </ul>
  */ 
  static HRESULT GenerateNames (const char *iRepository, const CATLISTV(CATAdpAutoNamingInput) &iInputs, CATAdpAutoNamingOutput &oOutput);

  /**
  * Specifies a size for the pool of naming.
  * Note : This value is used the next time the pool of names needs to be refilled.
  * 
  * @param iPoolSize[in]
  *   The size of the pool. Must be a number between 1 and 40. The default is 20.
  * @return
  *   <ul>
  *   <li><tt>S_OK</tt> The input size is valid.</li> 
  *   <li><tt>E_FAIL</tt> The size is invalid.</li>
  *   </ul>
  */ 
  static HRESULT SetPoolSizeForNextFill (int iPoolSize);

};
#endif
