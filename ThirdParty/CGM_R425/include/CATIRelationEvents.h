#ifndef CATIRelationEvents_H
#define CATIRelationEvents_H

// COPYRIGHT DASSAULT SYSTEMES 1999
   
/** 
 * @CAA2Level L1
 * @CAA2Usage U3 
 */

/*  CAA2Reviewed by FRH */

// export module
#include "KnowledgeItf.h"

// inherited from
#include "CATInterfaceEvents.h"

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATIRelationEvents;
#else
extern "C" const IID IID_CATIRelationEvents;
#endif

/**   
 * Interface dedicated to Knowledge relations events management.
 * <b>Role</b>: 3 events available.<br>
 *  - ChangeVisu when<br>
 *    - relation is activated or desactivated<br>
 *    - body changes<br>
 *  - Evaluate when relation is being evaluated again<br>
 *  - Delete when relation is deleted (before deletion)<br>
 * @see CATParmNotification
 */
class ExportedByKnowledgeItf CATIRelationEvents: public CATInterfaceEvents
{
  CATDeclareInterface;

public:

/**
 * Returns Change Visu  notification.
 */
virtual CATCallbackEvent GetChangeVisuNotification()  = 0;

/**
 * Produces Change Visu event dispatching.
 */
virtual void SendChangeVisuNotification () = 0;

/**
 * Returns Evaluate notification.
 */
virtual CATCallbackEvent GetEvaluateNotification()  = 0;

/**
 * Returns Delete notification.
 */
virtual CATCallbackEvent GetDeleteNotification()  = 0;

};

CATDeclareHandler(CATIRelationEvents, CATInterfaceEvents);

#endif
