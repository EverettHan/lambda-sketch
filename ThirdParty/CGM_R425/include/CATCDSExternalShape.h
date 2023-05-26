//===================================================================
//===================================================================
// CATCDSExternalShape.cpp
// Header definition of class CATCDSExternalShape
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2014/10/08 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATCDSExternalShape_H
#define CATCDSExternalShape_H

#include "CATCDSExternalObject.h"
#include "CATCDSBoolean.h"
#include "CATCDSArray.h"
#include "CATCDS3Point.h"
#include "CATCDSCPlusPlusVersions.h"

class CATCDSMesh;

/**
  @brief interface that developper must implement to declare a collidable object.
  
*/
class ExportedByCATCDSUtilities CATCDSExternalShape : public CATCDSExternalObject
{
public:
	/**
		@brief Return the precision of the tesselation of this shape.

		SAG http://en.wikipedia.org/wiki/Tessellation_%28computer_graphics%29
		This precision is used to select valid and invalid point of collision.
		
		@remark For dassault tesselate shape this represent the sag
	*/
	virtual double GetShapePrecision();

  virtual void GetBoundingSphere(double& oRadius, double& oCx, double& oCy, double& oCz);

	virtual void ApplyNoTransfo(CATCDSBoolean iBool);

	virtual CATCDSBoolean TransfoApplied();

  virtual bool IsRotationInvariant(CATCDS3Point const &iAxisOrigin, CATCDS3Vector const &iAxisDirection, double iTolerance) const;

#if defined(CPP11_AVAILABLE)
  virtual CATCDSArray<CATCDSMesh> ExportAsMeshes(bool iMasterRep) const = 0;
#endif

protected:
  virtual ~CATCDSExternalShape();


};

#endif