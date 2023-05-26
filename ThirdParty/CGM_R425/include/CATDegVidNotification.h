#ifndef CATDegVidNotification_h
#define CATDegVidNotification_h
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 2012
// fw DialogEngine
// protected CATCmdDialogAgents.m

//------------------------------------------------------------------------------
// Abstract: The notification used by a CATVidDialogAgent to hold a VID event
//------------------------------------------------------------------------------
// Inheritance: CATDegVidNotification (DialogEngine framework)
//                CATNotification (System framework)
//------------------------------------------------------------------------------

#include "CATNotification.h"
#include "CATSYPEventArgs.h"

class ExportedByCATDialogEngine CATDegVidNotification : public CATNotification
{

 CATDeclareClass;
 
public:
  
  CATDegVidNotification (CATSYPEventArgs * iArgs);

  virtual ~CATDegVidNotification ();

  CATSYPEventArgs * GetArgs ();

private:

  CATSYPEventArgs * _args;

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATDegVidNotification (const CATDegVidNotification &);
  CATDegVidNotification & operator= (const CATDegVidNotification &);
  
};

#endif
