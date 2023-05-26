/* -*-C++-*- */

#ifndef CATCVMGeoCreateInstance_H
#define CATCVMGeoCreateInstance_H

// COPYRIGHT DASSAULT SYSTEMES 2007

//===================================================================
//===================================================================
//
// CATCVMGeoCreateInstance
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// December 2007    Creation                         ASE
//===================================================================

#include "CATCVMGeoOperators.h"
#include "CATCVMGeoOperator.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATCVMGeoContainer;
class CATCVMReference;
class CATCVMComponent;
class CATCVMInstance;
class CATCVMInstancePath;
class CATMathTransformation;

class ExportedByCATCVMGeoOperators CATCVMGeoCreateInstance : public CATCVMGeoOperator
{
  //------------------------------------------------------------------------------
  // Create a CreateInstance operator
  //------------------------------------------------------------------------------
  public:
  //static CATCVMGeoCreateInstance *Create(CATTopData * iTopData);
    static CATCVMGeoCreateInstance *Create(CATCVMInstancePath *iCVMInstancePath,
                                           CATTopData         *iTopData);

  //------------------------------------------------------------------------------
	// Constructor
	//------------------------------------------------------------------------------
  protected:
  CATCVMGeoCreateInstance(CATTopData            *iTopData,
                          CATCVMGeoOperatorExt  *iExtensible);

	//------------------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------------------
  public:
	virtual ~CATCVMGeoCreateInstance();

  //------------------------------------------------------------------------------
  // Set the instance path of the reference to instanciate
  //------------------------------------------------------------------------------
  public:
  HRESULT SetReferenceToInstanciate(CATCVMInstancePath *iInstancePath);

  //------------------------------------------------------------------------------
  // Set the instance path of the reference where new instance will be included
  //------------------------------------------------------------------------------
  public:
  HRESULT SetWorkInstancePath(CATCVMInstancePath *iInstancePath);

  //------------------------------------------------------------------------------
  // Set the reference to instantiate
  //------------------------------------------------------------------------------
  public:
  HRESULT SetReferenceToInstanciate(CATCVMReference *iReference);

  //------------------------------------------------------------------------------
  // Set the host reference that will receive the instance
  //------------------------------------------------------------------------------
  public:
  HRESULT SetTargetReference(CATCVMReference *iTargetReference);

  //------------------------------------------------------------------------------
  // Set the unfolded component
  //------------------------------------------------------------------------------
  //public:
  //HRESULT SetUnfoldedComponent(CATCVMComponent *iUnfoldedComponent);

  //------------------------------------------------------------------------------
  // SetTransformation
  //------------------------------------------------------------------------------
  public:
  HRESULT SetTransformation(CATMathTransformation &iTransformation);

  //------------------------------------------------------------------------------
  // Get resulting reference
  //------------------------------------------------------------------------------
  public:
  CATCVMInstance *GetResultingInstance();

  public:
  static const CATString *GetDefaultOperatorId();
};
#endif
