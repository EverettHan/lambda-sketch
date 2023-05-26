#ifndef CATPLMChangeLogDesc_H
#define CATPLMChangeLogDesc_H

#include "CATPLMServicesItf.h"
#include "CATPLMOmxCollections.h"

#include "CATSysErrorDef.h"

#include "CATOmxSR.h"
#include "CATOmxKeyString.h"
#include "CATOmxArray.h"

class CATPLMChangeLogDescInt;

class ExportedByCATPLMServicesItf CATPLMChangeLogDesc
{
public:
  static const CATPLMChangeLogDesc &s();

  ~CATPLMChangeLogDesc();

  const CATOmxKeyString& GetChangeLogName() const;

  const CATOmxArray<CATOmxKeyString>& ListMasterAttrName() const;

  const CATOmxArray<CATOmxKeyString>& ListDetailAttrName() const;

  const CATOmxArray<CATOmxKeyString>& ListViewAttrName() const;

  const CATOmxArray<CATOmxKeyString>& ListActionTargetName() const;

  const CATOmxArray<CATOmxKeyString>& ListActionPhysicalIdName() const;

  const CATOmxKeyString ksActionPhysicalId,ksActionLogicalId,ksActionMajorId,ksActionType,ksActionTypeKindOf;
  const CATOmxKeyString ksCompCES;
  const CATOmxKeyString ksuser,ksorganization,ksproject;
  const CATOmxKeyString kscomment;
  const CATOmxKeyString ksmodificationDate;
  const CATOmxKeyString ksTargetPhysicalId,ksTargetLogicalId,ksTargetMajorId,ksTargetType,ksTargetTypeKindOf;
  const CATOmxKeyString ksrowuuid,ksmasterrowuuid/*write*/,ksmrowuuid/*read selectable*/;
  const CATOmxKeyString ksOwnerPhysicalId,ksOwnerLogicalId,ksOwnerMajorId,ksOwnerType,ksOwnerTypeKindOf;
  const CATOmxKeyString ksInstanceOfPhysicalId,ksInstanceOfLogicalId,ksInstanceOfMajorId,ksInstanceOfType,ksInstanceOfTypeKindOf;
  const CATOmxKeyString ksoperation;
  const CATOmxKeyString ksoperationData;
  const CATOmxKeyString ksuserfactName;// master
  const CATOmxKeyString ksuserdata;// master
  const CATOmxKeyString ksorder;// master
  const CATOmxKeyString ksstatus;// master
  const CATOmxKeyString ksoriginated;
  const CATOmxKeyString ksmodified;

  const CATOmxKeyString ksDerivedFromPhysicalId,ksDerivedFromLogicalId,ksDerivedFromMajorId,ksDerivedFromType,ksDerivedFromTypeKindOf;

private:
  CATPLMChangeLogDesc();

  CATPLMChangeLogDesc (CATPLMChangeLogDesc &);
  CATPLMChangeLogDesc& operator=(CATPLMChangeLogDesc&);

  const CATOmxKeyString ksChangeLog;
  CATOmxArray<CATOmxKeyString> _lViewAttrDesc,_lMasterAttrDesc,_lDetailAttrDesc,_lActionIdTargetId,_lActionPhysicalId;
};

#endif
