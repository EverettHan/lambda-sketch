#ifndef CATPLMLoaderUtils_H
#define CATPLMLoaderUtils_H

#include "CATOmxList.h"
#include "CATOmxOMap.h"
#include "CATListOfCATUnicodeString.h"

#include "CATSysErrorDef.h"

#include "CATPLMServicesItf.h"

class CATIPLMProviderDesc;
class CATUnicodeString;
class CATIPLMCompConnectionInstance;
class CATPLMRepositoryName;
class CATIPLMProviderMgr;
class CATOMYUnicodeStringHTab;
class CATIPLMCompContentMngtInstance;

class ExportedByCATPLMServicesItf CATPLMConnectionTools
{
public:
  static HRESULT GetRepoOfAllConnectedProv(CATUnicodeString& oKey);

  /**
  *
  * <br><b>Role</b>:
  * @param iRepositoryName
  *        iRepositoryName==CATPLMRepositoryName_Null <=> all connected providers
  * @param olInstReallyConnected
  *
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  static HRESULT ListOfConnectedProviderInst(const CATPLMRepositoryName& iRepositoryName, CATOmxList<CATIPLMCompConnectionInstance>& olInstReallyConnected);

  /**
  *
  * <br><b>Role</b>:
  * @param iRepositoryName
  *        iRepositoryName==CATPLMRepositoryName_Null <=> all connected providers
  * @param oListProvDesc
  *
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  static HRESULT ListOfConnectedProviderDesc(const CATPLMRepositoryName& iRepositoryName, CATOmxList<CATIPLMProviderDesc> & oListProvDesc);
  static HRESULT ListOfConnectedProviderDesc(const CATPLMRepositoryName& iRepositoryName, CATListOfCATUnicodeString & oListProv);
  static HRESULT ListOfConnectedProviderDesc(const CATPLMRepositoryName& iRepositoryName, CATIPLMProviderMgr* ipProvMgr, CATOmxList<CATIPLMProviderDesc> & oListProvDesc);
  static HRESULT ListOfConnectedProviderDesc(const CATPLMRepositoryName& iRepositoryName, CATIPLMProviderMgr* ipProvMgr, CATListOfCATUnicodeString & oListProv);

  /*
  * Returns the first connected provider in the connected provider list, for the given repository.
  * It assumes that we are connected to only one provider.
  * It logs a warning if more than one provider are connected.
  *
  * @param iRepositoryName
  *        iRepositoryName==CATPLMRepositoryName_Null <=> all connected providers.
  * @param oProviderDesc [out, IUnkown#Release]
  *        The provider desc, must be released.
  *
  * @return
  * <dt> <code>S_OK</code>       <dd> The connected provider retrieved
  * <dt> <code>S_FALSE</code>    <dd> More than one provider connected, first one returned
  * <dt> <code>E_FAIL</code>     <dd> Cannot retrieve the connected provider
  */
  static HRESULT GetConnectedProviderDesc(const CATPLMRepositoryName& iRepositoryName, CATIPLMProviderDesc*& oProviderDesc);

  static CATBoolean IsConnectedTo(const CATPLMRepositoryName& iRepositoryName);

  static HRESULT GetSecurityContextWithUuid(const CATPLMRepositoryName& iRepositoryName, CATUnicodeString& oSecurityContextWithUuid);

  static HRESULT GetSecurityContextWithUuid(CATIPLMProviderDesc *ipProvDesc, CATUnicodeString& oSecurityContextWithUuid);

  static HRESULT GetSecurityInfos(const CATPLMRepositoryName& iRepositoryName, CATUnicodeString& oUserId, CATUnicodeString& oSecurityContext, CATUnicodeString& oSecurityContextUuid, CATUnicodeString& oRoleId, CATUnicodeString& oOrgId, CATUnicodeString& oProjectId);

  static HRESULT GetSecurityInfos(CATIPLMProviderDesc *ipProvDesc, CATUnicodeString& oUserId, CATUnicodeString& oSecurityContext, CATUnicodeString& oSecurityContextUuid, CATUnicodeString& oRoleId, CATUnicodeString& oOrgId, CATUnicodeString& oProjectId);

  static HRESULT SetSecurityInfos(const CATUnicodeString& iUserId, const CATUnicodeString& iSecurityContext, const CATUnicodeString& iSecurityContextUuid, const CATUnicodeString& iRole, const CATUnicodeString& iOrganization, const CATUnicodeString& iProject, CATOMYUnicodeStringHTab& iohtab);

  static HRESULT ListOfConnectedContentMngtInstance(CATOmxList<CATIPLMCompContentMngtInstance>& oListContentMngtInstance);

  /*
  * Returns the first connected PLM1 ContentMngtInstance in the connected provider list
  * It assumes that we are connected to only one provider.
  * It logs a warning if more than one provider are connected.
  *
  * @param oContentMngtInstance [out, IUnknown#Release]
  *        The instance, must be released.
  *
  * @return
  * <dt> <code>S_OK</code>       <dd> The connected Instance retrieved
  * <dt> <code>S_FALSE</code>    <dd> More than one Instance connected, first one returned
  * <dt> <code>E_FAIL</code>     <dd> Cannot retrieve the connected Instance
  */
  static HRESULT GetConnectedContentMngtInstance(CATIPLMCompContentMngtInstance*& oContentMngtInstance);

  static CATBoolean IsOnCloud(const CATPLMRepositoryName& iRepositoryName);

  static CATBoolean IsConnectedToCloud(const CATPLMRepositoryName& iRepositoryName);

  static CATUnicodeString GetTenant(const CATPLMRepositoryName& iRepositoryName);

  //@deprecated replaced by GetSecurityInfos
  static HRESULT GetSecurityContextAndUuid(const CATPLMRepositoryName& iRepositoryName, CATUnicodeString& oSecurityContext, CATUnicodeString& oSecurityContextUuid);

private:
  static CATBoolean _IsOnCloud(CATBoolean iCheckConnectedState, const CATPLMRepositoryName& iRepositoryName);

  static CATUnicodeString _GetTenant(CATBoolean iCheckConnectedState, const CATPLMRepositoryName& iRepositoryName);

  static HRESULT _GetSecurityContext(const CATPLMRepositoryName& iRepositoryName, CATUnicodeString& oSecurityContext);

  static HRESULT _GetSecurityContext(CATIPLMProviderDesc *ipProvDesc, CATUnicodeString& oSecurityContext);

  static HRESULT _GetSecurityContextUuid(const CATPLMRepositoryName& iRepositoryName, CATUnicodeString& oSecurityContextUuid);

  static HRESULT _GetSecurityContextUuid(CATIPLMProviderDesc *ipProvDesc, CATUnicodeString& oSecurityContextUuid);

};

#endif
