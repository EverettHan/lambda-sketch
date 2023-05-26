#ifndef CATPLMCollabHelper_H
#define CATPLMCollabHelper_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010

#include "CATListPtrCATIAdpPLMIdentificator.h"

/**
 * @level Private
 * @usage U1       
 */
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATPLMIDSet.h"

/**
 * Specific helpers for collab
 */
class ExportedByCATPLMTos CATPLMCollabHelper
{
public:

  /**
  * Find extra components to be imported for solving integrity issues.
  * 
  * Current specification :
  *   - complete list with strong relational (ownership and instance-reference)
  * 
  * @param iListToBeCompleted
  *        List of identifiers to be computed (Is not empty).
  * @param oListOfExtraComponents
  *        List of extra identifiers to be imported (Has to be empty).
  * @return
  *        CATBehaviour_continue : visit next dependency
  *        CATBehaviour_break    : break visitation
  */
  static HRESULT FindExtraComponentsForSolvingIntegrityIssues (const CATListPtrCATIAdpPLMIdentificator & iListToBeCompleted, CATListPtrCATIAdpPLMIdentificator & oListOfExtraComponents);

  /**
  * Find extra components to be imported for solving integrity issues.
  * 
  * Current specification :
  *   - complete list with strong relational (ownership and instance-reference)
  * 
  * @param iListToBeCompleted
  *        List of identifiers to be computed (Is not empty).
  * @param oListOfExtraComponents
  *        List of extra identifiers to be imported (Has to be empty).
  * @return
  *        CATBehaviour_continue : visit next dependency
  *        CATBehaviour_break    : break visitation
  */
  static HRESULT FindExtraComponentsForSolvingIntegrityIssues (const CATPLMIDSet & iListToBeCompleted, CATPLMIDSet & oListOfExtraComponents);

private:

  CATPLMCollabHelper();
  ~CATPLMCollabHelper();
};
 
#endif
