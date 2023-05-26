#ifndef CATStateAgentEndNotification_h
#define CATStateAgentEndNotification_h
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1996
// protected DI0GRAF.m

//------------------------------------------------------------------------------
// Abstract: The basic class for a Cancel notification inside a CATStateCommand
//------------------------------------------------------------------------------
// Inheritance: CATStateAgentEndNotification (DialogEngine framework)
//                CATNotification (System framework)
//------------------------------------------------------------------------------

#include "CATNotification.h"

class ExportedByCATDialogEngine CATStateAgentEndNotification : public CATNotification
{

 CATDeclareClass;
 
public:
  
  enum AgentEndType { End, Cancel };
  
  CATStateAgentEndNotification (AgentEndType=End);

  virtual ~CATStateAgentEndNotification ();
  
  /*------------------------------------------------------------*/
  /* Get the type to know whether the command begins or resumes */
  /*------------------------------------------------------------*/
  
  AgentEndType GetType ();
  
private:
  
  AgentEndType _type;

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATStateAgentEndNotification (const CATStateAgentEndNotification &);
  CATStateAgentEndNotification & operator= (const CATStateAgentEndNotification &);
  
};

#endif
