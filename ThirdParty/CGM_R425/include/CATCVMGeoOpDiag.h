/* -*-C++-*- */

#ifndef CATCVMGeoOpDiag_H
#define CATCVMGeoOpDiag_H

// COPYRIGHT DASSAULT SYSTEMES 2007

//===================================================================
//===================================================================
//
// CATCVMGeoOpDiag
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// November 2007    Creation                         Alex State
//===================================================================

#include "CATCVMGeoObjects.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATCGMNewArray.h"

class ExportedByCATCVMGeoObjects CATCVMGeoOpDiag : public CATBaseUnknown
{
  //------------------------------------------------------------------------------
  // Component declaration for ObjectModeler
  //------------------------------------------------------------------------------
  public:
  CATDeclareClass;

  //------------------------------------------------------------------------------
	// Constructor
	//------------------------------------------------------------------------------
  public:
  CATCVMGeoOpDiag();
  
  CATCGMNewClassArrayDeclare;

	//------------------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------------------
  public:
	virtual ~CATCVMGeoOpDiag();

  //------------------------------------------------------------------------------
  // Check whether the generated geometry would have been out of scale
  //------------------------------------------------------------------------------
  public:
  CATBoolean GetOutOfScaleDiag();

  //------------------------------------------------------------------------------
  // Indicate whether the generated geometry would have been out of scale
  //------------------------------------------------------------------------------
  public:
  void SetOutOfScaleDiag(CATBoolean iOutOfScaleDiag);

  //------------------------------------------------------------------------------
  // Check whether the generated geometry would have contained one (or several)
  // collisions
  //------------------------------------------------------------------------------
  public:
  CATBoolean GetCollisionDetectionDiag();

  //------------------------------------------------------------------------------
  // Indicate whether the generated geometry would have contained one (or several)
  // collisions
  //------------------------------------------------------------------------------
  public:
  void SetCollisionDetectionDiag(CATBoolean iCollisionDetectionDiag);


  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private:
  CATBoolean _OutOfScaleDiag;
  CATBoolean _CollisionDetectionDiag;
};
#endif
