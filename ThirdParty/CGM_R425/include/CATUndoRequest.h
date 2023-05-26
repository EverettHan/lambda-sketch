#ifndef CATUndoRequest_h
#define CATUndoRequest_h
#include "UndoRedoUI.h"

// COPYRIGHT DASSAULT SYSTEMES 1996-2008

//------------------------------------------------------------------------------
// The base class for an Undo step object.
//------------------------------------------------------------------------------
// Standard use :
//
//  OmbUndoRedoContext context; // default context
//  CATUndoRequest * undoRequest = CATUndoRequest::Create("NLS title describing the step",context);
//  if (undoRequest)
//  {
//    ...
//  }
//------------------------------------------------------------------------------
// Derivation :
//
//  Calling the Manage method after creating a CATUndoRequest instance is mandatory
//  in order to add it in the UI Undo stack.
//  So it is strongly recommended to create a Create static method as for the base class so that it is easier to use.
//------------------------------------------------------------------------------
#include "CATBaseUnknown.h"

#include "CATUnicodeString.h"
#include "CATString.h"

class CATUndoRequest;
class CATListPtrCATUndoRequest;
class OmbUndoRedoContext; // defined in CATOmbUndoRedoDefs.h

class ExportedByUndoRedoUI  CATUndoRequest : public CATBaseUnknown
{

	CATDeclareClass;

	public:

		static CATUndoRequest * Create (const CATUnicodeString & iTitle,
			OmbUndoRedoContext & iContext);

		virtual ~CATUndoRequest ();


		//-------------------------------------------------------
		//  association with model transactions 
		//------------------------------------------------------- 

		void AddTransaction (int trans);
		int GetFirstTransaction ();
		void SetTransactionNumber (int trans);  

		//-------------------------------------------------------
		//  For internal use only 
		//------------------------------------------------------- 

		// execution of Undo or Redo

		virtual void Undo ();
		virtual void Redo ();
		virtual void BeforeUndoCommand ();
		virtual void BeforeRedoCommand ();
		virtual void AfterUndoCommand ();
		virtual void AfterRedoCommand ();

		void AddUndoUntilNum (int num);
		void RemoveUndoFromList (CATUndoRequest * Undo);
		void SetUndoParent (CATUndoRequest * Undo);
		void BeforeUndoUntilNum ();
		void BeforeRedoUntilNum ();
		void AfterUndoUntilNum ();
		void AfterRedoUntilNum ();

		int IsPurgeable ();
		int IsExclusive ();
		void SetExclusive (int Exclusive);
		void SetPurgeable (int Purgeable);

		// is Redo planned ?
		virtual int RedoRegistered ();

		// management of Undo and Redo in stacks
		virtual void InRedoStack (int num);
		virtual void InStack (int num);
		virtual int GetNumInStack ();
		virtual int GetUniqueID ();
		virtual void ResetNumInStack ();
		virtual void ResetNumInRedoStack ();

		void SetTitle (const CATUnicodeString & title1, const CATUnicodeString & title2);
		CATUnicodeString & GetUndoTitle ();
		CATUnicodeString & GetRedoTitle ();

		// local save
		void SetLocalSave (CATBoolean iValue);
		CATBoolean GetLocalSave ();

		CATUndoRequest * _UndoParent;
		CATListPtrCATUndoRequest * _UndoList;

		void				SetUndoOfRepeatedCommand(const CATString & iCmdRepeatedName);
		CATBoolean			IsUndoRedoOfRepeatedCommand();
		const CATString&	GetRepeatedCommandName();

	protected:

		/**
		* Constructs an Undo step and adds it in the UI Undo stack.
		* @param iTitle
		*   The step identifier. It is displayed in the Undo/Redo Overview display box.
		*/
		CATUndoRequest (const CATUnicodeString & iTitle);

		/**
		* To use immediately after Ctor so that the instance is appended in the UI Undo stack
		* and taken into account in the UI Undo/Redo management.
		* @param iContext
		*   Command context.
		* @return
		* <dl>
		* <dt> <tt>S_OK</tt>    <dd> The instance has been appended in the Undo stack.
		* <dt> <tt>S_FALSE</tt> <dd> The Undo stack has been dumped meanwhile.
		* <dt> <tt>E_FAIL</tt>  <dd> The Undo stack is locked.
		* </dl>
		*/
		virtual HRESULT Manage (OmbUndoRedoContext & iContext);

		int _num_in_stack;
		int _num_in_Redostack;
		int _inRedoStack;
		CATUnicodeString  _UndoTitle;
		CATUnicodeString  _RedoTitle;
		int _TransactionNumber;
		int _UntilNum;
		int _Purgeable;
		int _Exclusive;
		CATBoolean _triggersLocalSave;

	private:

		// NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
		CATUndoRequest (const CATUndoRequest &);
		CATUndoRequest & operator= (const CATUndoRequest &);

		CATBoolean _repeatedCommand;
		CATString  _repeatedCommandName;
    int        _undoStepUniqueId;
};

#endif
 
