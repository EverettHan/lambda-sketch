#ifndef CATAfrCommandActivateNotification_h
#define CATAfrCommandActivateNotification_h
#include "CATAfrFoundation.h"

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "CATNotification.h"

class CATCommand;


/**
 * Evenement permettant de modifier la palette suite a l'activation d'une CATCommand.
 * La modification est prise en compte jusqu'a la prochaine activation de commande.
 */

class ExportedByCATAfrFoundation CATAfrCommandActivateNotification : public CATNotification
{

 CATDeclareClass;

public:

  enum ActivationNotifType { Begin, Resume, ResumeThenLocalUndo };

  /** @nodoc */
  CATAfrCommandActivateNotification (ActivationNotifType activationType,
                                     CATCommand *activatedCommand);
  virtual ~CATAfrCommandActivateNotification (); 

  CATAfrCommandActivateNotification::ActivationNotifType GetActivationType ();
  CATCommand * GetActivatedCommand ();

  
private:

  ActivationNotifType _ActivationType;
  CATCommand        * _ActivatedCommand;

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATAfrCommandActivateNotification ();
  CATAfrCommandActivateNotification (const CATAfrCommandActivateNotification &);
  CATAfrCommandActivateNotification & operator= (const CATAfrCommandActivateNotification &);

};

#endif
