/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2020
#ifndef CATIPLMSaveTransactionCB_H
#define CATIPLMSaveTransactionCB_H

/**
 * @level Protected
 * @usage U4
 */

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATOmxOHMap.h"
#include "CATOmxList.h"

class CATOmxKeyString;
class CATError;
class CATMacForIUnknown;
class CATPLMID;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMSaveTransactionCB;
#else
extern "C" const IID IID_CATIPLMSaveTransactionCB;
#endif

class ExportedByCATPLMIntegrationInterfaces CATIPLMSaveTransactionCB : public CATBaseUnknown
{
public:

  CATDeclareInterface;

public:
  /**
   * Give an acces to the saved component after the commit in the database.
   * The components cannot be modified in the session.
    @param iProtocol:
  *   the name of the protocol
   * @param iSessionInfos:
   * a map of key/value for the PLMID/CATOmxAny in the session.
   * The map has been valuated thanks to CATPLMSessionSaveInfos API, before the Save Transaction.
  * @return :
  * S_OK in case of success
  * E_* if an error is encoutered.
   */
  virtual HRESULT PostProcessAfterCommit(CATOmxKeyString& iProtocol, const CATOmxOHMap<CATPLMID, CATOmxAny>& iSessionInfos) = 0;

};

CATDeclareHandler(CATIPLMSaveTransactionCB, CATBaseUnknown);

#endif
