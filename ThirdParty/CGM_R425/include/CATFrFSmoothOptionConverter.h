#ifndef CATFrFSmoothOptionConverter_H
#define CATFrFSmoothOptionConverter_H

//=============================================================================
//
// DESCRIPTION : Smooth option management and convert
//
//=============================================================================
// 17/11/14 NLD Creation
//              CATFrFSmoothOptionConverter(): conversion centralisee de SmoothOption
//              pour breakpoint, filtre et controle eventuel
// 16/12/15 NLD Embryon de documentation par collecte d'information,
//              sur les differents modes
//=============================================================================

#include "FrFAdvancedObjects.h"

// A noter. Au 161216
// - TopoSweep
//   CATFrFTopologicalSweep.h documente 0 et 1
//   CATFrFTopologicalSweepCx2.h ne documente rien
//   CATFrFTopologicalSweepCx2::GetSmoothOptionForGeometricalOperator()
//   laisse entendre que la valeur 2 est possible en provenance de SkinExtrapol
//   CATFrFTopologicalSweepCx2::SmoothAndG1SpineLevelForExtrapol fait un test explicite a 1
// - GeomSweep: CATGeneralizedSweepSurface.h
//   To get a G1 normal comb everywhere the underlying curve is G1.
//   iOption =0 => No Smooth
//           =1 => All Smooths are activate (MovingFrame & Normal)
//           =2 => Only Smooth of normals are activated. Spine is not changed. (G1 Extrapolation)
// - Profile: CATFrFImplicitProfile.h
//   les valeurs de SetSmoothOption() de CATFrFImplicitProfile ne sont pas documentees
//   mais les usages (_SmoothOption) distinguent 0 et valeur non nulle
// - RefElem:
//   non documente dans CATFrFRefElement.h
//   non documente dans CreateFrFGeomRefElement.h qui recoit l'option
//   recu           par CATGeneralizedSweepSurfaceCx2 et transmis a CATFrFSweepChecker
//   initialise a 0 par CATGeneralizedSweepSurfaceCx2 (ou fixe a 1 par declaratif)
//   non documente dans CATFrFSweepChecker.h
//   test de non nullite dans CATFrFSweepChecker.cpp (pour savoir si on doit respecter les tangences)
// Donc
// - au sein de l'operateur geometrique, les conversions, quoiqu'illegales vers RefElem et Profile
//   transmettent a priori la valeur 2 eventuelle, mais sans que cela soit vraiment genant

// - TopoSweep:
typedef enum
  {
   CATFrFSmoothOptionConvert_Unknown                  = 0,
   CATFrFSmoothOptionConvert_FromGeomSweepToRefElem   = 1,
   CATFrFSmoothOptionConvert_FromGeomSweepProfile     = 2,
   CATFrFSmoothOptionConvert_FromTopoSweepToGeomSweep = 3
  }
   CATFrFSmoothOptionConvert_ConvertType;

//=============================================================================
/** @nodoc @nocgmitf */
ExportedByFrFAdvancedObjects
int CATFrFSmoothOptionConverter(int                                   iSmoothOption,
                                CATFrFSmoothOptionConvert_ConvertType iConvertType = CATFrFSmoothOptionConvert_Unknown
                               ); 

#endif
