/* -*-C++-*- */

#ifndef CATCVMGeoMakeReference_H
#define CATCVMGeoMakeReference_H

// COPYRIGHT DASSAULT SYSTEMES 2007

//===================================================================
//===================================================================
//
// CATCVMGeoMakeReference
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

class CATCVMPSContainer;
class CATCVMGeoRep;
class CATCVMReference;
class CATCVMInstancePath;

class ExportedByCATCVMGeoOperators CATCVMGeoMakeReference : public CATCVMGeoOperator
{
  //------------------------------------------------------------------------------
  // Create a MakeReference operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoMakeReference *Create(CATCVMInstancePath *iTargetInstancePath,
                                        CATTopData         *iTopData);

  //------------------------------------------------------------------------------
	// Constructor
	//------------------------------------------------------------------------------
  protected:
  CATCVMGeoMakeReference(CATTopData            *iTopData,
                         CATCVMGeoOperatorExt  *iExtensible);

	//------------------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------------------
  public:
	virtual ~CATCVMGeoMakeReference();

  //------------------------------------------------------------------------------
  // Add a geometric rep to include in the reference (as subsystem)
  //------------------------------------------------------------------------------
  public:
  virtual HRESULT AddGeoRep(CATCVMGeoRep *iGeoRep);

  //------------------------------------------------------------------------------
  // Add an InstancePath to include in the reference (as subsystem)
  //------------------------------------------------------------------------------
  public:
  virtual HRESULT AddInstance(CATCVMInstancePath *iInstancePath);

  //------------------------------------------------------------------------------
  // Get resulting reference
  //------------------------------------------------------------------------------
  public:
  CATCVMReference *GetResultingReference();

  public:
  static const CATString *GetDefaultOperatorId();
};
#endif
