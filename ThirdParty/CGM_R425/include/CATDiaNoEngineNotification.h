#include "UndoRedoUI.h"
#ifndef CATDiaNoEngineNotification_H_
#define CATDiaNoEngineNotification_H_

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATNotification.h"
#include "CATBooleanDef.h"

class CATUndoRequest;

class ExportedByUndoRedoUI CATStackUndoNotif : public CATNotification
{
  CATDeclareClass;

  public:
   CATStackUndoNotif (CATUndoRequest * Undo);
   virtual ~CATStackUndoNotif();

   CATUndoRequest * _Undo;

};

class ExportedByUndoRedoUI CATUnstackUndoNotif : public CATNotification
{
  CATDeclareClass;

  public:
   CATUnstackUndoNotif (CATUndoRequest * Undo);
   virtual ~CATUnstackUndoNotif();

   CATUndoRequest * _Undo;

};

class ExportedByUndoRedoUI CATDeleteAllUndoNotif : public CATNotification
{
  CATDeclareClass;

  public:
   CATDeleteAllUndoNotif ();
   virtual ~CATDeleteAllUndoNotif();

};

class ExportedByUndoRedoUI CATStackRedoNotif : public CATNotification
{
  CATDeclareClass;

  public:
   CATStackRedoNotif ();
   virtual ~ CATStackRedoNotif();

};

class ExportedByUndoRedoUI CATUnstackRedoNotif : public CATNotification
{
  CATDeclareClass;

  public:
   CATUnstackRedoNotif ();
   virtual ~ CATUnstackRedoNotif();

};

class ExportedByUndoRedoUI CATDeleteAllRedoNotif : public CATNotification
{
  CATDeclareClass;

  public:
   CATDeleteAllRedoNotif ();
   virtual ~ CATDeleteAllRedoNotif();

};

class ExportedByUndoRedoUI CATChangeDoTitleNotif : public CATNotification
{
  CATDeclareClass;

  public:
   CATChangeDoTitleNotif ();
   virtual ~ CATChangeDoTitleNotif();

};

class ExportedByUndoRedoUI CATChangeDoAvailabilityNotif : public CATNotification
{
  CATDeclareClass;

  public:
   CATChangeDoAvailabilityNotif ();
   virtual ~ CATChangeDoAvailabilityNotif();

};

class ExportedByUndoRedoUI CATBeforeUndoNotif : public CATNotification
{
  CATDeclareClass;

  public:
   CATBeforeUndoNotif (CATUndoRequest * Undo);
   virtual ~CATBeforeUndoNotif();

   CATUndoRequest * _Undo;

};

class ExportedByUndoRedoUI CATAfterUndoNotif : public CATNotification
{
  CATDeclareClass;

  public:
   CATAfterUndoNotif ();
   virtual ~CATAfterUndoNotif();

};

class ExportedByUndoRedoUI CATBeforeRedoNotif : public CATNotification
{
  CATDeclareClass;

  public:
   CATBeforeRedoNotif (CATUndoRequest * Undo);
   virtual ~CATBeforeRedoNotif ();

   CATUndoRequest * _Undo;

};

class ExportedByUndoRedoUI CATAfterRedoNotif : public CATNotification
{
  CATDeclareClass;

  public:
   CATAfterRedoNotif ();
   virtual ~CATAfterRedoNotif();

};

class ExportedByUndoRedoUI CATNewTransactionNotif : public CATNotification
{
  CATDeclareClass;

  public:
   CATNewTransactionNotif (CATBoolean iGlobal, int iNumber);
   virtual ~CATNewTransactionNotif ();

   CATBoolean _global;
   int _number;
};

class ExportedByUndoRedoUI CATChangeStackStatusNotif : public CATNotification
{
  CATDeclareClass;

  public:
   CATChangeStackStatusNotif (int iStatus, CATBoolean iStepRemoved, CATBoolean iStackFlushedWithoutSave);
   virtual ~CATChangeStackStatusNotif ();

   // 0 : empty
   // 1 : neither empty nor full
   // 2 : becomes full
   // 3 : full
   int _status;
   CATBoolean _stepRemoved; // TRUE if at least one step of the stack has been unstacked
   CATBoolean _stackFlushedWithoutSave; // TRUE if the stack has been flushed without Save operation
};

#endif
 
