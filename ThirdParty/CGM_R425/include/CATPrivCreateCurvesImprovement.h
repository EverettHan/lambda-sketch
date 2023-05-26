//===================================================================
//   
// COPYRIGHT   : DASSAULT SYSTEMES 2000
//
// DESCRIPTION : CurvesImprovement
//
//
//===================================================================
#ifndef CreateCurvesImprovement_H
#define CreateCurvesImprovement_H

#include "FrFAdvancedOpeCrv.h"

#include "CATListOfCATGeometries.h"
#include "CATListOfCATCurves.h"
#include "CATListOfCATCrvParams.h"
#include "CATListOfCATCrvLimits.h"
#include "CATLISTP_CATMathPlane.h"
#include "CATLISTP_CATMathVector.h"
#include "CATFreeFormDef.h"
#include "CATListOfInt.h"
#include "CATListOfDouble.h"
#include "CATBoolean.h"
#include "CATCurvesImprovementDefine.h"
#include "CATCGMVirtual.h"

class CATLocalizer2DFrom3D;
class CATMathSetOfPoints;
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATCurvesImprovement;

//
// To create an instance of the operator :
// ---------------------------------------
// List of CATCurves must be G0 connected.
// All are : 3D curves or Pcurves on a same shell. No combination is allowed.
//
//---------------------------------------
//       WARNING
//---------------------------------------
//if iSoftwareConfiguration == NULL, then you will use an older version of CurvesImprovement
//
ExportedByFrFAdvancedOpeCrv 
CATCurvesImprovement * CATPrivCreateCurvesImprovement (CATSoftwareConfiguration * iSoftwareConfiguration,
                                                   CATGeoFactory            * iFactory,
                                                   const CATLISTP(CATCurve)       * iCurvesToImprove,
                                                   const CATLISTP(CATCrvLimits)   * iListOfLimits = 0,
                                                   const CATListOfInt             * iListOfOrientations = 0);
//
// OBSOLETE CONSTRUCTOR :
//
ExportedByFrFAdvancedOpeCrv 
CATCurvesImprovement * CATPrivCreateCurvesImprovement (CATGeoFactory          * iFactory,
                                                   const CATLISTP(CATCurve)     * iCurvesToImprove,
                                                   const CATLISTP(CATCrvLimits) * iListOfLimits = 0,
                                                   const CATListOfInt           * iListOfOrientations = 0);

#endif
