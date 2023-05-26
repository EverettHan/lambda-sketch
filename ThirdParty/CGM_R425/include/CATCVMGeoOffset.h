/* -*-C++-*- */

#ifndef CATCVMGeoOffset_H
#define CATCVMGeoOffset_H

// COPYRIGHT DASSAULT SYSTEMES 2008

//===================================================================
//===================================================================
//
// CATCVMGeoOffset
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// August 2008    Creation                         ASE
//===================================================================
#define EB_2009_04_03_offset

#include "CATCVMGeoOperators.h"
#include "CATCVMGeoOperator.h"
#include "CATBoolean.h"
#include "ListPOfCATCVMGeometry.h"

class CATCVMGeoContainer;
class CATCVMGeometry;
class CATCVMInstancePath;

class ExportedByCATCVMGeoOperators CATCVMGeoOffset : public CATCVMGeoOperator
{
  //------------------------------------------------------------------------------
  // Create a Extrude operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoOffset* Create(CATCVMGeoContainer *iCVMGeoContainer,
                                 CATTopData         *iTopData);
  static CATCVMGeoOffset *Create(CATCVMInstancePath *iCVMInstancePath,
                                 CATTopData         *iTopData);

  //------------------------------------------------------------------------------
	// Constructor
	//------------------------------------------------------------------------------
  protected:
  CATCVMGeoOffset(CATTopData            *iTopData,
                  CATCVMGeoOperatorExt  *iExtensible);

	//------------------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------------------
  public:
	virtual ~CATCVMGeoOffset();

  //------------------------------------------------------------------------------
  // Add a cell for boundary offset
  //------------------------------------------------------------------------------
  public:
  virtual void AddCellForBoundaryOffset(CATCVMGeometry *iCell);

  //------------------------------------------------------------------------------
  // Set offset value
  //------------------------------------------------------------------------------
  public:
  virtual void SetOffsetValue(double &iOffsetValue);

  //------------------------------------------------------------------------------
  // Set last run mode (FALSE per default)
  //------------------------------------------------------------------------------
  public:
  virtual void SetLastRunMode(CATBoolean iLastRunMode,
                              CATBoolean iCommitResult = TRUE);

  //------------------------------------------------------------------------------
  // Get offset cells
  //------------------------------------------------------------------------------
  public:
  virtual void GetOffsetCells(ListPOfCATCVMGeometry &oOffsetCellList);

  //------------------------------------------------------------------------------
	// CGM Internal Use
	//------------------------------------------------------------------------------
#ifndef EB_2009_04_03_offset      
  protected:
  void CustomizeCheckup(CATCVMGeoCheckup *iCheckup);
#endif
     
  public:
  static const CATString *GetDefaultOperatorId();
};
#endif
