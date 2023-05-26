//===================================================================
// COPYRIGHT  2021-10-19
//===================================================================
// CATPLMNLVInputHelperRead.cpp
// Header definition of class CATPLMNLVInputHelperRead
//===================================================================
//  2021-10-19 Creation: JSL7
//===================================================================

#ifndef CATPLMNLVInputHelperRead_H
#define CATPLMNLVInputHelperRead_H

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
#include "CATPLMNLVPropertiesRead.h"

class CATIPLMNLVInputHelperRead;
class CATPLMTypeH;
class CATOmxAny;
class CATOmxKeyValueBlock;

class ExportedByCATPLMServicesNLV CATPLMNLVInputHelperRead
{
public:
  // Standard constructors and destructorss
  // -------------------------------------
  CATPLMNLVInputHelperRead(const CATOmxKeyString& iksInputFunc);
  virtual ~CATPLMNLVInputHelperRead();

  HRESULT AddType(const CATPLMTypeH& iType);

  HRESULT AddName(const CATUnicodeString& iName);

  HRESULT AddPolicy(const CATUnicodeString& iPolicy);

  HRESULT AddPath(const CATUnicodeString& iPath);

  HRESULT AddSelect(const CATOmxOrderedOSet<CATOmxKeyString>& iSetOfAttributesNames);


  HRESULT AddId(const CATUuid& iUuid);

  HRESULT GetJson(CATOmxJsonObject& oJson)const;
  HRESULT Build();

  HRESULT AddOptions(const CATPLMNLVPropertiesRead& iProperties);

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATPLMNLVInputHelperRead(CATPLMNLVInputHelperRead &);
  CATPLMNLVInputHelperRead& operator=(CATPLMNLVInputHelperRead&);

  CATIPLMNLVInputHelperRead* _pInputHelper;
};

#endif

