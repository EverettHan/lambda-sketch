/* -*-C++-*- */

#ifndef CATCVMCheck_H
#define CATCVMCheck_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMCheck
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
#include "CATBoolean.h"
#include "CATListOfInt.h"
#include "CATErrorDef.h"

class CATCGMOutput;
class CATCVMInstance;
class CATCVMComponent;
class CATCVMReference;
class CATCVMOccurrence;

class ExportedByCATCVMSysOperators CATCVMCheck : public CATCVMSysOperator
{
  //------------------------------------------------------------------------------
  // Create a delete operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMCheck *Create(CATCVMContainer *iContainer);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMCheck(CATCVMContainer *iContainer);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public:
  virtual ~CATCVMCheck();

  //------------------------------------------------------------------------------
  // Add a relation to swallow
  //------------------------------------------------------------------------------
  public:
  void SetSystem(CATCVMSystem *iSystem);

  //------------------------------------------------------------------------------
  // Set the output stream for dumping the system structure
  //------------------------------------------------------------------------------
  public:
  void SetOutputStream(CATCGMOutput *iStream);

  //------------------------------------------------------------------------------
  // Run
  //------------------------------------------------------------------------------
  public:
  void Run();

  //------------------------------------------------------------------------------
  // Get Number of Errors
  //------------------------------------------------------------------------------
  public:
  int GetNbErrors();
  void SetWholeContainerCheck(CATBoolean iWholeContainerCheck);

  //------------------------------------------------------------------------------
  // Swallow relation
  //------------------------------------------------------------------------------
  private:
  void Check(CATCVMSystem *iSystem);
  void CheckContainer();
  void CheckContainerInternal(CATCVMContainer * iContainer);
  void CheckSystem(CATCVMSystem *iSystem);
  void CheckComponent(CATCVMComponent *iComponent);
  void CheckInstance(CATCVMInstance *iInstance);
  void CheckReference(CATCVMReference *iReference);
//  void CheckOccurrence(CATCVMOccurrence *iOccurrence);
  void CheckChain(CATCVMSystem *iOwnerOfTheChain, CATCVMObjectType iTypeOfTheOwner,
                  CATCVMSystem *iFirstSystemInchain, CATCVMObjectType iTypeOfTheFirstSystemInChain,
                  CATBoolean IsFirstSystemInChainCanBeNull);
  void CheckOneElementInChain(CATCVMSystem *iSystem, CATCVMObjectType iTypeOfTheSystem);
  void AddError(char * message, CATCVMObject * iCheckedElement, CATCVMObject * iInfoElement=NULL);

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  protected:
  
  CATCVMSystem *_CVMSystem;
  int           _NbErrors;
  CATCGMOutput *_OutputStream;
  CATBoolean _WholeContainerCheck;
};
#endif
