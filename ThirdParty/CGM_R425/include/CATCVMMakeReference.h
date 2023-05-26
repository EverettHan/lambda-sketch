/* -*-C++-*- */

#ifndef CATCVMMakeReference_H
#define CATCVMMakeReference_H

// COPYRIGHT DASSAULT SYSTEMES 2007

//===================================================================
//===================================================================
//
// CATCVMMakeReference
//
// class for CATCVMMakeReference operator
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Nov. 2007    Creation                         Alex State
//===================================================================

#include "CATCVMSysOperators.h"
#include "CATCVMSysOperator.h"
#include "ListPOfCATCVMSystem.h"
//#include "ListPOfCATCVMOccurrence.h"
#include "ListPOfCATCVMInstance.h"

class CATCVMReference;
class CATCVMSystem;
class CATCVMComponent;
class CATCVMContainer;
class CATCVMInstancePath;

class ExportedByCATCVMSysOperators CATCVMMakeReference : public CATCVMSysOperator
{
  //------------------------------------------------------------------------------
  // Create a MakeReference operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMMakeReference *Create(CATCVMInstancePath *iInstancePath);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMMakeReference(CATCVMInstancePath *iInstancePath);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public:
  virtual ~CATCVMMakeReference();

  //------------------------------------------------------------------------------
  // Add a system to include in the reference
  //------------------------------------------------------------------------------
  public:
  HRESULT AddSystem(CATCVMSystem *iSystem);

  //------------------------------------------------------------------------------
  // Run
  //------------------------------------------------------------------------------
  public:
  void Run();

  //------------------------------------------------------------------------------
  // Get resulting reference
  //------------------------------------------------------------------------------
  public:
  CATCVMReference *GetResultingReference();

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private:
  ListPOfCATCVMSystem      _SystemList;
  ListPOfCATCVMInstance    _InstanceList;
  CATCVMReference         *_ResultingReference;
  CATCVMReference         *_HighReference;
};
#endif
