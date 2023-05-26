#ifndef CREATEINTERPROXSUR_H 
#define CREATEINTERPROXSUR_H 

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "FrFOpeSur.h"

#include "CATSkillValue.h"

#ifndef NULL
#define NULL 0
#endif
#include "CATListOfCATSurfaces.h"
#include "CATCreateInterproxSur.h" // pour assurer build chez clients CAA compte tenu de migration Remove vers celui-ci. NLD130117

class CATGeoFactory;
class CATMathSetOfPointsND;
class CATMathSetOfVectors;
class CATMathDirection;
class CATInterproxSur;
class CATNurbsSurface;
class CATFrFCompositeSurface;

/**
 * @deprecated V5R14 CATCreateInterproxSur
 */


// SUPPRESSION IMPOSSIBLE, Encore utilise par FreeStyleShapeUI NLD 11/03/15

ExportedByFrFOpeSur
CATInterproxSur * CreateInterproxSur(      CATGeoFactory        *  iFactory    ,
                                           CATLISTP(CATSurface ) & iListe      ,
                                     const CATMathSetOfPointsND *  iPoints     ,
                                     const CATMathSetOfVectors  *  iVectors    ,
                                           double                & iTension    ,
                                           double                & iSmoothness ,
                                           double                & tolapp      ,
                                     const int                  *  iImposition ,
                                     const CATMathDirection     *  iVect       = NULL,
                                           CATSkillValue           iMode       = BASIC );

#endif









