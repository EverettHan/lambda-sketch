#ifndef CATPLMIdentificationAccessMacros_H
#define CATPLMIdentificationAccessMacros_H

/**
 * @level Private
 * @usage U3
 */

#include "CATPLMIdentificationAccess.h"
#include "CATError.h"  
#include "CATSysMacros.h"

class CATPLMTypeId;
class CATUnicodeString;
class CATOmxKeyString;

ExportedByCATPLMIdentificationAccess HRESULT CATTosDebugIdFct(int idmsg);
ExportedByCATPLMIdentificationAccess HRESULT CATTosFailedIdFct(int idmsg);

#define CATTosIdError(msgid) CATTosDebugIdFct(msgid)
#define CATTosIdWarning(msgid) CATTosFailedIdFct(msgid)

//------------------------------------------------------------------------
// CATTosIdMessage
//------------------------------------------------------------------------
#define CATTosIdMessage_None                                        0
#define CATTosIdMessage_ExpectingSuccessfull_HResult                1
#define CATTosIdMessage_InappropriateCondition_ForRequest           2
#define CATTosIdMessage_NullUnsetInternal_UnavailableForRequest     3
#define CATTosIdMessage_NullOrUnsetInput_InvalidForRequest          5
#define CATTosIdMessage_ImpossibleAllocation                        6
#define CATTosIdMessage_UnavailableSoftwareFunctionnality           8

/**  DO NOT USE, use default constructor instead */
extern const ExportedByCATPLMIdentificationAccess CATPLMTypeId  CATPLMTypeId_Null;

#endif
