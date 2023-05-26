/* -*-C++-*- */
/*
#ifndef CATCVMNest_H
#define CATCVMNest_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMNest
//
// class for Collaborative Variational Modelling (CVM) nest operator
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Mar. 2006    Creation                         Alex State
//===================================================================

#include "CATCVMSysOperators.h"
#include "CATCVMSysOperator.h"
#include "ListPOfCATCVMSystem.h"
#include "ListPOfCATCVMAtom.h"

class CATCVMAtom;
class CATCVMHandle;
class CATCVMComponent;
class CATCVMSystem;
class CATCVMContainer;

class ExportedByCATCVMSysOperators CATCVMNest : public CATCVMSysOperator
{
  //------------------------------------------------------------------------------
  // Create a nest operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMNest *Create(CATCVMContainer *iContainer);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMNest(CATCVMContainer *iContainer);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public:
  virtual ~CATCVMNest();

  //------------------------------------------------------------------------------
  // Add an atom to nest
  //------------------------------------------------------------------------------
  public:
  void AddAtom(CATCVMAtom *iAtom);

  //------------------------------------------------------------------------------
  // Add a system to nest
  //------------------------------------------------------------------------------
  public:
  void AddSystem(CATCVMSystem *iSystem);

  //------------------------------------------------------------------------------
  // Run
  //------------------------------------------------------------------------------
  public:
  void Run();

  //------------------------------------------------------------------------------
  // Get resulting component
  //------------------------------------------------------------------------------
  public:
  CATCVMComponent *GetResultingComponent();

  //------------------------------------------------------------------------------
  // SingleAtomRun
  //------------------------------------------------------------------------------
  private:
  void SingleAtomRun(CATCVMAtom *iSingleAtom);

  //------------------------------------------------------------------------------
  // SingleSystemRun
  //------------------------------------------------------------------------------
  private:
  void SingleSystemRun(CATCVMSystem *iSingleSystem);

  //------------------------------------------------------------------------------
  // Create a new port in a given (new) component:
  // The new port points to a given handle and replaces that
  // handle with the new port in all ports and relations of a
  // given high component (that contains the new component)
  //------------------------------------------------------------------------------
  private:
  void ReplaceHandleWithNewPort(CATCVMComponent *iHighComponent,
                                CATCVMHandle    *iHandle,
                                CATCVMComponent *iNewComponent);

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  protected:
  ListPOfCATCVMSystem  _SystemList;
  ListPOfCATCVMAtom    _AtomList;
  CATCVMComponent     *_ResultingComponent;
};
#endif
*/
