/* -*-C++-*- */

#ifndef CATCVMSysOperator_H
#define CATCVMSysOperator_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMSysOperator
//
// generic class for Collaborative Variational Modelling (CVM) system operators
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
#include "CATCVMInstancePath.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATCGMVirtual.h"

class CATCVMPSContainer;
class CATCVMContainer;
class CATCVMLog;

class ExportedByCATCVMSysOperators CATCVMSysOperator : public CATCGMVirtual
{
  CATCGMVirtualDeclareClass(CATCVMSysOperator);
  //------------------------------------------------------------------------------
  // Constructors
  //------------------------------------------------------------------------------
  protected:
  CATCVMSysOperator(CATCVMInstancePath *iWorkInstancePath=NULL);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public:
  virtual ~CATCVMSysOperator();

  //------------------------------------------------------------------------------
  // Run
  //------------------------------------------------------------------------------
  public:
  virtual void Run() = 0;

  //------------------------------------------------------------------------------
  // Safe run
  //------------------------------------------------------------------------------
  public:
  virtual HRESULT RunSafe();

  //------------------------------------------------------------------------------
  // Get/Set PSContainer
  //------------------------------------------------------------------------------
  protected:
  HRESULT SetPSContainer(CATCVMPSContainer * iContainer); 
  public:
  CATCVMPSContainer *GetPSContainer(); // Can return NULL if no set has been done !

  //------------------------------------------------------------------------------
  // Get/Set DataContainer
  //------------------------------------------------------------------------------
  protected:
  HRESULT SetDataContainer(CATCVMContainer * iContainer);
  public:
  CATCVMContainer *GetDataContainer(); // Can return NULL if no set has been done !

  //------------------------------------------------------------------------------
  // Set the work instance path
  //------------------------------------------------------------------------------
  public:
  HRESULT SetWorkInstancePath(CATCVMInstancePath * iInstancePath);

  //------------------------------------------------------------------------------
  // Get the work instance path // Can return NULL
  //------------------------------------------------------------------------------
  protected:
  CATCVMInstancePath *GetWorkInstancePath();

  //------------------------------------------------------------------------------
  // Get the work reference (from the Work instance path)
  //------------------------------------------------------------------------------
  protected:
  CATCVMReference *GetWorkReference(CATCVMContainer **oDataContainer = NULL);

  //------------------------------------------------------------------------------
  // Set CVM log
  //------------------------------------------------------------------------------
  public:
  void SetCVMLog(CATCVMLog *iCVMLog);

  //------------------------------------------------------------------------------
  // Get CVM log
  //------------------------------------------------------------------------------
  public:
  CATCVMLog *GetCVMLog();

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  protected:
  CATCVMLog          *_CVMLog;
  private:
  CATCVMInstancePath *_WorkInstancePath;
  CATCVMPSContainer  *_PSContainer;
  CATCVMContainer    *_DataContainer;
  private:
	  /**
	   *This method is called internally after Run if the Run was successful.
	   *If the property _Dirtify is true (default), then the container is marked as dirty
	   *If the property _Dirtify is false, then nothing is done
	   *Operators that do not dirtify must set _Dirtify to false
	   */
	virtual void UpdateContainerDirtyState();
  protected:
	  CATBoolean _Dirtify;
};
#endif
