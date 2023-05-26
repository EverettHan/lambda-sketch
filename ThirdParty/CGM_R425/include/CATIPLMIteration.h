// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATIPLMIteration.h
// Define the CATIPLMIteration interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
// July 2012 Creation: EPB
//===================================================================
#ifndef CATIPLMIteration_H
#define CATIPLMIteration_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMIteration;
#else
extern "C" const IID IID_CATIPLMIteration ;
#endif

//------------------------------------------------------------------

/**
 * @level Protected
 * @usage U3
 */

//------------------------------------------------------------------
#include "CATBaseUnknown.h"

#include "CATCollec.h"
#include "CATPLMID.h"
class CATLISTV(CATPLMID);

class CATIPLMCompRecordReadSet;
class CATIPLMFilterAttribute;
class CATIPLMError;

class ExportedByCATPLMServicesItf CATIPLMIteration: public CATBaseUnknown
{
  CATDeclareInterface;

public:
  virtual HRESULT GetIterations(const CATPLMID& iPlmid, const CATListOfCATString &lAttrList, CATIPLMCompRecordReadSet*& opResultsIteration) = 0;

  /**
  *
  * <br><b>Role</b>: 
  * @param iPlmid
  *   the PLMID to restore
  * @param opResultsIteration
  *   
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  /*@DEPRECATED*/
  virtual HRESULT Restore(const CATPLMID &iPlmid, CATPLMID &iWorkspaceID, CATIPLMCompRecordReadSet*& opResultsIteration) = 0;

  virtual HRESULT Restore(const CATPLMID &iPlmid, CATIPLMCompRecordReadSet*& opResultsIteration, const CATPLMID& iWorkspaceID = CATPLMID_Null, const CATPLMID &iActionID = CATPLMID_Null) = 0;

};

#endif
