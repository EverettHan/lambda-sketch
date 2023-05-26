// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CreateCrvFittingToNupbsArc :
// Interface for the creation of the Curve Approximation in a mono arc NUPBS.
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
//   /09/99 DHN Creation                                                    DHN
// 25/06/15 NLD Ajout signature avec configuration
//=============================================================================
#ifndef CreateCrvFittingToNupbsArc_H 
#define CreateCrvFittingToNupbsArc_H 
//
#include "PowerFrFOperators.h"
#include "CATDataType.h"
#include "CATSkillValue.h"
//
class CATGeoFactory;
class CATCurve;
class CATNurbsCurve;
class CATPNurbs;
class CATCrvLimits;
class CATCrvFittingToNupbsArc;
class CATSoftwareConfiguration;

//=============================================================================
ExportedByPowerFrFOperators
CATCrvFittingToNupbsArc * CATCreateCrvFittingToNupbsArc(      CATGeoFactory           *  iFactory     ,
                                                              CATSoftwareConfiguration*  iConfig      ,
                                                        const CATCurve                *  iCrvToConvert,
                                                        const CATCrvLimits            *  iCrvLim      ,
                                                        const CATLONG32                & iDimension   ,
                                                        const double                   & iToler       ,
                                                        const CATLONG32                & iMaxDegree   ,
                                                              CATSkillValue              iMode        = BASIC);
// DEPRECATED
ExportedByPowerFrFOperators
CATCrvFittingToNupbsArc * CATCreateCrvFittingToNupbsArc(      CATGeoFactory           *  iFactory     ,
                                                        const CATCurve                *  iCrvToConvert,
                                                        const CATCrvLimits            *  iCrvLim      ,
                                                        const CATLONG32                & iDimension   ,
                                                        const double                   & iToler       ,
                                                        const CATLONG32                & iMaxDegree   ,
                                                              CATSkillValue              iMode        = BASIC);


#endif


