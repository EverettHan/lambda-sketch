/* -*-C++-*- */

#ifndef CATCVMDelete_H
#define CATCVMDelete_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMDelete
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
#include "ListPOfCATCVMSystem.h"
#include "ListPOfCATCVMHandle.h"
#include "ListPOfCATCVMRelation.h"
#include "CATBoolean.h"
#include "CATListOfInt.h"
#include "ListPOfCATCVMContainer.h"

class CATCVMContainer;
class CATCVMReference;
class CATCVMInstance;
class CATCVMOccurrence;

class ExportedByCATCVMSysOperators CATCVMDelete : public CATCVMSysOperator
{
  //------------------------------------------------------------------------------
  // Create a delete operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMDelete *Create(CATCVMContainer *iContainer);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMDelete(CATCVMContainer *iContainer);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public:
  virtual ~CATCVMDelete();

  //------------------------------------------------------------------------------
  // Add a handle to delete
  //------------------------------------------------------------------------------
  public:
  void AddHandle(CATCVMHandle *iHandle);

  //------------------------------------------------------------------------------
  // Add a relation to delete
  //------------------------------------------------------------------------------
  public:
  void AddRelation(CATCVMRelation *iRelation);

  //------------------------------------------------------------------------------
  // Add a system to delete
  //------------------------------------------------------------------------------
  public:
  void AddSystem(CATCVMSystem *iSystem,
                 CATBoolean    iKeepData = TRUE);

  //------------------------------------------------------------------------------
  // Add a reference to delete
  //------------------------------------------------------------------------------
  public:
  void AddReference(CATCVMReference *iReference);

  //------------------------------------------------------------------------------
  // Add an instance to delete
  //------------------------------------------------------------------------------
  public:
  void AddInstance(CATCVMInstance *iInstance);

  //------------------------------------------------------------------------------
  // Add an occurrence to delete
  //------------------------------------------------------------------------------
/*  public:
  void AddOccurrence(CATCVMOccurrence *iOccurrence,
                     CATBoolean    iKeepData = TRUE);
*/
  //------------------------------------------------------------------------------
  // Run
  //------------------------------------------------------------------------------
  public:
  void Run();

  //------------------------------------------------------------------------------
  // Delete handle
  //------------------------------------------------------------------------------
  private:
  void DeleteHandle(CATCVMHandle *iHandle);

  //------------------------------------------------------------------------------
  // Delete relation
  //------------------------------------------------------------------------------
  private:
  void DeleteRelation(CATCVMRelation *iRelation);

  //------------------------------------------------------------------------------
  // Delete system
  //------------------------------------------------------------------------------
  private:
  void DeleteSystem(CATCVMSystem *iSystem,
                    CATBoolean    iKeepData);

  //------------------------------------------------------------------------------
  // Delete component
  //------------------------------------------------------------------------------
  private:
  void DeleteComponent(CATCVMComponent *iComponent,
                       CATCVMComponent *iHighComponent,
                       CATBoolean       iKeepData);

  //------------------------------------------------------------------------------
  // Delete reference
  //------------------------------------------------------------------------------
  private:
  void DeleteReference(CATCVMSystem *iSystem,
                       CATBoolean   iKeepData);

  //------------------------------------------------------------------------------
  // Delete instance
  //------------------------------------------------------------------------------
  private:
  void DeleteInstance(CATCVMSystem *iSystem);

  //------------------------------------------------------------------------------
  // Add a system to the internal list of systems
  //------------------------------------------------------------------------------
  private:
  void AddToSystemList(CATCVMSystem *iSystem,
                       CATBoolean    iKeepData);

  //------------------------------------------------------------------------------
  // Add a data container
  //------------------------------------------------------------------------------
  private:
  void AddDataContainer(CATCVMContainer *iDataContainer);

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  protected:
  ListPOfCATCVMHandle    _HandleList;
  ListPOfCATCVMRelation  _RelationList;
  ListPOfCATCVMSystem    _SystemList; // delete third : to be cleaned AFTER reuse links deletion
  CATListOfInt           _SystemKeepDataList;
  ListPOfCATCVMSystem    _ReferenceList; // delete first
  CATListOfInt           _ReferenceKeepDataList;
  ListPOfCATCVMSystem    _InstanceList; // delete second
  CATListOfInt           _InstanceKeepDataList;
  ListPOfCATCVMContainer _DataContainerList;
};
#endif
