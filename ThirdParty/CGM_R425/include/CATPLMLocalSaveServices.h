#ifndef CATPLMLocalSaveServices_h
#define CATPLMLocalSaveServices_h

#include "CATPLMIntegrationBase.h"
#include "IUnknown.h"
#include "CATUnicodeString.h"
class CATOMYUnicodeStringHTab;
class CATPLMRepositoryName;
class CATPLMConnectionParameters;
class CATOmySessionImageDescriptor;
class CATIAdpErrorMonitor;

/**
 * @level Private
 * @usage U1
 */

/**
 * This service class groups the methods that manage the connection informations
 * It is shared between CATPLMIntegration and CATPLMIntegrationUI
 */


class ExportedByCATPLMIntegrationBase CATPLMLocalSaveServices
{
public :
  /**
  * Retrieve the connection infos from the current connected provider
  * Retourne S_OK si il y a bien un provider connecte
  */
  static HRESULT GetLoginInfos(
      CATPLMRepositoryName &oConnectedRepository,
      CATOMYUnicodeStringHTab & oHTab);

  /**
  * Unstreams the HTab (in CATUnicodeString form) and fills the connection informations
  */
  static HRESULT GetCnxParameters(
      CATOmySessionImageDescriptor * iImageDescriptor,
      CATPLMConnectionParameters &oCnxParams,
      CATPLMRepositoryName & oRepName,
      CATUnicodeString & oAlias);

  /**
  * Compare the 2 htabs containing the login informations
  * @return S_OK if the connexion parameters are equal
  */
  static HRESULT CompareCnxParameters(
      CATOMYUnicodeStringHTab & iHTab1,
      CATOMYUnicodeStringHTab & iHTab2);

  /**
   * Retrieves the connection parameters from the current connected provider
   */
  static HRESULT GetCurrentCnxParameters(
      CATPLMRepositoryName &oRepName,
      CATUnicodeString & oInstanceId,
      CATPLMConnectionParameters *& oCnxParams);

  /**
   * Connects the session with the given image connection parameters
   */
  static HRESULT ConnectProviderWithImageParams(
      CATOmySessionImageDescriptor * iImageDescriptor,
      const CATUnicodeString & iPassword="");

private :
  /**
  * Fills the oHTab with the connection informations given in input
  */
  static HRESULT FillLoginInfosHTab(
      CATPLMRepositoryName & iRepo,
      const CATUnicodeString & iAlias,
      CATPLMConnectionParameters * iCnxParams,
      CATOMYUnicodeStringHTab & oHTab);
};

#endif
