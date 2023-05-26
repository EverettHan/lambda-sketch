#ifndef CATPLMElementH_H
#define CATPLMElementH_H

#include "CATPLMIdentificationAccess.h"

#include "CATPLMID.h"

#include "CATPLMPathDataCst.h"

#include "CATOmxAny.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxSR.h"

class CATPLMElementInt;

class ExportedByCATPLMIdentificationAccess CATPLMElementH
{
public:
  CATPLMElementH();

  // iUpdateStamp <=> updatestamp of iPlmid stored like:
  //                  a- a CATUuid in CATOmxAny (CATOmxAny::SetUuid(const CATUuid& iUuid)) 
  //                  or
  //                  b- like a string (if it is stored like a string, conversion is made to convert into a CATUuid)
  //
  // By default:
  // _relevancyStatus = CATPLMPathDataCst::not_relevant
  // _syncStatus = CATPLMPathDataCst::NotValuated
  // _relevancyStatus == CATPLMPathDataCst::not_relevant means that BY DEFAULT, _syncStatus WON'T BE COMPUTED!!!
  //
  // To compute _syncStatus, please use SetRelevanceStatus(CATPLMPathDataCst::relevant)
  CATPLMElementH(const CATPLMID& iPlmid,const CATOmxAny& iUpdateStamp);

  // Suppose you update a path element, you specify a modification of element found at position: iPosition. iPosition start at 0.
  CATPLMElementH(const CATPLMID& iPlmid, const CATOmxAny& iUpdateStamp,int iPosition);

  ~CATPLMElementH();

  // lazy copy
  // eg:
  // CATPLMElementH A(...)
  // CATPLMElementH B(A);
  // B and A share the same data
  CATPLMElementH(const CATPLMElementH& iSource);

  // lazy copy
  // eg:
  // CATPLMElementH A(...)
  // CATPLMElementH B = A;
  // B and A share the same data
  CATPLMElementH& operator = (const CATPLMElementH& iSource);

  // Copy
  // CATPLMElementH A(...)
  // CATPLMElementH B;
  // B.Clone(A);
  // B and A have their own content
  HRESULT Clone(const CATPLMElementH& iSource);

  int operator == ( const CATPLMElementH & iOther ) const;

  int operator != ( const CATPLMElementH & iOther ) const;

  const CATPLMID& GetPlmid() const;

  const CATOmxAny& GetUpdateStamp() const;

  // copy on write is implemented
  // Suppose you have:
  // CATPLMElementH A;
  // CATPLMElementH B = A;
  // A and B share same data
  // Suppose you do A.SetRelevanceStatus(...)
  // A and B don't share same data anymore
  HRESULT SetRelevanceStatus(CATPLMPathDataCst::RelevanceStatus iRelevanceStatus);

  CATPLMPathDataCst::RelevanceStatus GetRelevanceStatus() const;

  // copy on write is implemented
  // Suppose you have:
  // CATPLMElementH A;
  // CATPLMElementH B = A;
  // A and B share same data
  // Suppose you do A.SetSynchroStatus(...)
  // A and B don't share same data anymore
  HRESULT SetSynchroStatus(CATPLMPathDataCst::SynchroStatus iSyncStatus);

  CATPLMPathDataCst::SynchroStatus GetSynchroStatus() const;

  // Returned position start at 0
  int GetPosition() const;
private:
  HRESULT _CloneIfNecessary();

  CATPLMElementInt* _Clone(CATPLMElementInt* ipElementInt);

  CATOmxSR<CATPLMElementInt> _spElemInt;
};

extern const ExportedByCATPLMIdentificationAccess CATPLMElementH CATPLMElementH_Null;

template <> CATOmxCollecManager & CATOmxDefaultCollecManager <CATPLMElementH>::manager();

typedef CATOmxArray<CATPLMElementH,CATOmxDefaultCollecManager<CATPLMElementH>::manager> CATPLMElementHArray;

#endif
