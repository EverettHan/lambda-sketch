// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CATCreateGeometricMatchSurface :
// Declaration of global functions used to create and destroy
// an instance of the Geometric Match Surface operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// Dec 97  Creation                      Paul-Alexandre Lourme --  alm 
// 03/09/03 CCK : Nouveau create avec la SoftwareConfiguration
//=============================================================================
#ifndef CATCreateGeometricMatchSurface_H 
#define CATCreateGeometricMatchSurface_H 

#include "FrFAdvancedOpeSur.h"

#include "CATSkillValue.h"

class CATGeoFactory;
class CATFrFCompositeCurve;
class CATGeometricMatchSurface;
class CATPLine;
class CATSoftwareConfiguration;

// NE PLUS APPELER car pas de config
ExportedByFrFAdvancedOpeSur
CATGeometricMatchSurface * CATCreateGeometricMatchSurface(       CATGeoFactory           * iFactory    ,
                                                         //const CATFrFCompositeCurve    * iCompCurve1 ,
                                                           const CATPLine                * iFrontiere  ,
                                                           const CATFrFCompositeCurve    * iCompCurve2 ,
                                                                 CATSkillValue             iMode       = BASIC);

ExportedByFrFAdvancedOpeSur
CATGeometricMatchSurface * CATCreateGeometricMatchSurface(      CATSoftwareConfiguration * iConfig     ,
                                                                CATGeoFactory            * iFactory    ,
                                                        //const CATFrFCompositeCurve     * iCompCurve1 ,
                                                          const CATPLine                 * iFrontiere  ,
                                                          const CATFrFCompositeCurve     * iCompCurve2 ,
                                                                CATSkillValue              iMode       = BASIC);


#endif


