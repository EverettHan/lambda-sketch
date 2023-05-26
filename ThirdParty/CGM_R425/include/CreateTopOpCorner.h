#ifndef CreateTopOpCorner_H 
#define CreateTopOpCorner_H 

// COPYRIGHT DASSAULT SYSTEMES  1999


#include "Parallel.h"
#include "CATSkillValue.h"
#include "CATTopDef.h"
#include <stdlib.h>
//
class CATTopCorner;
class CATGeoFactory;
class CATGeometry;
class CATBody;
class CATCGMJournalList;
class CATLaw;
class CATTopData;
//

// CATCreateTopCorner -> CATTopCorner.h
/**
* @nodoc
* Deprecated. Use CATCreateTopCorner.
*/
ExportedByParallel
CATTopCorner * CreateTopOpCornerForPJB(CATGeoFactory     * iFactory,
				   CATTopData * iTopData,
				   CATBody      * iCurve1,
				   CATBody      * iCurve2,
				   CATBody       * iSupport,
				  double iRadius);
// CATCreateTopCorner -> CATTopCorner.h
/**
* @nodoc
* Deprecated. Use CATCreateTopCorner.
*/
ExportedByParallel
CATTopCorner * CreateTopOpCorner (CATGeoFactory     * iFactory,
				   CATTopData * iTopData,
				   CATBody      * iCurve1,
				   CATBody      * iCurve2,
				   CATBody       * iSupport,
				  double iRadius);  

/**
* @nodoc
* Deprecated. Use CATCreateTopCorner.
*/
ExportedByParallel
CATTopCorner * CreateTopOpCornerTgtCenterOnPt (CATGeoFactory     * iFactory,
           CATTopData   * iData,
           CATBody      * iCurve,
           CATBody      * iPoint,
           CATBody      * iSupport);

/**
* @nodoc
* Deprecated. Use CATCreateTopCorner.
*/
ExportedByParallel
CATTopCorner * CreateTopOpCornerTgtCenterOnCrvRad (CATGeoFactory     * iFactory,
           CATTopData   * iData,
           CATBody      * iCurveCenter,
           CATBody      * iCurveTgt,
           double         iRadius,
           CATBody      * iSupport);


#endif


