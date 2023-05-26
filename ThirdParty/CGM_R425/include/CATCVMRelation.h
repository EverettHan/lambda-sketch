/* -*-C++-*- */

#ifndef CATCVMRelation_H
#define CATCVMRelation_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMObject
//
// class for Collaborative Variational Modelling (CVM) relations
// A CATCVMRelation belongs to a CATCVMComponent and links 1..N CATCVMhandle 
// (ie CATCVMPort or CATCVMAtom). The handles must be one of the 2 following:
// -- Atom or Port of the Component owning this
// -- Port of Subcomponent of the Component owning this
//
// Handles must be added, removed or replaced using the operator CATCVMRelationManager
//
// A role is associated to each handle. This is an integer whose meaning must be defined
// in each leaf class; for example, in a symmetry constraint, the symmetry axis must have
// a different "role" from the 2 symmetric geometries to be processed correctly by the
// constraint solver
//===================================================================
// Feb. 2006    Creation                         Alex State
//===================================================================
#include "CATCVMSysObjects.h"
#include "CATCVMObject.h"
#include "CATCVMDef.h"
#include "ListPOfCATCVMHandle.h"
#include "CATListOfInt.h"
#include "CATCGMNewArray.h"

class CATCVMComponent;
class CATCVMCopy;

class ExportedByCATCVMSysObjects CATCVMRelation : public CATCVMObject
{
  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMRelation(CATCVMContainer *iContainer);
  CATCGMNewClassArrayDeclare;

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMRelation();

  //------------------------------------------------------------------------------
  // CleanUp
  //------------------------------------------------------------------------------
  public:
  virtual void CleanUp(CATBoolean iCompleteRemoval = FALSE);

  public:
 /**
  *This method must be defined in each leaf class. 
  *Return 1 if this has the right number and types of handle to be considered effective; 
  *else return 0.
  *Example: for a distance constraint, this method returns 1 if there are exactly 3 handles:
  *2 CVMGeometry and 1 CATCVMDouble
  */
  virtual CATBoolean HasCorrectHandles() = 0;  

  public:
 /**
  *Return 1 if this relation must be considered active; 
  *else return 0.
  *The method ToggleActivity() toggles the result of the method IsActive()
  *By default (ie at the creation of this) it returns 1
  */
  virtual CATBoolean IsActive();  
  public:
 /**
  *Toggle the result of the method IsActive()
  */
  virtual void ToggleActivity();  

  //------------------------------------------------------------------------------
  // SetComponent
  //------------------------------------------------------------------------------
  public:
  void SetComponent(CATCVMComponent *iComponent);

  //------------------------------------------------------------------------------
  // GetComponent
  //------------------------------------------------------------------------------
  public:
  CATCVMComponent *GetComponent();

  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
  public:
  CATBoolean IsA(CATCVMObjectType iObjectType);

  //------------------------------------------------------------------------------
  // Get the number of handles
  //------------------------------------------------------------------------------
  public:
  int GetNbHandles();

  //------------------------------------------------------------------------------
  // Get the handle for a given index
  //------------------------------------------------------------------------------
  public:
  CATCVMHandle *GetHandle(int iIndex);

  //------------------------------------------------------------------------------
  // Get the number of handles whose atom is of type iAtomType
  //------------------------------------------------------------------------------
  public:
  int GetNbHandles(CATCVMObjectType iAtomType);

  //------------------------------------------------------------------------------
  // Get the handle for a given index among the subset of handles whose atom is of type iAtomType
  //------------------------------------------------------------------------------
  public:
  CATCVMHandle *GetHandle(CATCVMObjectType iAtomType, int iIndex);

  //------------------------------------------------------------------------------
  // Get iHandle role
  // See above general comments of class for role description
  //------------------------------------------------------------------------------
  public:
  int GetHandleRole(CATCVMHandle * iHandle);

  //------------------------------------------------------------------------------
  // Get the role of the handle at iIndex
  // See above general comments of class for role description
  //------------------------------------------------------------------------------
  public:
  int GetHandleRole(int iIndex);

  //------------------------------------------------------------------------------
  // Return
  // 0 if the pair (iHandle, iRole) is a valid argument for this; 
  // 1 otherwise
  //------------------------------------------------------------------------------
  public:
  virtual CATBoolean IsValidArgument(CATCVMHandle * iHandle, int iRole) = 0;



  //------------------------------------------------------------------------------
  // THIS METHOD IS FOR INTERNAL USE ONLY
  // To add or remove handle, the operator CATCVMRelationManager must be used
  //------------------------------------------------------------------------------
  public:
  virtual void AddHandle(CATCVMHandle *iHandle, int iRole);

  //------------------------------------------------------------------------------
  // THIS METHOD IS FOR INTERNAL USE ONLY
  // To add, remove or replace a handle, the operator CATCVMRelationManager must be used
  //------------------------------------------------------------------------------
  public:
  virtual void RemoveHandle(int iIndex);

  //------------------------------------------------------------------------------
  // THIS METHOD IS FOR INTERNAL USE ONLY
  // To add, remove or replace a handle, the operator CATCVMRelationManager must be used
  //------------------------------------------------------------------------------
  public:
  void RemoveHandle(CATCVMHandle *iHandle);

  //------------------------------------------------------------------------------
  // THIS METHOD IS FOR INTERNAL USE ONLY
  // To add, remove or replace a handle, the operator CATCVMRelationManager must be used
  //------------------------------------------------------------------------------
  public:
  virtual void ReplaceHandle(CATCVMHandle *iNewHandle, CATCVMHandle *iOldHandle);

  //------------------------------------------------------------------------------
  // Duplicate the handles
  //------------------------------------------------------------------------------
  public:
  void DuplicateHandles(CATCVMRelation *iToRelation,
                        CATCVMCopy     *iCopy);

  //------------------------------------------------------------------------------
  // Create a copy (the pointed handles must already be duplicated)
  //------------------------------------------------------------------------------
  public:
  virtual CATCVMRelation *CreateCopy(CATCVMCopy      *iCopy) = 0;

  //------------------------------------------------------------------------------
  // UndoRedo method
  //------------------------------------------------------------------------------
  void  UndoRedoDataSwapping (CATCVMObject *iCVMObject, int iCVMEvent);
  
  //------------------------------------------------------------------------------
  // GetTypeName
  //------------------------------------------------------------------------------
  public:
  virtual CATUnicodeString GetTypeName();

  //------------------------------------------------------------------------------
  // Get CVM container
  //------------------------------------------------------------------------------
  public:
  virtual CATCVMContainer *GetContainer();

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  protected:
  CATCVMComponent     *_Component;
  ListPOfCATCVMHandle  _HandleList;
  CATListOfInt _RoleList;
  CATBoolean _IsActive;
private:
CATCVMRelation(const CATCVMRelation &);//Necessary to prevent unwanted automatic creation by compiler
void operator = (const CATCVMRelation &);

};
#endif
