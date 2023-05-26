/* -*-c++-*- */
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES  1999-2002
//=============================================================================
//
// Interface CATIDocModificationEvents :
//     
//       Interface to subscribe to events on document :
//        - link addition
//        - link deletion
//        - renaming
//
//=============================================================================
//
//=============================================================================
// Jan. 99   Creation                                Benoit Paget
// Nov. 2002 Modification                         RJA
//           Ajout des events GetLoadContainerNotification et GetUnLoadContainerNotification (des evenements necessaires au plan BRep Mode)
//=============================================================================
#ifndef CATIDocModificationEvents_H
#define CATIDocModificationEvents_H

/**
 * @level Private
 * @usage U3
 */

#include "CATInterfaceEvents.h"


#include "AC0XXLNK.h"
extern ExportedByAC0XXLNK IID IID_CATIDocModificationEvents ;

class ExportedByAC0XXLNK CATIDocModificationEvents : public CATInterfaceEvents
{
  CATDeclareInterface;
  public:
  
  // Managing events on link addition
  virtual CATCallbackEvent GetLinkAdditionNotification() = 0 ;

  // Managing events on link deletion
  virtual CATCallbackEvent GetLinkDeletionNotification() = 0 ;

  // Managing events on document renaming
  virtual CATCallbackEvent GetNameModificationNotification() = 0 ;
  
  // Managing events on document editor meter
  virtual CATCallbackEvent GetEditorModificationNotification() = 0 ;

  // Managing events on container creation
  virtual CATCallbackEvent GetContCreationNotification() = 0 ;

  // Managing events on container deletion
  virtual CATCallbackEvent GetContDeletionNotification() = 0 ;
  
  // Managing events on setPersistenceType on container
  virtual CATCallbackEvent GetContPersistTypeModificationNotification() = 0 ;

  // Managing userid changes on container
  virtual CATCallbackEvent GetContUserIdModificationNotification() = 0 ;

  // Managing events on docEnv changes
  virtual CATCallbackEvent GetDocEnvModificationNotification() = 0 ;

  // Managing events on document first modification
  // No model modification should be made when receiving this event.
  virtual CATCallbackEvent GetFirstModificationNotification() = 0 ;

  // Managing events on container loading
  virtual CATCallbackEvent GetLoadContainerNotification() = 0;
  // Managing events on container unloading
  virtual CATCallbackEvent GetUnLoadContainerNotification() = 0;
 // Managing events on loading Enovia Doc for WS for local copy on disk
  virtual CATCallbackEvent GetWSLoadEnoviaDocNotification() = 0;
} ;

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIDocModificationEvents, CATInterfaceEvents ) ;


#endif
