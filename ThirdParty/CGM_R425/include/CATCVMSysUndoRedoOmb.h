/* -*-C++-*- */

#ifndef CATCVMSysUndoRedoOmb_H 
#define CATCVMSysUndoRedoOmb_H

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATCVMSysUndoRedoOmb :
// Classe générique permettant la gestion de l'undo/redo session CVM
//
//=============================================================================
// mars    2007  Création                    Etienne Bartholomot
//=============================================================================

//#define EB_CVMLog_AddCVMRef 

#include "CATCVMSysObjects.h"
#include "CATCVMSysUndoRedoMemento.h"
#include "CATCVMLog.h"
#include "CATCVMObject.h"
#include "ListPOfCATCVMObject.h"

class CATIContainer;

class ExportedByCATCVMSysObjects CATCVMSysUndoRedoOmb 
{

  // Standard constructors and destructors
  // -------------------------------------
private:
  CATCVMSysUndoRedoOmb ();
   //virtual ~CATCVMSysUndoRedoOmb ();
 
public:

	 static  HRESULT Activate (CATIContainer * iContainer);
   static  HRESULT Deactivate();
   static  CATBoolean IsUndoRedoActivated() ;
	 
	 // Local action storage
	 static  HRESULT LogAction(CATCVMLog * iCVMLog, CATCVMObject * iCVMObject, int iCVMEvent );
   
   // Global Actions List management
   static  HRESULT EndAction();      // Memento creation
   static  HRESULT ForgetAction();   // Undo last logged actions without visu
   static  HRESULT CleanUp();        // withdraw last logged actions only for CVMImportExport
   static  HRESULT UndoAction();     // Forget Action + visu management
   static  HRESULT SetUndoPoint();   // SetUndoPoint
   static  HRESULT ResetAction();    // Deprecated
      
   // pour le Paint
   static  HRESULT DoAction(ListPOfCATCVMObject &CATCVMObjectList, int iCVMEvent=CVMLogEvent_Modify);
   
   //-------------------------------------------------------------------------
   // Get The differential Logged CVMObjects during any run, especially the extrude multi run
   //-------------------------------------------------------------------------
   static  HRESULT GetLoggedCVMObjects (ListPOfCATCVMSystem      & oCVMBodyList,
                                        CATListOfInt             & oCVMObjectNumber,
                                        ListPOfCATCVMObject      & oCVMObjectList);
   //-------------------------------------------------------------------------
   // Release the differential Logged CVMObjects during any run, especially the extrude multi run
   // to be called in UpdateVisu after Event treatment
   //-------------------------------------------------------------------------
   static  HRESULT ReleaseLoggedCVMObjects () ;
   //-------------------------------------------------------------------------
   // Internal methods for CCP use only
   //-------------------------------------------------------------------------
   static  HRESULT MementoActivation();
   static  HRESULT MementoDeactivation();
   //-----------------------------------------------------------------------------
   // GetCurrentMemento
   //-----------------------------------------------------------------------------
   static  CATCVMSysUndoRedoMemento *  GetCurrentMemento( );

   static void DumpUndoRedoLog(ostream * iStream);
   //-------------------------------------------------------------------------
   // internal CVM usage 
   // GetLoggedCVMObjects
   //-------------------------------------------------------------------------
   static HRESULT GetLoggedCVMObjects (ListPOfCATCVMObject  & oCVMObjectList,
                                       CATListOfInt         & oCVMEventList,
                                       ListPOfCATCVMObject  & oCVMPhotoList);

private:
	 static  HRESULT BeginAction();
   static  HRESULT UnsetUndoPoint(); // UnsetUndoPoint
   static  CATCVMSysUndoRedoMemento * RestoreAction(CATCVMLog * iCVMLog);
   
private:
	CATCVMSysUndoRedoOmb(const CATCVMSysUndoRedoOmb &);//Necessary to prevent unwanted automatic creation by compiler
	CATCVMSysUndoRedoOmb operator = (const CATCVMSysUndoRedoOmb &);
};

//-----------------------------------------------------------------------

#endif

