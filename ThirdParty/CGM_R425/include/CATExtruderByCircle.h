#ifndef CATExtruderByCircle_H
#define CATExtruderByCircle_H
// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CATExtruderByCircle: Utility for producing circular extrusion of Geometric entities.
//
// CATExtruderByCircleSubClass: sub class for circular extrusion outside extrusion engine
//
//=============================================================================
// Usage notes:
//
// - Geometric operator for CATRevol (using object instances)
// - Also used in Sweep              (through static methods)
//
//=============================================================================
//  June 98 RR  Creation                                              R. Rorato
// 19 07 02 ALV Ajout de _SoftwareConfiguration comme donnee membre.(pour versionning)
// 12 10 09 NLD Il faut ameliorer le protocole de CreateParallelSurface()
//              en recevant un argument iTwistDetectionIfPossible
//              et en rendant un argument oSurelyTwisted
// 28 10 10 FDS Perfo : add method to avoid to construct CATMathLine
// 02/12/14 NLD Detabulation
// 03/12/14 NLD Smart indent
//              Introduction de CATExtruderByCircleSubClass pour souplesse de maintenance
//              des fonctionnalites accessibles actuellement par methodes statiques
//              (switch d'activation par #define CATExtruderByCircleSubClassUseV1)
//              Phase 1: (avec switch d'activation par #define CATExtruderByCircleSubClassUseV1)
//              - CreateParallelCurve() et CreateParallelPCurve() recoivent la configuration
//              - CreateParallelSurface() recoit la configuration en argument 2 et non en dernier
//              - 1er  jeu de methodes dans CATExtruderByCircleSubClass: les methodes internes
//                GetParams()
//                ComputeCircle()
//                GetAngleFromPoint()
//                DistanceFromPtToAxisDir()
//                ProjectionPtToAxisDir()
//              - 2eme jeu de methodes dans CATExtruderByCircleSubClass: les methodes externes
//                (devant remplacer les methodes statiques de CATExtruderByCircle)
//                CreateParallelSurface()
//                CreateParallelCurve()
//                CreateParallelPCurve()
// 05/12/14 NLD Deflaggage CATExtruderByCircleSubClassUseV1 et CATExtruderByCircleSubClassUseV2
//              Export de CATExtruderByCircleSubClass
//              Suppression des methodes statiques          (phase 1: flaggage)
// 08/12/14 NLD Interversion des arguments du constructeur (configuration en 2eme argument)
// 22/12/14 NLD Suppression des methodes statiques          (phase 2: deflaggage: suppression definitive du code)
//-----------------------------------------------------------------------------
// xx/xx/xx NLD Migration des appelants sur CATExtruderByCircleSubClass
//              Suppression des methodes statiques
//              EN COURS
//=============================================================================

#include "Extrude.h"                                  // For Windows 
#include "CATExtruderByMatrix.h"                      // For inheritance

#include "CATCreateExtruder.h"

#include "CATListOfCATEdgeCurves.h"
#include "CATListOfCATPointOnEdgeCurves.h"
#include "CATListOfCATPoints.h"
#include "CATListOfCATCrvLimits.h"

#include "CATMathAxis.h"
#include "CATMathLine.h"
#include "CATMathDef.h"

#include "CATSoftwareConfiguration.h"

class CATMacroPoint ;
class CATPoint ;
class CATEdgeCurve ;
class CATCircle ;
class CATPCircle ;
class CATEdgeCurve ;
class CATCurve ;
class CATPlane ;
class CATSurface ;
class CATCrvLimits ;
class CATMathTransformation ;
class CATMathDirection ;
class CATMathPlane ;
class CATExtruderByCircleSubClass;

//-----------------------------------------------------------------------------
class ExportedByExtrude CATExtruderByCircle: public CATExtruderByMatrix
{
  public :

                      CATExtruderByCircle        (      CATGeoFactory                *  iFactory                 ,
                                                        CATSoftwareConfiguration     *  iSoftwareConfiguration   ,
                                                  const CATMathAxis                   & iRef                     );
  virtual            ~CATExtruderByCircle        () ;

  // virtual?         FilterExistingSurfaces     () non declaree virtual mais methode derivee de CATExtruder. NLD031214
          void        FilterExistingSurfaces     () ;

  // virtual?         ShareCenterGeometry        () non declaree virtual mais methode derivee de CATExtruder. NLD031214
          CATBoolean  ShareCenterGeometry        () const ; 

  //-------------------------------------------------------------------------
  // Create geometry
  //-------------------------------------------------------------------------
  virtual void        CreateParallelSurfaces     (      CATLISTP(CATEdgeCurve)        & iProfiles                ,
                                                        CATLISTP(CATCrvLimits)        & iProfileLimits           ,
                                                        CATLISTP(CATEdgeCurve)        & iCenters                 ,
                                                        CATLISTP(CATCrvLimits)        & iCenterLimits            ) ;

  virtual void        CreateParallelCurves       (      CATLISTP(CATPoint)            & iProfiles                ,
                                                        CATLISTP(CATEdgeCurve)        & iCenters                 ,
                                                        CATLISTP(CATCrvLimits)        & iCenterLimits            ) ;

  virtual void        CreateParallelPCurves      (      CATLISTP(CATPointOnEdgeCurve) & iProfiles                ,
                                                        CATEdgeCurve                 *  iCenter                  ,
                                                        CATCrvLimits                 *  iCenterLimits            ,
                                                        CATSurface                   *  iSupport                 ) ;

  //-------------------------------------------------------------------------
  // Orientation
  //-------------------------------------------------------------------------
  virtual void        GetDeriv                   (const CATSurface                   *  iSupport                 , 
                                                  const CATSurParam                   & iLocation                ,
                                                  const CATEdgeCurve                 *  iCenter                  ,
                                                        CATMathDirection              & oDirectionOfMove         ) ;

  //-------------------------------------------------------------------------
  // Get geometric parameters of the extrusion 
  //-------------------------------------------------------------------------
  private :

  virtual void        GetTransformation          (      CATPoint                     *  iCenter                  ,
                                                        CATMathTransformation         & oMove                    ) ;

  //-------------------------------------------------------------------------
  // Internal utility
  //-------------------------------------------------------------------------
  //-------------------------------------------------------------------------
  // Data
  //-------------------------------------------------------------------------
  private :

  CATMathAxis                  _Axis                     ;
  CATMathLine                  _AxisLine                 ;
  CATBoolean                   _ExistingSurfacesFiltered ;
  CATSoftwareConfiguration   * _SoftwareConfiguration    ;
  CATExtruderByCircleSubClass* _MySelfAsSubClass         ; // le deflaggage etant fait, pourrait etre renomme _SubClass
};


//-----------------------------------------------------------------------------
// CATExtruderByCircleSubClass: sub class for circular extrusion outside extrusion engine
//-----------------------------------------------------------------------------
class ExportedByExtrude CATExtruderByCircleSubClass
{
  friend class        CATExtruderByCircle;
  public :
                      CATExtruderByCircleSubClass(      CATGeoFactory                *  iFactory                 ,
                                                        CATSoftwareConfiguration     *  iSoftwareConfiguration   );

                     ~CATExtruderByCircleSubClass();


  //-------------------------------------------------------------------------
  // Methods replacing CATExtruderByCircle static methods
  //-------------------------------------------------------------------------
          CATSurface* CreateParallelSurface      (      CATEdgeCurve                 *  iProfile                 ,
                                                  const CATCrvLimits                  & iProfileLimits           ,
                                                  const CATMathAxis                   & iAxis                    ,
                                                  const CATAngle                        iStart                   ,
                                                  const CATAngle                        iEnd                     ,
                                                        int                             iTwistDetectionIfPossible,
                                                        int                           & oSurelyTwisted           ,
                                                        short                         & oRegular                 ,
                                                        short                         & oOrnVsProfile            ,
                                                        short                         & oOrnVsCenter             ,
                                                        short                         & oUVSwapped               );

          CATCircle*  CreateParallelCurve        (      CATPoint                     *  iProfile                 ,
                                                        CATMathAxis                   & iAxis                    ,
                                                        CATEdgeCurve                 *  iCenter                  ,
                                                        CATCrvLimits                  & iCenterLimits            ) ;

         CATPCircle*  CreateParallelPCurve       (      CATPointOnEdgeCurve          *  iProfile                 ,
                                                  const CATMathAxis                   & iAxis                    ,
                                                        CATEdgeCurve                 *  iCenter                  ,
                                                        CATCrvLimits                  & iCenterLimits            ,
                                                        CATSurface                   *  iSupport                 ,
                                                        short                         & oOrientation             ) ;

  //-------------------------------------------------------------------------
  // Other methods
  //-------------------------------------------------------------------------
  protected :
          void        GetParams                  (const CATMathAxis                   & iAxis                    ,
                                                  const CATCurve                     *  iCenter                  ,
                                                  const CATCrvLimits                  & iCenterLimits            ,
                                                        CATAngle                      & oStart                   ,
                                                        CATAngle                      & oEnd                     ) ;

  //-------------------------------------------------------------------------
  // Internal utility
  //-------------------------------------------------------------------------
          void        ComputeCircle              (const CATMathAxis                   & iAxis                    ,
                                                        CATPoint                     *  iProfile                 ,
                                                        CATCurve                     *  iCenter                  , 
                                                  const CATCrvLimits                  & iCenterLimits            ,
                                                        CATMathPlane                  & oPlane                   , 
                                                        CATPositiveLength             & oRadius                  , 
                                                        CATAngle                      & oStart                   , 
                                                        CATAngle                      & oEnd                     ) ;

          CATAngle    GetAngleFromPoint          (const CATMathAxis                   & iAxis                    ,
                                                  const CATMathPoint                  & iPoint                   ) ;

          double      DistanceFromPtToAxisDir    (const CATMathPoint                  & iPoint                   ,
                                                  const CATMathPoint                  & iAxisOrigin              ,
                                                  const CATMathVector                 & iAxisDir3                );

          void        ProjectionPtToAxisDir      (const CATMathPoint                  & iPointToProject          ,
                                                  const CATMathPoint                  & iAxisOrigin              ,
                                                  const CATMathVector                 & iAxisDir3                , 
                                                        CATMathPoint                  & oProjectedPoint          );

  protected :

  private   :
  CATGeoFactory              * _Factory                  ;
  CATSoftwareConfiguration   * _SoftwareConfiguration    ;


};

#endif








