/* -*-C++-*- */

#ifndef CATCVMCopy_H
#define CATCVMCopy_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMCopy
//
// class for Collaborative Variational Modelling (CVM) copy operator
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Apr. 2006    Creation                         Alex State
//===================================================================

#include "CATCVMSysOperators.h"
#include "CATCVMSysOperator.h"
#include "ListPOfCATCVMObject.h"
#include "CATMathTransformation.h"
#include "CATBoolean.h"
#include "CATCGMNewArray.h"
#include "ListPOfCATCVMInstancePath.h"
#include "ListPOfCATCVMInstance.h"

class CATCVMSystem;
class CATCVMContainer;
class CATCVMComponent;
class CATCVMReference;
class CATCVMInstancePath;
class CATCVMPSContainer;

class ExportedByCATCVMSysOperators CATCVMCopy : public CATCVMSysOperator
{
  //------------------------------------------------------------------------------
  // Create a copy operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMCopy *Create(CATCVMContainer *iCurrentContainer,
                            CATCVMSystem    *iSystem);
  static CATCVMCopy *Create(CATCVMInstancePath *iOriginInstancePath,
                            CATCVMSystem       *iSystem);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  private:
  CATCVMCopy(CATCVMContainer *iCurrentContainer = NULL,
             CATCVMSystem    *iSystem           = NULL);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public:
  virtual ~CATCVMCopy();
  
  //------------------------------------------------------------------------------
  // Pool allocation
  //------------------------------------------------------------------------------
  CATCGMNewClassArrayDeclare;

  //------------------------------------------------------------------------------
  // Set the target container (optional)
  //------------------------------------------------------------------------------
  public:
  void SetTargetContainer(CATCVMContainer *iCVMContainer);

  //------------------------------------------------------------------------------
  // Set the target instance path (optional)
  //------------------------------------------------------------------------------
  public:
  void SetTargetInstancePath(CATCVMInstancePath *iTargetInstancePath);

  //------------------------------------------------------------------------------
  // Get the target container
  //------------------------------------------------------------------------------
  public:
  CATCVMContainer *GetTargetContainer();

  //------------------------------------------------------------------------------
  // Get the target container
  //------------------------------------------------------------------------------
  public:
  CATCVMPSContainer *GetTargetPSContainer();

  //------------------------------------------------------------------------------
  // Set system to copy
  //------------------------------------------------------------------------------
  public:
  void SetSystemToCopy(CATCVMSystem *iSystem);

  //------------------------------------------------------------------------------
  // Set a list of instance paths to copy
  //------------------------------------------------------------------------------
  public:
  HRESULT SetInstancePathList(ListPOfCATCVMInstancePath &iInstancePathList);

  //------------------------------------------------------------------------------
  // Get the list of resulting instances
  //------------------------------------------------------------------------------
  public:
  HRESULT GetResultingInstanceList(ListPOfCATCVMInstance &oResultingInstanceList);

  //------------------------------------------------------------------------------
  // Set ReuseComponent
  //------------------------------------------------------------------------------
  private:
  HRESULT SetReuseComponent(CATCVMComponent *iReuseComponent);

  //------------------------------------------------------------------------------
  // Get ReuseComponent
  //------------------------------------------------------------------------------
  public:
  CATCVMComponent *GetReuseComponent();

  //------------------------------------------------------------------------------
  // Set target reference
  //------------------------------------------------------------------------------
  private:
  HRESULT SetTargetReference(CATCVMReference *iRootReference);

  //------------------------------------------------------------------------------
  // Get target reference
  //------------------------------------------------------------------------------
  public:
  CATCVMReference *GetTargetReference();

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
  // Set copy
  //------------------------------------------------------------------------------
  public:
  void SetCopy(CATCVMObject *iOriginal,
               CATCVMObject *iCopy,
               CATBoolean    iCopyIsNewlyCreated = TRUE);

  //------------------------------------------------------------------------------
  // Get copy
  //------------------------------------------------------------------------------
  public:
  CATCVMObject *GetCopy(CATCVMObject *iOriginal);
  
  //------------------------------------------------------------------------------
  // SetTextureTransformation
  //------------------------------------------------------------------------------
  public:
  void  SetTextureTransformation(CATMathTransformation &iTextureTransformation);
  
  //------------------------------------------------------------------------------
  // GetTextureTransformation FALSE if none
  //------------------------------------------------------------------------------
  public:
  CATBoolean GetTextureTransformation (CATMathTransformation &oTextureTransformation);

  //------------------------------------------------------------------------------
  // Copy instances
  //------------------------------------------------------------------------------
  private:
  HRESULT CopyInstances(CATCVMInstancePath *iTargetInstancePath);

  //------------------------------------------------------------------------------
  // Set internal CVM log
  //------------------------------------------------------------------------------
  private:
  HRESULT SetInternalCVMLog(CATCVMLog *iInternalCVMLog);

  //------------------------------------------------------------------------------
  // Get internal CVM log
  //------------------------------------------------------------------------------
  private:
  CATCVMLog *GetInternalCVMLog();

  //------------------------------------------------------------------------------
  // Initialize internal CVM log
  //------------------------------------------------------------------------------
  private:
  CATCVMLog *InitializeInternalCVMLog();

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  protected:
  CATCVMSystem        *_CVMSystem;
  CATCVMSystem        *_ResultingCVMSystem;
  CATCVMContainer     *_CurrentCVMContainer;
  CATCVMContainer     *_TargetCVMContainer;
  CATCVMPSContainer   *_TargetCVMPSContainer;
  CATCVMInstancePath  *_TargetInstancePath;
  CATMathTransformation _TextureTransformation;
  CATBoolean            _TextureTransformationHasBeenSet;
  ListPOfCATCVMInstancePath _InstancePathList;
  ListPOfCATCVMInstance _ResultingInstanceList;

  private:
  CATCVMReference *_TargetReference;
  CATCVMLog       *_InternalCVMLog;
};
#endif
