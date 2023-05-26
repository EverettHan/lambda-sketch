#ifndef CATAdpOwnershipServices_h
#define CATAdpOwnershipServices_h

#include "CATPLMIntegrationAccess.h"
#include "IUnknown.h"
class CATListPtrCATIAdpPLMIdentificator;
class CATUnicodeString;
class CATAdpResultIterator;


/**
* @level Protected
* @usage U1  
*/

#define AuthorizedModule     999

#define PLMPosCltSecAdminModel AuthorizedModule
#define CATPLMIntegrationAccess AuthorizedModule
#define TSTCATAdpOwnershipServices AuthorizedModule
#define CATPLMItgTests AuthorizedModule
#define PLMPosClientImpl AuthorizedModule
#define CATPLMItgTestIntegrationAccess AuthorizedModule
#define CATDbdImportModeler AuthorizedModule
#define CATComponentsFamilyBatchUI AuthorizedModule // Tres temporaire pour correction bug chez TVQ. Devrait passer sur service de LFE.
#define CATPCTER AuthorizedModule       
#define CATPCTCheckCnxSessionRefresh AuthorizedModule       

#if _MK_MODNAME_ == AuthorizedModule

#else
      #error Forbidden Access to CATAdpOwnershipServices
      @error
#endif

#undef PLMPosCltSecAdminModel
#undef CATPLMIntegrationAccess
#undef TSTCATAdpOwnershipServices
#undef CATPLMItgTests 
#undef PLMPosClientImpl
#undef CATPLMItgTestIntegrationAccess
#undef CATDbdImportModeler
#undef CATComponentsFamilyBatchUI
#undef CATPCTER 
#undef CATPCTCheckCnxSessionRefresh 

class ExportedByCATPLMIntegrationAccess CATAdpOwnershipServices
{
 public :

  /**
   * Performs a transfert of ownership of the components given in input.
   * @param iObjects [in] the list of components that will be transfered
   * @param iTargetPersonID [in]  the target person’s identificator 
   * @param iTargetOrganizationID [in] the target organisation's identificator
   * @param iTargetProjectID [in] the target project's identificator
   *
   * @param oErrors [out] This parameter is filled only if the method returns S_FALSE or E_FAIL.
   *                      
   *
   * @return S_OK if everything succeeded
   *         E_FAIL if an error occured and all the process have been canceled
   *                Check oErrors and if it is not available, read @href CATError#CATGetLastError
   */

  static HRESULT ChangeOwnership(const CATListPtrCATIAdpPLMIdentificator & iObjects, 
				 const CATUnicodeString & iTargetPersonID,
				 const CATUnicodeString & iTargetOrganizationID,
				 const CATUnicodeString & iTargetProjectID, 
				 CATAdpResultIterator *& oErrors);


 private :
  CATAdpOwnershipServices();
};
#endif
