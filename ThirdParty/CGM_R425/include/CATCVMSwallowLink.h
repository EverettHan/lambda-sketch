/* -*-C++-*- */
/*
#ifndef CATCVMSwallowLink_H
#define CATCVMSwallowLink_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMSwallowLink
//
// class for Collaborative Variational Modelling (CVM) delete operator
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
#include "ListPOfCATCVMRelation.h"
#include "CATCVMComponent.h"
#include "CATBoolean.h"
#include "CATListOfInt.h"

class CATCVMContainer;

class ExportedByCATCVMSysOperators CATCVMSwallowLink : public CATCVMSysOperator
{
  //------------------------------------------------------------------------------
  // Create a delete operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMSwallowLink *Create(CATCVMContainer *iContainer);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMSwallowLink(CATCVMContainer *iContainer);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public:
  virtual ~CATCVMSwallowLink();

  //------------------------------------------------------------------------------
  // Add a relation to swallow
  //------------------------------------------------------------------------------
  public:
  void AddRelation(CATCVMRelation *iRelation);

  //------------------------------------------------------------------------------
  // Set the system that will swallow the links
  //------------------------------------------------------------------------------
  public:
  void SetComponent(CATCVMComponent * iComponent);

  //------------------------------------------------------------------------------
  // Run
  //------------------------------------------------------------------------------
  public:
  void Run();

  //------------------------------------------------------------------------------
  // Swallow relation
  //------------------------------------------------------------------------------
  private:
  void SwallowRelation(CATCVMRelation *iRelation);

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  protected:
  ListPOfCATCVMRelation _RelationList;
  CATCVMComponent * _Component;
};
#endif
*/
