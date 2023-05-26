/* -*-C++-*- */

#ifndef CATCVMGeoEditInPlace_H
#define CATCVMGeoEditInPlace_H

// COPYRIGHT DASSAULT SYSTEMES 2007

//===================================================================
//===================================================================
//
// CATCVMGeoEditInPlace
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
#include "ListPOfCATCVMSystem.h"

class CATCVMGeoContainer;
class CATCVMInstancePath;

class ExportedByCATCVMGeoOperators CATCVMGeoEditInPlace : public CATCVMGeoOperator
{
  //------------------------------------------------------------------------------
  // Create a EditInPlace operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoEditInPlace *Create(CATCVMInstancePath *iCVMInstancePath,
                                      CATTopData         *iTopData);

  //------------------------------------------------------------------------------
	// Constructor
	//------------------------------------------------------------------------------
  protected:
  CATCVMGeoEditInPlace(CATTopData           *iTopData,
                       CATCVMGeoOperatorExt *iExtensible);

	//------------------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------------------
  public:
	virtual ~CATCVMGeoEditInPlace();

  //------------------------------------------------------------------------------
  // Set instance path
  //------------------------------------------------------------------------------
  public:
  HRESULT SetInstancePath(CATCVMInstancePath *iInstancePath);

  //------------------------------------------------------------------------------
  // Get duplicated systems (after 1st run)
  //------------------------------------------------------------------------------
  public:
  HRESULT GetDuplicatedSystemList(ListPOfCATCVMSystem &oDuplicatedSystemList);

  public:
  static const CATString *GetDefaultOperatorId();
};
#endif
