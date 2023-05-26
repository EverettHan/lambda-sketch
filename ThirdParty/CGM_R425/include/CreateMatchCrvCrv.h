// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CreateMatchCrCrv :
// Declaration of global functions used to create an instance of the Match 
// Curve Curve operator.
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// August 1999  Creation                        Paul-Alexandre LOURME (alm)
// 08 01 04 CCK Ajout de la SoftwareConfiguration
//=============================================================================

#ifndef CreateMatchCrvCrv_H 
#define CreateMatchCrvCrv_H 

#include "FrFOpeCrv.h"
#include "CATSkillValue.h"

class CATMatchCrvCrv;
class CATGeoFactory;
class CATCurve;
class CATPoint;
class CATSoftwareConfiguration;

// Create Match Crv Crv
// For each side give a curve and/or a point. 
// Give at least one curve to create the operator.
ExportedByFrFOpeCrv
CATMatchCrvCrv * CreateMatchCrvCrv(CATGeoFactory            * iFactory,
                                   CATCurve                 * iCurve1,
                                   CATPoint                 * iPoint1,
                                   CATCurve                 * iCurve2,
                                   CATPoint                 * iPoint2,
                                   CATSkillValue              iMode=BASIC,
                                   CATSoftwareConfiguration * iConfig=NULL);

ExportedByFrFOpeCrv
void Remove( CATMatchCrvCrv *&iMatchCrvCrv);

#endif





