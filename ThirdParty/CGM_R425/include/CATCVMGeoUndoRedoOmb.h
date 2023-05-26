/* -*-C++-*- */

#ifndef CATCVMGeoUndoRedoOmb_H 
#define CATCVMGeoUndoRedoOmb_H

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATCVMGeoUndoRedoOmb :
// Classe générique permettant la gestion de l'undo/redo session CVM
//
//=============================================================================
// mars    2007  Création                    Etienne Bartholomot
//=============================================================================

#include "CATCVMGeoObjects.h"

#include "ListPOfCATCVMBody.h"
#include "CATIContainer.h"

class ExportedByCATCVMGeoObjects CATCVMGeoUndoRedoOmb 
{

  // Standard constructors and destructors
  // -------------------------------------
private:
  CATCVMGeoUndoRedoOmb ();
   //virtual ~CATCVMGeoUndoRedoOmb ();
 
public:

	 static  HRESULT Activate (CATIContainer * iContainer);
   static  HRESULT Activate (CATIContainer * iContainer, ListPOfCATCVMBody &iCVMBodyList);
   static  HRESULT Activate (ListPOfCATCVMBody &iCVMBodyList);
   static  HRESULT Deactivate();

	 static  HRESULT BeginAction();
	 static  HRESULT DoAction();
   static  HRESULT EndAction();
   static  HRESULT ForgetAction();
	 
private:
	CATCVMGeoUndoRedoOmb(const CATCVMGeoUndoRedoOmb &);//Necessary to prevent unwanted automatic creation by compiler
	CATCVMGeoUndoRedoOmb operator = (const CATCVMGeoUndoRedoOmb &);
};

//-----------------------------------------------------------------------

#endif

