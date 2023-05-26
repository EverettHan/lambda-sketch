#ifndef CATOmbLocalSaveSessionInfo_H
#define CATOmbLocalSaveSessionInfo_H

/**
* @level Protected 
* @usage U1
*/

#include "CATUnicodeString.h"
#include "CATOmxSharable.h"
#include "CATIAV5Level.h"
#include "CATCollec.h"

class CATComponentId;
class CATOmbLoadingModeRuleSet;
class CATProxySpace;
class CATOmbLoadingModeRuleSet;
class CATListValCATComponentId;

/**
* Stream/Unstream all RepRefs info Session for LocalSave. 
*
* <br><b>Role</b>: 
* This class provides an easy access to stream the Session State of a RepRef when a LocalSave is launched. 
* This class will stream all required information that is not kept on the TOS/LOG mechanism.
* (SelectiveLoadingMode in use, Dirty Status of the SDs...)
*/
class CATOmbLocalSaveSessionInfo : public CATOmxSharable
{
public:
#ifndef CATIAR417
  /** 
  * Enrich the Input Loading Mode Rules with rules allowing the restoration of the correct Selective Loading Mode on a RepRef restored.
  *
  * @param ioRuleSet [inout]
  *   The RuleSet to be enriches
  *
  * @return
  *   <code>S_OK</code> code successfuk
  *   <code>E_FAIL</code> unexpected error. Chec Deserialization exit with success
  *
  */
  virtual HRESULT EnrichLoadingModeRuleSet(CATOmbLoadingModeRuleSet& ioRuleSet) = 0;
#endif
  /** 
  * Restore the Session State of the RepRef computed at the last LocalSave operation
  *
  * @param iWorkspace [in]
  *   Workspace in which the RepRef has been loaded. 
  *
  * @return
  *   <code>S_OK</code> 
  *   <code>E_FAIL</code> Unstream has not been performed correctly / Unexpected error
  *
  */
  virtual HRESULT RestoreInfoSessionOnRepRefs(const CATProxySpace& iWorkspace, const CATLISTV(CATComponentId)& iOpenedComps) = 0; 
};

#endif


