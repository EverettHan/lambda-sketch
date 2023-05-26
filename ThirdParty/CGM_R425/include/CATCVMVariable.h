/* -*-C++-*- */

#ifndef CATCVMVariable_H
#define CATCVMVariable_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMObject
//
// class for Collaborative Variational Modelling (CVM) variables
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
#include "CATCVMAtom.h"
#include "CATCVMDef.h"
#include "CATCGMNewArray.h"

class CATCVMSystem;

class ExportedByCATCVMGeoObjects CATCVMVariable : public CATCVMAtom
{
  //------------------------------------------------------------------------------
  // Constructors
  //------------------------------------------------------------------------------
  protected:
  CATCVMVariable(CATCVMContainer *iContainer);
  CATCGMNewClassArrayDeclare; 

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMVariable();

  //------------------------------------------------------------------------------
  // UndoRedo method
  //------------------------------------------------------------------------------
  void  UndoRedoDataSwapping (CATCVMObject *iCVMObject, int iCVMEvent);

  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
  public:
  virtual CATBoolean IsA(CATCVMObjectType iObjectType);
};
#endif
