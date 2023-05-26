#ifndef __CATOmbPLMStreamDescriptorBridge_H
#define __CATOmbPLMStreamDescriptorBridge_H

#include "CATOmbSwitchEngine.h"
#include "CATPLMID.h"
#include "CATOmxArray.h"
#include "CATOmxSharable.h"
struct CATOmbStreamDescriptorQualifiers;
class CATIPLMRecordRead;
class CATIPLMIntegRecordRead;

struct ExportedByCATOmbSwitchEngine CATOmbDBSDs: public CATOmxSharable
{
  CATPLMID PLMID;
  CATOmxArray<CATOmbStreamDescriptorQualifiers> SDs;
  virtual ~CATOmbDBSDs();
};

/**
 * Bridge to CATPLMStreamDescriptor framework
 * (Mainly because of missing prereq on CATPLMComponentServices)
 */
class CATOmbPLMStreamDescriptorBridge
{
public:
  virtual CATOmxIter<CATOmbDBSDs> QuerySDsInDB(CATOmxIter<const CATPLMID>& iPLMDIDs,int iIsIteration) = 0;

  virtual HRESULT GetOmbSDsInfosFromRecord(CATIPLMRecordRead* iRecordRead,CATIPLMIntegRecordRead* iIntegRecordRead,CATOmxArray<CATOmbStreamDescriptorQualifiers>& SDsQualifiers) = 0;

  static CATOmbPLMStreamDescriptorBridge* Get();
};


#endif
