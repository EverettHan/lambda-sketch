#ifndef CATCreateTryDistance_h
#define CATCreateTryDistance_h

// encapsulation de la distance par try et catch

#include "CATSkillValue.h"
#include "CATDistanceMinPtCrv.h"
#include "CATDistanceMinPtSur.h"
#include "CATDistanceMinCrvCrv.h"

class CATPCurve;
class CATCurve;
class CATSurface;
class CATMathPoint;
class CATGeoFactory;
class CATSoftwareConfiguration;


#include "GeoPlate.h"


ExportedByGeoPlate  CATDistanceMinPtCrv * CATCreateTryDistance(CATGeoFactory * iFactory,
															   CATSoftwareConfiguration * iConfig,
							   const CATMathPoint & iPt,
							   CATCurve * iCrv,
							   CATSkillValue iMode=BASIC);


ExportedByGeoPlate  CATDistanceMinPtSur * CATCreateTryDistance(CATGeoFactory * iFactory,
															   CATSoftwareConfiguration * iConfig,
                                     const CATMathPoint & iPt, 
                                     const CATSurface *iSur,
                                     CATBoolean iSearchOnBoundary =TRUE,
                                     CATSkillValue iMode=BASIC );

ExportedByGeoPlate CATDistanceMinCrvCrv * CATCreateTryDistance(CATGeoFactory * iFactory, 
															   CATSoftwareConfiguration * iConfig,
                                                            CATCurve * iCrv1,
                                                            CATCurve * iCrv2,
                                                            CATSkillValue iMode = BASIC);

#endif
