#ifndef CATAgentNotification_H_
#define CATAgentNotification_H_
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0STATE.m

#include "CATNotification.h"

//-----------------------------------------------------------------------------
class ExportedByCATDialogEngine CATAgentAcceptNotif : public CATNotification
{
  CATDeclareClass;
  
public:

  CATAgentAcceptNotif ();
  virtual ~CATAgentAcceptNotif ();

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATAgentAcceptNotif (const CATAgentAcceptNotif &);
  CATAgentAcceptNotif & operator= (const CATAgentAcceptNotif &);
};

//-----------------------------------------------------------------------------
class ExportedByCATDialogEngine CATAgentActivateNotif : public CATNotification
{
  CATDeclareClass;
  
public:

  CATAgentActivateNotif ();
  virtual ~CATAgentActivateNotif ();

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATAgentActivateNotif (const CATAgentActivateNotif &);
  CATAgentActivateNotif & operator= (const CATAgentActivateNotif &);
};

//-----------------------------------------------------------------------------
class ExportedByCATDialogEngine CATAgentDesactivateNotif : public CATNotification
{
  CATDeclareClass;
  
public:

  CATAgentDesactivateNotif ();
  virtual ~CATAgentDesactivateNotif ();

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATAgentDesactivateNotif (const CATAgentDesactivateNotif &);
  CATAgentDesactivateNotif & operator= (const CATAgentDesactivateNotif &);
};

//-----------------------------------------------------------------------------
class ExportedByCATDialogEngine CATAgentCancelNotif : public CATNotification
{
  CATDeclareClass;
  
public:

  CATAgentCancelNotif ();
  virtual ~CATAgentCancelNotif ();

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATAgentCancelNotif (const CATAgentCancelNotif &);
  CATAgentCancelNotif & operator= (const CATAgentCancelNotif &);
};

//-----------------------------------------------------------------------------
class ExportedByCATDialogEngine CATAgentValuationNotif : public CATNotification
{
  CATDeclareClass;
  
public:

  CATAgentValuationNotif ();
  virtual ~CATAgentValuationNotif ();

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATAgentValuationNotif (const CATAgentValuationNotif &);
  CATAgentValuationNotif & operator= (const CATAgentValuationNotif &);
};

//-----------------------------------------------------------------------------
class ExportedByCATDialogEngine CATAgentResetValuationNotif : public CATNotification
{
  CATDeclareClass;
  
public:

  CATAgentResetValuationNotif ();
  virtual ~CATAgentResetValuationNotif ();

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATAgentResetValuationNotif (const CATAgentResetValuationNotif &);
  CATAgentResetValuationNotif & operator= (const CATAgentResetValuationNotif &);
};

//-----------------------------------------------------------------------------
class ExportedByCATDialogEngine CATAgentPrevaluationNotif : public CATNotification
{
  CATDeclareClass;
  
public:

  CATAgentPrevaluationNotif ();
  virtual ~CATAgentPrevaluationNotif ();

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATAgentPrevaluationNotif (const CATAgentPrevaluationNotif &);
  CATAgentPrevaluationNotif & operator= (const CATAgentPrevaluationNotif &);
};

//-----------------------------------------------------------------------------
class ExportedByCATDialogEngine CATAgentResetPrevaluationNotif : public CATNotification
{
  CATDeclareClass;
  
public:

  CATAgentResetPrevaluationNotif ();
  virtual ~CATAgentResetPrevaluationNotif ();

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATAgentResetPrevaluationNotif (const CATAgentResetPrevaluationNotif &);
  CATAgentResetPrevaluationNotif & operator= (const CATAgentResetPrevaluationNotif &);
};

#endif
