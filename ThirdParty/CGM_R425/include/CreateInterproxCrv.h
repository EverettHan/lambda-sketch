#ifndef CREATEINTERPROXCRV_H 
#define CREATEINTERPROXCRV_H 

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "FrFOpeCrv.h"

#include "CATSkillValue.h"
#include "CATListOfCATCurves.h"
#include "CATCreateInterproxCrv.h" // pour assurer au clien CAA la presence de Remove() que je migre dans celui-la
class CATGeoFactory;
class CATMathSetOfPointsND;
class CATMathSetOfVectors;
class CATInterproxCrv;
class CATCurve;

/**
 * @deprecated V5R14 CATCreateInterproxCrv
 */
// SUPPRESSION IMPOSSIBLE, Encore utilise par FreeStyleShapeUI NLD 11/03/15

ExportedByFrFOpeCrv
CATInterproxCrv * CreateInterproxCrv(      CATGeoFactory        *  iFactory      ,
                                           CATLISTP(CATCurve )   & iListe        ,
                                     const CATMathSetOfPointsND *  iPoints       ,
                                     const CATMathSetOfVectors  *  iVectors      ,
                                           double                & iTension      ,
                                           double                & iSmoothness   ,
                                           double                & iTolapp       ,
                                     const int                     iImposition[2],
                                           CATSkillValue           iMode         = BASIC );


#endif
