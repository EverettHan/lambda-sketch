// COPYRIGHT DASSAULT SYSTEMES 1999
/** @CAA2Required */
//==========================================================================
//
// CATFrFSweepChecker:
//
//==========================================================================
//
// Usage notes:
//
//========================================================================== 
// 13/07/99 CPL Creation
//              Reste a stocker les infos pour le calcul 
//              Stucture et methodes pour le Checker
// 25/09/99 CPL Profile tgt deviation
// 13/04/00 PRG Analyse de la parametrisation dans le sens des guides
// 17/08/00 PRG Analyse des continuites internes du sweep
// 27/10/00 PRG integration des operateurs de sweep a profile implicite 
//              (blend, sweep circle, conique, ...).
// 18/08/03 MNA Dans le but de rajouter des Warnings dans les operateurs de sweep et Loft
//              j'ajoute des Warnings me permettant de comparer les discontinuites 
//              des entrees entrees du Loft et les sorties.
//
// 25/08/03 MNA Mise en place des Warnings et Methode GetExternalAnalyseOfSurface.
// 25/08/03 MNA Mise en place des Warnings et Methode GetInternalAnalyseOfSurface
//
// 15 10 03 MNA _externalProfileDevAnalysisPossible _externalGuideDevAnalysisPossible 
//              Selon le type de Sweep ce n'est pas coherent de faire une telle analyse :
//              (codes ulterieurement parametres par CATFrFSweepCheckerSurfaceType NLD161012)
//              _ SurfacesType=0 (Lofts)            =>
//                  -> Cas du Loft (Check des guides + profils)
//
//              _SurfacesType=1 (profils implicites)=>  
//                  -> Cas de Sweep a profil implicite, passant par les guides 
//                  -> Cas de sweep a profil implicite ne passant pas par les guides (Check ni guide ni profil : Voir loi de longueur negative)
//
//              _SurfacesType= 2 (Birail)         =>  
//                  ->Cas general : Birail passant par les guides           (et non les profils.)
//                  ->Birail ne passant ni par les guides ni par les profils
//                        ( Anchor points pas sur le profil)(22-> Check ni guide, ni profil) -> OK
//              _SurfacesType=3 (Sweep Unspec)    =>
//                  -> Cas general :Sweep Unspec passant par les profil (pas guide)si :
//                     profilepositionType=2 (voir CATFrFTopologicalSweep)
//                     profilepositionType=4 (voir CATFrFTopologicalSweep) 
//                     SAUF si j'ai une surface de ref avec une loi d'angle non constante egale a 0.0
//                  -> Sweep Unspec ne passant ni par les guides ni par les profils
//              _SurfacesType=4 (Blend)
// 24/10/03   MNA : Nouvelles methodes de Gestion de la remontee de Warning: GetNumberOfWarning(),BeginningWarning(),NextWarning(),
//                                                                           GetCoupleOfCurvesError.
//
// 31/10/03   MNA : Ajout de la methode ComputeParamForBorderChecker qui permet de calculer les points ou on veut chercher les deviations
//
// 03/11/03 MNA : Je deplace l'implementation des methodes : SetOrnMG,SetSpine,SetSpineOrientation,SetGuidesOrientations du .h 
// 05/11/03 MNA : nouvelle methode AddRefMaxDevPoint(CATTransitionPositionResult & ioDevResul) permet de faire
//                un AddRef sur un objet du type CATTransitionDeviationResult.
// 05/11/03 MNA : idem ReleaseRefMaxDevPoint(CATTransitionPositionResult & ioDevResult)
// 07/11/03 MNA : Ajout de la methode ComputeImplicitProfileForBirailSweep();
// 07/11/03 MNA : Ajout de la variable _RemoveImplicitProfile (Cas ou le profil implicite est cree par mes soins).
// 10/11/03 MNA : Changement de signature de ComputeMaxDevForOneGuide,ComputeMaxDevForOneGuideWithExpliciteProfile,ComputeMaxDevForOneBoundaryGuide,
//                ComputeMaxDevForOneNonIsoparametricGuide => Je renvoie un long
// 12/11/03 MNA : Je change la signature de ComputeTwoBorderCcvs(), je rajoute un int pour l'Orn de la courbe.
// 13/11/03 MNA : Je deplace les methodes implementees ici (ActivateMaxOffsetDeviation(),SetNbOfDiscretizedPointsForGuide()
//                SetNbOfDiscretizedPointsForProfile()),GetProfileCrvDiscontinuities(),GetGuideCrvDiscontinuities(),GetProfileSurDiscontinuities(),
//                GetGuideSurDiscontinuities() dans le .cpp, conformement a la litterature disponible a CGM:
//                "principes généraux de programmation" du Pere Lochard.
//                IDEM enum Diagnostic devient CATFrFSweepChecker_Diagnostic meme litterature. (Pour plus de renseignements sur cet ouvrage s'adresser 
//                au bureau LAV. 216, possibilite de dedicaces)
// 26/11/03 MNA : Je change la signature 
//                de void ComputeMaxDevForOneProfile( CATLONG32 iIndexProfile )
//                &  void ComputeMaxTgtForOneProfile( CATLONG32 iIndexProfile )
//                je renvoie un long
// 01/12/03 MNA : Ajout de plusieurs donnees membres _IsToUpdate(suffixe) qui indique si le Run a deja ete effectue ou non sur chaque
//                option (En effet on peut lancer un Run double avec des activations differentes, a gerer).
// 27/05/04 NLD : Ajout de GetProfileDomain() pour acces et verification aux domaines
//                _ProfileDomain est renommé _ProfileDomainDoNotUse
// 25/06/04 NLD : Passage par une méthode locale ProtectedCreatePointOnCurve pour eviter de
//                laisser trainer des points sur les ForeignCurves, rendant les modèles illisibles
//                (tant que le problème des points remanents n'est pas reglé)
// 01/07/04 NLD : Ajout de GetUnderLyingCurve()
// 08/02/05 NLD : Structure CheckerPositionResult pour gerer la destruction
//                des points de positionnement
// 20/05/05 NLD : Ajout _GlobalApproxTolerance et SetGlobalApproxTolerance()
// 29/06/05 NLD : Ajout de SetGuideNumbersAlongProfiles() et _GuideNumbersAlongProfiles
// 19/09/05 NLD : Shunt de LookForSidesToMerge() et ComputeEndsForPLine(), non couvertes par tests, non appelees
// 01 12 06 JSX   Ajout GaussianCurvatureAnalysis
// 19/12/07 NLD : Ajout _ScaledAndVersionnedInfinite ;
// 23/10/09 NLD : Correction signature de GetMaxGapBetweenGuideAndProfile() qui ne rendait pas
//                ses arguments de sortie theoriques (non passes par adresse)
//                (N.B jamais utilisee)
// 09/12/09 NLD Definition de nomenclature pour les #define partages:
//              ShuntNLDTestCoverage_ComputeEndsForPLine devient CATFrFSweepCheckerShuntCoverage_ComputeEndsForPLine
// 17/10/12 NLD Typage de _SurfacesType et SetSurfacesType() avec CATFrFSweepChecker_SurfaceType
// 02/12/16 NLD Smart indent
// 05/01/17 NLD Ajout FinalReleaseRefMaxDevPoints()
//========================================================================== 

#ifndef CATFrFSweepChecker_H 
#define CATFrFSweepChecker_H


#include <FrFOpeUtil.h>
#include <CATIACGMLevel.h>

#include <CATTransitionCheckingCommand.h>
#include <CATSweepClassId.h>
#include <CATMathDef.h>
#include <CATFrFCompositeCurve.h>
#include <CATSoftwareConfiguration.h>
#include <CATCGMVirtual.h>
#include <CATListOfInt.h>
#include <CATMathPoint.h>

class CATSurface;
class CATCurve;
class CATGeoFactory;
class CATCartesianPoint;
class CATMathVector;
class CATMathPoint;


enum CATFrFSweepChecker_Diagnostic {NoProblem                           ,
                                    GuideDevPointExt                    ,
                                    ProfilDevPointExt                   , 
                                    GuideDevTangencyExt                 ,
                                    ProfilDevTangencyExt                ,
                                    PasDeCleanPossibleChangerLaTol      ,
                                    ProblemeCleanGuideDevPointInt       ,
                                    ProblemeCleanProfileDevPointInt     ,
                                    ProblemeTrouSurfSupTrouGuideEntree  ,
                                    ProblemeTrouSurfSupTrouProfileEntree,
                                    GuideDevPointInt                    ,
                                    ProfilDevPointInt                   ,
                                    GuideDevTangencyInt                 ,
                                    ProfilDevTangencyInt                };

enum CATFrFSweepChecker_SurfaceType{CATFrFSweepChecker_SurfaceType_0Loft            = 0,
                                    CATFrFSweepChecker_SurfaceType_1ImplicitProfile = 1,
                                    CATFrFSweepChecker_SurfaceType_2Birail          = 2,
                                    CATFrFSweepChecker_SurfaceType_3Unspec          = 3,
                                    CATFrFSweepChecker_SurfaceType_4Blend           = 4
                                   };

//-----------------------------------------------------------------------------
class ExportedByFrFOpeUtil CATFrFSweepChecker  : public CATCGMVirtual
{
  public:
    //------------------
    // Ctor & Destructor
    //------------------
  
      CATFrFSweepChecker (CATGeoFactory            * iFactory        ,
                          CATLONG32                  iNbGuides       ,
                          CATFrFCompositeCurve    ** iGuides         ,
                          CATLONG32                  iNbProfiles     ,
                          CATFrFCompositeCurve    ** iProfiles       ,
                          CATLONG32                * iOrnPs          , 
                          CATLONG32                  iOrnMG          ,
                          CATLONG32                  iIndexMP        ,
                          CATLONG32                  iIndexMG        ,
                          CATLONG32                * iProfileDomain  ,
                          CATLONG32                  iNbSurfacesP    , 
                          CATLONG32                  iNbSurfacesG    , 
                          CATSurface              ** iSweepSurfaces  ,
                          CATSoftwareConfiguration * iSoftwareConfig = NULL);
        
      CATFrFSweepChecker (CATGeoFactory            * iFactory        ,
                          CATLONG32                  iNbGuides       ,
                          CATFrFCompositeCurve    ** iGuides         ,
                          CATLONG32                  iNbSurfacesG    ,
                          CATSurface              ** iSurfaces       ,
                          CATLONG32                * iOrnGs          ,
                          CATSoftwareConfiguration * iSoftwareConfig = NULL);

    virtual ~CATFrFSweepChecker();
  
    //---------
    // Operator
    //---------

    void Run();


    //------------------
    // Advanced settings 
    //------------------
    
    //MNA 15 10 03 ->proto
    //Doc RemoveExternalCheckOnProfile && RemoveExternalCheckOnGuide:
    //Cette information est necessaire pour juger de la validite d'une demande de 
    //verification de la compatibilite des donnees d'entrees avec le sweep resultat.

    void RemoveExternalCheckOnProfile      ();
    void RemoveExternalCheckOnGuide        ();

    void ActivateProfileMaxDeviation       (      CATBoolean     iActive                    = CATBoolean(1));      // Default: In
    void ActivateGuideMaxDeviation         (      CATBoolean     iActive                    = CATBoolean(1));      // Default: In
    void ActivateChecker                   (      CATBoolean     iActive                    = CATBoolean(1));      // Default: Out
    void ActivateGuideParamAnalysis        (      CATBoolean     iActive                    = CATBoolean(1));  
    void ActivateProfileParamAnalysis      (      CATBoolean     iActive                    = CATBoolean(1));  
    
    void ActivateProfileTangencyDeviation  (      CATLONG32      iCase                      = 0,
                                            const CATMathVector* iTangent                   = 0);
    // iGuide va de 1 a NbGuides
    void ActivateGuideTangencyDeviation    (      CATLONG32      iNumGuide                  , 
                                            const CATMathVector* iGuideNormalVector         = 0);

    void ActivateInternalDeviations              (CATBoolean     iActive                    = CATBoolean(1));      // Default: In
    
    void ActivateGlobalInternalDeviationsAnalysis(CATBoolean     iActive                    = CATBoolean(1));      // Default: In
    void ActivateGlobalExternalDeviationsAnalysis(CATBoolean     iActive                    = CATBoolean(1));      // Default: In
    

    void ActivateMaxOffsetDeviation              (CATBoolean     iOffsetActive              = CATBoolean(1));

    void ActivateMaxGaussianComputation          (CATBoolean     iGaussianCurvature         = TRUE);
      // When iTangent == NULL, Profile have to be a "Wire Pose Sur"
      // (iCase == 0) => Tangency on First & Last Profile
      // (iCase == 1) => Tangency on only  First Profile
      // (iCase == 2) => Tangency on only  Last Profile  
    void SetNbOfDiscretizedPointsForGuide        (CATLONG32      iNbPts                     );

    void SetNbOfDiscretizedPointsForProfile      (CATLONG32      iNbPts                     );

    void SetSmoothOption                         (CATLONG32      iSmoothOption              ,
                                                  double         iAngle                     );

    void SetCleanOption                          (CATLONG32      iCleanOption               ,
                                                  double         iCleanMaxDeformationOnGuide,
                                                  double         iCleanMaxDeformationOnProfile);

    void SetProfileApproxTolerance               (double         iProfileApproxTolerance      );

    void SetGuideApproxTolerance                 (double         iGuideApproxTolerance        );

    void SetGlobalApproxTolerance                (double         iGlobalApproxTolerance       );

    void SetExtrapolatedConnexions               (CATListOfInt & iListExtrapolatedConnexions  );
    
    void SetIndexOfPackCrvInCcv                  (CATListOfInt & iIndexOfPackCrvInCcv         );

    void SetTypeOfGuides                         (CATLONG32    * iTypeOfGuides                );

    //MNA : Le mode Untwist peut autorise un trou dans le chainage topologique des surfaces
    void SetUnTwistMode                          (CATLONG32      iUnTwist                     );

    void SetAngularLaws                          ();
    void SetLengthLaws                           ();

    void SetSurfaces                             (CATLONG32                      iNbSurfacesP                 ,
                                                  CATLONG32                      iNbSurfacesG                 ,
                                                  CATSurface                  ** iSweepSurfaces               );

    //MNA -> Info transmise par CATExtrudedSweepSurface (Dans le cas des surfaces sweep)
    // Doc : Permet de savoir quel sont les cotes a merger pour deux surfaces adjacentes.

    void SetSurfacesOrientations                 (CATLONG32                      iNbSurfacesP                 ,
                                                  CATLONG32                      iNbSurfacesG                 ,
                                                  CATLONG32                    * iOrientationsV               ,
                                                  CATLONG32                    * iOrientationsU               );

    //MNA : Donnee transmise par le Loft ou en interne dans le cas de Sweep Birail

    void SetImplicitProfile                      (CATFrFCompositeCurve         * iImplicitProfile);

    //MNA : -> Permet de connaitre la nature de la surface (Sweep + Blend)

    void SetSurfacesType                         (CATFrFSweepChecker_SurfaceType iType                        );
    
    void SetOrnMG                                (CATLONG32                      iOrnMG                       );

    void SetSpine                                (CATFrFCompositeCurve         * spineCCV                     );

    void SetSpineOrientation                     (CATLONG32                      spineOrientation             );

    void SetGuideOrders                          (CATLONG32                    * guideOrders                  );

    void SetGuideOrientations                    (CATLONG32                    * guideOrientations            );

    void SetGuideNumbersAlongProfiles            (int                            NbValues                     ,
                                                  CATLONG32                    * guideNumbers                 ) ;// (1 + nb profile segments) values

    //-------
    // Result
    //-------
    CATLONG32 GetNumberOfGuides() const
      {
      return _NbGuides;
      };
    //----------------------------
    // GetExternalAnalyseOfSurface
    //----------------------------
    
    //MNA : Methodes relatives a la remontee de Warning

    //Renvoie le nombre de Warning detectes

    CATLONG32  GetNumberOfWarning();

    //Initialise l'iterateur du nombre de Warning
    void       BeginningWarning();

    //Si c'est possible passe au Warning suivant
    CATBoolean NextWarning();

    //Renvoie le diagnostic (int) et le couple de curves concernes par l'anomalie renvoyee.
    //L'utilisteur DOIT FAIRE UN ADDREF sur les objets curves, sinon il s'expose a des eventuelles
    //destructions pas maitrisees.

    CATFrFSweepChecker_Diagnostic GetCoupleOfCurvesError(CATCurve* &oCurveError1, CATCurve* &oCurveError2);
    
       
    CATFrFSweepChecker_Diagnostic GetDiagnosisOfExternalAnalysis();
    
   
    CATFrFSweepChecker_Diagnostic GetDiagnosisOfInternalAnalysis();
    
    // Max Deviation
    //   et l'index c'est un index de quoi?
    void GetMaxGapBetweenGuideAndProfile         (CATLONG32                      iIndex                         ,
                                                  double                       & oMaxGapBetweenGdAndProf        ,
                                                  CATMathPoint                 & oPositionMaxGapBetweenGdAndProf);

    // N.B les points sous CATTransitionPositionResult ne demeurent pas la propriete de cet objet 
    void GetMaxDevOnProfile                      (CATLONG32                      iIndex                         ,
                                                  CATTransitionCheckingCommand   iCmd                           ,
                                                  CATTransitionDeviationResult & oDeviation                     ,
                                                  CATTransitionPositionResult  & oPosition                      );

    // N.B les points sous CATTransitionPositionResult ne demeurent pas la propriete de cet objet 
    void GetMaxDevOnGuide                        (CATLONG32                      iIndex                         ,
                                                  CATTransitionCheckingCommand   iCmd                           ,
                                                  CATTransitionDeviationResult & oDeviation                     ,
                                                  CATTransitionPositionResult  & oPosition                      );

    // N.B les points sous CATTransitionPositionResult restent la propriete de cet objet 
    void GetProfileCrvDiscontinuities            (CATLONG32                    & oNbCurvesOnProfiles            ,
                                                  CATTransitionDeviationResult*& oDiscontinuities               ,
                                                  CATTransitionPositionResult *& oPositions                     );
    // N.B les points sous CATTransitionPositionResult restent la propriete de cet objet 
    void GetGuideCrvDiscontinuities              (CATLONG32                    & oNbCurvesOnGuides              ,
                                                  CATTransitionDeviationResult*& oDiscontinuities               ,
                                                  CATTransitionPositionResult *& oPositions                     );

    // N.B les points sous CATTransitionPositionResult restent la propriete de cet objet 
    void GetProfileSurDiscontinuities            (CATLONG32                    & oNbSurfP                       ,
                                                  CATTransitionDeviationResult*& oDiscontinuities               ,
                                                  CATTransitionPositionResult *& oPositions                     );

    // N.B les points sous CATTransitionPositionResult restent la propriete de cet objet 
    void GetGuideSurDiscontinuities              (CATLONG32                    & oNbSurfG                       ,
                                                  CATTransitionDeviationResult*& oDiscontinuities               ,
                                                  CATTransitionPositionResult *& oPositions                     );
    
    void GetGuidesParamAnalysis                  (CATLONG32                      iNumGuide                      ,
                                                  CATLONG32                    & oNbCurves                      ,
                                                  CATLONG32                   *& oNbOfArcs                      ,
                                                  CATLONG32                   *& oCrvDegrees                    );

    void GetSpineParamAnalysis                   (CATLONG32                    & oNbCurves                      ,
                                                  CATLONG32                   *& oNbOfArcs                      ,
                                                  CATLONG32                   *& oCrvDegrees                    );

    void GetProfilesParamAnalysis                (CATLONG32                      iNumProfile,
                                                  CATLONG32                    & oNbCurves                      ,
                                                  CATLONG32                   *& oNbOfArcs                      ,
                                                  CATLONG32                   *& oCrvDegrees                    );

    void GetLongitudinalSweepParamAnalysis       (CATLONG32                    & oNbOfLongitudinalSurfaces      ,
                                                  CATLONG32                   *& oNbOfUArcsPerSurface           ,
                                                  CATLONG32                   *& oSurfUDegrees                  );

    void GetTransversalSweepParamAnalysis        (CATLONG32                    & oNbOfTransversalSurfaces       , 
                                                  CATLONG32                   *& oNbOfVArcsPerSurface           ,
                                                  CATLONG32                   *& oSurfVDegrees                  );

    CATLONG32* GetGuideOrders();

    CATLONG32 OperatorWithSpine();

    // lecture de l'offset max
    void GetMaxOffsets                           (double                       & negativeMaxOffset              ,
                                                  double                       & positiveMaxOffset              ,
                                                  CATLONG32                    & negativeMaxOffsetSurfaceTag    ,
                                                  CATLONG32                    & positiveMaxOffsetSurfaceTag    );

    void GetMaxAbsGaussianCurvature              (double                       & MaxAbsGaussianCurvature        ,
                                                  CATLONG32                    & MaxAbsGaussianCurvatureSurfaceTag,
                                                  double                       * SurParam                       ,
                                                  CATMathPoint                 & iMaxGaussPoint                 );



    void MaxGaussianCurvatureAnalysis            ();

  protected:

    CATGeoFactory                * _Factory;

    CATLONG32                      _NbGuides;
    CATFrFCompositeCurve        ** _Guides;
    CATLONG32                    * _GuidesType; //Nouvelle variable permettant de specifier 
                                           //le type de la guide (i.e. middleguide, fontionnal)
    CATLONG32                      _NbProfiles;
    CATFrFCompositeCurve        ** _Profiles;

    CATLONG32                      _OrnMG;
    CATLONG32                      _IndexMG;
    CATLONG32                    * _OrnGs;
    CATLONG32                    * _OrnPs;
    CATLONG32                      _OrnSpine;
    CATLONG32                      _IndexMP;
    CATLONG32                    * _ProfileDomainDoNotUse; 
            
    CATLONG32                      _NbSurfacesP;
    CATLONG32                      _NbSurfacesG;
    CATSurface                  ** _SweepSurfaces;
    CATFrFSweepChecker_SurfaceType _SurfacesType;

    CATLONG32                    * _guideOrders;

//  CATSweepClassId                _SweepType;

    CATLONG32                      _NbGuidePts;
    CATLONG32                      _NbProfilePts;

    CATLONG32                      _TgtProfile[2];

    CATMathVector                * _TgtPlane[2];

    CATFrFCompositeCurve         * _spineCCV;

    CATLONG32                      _nbCurvesOnTheSpine;
    CATLONG32                    * _nbOfArcsOnTheSpine;
    CATLONG32                    * _curveDegreesOnTheSpine;

    CATLONG32                      _nbCurvesOnGuides;
    CATLONG32                   ** _nbOfArcsOnGuides;
    CATLONG32                    * _nbOfControlPointsOnGuides;
    CATListOfDouble              * _ParamCPsOnGuides;
    CATListOfInt                 * _CurvesIndexAssociatedToCPsOnGuides;
    CATLONG32                   ** _curveDegreesOnGuides;

    CATLONG32                      _nbCurvesOnProfiles;
    CATLONG32                   ** _nbOfArcsOnProfiles;
    CATLONG32                    * _nbOfControlPointsOnProfiles;
    CATListOfDouble              * _ParamCPsOnProfiles;
    CATListOfInt                 * _CurvesIndexAssociatedToCPsOnProfiles;
    CATLONG32                   ** _curveDegreesOnProfiles;

    CATLONG32                      _nbOfLongitudinalSurfaces;
    CATLONG32                      _nbOfTransversalSurfaces;

    CATLONG32                    * _nbOfUArcsPerSurface;
    CATLONG32                    * _nbOfVArcsPerSurface;

    CATLONG32                    * _surfacesUDegrees;
    CATLONG32                    * _surfacesVDegrees;
    CATLONG32                    * _SurfacesUOrn;
    CATLONG32                    * _SurfacesVOrn;
    CATLONG32                    * _OrnVsProfile;
    CATLONG32                    * _OrnVsGuide;
    CATLONG32                    * _GuideNumbersAlongProfiles;
    double                         _ScaledAndVersionnedInfinite;


  private:

    struct CheckerPositionResult
      {
       int                         Remove ;
       CATTransitionPositionResult Position ;
      } ;

    void            Init               ();

    void            ExternalDevAnalysis();
    void            InternalDevAnalysis();

    void            MaxOffsetAnalysis  ();

    //MNA Check sur les index des Warnings a remonter au niveau topo
    
    void            CheckIndexWarning  ();
    
    //MNA : Pour les besoins Personnels : Ajout des Orientations de reference 
    //      des surfaces Sweep, elles sont calculees en fonction des orientation des 
    //MasterGuide, masterProfile, Spine, Implicit profile

    void            FillTabOfSurfacesOrientations              (CATLONG32 iNbSurfacesP,
                                                                CATLONG32 iNbSurfacesG);

    //MNA : Je check en fonction du type de surface si les calculs de deviations demandes sont
    // coherents (a l'aide des methodes RemoveExternalProfile & RemoveExternalGuide)

    void            CheckDeviationsToDo(); 

     //  return 1 if ok, 0 if calcul not succeeded
    CATLONG32       ComputeMaxDevForOneGuide                    (CATLONG32 iIndexGuide   );
    CATLONG32       ComputeMaxDevForOneProfile                  (CATLONG32 iIndexProfile );
    CATLONG32       ComputeMaxTgtForOneProfile                  (CATLONG32 iIndexProfile );

    CATLONG32       ComputeMaxDevForOneGuideWithExpliciteProfile(CATLONG32 iIndexGuide);
    //  return 1 if ok, 0 if the guide does not match to an isoparametric
    CATLONG32       ComputeMaxDevForOneBoundaryGuide            (CATLONG32 iIndexGuide);
    CATLONG32       ComputeMaxDevForOneNonIsoparametricGuide    (CATLONG32 iIndexGuide);    

    void            ComputeMaxGapBetweenGuideAndProfile         (); //-> MNA

    void       ComputeTwoBorderCcvs                ( const CATMathPoint         & iPt      ,
                                                           CATLONG32              iSurfMinP, 
                                                           CATLONG32              iSurfMaxP,
                                                           CATLONG32              iSurfG   ,
                                                           CATFrFCompositeCurve*& oCcv1    , 
                                                           CATFrFCompositeCurve*& oCcv2    ,
                                                           int                    iOrn     ) const;

    void       ComputeProfileBorderCcv( CATLONG32 iIndexProfile,
                                        CATFrFCompositeCurve*& oCcv) const;

    //MNA 07/11/03=> Dans le cas du SweepBirail le profil ne passe pas par la surface,
    //je calcule donc un profil implicite (Bord de la grille de surface suivant V.)
    CATBoolean ComputeImplicitProfileForBirailSweep(CATFrFCompositeCurve         *& oImplicitProfile) const;
 
    void       ComputeMaxDist                      (CATFrFCompositeCurve         *  iCcvElt      ,
                                                    CATFrFCompositeCurve         *  iCcvSur1     ,
                                                    CATFrFCompositeCurve         *  iCcvSur2     ,
                                                    CATLONG32                       iIndexGuide  ,
                                                    CATLONG32                       iIndexProfile,
                                                    CATTransitionCheckingCommand  & iCmd        );

#define CATFrFSweepCheckerShuntCoverage_ComputeEndsForPLine
#ifndef CATFrFSweepCheckerShuntCoverage_ComputeEndsForPLine
    CATLONG32  ComputeEndsForPLine( const CATSurface* CSur,
                                    const CATSurface * NSur,
                                          CATSurParam& CStart, CATSurParam& CEnd,
                                          CATSurParam& NStart, CATSurParam& NEnd) const;
#endif


    void       ComputeValueAtCorners(const CATSurface * Sur ,
                                     double minU, double minV, 
                                     double maxU, double maxV,
                                     CATMathPoint * oVal) const;

   // return 0 if no proximity
   // return 1 if positive merge possible,
   // return -1 if negative merge possible,
   CATLONG32    FindProximity(const double& res2,
                              const CATMathPoint& startGuidePoint,
                              const CATMathPoint& endGuidePoint,
                              const CATMathPoint& surfacesStartPoint,
                              const CATMathPoint& surfacesEndPoint);

    // iTypeContour vaut 1 pour les guides, 2 pour les profiles
    void        ComputeMaxTgtDev( const CATFrFCompositeCurve* iCcv         ,
                                  const CATMathVector       * iTgtPlane    ,
                                        CATLONG32             iIndexContour,
                                        CATLONG32             iTypeContour );

    void        GuideParamAnalysis();
    void        ProfileParamAnalysis();

    void        ParamAnalysisOfACCV(CATFrFCompositeCurve    * CCV                    ,
                                    CATLONG32                 nbCurves               ,
                                    CATLONG32               * nbArcsPerCurve         ,
                                    CATLONG32               * curveDegrees           ,
                                    CATLONG32               & nbControlPointsPerCurve,
                                    CATListOfDouble         & oParamOfCps            ,
                                    CATListOfInt            & oCrvIndexOfCps         );
    void        ParamAnalysisOfTheLongitudinalSweepSurfaces();
    void        ParamAnalysisOfTheTransversalSweepSurfaces();

    void        CurvesContinuityAnalysis();
    void        SurfacesContinuityAnalysis();  

    void        ContinuityAnalysisOfASetOfCurves(CATLONG32                      nbCCVs,
                                                 CATFrFCompositeCurve        ** CCVs,
                                                 CATTransitionDeviationResult * maxDiscontinuitiesOnCCVs,
                                                 CheckerPositionResult        * maxDiscontinuitiesPositionsOnCCVs,
                                                 CATLONG32                    * orientations);

    // iSize = 0 pour les isopares en v (longitudinal) et 1 pour les isopares ne u (transversal) .
    void        InternalContinuityAnalysis(      CATLONG32                     iSide       ,
                                                 CATLONG32                     nbCurves, 
                                                 CATSurface                 ** leftSurfaces,
                                                 CATSurface                 ** rightSurfaces,
                                                 CATLONG32                   * iLeftOrn,
                                                 CATLONG32                   * iRightOrn,
                                                 CATTransitionDeviationResult& maxDiscontinuitiesOnSurfaces,
                                                 CheckerPositionResult       & maxDiscontinuitiesPositionsOnSurfaces);

    void        CreateBoundary            (      CATLONG32                     iSideUV,    // 0 pour u, 1 pour v
                                                 CATLONG32                     iSideParam, // 0 pour le debut, 1 pour la fin
                                                 CATLONG32                     nbCurves,
                                                 CATSurface                **  surfaces,
                                                 CATFrFCompositeCurve       *& boundaryCCV,
                                                 CATLONG32                   & onbCps,
                                                 CATListOfDouble             & oParamOfCps,
                                                 CATListOfInt                & oCrvIndexOfCps);

#define CATFrFSweepCheckerShuntCoverage_LookForSidesToMerge
#ifndef CATFrFSweepCheckerShuntCoverage_LookForSidesToMerge
    void         LookForSidesToMerge(      CATLONG32   iSide       ,
                                     const CATSurface* leftSurface ,
                                     const CATSurface* rightSurface,
                                           CATLONG32 & ioReverse   ,
                                           CATLONG32 & ioSideLeft  ,
                                           CATLONG32 & ioSideRight );
#endif

    void         ComputeParamForBorderChecker(CATFrFCompositeCurve * iCcv                         ,
                                              int                    inbPointsPerCurve            ,
                                              CATListOfDouble      & oPointsParamWhereToComputeDev,
                                              CATListOfInt         & oIndexAssociatedToParam      );

    //MNA 04/11/03 : Methode permettant de faire un AddRef sur tous les points de CATTransitionPositionResult
    void         AddRefMaxDevPoint           (CheckerPositionResult & ioDevResult);

    //MNA 04/11/03 : Methode permettant de faire un Release sur tous les points de CATTransitionPositionResult
    // suivi eventuellement d'un Remove (NLD08/02/05)
    void         ReleaseRefMaxDevPoint       (CATTransitionPositionResult & ioDevResult,
                                              int                           iRemove    = 0);

    void         FinalReleaseRefMaxDevPoint  (CheckerPositionResult & ioDevResult ) ;
    void         FinalReleaseRefMaxDevPoints (CATLONG32              iNbPositions ,
                                              CheckerPositionResult * ioPositions );


    // rend l'index de domaine d'un profil, commencant a 0
    // avec controle de validité et sortie en erreur eventuelle
    CATLONG32    GetProfileDomain            (CATLONG32               iIndexProfile) const;

    // Creation d'un point sur une courbe
    CATPoint   * ProtectedCreatePointOnCurve (CATCrvParam           & iCrvParam    ,
                                              CATCurve              * iCurve       ) ;

    // Accès à l'éventuelle courbe sous un point
    // et ajout eventuel de cette courbe aux courbes en erreur, avec en prime AddRef() sur la courbe
    CATCurve  * GetUnderLyingCurve(CATPoint* iPoint, CATBoolean iAddToErrorCurves=CATBoolean(0)) ;

    CATSoftwareConfiguration *     _SoftwareConfig;
    CATBoolean                     _Checker;
    CATBoolean                     _externalProfileDevAnalysis;
    CATBoolean                     _externalGuideDevAnalysis;

    CATLONG32 *                    _externalProfileDevAnalysisPossible; //est-ce que c'est coherent de faire une telle analyse en fonction du type de sweep???
    CATLONG32 *                    _externalGuideDevAnalysisPossible;

    CATBoolean                     _GuideParamAnalysis;
    CATBoolean                     _ProfileParamAnalysis;
    CATBoolean                     _internalDevAnalysis;
    CATBoolean                     _maxOffsetAnalysis;
    CATBoolean                     _maxGaussianCurvatureAnalysis;
    double                         _MaxGaussSurParam[2];
    CATMathPoint                   _MaxGaussPoint;

    CATBoolean                     _GlobalExternalAnalysis;
    CATBoolean                     _GlobalInternalAnalysis;

    CATLONG32                      _IsInternalDevAnalUpToDate;
    CATLONG32                      _IsProfExternalDevAnalUpToDate;
    CATLONG32                      _IsGuideExternalDevAnalUpToDate;
    CATLONG32                      _IsMaxOffsetAnalUpToDate;
    CATLONG32                      _IsGuideParamAnalUpToDate;
    CATLONG32                      _IsProfParamAnalUpToDate;
    CATLONG32                      _IsGaussianCurvatureAnalUpToDate;


    CATTransitionDeviationResult * _GuidesDev;
    CheckerPositionResult        * _GuidesPos;

    CATTransitionDeviationResult * _ProfilesDev;
    CheckerPositionResult        * _ProfilesPos;

    CATLONG32                      _nbGuideSupports;
    CATLONG32                    * _continuityGuideIndex;
    CATLONG32                      _guideSuppCtr;
    const CATMathVector         ** _guideNormalSupports;

    CATLONG32                      _SmoothOption;
    CATAngle                       _SmoothAngleThreshold;

    CATLONG32                      _CleanOption;
    double                         _CleanTolDeformationOnGuide;
    double                         _CleanTolDeformationOnProfile;

    double                         _GuideApproxTolerance;
    double                         _ProfileApproxTolerance;
    double                         _GlobalApproxTolerance;

    CATLONG32                      _UnTwistMode;
    CATBoolean                     _IsThereExtrapolatedVertices;
    CATLONG32                    * _ExtrapolatedVertices;

    int                            _ModeOfPackCrvInCCvProfile;
    int                          * _PackCrvInCcvProfile;

    double                       * _MaxGapBetweenGuideAndProfile;    //-> MNA
    CATMathPoint                 * _IndicePositionMaxGapOnGuide;     //-> MNA
    CATMathPoint                 * _IndicePositionMaxGapOnProfile;   //-> MNA

    // continuites internes sur les guides - avec leurs positions
    CATTransitionDeviationResult * _maxDiscontinuitiesOnTheGuides;
    CheckerPositionResult        * _maxDiscontinuitiesPositionsOnTheGuides;

    // continuites internes sur la spine avec leur position
    CATTransitionDeviationResult * _discontinuitiesOnTheSpine;
    CheckerPositionResult        * _discontinuitiesPositionsOnTheSpine;

    // continuites internes sur les profiles - avec leurs positions
    CATTransitionDeviationResult * _maxDiscontinuitiesOnTheProfiles;
    CheckerPositionResult        * _maxDiscontinuitiesPositionsOnTheProfiles;

    // continuites internes sur les surfaces dans le sens des guides
    // - avec leurs positions
    CATTransitionDeviationResult * _maxUDiscontinuitiesOnSurfaces;
    CheckerPositionResult        * _maxUDiscontinuitiesPositionsOnSurfaces;

    // continuites internes sur les surfaces dans le sens des profiles
    // - avec leurs positions
    CATTransitionDeviationResult * _maxVDiscontinuitiesOnSurfaces;
    CheckerPositionResult        * _maxVDiscontinuitiesPositionsOnSurfaces;

    //MNA j'ajoute les donnees membres relatives aux PCurvesError a rendre pour
    //la remontee de diagnostic, et gestion des Warning.

    CATLONG32                      _NbWarning;
    CATLONG32                      _IndexOfWarning;
    // NLD270504 je passe par un #define pour aider analyseur de syntaxe de Sniff 
    #define CATFrFSweepChecker_ListPOfCATCurve CATLISTP(CATCurve)
    CATFrFSweepChecker_ListPOfCATCurve   *         _ListOfCurveError;
    CATListOfInt                   _ListOfDiag;

    // maxOffsets positifs et negatifs
    double                         _negativeMaxOffset;
    double                         _positiveMaxOffset;

    CATLONG32                      _negativeMaxOffsetSurfaceTag;
    CATLONG32                      _positiveMaxOffsetSurfaceTag;

    double                         _MaxAbsGaussianCurvature;
    CATLONG32                      _MaxAbsGaussianCurvatureSurfaceTag;
    //MNA -> Special Loft Ajout du profil implicite pour les cas degeneres(via operateur geom)
    CATFrFCompositeCurve         * _ImplicitProfile;
    //MNA 07/11/03 -> Cas ou on a cree un profil implicite pour le SweepBirail on le detruit
    CATBoolean                     _RemoveImplicitProfile;



};

#endif
