/* -*-C++-*- */

#ifndef CATCVMGeoLoopPointProjection_H
#define CATCVMGeoLoopPointProjection_H

// COPYRIGHT DASSAULT SYSTEMES 2008

//===================================================================
//===================================================================
//
// CATCVMGeoLoopPointProjection
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// August 2008    Creation                         ASE
//===================================================================

#include "CATCVMGeoOperators.h"
#include "CATCVMGeoOperator.h"
#include "CATBoolean.h"

class CATCVMGeometry;
class CATCVMInstancePath;
class CATMathPoint;
class CATMathVector;

class ExportedByCATCVMGeoOperators CATCVMGeoLoopPointProjection : public CATCVMGeoOperator
{
  //------------------------------------------------------------------------------
  // Create a Extrude operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoLoopPointProjection* Create(CATCVMGeoContainer *iCVMGeoContainer,
                                              CATTopData         *iTopData);
  static CATCVMGeoLoopPointProjection *Create(CATCVMInstancePath *iCVMInstancePath,
                                              CATTopData         *iTopData);

  //------------------------------------------------------------------------------
	// Constructor
	//------------------------------------------------------------------------------
  protected:
  CATCVMGeoLoopPointProjection(CATCVMGeoContainer    *iCVMGeoContainer,
                               CATTopData            *iTopData,
                               CATCVMGeoOperatorExt  *iExtensible);
  CATCVMGeoLoopPointProjection(CATTopData            *iTopData,
                               CATCVMGeoOperatorExt  *iExtensible);

	//------------------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------------------
  public:
	 virtual ~CATCVMGeoLoopPointProjection();

  //------------------------------------------------------------------------------
  // Set a cell for boundary projection
  //------------------------------------------------------------------------------
  public:
   void SetCellForBoundaryProjection(CATCVMGeometry *iCell);

  //------------------------------------------------------------------------------
  // Set known boundary cell (optional)
  //------------------------------------------------------------------------------
  public:
   void SetBoundaryCell(CATCVMGeometry *iBoundaryCell);

  //------------------------------------------------------------------------------
  // Set point to project
  //------------------------------------------------------------------------------
  public:
   void SetPointToProject(CATMathPoint &iPoint);

  //------------------------------------------------------------------------------
  // Get the projected point, the boundary cell and normal-to-boundary vector
  // Please note: the vector is oriented towards the matter side
  //              of the boundary cell
  //------------------------------------------------------------------------------
  public:
   void GetResultingPoint(CATMathPoint    &oProjectedPoint,
                          CATCVMGeometry *&oBoundaryCell,
                          CATMathVector   &oNormalVector);  
  public:
   static const CATString *GetDefaultOperatorId();
};
#endif
