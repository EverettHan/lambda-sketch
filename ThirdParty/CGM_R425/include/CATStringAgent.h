#ifndef CATStringAgent_H
#define CATStringAgent_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0APPLI.m

#include "CATAcquisitionAgent.h"

#include "CATString.h"
#include "CATListOfCATString.h"
#include "CATDlgEngUtility.h"

class CATCommand;
class CATNotification;

//-----------------------------------------------------------------------------
class ExportedByCATDialogEngine CATStringAgent : public CATAcquisitionAgent
{
  
  CATDeclareClass;
  
public:
  
  //------
  // 'tors
  //------
  CATStringAgent (const CATString & commandName, CATDlgEngBehavior Behavior=NULL);
  virtual ~CATStringAgent ();
  
  //------------------
  // Value management
  //------------------
  
  virtual const CATString & GetValue ();
  virtual void SetValue (const CATString & value );
  
  //------------------
  // decode management
  //------------------
  
  virtual void * DecodeNotification (CATCommand * from, CATNotification * notif); 
  
  //------------------
  // Undo and Redo management
  //------------------
  
  virtual void * UndoValue ();
  virtual void * RedoValue ();
  virtual void InitializeValue ();
  virtual void StoreValue ();
  virtual void ResetValue ();
  
  //------------------
  // CSO management
  //------------------
  
  virtual void PutIntoPSO ();
  virtual void RemoveFromPSO ();
  virtual void PutIntoHSO ();
  virtual void RemoveFromHSO ();
  
protected:
  
  CATString _Empty;    
  CATString _value;    
  CATString _preValue;    
  CATString _tempValue;    
  int _currentValueInd;
  CATListOfCATString _valueStack;

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATStringAgent ();
  CATStringAgent (const CATStringAgent &);
  CATStringAgent & operator= (const CATStringAgent &);  

};

#endif
