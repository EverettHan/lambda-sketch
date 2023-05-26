/* -*-C++-*- */

#ifndef CATCVMGeoExtrude_H
#define CATCVMGeoExtrude_H

// COPYRIGHT DASSAULT SYSTEMES 2007

//===================================================================
//===================================================================
//
// CATCVMGeoExtrude
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// March 2007    Creation                         ASE
//===================================================================
#define EB_2009_04_03_Extrude

#include "CATCVMGeoOperators.h"
#include "CATCVMGeoOperator.h"
#include "CATBoolean.h"
#include "ListPOfCATCVMGeometry.h"

class CATCVMGeoContainer;
class CATCVMGeometry;
class CATMathVector;
class CATMathAxis;
class CATMathAngle;
class CATCVMInstancePath;

class ExportedByCATCVMGeoOperators CATCVMGeoExtrude : public CATCVMGeoOperator
{
  CATCGMVirtualDeclareClass(CATCVMGeoExtrude);
  //------------------------------------------------------------------------------
  // Create a Extrude operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoExtrude* Create(CATCVMGeoContainer *iCVMGeoContainer,
                                  CATTopData         *iTopData);
  static CATCVMGeoExtrude* Create(CATCVMInstancePath *iCVMInstancePath,
                                  CATTopData         *iTopData);

  //------------------------------------------------------------------------------
	// Constructor
	//------------------------------------------------------------------------------
  protected:
  CATCVMGeoExtrude(CATCVMGeoContainer    *iCVMGeoContainer,
                   CATTopData            *iTopData,
                   CATCVMGeoOperatorExt  *iExtensible);
  CATCVMGeoExtrude(CATTopData            *iTopData,
                   CATCVMGeoOperatorExt  *iExtensible);

	//------------------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------------------
  public:
	virtual ~CATCVMGeoExtrude();

  //------------------------------------------------------------------------------
  // Add a cell to Extrude
  //------------------------------------------------------------------------------
  public:
  virtual void AddCellToExtrude(CATCVMGeometry *iCell);

  //------------------------------------------------------------------------------
  // Set Extrude vector
  //------------------------------------------------------------------------------
  public:
  virtual void SetExtrudeVector(CATMathVector &iExtrudeVector);

  //------------------------------------------------------------------------------
  // Set revol axis
  //------------------------------------------------------------------------------
  public:
  virtual void SetRevolAxis(CATMathAxis &iRevolAxis);

  //------------------------------------------------------------------------------
  // Set revol angle
  //------------------------------------------------------------------------------
  public:
  virtual void SetRevolAngle(CATAngle &iRevolAngle);

  //------------------------------------------------------------------------------
  // Set check input only mode (FALSE per default)
  //------------------------------------------------------------------------------
  public:
  virtual void SetCheckInputOnlyMode(CATBoolean iCheckInputOnlyMode);

  //------------------------------------------------------------------------------
  // Set last run mode (FALSE per default)
  //------------------------------------------------------------------------------
  public:
  virtual void SetLastRunMode(CATBoolean iLastRunMode,
                              CATBoolean iCommitResult = TRUE);

  //------------------------------------------------------------------------------
  // Get top cells
  //------------------------------------------------------------------------------
  public:
  virtual void GetTopCells(ListPOfCATCVMGeometry &oTopCellList);

  //------------------------------------------------------------------------------
  // Is the input data valid
  //------------------------------------------------------------------------------
  public:
  virtual CATBoolean IsValidInput();

  //------------------------------------------------------------------------------
  // Set the Prisme mode (simple/complet)
  //------------------------------------------------------------------------------
  // KY1 (09.02.2009) : 
  // 0 => (simple mode)   only vertical prisme and it's allowed only on circle or plane face with canonical edges
  // 1 => (complete mode) Allows vertical and non vertical prisme on circle, ellipse an also on plane face with curved edges 
  // By default prisme mode = 1
  // Le prisme mode n'affecte pas le revolve 
  virtual void SetPrismeMode(CATBoolean mode);

  //------------------------------------------------------------------------------
  // Set the tolerance angle for the validity of prisme direction
  //------------------------------------------------------------------------------
  // KY1 (17.02.2009) : input (Angle) angle de tolerance en degre et non en radian

  virtual void SetAngleTolForPrismeDirection(double Angle);

  //------------------------------------------------------------------------------
	// CGM Internal Use
	//------------------------------------------------------------------------------
#ifndef EB_2009_04_03_Extrude   
  protected:
  void CustomizeCheckup(CATCVMGeoCheckup *iCheckup);
#endif     
  public:
  static const CATString *GetDefaultOperatorId();
};
#endif
