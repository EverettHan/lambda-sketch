/* -*-C++-*- */

#ifndef CATCVMGeoCopy_H
#define CATCVMGeoCopy_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMGeoCopy
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Sep. 2006    Creation                         Alex State
//===================================================================

#include "CATCVMGeoOperators.h"
#include "CATCVMGeoOperator.h"
#include "ListPOfCATCVMObject.h"
#include "ListPOfCATCVMSystem.h"
#include "ListPOfCATCVMInstancePath.h"
#include "ListPOfCATCVMReference.h"
#include "ListPOfCATCVMInstance.h"

class CATCVMGeoOperatorExt;
class CATCVMObject;
class CATCVMBody;
class CATCVMComponent;
class CATCVMSystem;
class CATTopData;
class CATMathTransformation;
class CATString;
class CATCVMInstancePath;

class ExportedByCATCVMGeoOperators CATCVMGeoCopy : public CATCVMGeoOperator
{
  //------------------------------------------------------------------------------
  // Create a Copy operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoCopy *Create(CATCVMGeoContainer *iCVMGeoContainer,
                               CATTopData         *iTopData);
  static CATCVMGeoCopy *Create(CATCVMInstancePath *iCVMInstancePath,
                               CATTopData         *iTopData);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMGeoCopy(CATCVMGeoContainer   *iCVMGeoContainer,
                CATTopData           *iTopData,
                CATCVMGeoOperatorExt *iExtensible);
  CATCVMGeoCopy(CATTopData           *iTopData,
                CATCVMGeoOperatorExt *iExtensible);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public:
  virtual ~CATCVMGeoCopy();

  //------------------------------------------------------------------------------
  // Pool allocation
  //------------------------------------------------------------------------------   
  CATCGMNewClassArrayDeclare;        

  //------------------------------------------------------------------------------
  // DEPRECATED -- Use SetObjectList
  //------------------------------------------------------------------------------
  public:
  virtual void AddSystemToCopy(CATCVMSystem *iSystem);

  public:
  virtual void SetObjectList(ListPOfCATCVMObject & iObjectList);

  //------------------------------------------------------------------------------
  // Set the target container or instance path (optional)
  //------------------------------------------------------------------------------
  public:
  virtual void SetTargetContainer(CATCVMGeoContainer *iCVMGeoContainer);
  virtual void SetTargetInstancePath(CATCVMInstancePath *iCVMInstancePath);

  //------------------------------------------------------------------------------
  // Set the host component (optional)
  //------------------------------------------------------------------------------
  public:
  virtual void SetHostComponent(CATCVMComponent *iComponent);

  //------------------------------------------------------------------------------
  // Set the Transformation (optional)
  //------------------------------------------------------------------------------
  public:
  void SetTransformation (CATMathTransformation &iTransformation);

  //------------------------------------------------------------------------------
  // Set a list of image Objects to be used when a given Object is found
  //------------------------------------------------------------------------------
  public:
  HRESULT SetImageList(ListPOfCATCVMObject &iObjectList,
                       ListPOfCATCVMObject &iImageList);
  //------------------------------------------------------------------------------
  // Get the list of resulting instances
  //------------------------------------------------------------------------------
  public:
  HRESULT GetResultingInstancePathList(ListPOfCATCVMInstancePath &oResultingInstancePathList);

/*
  //------------------------------------------------------------------------------
  // Set the incrementation value for the extension of the name for the copy
  //------------------------------------------------------------------------------
  public:
  virtual void SetNameExtensionIncrement(int iExtensionIncrementValue);
*/
  //------------------------------------------------------------------------------
	// CGM Internal Use
	//------------------------------------------------------------------------------
  private:
	////virtual int RunOperator();
     
  //------------------------------------------------------------------------------
  // Get number of resulting systems
  //------------------------------------------------------------------------------
  public:
  int GetNbResultingSystems();

  //------------------------------------------------------------------------------
  // Get resulting system
  //------------------------------------------------------------------------------
  public:
  CATCVMSystem *GetResultingSystem(int iIndex);

  //------------------------------------------------------------------------------
  // Get resulting system
  //------------------------------------------------------------------------------
  public:
  void GetResultingSystems(ListPOfCATCVMSystem &oResultingSystemList );

  //------------------------------------------------------------------------------
  // Get copy
  //------------------------------------------------------------------------------
  public:
  virtual CATCVMObject *GetCopy(CATCVMObject *iOriginal);

  public:
  static const CATString *GetDefaultOperatorId();
};
#endif
