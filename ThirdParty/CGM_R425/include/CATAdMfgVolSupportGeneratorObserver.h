/**
*  @quickReview SOU 19:04:05 Support for SetMinimumArea() and SetMinimumBox()
*  @quickReview SOU 17:08:14 Support for SetComputeTopBottomSurfaces()
*  @quickReview SOU 17:07:28 Added method ReactToSetInputPolyBody()
*/ 

#include "CATIACGMLevel.h"
#ifdef CATIAR420

#ifndef CAT_ADMFG_VOL_SUPPORT_GENERATOR_OBSERVER_H
#define CAT_ADMFG_VOL_SUPPORT_GENERATOR_OBSERVER_H

#include "AdvTopoOpeItf.h"
#include "CATAdMfgVolSupportGenerator.h"
#include "CATIPolyMesh.h"
#include "CATMathPlane.h"
#include "CATMathBox2D.h"

/**
* Observer class to CATAdMfgVolSupportGenerator.
*/
class ExportedByAdvTopoOpeItf CATAdMfgVolSupportGeneratorObserver
{

public:

	virtual ~CATAdMfgVolSupportGeneratorObserver ();

public:

	///////////////////////
	//ReactTo methods :
	virtual void ReactToSetInputMesh (const CATIPolyMesh &iMesh) = 0;
	virtual void ReactToSetInputPolyBody(const CATPolyBody &iPolyBody) = 0;
	virtual void ReactToSetReferencePlane (const CATMathPlane& iRefPlane) = 0;  
	virtual void ReactToSetComputeTopBottomSurfaces(const CATBoolean& iComputeTopBottomSurfaces) = 0;
	virtual void ReactToSetMinimumArea(double iMinimumArea) = 0;
	virtual void ReactToSetMinimumBox(const CATMathBox2D& iBox) = 0;
	
	virtual void ReactToSetAngles(double iBottomLimitAngle, double iTopLimitAngle) = 0;
	virtual void ReactToOutput(CATLISTP(CATAdMfgVolSupportDomain) (&oOutputDomains)) = 0;

public:
	virtual void AfterConstructor () = 0;
	virtual void BeforeRun () = 0;
	virtual void AfterRun () = 0;
	virtual void BeforeDestructor () = 0;  
};

#endif

#endif
