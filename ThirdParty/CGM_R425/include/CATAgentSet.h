#ifndef CATAgentSet_H
#define CATAgentSet_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1996
// protected DI0STATE.m

//------------------------------------------------------------------------------
// Abstract: The basic class for a Set of Agents.
//           An AgentSet is used to group agents in order to
//           dispatch a notification to all the agents without stoping at the
//           first Accept or to make them be the Father (sense of send/receive)
//           of the same view.
//  
//------------------------------------------------------------------------------
// Usage:    allocate an object of this class
//           Add dialog agents to this object.
//           Declare the AgentSet as a DialogAgent of a state in a 
//           CATStateCommand
//
//------------------------------------------------------------------------------
// Inheritance: CATAgentSet (DialogEngine framework)
//                   CATDialogAgent    (DialogEngine framework)
//                       CATCommand       (System framework)
//------------------------------------------------------------------------------
// Main usable methods
//  
//           AddDialogAgent 
//           RemoveDialogAgent
//
//------------------------------------------------------------------------------

#include "CATDialogAgent.h"

#include "CATDlgEngUtility.h"

class CATCommand;
class CATString;
class CATLISTP(CATCommand);

class ExportedByCATDialogEngine CATAgentSet : public CATDialogAgent
{
  
  CATDeclareClass;
  
public:
  
  CATAgentSet (const CATString & Name, CATDlgEngBehavior Behavior=NULL);
  
  virtual ~CATAgentSet ();
  
  //-----------------------------------------------------------------
  // manage receivers
  //-----------------------------------------------------------------
  
  void AddDialogAgent (CATCommand * receiver);
  void RemoveDialogAgent (CATCommand * receiver);
  
  virtual void ResetPrevaluation ();

private:
  
  /*----------------------------------------------------------*/
  /* DE² DUMP	-DE² use-			*/
  /*----------------------------------------------------------*/
  /** @nodoc */
  CATLISTP(CATCommand) GetAgentList();

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATAgentSet ();
  CATAgentSet (const CATAgentSet &);
  CATAgentSet & operator= (const CATAgentSet &);
  
protected:
  
  /*----------------------------------------------------------*/
  /* Set/Retrieve the agent properties	-DE² use-			*/
  /*----------------------------------------------------------*/
  /** @nodoc */
  virtual HRESULT _SetProperty(CATUnicodeString iPropertyId, const CATListValCATBaseUnknown_var& ispPropValue);
  
  friend class CATDE2DumpCppStateCommand;
};

#endif
