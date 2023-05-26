// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATIPLMCompIterationService.h
// Define the CATIPLMCompIterationService interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
// July 2012  Creation: EPB
//===================================================================
#ifndef CATIPLMCompIterationService_H
#define CATIPLMCompIterationService_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATPLMID.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompIterationService;
#else
extern "C" const IID IID_CATIPLMCompIterationService ;
#endif

#include "CATCollec.h"
class CATLISTV(CATPLMID);
class CATIPLMCompRecordReadSet;
class CATIPLMFilterAttribute;
class CATPLMRepositoryName;
class CATIPLMError;

/**
 * @level Protected
 * @usage U3
 */

class ExportedByCATPLMServicesItf CATIPLMCompIterationService: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  virtual HRESULT GetIterations(const CATPLMID& iPlmid, const CATListOfCATString &lAttrList, CATIPLMCompRecordReadSet*& opResultsIteration) = 0;

  /*@deprecated*/
  virtual HRESULT Restore(const CATPLMID &iPlmid, CATPLMID &iWorkspaceID, CATIPLMCompRecordReadSet*& opResultsIteration) = 0;

  virtual HRESULT Restore(const CATPLMID &iPlmid, CATIPLMCompRecordReadSet*& opResultsIteration, const CATPLMID &iWorkspaceID = CATPLMID_Null, const CATPLMID &iActionID = CATPLMID_Null) = 0;
};

#endif
