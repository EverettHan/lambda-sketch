#ifndef CATStateChangeNotification_h
#define CATStateChangeNotification_h
#include "CATAfrFoundation.h"

// COPYRIGHT DASSAULT SYSTEMES 2001
// protected CATAfrFrame.m

#include "CATNotification.h"

class CATCommand;
class CATStateCommand;
class CATDialogTransition;
class CATDialogState;

/**
 * Classe permettant de savoir lorsqu'il y a un changement d'état
 */

class ExportedByCATAfrFoundation CATStateChangeNotification : public CATNotification
{

 CATDeclareClass;

public:

  /** @nodoc */
  CATStateChangeNotification (CATCommand * iParent, CATDialogTransition * iTransition, CATDialogState * iOrigin, CATDialogState * iFinal);
  virtual ~CATStateChangeNotification (); 

  CATDialogTransition * GetTransition ();
  CATDialogState * GetOrigin ();
  CATDialogState * GetFinal ();
  CATStateCommand * GetParent ();
  
private:

  CATDialogTransition * _Transition;
  CATDialogState * _OriginState;
  CATDialogState * _FinalState;
  CATStateCommand * _Parent;

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATStateChangeNotification ();
  CATStateChangeNotification (const CATStateChangeNotification &);
  CATStateChangeNotification & operator= (const CATStateChangeNotification &);

};

#endif
