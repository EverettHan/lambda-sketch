/**
* @level Protected
* @usage U1
*/
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005
#ifndef CATPLMEnvironment_H
#define CATPLMEnvironment_H

#include "CATPLMServicesItf.h"
#include "CATPLMBaseObject.h"

// CATPLMServices
#include "CATPLMDomain.h"
#include "CATPLMOmxCollections.h"

// System
#include "CATCollec.h"

// ObjectModelerCollection
#include "CATOmxSR.h"
#include "CATOmxOMap.h"
#include "CATOmxOSet.h"
#include "CATOmxPair.h"
#include "CATOmxQIPtr.h"

// CATPLMIdentificationAccess
#include "CATPLMRepositoryName.h"
#include "CATPLMCoreType.h"

class CATUnicodeString;
class CATString;
class CATPLMType;
class CATListPtrCATPLMType;
class CATIPLMProviderDesc;
class CATPLMEnvironmentDomain;
class CATListPtrCATPLMEnvironmentDomain;
class VPMIDicEnvironment;
class CATListValCATString;
class VPMIDicMgr;

/**
* An Environment is a way to federate and specified Domains. 
* An Environment defined two notions:
* The types of components that can be examined in this environment(Queriable).
* The type of component that can be created in this environment.
* The provider should keep in session a pointer to a CATPLMEnvironment object in order to avoid heavy server exchanges.
*/
class ExportedByCATPLMServicesItf CATPLMEnvironment : public CATPLMBaseObject
{
  friend class CATPLMxMetaData;

  CATDeclareClass;
public:

  CATPLMEnvironment( const CATString & iId, const CATUnicodeString & iAlias, CATIPLMProviderDesc * iProvider );

  CATPLMEnvironment( VPMIDicEnvironment * iEnvironment, CATIPLMProviderDesc * iProvider );

  virtual ~CATPLMEnvironment();

  /**
  * Get the @href CATPLMType which is being authorized to use in creation in this environment.
  *
  * <br><b>Role</b>: Inform the user about the type of component that can be created in this environment.
  *
  * @param const CATString & iUsableModelerName [in]
  *   The domain (modeler name) in which the user wants to known the authorized kind of -PLMCoreType- to be create. (modeler name <=> PRODUCT, metadata name <=> PRODUCTCFG)
  * @param const CATString & iCoreType [in]
  *   The PLMCoreType required (PLM_Reference, PLM_Instance ...)
  * @param oType [out, CATBaseUnknown#Release]
  *   The type of component that can be created in this environment. Release the returned object when useless.
  * @return
  * <dt> <code>S_OK</code>     <dd> A @href CATPLMType is an authoring type for the provided PLMCoreType in the provided domain.
  * <dt> <code>S_FALSE</code>  <dd> No authoring type available for this PLMCoreType in the domain.
  * <dt> <code>E_FAIL</code>   <dd> Failure
  *
  */
  HRESULT GetAuthoringType( const CATString & iUsableModelerName, const CATString & iCoreType, CATPLMType ** oType );

  /**
  * Get the @href CATPLMType which can be examined by the user in this environment.
  *
  * <br><b>Role</b>: Inform the user about the types of components that can be examined in this environment. 
  *
  * @param const CATString & iModeler [in]
  *   The domain (modeler name) in which the user wants to known the authorized kind of -PLMCoreType- to be examined. (modeler name <=> PRODUCT, metadata name <=> PRODUCTCFG)
  * @param const CATString & iCoreType [in]
  *   The PLMCoreType required (PLM_Reference, PLM_Instance ...)
  * @param oTypes [out] CATLISTP_APPLY_RELEASE on list
  *   The types of components that can be examined in this environment. Release the returned objects when useless.
  * @return
  * <dt> <code>S_OK</code>     <dd> At least one @href CATPLMType is a usable type for the provided PLMCoreType in the provided domain.
  * <dt> <code>S_FALSE</code>  <dd> No usable type available for this PLMCoreType in the domain.
  * <dt> <code>E_FAIL</code>   <dd> Failure
  *
  */
  HRESULT GetUsableTypes( const CATString & iUsableModelerName, const CATString & iCoreType, CATListPtrCATPLMType & oTypes );

  /**
  * Returns the list of Modeler which defines Usable Types in this environment.
  *
  * <br><b>Role</b>: Returns the list of Modeler which defines Usable Types in this environment. 
  *
  * @param coModelerIds [out]
  *   The Modeler ids involving in this environment as Usable.
  * @return
  * <dt> <code>S_OK</code>     <dd> SuccessFul.
  * <dt> <code>E_FAIL</code>   <dd> Failure.
  *
  */
  HRESULT ListUsableModelers( CATListValCATString & oModelerIds );

  /**
  * Returns the list of Modeler which defines an Authoring Type in this environment.
  *
  * <br><b>Role</b>: Returns the list of Modeler which defines an Authoring Types in this environment. 
  *
  * @param coModelerIds [out]
  *   The Modeler ids involving in this environment as Authoring.
  * @return
  * <dt> <code>S_OK</code>     <dd> SuccessFul.
  * <dt> <code>E_FAIL</code>   <dd> Failure.
  *
  */
  HRESULT ListAuthoringModelers( CATListValCATString & oModelerIds );

  /**
  * Get the Extensions which can be examined from a specific type in this environnement.
  *
  * <br><b>Role</b>: Inform the user about the types of components that can be examined in this environment.
  *
  * @param iType [in]
  *   The type to analyse.
  * @param oExtensionList [out, CATBaseUnknown#Release]
  *   The list of extension which can be associated to this type.
  * @return
  * <dt> <code>S_OK</code>     <dd> The output list is OK. If no extension is associated to this type, the output list is empty.
  * <dt> <code>S_FALSE</code>  <dd> iType is not usable in this environment.
  * <dt> <code>E_FAIL</code>   <dd> Failure - For exmaple, if iType is an extension type.
  *
  */
  HRESULT GetUsableExtensions( const CATPLMType *iType, CATListPtrCATPLMType &oExtensionList );

  /**
  *	Adds the EnvironmentDomain inside the Environment
  * @param iEnvDomain [in, CATBaseUnknown#Release]
  *    The CATPLMEnvironmentDomain.
  */
  HRESULT AddEnvironmentDomain( CATPLMEnvironmentDomain * iEnvDomain);

private:
  HRESULT _GetEnvironmentDomain( const CATString iEnvDomainId, CATPLMEnvironmentDomain ** oEnvDomain);

  HRESULT _GetEnvironmentAuthoringDomain ( const CATString iDomainId, CATPLMEnvironmentDomain ** oEnvDomain);

  // A list of domain (<=>Package) is associated to each environment. We need to build domain and then associate them to current environment
  HRESULT _BuildDomain(const CATUnicodeString& iUsableModelerName);

  HRESULT _BuildAuthoringDomain(const CATUnicodeString& iAuthoringPackageName);

  HRESULT _BuildMapUsableModelerNameWithPairUsableAndAuthoringPackageName();

  HRESULT _BuildMapUsableModelerNameWithPairUsableAndAuthoringPackageName(const CATUnicodeString& iPackageName);

  HRESULT _BuildAuthoringPackageNames();

  HRESULT _GetUsableModelerNameUsablePackageNameAuthoringPackageName(const CATUnicodeString& iPackageName,CATUnicodeString& oUsableModelerName,CATUnicodeString& oUsablePackageName,CATUnicodeString& oAuthoringPackageName);

  CATOmxOMap<CATOmxKeyString,CATPLMEnvironmentDomain*,naive_manager,com_manager> _mapPackageNameWithEnvDomain;
  CATPLMRepositoryName _RepoName;

  CATOmxSR<VPMIDicEnvironment>  _spEnvironment;

  CATPLMRepositoryName _repo;

  CATOmxSR<VPMIDicMgr> _spDicMgr;

  CATOmxOMap<CATOmxKeyString,CATPLMEnvironmentDomain*,naive_manager,com_manager > _mapModelerNameWithEnvDomainAlreadyLoaded;

  CATOmxOSet<CATOmxKeyString> _availableAuthoringPackageNameSet;

  //eg:          PRODUCT          ,          <    PRODUCTCFG      ,  PLMProductDS        >
  //         Usable Modeler Name  ,          <Usable Package Name ,Authoring Package Name> >
  CATOmxOMap<CATOmxKeyString,CATPLMPairKSKS> _mapUsableModelerNameWithPairUsableAndAuthoringPackageName;
  CATOmxOMap<CATOmxKeyString,CATOmxKeyString> _mapAuthoringPackageNameWithUsableModelerName;

  static CATLONG32 _nb;

  CATPLMKSSet _ModelerNameSet;
};
#endif
