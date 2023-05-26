// COPYRIGHT DASSAULT SYSTEMES 1999
//============================================================================
//
// CreateFrFGeomRefElement :
// Declaration of global functions used to create and destroy
// an instance of a Geometric Reference Element
//
//============================================================================
//    01 99 CPL Creation
// 26 09 14 NLD Gestion de configuration: CreateGeomRefElement recoit une configuration
//============================================================================
#ifndef CreateFrFGeomRefElement_H
#define CreateFrFGeomRefElement_H

#include "CATDataType.h"
#include "FrFAdvancedObjects.h"
#include "CATFrFRefElement.h"

class CATGeoFactory;
class CATGeometry;
class CATFrFCompositeCurve;
class CATFrFNormalMultiComb;
class CATSoftwareConfiguration;

ExportedByFrFAdvancedObjects 
CATFrFRefElement* CreateGeomRefElement(      CATGeoFactory           * iFactory       ,
                                             CATSoftwareConfiguration* iConfig        ,
                                       const CATGeometry             * iSurface       );

// iSmoothOption==1 <=> To get a G1 normal comb everywhere the underlying curve is G1.
ExportedByFrFAdvancedObjects 
CATFrFRefElement* CreateCcvRefElement (      CATGeoFactory           * iFactory       ,
                                             CATFrFCompositeCurve    * iCcv           ,
                                             CATFrFNormalMultiComb   * iComb          = 0,
                                             CATLONG32                 iSmoothOption  = 0,
                                             double                    iSmoothAngle   = -1.,
                                             CATLONG32                 iCGMLevel      = 0,
                                             int                       iC0Deformation = 0,
                                             int                       iGlobalLaw     = 1);

#endif 
