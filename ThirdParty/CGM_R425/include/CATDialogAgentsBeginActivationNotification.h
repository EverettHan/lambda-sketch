#ifndef CATDialogAgentsBeginActivationNotification_h
#define CATDialogAgentsBeginActivationNotification_h
#include "CATAfrFoundation.h"

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "CATNotification.h"

/**
 * Classe permettant de savoir lorsque l'état courant commence a activer ses agents
 */

class ExportedByCATAfrFoundation CATDialogAgentsBeginActivationNotification : public CATNotification
{

 CATDeclareClass;

public:

  /** @nodoc */
  CATDialogAgentsBeginActivationNotification ();
  virtual ~CATDialogAgentsBeginActivationNotification (); 
  
private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATDialogAgentsBeginActivationNotification (const CATDialogAgentsBeginActivationNotification &);
  CATDialogAgentsBeginActivationNotification & operator= (const CATDialogAgentsBeginActivationNotification &);

};

#endif
