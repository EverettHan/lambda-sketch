
#ifndef CreateSketchGeodesic_H 
#define CreateSketchGeodesic_H 
// UTILISER LE CATCreateSketchGeodesic si possible
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

//aov wk 43 2005: par ce create, le journal ne contient que les ordres sur les edges
//j'ajoute la variable iModeJourn permettant de gerer maintenant l'ordre sur les vertex
//sans destabiliser le code existant qui retraitait ces ordres.
ExportedByAdvTopoSketchLight
CATSketchGeodesic * CreateGeodesicPointDir (CATGeoFactory     * iFactory,
                                            CATTopData        * iData,
					    CATGeometry       * iSupport = NULL,
					    CATGeometry       * iPoint = NULL,
					    CATMathVector     * iTangent = NULL,
					    CATPositiveLength   iLength = 0,
					    CATBody           * iTargetBody = NULL,
					    CATSkillValue       iMode = BASIC,
              int                 iModeJourn=0);


// deprecated - Do not use
ExportedByAdvTopoSketchLight
CATSketchGeodesic * CreateGeodesicPointDir (CATGeoFactory     * iFactory,
					    CATGeometry       * iSupport = NULL,
					    CATGeometry       * iPoint = NULL,
					    CATMathVector     * iTangent = NULL,
					    CATPositiveLength   iLength = 0,
					    CATBody           * iTargetBody = NULL,
					    CATCGMJournalList * iReport = NULL,
					    CATSkillValue       iMode = BASIC);
//
ExportedByAdvTopoSketchLight
void Remove( CATSketchGeodesic *&iSketchGeodesic );
//
#endif


