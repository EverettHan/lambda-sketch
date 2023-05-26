

#ifndef CATPLMNLVOptions_H
#define CATPLMNLVOptions_H

#include "CATPLMServicesNLV.h"
#include <vector>
#include <map>
#include "CATUnicodeString.h"
#include "CATOmxKeyString.h"
#include "CATOmxJsonObject.h"
#include "CATIPLMError.h"
#include "CATPLMNLVSemantic.h"
#include "CATPLMNLVInputHelperWrite.h"




class ExportedByCATPLMServicesNLV CATPLMNLVOptions
{
public:


  static  CATPLMNLVOptions s();

  const CATOmxKeyString ksAnswerFormat;
  const CATOmxKeyString ksWithCopyFrom;
  const CATOmxKeyString ksWithThumbnail;
  const CATOmxKeyString ksWithIsLastVersion;
  const CATOmxKeyString ksClonePrefix;
  const CATOmxKeyString ksCopyFiles;
  const CATOmxKeyString ksWithAdjacentVersion;
  const CATOmxKeyString ksValidIntents;
  const CATOmxKeyString ksWithAttributes;
  const CATOmxKeyString ksWithSystemAttributes;
  const CATOmxKeyString ksWithModifiedObjects;
  const CATOmxKeyString ksInitializationBL;
  const CATOmxKeyString ksWithNLS;

  HRESULT AddAnswerFormat(CATPLMNLVSemantic::AnswerFormat iAnswerFormat, std::map<CATUnicodeString, CATUnicodeString>& ioParamMap);
  HRESULT AddWithCopyFrom(bool iWithCopyFrom, std::map<CATUnicodeString, CATUnicodeString>& ioParamMap);
  HRESULT AddWithThumbnail(bool iWithThumbnail, std::map<CATUnicodeString, CATUnicodeString>& ioParamMap);
  HRESULT AddWithIsLastVersion(bool iWithIsLastVersion, std::map<CATUnicodeString, CATUnicodeString>& ioParamMap);
  HRESULT AddClonePrefix(CATPLMNLVSemantic::ClonePrefix iClonePrefix, std::map<CATUnicodeString, CATUnicodeString>& ioParamMap);
  HRESULT AddCopyFiles(bool iCopyFiles, std::map<CATUnicodeString, CATUnicodeString>& ioParamMap);
  HRESULT AddWithAdjacentVersion(bool iWithAdjacentVersion, std::map<CATUnicodeString, CATUnicodeString>& ioParamMap);
  HRESULT AddValidIntents(std::vector<CATPLMNLVSemantic::Intent>& iListIntent, std::map<CATUnicodeString, CATUnicodeString>& ioParamMap);
  HRESULT AddWithAttributes(bool iWithAttributes, std::map<CATUnicodeString, CATUnicodeString>& ioParamMap);
  HRESULT AddWithSystemAttributes(bool iWithSystemAttributes, std::map<CATUnicodeString, CATUnicodeString>& ioParamMap);
  HRESULT AddWithModifiedObjects(bool iWithModifiedObjects, std::map<CATUnicodeString, CATUnicodeString>& ioParamMap);
  HRESULT AddInitializationBL(bool iInitializationBL, std::map<CATUnicodeString, CATUnicodeString>& ioParamMap);
  HRESULT AddWithNLS(bool iWithNLS, std::map<CATUnicodeString, CATUnicodeString>& ioParamMap);

private:
  CATPLMNLVOptions();

};



//-----------------------------------------------------------------------


#endif
