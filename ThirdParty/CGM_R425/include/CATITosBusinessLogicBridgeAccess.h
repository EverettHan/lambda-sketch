#ifndef CATITosBusinessLogicBridgeAccess_H
#define CATITosBusinessLogicBridgeAccess_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2012

/**
* @level Private
* @usage U3
*/

#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATOmxArray.h"
#include "CATOmxKeyString.h"
#include "CATIPLMErrorCollector.h"
#include "CATOmxOHMap.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMTos IID IID_CATITosBusinessLogicBridgeAccess;
#else
extern "C" const IID IID_CATITosBusinessLogicBridgeAccess ;
#endif

class CATComponentId;
class CATOmxKeyValueBlock;
class CATUnicodeString;

/**
* Restricted services for BL
*/
class ExportedByCATPLMTos CATITosBusinessLogicBridgeAccess: public CATBaseUnknown
{
  CATDeclareInterface;

public:
  typedef CATOmxPair<CATPLMTypeH,CATOmxKeyValueBlock> CATPLMTypeHKVBlockIterElem;
  typedef CATOmxIter<CATPLMTypeHKVBlockIterElem> CATPLMTypeHKVBlockIter;

  /**
  * Apply business logic on CloneAsLoaded operation
  *
  * @param iCID
  *        The component to work on
  * @param iCloningString
  *        The cloning string
  * @param oBlock
  *        The impacted attributes
  * @param iErrorCollector
  *        Optional parameter for managing reporting
  * @return
  *        S_OK   : if succeeded
  *        E_FAIL : if failure
  */
  virtual HRESULT ApplyCloneAsLoadedBusinessLogic (const CATComponentId & iCID, const CATUnicodeString & iCloningString, CATPLMTypeHKVBlockIter & oBlocks, CATIPLMErrorCollector_var ihErrorCollector = NULL_var) = 0;

};

//------------------------------------------------------------------

#endif
