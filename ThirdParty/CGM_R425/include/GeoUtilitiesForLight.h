/* -*-C++-*- */

#ifndef GeoUtilitiesForLight_H
#define GeoUtilitiesForLight_H

// COPYRIGHT DASSAULT SYSTEMES 2008

//=============================================================================
//=============================================================================
//
// GeoUtilitiesForLight : 
//                        
//
//=============================================================================

//=============================================================================
// May  2008  Creation                                                    SOU
//=============================================================================
//=============================================================================

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATCurve;
class CATSurface;
class CATMathPoint;
class CATCrvLimits;
class CATCrvParam;

#include "CATBoolean.h"
#include "TopUtilLight.h"

ExportedByTopUtilLight CATBoolean  FindSingleIntersectionCrvSur(CATGeoFactory* iFactory,
                                                               CATSoftwareConfiguration* iConfig,
                                                               CATCurve* iCurve, 
                                                               CATSurface* iSurface, 
                                                               const CATMathPoint &iRefPoint,
                                                               CATCrvLimits &iCrvLimits, 
                                                               const double &iTol, 
                                                               CATCrvParam &oIntParam);


#endif

//===========================================================================================================



