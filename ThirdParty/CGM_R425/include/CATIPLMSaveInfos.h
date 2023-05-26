/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2020
#ifndef CATIPLMSaveInfos_H
#define CATIPLMSaveInfos_H

/**
 * @level Protected
 * @usage U4
 */

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATOmxOHMap.h"
#include "CATOmxList.h"
#include "CATOmxKeyValue.h"

class CATOmxKeyString;
class CATError;
class CATMacForIUnknown;
class CATPLMID;


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMSaveInfos;
#else
extern "C" const IID IID_CATIPLMSaveInfos;
#endif

class ExportedByCATPLMIntegrationInterfaces CATIPLMSaveInfos : public CATBaseUnknown
{
public:

  CATDeclareInterface;

  /**
  * retrieve an information set with CATPLMSessionSaveInfos
  */
  virtual HRESULT WriteContextInfos(const CATOmxOHMap<CATPLMID, CATOmxAny>& iSessionInfos, CATOmxKeyValue &oSerializedListeners, CATOmxKeyValue& oSerializedTransactionParameters, CATOmxKeyValue & oSerializedInfos) = 0;

  /**
* Process the errors raised during the save on the provider
* @param iServerErrors:
*   the errors encountered during the save associated to the component which have raised the error.
*   (These errors can be raised by the session or the provider.)
* @param iSessionInfos:
*   additional infos relative to this protocol that can be found on PLM components involved in a save transaction
* @param oSessionErrors:
*   The errors to display to the end-user
*/
  virtual void PostProcessErrors(const CATOmxOHMap<CATPLMID, CATError>& iServerErrors, const CATOmxOHMap<CATPLMID, CATOmxAny>& iSessionInfos, CATOmxList<CATError> & oSessionErrors) = 0;

};

CATDeclareHandler(CATIPLMSaveInfos, CATBaseUnknown);

#endif
