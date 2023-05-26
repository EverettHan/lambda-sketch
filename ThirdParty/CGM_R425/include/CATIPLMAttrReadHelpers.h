#ifndef CATIPLMAttrReadHelpers_H
#define CATIPLMAttrReadHelpers_H

#include "CATPLMServicesItf.h"

#include "CATPLMOmxCollections.h"

class CATPLMType;
class CATIPLMAttrRead;
class CATUnicodeString;
class CATListValCATString;
class CATListValCATUnicodeString;

class ExportedByCATPLMServicesItf CATIPLMAttrReadHelpers
{
public:
  enum eMode {eRetrieveAllList, eRetrieveFirstElementOfList};

  static HRESULT Stream(CATPLMType* ipType,
    CATIPLMAttrRead* ipAttrRead,
    const CATListValCATString& iListAttrName,
    CATListValCATUnicodeString& oListAttrValue,
    eMode iMode
  );

  static HRESULT Stream(CATPLMType* ipType,
    CATIPLMAttrRead* ipAttrRead,
    CATListValCATString& oListAttrName,
    CATListValCATUnicodeString& oListAttrValue,
    eMode iMode);

  static HRESULT Stream(CATPLMType* ipType,
    CATIPLMAttrRead* ipAttrRead,
    CATPLMOrderedOSetOfKS& oAttrNameSet,
    CATPLMKSToCUS& oAttrNameToAttrVal,
    eMode iMode);

  static HRESULT Stream(CATPLMType* ipType,
    CATIPLMAttrRead* ipAttrRead,
    const CATOmxKeyString& iAttrName,
    CATUnicodeString& oAttrVal,
    eMode iMode);
};

#endif
