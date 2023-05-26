//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CreateFrFIntersection :
// Declaration of global function used to create and destroy
// an instance of the CATFrFIntersectionCCvCCv operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// November 1998      Creation                 Paul-Alexandre LOURME
//=============================================================================
#ifndef CreateFrFIntersectionCCvCCv_H 
#define CreateFrFIntersectionCCvCCv_H 
//
#include "CATIACGMLevel.h"
//
#include "FrFAdvancedOpeCrv.h"
#include "CATFrFIntersectionCCvCCv.h"
#include "CATSkillValue.h"
#include "CATGeoFactory.h"
//
class CATSoftwareConfiguration;


ExportedByFrFAdvancedOpeCrv
CATFrFIntersectionCCvCCv * CATCreateFrFIntersectionCCvCCv (CATGeoFactory         * iFactory,
                                                        CATFrFCompositeCurve  * iCCv1,
                                                        CATFrFCompositeCurve  * iCCv2,
                                                        CATSkillValue iMode=BASIC,
                                                        const CATSoftwareConfiguration * iConfig=NULL);
//

#endif
