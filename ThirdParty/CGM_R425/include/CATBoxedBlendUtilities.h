/* -*-C++-*- */
#ifndef CATBoxedBlendUtilities_H
#define CATBoxedBlendUtilities_H
// COPYRIGHT DASSAULT SYSTEMES 2005

//===================================================================
// Usage notes:
// - Utilities based on Boxed for Blend
//
//===================================================================

//===================================================================
// Jul. 05    Creation                         R. Rorato
//===================================================================

#include "CATMathDef.h"
#include "RibbonLight.h"
class CATTopRibSupport;
class CATSoftwareConfiguration;
class CATTopRibTool;
class CATMathBox;
class CATGeometry;
class CATMathPoint;

class ExportedByRibbonLight CATBoxedBlendUtilities
{
public:

	static CATBoolean DoBoxesIntersect( 
		CATSoftwareConfiguration* iConfig,
		const int                 iNbSupports,
		CATTopRibSupport*         iSupportArray[],
		const CATPositiveLength   iClearance);

	static CATMathBox * ComputeWorkingBox( 
		CATTopRibTool*            iTool,
		const CATPositiveLength   iClearance);

	static CATBoolean IsIntersectionPossible( 
		CATSoftwareConfiguration* iConfig,
		const CATGeometry*        iGeometry1, 
		const CATGeometry*        iGeometry2, 
		double                    iOffset,
		double                    iTolerance,
		CATBoolean                iOnlyUseCacheableData = TRUE);

	static CATBoolean IsContainmentPossible( 
		CATSoftwareConfiguration* iConfig,
		const CATGeometry*        iGeometry, 
		const CATMathPoint&       iPoint, 
		double                    iTolerance);


};
#endif
