// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATIPLMCompConnectionService.h
// Define the CATIPLMCompConnectionService interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//  May 2004  Creation: Code generated by the CAA wizard  jsy
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMCompConnectionService_H
#define CATIPLMCompConnectionService_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompConnectionService;
#else
extern "C" const IID IID_CATIPLMCompConnectionService ;
#endif

#include "CATLISTV_CATPLMRepositoryName.h"
#include "CATListValCATPLMCertificateToken.h"

class CATPLMRepositoryName;
//class CATIPLMCompConnection;
class CATString;
class CATIPLMCompConnectionInstance ;
class CATListPtrCATIPLMCompConnectionInstance;
class CATPLMID;

/**
 * Interface belonging to the <b>Component services</b>.
 * Using this level of abstraction you manipulate providers without knowing the PDM it belongs to.<br>
 *
 */
class ExportedByCATPLMServicesItf CATIPLMCompConnectionService: public CATBaseUnknown
{
  CATDeclareInterface;

  public:
  /**
  * Returns all the connection  which can be used.
  *   @param iType 
  *	     Provider Repository Name. If empty, all providers are required.@see CATPLMRepositoryName
  *   @param  oListCompCnx 
  *      provider connections. Each connection of the list must be released after use.
  *      the oListCompCnx list is updated by the implementation (coonexiosn are added to the given list)
  *   @return
  *      Error code of function.
  */
    
    virtual HRESULT ListConnections (const CATPLMRepositoryName iRepos, CATListPtrCATIPLMCompConnectionInstance ** oListCompCnx) = 0;

  

  /**
  *   Returns the connection for the given repository name and instance Id.
  *   @param iRepos 
  *      Provider Repository Name. @see CATPLMRepositoryName
  *   @param iID, 
  *      instance Id
  *   @param oCompCnx
  *      the connection.
  *   @return
  *      Error code of function.
  *      S_FALSE if no connection of the required type has been found.
  */
  virtual HRESULT GetConnection  (const CATPLMRepositoryName iRepos, const CATString iID, CATIPLMCompConnectionInstance ** oCompCnx) = 0;

  /**
  * Returns the list of the available providers.
  *   @param oAvailableProviders
  *      The list of available providers.
  *   @return
  *      S_OK, if everything run well, otherwise E_FAIL.
  */
  virtual HRESULT ListRepositoryNames(CATPLMRepositoryNames& oAvailableProviders) = 0;

  /**
  * Use an URL defined by a provider to connect and retreive a valid PLMID.
  *   @param iRepos 
  *      Provider Repository Name. @see CATPLMRepositoryName
  *   @param iID, 
  *      instance Id
  *   @param iURL
  *      The URL used by the repository to create a connection and retreive 
  *      a valid PLMID.
  *   @param oPLMID 
  *      The extracted element
  *   @return
  *      S_OK,   if everything run well
  *      S_FALSE The connection is OK, but the element cannot be found (PLMID invalid)
  *      E_FAIL  connection failed
  */
  virtual HRESULT ConnectAndGetPLMIDFromURL(const CATPLMRepositoryName iRepo, const CATString iID, const CATUnicodeString & iURL, CATPLMID & oPLMID) = 0;

  /**
  * Returns a URL like string based on a Executable Parameter.
  *   @param iRepo 
  *      Provider Repository Name. @see CATPLMRepositoryName
  *   @param iExeParamName
  *      Name of the parameter that needs to be transformed
  *   @param iExeParam
  *      Value of the parameter that needs to be transformed
  * @return
  *      An URL compatible with the ConnectAndGetPLMIDFromURL method. Default behaviour builds an URL like
  *      iRepo://TreatedString the TreatedString is iExeParam with automatic character transformation for URL compatibility
  */
   virtual CATUnicodeString GetURLFromExecutableParameter (const CATPLMRepositoryName iRepo, const CATUnicodeString &iExeParamName, const CATUnicodeString &iExeParam) = 0;

  /**
  * Returns the list of client certificates for a specified repository.
  *   @param iRepo 
  *      Provider Repository Name. @see CATPLMRepositoryName 
  *      The provider can be disconnected / not instanciated.
  *   @param oClientCertificates 
  *      The list of certificate tokens that can be used on server side to check behaviors. This list can be empty.
  *      this list is filled by xml files that are delivered in rtv.
  * @return
  *      S_OK : Specific repository tokens were added in the list
  *      S_FALSE : No specific repository tokens were added.
  *      E_FAIL : The repository is unknown
  */
  virtual HRESULT GetClientCertificateTokens (const CATPLMRepositoryName &iRepo, CATListOfCATPLMCertificateToken &oClientCertificates) = 0;

  /**
  * Returns the list of client certificates required for a specified repository.
  *   @param iRepo 
  *      Provider Repository Name. @see CATPLMRepositoryName 
  *      The provider can be disconnected / not instanciated.
  *   @param oClientCertificates 
  *      The list of certificate tokens that are needed by the client for the succeess of the connection.
  *      this list is filled by xml files that are delivered in rtv.
  * @return
  *      S_OK : Specific repository tokens were added in the list
  *      S_FALSE : No specific repository tokens were added.
  *      E_FAIL : The repository is unknown
  */
  virtual HRESULT GetRequiredClientCertificateTokens (const CATPLMRepositoryName &iRepo, CATListOfCATPLMCertificateToken &oClientCertificates) = 0;

  /**
  * Checks that the list of required certificates is fulfill by a supplied certificate.
  *   @param iSupCert 
  *      List of supplied certificate. 
  *   @param iReqCert 
  *      List of required certificate. 
  *   @param oErrorReqToken 
  *      The first token which is not fullfilled.
  * @return
  *      S_OK : All required certificates are fulfill
  *      E_FAIL : At least one certificate is not fulfill, oErrorReqToken contains the first one.
  */
  virtual HRESULT CheckCertificates (const CATListOfCATPLMCertificateToken &iSupCert, const CATListOfCATPLMCertificateToken &iReqCert, CATPLMCertificateToken &oErrorReqToken) = 0;

  /* Check that a functionality is available on a repository
  *   @param iRepo 
  *      Provider Repository Name. @see CATPLMRepositoryName 
  *   @param iProjectName
  *      The name of the functionality
  *   @return
  *      S_OK if the functionality was found and is activated
  *      E_FAIL otherwise
  */
  virtual HRESULT CheckFunctionality(const CATPLMRepositoryName &iRepo, const char * iProjectName) = 0;
};

#endif