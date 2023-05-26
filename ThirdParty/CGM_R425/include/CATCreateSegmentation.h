
// COPYRIGHT DASSAULT SYSTEMES 1997 
//==========================================================================
//
// CATSegmentation:
// Interface class of the Interapproximation Operator for Curve.
//
//==========================================================================
//
// Usage notes:
//
//========================================================================== 
// July. 97     Creation                  Catherine Eymin
//========================================================================== 

#ifndef CATCreateSegmentation_H
#define CATCreateSegmentation_H

#include "FrFOpeCrv.h"

#include "CreateSegmentation.h"
#include "CATCGMVirtual.h"

class CATCurve;
class CATNurbsCurve;
class CATSoftwareConfiguration;
class CATSegmentation;

ExportedByFrFOpeCrv
CATSegmentation * CATCreateSegmentation(CATGeoFactory *iFactory, CATSoftwareConfiguration * iSoftwareConfiguration, 
                                        CATCurve       *iCurve,
                                        CATLONG32       NbSeg ,
                                        CATSkillValue mode=BASIC );
ExportedByFrFOpeCrv
CATSegmentation * CATCreateSegmentation(CATGeoFactory *iFactory, CATSoftwareConfiguration * iSoftwareConfiguration,
                                        CATLISTP(CATCurve ) &iListe,
                                        CATLONG32       NbSeg ,
                                        CATSkillValue mode=BASIC );

ExportedByFrFOpeCrv
CATSegmentation * CATCreateSegmentation(CATGeoFactory *iFactory, CATSoftwareConfiguration * iSoftwareConfiguration,
                                        CATCurve       *iCurve,
                                        CATLONG32       NbSeg ,
                                        CATLONG32      &NbBreak,
                                        CATCrvParam    *Wpar,     
                                        CATSkillValue   mode=BASIC );

ExportedByFrFOpeCrv
CATSegmentation * CATCreateSegmentation(CATGeoFactory *iFactory, CATSoftwareConfiguration * iSoftwareConfiguration,
                                        CATCurve       *iCurve,
                                        double         &Tolap ,
                                        CATSkillValue   mode=BASIC );
ExportedByFrFOpeCrv
CATSegmentation * CATCreateSegmentation(CATGeoFactory *iFactory, CATSoftwareConfiguration * iSoftwareConfiguration,
                                        CATLISTP(CATCurve ) &iListe,
                                        double              &Tolap ,
                                        CATSkillValue        mode=BASIC );
ExportedByFrFOpeCrv
CATSegmentation * CATCreateSegmentation(CATGeoFactory *iFactory, CATSoftwareConfiguration * iSoftwareConfiguration,
                                        CATCurve       *iCurve,
                                        double         &Tolap ,
                                        CATLONG32      &NbBreak,
                                        CATCrvParam    *Wpar,     
                                        CATSkillValue   mode=BASIC );


#endif


