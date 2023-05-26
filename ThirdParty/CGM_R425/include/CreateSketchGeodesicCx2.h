
#ifndef CreateSketchGeodesicCx2_H 
#define CreateSketchGeodesicCx2_H 

//#include "AdvTopoSketch.h"
#include "AdvTopoSketchLight.h"

#include "CATMathDef.h"
#include "CATSkillValue.h"
#include <stdlib.h>
//
class CATSketchGeodesic;
class CATGeoFactory;
class CATGeometry;
class CATMathVector;
class CATBody;
class CATCGMJournalList;
class CATTopData;
class CATSketchGeodesicCx2;

//D1A Mar 23
//=============================================================================
// CGM Internal use
//=============================================================================

ExportedByAdvTopoSketchLight
CATSketchGeodesicCx2 * CreateGeodesicPointDirCx2(CATGeoFactory     * iFactory,
                                                CATTopData        * iData,
																						    CATGeometry       * iSupport = NULL,
																						    CATGeometry       * iPoint = NULL,
																						    CATMathVector     * iTangent = NULL,
																						    CATPositiveLength   iLength = 0,
																						    CATBody           * iTargetBody = NULL,
																						    CATSkillValue       iMode = BASIC,
																	              int                 iModeJourn=0);



#endif


