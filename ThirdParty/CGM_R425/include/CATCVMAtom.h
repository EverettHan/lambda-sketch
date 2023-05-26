/* -*-C++-*- */

#ifndef CATCVMAtom_H
#define CATCVMAtom_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMObject
//
// class for Collaborative Variational Modelling (CVM) atoms
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Feb. 2006    Creation                         Alex State
//===================================================================
#include "CATCVMSysObjects.h"
#include "CATCVMHandle.h"
#include "CATCVMObject.h"
#include "CATCVMDef.h"
#include "CATUnicodeString.h"
#include "CATBoolean.h"
#include "CATCGMNewArray.h"

class CATCVMSystem;
class CATCVMCopy;

class ExportedByCATCVMSysObjects CATCVMAtom : public CATCVMHandle
{
  //------------------------------------------------------------------------------
  // Component declaration
  //------------------------------------------------------------------------------
  CATDeclareClass;

  //------------------------------------------------------------------------------
  // Constructors
  //------------------------------------------------------------------------------
  protected:
  CATCVMAtom(CATCVMContainer *iContainer);
  CATCGMNewClassArrayDeclare;

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMAtom();

  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
  public:
  virtual CATBoolean IsA(CATCVMObjectType iObjectType);

  //------------------------------------------------------------------------------
  // Create a copy
  //------------------------------------------------------------------------------
  public:
  virtual CATCVMObject *CreateCopy(CATCVMCopy   *iCopy) = 0;
  
  virtual void IdenticalDataCopy(CATCVMObject * iCVMPrev);
  void LocalDataCopy(CATCVMAtom *iCVMPrev);

  //------------------------------------------------------------------------------
  // Swap Definition from CVMPhoto for Undo / Redo Treatment
  //------------------------------------------------------------------------------
  virtual void  UndoRedoDataSwapping(CATCVMObject *iCVMObject, int iCVMEvent);

  //------------------------------------------------------------------------------
  // Release data
  //------------------------------------------------------------------------------
  public:
  virtual void ReleaseData();

  //------------------------------------------------------------------------------
  // GetSystem
  //------------------------------------------------------------------------------
  public:
  CATCVMSystem *GetSystem();
  
  //------------------------------------------------------------------------------
  // GetTypeName
  //------------------------------------------------------------------------------
  public:
  virtual CATUnicodeString GetTypeName();

  //------------------------------------------------------------------------------
  // Chain management
  //------------------------------------------------------------------------------
  public:
  virtual CATCVMObject *Get_Atom_Next();
  virtual CATCVMObject *Get_Atom_Prev();
  virtual void Set_Atom_Next(CATCVMObject * iCVMNext);
  virtual void Set_Atom_Prev(CATCVMObject * iCVMPrev);
  virtual void RemoveFromAtomLoop();

  private:
  CATCVMObject * _Atom_Prev;
  CATCVMObject * _Atom_Next;

};
#endif
