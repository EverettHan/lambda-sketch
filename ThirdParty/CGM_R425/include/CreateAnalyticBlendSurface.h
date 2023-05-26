// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CreateAnalyticBlendSurface :
// Declaration of global functions used to create and destroy
// an instance of the Analytic Blend Surface operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// May. 97 TPG Creation                          Tuan Phung
// 18/04/12 NLD Ajout CATCreateAnalyticBlendSurface avec CATSoftwareConfiguration
//              Detabulation
//=============================================================================
#ifndef CreateAnalyticBlendSurface_H 
#define CreateAnalyticBlendSurface_H 

#include "FrFOpeSur.h"

#include "CATSkillValue.h"

class CATGeoFactory;
class CATCurve;
class CATCrvLimits;
class CATAnalyticBlendSurface;
class CATSoftwareConfiguration;

//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATAnalyticBlendSurface *    CreateAnalyticBlendSurface(      CATGeoFactory            *  iFactory   ,
                                                        const CATCurve                 *  iCurve1    ,
                                                        const CATCrvLimits              & iCrvLimits1,
                                                        const CATCurve                 *  iCurve2    ,
                                                        const CATCrvLimits              & iCrvLimits2,
                                                              CATSkillValue               iMode      = BASIC);
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATAnalyticBlendSurface * CATCreateAnalyticBlendSurface(      CATGeoFactory            *  iFactory   ,
                                                              CATSoftwareConfiguration *  iConfig    ,
                                                        const CATCurve                 *  iCurve1    ,
                                                        const CATCrvLimits              & iCrvLimits1,
                                                        const CATCurve                 *  iCurve2    ,
                                                        const CATCrvLimits              & iCrvLimits2);


//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
void Remove( CATAnalyticBlendSurface *&ioAnalyticBlendSurface );



#endif


