#ifndef CATExtruderByLine_H
#define CATExtruderByLine_H
// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CATExtruderByLine: Utility for producing Linear extrusion of Geometric entities.
//
// CATExtruderByLineSubClass: sub class for linear extrusion outside extrusion engine
//
//=============================================================================
// Usage notes:
//
// - Geometric operator for CATPrism (using object instances)
// - Also used in Sweep              (through static methods)
//
//=============================================================================
// June  98 RR  Creation                                              R. Rorato
// 19 07 02 ALV Ajout de _SoftwareConfiguration comme donnee menbre.(pour versionning)
// 07 11 12 G5S Added argument iToSimplify to function CreateParallelSurface so we can decide to
//              generate a non-canonical surface instead of a canonical one. This is useful for the
//              Remove First Volume project.
//              (renamed iGenerateCanonic by NLD 04/12/14)
// 03/12/14 NLD Detabulation
//              Smart indent
//              CreateParallelCurve() recoit la configuration
// 04/12/14 NLD Ajout CATExtruderByLineSubClass pour acces par instance d'objet
//              aux methodes anciennement statiques
//                CreateParallelSurface()
//                CreateParallelCurve()
//                CreateParallelPCurve()
//              (switch d'activation par #define CATExtruderByLineSubClassUse)
//              L'argument iToSimplify de CreateParallelSurface() est renomme iGenerateCanonic
// 05/12/14 NLD Deflaggage CATExtruderByLineSubClassUse. Suppression ancien code avant CATExtruderByLineSubClass
//              Export de CATExtruderByLineSubClass
//              Suppression des methodes statiques CreateParallelCurve() et CreateParallelPCurve() (phase 1: flaggage)
// 08/12/14 NLD Suppression de la methode statique CreateParallelSurface()                         (phase 1: flaggage)
//              Interversion des arguments du constructeur (configuration en 2eme argument)
// 22/12/14 NLD Suppression des methodes statiques CreateParallelCurve() et CreateParallelPCurve() (phase 2: deflaggage et suppression definitive)
//              Suppression de la methode statique CreateParallelSurface()                         (phase 2: deflaggage et suppression definitive)
//=============================================================================

#include "Extrude.h"                                  // For Windows 
#include "CATExtruderByMatrix.h"                      // For inheritance

#include "CATCreateExtruder.h"

#include "CATListOfCATEdgeCurves.h"
#include "CATListOfCATPointOnEdgeCurves.h"
#include "CATListOfCATPoints.h"
#include "CATListOfCATCrvLimits.h"
#include "CATMathPoint.h"
#include "CATMathDef.h"
#include "CATSoftwareConfiguration.h"

class CATMacroPoint ;
class CATEdgeCurve ;
class CATPlane ;
class CATSurface ;
class CATPLine ;
class CATLine ;
class CATCrvLimits ;
class CATMathTransformation ;
class CATMathDirection ;
class CATExtruderByLineSubClass;
//-----------------------------------------------------------------------------
class ExportedByExtrude CATExtruderByLine: public CATExtruderByMatrix
{
  public :

  //-------------------------------------------------------------------------
  // Linear extruder
  //-------------------------------------------------------------------------
                      CATExtruderByLine          (      CATGeoFactory                 *  iFactory                 ,
                                                        CATSoftwareConfiguration      *  iSoftwareConfiguration   ,
                                                  const CATMathPoint                   & iRef                     );
  virtual            ~CATExtruderByLine          () ;

  // virtual?         FilterExistingSurfaces     () non declaree virtual mais methode derivee de CATExtruder. NLD031214
          void        FilterExistingSurfaces     () ;

  // virtual?         ShareCenterGeometry        () non declaree virtual mais methode derivee de CATExtruder. NLD031214
          CATBoolean  ShareCenterGeometry        () const ; 

  //-------------------------------------------------------------------------
  // Create geometry
  //-------------------------------------------------------------------------
  virtual void        CreateParallelSurfaces     (      CATLISTP(CATEdgeCurve)         & iProfiles                ,
                                                        CATLISTP(CATCrvLimits)         & iProfileLimits           ,
                                                        CATLISTP(CATEdgeCurve)         & iCenters                 ,
                                                        CATLISTP(CATCrvLimits)         & iCenterLimits            );

  virtual void        CreateParallelCurves       (      CATLISTP(CATPoint)             & iProfiles                ,
                                                        CATLISTP(CATEdgeCurve)         & iCenters                 ,
                                                        CATLISTP(CATCrvLimits)         & iCenterLimits            ) ;

  virtual void        CreateParallelPCurves      (      CATLISTP(CATPointOnEdgeCurve)  & iProfiles                ,
                                                        CATEdgeCurve                  *  iCenter                  ,
                                                        CATCrvLimits                  *  iCenterLimits            ,
                                                        CATSurface                    *  iSupport                 ) ;

  //-------------------------------------------------------------------------
  // Orientation
  //-------------------------------------------------------------------------
  virtual void        GetDeriv                   (const CATSurface                    *  iSupport                 ,
                                                  const CATSurParam                    & iLocation                ,
                                                  const CATEdgeCurve                  *  iCenter                  ,
                                                        CATMathDirection               & oDirectionOfMove         ) ;

  //-------------------------------------------------------------------------
  // Get geometric parameters of the extrusion 
  //-------------------------------------------------------------------------
  private :

  virtual void        GetTransformation          (      CATPoint                      *  iCenter                  ,
                                                        CATMathTransformation          & oMove                    ) ;

          void        GetParams                  (const CATEdgeCurve                  *  iCenter                  ,
                                                  const CATCrvLimits                   & iCenterLimits            ,
                                                        CATMathDirection               & oExtrudeDirection        ,
                                                        CATLength                      & oStart                   ,
                                                        CATLength                      & oEnd                     ) ;

          void        GetParams                  (      CATPointOnEdgeCurve           *  iCenter                  ,
                                                        CATMathVector                  & oOffset                  ) ;

  //-------------------------------------------------------------------------
  // Data
  //-------------------------------------------------------------------------
  private :

  CATExtruderByLineSubClass  * _MySelfAsSubClass         ;

  CATMathPoint                 _Reference                ;
  CATBoolean                   _ExistingSurfacesFiltered ;
  CATSoftwareConfiguration   * _SoftwareConfiguration    ; // Versionning 

};


//-----------------------------------------------------------------------------
// CATExtruderByLineSubClass: sub class for linear extrusion outside extrusion engine
//-----------------------------------------------------------------------------
class ExportedByExtrude CATExtruderByLineSubClass
{
  friend class        CATExtruderByLine;
  public :
                      CATExtruderByLineSubClass  (      CATGeoFactory                *  iFactory                 ,
                                                        CATSoftwareConfiguration     *  iSoftwareConfiguration   );

                     ~CATExtruderByLineSubClass  ();


  //-------------------------------------------------------------------------
  // Methods replacing CATExtruderByLine static methods
  //-------------------------------------------------------------------------

          // Parallel surface creation
          // -------------------------
          //     iGenerateCanonic must be set to TRUE in order to obtain default and recommended behaviour
          //     with canonical surfaces generation if possible (planes, cylinders)

          // N.B par rapport a la methode statique de CATExtruderByLine, il y a reordonnancement des arguments
          //     iGenerateCanonic (anciennement iToSimplify) est remonte avec les arguments d'entree.         NLD041214

  // USED   outside CATExtruderByLine   (by CATExtrudedSweepSurfaceByLine)                                    NLD031214
  //                                    (by CATHybFilletUtilities)
  //                                    (by CATSweepRelimit3)                                                 NLD031214

          CATSurface * CreateParallelSurface     (
                                                        CATEdgeCurve                 *  iProfile                 ,
                                                  const CATCrvLimits                  & iProfileLimits           ,
                                                  const CATMathDirection              & iExtrudeDirection        ,
                                                  const CATLength                       iStart                   ,
                                                  const CATLength                       iEnd                     ,
                                                  const CATBoolean                      iGenerateCanonic         ,
                                                        short                         & oRegular                 ,
                                                        short                         & oOrnVsProfile            ,
                                                        short                         & oOrnVsCenter             ,
                                                        short                         & oUVSwapped
                                                 ) ;

          // Parallel pCurve creation
          // ------------------------
  // USED   outside CATExtruderByLine   (by CATExtrudedSweepSurfaceByLine)                                    NLD031214
          CATPLine   * CreateParallelPCurve      (      CATPointOnEdgeCurve          *  iProfile                 ,
                                                  const CATMathDirection              & iExtrudeDirection        ,
                                                  const CATLength                       iStart                   ,
                                                  const CATLength                       iEnd                     ,
                                                        CATSurface                   *  iSupport                 ) ;

          // Parallel curve creation
          // -----------------------
  // not used outside CATExtruderByLine                                                                       NLD031214
          CATLine    * CreateParallelCurve       (      CATPoint                     *  iProfile                 ,
                                                  const CATMathDirection              & iExtrudeDirection        ,
                                                  const CATLength                       iStart                   ,
                                                  const CATLength                       iEnd                     ) ;

  //-------------------------------------------------------------------------
  // Other methods
  //-------------------------------------------------------------------------
  protected :

  //-------------------------------------------------------------------------
  // Data
  //-------------------------------------------------------------------------
  protected :

  private   :
  CATGeoFactory              * _Factory                  ;
  CATSoftwareConfiguration   * _SoftwareConfiguration    ;


};

#endif








