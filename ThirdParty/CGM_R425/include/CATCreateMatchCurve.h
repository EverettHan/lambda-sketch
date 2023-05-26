// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CreateMatchCurve :
// Declaration of global functions used to create an instance of the Match 
// Curve operator.
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
//   /01/98 JBX Creation                                           Julien Bouix
// 05/03/15 NLD Reception de la configuration
//=============================================================================

#ifndef CreateMatchCurve_H 
#define CreateMatchCurve_H 

#include "FrFOpeCrv.h"
#include "CATSkillValue.h"

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATCurve;
class CATCrvParam;
class CATMatchCurve;
class CATPointOnCurve;
class CATPoint;

// DO NOT USE (use CATPGMCreateMatchCurve())
ExportedByFrFOpeCrv
CATMatchCurve * CATCreateMatchCurve(      CATGeoFactory           * iFactory   ,
                                          CATSoftwareConfiguration* iConfig    ,
                                    const CATPointOnCurve         * iLimitPoint,
                                    const CATCurve                * iCrvMatched,
                                    const CATCurve                * iCrvRef    ,
                                    const CATCrvParam             & iParamPtRef,
                                          CATSkillValue             iMode=BASIC);

// DO NOT USE (use CATPGMCreateMatchCurve())
ExportedByFrFOpeCrv
CATMatchCurve * CATCreateMatchCurve(      CATGeoFactory           * iFactory   ,
                                          CATSoftwareConfiguration* iConfig    ,
                                    const CATPointOnCurve         * iLimitPoint,
                                    const CATCurve                * iCrvMatched,
                                          CATPoint                * iRefPoint  ,
                                          CATSkillValue             iMode=BASIC);

#endif





