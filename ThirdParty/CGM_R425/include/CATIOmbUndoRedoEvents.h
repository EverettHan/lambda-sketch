/* -*-c++-*- */
#ifndef CATIOmbUndoRedoEvents_H
#define CATIOmbUndoRedoEvents_H
/// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @level Private
* @usage U3
*/

#include "CATInterfaceEvents.h"

#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIOmbUndoRedoEvents ;

/**
* Interface to subscribe to undo redo  events management.
* <b>Role</b>: This interface, implemented by each V5 document, enables you to be informed
* when an undo or redo operation occurs in the session. 
* <br>The methods returns the callback indentifier. Here is an example with the @href AddCallback global function.
* <pre>
*     CATDocument *pDoc = ....
*     CATIOmbUndoRedoEvents_var spUndoRedoOnDoc = pDoc ;
*     ::AddCallback( this, 
*                   pDoc, 
*                    spUndoRedoOnDoc-><b>GetUndoRedoNotification</b>(), 
*                   (CATSubscriberMethod) &MyClass::MethodOnMyClass); 
*
* </pre>
* Where <tt>this</tt> is an instance of <tt>MyClass</tt>.
*  
*/

class ExportedByAD0XXBAS CATIOmbUndoRedoEvents : public CATInterfaceEvents
{
  CATDeclareInterface;
  public:

  /**
   *
   * Returns undo/redo notification.
   * @return 
   *   The callback identifier. 
   */
  virtual CATCallbackEvent GetUndoRedoNotification() = 0 ;

  /**
   * Returns notification before undo/redo mechanism.
   * @return
   *    The callback identifier. 
   */
  virtual CATCallbackEvent GetBeforeUndoRedoNotification() = 0 ;

} ;

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIOmbUndoRedoEvents, CATBaseUnknown ) ;


#endif
