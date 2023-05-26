// COPYRIGHT DASSAULT SYSTEMES 2010

#ifndef CATPLMRelationRemoteStatus_H
#define CATPLMRelationRemoteStatus_H

/**
* @level Protected
* @usage U1
*/

#include "CATPLMRelationInformation.h"

/**
* Remote status of a relation.
*
* The remote status is evaluated only at import time (Open, Refresh, ...).
* This information is never updated by PLM Session.
* 
* @param CATPLMRelationRemoteStatus_NotAvailable
*   The remote status is not evaluated because component has never been imported.
* @param CATPLMRelationRemoteStatus_Solved_Synchronized
*   The relation was solved and synchronized.
* @param CATPLMRelationRemoteStatus_Solved_Unsynchronized
*   The relation was solved and unsynchronized.
* @param CATPLMRelationRemoteStatus_Broken_ComponentDestroyed
*   The relation was broken because one of pointed components was destroyed (Irreversible state).
* @param CATPLMRelationRemoteStatus_Broken_ComponentOutOfScope
*   The relation was broken because the pointed components are out of scope (Irreversible state).
* @param CATPLMRelationRemoteStatus_Broken_InconsistentOccurrence
*   The relation was broken because the pointed components are inconsistent due to a transfert in a workspace (Temporary state).
*/
enum CATPLMRelationRemoteStatus
{
  CATPLMRelationRemoteStatus_NotAvailable = 0,
  CATPLMRelationRemoteStatus_Solved_Synchronized = 1,
  CATPLMRelationRemoteStatus_Solved_Unsynchronized = 2,
  CATPLMRelationRemoteStatus_Broken_ComponentDestroyed = 3,
  CATPLMRelationRemoteStatus_Broken_ComponentOutOfScope = 4,
  CATPLMRelationRemoteStatus_Broken_InconsistentOccurrence = 5
};

#endif
