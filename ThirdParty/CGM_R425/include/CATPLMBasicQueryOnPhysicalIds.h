// COPYRIGHT Dassault Systemes 2018
//===================================================================
//
// CATPLMBasicQueryOnPhysicalIds.h
// Header definition of CATPLMBasicQueryOnPhysicalIds
//
//===================================================================
//
// Usage notes:
// described an object type manages by the provider.
//
//===================================================================
//  June 2018  Creation: EPB
//===================================================================
#ifndef CATPLMBasicQueryOnPhysicalIds_H
#define CATPLMBasicQueryOnPhysicalIds_H

#include "CATPLMServicesItf.h"

#include "CATOmxArray.h"
#include "CATPLMOmxCollections.h"
#include "CATOmxAutoPtr.h"

#include "CATPLMRepositoryName.h"

#include "CATPLMAsyncId.h"

class CATIPLMBasicQueryOnPhysicalIds;
class CATXMQLRequestSelector;
class CATUuid;
class CATIPLMCompRecordReadSet;
class CATUnicodeString;
class CATPLMAsyncId;

class ExportedByCATPLMServicesItf CATPLMBasicQueryOnPhysicalIds
{
public:
  CATPLMBasicQueryOnPhysicalIds();
  ~CATPLMBasicQueryOnPhysicalIds();

  HRESULT Init(const CATPLMRepositoryName& iRepositoryName, const CATPLMAsyncIdSet& iSetOfAsyncId, const CATPLMKSSet& iBoSetOfBasicAttributes = CATPLMKSSet_Empty, const CATPLMKSSet& iRelSetOfBasicAttributes = CATPLMKSSet_Empty);

  HRESULT Init(const CATPLMRepositoryName& iRepositoryName, const CATOmxOSet<CATUnicodeString>& iSetOfPhysicalId, const CATPLMKSSet& iBoSetOfBasicAttributes = CATPLMKSSet_Empty, const CATPLMKSSet& iRelSetOfBasicAttributes = CATPLMKSSet_Empty);

  HRESULT Init(const CATPLMRepositoryName& iRepositoryName, const CATOmxArray<CATUnicodeString>& iListOfPhysicalId, const CATPLMKSSet& iBoSetOfBasicAttributes = CATPLMKSSet_Empty, const CATPLMKSSet& iRelSetOfBasicAttributes = CATPLMKSSet_Empty);

  /*
  * Suppose CATPLMBasicQueryOnPhysicalIds has been called with iListOfPhysicalId.Size() == 0, then Execute returns a CATIPLMCompRecordReadSet with 0 RecordRead:
  * CATOmxSR<CATIPLMRecordRead> spRecordRead;
  * opRecordReadSet->Next(&spRecordRead) == S_FALSE && spRecordRead == NULL
  */
  HRESULT Execute(CATIPLMCompRecordReadSet*& opRecordReadSet);

private:
  static CATIPLMBasicQueryOnPhysicalIds* _GetToolsFactory(const CATPLMRepositoryName& irepository);

  CATPLMRepositoryName _repositoryName;

  CATOmxAutoPtr<CATIPLMBasicQueryOnPhysicalIds> spBasicQuery;

  // The copy constructor and the equal operator must not be implemented
  // -------------------------------------------------------------------
  CATPLMBasicQueryOnPhysicalIds(CATPLMBasicQueryOnPhysicalIds &);
  CATPLMBasicQueryOnPhysicalIds& operator=(CATPLMBasicQueryOnPhysicalIds&);
};

#endif
