#ifndef CATDialogAgentsEndActivationNotification_h
#define CATDialogAgentsEndActivationNotification_h
#include "CATAfrFoundation.h"

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "CATNotification.h"

class CATCommand;

/**
 * Classe permettant de savoir lorsque l'état courant a fini d'activer ses agents
 */

class ExportedByCATAfrFoundation CATDialogAgentsEndActivationNotification : public CATNotification
{

 CATDeclareClass;

public:

  /** @nodoc */
  CATDialogAgentsEndActivationNotification ();
  virtual ~CATDialogAgentsEndActivationNotification (); 
  
private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATDialogAgentsEndActivationNotification (const CATDialogAgentsEndActivationNotification &);
  CATDialogAgentsEndActivationNotification & operator= (const CATDialogAgentsEndActivationNotification &);

};

#endif
