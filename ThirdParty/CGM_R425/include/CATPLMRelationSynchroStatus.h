// COPYRIGHT DASSAULT SYSTEMES 2010

#ifndef CATPLMRelationSynchroStatus_H
#define CATPLMRelationSynchroStatus_H

/**
* @level Protected
* @usage U1
*/

#include "CATPLMRelationInformation.h"

/**
* Synchronization status of a relation.
* 
* Anthoring space :
*                              -------------------------------------------------------------------------------------------------
*                              |                                   Relation Synchro Status                                     |
*                              -------------------------------------------------------------------------------------------------
*                              |  Neutral  |  Sync Remote  |  Unsync Remote  |  Sync Session  |  Unsync Session  |  Undefined  |
* ------------------------------------------------------------------------------------------------------------------------------
* |          |  Solved         |     X                                               X                  X                      |
* | Relation |  Broken Session |                                                                                         X     |
* |  Status  |  Broken Remote  |                                                                                         X     |
* |          |  NotOpened      |     X              X                X                                                         |
* ------------------------------------------------------------------------------------------------------------------------------
*
* Other space :
*                              -------------------------------------------------------------
*                              |                  Relation Synchro Status                  |
*                              -------------------------------------------------------------
*                              |  Neutral  |  Sync Remote  |  Unsync Remote  |  Undefined  |
* ------------------------------------------------------------------------------------------
* |          |  Solved         |     X                                                     |
* |  Status  |  Broken Remote  |                                                     X     |
* |          |  NotOpened      |     X              X                X                     |
* ------------------------------------------------------------------------------------------
*
*
* @param CATPLMRelationSynchroStatus_Synchronized_Session
*   The relation is synchronized (session status)
* @param CATPLMRelationSynchroStatus_Synchronized_Remote
*   The relation was synchronized in the remote persistency (database status at open)
* @param CATPLMRelationSynchroStatus_Unsynchronized_Session
*   The relation is not synchronized (session status)
* @param CATPLMRelationSynchroStatus_Unsynchronized_Remote
*   The relation was not synchronized in the remote persistency (database status at open)
* @param CATPLMRelationSynchroStatus_Neutral
*   Unrelevant status
* @param CATPLMRelationSynchroStatus_Undefined
*   The status is not available
* @param CATPLMRelationSynchroStatus_NotApplicable
*   The SynchroStatus is not handled (the relation is not neutral).
*/
enum CATPLMRelationSynchroStatus
{
    CATPLMRelationSynchroStatus_Synchronized_Session = 0,
    CATPLMRelationSynchroStatus_Synchronized_Remote = 1,
    CATPLMRelationSynchroStatus_Unsynchronized_Session = 2,
    CATPLMRelationSynchroStatus_Unsynchronized_Remote = 3,
    CATPLMRelationSynchroStatus_Neutral = 4,
    CATPLMRelationSynchroStatus_Undefined = 5,
    CATPLMRelationSynchroStatus_NotApplicable = 6,
} ;

#endif
