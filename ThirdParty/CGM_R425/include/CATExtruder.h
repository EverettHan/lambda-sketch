// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CATExtruder:
// Base class for producing extrusion of Geometric entities.
//
//=============================================================================
// Usage notes:
//
// - Create such a class adapted to the type of extrude ( Tabulated, Revol or Sweep)
// - Create successively CATExtruder objects associated to this CATExtruder.
//=============================================================================

//=============================================================================
// HISTORIC
//
//  June 98 RR  Creation                                              R. Rorato
// 07 06 00 ALM __SortieDesLongueursDExtrapolation_070600 : on sort les longueurs
//              d'extrapolation estimees par GetDiscontinuityVertices, pour le 
//              nouveau code de calcul de skin de CATSweep
// 03 08 00 ALM Suppression de __SortieDesLongueursDExtrapolation_070600 et 
//              livraison de ComputeDiscontinuities qui gere le non manifold,
//              les extrapolations sur voisinage, et ne met pas a jour les 
//              CATCrvLimits dans la CCv apres extrapolation. Ce code est 
//              appelle par CATSweep, via un set au runtime :
//              set DEV__ALM_Sweep2.
// 03 08 00 ALM On rend Locate virtual pour la deriver dans CATExtruderBySweep,
//              pour mettre en place un traitement particulier lorsqu'il y a
//              eu un set DEV__ALM_Sweep2
// 11 12 00 ALM Nouvelle donnee pour le gerer le fait qu'on fait des SetCenterBody
//              a l'interieur d'un meme Run sur le meme CATExtruder : _NewCenters
// 20 02 01 ALM Suppression de DEV__ALM_Sweep2 au profit de la methode 
//              SetDiscontinuityTreatment qui specifie dans quel mode on travaille.
//              La variable mise a jour est _DiscontinuityTreatmentMode, elle
//              peut prendre les valeurs :
//              * 0 : mode par defaut = ancien mode = mode matriciel, 
//              * 1 : nouveau mode developpe dans CATSweep2.
// 05 03 01 ALM Ajout de oCuspVertices dans ComputeDiscontinuities.
// 19 03 01 ALM Mise en place de SetCuspTreatment()
// 21 03 01 ALM Ajout de CrvIndicesLists, CrvParamsLists, ParamsLists, 
//              et LimitTypesLists dans ComputeDiscontinuities.
// 19 07 02 ALV Ajout de _SoftwareConfiguration pour gestion du versionning 
//              + ajout de iSoftwareConfiguration dans le constructeur.
// 28 01 05 NLD Ajout de _TopologyCallBacks SetTopologyCallBacks()
// 24 10 07 NLD Ajout de SnapOnExistingSurfaceShunt()
// 05 03 09 FDS RI650024 , non prise en compte des points on surface
// 04 12 09 NLD Ajout AddToRemove()
// 31 03 10 NLD Ajout IsInstanceResultRemovable()
// 15 10 10 NLD Ajout CATExtruderGeometryList() pour preparation migration sur accès rapide
//              Dans CATExtruderGeometryList, passage de l'implementation par listes
//              à l'implementation par hashtable
// 22 10 10 NLD CATExtruderGeometryList est isolée dans un fichier dédié
//              pour facilité de génération de l'interface de CATExtruder
// 18 02 11 NLD Ajout GetCATExtruderC0MeridianCurveComputerDefaultOperatorId()
// 04 07 12 NLD Ajout GetCATExtruderC0PointComputerDefaultOperatorId()
// 11 10 13 ld2 AddMeridianPCurveLimit(), GetUnionOfMeridianPCurveLimit()
// 24 10 14 NLD Ajout de SnapOnExistingSurfaceDo()
// 27 10 14 NLD Ajout de RemoveGeometryToRemove()
//=============================================================================
#ifndef CATExtruder_H
#define CATExtruder_H

//=============================================================================
// DEBUG OPTIONS
//=============================================================================


//=============================================================================
// INCLUDES
//
#include "Extrude.h"
#include "CATListOfCATGeometries.h"
#include "CATListOfCATSurfaces.h"
#include "CATListOfCATCurves.h"
#include "CATListOfCATPCurves.h"
#include "CATListOfCATEdgeCurves.h"
#include "CATListOfCATPoints.h"
#include "CATListOfCATMacroPoints.h"
#include "CATListOfCATPointOnEdgeCurves.h"
#include "CATListOfCATCrvLimits.h"
#include "CATListOfInt.h"
#include "CATListOfCATPGMExtruded.h"
#include "CATListOfCATMathFunctionX.h"
#include "CATMathDef.h"
#include "CATIsoParameter.h"
#include "CATSoftwareConfiguration.h"

#include "CATListPV.h" 
#include "CATPGMExtruder.h"
#include "CATExtruderGeometryList.h"

//=============================================================================

//=============================================================================
// CLASSES
//
class CATGeoFactory ;
class CATGeometry ;
class CATMacroPoint ;
class CATPointOnEdgeCurve ;
class CATPointOnSurface;
class CATCrvParam ;
class CATSetOfCrvParams;
class CATCrvLimits ;
class CATEdgeCurve ;
class CATSurface ;
class CATPlane ;
class CATSurParam ;
class CATBody ;
class CATExtruded ;
class CATExtrudedInstance ;
class CATExtrudedPoint ;
class CATExtrudedCurve ;
class CATExtrudedSurface ;
class CATMapGeometry ;
class CATMathDirection ;
class CATMathFunctionX ;
class CATMathTransformation1D ;
class CATMathTransformation2D ;
class CATSetOfSurParams;
class CATTopologyCallBacks;
class CATHashTableCurveLimitsSet;
//=============================================================================

//#define CATExtruder_GeneralTraceActivation

//-----------------------------------------------------------------------------

class ExportedByExtrude CATExtruder  : public CATPGMExtruder
{
  public :

  //-------------------------------------------------------------------------
  // Constructor
  //-------------------------------------------------------------------------
                                      CATExtruder          (      CATGeoFactory                * iFactory                 ,
                                                                  CATSoftwareConfiguration     * iSoftwareConfiguration   );

  //-------------------------------------------------------------------------
  // Destructor
  //-------------------------------------------------------------------------
  virtual                            ~CATExtruder          ();

  //-------------------------------------------------------------------------
  // Requests the extrusion of a geometric object (Profile) 
  // by another geometric object (Center)
  // in the context of previous extrusions.
  //-------------------------------------------------------------------------
                CATPGMExtruded      * CreateExtruded            (      CATGeometry                  *  iProfile                , // MacroPoint, EdgeCurve or Surface
                                                                       CATCrvLimits                 *  iProfileLimits          , // if EdgeCurve 
                                                                       CATGeometry                  *  iCenter                 , // MacroPoint, EdgeCurve or Surface
                                                                       CATCrvLimits                 *  iCenterLimits           , // if EdgeCurve 
                                                                       CATLISTP(CATPGMExtruded)      & iLinkWith               ,
                                                                       CATLISTP(CATGeometry)         & iLinkWithGeom           ,
                                                                       CATListOfInt                  & iSigns                  ,
                                                                                                                          // Meaningfull for iCenter = CATPoint only
                                                                       CATExtruder::Continuity         iContinuity             = CATExtruder::C1) ;

  //-------------------------------------------------------------------------
  // Profile Curves management
  //-------------------------------------------------------------------------
  virtual       void                  SetProfileBody            (const CATBody                      *  iProfileBody            ) ;

  //-------------------------------------------------------------------------
  // Center Curves Orientation management
  //-------------------------------------------------------------------------
                void                  SetCenterCurves           (      CATLISTP(CATCurve)            & CenterCurves            ,
                                                                       CATListOfInt                  & CenterCurvesOrn         ) ;
                CATLONG32             GetCenterCurvesCount      () ;
                void                  GetCenterCurve            (const CATCurve                     *  iCenterCurve            ,
                                                                       CATLONG32                     & oCenterCurveIndex       ,  // in [0, CenterCurvesCount-1]
                                                                       short                         & oCenterCurveOrientation ) ;
  virtual       void                  SetCenterBody             (const CATBody                      *  iCenterBody             ) ;

  //-------------------------------------------------------------------------
  // Definition of optional topology call backs objects
  //-------------------------------------------------------------------------
                void                  SetTopologyCallBacks      (      CATTopologyCallBacks         *  iTopologyCallBacks      ) ;

  //-------------------------------------------------------------------------
  // Already existing surfaces.
  // This list defines which surfaces can be used rather than generated.
  // This list may be modified because it is filtered according to extrude type.
  //-------------------------------------------------------------------------
  virtual       void                  SetExistingSurfaces       (      CATLISTP(CATSurface)         *  ioSurfacesList          ) ;




  //=========================================================================
  // Management methods to be provided by child classes:
  //=========================================================================

  
  
  //-------------------------------------------------------------------------
  // Indicates whether several Lim on same geometry is supported.
  //-------------------------------------------------------------------------
  virtual       CATBoolean            ShareCenterGeometry       () const = 0 ; 

  //-------------------------------------------------------------------------
  // Indicates whether snap on existing surfaces is shunted
  //-------------------------------------------------------------------------
  virtual       int                   SnapOnExistingSurfaceShunt() ;
  
  //-------------------------------------------------------------------------
  // Remove from list the unnecessary surfaces.
  //-------------------------------------------------------------------------
  virtual       void                  FilterExistingSurfaces    () = 0 ;
  

  
  
  
  //=========================================================================
  // Creation methods to be provided by child classes:
  //=========================================================================

  //-------------------------------------------------------------------------
  // Create geometry
  //-------------------------------------------------------------------------
  virtual       void                  CreateParallelSurfaces    (      CATLISTP(CATEdgeCurve)        & iProfiles               ,
                                                                       CATLISTP(CATCrvLimits)        & iProfileLimits          ,
                                                                       CATLISTP(CATEdgeCurve)        & iCenters                ,
                                                                       CATLISTP(CATCrvLimits)        & iCenterLimits           ) = 0 ;

  virtual       void                  CreateTopSurfaces         (      CATLISTP(CATSurface)          & iProfileSurfaces        ,
                                                                       CATLISTP(CATMacroPoint)       & iCenters                ) = 0 ;

  virtual       void                  CreatePointOnSurface      (      CATExtrudedPoint             *  iInstance               ,
                                                                       CATPointOnSurface            *  iProfile                ,
                                                                       CATMacroPoint                *  iCenterMacroPoint       ,
 // 05 03 09 FDS RI650024 , non prise en compte des points on surface
                                                                       CATSurface                   *  iExtrudedSurface        ) ;

  virtual       void                  CreatePCurvesOnTop        (      CATLISTP(CATPCurve)           & iProfilePCurves         ,
                                                                       CATLISTP(CATCrvLimits)        & iProfileLimits          ,
                                                                       CATLISTP(CATSurface)          & iProfileSupports        ,
                                                                       CATLISTP(CATMacroPoint)       & iCenters                ) = 0 ;

  virtual       void                  CreateParallelCurves      (      CATLISTP(CATPoint)            & iProfiles               ,
                                                                       CATLISTP(CATEdgeCurve)        & iCenters                ,
                                                                       CATLISTP(CATCrvLimits)        & iCenterLimits           ) = 0 ;

 //-------------------------------------------------------------------------
  // The following methods have to be provided only whenever CreateParallelSurfaces 
  // may return Plane whose isopars are not parallel to Profile and Center
  // (SetParametrizationToNotRegular).
  //-------------------------------------------------------------------------
  virtual       void                  CreateParallelPCurves     (      CATLISTP(CATPointOnEdgeCurve) & iProfiles               ,
                                                                       CATEdgeCurve                 *  iCenter                 ,
                                                                       CATCrvLimits                 *  iCenterLimits           ,
                                                                       CATSurface                   *  iSupport                ) = 0 ;

  virtual       void                  CreateMeridianPCurves     (      CATEdgeCurve                 *  iProfile                ,
                                                                       CATCrvLimits                 *  iProfileLimits          ,
                                                                       CATLISTP(CATPointOnEdgeCurve) & iCenters                ,
                                                                       CATSurface                   *  iSupport                ) = 0 ;

  //-------------------------------------------------------------------------
  // Parametrization mapping to be provided by child classes whenever Surface
  // parametrization has been set to not linear and Mappings have not been provided.
  //-------------------------------------------------------------------------
  virtual       void                  GetEquivalentPoints       (const CATEdgeCurve                 *  iProfile                ,
                                                                 const CATEdgeCurve                 *  iCenter                 ,
                                                                 const CATSurface                   *  iProduct                ,
                                                                 const CATLONG32                       iParamsCount            ,
                                                                 const CATCrvParam                     iProfileParams    []    ,
                                                                 const CATCrvParam                     iCenterParams     []    ,
                                                                       CATSurParam                     oProductParams    []    ) ;
  
  //-------------------------------------------------------------------------
  // 15/02/99 Informations on discontinuity vertices for extrapolation
  // On rend la liste des Vertex presentant des discontinuites
  // ainsi que les listes (couplees par indice) des Edges a extrapoler
  // et des nouvelles limites des courbes sous-jacentes
  //-------------------------------------------------------------------------
  virtual       void                  GetDiscontinuityVerticesOnCenter
                                                                (      CATListPV                     & oDiscontinuityVertices  ,
                                                                       CATListPV                     & oEdgesToExtrapolate     ,
                                                                       CATLISTP(CATCrvLimits)        & oNewEdgesLimits         );

  virtual       void                  ComputeDiscontinuities    (      CATListPV                     & oNMVertices             ,
                                                                       CATListPV                     & oC0Vertices             ,
                                                                       CATListPV                     & oEdgesToExtrapolate     ,
                                                                       CATListOfDouble               & oExtrapolationLengthOnStart    ,
                                                                       CATListOfDouble               & oExtrapolationLengthOnEnd    ,
                                                                       CATListPV                     & oCuspVertices           ,
                                                                       CATListPV                     & oCrvIndicesLists        ,
                                                                       CATListPV                     & oCrvParamsLists         ,
                                                                       CATListPV                     & oParamsLists            ,
                                                                       CATListPV                     & oLimitTypesLists        );

  //-------------------------------------------------------------------------
  // Result geometry management
  //-------------------------------------------------------------------------
  // Indicates whether the geometric result of the instance is to be removed
  // at instance destruction
  // returns 1 if result to be removed, else returns 0
  // Default implementation returns 0
  // Specific behaviour for null element: gives the general mode for this extruder,
  // indicating whether some elements can be removable, or not
  virtual       int                   IsInstanceResultRemovable (      CATGeometry                  *  iResult                 );

  //-------------------------------------------------------------------------
  // Mandatory method to be provided in order to orient volumic results.
  //-------------------------------------------------------------------------
  virtual       void                  GetDeriv                  (const CATSurface                   *  iSupport                ,
                                                                 const CATSurParam                   & iLocation               ,
                                                                 const CATEdgeCurve                 *  iCenter                 ,
                                                                       CATMathDirection              & oDirectionOfMove        ) = 0 ;

  //=========================================================================
  // Methods for child classes
  //=========================================================================
  // Default parametrization is Regular, Not Linear.
  // If Regular, Surface Limits must fit to profile and center provided limits.
  // If Linear, default parametrization is:
  //--------------------------------------
  // Profile along U, Center along V.
  // Profile orientation: U increases.
  // Center orientation: V increases.
  // Profile and Center parametrization are both linear vs Surface.
  //-------------------------------------------------------------------------
                void                  SetResult                 (const int                             iProfileIndex           ,
                                                                 const int                             iCenterIndex            ,
                                                                       CATGeometry                  *  iResult                 ) ;

  // Use either one of these is default does not apply:

  // For ParallelSurfaces only 
                void                  SetParametrizationToNotRegular
                                                                (const int                             iProfileIndex           ,
                                                                 const int                             iCenterIndex            ) ;

  // For ParallelSurfaces only :
                void                  SetParametrizationToLinear(const int                             iProfileIndex           ,
                                                                 const int                             iCenterIndex            ,
                                                                 const int                             iOrnVsProfile           = 1, 
                                                                 const int                             iOrnVsCenter            = 1,
                                                                 const CATBoolean                      iUVSwapped              = 0) ; 

  // For ParallelSurface only (NB: CATMathTransformation2D & CATMathFunctionX will be deleted automatically)
  // iLinearities defines which side have linear parametrization with regards to Profile and/or Center curves.
  // Samples:
  // Linear in both directions: SetParametrization(i,j,CATIsoParBothDir,TUV) ; 
  // Not Linear in both directions: SetParametrization(i,j,CATIsoParNoDir,TUV,ProfileMap, CenterMap) ; (recommended)
  // Not Linear in both directions: SetParametrization(i,j,CATIsoParNoDir,NULL,NULL,NULL) ; 
  // Linear along Center (V) direction and Map provided: SetParametrization(i,j,CATIsoParamU,TUV,ProfileMap,NULL) ; 
  // Linear along Center (V) direction: SetParametrization(i,j,CATIsoParamU,TUV,NULL,NULL) ; 
                void                  SetParametrization        (const int                             iProfileIndex           ,
                                                                 const int                             iCenterIndex            ,
                                                                 const CATIsoParameter                 iLinearities            ,
                                                                       CATMathTransformation2D      *  iFromProfileCenterToUV  ,
                                                                       CATMathFunctionX             *  iFromProfileToIsopar    ,
                                                                       CATMathFunctionX             *  iFromCenterToIsopar     ) ;

  // For TopSurface & ParallelSurface with Not Regular parametrization only
                void                  SetOrientationToChanged   (const int                             iProfileIndex           ,
                                                                 const int                             iCenterIndex            ) ;

  // For PCurveOnTop & PCurve on ParallelSurface & Parallel Curve.
  // NB: CATMathTransformation1D will be deleted automatically.
  // NB: if (iFromInputToResult==NULL) Transformation is computed according to limits.
                void                  SetParametrization        (const int                             iProfileIndex           ,
                                                                 const int                             iCenterIndex            ,
                                                                       CATMathTransformation1D      *  iFromInputToResult      ) ;
  
  // Specify the discontinuity treatment mode.
  // It should only be called by CATFrFTopologicalSweep
                void                  SetDiscontinuityTreatment (      CATLONG32                       iMode                   = 0);

  // Specify the cusp treatment mode.
  // It should only be called by CATFrFTopologicalSweep
                void                  SetCuspTreatment          (      CATLONG32                       iMode                   = 0);



  //=========================================================================
  // Internal usage methods
  //=========================================================================
  
  //-------------------------------------------------------------------------
  // Instance Types
  //-------------------------------------------------------------------------
  enum InstanceType { // Surfaces:
                      ParallelSurface,
                      TopSurface     ,
                      // Curves:
                      ParallelPCurve ,
                      MeridianPCurve ,
                      PCurveOnTop    ,
                      ParallelCurve  ,
                      // Points:
                      PoecOnParallel ,
                      PoecOnMeridian ,
                      PointOnSurfaceOnMeridian
                     } ;

  
  //-------------------------------------------------------------------------
  // Instances Management
  //-------------------------------------------------------------------------
                void                    Subscribe               (      CATExtrudedInstance          *  iInstance               ) ;
                void                  UnSubscribe               (      CATExtrudedInstance          *  iInstance               ) ;
                CATExtrudedInstance * GetRefInstance            (const CATExtrudedInstance          *  iInstance               ) const ;
                void                  UpdateSize                () ;

  //-------------------------------------------------------------------------
  // Extruded Management
  //-------------------------------------------------------------------------
  virtual       CATPGMExtruded      * Locate                    (      CATGeometry                  *  iProfile                ,
                                                                       CATGeometry                  *  iCenter                 ) ;
                void                  Append                    (      CATGeometry                  *  iProfile                ,
                                                                       CATGeometry                  *  iCenter                 ,
                                                                       CATPGMExtruded               *  iExtruded               ) ;

  //-------------------------------------------------------------------------
  // Geometric Instances Creation
  //-------------------------------------------------------------------------
                void                  CreatePLine               (      CATExtrudedCurve             *  iInstance               ,
                                                                       CATSurParam                   & iStart                  ,
                                                                       CATSurParam                   & iEnd                    ,
                                                                       CATSurface                   *  iSurface                ) ;

                void                  CreatePoec                (      CATExtrudedPoint             *  iInstance               ,
                                                                       CATCurve                     *  iCurve                  ,
                                                                 const CATCrvParam                   & iParamOnCurve           ,
                                                                       CATEdgeCurve                 *  iEdgeCurve              ) ;

                CATMacroPoint       * CreateMacroPoint          (      CATLISTP(CATPoint)            & iPoints                 ) ;

                CATEdgeCurve        * CreateEdgeCurve           (      CATLISTP(CATCurve)            & iCurves                 ,
                                                                       CATLISTP(CATCrvLimits)        & iLimits                 ,
                                                                       CATListOfInt                  & iOrns                   ) ;

                CATEdgeCurve        * CreateEdgeCurve           (      CATLISTP(CATCurve)            & iCurves                 ,
                                                                       CATLISTP(CATCrvLimits)        & iLimits                 ,
                                                                       CATListOfInt                  & iOrns                   ,
                                                                       CATLISTP(CATMathFunctionX)    & iMaps                   ) ;

                void                  CreateC0Point             (      CATEdgeCurve                 *  iC1                     ,
                                                                       int                             iOri1                   ,
                                                                       CATEdgeCurve                 *  iC2                     ,
                                                                       int                             iOri2                   ,
                                                                       CATExtrudedPoint             *  C0ParallelInstances1    ,
                                                                       CATExtrudedPoint             *  C0ParallelInstances2    ) ;
 
                void                  CreateC0MeridianCurve     (      CATSurface                   *  iSurfaces            [2],
                                                                 const CATLONG32                       iNbInit                 ,
                                                                       CATSetOfSurParams             & iInitPt1                ,
                                                                       CATSetOfSurParams             & iInitPt2                ,
                                                                       int                          *  iInitSigns              ,
                                                                       CATEdgeCurve                 *& oEdgeCurve              ,
                                                                       CATPCurve                    *  oPCurves             [2],
                                                                       CATPointOnEdgeCurve         **  oPoecs                  ,
                                                                       CATSetOfCrvParams            *& oCuttingParams          );

                CATGeometry         * GetResult                 (      CATExtrudedInstance          *  iInstance               );

  // Adds geometry to remove at end of all operations
                void                  AddToRemove               (      CATGeometry                  *  iGeometryToRemove       ) ;

  /** @nodoc @nocgmitf
  * Adds association EC/PC --> limits on PCurve
  */
                void                  AddMeridianPCurveLimit    (      CATEdgeCurve                 *  iEC                     ,
                                                                       CATPCurve                    *  iPC                     ,
                                                                 const CATCrvLimits                  & iLimit                  );

  /** @nodoc @nocgmitf
  * Retrieve the union of all limits of PCurve iPC used to define a POEC on edge curve iEC
  */
                CATCrvLimits        * GetUnionOfMeridianPCurveLimit(   CATEdgeCurve                 *  iEC                     ,
                                                                       CATPCurve                    *  iPC                     );

  //-------------------------------------------------------------------------
  // Internal utilities
  //-------------------------------------------------------------------------
  private :

  // Snap sur une surface existante: tentative
                CATBoolean            SnapOnExistingSurface     (      CATExtrudedSurface           *  iInstance               ,
                                                                       CATMathTransformation2D       & oTUV                    ) ;

  // Snap sur une surface existante: snap effectif
                void                  SnapOnExistingSurfaceDo   (      CATExtrudedSurface           *  iInstance               ,
                                                                       CATSurface                   *  iExistingSurface        ) ;


  // Effacement des elements de _ToRemove
                void                  RemoveGeometryToRemove    ();

  //=========================================================================
  // Data
  //=========================================================================
  private :

  #define CATExtruder_ListPOfCATCurve   CATLISTP(CATCurve)
  #define CATExtruder_ListPOfCATSurface CATLISTP(CATSurface)

  CATExtruder_ListPOfCATCurve      _CenterCurves     ; // On ne fait que vehiculer ces donnees
  CATListOfInt                     _CenterCurvesOrn  ; //   "            "            "


//
  CATExtruderGeometryList          _Profiles         ; // Les geometries profil a extruder
  CATExtruderGeometryList          _Centers          ; // Les geometries centre a extruder
  CATExtruderGeometryList          _NewCenters       ; // Nouvelle donnee d extrusion, pour decrire la courbe centre,
                                                       // vue en tant qu'element de travail, dans sa partie C1 ou non
  CATExtruderGeometryList          _ToRemove         ; // Surfaces "snappees" a enlever

  CATExtrudedInstance           ** _Instances        ; // _Instances[iCenter][iProfile]
  CATMapGeometry                 * _Log              ; // Log des CATExtruded
  int                              _PCount           ;
  int                              _CCount           ;
  int                              _PSize            ;
  int                              _CSize            ;
  
  InstanceType                     _Type             ; // Le traitement courant 
  CATListOfInt                     _IPs              ;
  CATListOfInt                     _ICs              ;

  CATHashTableCurveLimitsSet     * _MeridianPCurveLimit;


  protected :

  CATGeoFactory                  * _Factory          ; // Container dans lequel il faut creer les objets
  CATExtruder_ListPOfCATSurface  * _ExistingSurfaces ; // Une liste des surfaces existantes dans laquelle piocher
  CATLONG32                        _DiscontinuityTreatmentMode;
  CATLONG32                        _CuspTreatmentMode;
  CATSoftwareConfiguration       * _SoftwareConfiguration; //Versionning
  CATTopologyCallBacks           * _TopologyCallBacks;

};
//=============================================================================
// identificateur de l'operateur CATExtruderC0MeridianCurveComputer (pour gestion CGMReplay)
//NLD021020 non necessaire ici extern "C"
ExportedByExtrude CATString *GetCATExtruderC0MeridianCurveComputerDefaultOperatorId();

//=============================================================================
// identificateur de l'operateur CATExtruderC0PointComputer         (pour gestion CGMReplay)
//NLD021020 non necessaire ici extern "C"
ExportedByExtrude CATString *GetCATExtruderC0PointComputerDefaultOperatorId();

#endif








