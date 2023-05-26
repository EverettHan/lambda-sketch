// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CreateGeometricBlendSurface :
// Declaration of global functions used to create and destroy
// an instance of the Geometric Blend Surface operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
//   /12/97 ALM Creation                          Paul-Alexandre Lourme --  alm
//   /07/99 ALM Modification
// 29/03/18 NLD Reception et transmission de la configuration dans tous les Create
//              Mise au propre; smart indent
//=============================================================================
#ifndef CreateGeometricBlendSurface_H 
#define CreateGeometricBlendSurface_H 

#include "FrFAdvancedOpeSur.h"

#include "CATDataType.h"
#include "CATSkillValue.h"

class CATGeoFactory;
class CATFrFCompositeCurve;
class CATFrFCompositeCurveMapping;
class CATFrFCCvLimits;
class CATFrFCoupling;
class CATGeometricBlendSurface;
class CATSoftwareConfiguration;


ExportedByFrFAdvancedOpeSur
CATGeometricBlendSurface * CreateGeometricBlendSurface      (      CATGeoFactory                * iFactory     ,
                                                                   CATSoftwareConfiguration     * iConfig      ,
                                                             const CATFrFCompositeCurve        ** iCompCurve   ,
                                                             const CATFrFCCvLimits              * iCCvLimits   = 0,
                                                             const CATFrFCompositeCurveMapping ** iCCvMapping  = 0,
                                                                   CATSkillValue                  iMode        = BASIC);

ExportedByFrFAdvancedOpeSur
CATGeometricBlendSurface * CreateGeometricBlendSurface      (      CATGeoFactory                * iFactory     ,
                                                                   CATSoftwareConfiguration     * iConfig      ,
                                                                   CATLONG32                      iLevel       ,
                                                             const CATFrFCompositeCurve         * iCompCurve1  ,
                                                             const CATFrFCompositeCurve         * iCompCurve2  ,
                                                                   CATSkillValue                  iMode        = BASIC);
ExportedByFrFAdvancedOpeSur
CATGeometricBlendSurface * CreateGeometricBlendSurface      (      CATGeoFactory                * iFactory     ,
                                                                   CATSoftwareConfiguration     * iConfig      ,
                                                             const CATFrFCompositeCurve         * iCompCurve1  ,
                                                             const CATFrFCompositeCurve         * iCompCurve2  ,
                                                                   CATSkillValue                  iMode        = BASIC);

ExportedByFrFAdvancedOpeSur
CATGeometricBlendSurface * CreateGeometricFilletBlendSurface(      CATGeoFactory                * iFactory     ,
                                                                   CATSoftwareConfiguration     * iConfig      ,
                                                             const CATFrFCompositeCurve         * iCompCurve1  ,
                                                             const CATFrFCompositeCurve         * iCompCurve2  ,
                                                                   CATSkillValue                  iMode        = BASIC);

ExportedByFrFAdvancedOpeSur
CATGeometricBlendSurface * CreateGeometricExtrapolSurface   (      CATGeoFactory                * iFactory     ,
                                                                   CATSoftwareConfiguration     * iConfig      ,
                                                             const CATFrFCompositeCurve         * iCompCurve   ,
                                                             const CATFrFCCvLimits              * iCCvLimits   = 0,
                                                             const CATFrFCompositeCurveMapping  * iCCvMapping  = 0,
                                                                   CATSkillValue                  iMode        = BASIC);

ExportedByFrFAdvancedOpeSur
CATGeometricBlendSurface * CreateGeometricBlextSurface      (      CATGeoFactory                * iFactory     ,
                                                                   CATSoftwareConfiguration     * iConfig      ,
                                                             const CATLONG32                      iNbCCv       ,
                                                             const CATFrFCompositeCurve        ** iCompCurve   ,
                                                                   CATFrFCoupling               * iCoupling    = 0);

/*ExportedByFrFAdvancedOpeSur
CATGeometricBlendSurface * CreateGeometricBlextSurface      (      CATGeoFactory                * iFactory     ,
                                                                   CATSoftwareConfiguration     * iConfig      ,
                                                                   CATLONG32                      iLevel       ,
                                                             const CATLONG32                      iNbCCv       ,
                                                             const CATFrFCompositeCurve        ** iCompCurve   ,
                                                                   CATFrFCoupling               * iCoupling    = 0);
*/

ExportedByFrFAdvancedOpeSur
CATGeometricBlendSurface * CreateGeometricBlextMultiForm    (      CATGeoFactory                * iFactory     ,
                                                                   CATSoftwareConfiguration     * iConfig      ,
                                                                   CATLONG32                      ilevel       ,
                                                             const CATLONG32                      iNbCCv       ,
                                                             const CATFrFCompositeCurve        ** iCompCurve   ,
                                                                   CATFrFCoupling               * iCoupling    = 0);
ExportedByFrFAdvancedOpeSur
CATGeometricBlendSurface * CreateGeometricBlextMultiForm    (      CATGeoFactory                * iFactory     ,
                                                                   CATSoftwareConfiguration     * iConfig      ,
                                                             const CATLONG32                      iNbCCv       ,
                                                             const CATFrFCompositeCurve        ** iCompCurve   ,
                                                                   CATFrFCoupling               * iCoupling    = 0);

ExportedByFrFAdvancedOpeSur
void Remove( CATGeometricBlendSurface *&ioGeometricBlendSurface );



#endif


