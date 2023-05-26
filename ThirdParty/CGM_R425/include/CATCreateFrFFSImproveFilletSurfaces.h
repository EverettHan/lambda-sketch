//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2011
//=============================================================================
//
// 05-05-11    MWE ; Creation 
//=============================================================================
#ifndef CATCreateFrFFSImproveFilletSurfaces_h
#define CATCreateFrFFSImproveFilletSurfaces_h

#include "GeoPlate.h"

#include "CATFrFImproveFilletSurfaces.h"
class CATSoftwareConfiguration;
class CATGeoFactory;


//-----------------------------------------------------------------------------

ExportedByGeoPlate CATFrFImproveFilletSurfaces* 
 CATCreateFrFFSImproveFilletSurfaces(CATGeoFactory*  iFactory, CATSoftwareConfiguration * iSoftConfig);


#endif

