// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CreateCrvOneArcProjection :
// Declaration of global functions used to create and destroy
// an instance of the Curve Projection operator (giving a one-arc PNurbs)
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// August 98  Creation                          DHN
// 28/06/15 NLD Ajout de la configuration (anciennement passee a posteriori a l'operateur
//              en argument
//=============================================================================
#ifndef CreateCrvOneArcProjection_H 
#define CreateCrvOneArcProjection_H 
//
#include "PowerFrFOperators.h"
#include "CATDataType.h"
#include "CATSkillValue.h"
//
class CATGeoFactory;
class CATSurface;
class CATCurve;
class CATPNurbs;
class CATCrvLimits;
class CATSurLimits;
class CATMathDirection;
class CATCrvOneArcProjection;
class CATSoftwareConfiguration;

ExportedByPowerFrFOperators
CATCrvOneArcProjection * CreateCrvOneArcProjection(      CATGeoFactory           *  iFactory     ,
                                                         CATSoftwareConfiguration*  iConfig      ,
                                                   const CATCurve                *  iCrvToProject,
                                                   const CATCrvLimits            *  iCrvLim      ,
                                                   const CATSurface              *  iSurface    ,
                                                   const CATSurLimits            *  iSurLim     ,
                                                   const double                   & iToler      ,
                                                   const CATLONG32                & iMaxDegree  ,
                                                   const CATMathDirection        *  iDirection  = (const CATMathDirection*)0,
                                                         CATSkillValue              iMode       = BASIC);

//
ExportedByPowerFrFOperators
void Remove( CATCrvOneArcProjection *&iCrvOneArcProjection );

#endif


