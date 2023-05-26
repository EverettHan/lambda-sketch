//===================================================================
// COPYRIGHT  2019-01-14
//===================================================================
// CATPLMNLVInputHelper.cpp
// Header definition of class CATPLMNLVInputHelper
//===================================================================
//  2019-01-14 Creation: LCS2
//===================================================================

#ifndef CATPLMNLVInputHelperWrite_H
#define CATPLMNLVInputHelperWrite_H

#include "CATPLMServicesNLV.h"
#include <map>
#include <vector>
#include "CATUnicodeString.h"
#include "CATOmxJsonObject.h"
#include "CATOmxJsonArray.h"
#include "CATOmxKeyString.h"
#include "CATPLMNLVSemantic.h"
#include "CATOmxOrderedOSet.h"
#include "CATOmxList.h"
#include "CATPLMType.h"
#include "CATPLMCEStamp.h"
#include "CATPLMNLVPropertiesWrite.h"

class CATIPLMNLVInputHelperWrite;
class CATPLMTypeH;
class CATOmxAny;
class CATOmxKeyValueBlock;

class ExportedByCATPLMServicesNLV CATPLMNLVInputHelperWrite
{
public:
  // Standard constructors and destructorss
  // -------------------------------------
  CATPLMNLVInputHelperWrite(const CATOmxKeyString& iksInputFunc);
  virtual ~CATPLMNLVInputHelperWrite();

  HRESULT AddMetatype(const CATPLMType::PLMMetaType iMetatype);

  HRESULT AddCestamp(const CATUuid& iUuid, const CATPLMType::PLMMetaType iMetatype, const CATPLMCEStamp& iCestamp);

  HRESULT AddInstances(const CATOmxOrderedOSet<CATUuid>& iSetOfUuid);

  HRESULT AddOutputThenBuild(const CATOmxKeyValueBlock& iKvb);

  HRESULT AddOptions(const CATPLMNLVPropertiesWrite& iProperties);

  HRESULT AddCopyId(const CATUuid& iUuid);

  HRESULT AddAncestors(const CATUuid& iUuid, const CATPLMNLVSemantic::Intent& iSemantic);

  // Set attribute value on new object created after Copy/Cloning/Versioning operations using NLV engine
  HRESULT AddAttribute(const CATPLMTypeH& iBaseOrExtType, const CATOmxKeyString& iAttributeName, const CATOmxAny& iAttributeValue);

  // Attribute values retrieved from server after Copy/Cloning/Versioning operations using NLV engine
  // Short is name retrieved from metadata
  HRESULT AddSelect(const CATPLMTypeH& iBaseOrExtType, CATOmxOrderedOSet<CATOmxKeyString>& iSetOfShortAttributesNames);

#if !defined(_WINDOWS_SOURCE) \
           /* PLMAdapter  */ || defined(__CATPLMServicesItf) || defined(__CATPLMxNLV)
  // Attribute values retrieved from server after Copy/Cloning/Versioning operations using NLV engine
  // CATPLMLanguageToolkit, GetM1AttrOriginalName
  HRESULT AddSelectRestricted(CATOmxOrderedOSet<CATOmxKeyString>& iSetOfLongAttributesNames);
#endif

  HRESULT GetJson(CATOmxJsonObject& oJson)const;
  HRESULT Build();
private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATPLMNLVInputHelperWrite(CATPLMNLVInputHelperWrite &);
  CATPLMNLVInputHelperWrite& operator=(CATPLMNLVInputHelperWrite&);

  CATIPLMNLVInputHelperWrite* _pInputHelper;
};

#endif
