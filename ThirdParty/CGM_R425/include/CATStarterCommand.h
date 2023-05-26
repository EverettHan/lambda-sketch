#ifndef CATStarterCommand_H
#define CATStarterCommand_H
#include "CATAfrFoundation.h"

// COPYRIGHT DASSAULT SYSTEMES 2003
// protected Headers.m

#include "CATCommand.h"

#include "CATString.h"
#include "CATBooleanDef.h"
#include "CATAfrCommandHeaderArgs.h"
class CATNotification;

/**
 * Command starter
 * Must be used in CATCommandHeader and CATIAApplicationImpl only.
 * <b>Role</b>: The Command Starter has been created to be able
 * to use StartCommand in macros.
 */

class ExportedByCATAfrFoundation CATStarterCommand : public CATCommand
{
  
  /** @nodoc */
  CATDeclareClass;
  
public:
  
  /** @nodoc */
  CATStarterCommand ();

  /** @nodoc */   
  virtual ~CATStarterCommand ();

  /** @nodoc */   
  static void SetAutomationMode (CATBoolean iAutomation);
  /** @nodoc */   
  static CATBoolean GetAutomationMode ();
  
  /** @nodoc */   
  CATCommand * StartCommand (const CATString & Class,
                             const CATString & Name,
                             void * Arg);

private:

  static CATBoolean _automation;

  /** @nodoc */
  void StarterCB (CATCommand * sendObject,
                  CATNotification * evt,
                  CATCommandClientData data);

  CATString _class;
  CATString _name;
  void * _arg;
  CATCommand * _createdCommand;

  //New arguments for Command Headers
  CATAfrCommandHeaderArgs _argsList;

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATStarterCommand (const CATStarterCommand &);
  CATStarterCommand & operator= (const CATStarterCommand &);
  
};

#endif
