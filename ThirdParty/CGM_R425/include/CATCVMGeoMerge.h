/* -*-C++-*- */

#ifndef CATCVMGeoMerge_H
#define CATCVMGeoMerge_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMGeoMerge
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
#include "ListPOfCATCVMGeometry.h"

class CATCVMGeoContainer;
class CATCVMBody;
class CATCVMGeometry;
class CATCVMInstancePath;

class ExportedByCATCVMGeoOperators CATCVMGeoMerge : public CATCVMGeoOperator
{
  //------------------------------------------------------------------------------
  // Merge type
  //------------------------------------------------------------------------------
  public:
  enum Type
  {
    None,
    Union,
    Substract,
    Intersect
  };

  //------------------------------------------------------------------------------
  // Create a merge operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoMerge* Create(CATCVMGeoContainer *iCVMGeoContainer,
                                CATTopData         *iTopData);
  static CATCVMGeoMerge* Create(CATCVMInstancePath *iCVMInstancePath,
                                CATTopData         *iTopData);

  //------------------------------------------------------------------------------
	// Constructor
	//------------------------------------------------------------------------------
  protected:
  CATCVMGeoMerge(CATCVMGeoContainer   *iCVMGeoContainer,
                 CATTopData           *iTopData,
                 CATCVMGeoOperatorExt *iExtensible);
  CATCVMGeoMerge(CATTopData           *iTopData,
                 CATCVMGeoOperatorExt *iExtensible);

	//------------------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------------------
  public:
	virtual ~CATCVMGeoMerge();

	//------------------------------------------------------------------------------
	// Set bodies to intersect (incompatible with the other set method)
	//------------------------------------------------------------------------------
  public:
	virtual void Set(CATCVMBody *iBody1,
		               CATCVMBody *iBody2);

	//------------------------------------------------------------------------------
	// Set cells to intersect with remainder of body (incompatible with the other
  // set method)
	//------------------------------------------------------------------------------
  public:
  virtual void Set(CATCVMBody            *iBody1,
                   ListPOfCATCVMGeometry &iCellsToSplit);

  //------------------------------------------------------------------------------
	// Set collision test mode
	//------------------------------------------------------------------------------
  public:
  virtual void SetCollisionTestMode(CATBoolean iCollisionTestMode);

  //------------------------------------------------------------------------------
	// Set boolean type
	//------------------------------------------------------------------------------
  public:
    virtual void SetBooleanType(CATCVMGeoMerge::Type iBooleanType);

	//------------------------------------------------------------------------------
  // Get the result of the collision test
	//------------------------------------------------------------------------------
  //public:
  //virtual CATBoolean GetCollisionTestResult();

  //------------------------------------------------------------------------------
	// CGM Internal Use
	//------------------------------------------------------------------------------
  private:
	//virtual int RunOperator();
     
  public:
  static const CATString *GetDefaultOperatorId();
 };
#endif
