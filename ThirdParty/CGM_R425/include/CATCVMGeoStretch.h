/* -*-C++-*- */
/*
#ifndef CATCVMGeoStretch_H
#define CATCVMGeoStretch_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMGeoStretch
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
class CATCVMGeometry;
class CATMathVector;

class ExportedByCATCVMGeoOperators CATCVMGeoStretch : public CATCVMGeoOperator
{
  //------------------------------------------------------------------------------
  // Create a stretch operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoStretch* Create(CATCVMGeoContainer *iCVMGeoContainer,
                                  CATTopData         *iTopData);

  //------------------------------------------------------------------------------
	// Constructor
	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------------------
  public:
	virtual ~CATCVMGeoStretch();
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);

  //------------------------------------------------------------------------------
  // Add a cell to Stretch
  //------------------------------------------------------------------------------
  public:
  virtual void AddCellToStretch(CATCVMGeometry *iCell);

  //------------------------------------------------------------------------------
  // Set Stretch vector
  //------------------------------------------------------------------------------
  public:
  virtual void SetStretchVector(CATMathVector &iStretchVector);

  //------------------------------------------------------------------------------
  // Keep initial cell
  //------------------------------------------------------------------------------
  public:
  virtual void SetKeepInitialCell(CATBoolean iKeepInitialCell,
                                  CATBoolean iFillClosedBoundary = FALSE);

  //------------------------------------------------------------------------------
  // Get number of top cells
  //------------------------------------------------------------------------------
  public:
  virtual int GetNbTopCells();

  //------------------------------------------------------------------------------
  // Get top cell
  //------------------------------------------------------------------------------
  public:
  virtual CATCVMGeometry *GetTopCell(int iIndex);
  //------------------------------------------------------------------------------
	// CGM Internal Use
	//------------------------------------------------------------------------------
  private:
	//virtual int RunOperator();
     
  public:
  static const CATString *GetDefaultOperatorId();
};
#endif
*/
