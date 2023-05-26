/* -*-C++-*- */
/*
#ifndef CATCVMGeoUndoRedo_H
#define CATCVMGeoUndoRedo_H

// COPYRIGHT DASSAULT SYSTEMES 2005

//===================================================================
//===================================================================
//
// CATCVMGeoUtilties
//
// Internal geometric utilities for Collaborative Variational
// Modelling (CVM)
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Mar. 2006    Creation                         Alex State
//===================================================================

#include "CATCVMGeoObjects.h"
#include "CATCVMGeoContainer.h"
#include "CATCVMStreamArea.h"
#include "CATDataType.h"

class ExportedByCATCVMGeoObjects CATCVMGeoUndoRedo
{
  //------------------------------------------------------------------------------
  // Save, Undo, Redo methods (one shot, but it's possible to
  // endlessly alternate between undo and redo)
  //------------------------------------------------------------------------------
  public:
	static void Save (CATCVMGeoContainer *  iCVMGeoContainer);
  static void Undo (CATCVMGeoContainer * &ioCVMGeoContainer);
  static void Redo (CATCVMGeoContainer * &ioCVMGeoContainer);
  static void Close();
  
  static CATBoolean IsUndoPossible();
  static CATBoolean IsRedoPossible();
  //------------------------------------------------------------------------------
  private:
  
  static void Stream  (CATCVMGeoContainer *&ioCVMGeoContainer, void *&ioCVMStreamArea);
  static void Unstream(CATCVMGeoContainer *&ioCVMGeoContainer, void *&ioCVMStreamArea);
  
  private:
      CATCVMGeoUndoRedo();
      CATCVMGeoUndoRedo(const CATCVMGeoUndoRedo &);//Necessary to prevent unwanted automatic creation by compiler
      void operator = (const CATCVMGeoUndoRedo &);

};
#endif
*/


