// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CATExtruderByMatrix:
// Utility for producing Linear or Circular extrusion of Geometric entities.
//
//=============================================================================
// Usage notes:
//
// - Master class for CATExtruderByLine & CATExtruderByCircle.
//=============================================================================
// June 98   Creation                                     R. Rorato
// 19 07 02 ALV Ajout de iSoftwareConfiguration comme donnee du constructeur.(pour versionning)
// 13/06/08 NLD Ajout SetResult() (derivation) (pour rederivation par CATExtruderBySweep)
// 05 03 09 FDS RI650024 , non prise en compte des points on surface
// 12/04/10 NLD La gestion des courbes a detruire est centralisee dans 2 nouvelles methodes
//              AddCurveToDelete() et RemoveCurvesToDelete()
// 28/10/15 NLD Ajout DebugCloneAndCount(): clonage avec comptage pour debug des leaks de surfaces
//=============================================================================
#ifndef CATExtruderByMatrix_H
#define CATExtruderByMatrix_H

#include "Extrude.h"                          // For Windows 
#include "CATExtruder.h"                      // For inheritance
#include "CATSoftwareConfiguration.h"

class CATTransfoManager ;
class CATMacroPoint ;
class CATEdgeCurve ;
class CATSurface ;
class CATPlane ;
class CATMathTransformation ;

#include "CATListOfCATPoints.h"
#include "CATListOfCATMacroPoints.h"
#include "CATListOfCATPointOnEdgeCurves.h"
#include "CATListOfCATPCurves.h"
#include "CATListOfCATCurves.h"
#include "CATListOfCATSurfaces.h"
#include "CATListOfCATTransfoManagers.h"
//---------------------------------------------------------------------------
class ExportedByExtrude CATExtruderByMatrix: public CATExtruder
{
  public :

  //-------------------------------------------------------------------------
                       CATExtruderByMatrix       (      CATGeoFactory                *  iWhere                   ,
                                                        CATSoftwareConfiguration     *  iSoftwareConfiguration   ) ;
  virtual             ~CATExtruderByMatrix       () ;

  //-------------------------------------------------------------------------
  // Geometric extrusions
  //-------------------------------------------------------------------------
  virtual void         CreateTopSurfaces         (      CATLISTP(CATSurface)          & iProfileSurfaces         ,
                                                        CATLISTP(CATMacroPoint)       & iCenters                 ) ;

  //                                                                       // 05 03 09 FDS RI650024 , non prise en compte des points on surface
  virtual void         CreatePointOnSurface      (      CATExtrudedPoint             *  iInstance                ,
                                                        CATPointOnSurface            *  iProfile                 ,
                                                        CATMacroPoint                *  iCenterMacroPoint        ,
                                                        CATSurface                   *  iExtrudedSurface         ) ;

  virtual void         CreatePCurvesOnTop        (      CATLISTP(CATPCurve)           & iProfilePCurves          ,
                                                        CATLISTP(CATCrvLimits)        & iProfileLimits           ,
                                                                                     // iSupports: Produit croise Profile * Center ( Profile varie le plus vite )
                                                        CATLISTP(CATSurface)          & iSupports                ,
                                                        CATLISTP(CATMacroPoint)       & iCenters                 ) ;

  virtual void         CreateMeridianPCurves     (      CATEdgeCurve                 *  iProfile                 ,
                                                        CATCrvLimits                 *  iProfileLimits           ,
                                                        CATLISTP(CATPointOnEdgeCurve) & iCenters                 ,
                                                        CATSurface                   *  iSupport                 ) ;

  virtual void         SetResult                 (const int                             iProfileIndex            ,
                                                  const int                             iCenterIndex             ,
                                                        CATGeometry                  *  iResult                  );

  //-------------------------------------------------------------------------
  // Get geometric parameters of the extrusion as a transformation Matrix.
  //-------------------------------------------------------------------------
  virtual void         GetTransformation         (      CATPoint                     *  iCenter                  ,
                                                        CATMathTransformation         & oMove                    ) = 0 ;


  //-------------------------------------------------------------------------
  // General utility
  //-------------------------------------------------------------------------
  // Debug method: geometry cloning through CATCallCount, with trace,
  // for leak resolution on remaining geometric objects
  // - Use DebugCloneAndCount() for duplication, then remove old element
  // - MemoryCheck output file gives numbered stack 
  // - Find numbered stack and cloned element tag association in output file
  // - Usual follow tag tools (CATCGMFollowTag) may then 
  static  void         DebugCloneAndCount        (      CATGeoFactory                *  iFactory                 ,
                                                        CATGeometry                  *  iGeometry                ,
                                                        CATGeometry                  *& oGeometry                );


  //-------------------------------------------------------------------------
  // Internal utility
  //-------------------------------------------------------------------------
  private :

  CATTransfoManager  * GetTransfoManager         (      CATPoint                     *  iPoint                    ,
                                                        CATMathTransformation         & oMathTransfo              ) ;
  void                 AddCurveToDelete          (      CATCurve                     *  iCurve                    );
  void                 RemoveCurvesToDelete      ();
  //-------------------------------------------------------------------------
  // Data
  //-------------------------------------------------------------------------
  private :
  CATLISTP(CATPoint)          _DonePoints    ;
  CATLISTP(CATTransfoManager) _DoneTransfos  ;
  CATLISTP(CATCurve)          _CurvesToDelete;

};

#endif








