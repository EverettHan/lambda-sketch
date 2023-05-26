/**
 * @level Private
 * @usage U1
 */
#ifndef CATVVSPLMAndVaultSiteManager_H
#define CATVVSPLMAndVaultSiteManager_H

#include "VVSStreamConsumer.h"

#include "CATVVSVaultSiteDescriptorDefinition.h"
#include "CATVVSUrl.h"

#include "CATUuid.h"

/**
 * It is in charge to manage the VaultSite and the PLMSite.
 * The Code of the PDM uses this manager in order to :
 *  - declare its VaultSite
 *  - declare itself.
 * Declaring means giving its identity , its type, its version and
 * some declarative properties
 *
 * Some VaultSite ( like cache) are declared by the System
 */
class ExportedByVVSStreamConsumer CATVVSPLMAndVaultSiteManager
{

  public:

 /**
  * <dl>
  * <dt><b>Registrate a vault site</b>
  *
  *   @param iNewVaultSiteDescriptorDefinition
  *      The vault site descriptor, must not be NULL
  *
  *   @param oIdentifier
  *      The vault site identifier
  *
  * <pre>
  *   @return
  *     S_OK           : Succeeded
  *     S_FALSE        : Soft component is not registered probably because soft component
  *                      implementation has not been found
  *     E_FAIL         : Unexplained failure
  *     E_INVALIDARG   : If iNewVaultSiteDescriptorDefinition is NULL
  * </pre>
  * </dl>
  */
  HRESULT RegisterVaultSiteDescriptorDefinition(CATVVSVaultSiteDescriptorDefinition* iNewVaultSiteDescriptorDefinition,int& oIdentifier) ;

 /**
  * <dl>
  * <dt><b>unregistrate a vault site</b>
  *
  *   @param iIdentifier
  *      The vault site identifier
  *
  * <pre>
  *   @return
  *     S_OK           : Succeeded
  *     E_FAIL         : Unexplained failure
  * </pre>
  * </dl>
  */
  HRESULT UnregisterVaultSiteDescriptor (int iIdentifier);

  HRESULT FindIndexOfVaultSiteInChargeofUrl(const CATVVSUrl& iUrl,int& oIndex) ;

  HRESULT GetRegisteredVaultSites(CATListOfCATUnicodeString& oInstNames);

  HRESULT GetVaultSiteInformations(int iIdentifierId, CATUnicodeString& oInstName, CATUnicodeString& oCptName, CATUnicodeString& oVersion);
  /**
   * Return the index of a registered vault site
   * @param iCacheName [in]
   *   The name of the vault site.
   * @param oIndex [out]
   *   The index of the vault site.
   *
   * @return
   *  <UL>
   *    <LI><code>S_OK</code> if everything ran ok.</LI>
   *    <LI><code>E_FAIL</code> if an error occurs or if a vault site with the given name dos not exist.</LI>
   *  </UL>
   */
  HRESULT FindIndexOfVaultSiteFromName(const CATUnicodeString& iName, int& oIndex);

  /**
   * Gets a property of a Vault site.<BR/>
   * <B>Role:</B> Properties of a vault site are defined at its registration.
   * @param iIdentifier
   *  The Identifier of the vault site.
   * @param iPropertyKey
   *  The key of the vault site
   * @param oPropertyKey
   *  The content of the property.
   */
  HRESULT GetVaultSiteProperty(int iIdentifier, const CATUnicodeString& iPropertyKey, CATUnicodeString& oPropertyKey);

  /**
   * Sets a property of a Vault site.<BR/>
   * <B>Role:</B> Properties of a vault site are defined at its registration.
   * @param iIdentifier
   *  The Identifier of the vault site.
   * @param iPropertyKey
   *  The key of the vault site
   * @param oPropertyKey
   *  The content of the property.
   */
  HRESULT SetVaultSiteProperty(int iIdentifier, const CATUnicodeString& iPropertyKey, const CATUnicodeString& iPropertyValue);

  /**
  * Retrieves the UUID needed to disable the history functionnality.
  * <B>Role:</B> With this UUID, the caller gets the possibility to disable
  * historization if it is allowed to
  * @param oUuid
  *  The uuid the caller has to record
  */
  HRESULT RetrieveNoHistoryUuid(CATUuid& oUuid);
  
  /**
  * INTERNAL service do not use
  * 
  * register PW or AW vautl Site in Asynchronous Process and debug tools
  **/
  HRESULT ForcePowerIORegistration(CATUnicodeString& CacheName, CATUnicodeString& iCachePath);
   
  CATVVSPLMAndVaultSiteManager();
  ~CATVVSPLMAndVaultSiteManager();

  private:

  /**
  * Check if the no history functionnality is enabled or not.
  * @return the taken decision.
  *   If S_OK : Enable the non historization, meaning disable historization
  *   If S_FALSE : Enable historization
  */
  HRESULT CheckNoHistoryUuidRecord() const;
};

#endif

