// COPYRIGHT DASSAULT SYSTEMES 2007


#ifndef CATOmbRelationInformation_H
#define CATOmbRelationInformation_H

/**
* @level Protected
* @usage U1
*/


/**
* Synchronization status of a relation.
*
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
* @param CatOmbRelationSynchroStatus_Synchronized_Session
*   The relation is synchronized (session status)
* @param CatOmbRelationSynchroStatus_Synchronized_Remote
*   The relation was synchronized in the remote persistency (database status at open)
* @param CatOmbRelationSynchroStatus_Unsynchronized_Session
*   The relation is not synchronized (session status)
* @param CatOmbRelationSynchroStatus_Unsynchronized_Remote
*   The relation was not synchronized in the remote persistency (database status at open)
* @param CatOmbRelationSynchroStatus_Neutral
*   Unrelevant status
* @param CatOmbRelationSynchroStatus_Undefined
*   The status is not available
* @param CatOmbRelationSynchroStatus_NotApplicable
*   The SynchroStatus is not handled (the relation is not neutral).
*/
enum CATOmbRelationSynchroStatus
{
  CatOmbRelationSynchroStatus_Synchronized_Session = 0,
  CatOmbRelationSynchroStatus_Synchronized_Remote = 1,
  CatOmbRelationSynchroStatus_Unsynchronized_Session = 2,
  CatOmbRelationSynchroStatus_Unsynchronized_Remote = 3,
  CatOmbRelationSynchroStatus_Neutral = 4,
  CatOmbRelationSynchroStatus_Undefined = 5,
  CatOmbRelationSynchroStatus_NotApplicable = 6,
};

/**
* Status of a relation.
*
* @param CatOmbRelationStatus_Solved
*   The relation is solved in session (session status)
* @param CatOmbRelationStatus_Broken_Session
*   The relation is not solved because it is broken because the target component has been deleted in the session (session status)
* @param CatOmbRelationStatus_Broken_Remote
*   The relation is not solved because it is broken because the target component has been deleted in the remote persistency (database status at open)
* @param CatOmbRelationStatus_NotOpened
*   The relation is not solved because the target component is not opened in session.
* @param CatOmbRelationStatus_Undefined
*   The relation is not solved, but we are not able to understand why.
*/
enum CATOmbRelationStatus
{
  CatOmbRelationStatus_Solved = 0,
  CatOmbRelationStatus_Broken_Session = 1,
  CatOmbRelationStatus_Broken_Remote = 2,
  CatOmbRelationStatus_NotOpened = 3,
  CatOmbRelationStatus_Undefined = 4
};

/**
* Additional status of a relation.
* @param CatOmbAdditionalRelationStatus_NOAMIS
*   NOAMIS : Not Opened, Another Minor In Session.
*   The relation is minor sensitive and not opened in session while another minor version of the pointed component is opened in session.
* @param CatOmbAdditionalRelationStatus_MISNIP
*   MISNIP : Minor In Session Not Initially Pointed.
*   The relation is minor unsensitive and dynamically solved on another minor version of the pointed component opened in session.
*/
enum CATOmbAdditionalRelationStatus
{
  CatOmbAdditionalRelationStatus_NoAdditionalStatus,
  CatOmbAdditionalRelationStatus_NOAMIS,
  CatOmbAdditionalRelationStatus_MISNIP
};

/**
* Orientation of a relation.
*
* @param CatOmbRelationOrientation_NEUTRAL
*   Neutral relation.
* @param CatOmbRelationOrientation_IN
*   In relation.
* @param CatOmbRelationOrientation_OUT
*   Out relation.
*/
enum CATOmbRelationOrientation
{
  CatOmbRelationOrientation_NEUTRAL,
  CatOmbRelationOrientation_IN,
  CatOmbRelationOrientation_OUT,
  CatOmbRelationOrientation_INOUT
};

/**
* Remote status of a relation.
*
* The remote status is evaluated only at import time (Open, Refresh, ...).
* This information is never updated by PLM Session.
*
* @param CatOmbRelationRemoteStatus_NotAvailable
*   The remote status is not evaluated because component has never been imported.
* @param CatOmbRelationRemoteStatus_Solved_Synchronized
*   The relation was solved and synchronized.
* @param CatOmbRelationRemoteStatus_Solved_Unsynchronized
*   The relation was solved and unsynchronized.
* @param CatOmbRelationRemoteStatus_Broken_ComponentDestroyed
*   The relation was broken because one of pointed components was destroyed (Irreversible state).
* @param CatOmbRelationRemoteStatus_Broken_ComponentOutOfScope
*   The relation was broken because the pointed components are out of scope (Irreversible state).
* @param CatOmbRelationRemoteStatus_Broken_InconsistentOccurrence
*   The relation was broken because the pointed components are inconsistent due to a transfert in a workspace (Temporary state).
*/
enum CATOmbRelationRemoteStatus
{
  CatOmbRelationRemoteStatus_NotAvailable = 0,
  CatOmbRelationRemoteStatus_Solved_Synchronized = 1,
  CatOmbRelationRemoteStatus_Solved_Unsynchronized = 2,
  CatOmbRelationRemoteStatus_Broken_ComponentDestroyed = 3,
  CatOmbRelationRemoteStatus_Broken_ComponentOutOfScope = 4,
  CatOmbRelationRemoteStatus_Broken_InconsistentOccurrence = 5
};

#endif
