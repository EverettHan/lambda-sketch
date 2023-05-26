// COPYRIGHT Dassault Systemes 2014
//===================================================================
//
// CATPLMDictionaryStream
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// November 2014  Creation: EPB
//===================================================================
#ifndef CATPLMDictionaryStream_H
#define CATPLMDictionaryStream_H

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfCATString.h"
#include "CATIPLMProviderDesc.h"

#include "CATPLMRepositoryName.h"

#include "CATPLMServicesItf.h"

#include "CATOmxOSet.h"
#include "CATOmxSR.h"

class ExportedByCATPLMServicesItf CATPLMDictionaryStream
{
friend class CATPLMxMetaData;
friend class CATPLMEnvironment;
private:
  CATPLMDictionaryStream();
  ~CATPLMDictionaryStream();

  HRESULT SetRepository(const CATPLMRepositoryName& iRepo);

  HRESULT IsAllStreamLoaded();

  HRESULT ListAvailablePackagesInPartialStream(CATListValCATString& oListAvailablePackages);

  HRESULT ListAvailablePackages(const CATListOfCATUnicodeString& iPackageNameList,CATListOfCATUnicodeString& oAvailableAuthoringPackageNameList,CATBoolean isErrorRaised);

  HRESULT IsAvailablePackage(const CATUnicodeString& iPackageName);

  HRESULT IsAvailablePackage(const CATListValCATString& iPackageNameList);

private:
  HRESULT _ListAvailablePackagesInPartialStream(CATOmxOSet<CATUnicodeString>& oListAvailablePackages);

  static CATOmxOSet<CATUnicodeString> _availableDomainSet;
  CATPLMRepositoryName _repo;
};

#endif
