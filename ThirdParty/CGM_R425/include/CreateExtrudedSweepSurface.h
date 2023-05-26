// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CreateExtrudedSweepSurface:
// Utility for producing sweep of Geometric entities.
//=============================================================================
// Usage notes:
//
// - CXR2.
// - reserve (Protected) a l operateur topologique de Sweep.
//=============================================================================
// 17 07 98 CPL Creation
// 19 06 02 ALV Ajout de iSoftwareConfiguration (pour versionning de CATExtruder)
// 16 12 02 NLD Ajout de iSoftwareConfiguration dans le Create standard
// 03/10/14 NLD Reordonnancement des arguments pour les createurs canoniques
//              en conformite avec le createur standard (configuration en deuxieme)
//              Reception de l'index de domaine
//=============================================================================
#ifndef CreateExtrudedSweepSurface_H
#define CreateExtrudedSweepSurface_H
//
#include "FrFAdvancedOpeSur.h"
#include "CATMathDef.h"
#include "CATSkillValue.h"
#include "CATSoftwareConfiguration.h"
//
class CATGeoFactory;
class CATFrFCompositeCurve;
class CATExtrudedSweepSurface;
class CATMathAxis;
class CATMathTransformation;
class CATFrFSweepShape;
//-----------------------------------------------------------------------------
ExportedByFrFAdvancedOpeSur
CATExtrudedSweepSurface** CreateExtrudedSweepSurface
(CATGeoFactory           * iFactory              ,
 CATSoftwareConfiguration* iSoftwareConfiguration,
 CATFrFCompositeCurve    * iProfile              ,
 CATFrFCompositeCurve    * iGuide                ,
 CATLONG32                 iCrvIndex             ,
 CATFrFSweepShape        * iShape                ,
 CATLONG32                 iDomainIndex          = 0
);

ExportedByFrFAdvancedOpeSur
CATExtrudedSweepSurface** CreateExtrudedSweepSurfaceByLine
(CATGeoFactory           * iFactory              ,
 CATSoftwareConfiguration* iSoftwareConfiguration,
 CATFrFCompositeCurve    * iProfile              ,
 CATFrFCompositeCurve    * iGuide                ,
 CATLONG32                 iCrvIndex             ,
 CATLONG32                 iDomainIndex          ,
 CATMathTransformation   * iProfileTransfo
);

ExportedByFrFAdvancedOpeSur
CATExtrudedSweepSurface** CreateExtrudedSweepSurfaceByCircle
(CATGeoFactory           * iFactory              ,
 CATSoftwareConfiguration* iSoftwareConfiguration,
 CATFrFCompositeCurve    * iProfile              ,
 CATFrFCompositeCurve    * iGuide                ,
 CATLONG32                 iCrvIndex             ,
 CATLONG32                 iDomainIndex          ,
 CATMathTransformation   * iProfileTransfo       ,
 CATMathAxis             & iAxis                 
);

#endif
