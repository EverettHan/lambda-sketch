#ifndef CATIPLMCompApplicationLoader_H
#define CATIPLMCompApplicationLoader_H

// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// CATIPLMCompApplicationLoader
//
// Allows to query some attribute values of a list of PLM objects.
//
// The list of attributes to query on a PLM object depends on the 
// application identifier and the type of this object. This list
// is not modifiable at runtime but it is constant during the session.
// 
//===================================================================
//
// Usage notes:
//   CATIPLMCompApplicationLoader objects are created thanks to the 
//   interface CATIPLMCompStatementService
//
//===================================================================
//  Dec 2013  Creation
//===================================================================

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompApplicationLoader;
#else
extern "C" const IID IID_CATIPLMCompApplicationLoader ;
#endif

class CATPLMID;
class CATPLMCEStamp;
class CATIPLMCompRecordReadSet;
class CATPLMCacheId;

/**
 * @level Protected
 * @usage U3
 */

class ExportedByCATPLMServicesItf CATIPLMCompApplicationLoader: public CATBaseUnknown
{
  CATDeclareInterface;

public:
  
  /**
   * Adds a new input to the list of objects to query.
   * @param iPLMID 
   *    the PLMID of the new object 
   * @param iCEStamp 
   *    the CEStamp associated to the object
   */
  virtual HRESULT AddInput (const CATPLMID &iPLMID, const CATPLMCEStamp &iCEStamp) = 0;

  /**
   * Adds a new input to the list of objects to query.
   * See @href CATPLMCacheId for how to get one from your CATPLMIDs or queries.
   *
   * @param iCacheId
   *    the CATPLMCacheId of the object.
   */
  virtual HRESULT AddInput (const CATPLMCacheId &iCacheId) = 0;

  /**
  * Executes the query.
  *
  * For each couple (PLMID,CEStramp) of the AddInput list, first query the cache then the PDM on a
  * predefined list of attributes. When querying the cache, the expected CEStamp value is mandatory 
  * which means that an occurrence of the same PLMID but with another CEStamp value is not returned.
  * When querying the PDM, the CEStamp is returned and could be different from the expected one.
  *
  * @param oRRS [out, CATBaseUnknown#Release]
  *    a CATIPLMCompRecordReadSet interface providing access to the result. 
  *	@return
  *		Error code of function :
  *     S_OK    : Query is successfully and all elements were found.
  *     S_FALSE : Query is successfully but there is at least one CATIPLMRecordRead in error.
  *     E_FAIL  : A problem occurs during the query. get further information by using CATIPLMErrorStack
  */
  virtual HRESULT Query ( CATIPLMCompRecordReadSet *& oRRS) = 0;

  /**
   * Activates/deactivates the computation of the synchro status on SRs
   * Default is TRUE
   */
  virtual void ComputeSemanticRelationsSynchroStatus(CATBoolean iComputeSemanticRelationsSynchroStatus) =0;
};

//------------------------------------------------------------------
#endif
