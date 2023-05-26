/* -*-C++-*- */

#ifndef CATCVMGeoUpdate_H
#define CATCVMGeoUpdate_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMGeoUpdate
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// June 2006    Creation                         ASE
//===================================================================

#include "CATCVMGeoOperators.h"
#include "CATCVMGeoOperator.h"
#include "CATBoolean.h"

class CATCVMGeoContainer;
class CATCVMInstancePath;

class ExportedByCATCVMGeoOperators CATCVMGeoUpdate : public CATCVMGeoOperator
{
  //------------------------------------------------------------------------------
  // Create a subdivision operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoUpdate* Create(CATCVMGeoContainer *iCVMGeoContainer,
                                 CATTopData         *iTopData);
  static CATCVMGeoUpdate* Create(CATCVMInstancePath *iCVMInstancePath,
                                 CATTopData         *iTopData);

  //------------------------------------------------------------------------------
	// Constructor
	//------------------------------------------------------------------------------
  protected:
  CATCVMGeoUpdate(CATCVMGeoContainer   *iCVMGeoContainer,
                  CATTopData           *iTopData,
                  CATCVMGeoOperatorExt *iExtensible);
  CATCVMGeoUpdate(CATTopData           *iTopData,
                  CATCVMGeoOperatorExt *iExtensible);

	//------------------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------------------
  public:
	virtual ~CATCVMGeoUpdate();

  //------------------------------------------------------------------------------
	// Set & Get collision test mode
	//------------------------------------------------------------------------------
  public:
  virtual void SetCollisionTestMode(CATBoolean iCollisionTestMode);

	//------------------------------------------------------------------------------
  // Get the result of the collision test
	//------------------------------------------------------------------------------
  public:
  virtual CATBoolean GetCollisionTestResult();

  //------------------------------------------------------------------------------
	// CGM Internal Use
	//------------------------------------------------------------------------------
  private:
	//virtual int RunOperator();

  public:
  static const CATString *GetDefaultOperatorId();
};
#endif
