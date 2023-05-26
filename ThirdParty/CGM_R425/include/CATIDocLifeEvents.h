/* -*-c++-*- */
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES  1997-2002
//=============================================================================
//
// Interface CATIDocLifeEvents :
//     
//       Interface to subscribe to events on document creation et destruction
//
//=============================================================================
//
//=============================================================================
// Jan. 99   Creation                                Benoit Paget
// Nov. 1999 Modification                         OGM
//           Ajout de InitializeNotification
// Nov. 2002 Modification                         RJA
//           Ajout des events GetLoadContainerNotification et GetUnLoadContainerNotification (des evenements necessaires au plan BRep Mode)
// Jul. 2004 Modification BES
//           Ajout des events GetNoStorageForContainerNotification; GetUnabletoUnstreamNotification;GetUnableToOpenRootNotification;GetAddRefForLockNotification;GetReleaseForLockNotification,GetNoStoragePropertyNotification
//           Pour l'outil de Debug des Documents
//=============================================================================
#ifndef CATIDocLifeEvents_H
#define CATIDocLifeEvents_H

/**
 * @level Protected 
 * @usage U3
 */

#include "CATInterfaceEvents.h"


#include "AC0XXLNK.h"
extern ExportedByAC0XXLNK IID IID_CATIDocLifeEvents ;

class ExportedByAC0XXLNK CATIDocLifeEvents : public CATInterfaceEvents
{
  CATDeclareInterface;
  public:
  
  // Managing events on document creation
  virtual CATCallbackEvent GetCreateDocumentNotification() = 0 ;

  // Managing events on document initialization
  virtual CATCallbackEvent GetBeforeDocInitNotification() = 0 ;
  virtual CATCallbackEvent GetAfterDocInitNotification() = 0 ;
  virtual CATCallbackEvent GetInitializeDocumentNotification() = 0 ;

  // Managing events on document destruction
  virtual CATCallbackEvent GetRemoveDocumentNotification() = 0 ;

  // Managing events on beginning of document opening
  virtual CATCallbackEvent GetStartOpenNotification() = 0 ;

  // Managing events on end of document opening
  virtual CATCallbackEvent GetEndOpenNotification() = 0 ;

  // Managing events on container loading
  virtual CATCallbackEvent GetLoadContainerNotification() = 0;

  // Managing events on container unloading
  virtual CATCallbackEvent GetUnLoadContainerNotification() = 0;

  // Managing events on beginning of document saving
  virtual CATCallbackEvent GetStartSaveNotification() = 0 ;

  // Managing events on end of document saving
  virtual CATCallbackEvent GetEndSaveNotification() = 0 ;

  // Managing events on "new from" uuids regeneration
  virtual CATCallbackEvent GetReplaceUUIDsNotification() = 0 ;

  // R14SP6 Only. Will not exist for R15. Allow MechMod to load container before save operation
  virtual CATCallbackEvent GetBeforeSaveNotification() = 0 ;


  // Managing events on document unloading
  /**
   * Returns the name of the base class of the notifications which are sent by the document unloader.<br>
   * If you want to receive more than one notification, you should only subscribe to this one:<pre>
   * AddCallback(< xxx, > pSession, DocLifeEvents.GetDocUnloadNotification(), (CATSubscriberMethod)&CATxxx::AtDocUnload, pData);
   *
   * void CATxxx::AtDocUnload(..., CATNotification *ipNotif, ...)
   * {
   *    const CATMetaClass *pNotifMetaClass = ipNotif->GetMetaObject();
   *    if (pNotifMetaClass->IsAKindOf(CATBeginDocUnloadNotif::MetaObject()))
   *      < Begin >
   *    else if (pNotifMetaClass->IsAKindOf(CATPrepareDocUnloadNotif::MetaObject()))
   *      < Prepare >
   *    else if (pNotifMetaClass->IsAKindOf(CATEndDocUnloadNotif::MetaObject()))
   *      < End >
   * }</pre>
   */
  virtual CATCallbackEvent GetDocUnloadNotification() = 0;

  /**
   * Returns the name of the first notification which is sent before unloading documents.<br>
   * The notification @href CATBeginDocUnloadNotif is sent in order to verify if the documents can be unloaded or not.
   */
  virtual CATCallbackEvent GetBeginDocUnloadNotification() = 0;

  /**
   * Returns the name of the second notification which is sent before unloading documents.<br>
   * The notification @href CATPrepareDocUnloadNotif is sent in order to let the subscribers break their links with
   * the documents that are going to be unloaded.<br>
   * BEWARE: the Specs links must not be broken there.
   */
  virtual CATCallbackEvent GetPrepareDocUnloadNotification() = 0;

  /**
   * Returns the name of the notification which is sent at the end of the unloading.<br>
   * The notification @href CATEndDocUnloadNotif is sent in order to inform the subscribers if the unloading is successful or not.
   */
  virtual CATCallbackEvent GetEndDocUnloadNotification() = 0;




/* DOCUMENT DEBUG TOOL ONLY*/
// Internal service. Do not use!!

 /** 
 * This callback allows us knowing that a container has no storage
 */
 virtual CATCallbackEvent GetNoStorageForContainerNotification() = 0;
 /** 
 * This callback allows us knowing that a container has no stream
 */
 virtual CATCallbackEvent GetUnableToUnstreamNotification() = 0;
 /**
 * This callback allows us knowing that a container has no stream
 */
 virtual CATCallbackEvent GetUnableToStreamNotification() = 0;
 /**
 * This callback allows us knowing we cannot open root storage
 */
 virtual CATCallbackEvent GetUnableToOpenRootNotification() = 0;
/**
 * This callback allows us knowing some data streams are invalid
 */
 virtual CATCallbackEvent GetDataStreamError() = 0;
/**
 * This callback allows us knowing something went wrong during doc init
 */
 virtual CATCallbackEvent GetInitDocError() = 0;
/**
 * This callback allows us knowing an AddRefForLock happens
 */
 virtual CATCallbackEvent GetAddRefForLockNotification() = 0;
 /**
 * This callback allows us knowing a ReleaseForLock happens
 */
 virtual CATCallbackEvent GetReleaseForLockNotification() = 0;
 /**
 * This callback allows us knowing a ReleaseForLock happens
 */
 virtual CATCallbackEvent GetNoStoragePropertyNotification() = 0;
 /**
 * This callback allows ObjectSpecsModeler to describe their errors in the debug tool
 */
 virtual CATCallbackEvent GetSpecsErrorNotification() = 0;


/* DOCUMENT DEBUG TOOL ONLY*/

} ;

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIDocLifeEvents, CATInterfaceEvents ) ;


#endif
