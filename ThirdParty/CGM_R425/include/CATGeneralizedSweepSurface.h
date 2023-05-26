// COPYRIGHT DASSAULT SYSTEMES 1997
//==========================================================================
//
// CATGeneralizedSweepSurface:
// Interface class of the SWEEP Operator.
//
//==========================================================================
//
// Usage notes:
// This class can be used as is for simple Generalized Sweep or derived
// in order to implement specific algorithm or capabilities.
//
//==========================================================================
// March 98 CPL Creation                                            Pradalou
// July  99 CPL Add GetSweepChecker
// 16 11 99 CPL Add ViewingDirection
// 25 01 00 CPL Add GetAllProfiles
// 26 06 01 CPL SetSmoothOption
// 03 01 01 CCK Ajout de SetSoftwareConfiguration
// 07 03 02 JSX - ajout methode SetResultTolerance(double iTolerance)
// 10 12 02 JSX Methodes GetAggregatedObject et Create en protected 
//              Rearchitecture du "Polymorphisme"
//              Les methodes communes ne sont ne sont plus virtuelles pures 
// 16 01 03 NDN Ajout de la methode SetProfileApproxTolerance
// 18 03 02 CCK Ajout des methodes SetUnTwistMode, GetInfoUnTwist, SetWrapMode
// 19 03 02 NLD que l'on met en virtual!
// 13 06 03 NDN SetExtrapolatedConnexions()
// 05 09 03 JSX Ajout GetNonC2Parameters()
// 26 08 03 MNA SetCleanOption :Info Necessaire pour le SweepChecker ()
// 29 10 03 NLD polymorphisme, suite. Ajout de GetDerivedObject()
// 08 01 04 NLD Ajout SetCanonicSurfacesDetection
// XX 03 04 JSX SetSplitMode(), GetSplitedSurfaces(), SetSplitedSurfaces()
// 11 01 05 NLD Ajout SetFrFTopologyCallBacks()
// 15 02 05 JSX Implementation pour Factorisation du Run
//              Implementation pour Factorisation du SetFrFTopologyCallBacks
// 18 10 06 NLD Ajout SetTopoImposedParameters()
// 26 10 06 NLD Ajout ForceMultipleViewingDirMode()
// 22 06 07 NLD Ajout de SetApproxType()
// 05 11 10 NLD Ajout de SetProgressBar()
// 22 03 11 NLD Ajout de GetCATSweepCanonicSurfaceDetectorDefaultOperatorId()
// 14 11 14 NLD Definition des identificateurs CATGeneralizedSweepSurfaceSmoothOption*
// 17 11 14 NLD Smart indent
// 16 06 22 JSX herite de CATFrFObject
//==========================================================================

#ifndef CATGeneralizedSweepSurface_H
#define CATGeneralizedSweepSurface_H

#include <FrFAdvancedOpeSur.h>
#include <CATMathDef.h>
#include <CATSweepClassId.h>
#include <CATCGMVirtual.h>
#include <CATListOfDouble.h>
#include <CATListOfInt.h>

#include <CreateGeneralizedSweepSurface.h>

class CATSweepSurface;
class CATExtrudedSweepSurface;
class CATCurve;
class CATGeoFactory;
class CATMathTransformation;
class CATMathAxis;
class CATFrFCompositeCurve;
class CATFrFProfile;
class CATFrFMovingFrame;
class CATFrFGeneralizedProfile;
class CATFrFTopologyCallBacks ;
class CATFrFSweepChecker;
class CATMathPoint;
class CATMathDirection;
class CATFrFCCvParam;
class CATSoftwareConfiguration;
class CATError;
class CATCGMProgressBar;
//class CATSurface;
#include <CATListOfCATSurfaces.h>

#include "CATFrFObject.h"
//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedOpeSur CATGeneralizedSweepSurface : public CATFrFObject//CATCGMVirtual
{
  public :

    virtual                      ~CATGeneralizedSweepSurface();

    //--------------------
    // Information methods
    //--------------------

    virtual       CATSweepClassId           IsA                        ()                                                               const = 0;
    virtual       CATBoolean                IsAKindOf                  (const CATSweepClassId            iClassId                     ) const;


    //--------------------
    // Set methods
    //--------------------
    // Versionning
    virtual       void                      SetSoftwareConfiguration   (      CATSoftwareConfiguration*  Config                       );

    virtual       void                      SetPlanesDetection         (      CATBoolean                 iOK                          );

    virtual       void                      SetCanonicSurfacesDetection(      CATBoolean                 iOK                          );

    virtual       void                      SetTwistDetection          (      CATBoolean                 iOK                          );

    // To get a G1 normal comb everywhere the underlying curve is G1.
    // iOption =0 => No Smooth
    //         =1 => All Smooths are activate (MovingFrame & Normal)
    //         =2 => Only Smooth of normals are activated. Spine is not changed. (G1 Extrapolation)
    //                                                          // Definition des identificateurs. NLD141114
    #define CATGeneralizedSweepSurfaceSmoothOptionInactive   0
    #define CATGeneralizedSweepSurfaceSmoothOptionStandard   1
    #define CATGeneralizedSweepSurfaceSmoothOptionNormalOnly 2

    virtual       void                      SetSmoothOption            (      CATLONG32                  iOption                      );
    virtual       void                      SetSmoothAngleThreshold    (      double                     iAngle                       );

    // N.B Cette methode permet de donner une information sur les cleans faits en amont,
    // destinée au SweepChecker, mais ne declenche pas de traitement de nettoyage
    virtual       void                      SetCleanOption             (      int                        iCleanOption                 ,
                                                                              double                     iCleanTolDeformationOnGuide  ,
                                                                              double                     iCleanTolDeformationOnProfile);

    // Precision of SweepSurface
    virtual       void                      SetResultTolerance         (      double                     iTolerance                   );

    // To set the tolerance used to approximate profiles (used only if there is
    // explicit profiles. Defaut value is Factory resolution).
    virtual       void                      SetProfileApproxTolerance  (      double                     iTolerance                   );

    // To obtain Canonic Results
    // iCanonicMode=1 : Canonic Mode (by default)
    // else iCanonicMode= 0
    virtual       void                      SetCanonicMode             (      CATLONG32                  iCanonicMode                 ) ;

    // To impose parameters for marching
    virtual       void                      SetTopoImposedParameters   (      CATListOfDouble          & iTopoImposedParameters       ) ;

    // Proto
                  void                      SetApproxType              (      CATLONG32                  iApproxType                  ) ;

    //---------
    // Operator
    //---------

    virtual       void                      Run                        ();

    //-----------------
    // Used by Topology
    //-----------------

    // Calculation of one Section at the iT param
    virtual       CATLONG32                 GetNumberOfAllProfiles     ();

    virtual       CATCurve**                GetAllProfiles             (      double                     iT                           ,
                                                                              CATGeoFactory           *  iFactory                     );

    virtual       CATCurve**                GetAllProfiles             (const CATFrFCCvParam           & iParamOnSpine                ,
                                                                              CATGeoFactory           *  iFactory                     );

    // transformation between the Profile axis & the local axis(iT)
    virtual       CATBoolean                GetTransformation          (      double                     iT                           ,
                                                                              CATMathTransformation    & oTransfo                     );
    virtual       CATBoolean                GetTransformation          (      double                     iT                           ,
                                                                              CATMathTransformation    & oTransfo                     ,
                                                                              CATMathPoint            *  iInitPt                      );

    virtual       void                      GetLocalFrame              (      double                     iT                           ,
                                                                              CATMathAxis              & oAxis                        ,
                                                                              double                  *  idAxis                       = 0,
                                                                              double                  *  id2Axis                      = 0);
    virtual       void                      GetLocalFrame              (const CATFrFCCvParam           & iParamOnSpine                ,
                                                                              CATMathAxis              & oAxis                        );

    virtual       void                      SetProfilePosition         (      CATMathAxis             *  iProfileAxis                 );
    // Topological callbacks
    virtual       void                      SetFrFTopologyCallBacks    (      CATFrFTopologyCallBacks *  iFrFTopologyCallBacks        );
    // Progress bar
    virtual       void                      SetProgressBar             (      CATCGMProgressBar       *  iProgressBar                 );

    // Moving Frame:
    //-------------
    // Z: tgt guide
    // Y: ViewingDirection
    virtual const CATMathDirection        * GetViewingDirection        () = 0;
    virtual       void                      SetViewingDirection        (const CATMathDirection         & iViewingDirection            ) = 0;
    virtual       void                      ForceMultipleViewingDirMode();


    virtual       CATFrFCompositeCurve    * GetMasterGuide             () const = 0;
    virtual       void                      SetMasterGuide             (      CATFrFCompositeCurve    *  iGuide                       ) = 0;
    // Indique quelles sont les connexions ayant fait l'objet
    // d'une extrapolation.
    // Si la master guide contient n courbes, les connexions sont numerotees
    // de 1 (entre courbes 1 et 2) a (n-1),
    // ou n (entre n et 1) dans le cas d'une master guide fermee 
    virtual       void                      SetExtrapolatedConnexions  (      CATListOfInt            *  iListExtrapolatedConnexions  );

    // Profile is a CATFrFImplicitProfile or a CATFrFProfile
    virtual       CATFrFGeneralizedProfile* GetGeneralizedProfile      ();

    // Do not use
    virtual       CATFrFProfile           * GetMasterProfile           ();
    virtual       void                      SetMasterProfile           (      CATFrFCompositeCurve    *  iProfile                     ) = 0;

    virtual       void                      SetMovingFrame             (      CATFrFMovingFrame       *  iMF                          ) = 0;
    virtual       CATFrFMovingFrame       * GetMovingFrame             ()                                                               = 0;

    //-------------
    // Sweep Result
    //-------------

    virtual       CATLONG32                 GetNumberOfSweeps          ();
    virtual       void                      BeginningSweep             ();
    virtual       CATBoolean                NextSweep                  ();

    // Get for each sweep the number of cross surfaces
    virtual       CATLONG32                 GetNumberOfSurfaces        () ;
    virtual       CATSweepSurface        ** GetSurfaces                ()    const;

    // Extract Sweep surface and Free Memory
    virtual       CATSweepSurface        ** ExtractSurfaces            () ;

    //---------------------
    // Extruded Sweep Result: MultiShape or Canonic Mode
    //---------------------

    virtual       CATLONG32                 GetNumberOfExtrudedSweeps  ();
    virtual       void                      BeginningExtrudedSweep     ();
    virtual       CATBoolean                NextExtrudedSweep          ();

    // Get for each sweep the number of cross surfaces
    virtual       CATLONG32                 GetNumberOfExtrudedSurfaces();
    virtual       CATExtrudedSweepSurface** GetExtrudedSurfaces        () const;

    //---------------------
    // Check Result 
    //---------------------
    // Run() must be done !!!
    // You have to delete the checker after use.
    // but if CanonicSurfaces: return NULL
    virtual       CATFrFSweepChecker      * GetSweepChecker            ()                                                               = 0;

    // iUnTwistMode = 0 : on n'est pas dans le mode UnTwist
    //                1 : on est dans le mode UnTwist
    virtual       void                      SetUnTwistMode             (      CATLONG32                  iUnTwistMode                 );

    virtual       void                      GetInfoUnTwist             (      CATListOfDouble          & ioTwistInitParamMF           ,
                                                                              CATListOfDouble          & ioTwistEndParamMF            ,
                                                                              CATListOfDouble          & ioTwistInitParamOnShape      ,
                                                                              CATListOfDouble          & ioTwistEndParamOnShape       );

    // iWrapMode = 0 : on n'est pas dans le mode de rebroussement
    //             1 : on est dans le mode de rebroussement (=> calcul des distances de recul)
    virtual       void                      SetWrapMode                (      CATLONG32                  iWrapMode                    );

    virtual       void                      GetNonC2Parameters         (      CATListOfDouble          & NonC2Parameters              );
    
    virtual       void                      SetGetDBG                  (      CATLONG32                  iDBGMode                     ,
                                                                              void                   **  iInfoDBG                     );

    virtual       void                      SetSplitMode               (      CATLONG32                  iSplitMode                   );
    virtual       void                      GetSplitedSurfaces         (      CATLISTP(CATSurface)     & oPreviousSurfaces            ,
                                                                              CATListOfInt             & oC2Domain                    );
    virtual       void                      SetPreviousSurfaces        (const CATLISTP(CATSurface)     & iPreviousSurfaces            ,
                                                                        const CATListOfInt             & iC2Domain                    );


  protected:
    // rend l'objet de type general
    virtual    CATGeneralizedSweepSurface * GetAggregatedObject        ()                                                               const = 0;
    // rend l'objet derivé

    virtual    CATGeneralizedSweepSurface * GetDerivedObject           ()                                                               const = 0;
    virtual       void                      Create                     ()                                                               = 0;
    virtual       void                      CanonicShapeDestruction    ();

// DEBUG
  protected :
    virtual       CATBoolean                DBG_CheckAll               ()                                                               const = 0;
    virtual       void                      DBG_ErrorRethrow           (      CATError                *  iError                       ) const = 0;
    virtual       int                       DBG_IncLevel               ()                                                               const = 0;
    virtual       int                       DBG_DecLevel               ()                                                               const = 0;
    virtual       void                      DBG_IniLevel               ()                                                               = 0;
// DEBUG
   
};

//NLD021020 non necessaire ici extern "C"
ExportedByFrFAdvancedOpeSur CATString *GetCATSweepCanonicSurfaceDetectorDefaultOperatorId();

#endif
