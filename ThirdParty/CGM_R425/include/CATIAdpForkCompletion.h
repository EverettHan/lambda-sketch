#ifndef __CATIAdpForkCompletion_H
#define __CATIAdpForkCompletion_H

// SpecialAPI
#include "CATSysErrorDef.h"
// ObjectModelerCollection
#include "CATOmxKeyValueBlock.h"
#include "CATOmxList.h"
#include "CATOmxOHMap.h"
#include "CATOmxOrderedOSet.h"
#include "CATOmxSharable.h"
#include "CATOmxSR.h"
// CATPLMIdentificationAccess
#include "CATPLMID.h"
#include "CATPLMID_Simple.h"
#include "CATPLMTypeH.h"
// CATPLMIntegrationAccess
#include "CATPLMIntegrationAccess.h"

/**@see RunForkCompletion*/
#define E_FORKCOMPLETION_RULES  MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x8e70)
/**@see RunForkCompletion*/
#define E_FORKCOMPLETION_SERVER MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x8e71)

/**
 * Meyerwerft sistership project "fork completion"/"complete aggregated objects"
 * Fork process consist in duplicating iteratively objects from a "prototype" collaborative space to another collaborative space ("sistership")
 * Let a prototype reference which has already been forked inside sistership collaborative space.
 * Then adding a new prototype child under this prototype reference will not automatically trigger sistership child creation.
 * This class allows to find these missing children.
 *
 * @usage:
 * notice that return code checks are omitted for clarity.
 * CATOmxSR<CATIAdpForkCompletion> hForkCompletion;
 * CATOmxOrderedOSet<CATPLMTypeH> childrenTypes = list of children types to work on;
 * CATIAdpForkCompletion::Create(childrenTypes,hForkCompletion);
 * //Select objects to work on
 * CATPLMID_Simple sistershipReferenceId = <the PLMID of some sistership reference>;
 * hForkCompletion->AddForkedObject(sistershipReferenceId);
 * //server queries
 * hForkCompletion->QueryMissingChildren();
 * //retrieve results
 * CATOmxArray<CATPLMID_Simple> missingPrototypeChildren,deletedPrototypeChildren;
 * hForkCompletion->EnumMissingChildren(sistershipReferenceId,missingPrototypeChildren,deletedPrototypeChildren);
 * //do something with missingPrototypeChildren and deletedPrototypeChildren children
 * 
 * //run server fork completion on one of the"missing" child
 * CATPLMID_Simple missingPrototypeChild = missingPrototypeChildren[1];
 * CATOmxOHMap<CATPLMID_Simple,CATPLMID_Simple> map;
 * map[missingChild] = CATPLMID_Simple();
 * CATOmxKeyValueBlock forkOptions = ...;
 * hForkCompletion->RunForkCompletion(forkOptions,map);
 * CATPLMID_Simple newSistershipChild = map[missingPrototypeChild]; //here is the identifier of the newly created sistership version of missingPrototypeChild
 */
class CATIAdpForkCompletion: public CATOmxSharable
{
public:
  /**create object*/
  ExportedByCATPLMIntegrationAccess static HRESULT Create(const CATOmxOrderedOSet<CATPLMTypeH>& iChildrenTypes,CATOmxSR<CATIAdpForkCompletion>& oObj);

  /**Add a sistership reference or representation to work on*/
  virtual HRESULT AddForkedFather(const CATPLMID_Simple& iForkedFatherId) = 0;

  /**query server to find missing children*/
  virtual HRESULT QueryMissingChildren() = 0;

  /**
   * retrieve results
   * @param iForkedFatherId:
   *    the same id as passed to AddForkedFather
   * @param oMissingChildren:
   *    prototype ids of children that exist inside prototype but not inside sistership
   * @param oDeletedChildren:
   *    prototype ids of children that exist inside prototype, have already been forked but do not exist anymore inside sistership (probably deleted)
   */
  virtual HRESULT EnumMissingChildren(const CATPLMID_Simple& iForkedFatherId,CATOmxArray<CATPLMID_Simple>& oMissingChildren,CATOmxArray<CATPLMID_Simple>& oDeletedChildren) = 0;

  /**
   * run fork completion on server
   * @param iOptions
   *   fork options, @see CATPLMCompForkInputs, CATIPLMTransferToNewProject
   * @param ioChildren
   *   in input: keys contain ids of object to fork (prototype aggregated objects retrieved by EnumMissingChildren)
   *   in output: upon success, values will contain new sistership version of prototype objects.
   * @return 
   *   E_FORKCOMPLETION_RULES: a rule forbids the operation
   *   E_FORKCOMPLETION_SERVER: server operation failed
   *   E_XXX: invalid arguments, misuse or internal error
   */
  virtual HRESULT RunForkCompletion(const CATOmxKeyValueBlock& iOptions,CATOmxOHMap<CATPLMID_Simple,CATPLMID_Simple>& ioChildren) = 0;
  
  /**an error and the optional id of the object to which it is related*/
  struct ErrorAndId
  {
    CATOmxSR<CATError> Error; //non NULL
    CATPLMID Id;              //can be NULL
  };
  /**
   * Retrieve the errors that has been logged until now during operation
   * Calling this method flushes error list so that a subsequent call to this method will return empty list.
   */
  virtual CATOmxIter<const ErrorAndId> GetErrors() = 0;
};

#endif
