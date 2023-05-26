/* -*-C++-*- */
#ifndef CATTopRibDistanceMin_H
#define CATTopRibDistanceMin_H
// COPYRIGHT DASSAULT SYSTEMES 2002

//===================================================================
//
// Utilitaire de CATTopRib 
//
//===================================================================

//===================================================================
// Usage notes:
// - usage "Safe" de CreateDistanceMin
//
//===================================================================

//===================================================================
// Jan. 02    Creation                         R. Rorato
// 02/02/09 NLD Ajout methode avec SoftwareConfiguration
//===================================================================
//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"
#include "CATMathDef.h"
#include "CATBaseUnknown.h"

class CATGeoFactory;
class CATCurve;
class CATMathPoint;
class CATCrvParam;
class CATCrvLimits;
class CATSoftwareConfiguration;

ExportedByRIBLight CATBoolean CATTopRibDistanceMin(CATGeoFactory*     iFactory,  // returns whether operation was successfull
                                               CATSoftwareConfiguration* iConfig,
                                               CATMathPoint      &iPoint,
                                               CATCurve*          iCurve,
                                               CATCrvParam       &oParam,
                                               CATCrvLimits*      iCurveLimits=NULL,
                                               CATPositiveLength* ioMaxDistance=NULL); // returns MaxDist if not NULL
ExportedByRIBLight CATBoolean CATTopRibDistanceMin(CATGeoFactory*     iFactory,  // returns whether operation was successfull
                                               CATMathPoint      &iPoint,
                                               CATCurve*          iCurve,
                                               CATCrvParam       &oParam,
                                               CATCrvLimits*      iCurveLimits=NULL,
                                               CATPositiveLength* ioMaxDistance=NULL); // returns MaxDist if not NULL

#endif
