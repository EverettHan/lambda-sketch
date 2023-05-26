#ifndef CATNotificationDispatcher_h
#define CATNotificationDispatcher_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//
// CATIA Version 5 Release 1 Framework Model
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
//  Abstract : Dispatch notifications.
//             will support register on a kind of notification
//             (waiting for system framework)
//             (for now : AddCallback and RemoveCallback method of basic
//                        component is used, with a CATCallbackEvent wich is
//                        a model connexion - the client has to check the kind
//                        of notification.
//              A new dispather should be provided to suppress CATCallbackEvent,
//              and to allow attach to a kind of notification.
//              Method will be on the dispatcher, not on the client.

//------------------------------------------------------------------------------
//  Usage :     used to dispatch informations. 
//
//------------------------------------------------------------------------------
//  Inheritance : CATNotificationDispatcher
//                  CATCallbackManager (Framework System)
//------------------------------------------------------------------------------
//  Main Methods :
//             Dispatch (CATNotification *);
//
//------------------------------------------------------------------------------
#include "CATVisItf.h"

#include "CATCallbackManager.h"

class CATNotification;

/**
 * Class to dispatch notifications.
 * <b>Role</b>: This callback manager is used to dispatch the visualization
 * events especially @href CATIModelEvents
 */

class ExportedByCATVisItf CATNotificationDispatcher : public CATCallbackManager
{
//------------------------------------------------------------------------------
 public:

   CATDeclareClass;

  /** @nodoc */
   CATDeclareCBEvent (DISPATCHER_CONNEXION);

/**
 * Constructs a CATNotificationDispatcher.
 */
   CATNotificationDispatcher();

   virtual ~CATNotificationDispatcher();

/**
 * Dispatches a notification.
 * @param iNotification 
 *   The event notification to dispatch.
 */
   void Dispatch(CATNotification & iNotification);

/** @nodoc */
   CATCallbackEvent GetConnexion() const;

};
#endif
