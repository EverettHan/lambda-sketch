// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CATCreateBreakCurve :
// Declaration of global functions used to create and destroy
// an instance of the Break Curve operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// July. 97 GDR Creation
// Feb.  98 NDN Modification (with a KnotRank)
// 30/03/15 NLD Mise au propre complete
//              - mise de l'historique au standard
//              - suppression des tabulations
//              - smart indent
//              - reception de la configuration
//=============================================================================
#ifndef CATCreateBreakCurve_H 
#define CATCreateBreakCurve_H 
//
#include "FrFOpeCrv.h"
#include "CATDataType.h"
#include "CATSkillValue.h"
//
class CATGeoFactory;
class CATPointOnCurve;
class CATBreakCurve;
class CATNurbsCurve;
class CATSoftwareConfiguration;

//=============================================================================
ExportedByFrFOpeCrv
CATBreakCurve * CATCreateBreakCurve(CATGeoFactory           * iFactory              ,
                                    CATSoftwareConfiguration* iSoftwareConfiguration,
                                    CATPointOnCurve         * iPtBreak              ,
                                    CATSkillValue             iMode                 = BASIC);


ExportedByFrFOpeCrv
CATBreakCurve * CATCreateBreakCurve(CATGeoFactory           * iFactory              ,
                                    CATSoftwareConfiguration* iSoftwareConfiguration,
                                    CATNurbsCurve           * iCrvToBreak           ,
                                    CATLONG32                 iKnotRank             ,
                                    CATSkillValue             iMode                 = BASIC);

#endif


