// A VOIR: orientation de la surface par rapport aux orientations
//   des courbes guide et profil

// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATExtrudedSweepSurface:
// Utility for producing sweep of Geometric entities.
//=============================================================================
// Usage notes:
//
// - CXR2.
// - reserve (Protected) a l operateur topologique de Sweep.
//=============================================================================
// 15 07 98 NLD Creation.
// 17 07 98 CPL Destructeur virtual
// 04 12 98 CPL Ajout _RmProfile dans le cas du Sweep Circle/Segment.
// 07 07 99 NLD Ajout DbgGetEquivalentPointsCount,
//                    DbgGetEquivalentPointsCountForBreak,
//                    BreakPoint()
// 20 07 99 CPL Ajout GetSurface
// 15 02 00 CPL Ajout SetImplicitProfile
// 22 02 01 NLD IsTwisted(), _Twisted
// 22 03 01 CPL _VivicityEngine
// 29 01 02 NLD _TwistedSurface et argument optionnel ioTwistedSurface a IsTwisted
// 16 12 02 NLD Gestion de la configuration;
//              - ajout _SoftwareConfiguration
//              - ajout SetSoftwareConfiguration
// 18 04 03 CCK Changement de _TwistedSurface en _ListOfTwistedSurf (dans le mode UnTwist,
//              on veut toutes les surfaces twistees)
// 24 04 03 CCK Nouvelle methode IsTwisted pour gerer les listes de surfaces
// 20 10 03 NLD Ajout ValidateSupportSurface()
// 21 10 03 NLD Arguments supplémentaires à SetSupportSurface() pour validation
//              de la surface support
// 22 10 03 CCK IsTooSharp(), _TooSharp
// 19 01 04 NLD Ajout  _OrnVsProfileSweepSurface et  _OrnVsGuideSweepSurface
//              pour distinguer de  _OrnVsProfile et  _OrnVsGuide qui seront relatifs
//              à la surface support éventuelle
//              Ajout _ActiveCoinsGetEquivalentPoints
// 22 01 04 NLD Ajout _BilinearMappingToSupport et argument iBilinearMappingToSupport à SetSupportSurface
// 09 02 04 NLD Ajout de _RemoveTwistedSurfaces
// 10 02 04 NLD Ajout de _RemoveSweepSurface, _RemoveSupportSurface,
//              et argument iReadOnly à GetSweepSurface(), GetSupportSurface(), GetSurface()
// 19 02 04 NLD Ajout de _Validated et Init()
// 24 11 04 NLD Mode iValidate=2 de SetSupportSurface()
// 22 06 05 NLD GetSurface() renomme en GetExtrudedSurface() pour facilite de recherche XRef
// 28 06 05 NLD Ajout de LockGeometry() et UnlockGeometry() qui remplacent les macros
// 02 08 06 NLD Ajout _UseBilinearMappingToSupport
// 05 10 06 NLD Ajout _ProfileInMFPlane et argument iProfileInMFPlane a SetImplicitProfile()
//              dont les arguments deviennent optionnels
//              Ajout argument optionnel ioKOCheckMFPlaneParameters à GetEquivalentPoints()
// 05 10 06 NLD Ajout _WorkingMFPlane
// 29 11 06 NLD L'argument ioListTwistedSurface de IsTwisted() devient un pointeur de liste
//              afin de gerer le cas de l'appelant ne voulant pas lire la liste
// 11 01 07 NLD Distinction twist/wrap
//              Ajout _Wrapped,  ajout argument ioWrapped à IsTwisted()
// 05 12 08 NLD Ajout _OptimizeReportData
// 12/10/09 NLD Ajout _TwistDetection et SetTwistDetection()
// 22/10/09 NLD Ajout ReportPeriodicityInfo() pour factorisation SweepSurface/SupportSurface
//              Ajout ReportPeriodicityInfoOnSupportSurface()
//              Ajout _OKPeriodicityOnSupportSurface
// 06/04/10 NLD Ajout _SweepSurfaceLimits pour aide au diagnostic fine
//              (evite les unions de limites faites par l'extruder)
//              et de GetSweepSurfaceInitialLimits()
// 03/05/10 NLD Sont desormais declares dans l'implementation:
//              _DbgGetEquivalentPointsCount,
//              _DbgGetEquivalentPointsCountForBreak,
//              _ActiveCoinsGetEquivalentPoints
// 22/10/15 NLD Mise au propre. Smart indent
//              Ajout _ListOfDebugSurfToRemove
// 26/04/21 NLD Revue/protection des données d'orientation
//              - _OrnVsProfile passe en protected
//              - _OrnVsGuide   passe en protected
//              Ajout SetOrnVsProfile()
//              Ajout SetOrnVsGuide()
//              Ajout GetOrnVsProfile()
//              Ajout GetOrnVsGuide()
// 08/12/21 NLD Changement de signature du constructeur qui reçoit la configuration
//              Ajout InitFromAnalyticSurfaces()
// 08/03/23 JSX _OrnVsGuide et _OrnVsProfile en private pour suivre avec set/get
//=============================================================================
#ifndef CATExtrudedSweepSurface_H
#define CATExtrudedSweepSurface_H

#include <FrFAdvancedOpeSur.h>                  // For Windows

class CATGeoFactory ;
class CATGeometry ;
class CATPlane ;
class CATSweepSurface ;
class CATSurface;
class CATMathTransformation2D;
class CATCurve;
class CATPCurve;
class CATCrvParam;
class CATCrvLimits;
class CATSurParam;
class CATSurLimits;
class CATFrFSweepShape ;
class CATMathTransformation2D;
class CATMathTransformation1D;
class CATFrFCompositeCurve;
class CATPointOnEdgeCurve;
class CATEdgeCurve;
class CATPlane;
class CATFrFSweepVivicity;
class CATSoftwareConfiguration;

#include <CATMathDef.h>                       // Pour typedef CATBoolean
#include <CATCGMVirtual.h>
#include <CATListOfCATSurfaces.h>
#include <CATListOfDouble.h>

//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedOpeSur CATExtrudedSweepSurface : public CATCGMVirtual
{
  public :

//-------------------------------------------------------------------------
// Constructor from CATSurface
//-------------------------------------------------------------------------
// A remplacer par un constructeur avec iFactory et iSoftwareConfiguration. NLD221015
CATExtrudedSweepSurface ();

// iProfileIndex et iGuideIndex donnent les index des courbes dans le profil
// et la guide auxquelles correspondent cette surface
// iDomainIndex donne l'index dans la shape du domaine qui correspond à cette surface
                     CATExtrudedSweepSurface  (CATGeoFactory           * iFactory              ,
                                               CATSoftwareConfiguration* iConfig               ,
                                               CATFrFCompositeCurve    * iProfile              ,
                                               CATLONG32                 iProfileIndex         ,
                                               CATFrFCompositeCurve    * iGuide                ,
                                               CATLONG32                 iGuideIndex           ,
                                               CATFrFSweepShape        * iShape                ,
                                               CATLONG32                 iDomainIndex          = 0);

         void        SetSoftwareConfiguration (CATSoftwareConfiguration* iConfig               ) ;

//-----------------------------------------------------------------------------
//- Destructor
//-----------------------------------------------------------------------------
virtual ~CATExtrudedSweepSurface() ;

// ****************************************
// * Methods needed by CATExtruderBySweep * cf CATExtruder.h
// ****************************************
// Indications sur la parametrisation:
// - reguliere : les limites de la surface sweep sont des isopares
//     de la surface support
//     avec 2 cas:
//      - lineaire : on passe de la parametrisation des courbes
//          d appui (profil et guide) a celle de la surface par
//          une transformation lineaire
//      - non lineaire : le parametrage de la surface est quelconque
//
// - non reguliere : les limites de la surface sweep ne sont pas des
//     isopares de la surface support
//     exemple:
//         *     |-******    *  : surface sweep
// profil *      |*    *|    !- : surface support (ex: plan)
//       *       ******--
//
//         guide ******
//
// Par defaut: parametrisation reguliere, non lineaire
//
// Methodes de definition de la parametrisation
// --------------------------------------------
         // Indique que la parametrisation n est pas reguliere
         void        SetParametrizationToNotRegular() ;

         // Indique que la parametrisation est lineaire
         // Calcul la transformation lineaire
         void        SetParametrizationToLinear
                                        (const int                       iOrnVsProfile          = 1 , // -1 si sens surface inverse sens profil
                                         const int                       iOrnVsGuide            = 1 , // -1 si sens surface inverse sens guide
                                         const int                       iSwapped               = 0 ); // 1 si inversion u et v, 0 sinon

         // definit la transformation lineaire de parametrisation des
         // courbes de definition vers la surface
         // si pas de transformation, on la calcule
         void        DefLinearParametrization
                                        (      CATMathTransformation2D*  iFromProfileCenterToUV = 0) ;

// Methodes d'interrogation de la parametrisation
// ----------------------------------------------
         // tout en un coup, mais certains arguments n'ont de signification
         // qu'en fonction des valeurs de certains autres
         // si elle rend un pointeur non nul vers une transfo,
         // la destruction de celle-ci est a la charge de l'appelant
         void        GetParametrization
                                        (      int                     & oRegular              ,
                                               int                     & oLinear               ,
                                               int                     & oOrnVsProfile         ,
                                               int                     & oOrnVsGuide           ,
                                               CATBoolean              & oSwapped              ,
                                               CATMathTransformation2D*& oFromProfileCenterToUV) ;

         // Methode de correspondance
         void        GetEquivalentPoints(const CATLONG32                 iNbPoints             ,
                                         const CATCrvParam               iProfileParams      [],
                                         const CATCrvParam               iGuideParams        [],
                                               CATSurParam               oSurfParams         [],
                                               CATListOfDouble        *  ioKOCheckMFPlaneParameters = 0) ;

         // Methodes de creation des PCurves

         // - paralleles aux guides
         CATPCurve * CreateParallelPCurve(const CATCrvParam             & iProfileParam         ,
                                          const CATCrvLimits            & iGuideLimits          ) ;

         // - paralleles aux profils
         CATPCurve * CreateMeridianPCurve
                                         (const CATCrvLimits            & iProfileLimits        ,
                                          const CATCrvParam             & iGuideParam           ) ;

         // cpl seulement pour canonic
 virtual CATPCurve * CreateParallelPCurve(      CATPointOnEdgeCurve    *  iProfile              ,
                                                CATEdgeCurve           *  iCenter               ,
                                                CATCrvLimits            & iCenterLimits         ,
                                                CATSurface             *  iSupport              ,
                                                short                   & oOrientation          );

          //
          // Obtention de la surface support
         CATSurface * GetSupportSurface   (      CATBoolean                iReadOnly             = CATBoolean(0)) ;
          // Obtention des limites initiales de la surface support
         void         GetSupportSurfaceInitialLimits
                                         (      CATSurLimits            & oInitialLimits        );
         // Obtention de la surface sweep (obtenue par balayage)
         CATSurface * GetSweepSurface     (      CATBoolean                iReadOnly             = CATBoolean(0)) ;
         // Obtention des limites initiales de la surface sweep (obtenue par balayage)
         void         GetSweepSurfaceInitialLimits
                                          (      CATSurLimits            & oInitialLimits        );

         CATSurface * GetExtrudedSurface  (      CATBoolean                iReadOnly             = CATBoolean(0)) ;

         void         SetSweepSurface     (      CATSurface             *);

         // iValidate=1 en entree pour demander la validation de la surface support
         //   par rapport à la surface sweep, 0 sinon
         // iValidate=2 en entree pour forcer le marquage valide de la surface support
         // oOkValid=1 en sortie si la surface est valide, 0 sinon
         // Mapping bilineaire optionnel
         void         SetSupportSurface   (      CATSurface             *,
                                                 int                       iValidate                ,
                                                 CATMathTransformation2D*  iBilinearMappingToSupport,
                                                 int                     & oOkValid                 );

         void         SetOrnVsProfile     (      int                       iOrnVsProfile            );
         int          GetOrnVsProfile     ();
         void         SetOrnVsGuide       (      int                       iOrnVsGuide              );
         int          GetOrnVsGuide       ();

        // Run
 virtual void         GetResult           ();

         void         DestroySurface      ();

         void         RemoveProfile       ();

         // iImplicitProfile indique que le profil est implicite
         // iProfileInMFPlane indique que le profil doit toujours etre dans
         // le plan défini par le moving frame
         void         SetImplicitProfile  (      CATBoolean                iImplicitProfile         = TRUE,
                                                 CATBoolean                iProfileInMFPlane        = FALSE) ;

         // ecriture de l'indicateur de detection de twist active
         void         SetTwistDetection   (      int                       iTwistDetection          = 1);
         // lecture/ecriture de l'indicateur de surface twistee
         // et de la surface restreinte twistee
         void         IsTwisted           (      int                       iSet                     ,     // 1 pour ecrire,                   0 pour lire
                                                 int                     & ioTwisted                ,     // 1 pour surface twistee,          0 sinon
                                                 int                     & ioWrapped                ,     // 1 pour surface en rebroussement, 0 sinon
                                                 CATSurface            **  ioTwistedSurface         = 0) ;// pointeur eventuel vers surface restriction twistee

         // methode permettant la lecture/ecriture toutes les surfaces associees aux zones twistees;
         // N.B si on veut seulement lire l'indicateur de twist, ne pas utiliser cette methode qui nous rend toutes
         // les surfaces, et nous rend proprietaire de ces surfaces,
         // mais utiliser la methode monosurface ci-dessus
         // N.B les surfaces sont rendues a la suite des surfaces deja contenues en entree dans la liste
         // passee en argument
         //    Nicolas 07/05/03 
         // Si en mode lecture on ne nous passe pas de pointeur de liste, on reste proprietaire des surfaces
         //    Nicolas 29/11/06
         void         IsTwisted           (      int                       iSet                     ,     // 1 pour ecrire,                   0 pour lire
                                                 int                     & ioTwisted                ,
                                                 int                     & ioWrapped                ,
                                                 CATLISTP(CATSurface)   *  ioListTwistedSurface     = NULL);

         // lecture/ecriture de l'indicateur de surface en pointe (u et v colineaire)
         void         IsTooSharp          (      int                       iSet                     ,     // 1 pour ecrire,                   0 pour lire
                                                 int                     & ioTooSharp               );    // 1 pour surface en pointe,        0 sinon

//-------------------------------------------------------------------------
// Data
//-------------------------------------------------------------------------
// Ici je fais un passage progressif et très/trop tardif de données de public en protected; NLD260421
protected:
   CATGeoFactory                              * _Factory ;
   CATSoftwareConfiguration                   * _SoftwareConfiguration ;

   CATSurface                                 * _SweepSurface ;
   CATSurLimits                               * _SweepSurfaceLimits;
   CATSurface                                 * _SupportSurface ;
   CATSurLimits                               * _SupportSurfaceLimits;
// CATSurface                                 * _TwistedSurface ; // restriction twistee

// define pour aider l'analyseur de syntaxe de Sniff
#define CATExtrudedSweepSurface_ListPOfCATSurface CATLISTP(CATSurface) 
   CATExtrudedSweepSurface_ListPOfCATSurface    _ListOfTwistedSurf;
   CATExtrudedSweepSurface_ListPOfCATSurface    _ListOfDebugSurfToRemove;


public:
   CATFrFCompositeCurve                       * _Profile;
   CATFrFCompositeCurve                       * _Guide;

   // Paramétrisation
   CATLONG32                                    _Regular;
   CATLONG32                                    _Linear;
private:
   CATLONG32                                    _OrnVsProfile;
   CATLONG32                                    _OrnVsGuide;
public:
   CATLONG32                                    _OrnVsProfileSweepSurface;
   CATLONG32                                    _OrnVsGuideSweepSurface;
   CATBoolean                                   _Swapped;
   CATMathTransformation2D                    * _FromProfileCenterToUV;
   CATMathTransformation1D                    * _TransfoProfileParameter;

public:
   CATFrFSweepShape                           * _Shape;
   CATLONG32                                    _GuideIndex;
   CATLONG32                                    _ProfileIndex;
   CATLONG32                                    _DomainIndex;

   CATBoolean                                   _RmProfile;
   CATBoolean                                   _IsImplicitProfile;
   CATBoolean                                   _ProfileInMFPlane;

   CATFrFSweepVivicity                        * _VivicityEngine;

protected:
   int                                          _TwistDetection;
   int                                          _Twisted ;
   int                                          _Wrapped ;
   int                                          _TooSharp;

private: 
         void         Init                ();
         void         InitFromAnalyticSurfaces();

         // lock/unlock de geometry et calcul du nombre de references
         int          LockGeometry        (      CATGeometry            *  iGeom                    );
         int          UnlockGeometry      (      CATGeometry            *  iGeom                    );
         void         ProjectCrvOnSupport (      CATCurve               *  PCrvRes                  ,
                                                 CATPCurve              *& oPcrv                    );
         // Validation et suppression eventuelle de la surface support
         void         ValidateSupportSurface() ;
         // Postage de l'information de pseudo-periodicite si elle existe sur la courbe profil
         void         ReportPeriodicityInfo(     CATSurface             *  iSurface                 ,
                                                 CATBoolean                iSwapped                 );
         void         ReportPeriodicityInfoOnSupportSurface();

//static int _DbgGetEquivalentPointsCount ;
//static int _DbgGetEquivalentPointsCountForBreak ;
//static int _ActiveCoinsGetEquivalentPoints ;
         void         BreakPoint           () ;

   CATLONG32                                    _OnSweepSurface;
   int                                          _RemoveTwistedSurfaces;
   int                                          _RemoveSweepSurface;
   int                                          _RemoveSupportSurface;
   int                                          _Validated;
   int                                          _OKPeriodicityOnSupportSurface;
   CATPlane                                   * _WorkingMFPlane ;

   CATMathTransformation2D                    * _BilinearMappingToSupport;
   int                                          _UseBilinearMappingToSupport ;
   void                                       * _OptimizeReportData ;
} ;

#endif
