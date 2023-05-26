#ifndef CATPLMDicPathTypeCstDef_H
#define CATPLMDicPathTypeCstDef_H

#include "CATPLMServicesItf.h"

//system
#include "CATBoolean.h"

#include "CATOmxKeyString.h"
#include "CATOmxOSet.h"

class ExportedByCATPLMServicesItf CATPLMDicPathTypeCstDef
{
public:
  //s() like singleton...
  static const CATPLMDicPathTypeCstDef& s();

  CATOmxKeyString ksPathType;
  CATUnicodeString PathType;
  CATOmxKeyString ksSemanticRelation;
  CATUnicodeString SemanticRelation;
  CATOmxKeyString kselementdotorder;
  CATOmxKeyString kselement;
  CATOmxKeyString ksIDRel;
  CATOmxKeyString ksRole;
  CATOmxKeyString ksSemantics;
  CATOmxKeyString ksRoleSemantics;
  CATOmxKeyString ksAppIndex;
  CATOmxKeyString ksPrivateData;
  CATOmxKeyString ksSyncDomain;
  CATOmxKeyString ksSyncSpec;
  CATOmxKeyString ksSyncValue;
  CATOmxKeyString ksOutOfScopes;
  CATOmxKeyString ksownerdotphysicalid;
  CATOmxKeyString ksownerdottype;
  CATOmxKeyString ksid;//id (pathtype) <= > physicalid (bo / connection)
  CATOmxKeyString ksinterface;
  CATOmxKeyString ksLastPIDAndRole;
  CATOmxKeyString kselementdotphysicalid;
  CATOmxKeyString kselementdottype;
  CATUnicodeString elementdotphysicalid;
  CATUnicodeString elementdottype;

  ~CATPLMDicPathTypeCstDef();

  CATBoolean IsMandAttr(const CATOmxKeyString& iAttributeName,CATBoolean iIsKindOfSR,CATBoolean iIsSlimSRActivated) const;

private:
  CATPLMDicPathTypeCstDef();

  CATPLMDicPathTypeCstDef (const CATPLMDicPathTypeCstDef &);
  CATPLMDicPathTypeCstDef& operator=(const CATPLMDicPathTypeCstDef&);

  CATOmxOSet<CATOmxKeyString> _SetOfMandatoryAttrForSRWithSlimSR,_SetOfMandatoryAttrForSRWithoutSlimSR,_SetOfMandatoryAttrForPathType;
};

#endif
