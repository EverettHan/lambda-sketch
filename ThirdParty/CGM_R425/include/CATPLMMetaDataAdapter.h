//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
// CATPLMMetaDataAdapter.h
// Define the CATPLMMetaDataAdapter adapter
//===================================================================
// Usage notes:
//   adapter for interface CATIPLMMetaData
//===================================================================
// Feb 2009
// Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMMetaDataAdapter_H
#define CATPLMMetaDataAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMMetaData.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll
#include "CATPLMEnvironment.h"
#include "CATPLMOmxCollections.h"

#include "CATListOfCATUnicodeString.h"
#include "CATBoolean.h"

#include "CATOmxKeyString.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxOMap.h"
#include "CATOmxOSet.h"
#include "CATOmxOrderedOSet.h"

class CATPLMTypeId;
class VPMIDicMgr;
class CATIPLMProviderDesc;
class CATListPtrCATPLMType;
class CATPLMDomain;
class VPMIDicEnvironment;
class VPMIDicExtension;

/**
 * gives an adapter to the interface CATIPLMMetaData
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMMetaDataAdapter : public CATIPLMMetaData
{
public:
  CATPLMMetaDataAdapter();
  virtual ~CATPLMMetaDataAdapter();

  /** 
  * @nodoc
  */
  virtual HRESULT LoadDomain(CATString *iDomainId, CATPLMDomain **oDomain);

  /** 
  * @nodoc
  */
  virtual HRESULT LoadDomains (const CATListValCATString  & iDomainIds  , CATListPtrCATPLMDomain & oDomains);

  /** 
  * @nodoc
  */
  virtual HRESULT GetDomain(CATString *iDomainId, CATPLMDomain **oDomain);

  /** 
  * @nodoc
  */
  virtual HRESULT ListDomains(CATListValCATString **oDomainId, CATListValCATUnicodeString **oDomainAlias);

  /** 
  * @nodoc
  */
  virtual HRESULT ListEnvironments( CATListValCATString & oEnvId, CATListValCATUnicodeString & oEnvAlias);

  /** 
  * @nodoc
  */
  virtual HRESULT LoadEnvironment( const CATString & iEnvId, CATPLMEnvironment** oppEnvironment );

  /** 
  * @nodoc
  */
  virtual HRESULT GetEnvironment(const CATString & iEnvId, CATPLMEnvironment** oppEnvironment);

  /** 
  * @nodoc
  */
  virtual HRESULT ListModelers( CATListValCATString & oModelerId, CATListValCATUnicodeString & oModelerAlias );

  /** 
  * @nodoc
  */
  virtual HRESULT LoadModeler( const CATString & iModelerId, CATListPtrCATPLMType & oTypes );

  /** 
  * @nodoc
  */
  virtual HRESULT GetModeler(const CATString & iModelerId, CATListPtrCATPLMType & oTypes );

  /** 
  * @nodoc
  */
  virtual HRESULT GetPLMTypeFromTypeId( const CATPLMTypeId iTypeId, CATPLMType ** oType);

  /** 
  * @nodoc
  */
  virtual HRESULT ListSiteNames(CATListValCATUnicodeString * oSiteNames);

  /** 
  * @nodoc
  */
#ifdef CATIAR418
  virtual HRESULT AddExtension(VPMIDicExtension* ipExtensionType);
#endif
  /** 
  * @nodoc
  */
#ifdef CATIAR418
  virtual HRESULT EnrichExtension(VPMIDicExtension* ipExtensionType);
#endif
  virtual HRESULT SwitchSecurityContext(CATPLMType* ipType);

  virtual HRESULT BuildMaskForPackage(const CATUnicodeString& iPackageName);

  virtual HRESULT ListDomains(CATListValCATString& olDomainId,CATListValCATUnicodeString& olDomainAlias);

  virtual HRESULT ListDomains(CATPLMDomainList& olDomain,CATBoolean isCheckVisibilityActivated = FALSE);

  virtual CATBoolean IsMetadataLoaded() const;

  virtual CATBoolean IsAdminLoaded() const;

  virtual void CleanUp();

protected:
  /*
  * @param oppEnvironment [out, CATBaseUnknown#Release]
  */
  HRESULT _LoadEnvironment( VPMIDicMgr* ipDicMgr,
                            CATIPLMProviderDesc* ipProvider,
                            const CATString & iEnvId,
                            CATPLMEnvironment** oppEnvironment );

  HRESULT _ListEnvironments(VPMIDicMgr* ipDicMgr,
                            CATListValCATString & oEnvId,
                            CATListValCATUnicodeString & oEnvAlias);

  /*
  * @param oppEnvironment [out, CATBaseUnknown#Release]
  */
  HRESULT _GetEnvironment(const CATString & iEnvId, CATPLMEnvironment** oppEnvironment);

  HRESULT _InitEnvironmentsLists(VPMIDicMgr* ipDicMgr);

  /**
  * @param <tt> VPMIEnvironment &iVPMEnvironment </tt>
  * [in] iVPMEnvironment
  * @return
  * <tt>HRESULT</tt>
  * <dl>
  * <dt> <tt>S_OK</tt>     <dd> Successfully processed the EnvironmentList for given iVPMEnvironment
  * <dt> <tt>E_FAIL</tt>  <dd> Failed to retrieve the ModelerList for given ModelerId
  * </dl>
  */
  HRESULT _ProcessEnvironment(CATIPLMProviderDesc* ipProvider,VPMIDicEnvironment * iVPMEnvironment);

  HRESULT _InitModelersLists(VPMIDicMgr* ipDicMgr);

  HRESULT _ListModelers( VPMIDicMgr* ipDicMgr,CATListValCATString & oModelerId,CATListValCATUnicodeString & oModelerAlias);

  HRESULT _LoadModeler(  VPMIDicMgr* ipDicMgr,const CATString & iModelerId,CATListPtrCATPLMType & oTypes );

  HRESULT _GetModeler(const CATString & iModelerId,CATListPtrCATPLMType & oTypes );

  HRESULT _SetDomain(CATPLMDomain* iDomain);

  HRESULT _GetDomain (CATString * iDomainId , CATPLMDomain ** oDomain);

  HRESULT _ListDomains ( VPMIDicMgr* ipDicMgr,
                         CATListValCATString ** oDomainId ,
                         CATListValCATUnicodeString ** oDomainAlias);

  HRESULT _InitDomainsLists(VPMIDicMgr* ipDicMgr);

  void _CleanUpEnvs();

  void _CleanUpModelers();

  void _CleanUpDomains();

private:
  HRESULT _ProcessModeler(VPMIDicMgr* ipDicMgr,const CATString & iModelerId);

  CATBoolean _IsAllMetadataLoadedOnConnectedProviders() const;

  CATBoolean _IsAllAdminLoadedOnConnectedProviders() const;

  CATUnicodeString _ListConnectedProviders() const;

  // the cached list of envronment. Populated during GetModeler & LoadModeler.
  CATPLMKeyStringToPLMEnv _mEnvNameWithPLMEnv;
  CATOmxOrderedOSet<CATOmxKeyString> _orderedEnv;//for fucking existing odts in fucking RECORD mode...

  CATBoolean _IsInitEnvListAlreadyProcessed;
  CATUnicodeString _ListConnectedProvForInitEnv;

  CATBoolean _IsModelerListAlreadyProcessed;
  CATUnicodeString _ListConnectedProvForModelerList;

  CATPLMKeyStringToPairIntListOfType _mapModelerWithPairBuildStatusListOfType;

  // the cached list of CATPLMDomains. Populated only once (expect if RemoveDomains is called).
  CATPLMKeyStringToPLMDomain _DomainList;

  // the cached list of domain IDs. Populated only once (expect if RemoveDomains is called).
  CATBoolean _IsInitDomainsListsAlreadyProcessed;
  CATUnicodeString _ListConnectedForDomainsLists;

  CATPLMStringToPairStringString _mapDomainIdWithPairDomainIdDomainAlias;

  CATPLMMetaDataAdapter (CATPLMMetaDataAdapter &);
  CATPLMMetaDataAdapter& operator=(CATPLMMetaDataAdapter&);
};

#endif
