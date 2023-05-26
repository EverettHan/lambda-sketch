#ifndef __CATIAdpForkCompletionRule_H
#define __CATIAdpForkCompletionRule_H

// System
#include "CATBaseUnknown.h"
// ObjectModelerCollection
#include "CATOmxIter.h"
#include "CATOmxList.h"
#include "CATOmxOrderedOSet.h"
#include "CATOmxSharable.h"
#include "CATOmxSR.h"
// CATPLMIdentificationAccess
#include "CATPLMID_Simple.h"
// CATPLMIntegrationAccess
#include "CATPLMIntegrationAccess.h"

/**
 * Implement this interface to add rules that will be checked when executing a "fork completion".
 * For fork definition, see CATIPLMTransferToNewProject
 * For fork completion definition, see CATIAdpForkCompletion
 */
class ExportedByCATPLMIntegrationAccess CATIAdpForkCompletionRule: public CATBaseUnknown
{
  CATDeclareInterface;
public:

  /**
   * @return the list of supported types
   */
  virtual CATOmxOrderedOSet<CATPLMTypeH> GetSupportedTypes() = 0;

  struct Context
  {
    const CATUnicodeString Sistership;
    const CATOmxOrderedOSet<CATPLMID_Simple> PrototypeChildren;
  };

  /**
   * Fork completion request
   */
  struct Request: public CATOmxSharable
  {
    //inputs:
    const CATPLMID_Simple PrototypeChild;   //the PLMID of the aggregated object we want to fork (inside prototype)
    const CATPLMID_Simple PrototypeFather;  //the PLMID of the object aggregating object (inside prototype)
    const CATPLMID_Simple SistershipFather; //the PLMID of the sistership version of PrototypeFather, under which we want to create sistership version of PrototypeChild

    //outputs:
    CATOmxSR<CATError> Error;                                  //Error explaining why fork completion is not possible
    CATOmxOrderedOSet<CATPLMID_Simple> PrototypePrerequisites; //PLMID of prototypes objects which sistership version is required in order to allow fork completion of PrototypeChild

    inline Request(const CATPLMID_Simple& iPrototypeChild,const CATPLMID_Simple& iPrototypeFather,const CATPLMID_Simple& iSistershipFather):
      PrototypeChild(iPrototypeChild),
      PrototypeFather(iPrototypeFather),
      SistershipFather(iSistershipFather)
    {}
  };

  /**
   * Check if a batch of fork completion requests is possible
   * @see CATIAdpForkCompletionRule::Request
   * Notice that here we work on not loaded objects so server queries are required in order to navigate on objects or retrieve attributes.
   * Some query helpers are available in CATAdpQueryHelpers.h
   * @param iContext
   *   global context for the operation
   * @param ioRequests:
   *   the list of request to process, it is non empty and only contains objects "supported" by this rule
   * @param oErrors:
   *   error explaining why the check has failed
   * @return 
   *   E_XXX: 
   *     failed to check if request is possible, operation is aborted
   *     oErrors should contain errors explaining why the check was not possible
   *   S_XXX:
   *     check was successful
   *     if the operation is illegal, set Error field of problematic request (message will be displayed to the user)
   *     if the operation is possible only if some related objects are cloned, add them to PrototypePrerequisites field of associated request
   */
  virtual HRESULT CheckRequests(const Context& iContext,const CATOmxList<CATIAdpForkCompletionRule::Request>& ioRequests,CATOmxIter<CATError>& oErrors) = 0;
};

extern ExportedByCATPLMIntegrationAccess const IID IID_CATIAdpForkCompletionRule;

#endif
