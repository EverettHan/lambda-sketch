/* -*-C++-*- */

#ifndef CATCVMCreateInstance_H
#define CATCVMCreateInstance_H

// COPYRIGHT DASSAULT SYSTEMES 2007

//===================================================================
//===================================================================
//
// CATCVMCreateIstance
//
// class for CATCVMCreateInstance operator
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
#include "CATMathTransformation.h"

class CATCVMReference;
class CATCVMInstance;
//class CATCVMOccurrence;
class CATCVMInstancePath;
class CATCVMComponent;
class CATCVMContainer;
class CATCVMInstancePath;

class ExportedByCATCVMSysOperators CATCVMCreateInstance : public CATCVMSysOperator
{
  //------------------------------------------------------------------------------
  // Create a CATCVMCreateIstance operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMCreateInstance *Create();

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMCreateInstance();

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public:
  virtual ~CATCVMCreateInstance();

  //------------------------------------------------------------------------------
  // Set the instance path of the reference to instanciate
  //------------------------------------------------------------------------------
  public:
  HRESULT SetReferenceToInstanciate(CATCVMInstancePath *iInstancePath);

  //------------------------------------------------------------------------------
  // Get the instance path of the reference to instanciate (for cgmreplay)
  //------------------------------------------------------------------------------
  HRESULT GetReferenceToInstanciate(CATCVMInstancePath *& oInstancePath);


  //------------------------------------------------------------------------------
  // SetTransformation
  //------------------------------------------------------------------------------
  public:
  HRESULT SetTransformation(CATMathTransformation &iTransformation);
 //------------------------------------------------------------------------------
  // GetTransformation (for cgmreplay)
  //------------------------------------------------------------------------------
  HRESULT GetTransformation(CATMathTransformation &iTransformation);

  //------------------------------------------------------------------------------
  // Run
  //------------------------------------------------------------------------------
  public:
  void Run();

  //------------------------------------------------------------------------------
  // Get resulting reference
  //------------------------------------------------------------------------------
  public:
  CATCVMInstance *GetResultingInstance();

  //------------------------------------------------------------------------------
  // Set the reference to instantiate
  //------------------------------------------------------------------------------
  public:
  HRESULT SetReferenceToInstanciate(CATCVMReference *iReference);

  //------------------------------------------------------------------------------
  // Get/Set the host reference that will receive the instance
  //------------------------------------------------------------------------------
  public:
  HRESULT SetTargetReference(CATCVMReference *iTargetReference);
  private:
  CATCVMReference * GetTargetReference();

  //private:
  HRESULT SortInput();

  //------------------------------------------------------------------------------
  // Sort the input data
  //------------------------------------------------------------------------------
  //private:
  HRESULT SetInstanceTransformation(CATMathTransformation &iInstanceTransformation);

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private:
  CATCVMReference       *_Reference;
  CATCVMReference       *_TargetReference;
  CATMathTransformation  _Transformation;
  CATMathTransformation  _InstanceTransformation;
  CATCVMInstance        *_ResultingInstance;

  CATCVMInstancePath    *_InstanceTargetPath;
};
#endif
