/* -*-c++-*- */
#ifndef CATIDOCEVENTS_H
#define CATIDOCEVENTS_H
/// COPYRIGHT DASSAULT SYSTEMES 1999

/**
  * @level Private
  * @usage U3
  */


#include "CATInterfaceEvents.h"
class CATIDocEvents_var;


#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIDocEvents ;

/**
* @nodoc 
* Interface to subscribe to document events management.
*/

class ExportedByAD0XXBAS CATIDocEvents : public CATInterfaceEvents
{
  CATDeclareInterface;
  public:

  /**
    * @nodoc 
   * Returns undo/redo notification.
   */
  virtual CATCallbackEvent GetUndoRedoNotification() = 0 ;

  /**
   * @nodoc 
   * Returns notification before undo/redo mechanism.
   */
  virtual CATCallbackEvent GetBeforeUndoRedoNotification() = 0 ;

  /**
   * @nodoc 
   * Returns Save/Load notification .
   */
  virtual CATCallbackEvent GetSaveLoadNotification() = 0 ;
  
  /**
   * @nodoc 
   * Returns Copy notification .
   */
  virtual CATCallbackEvent GetCopyNotification() = 0 ;

    
  /**
   * @nodoc 
   * Returns Cut/Delete notification .
   */
  virtual CATCallbackEvent GetCutDeleteNotification() = 0 ;

  /**
   * @nodoc 
   * Returns Paste notification .
   */
  virtual CATCallbackEvent GetPasteNotification() = 0 ;    

  /**
   * @nodoc 
   * Returns Link notification (via Edit-Links for instance).
   */
  virtual CATCallbackEvent GetLinkModifNotification() = 0 ;      
  
  /**
   * @nodoc 
   * Returns notification for Unitary Load done via File-Contents (cf container under the compound).
   */
  virtual CATCallbackEvent GetUnitaryLoadNotification() = 0 ;      
  
  /**
   * @nodoc 
   * Returns notification for pointed documents load (via Desk for instance).
   */
  virtual CATCallbackEvent GetPointedDocLoadNotification() = 0 ;   
  
 /**
  * @nodoc
  */
  virtual CATCallbackEvent GetBeginCopyNotification() = 0 ;

 /**
  * @nodoc
  */
  virtual CATCallbackEvent GetBeginCutDeleteNotification() = 0 ;

 /**
  * @nodoc
  */
  virtual CATCallbackEvent GetBeginPasteNotification() = 0 ;
} ;

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIDocEvents, CATBaseUnknown ) ;


#endif
