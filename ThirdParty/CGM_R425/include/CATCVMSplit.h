/* -*-C++-*- */
/*
#ifndef CATCVMSplit_H
#define CATCVMSplit_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMSplit
//
// class for Collaborative Variational Modelling (CVM) split operator
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

class ExportedByCATCVMSysOperators CATCVMSplit : public CATCVMSysOperator
{
  //------------------------------------------------------------------------------
  // Create a Split operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMSplit *Create(CATCVMContainer *iContainer,
                             CATCVMSystem    *iSystem,
                             CATCVMSystem    *iResultingSystem = NULL);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMSplit(CATCVMContainer *iContainer,
              CATCVMSystem    *iSystem,
              CATCVMSystem    *iResultingSystem = NULL);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public:
  virtual ~CATCVMSplit();

  //------------------------------------------------------------------------------
  // Add an atom to extract
  //------------------------------------------------------------------------------
  public:
  void AddAtom(CATCVMAtom *iAtom);

  //------------------------------------------------------------------------------
  // Add a system to extract
  //------------------------------------------------------------------------------
  public:
  void AddSystem(CATCVMSystem *iSystem);

  //------------------------------------------------------------------------------
  // Run
  //------------------------------------------------------------------------------
  public:
  void Run();

  //------------------------------------------------------------------------------
  // Get resulting system
  //------------------------------------------------------------------------------
  public:
  CATCVMSystem *GetResultingSystem();

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  protected:
  ListPOfCATCVMSystem  _SystemList;
  ListPOfCATCVMAtom    _AtomList;
  CATCVMSystem        *_System;
  CATCVMSystem        *_ResultingSystem;
};
#endif
*/
