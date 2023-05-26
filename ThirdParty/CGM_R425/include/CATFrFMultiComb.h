// COPYRIGHT DASSAULT SYSTEMES 2000
//==========================================================================
//
// Objet d'extraction de peignes sur une liste de courbes. 
// 
//==========================================================================
// 
// Pour chaque courbe posee sur un fond, et si l'on veut une continuite G1 du peigne avec ce fond, 
// il faut egalement passer la Surface.
// Dans le cas ou l'on veut un peigne libre (courbe 3D ou PCurve sur laquelle on ne veut pas une 
// continuite G1), le pointeur sur la Surface associe doit etre a NULL.
// Les courbes libres, i.e sans fond, doivent avoir en chaque extremite soit une courbe posee sur un fond, 
// soit un vecteur direction impose.
// Dans tous les cas pour lever l'ambiguite quant a la courbe qui va etre utilisee, la methode
// SetCurveForAnCurve (????) permet de preciser la courbe geometrique a prendre pour une courbe donnee.
//
// Une liste d'orientations doit etre fournie, qui pour chaque courbe donne son orientation au
// sein de la liste et telle que la liste soit orientee positivement (+1) de la premiere courbe
// jusqu'a la derniere.
//
// La direction de G1 par defaut du peigne est le produit vectoriel de la tangente de la courbe, composee
// avec l'orientation de courbe dans la liste, et avec la normale a la Surface dans les cas de courbes posees, 
// et via une loi definie par les vecteurs imposees et/ou les courbes adjacentes dans les cas de courbes libres.
//
// Toutes les courbes ont une orientation +1 pour leur peigne initialement. Au moment de l'update une
// orientation est attribuee a chaque peigne pour garantir le C0 entre les peignes, la premiere courbe
// donnant l'orientation +1. InvertMultiCombOrientation permet d'inverser a tout moment le peigne entier.
//
// L'utilisateur peut, et doit dans certains cas, definir un ensemble de directions en un certain nombre
// de point sur sa liste de courbes.
//
// ATTENTION : - Tous les rangs (iRank*)  commencent a 1
//               mais les       (iIndex*) commencent a 0
//               (C'est cela oui. Plus ou moins vrai. Vrai a partir du 260413)
//
//             - Deux courbes consecutives doivent etre adjacentes.
//
//             - On ne peut definir deux directions sur un meme vertex.
//=======================================================================================================
//   /04/00 NDN Creation
//   /11/01 MNA Modifications :
//               - Ajout de la methode SetLocalisation qui permet de localiser 
//                 la deformation induite par une modification de peigne. 
//               - Ajout de la methode SetAdvancedLocalization qui permet de preciser le peigne 
//                 sur lequel on veut effectuer une localisation globale. 
//                 !  (merci pour tes notations foireuses dans RemoveAdvancedLocalization(), ActivateAdvancedLocalization()
//                 !  correction iIndex en iRank le 26/04/13;
//                 !  par ailleurs ce n'est pas SetLocalisation() mais ActivateLocalization())
//               - Ajout du tableau _ArrayOfCrossDerivExt qui permet de  stocker les informations 
//                 concernant les derivees croisees a imposer.
//               - Mise a jour de la methode SetCrossDerivative :L'Update est fait dans la methode ComputeLaw
//                 contrairement a l'ancienne methodologie ou le calcul des lois (longueur, direction, angle)
//                 etait calculee directement dans la methode Set CrossDerivative.
//               - Ajout de la donne membre _ArrayOfCrossDerivExt ou je stocke les informations des nouvelles 
//                 derivees croisees dans le run.
//   /01/02 MNA Modifications :  
//               - Mise en place de la nouvelle localisation de la deformation
//              Methodes ajoutees :
//               - IsLocalizeDefNecessary permet de verifier la
//                 pertinance de la localisation de la deformation.
//                 (merci pour tes notations foireuses. correction iIndex en iRank le 25/04/13)
//               - ComputeLimitConditionsOnLaw permet la prise en compte
//                 des conditions aux limites a appliquer a la loi de 
//                 deformation.
//               - ComputeLocalizedDefLaw permet le calcul d'une loi de def
//                 localisee.
//               - Mise a jour de la methode de la loi de deformation.
//                 Ajout de methode Set et Get SetTolForLawDef et SetLevelForAdvancedDefCompute
//                 elles permettent de preciser la tolerance pour le calcul de la loi de 
//                 deformation localisee (MODE AVANCE), et d'activer le mode de localisation avancee. 
// 07/01/03 MNA Ajout de la methode SetNoCheckOfSensOfDir (CATLONG32 iIndex)
//              Desactive la verif du sens des direction passee entre la fin 
//              du comb i et le comb i+1. (Cette verif n 'a pas lieu d'etre 
//              si elle eest effectuee par l'appelant et surtout dans les cas 
//              de Comb C0 avec un angle > 90.) (_NoCheckOfSensOfDir)
// 10/01/03 MNA Ajout de la methode SetIsoparMode qui permet de piloter un mode ou on construit
//              comme direction privilegiee l'isopar transverse de la surface.
// 15/01/03 MNA Ajout de la methode EvalDirectionForG1.
// 12/02/03 NDN Pilotage de la correction C0.
// 05 08 05 JSX Ajout de SetGlobalLaw
// 04/11/05 NLD On derive de CATFrFObjectVirtual au lieu de CATCGMVirtual 
//              Ajout de iConfig dans le constructeur
// 27/02/07 NLD Migration vers CATFrFObject au lieu de CATFrFObjectVirtual
// 02/12/09 JSX Add Direction in Set3DCombCreationOption
// 16/02/10 JSX Ajout de iGlobalLawOfDerNormsOnV dans le constructeur pour les lofts G2 
//              Nouvelles Methodes: SetCrossG2Law / ComputeDataForCrossG2Law / ComputeLaw_CrossG2Law
//              Données supplementaires _TabOfNewCrossG2Norm _ArrayOfCrossG2NormExt _GlobalLawOfDerNormsOnV
// 13/10/10 JSX Ajout des lois d'imposition de la courbure (sur la normal uniquement)
// 04/11/10 JSX SetG2Law remplace SetCrossG2Law et SetNormalG2Corr
//              (voir 25/04/13 pour parametrisation)
// 30/11/12 NLD Ajout _TolObject pour eviter les acces repetes a CATGetTolerance(GetFactory())
// 25/04/13 NLD Ajout Init() et CreateCombs()
//              SetCrossG2Law() recoit un type de loi par une enumeration typee G2LawType
// 26/04/13 NLD Mise au propre: reindentation complete
//              Controle des micmacs de notations (iIndex / iRank) dans interfaces et implementations et corrections
//              des interfaces de
//              - IsLocalizeDefNecessary(), SetG2Law()
//              - RemoveAdvancedLocalization(), ActivateAdvancedLocalization()
//              Les methodes recevant reellement des index sont: (j'indique [EXT] pour appels externes, [INT] pour methodes internes)
//              [EXT] SetNoCheckOfSensOfDir(), *SetIsoparMode(), SetRemoveC0Correction(),
//              [INT] ComputeDataForCross*()
//              Ajout _Debug et classe CATFrFMultiCombDebug
//              Ajout ComputeLaw_CreateSplineLaw()
// 29/04/13 NLD _GlobalLengthLaw remplace _GlobalLaw
//              SetGlobalLaw(), SetTolForLawDef(), GetTolForLawDef() passent de l'interface dans l'implementation
//              Ajout _FakeConnectionNumbers, _FakeConnectionNumbersComputed, ComputeFakeVertices()
//              Ajout _FakeConnectionTreatment et SetFakeConnectionTreatment()
// 25/08/22 jsx Ajout de ForceLocalLawForBoundarySurface. Probablement a revoir (ce n'est peut etre pas necessaire)
//=========================================================================================================
#ifndef CATFrFMultiComb_H
#define CATFrFMultiComb_H

#include "FrFOpeCrv.h"
#include "CATMathSetOfPointsND.h"
#include "CATMathVector.h"
#include "CATListOfInt.h"
#include "CATFrFObject.h"
#include "CATTolerance.h"
#include "CATThrowForNullPointer.h"

class CATMathVector;
class CATMathPoint;
class CATMathDirection;
class CATMath3x3Matrix;
class CATCurve;
class CATSurface;
class CATCrvParam;
class CATGeoFactory;
class CATFrFComb;
class CATLaw;
class CATCrvLimits;
class CATSplineLaw;
class CATSoftwareConfiguration;
class CATFrFMultiCombDebug;
//--------------------------------------------------------------------------
class ExportedByFrFOpeCrv CATFrFMultiComb : public CATFrFObject
  {
  
    friend class CATFrFMultiCombDebug;

  public:
    //--------------------
    // Constructor
    //--------------------
                        CATFrFMultiComb(      CATGeoFactory           * iFactory                ,
                                              CATSoftwareConfiguration* iConfig                 ,
                                        const CATCurve               ** iCrv                    ,
                                        const CATCrvLimits            * iLim                    ,
                                              CATLONG32               * iCont                   ,
                                        const CATListOfInt            * iListOfOrn              ,
                                              CATBoolean                i3DMixMode              = FALSE, 
                                              CATLaw                  * iGlobalLawOfNorms       = 0,
                                              double                  * iParamsForLaw           = 0,
                                              CATLaw                  * iGlobalLawOfDerNormsOnV = 0);

    //--------------------
    // Destructor
    //--------------------
    virtual            ~CATFrFMultiComb();

    //--------------------
    // Set && Get
    //--------------------
    // if iNorm>=0, then iDir is normalized and the final direction will have a norm equal to iNorm.
    virtual void        SetDirection      (CATLONG32 iRankOfCurve,  const CATCrvParam &iParam, const CATMathVector &iDir, double iNorm = -1.0);
    // To impose cross derivative.
            void        SetCrossDerivative(CATLONG32 iRankOfCurve,  const CATCrvParam &iParam, const CATMathVector &iDir);

    // To impose G2 derivative.
    //                              Attention le type de iType semble etre partage avec CATFrFNormalMultiComb. NLD250413
          typedef enum {G2ForNormalLaw = 1,
                        G2ForCrossLaw  = 2,
                        G2ForBothLaw   = 3} G2LawType;

            void        SetG2Law          (      CATLONG32      iRankOfCurve,
                                           const CATCrvParam  & iParam,
                                                 G2LawType      iType,                 /* CATLONG32 iKind */
                                                 double         iNormalG2Correction,
                                           const CATMathVector &iDir);

            void        SetNoCheckOfSensOfDir (CATLONG32 iIndex);
            void        SetNormalize          (CATLONG32 iNormalize);

    // SetNormalModeOption : Default is No/0. If you want to create normal combs instead of tangent combs.
           void         SetNormalModeOption(CATBoolean iYesNo = TRUE);
           CATBoolean   GetNormalModeOption();

    // To close the set of Curves i.e. the last and the first Curve are adjacent.
           void         SetIsClosed();
           CATBoolean   IsClosed();

    // Set3DCombCreation. Default is No/0. If you want to create a comb on 3D Curves.
    //                   PlaneNormal : Direction of the extrude build on the crv of the comb
    //                                 ativate only in case of NomalComb. 
           void         Set3DCombCreationOption(CATBoolean iYesNo = TRUE, CATMathVector *PlaneNormal = NULL);
           CATBoolean   Get3DCombCreationOption();

    // Dialog method.
     const CATSurface * GetCurveAndSurface(CATLONG32 iRankOfCurve, const CATCurve *& oCurve, CATCrvLimits * iLim=0);

    // ISOPAR  
    // Ce mode ne doit etre utilise que lorsque l'on se place dans un contexte CATFrFComb (PCurve....) Pas de 3DComb, ni de 3DDmixComb.
    //                        documentation tardive du mode. NLD250413
    //  = 0 : standard
    //  = 1 : iso U
    //  = 2 : iso V
            void       SetIsoparMode    (CATLONG32 iIndex, CATLONG32 iType = 0);
    // Ce mode ne doit etre utilise que lorsque l'on se place dans un contexte CATFrFComb (PCurve....) Par defaut,
    // Lorsque j'enleve le mode Isopar, je construit un CATFrFComb (voir precedemment le cadre d'utilisation)
            void       RemoveIsoparMode (CATLONG32 iIndex);
            CATLONG32  GetIsoparMode    (CATLONG32 iIndex);

    // LOCALIZATION
    // To remove localization of the deformation.
            void       RemoveLocalization();
    // To Set localization of the deformation.
            void       ActivateLocalization();
            void       RemoveAdvancedLocalization  (CATLONG32 iRankOfCurve);
    // Activation du mode de localisation de la deformation, uniquement sur le peigne sur lequel on veut localiser l'info.
            void       ActivateAdvancedLocalization(CATLONG32 iRankOfCurve);
            CATBoolean GetLocalizationOption();

    // Activation du mode analyse/traitement des fausses connexions
    virtual void       SetFakeConnectionTreatment();

    // CORRECTION
    // AngleMax en dessous duquel on corrige automatiquement le peigne en C0 (angle en radian).
            void       SetC0AngleThreshold(double iMaxAngleForRepairing);
    // Define connexion where you don't want any C0 correction.
    // Connexion "iIndex" is between iIndex and iIndex+1, iIndex starting from 0. 
    // On closed comb, closure connexion correspond to iIndex=NbElementsInComb. 
    // Default is alway repair.
    // WARNING : if there is any incompatibility between this option and SetC0AngleThreshold option on a connexion, no
    // C0 repair will be done.
            void      SetRemoveC0Correction(CATLONG32 iIndexOfConnexion);

    // Methodes qui permettent de fixer (resp. recuperer) la Tolerance pour la loi de deformation.
            void      SetTolForLawDef(double iTolForLawDef)  ; // NLD290413 {_TolForLawDef = iTolForLawDef;}
            double    GetTolForLawDef()                      ; // NLD290413 { return _TolForLawDef;  }

    // Permet d'activer le calcul de la loi de deformation localisee avancee.
            void      SetLevelForAdvancedDefCompute();
            void      RemoveLevelForAdvancedDefCompute();

    //--------------------
    // After any set and before any eval methods
    //--------------------
    virtual void      UpdateComb();
    virtual CATLONG32 Check();

    //--------------------
    // Eval methods
    //--------------------
    virtual void      EvalPoint            (CATLONG32 iRankOfCurve, const CATCrvParam &iParam, CATMathPoint &iPt);
    virtual void      EvalDirectionForG1   (CATLONG32 iRankOfCurve, const CATCrvParam &iParam, CATMathVector *iFirstDerivDirForG1);
    virtual CATLONG32 EvalFirstDerivatives (CATLONG32 iRankOfCurve, const CATCrvParam &iParam, CATMathVector *iDu,  CATMathVector *iDv);
    virtual void      EvalSecondDerivatives(CATLONG32 iRankOfCurve, const CATCrvParam &iParam, CATMathVector *iDuu, CATMathVector *iDuv, CATMathVector *iDvv);

    // This method returns a rc (i.e. Return Code) if one of the two (or the twice) vectors evaluate is nul:
    //               - rc =1 if Du is nul - rc =2 if Dv is nul    - rc =3 if the twice (Du and Dv) are nul.
    virtual CATLONG32 EvalNormal           (CATLONG32 iRankOfCurve, const CATCrvParam &iParam, CATMathDirection &iDir);

    // This method return a Rc (return code) if the normalDerivative couldn't been evaluated (i.e. Norme < CATEpsg)  
    virtual CATLONG32 EvalNormalDerivative (CATLONG32 iRankOfCurve, const CATCrvParam &iParam, CATMathVector * iDerDirU, CATMathVector * iDerDirV);

    //--------------------
    // Change Direction.
    //--------------------
    // Invert the direction used for G1.
            void      InvertMultiCombOrientation();
    // Invert orientation of the list of curve.
            void      InvertCurvesOrientation();
    // To set support orientation for each comb. NewOrn=1 or -1.
            void      SetCombOrientation(int iRankOfCurve,int NewOrn);


    //--------------------
    // To get maximal angular deformation. The result is expressed in radian.
    //--------------------
            double    GetAngularDeviation();
            double    GetAngularDeviation(CATLONG32 iRankOfCurve,const CATCrvLimits *iLim=0);

    //--------------------
    // To get the continuity 
    // Returned values are -1 for C-1, 0 for C0 and 1 for G1 (iAngleContinuity is expresed in radian).
    // Check is done between iRankOfCurve, so -1 will be returned if iRankOfCurve==NumberOfCurves
    // except if this is closed.
    //--------------------
    // To get the continuity between the curves used by CATFrFCombs.
            CATLONG32 GetContinuityBetweenCurves(CATLONG32 iRankOfCurve, double iPointContinuity, double iAngleContinuity);
    //--------------------
    // To get the continuity between Combs .
            CATLONG32 GetContinuityBetweenComb  (CATLONG32 iRankOfCurve, double iPointContinuity, double iAngleContinuity);


    //--------------------
    // To get the number of comb.
            CATLONG32 GetNumberOfComb() const;

    //--------------------
    // To get one extremity of the comb according to orientation of the curve.
    // For iSide : Beginning=0 and End=1.
    //--------------------
            void      GetOneCombExtremity(CATLONG32 iRankOfCurve, CATLONG32 iSide, CATCrvParam &oParam) const;

    //--------------------
    // To work directly on the parametrization of The MultiComb.
    //--------------------
    // Largeur de l'espace parametrique du multicomb
            double    GetParametricSpace() const;
    // iSpecifiedRank specifies the considered curve in case of multiple choice.
    virtual void      FromGlobalToLocalParam(double        iGlobalParam   ,
                                             CATLONG32   & oRankOfCurve   ,
                                             CATCrvParam & oParamOnCurve  ,
                                             CATLONG32   * iSpecifiedRank = 0
                                            );
    virtual void      FromLocalToGlobalParam(                     CATLONG32 iRankOfCurve, const CATCrvParam &iParamOnCurve, double &oGlobalParam);

      const CATFrFComb * GetOneComb               (CATLONG32 iRankOfCurve) const;
            void      SetGlobalLaw                (int       iGlobalLengthLaw); // NLD290413    { _GlobalLengthLaw = iGlobalLengthLaw; }
            void      ForceLocalLawForBoundarySurface();
            CATBoolean GetForceLocalLawForBoundarySurface();

            void      Dump();

  protected:

                      CATFrFMultiComb(); // constructeur interdit

    // Permet de tester si la localisation de la deformation est necessaire ou non.
            CATBoolean IsLocalizeDefNecessary     (CATLONG32 iRank, double &iTol );
    // Permet de calculer les conditions aux limites de la loi en fonction des donnees d'entrees
    // ou des conditions aux limites existants sur l'ancienne loi.
            void       ComputeLimitConditionsOnLaw(CATSplineLaw *iPrevLaw,double *iStartTg, double *iEndTg, CATLONG32 *oTgDefine, double* oTgLaw);
    // Permet de calculer une loi avec localisation de la deformation.
            void       ComputeLocalizedDefLaw     (CATSplineLaw *& ioLawDefLocalize,CATLONG32 &iLocNbPt, double *iLocalParam, double *iLocalDirDef);
            void       CleanConstraints           ();
            void       ComputeTargetDirections    ();
            CATLONG32  ComputeDataForCrossDeriv   (CATLONG32 iIndexInArray, double &oDerL,       double &oDerA1      , double &oDerA2);
            CATLONG32  ComputeDataForCrossG2Law   (CATLONG32 iIndexInArray, double &oDerG2dirG1, double &oDerG2Cross);


  private :

            void       Init                     ();
            void       CreateCombs              (
                                                 const CATCurve**                iCrv                   ,
                                                 const CATCrvLimits*             iLim                   ,
                                                       CATLONG32 *               iCont                  ,
                                                       CATBoolean                i3DMixMode             ,
                                                       double*                   iParamsForLaw
                                                );
            void       ComputeOneDirection      (CATLONG32              iCurrRank ,
                                                 CATLONG32              iRefRank  ,
                                           const CATCrvParam          & iCurrParam,
                                           const CATCrvParam          & iRefParam);

            void       ComputeLaw               ();

            void       ComputeLaw_DirectionLaw  (CATLONG32              iRank   ,
                                                 CATMathSetOfPointsND & iParam  ,
                                                 CATMathSetOfPointsND & iAngle  ,
                                                 double               * StartTg = 0,
                                                 double               * EndTg   = 0);

            void       ComputeLaw_DeformationLaw(CATLONG32              iRank   ,
                                                 CATMathSetOfPointsND & iParam  ,
                                                 CATMathSetOfPointsND & iAngle  ,
                                                 double               * StartTg = 0,
                                                 double               * EndTg   = 0);

            void       ComputeLaw_LengthLaw     (CATLONG32              iRank   ,
                                                 CATMathSetOfPointsND & iParam  ,
                                                 CATMathSetOfPointsND & iAngle  ,
                                                 double               * StartTg = 0,
                                                 double               * EndTg   = 0);

            void       ComputeLaw_CrossG2Law    (CATLONG32              iRank,
                                                 CATMathSetOfPointsND & iParam,
                                                 CATMathSetOfPointsND & iCrosG2Tg,
                                                 CATMathSetOfPointsND & iCrosG2Cr,
                                                 double               * StartTg[],
                                                 double                * EndTg[]);
            void       ComputeLaw_GlobalLengthLaw(CATMathSetOfPointsND &iLength);

        CATSplineLaw* ComputeLaw_CreateSplineLaw(//CATLONG32            iRank   ,
                                                 CATSplineLaw        *  iPrevLaw,
                                                 CATMathSetOfPointsND & iParam  ,
                                                 CATMathSetOfPointsND & iValue  ,
                                                 double              *  StartTg ,
                                                 double              *  EndTg   );


    // utilitaire pour decouper une spline law globale aux limites d'un comb 
            CATSplineLaw *GetPieceOfLaw         (CATLONG32 iRank, const CATSplineLaw * iLaw);

            void       ComputeFakeVertices();

    // oStart may be superior to oEnd if Orientation is negative.
            void       GetLimitsForGlobalParam  (CATLONG32 iRankOfCurve, double &oStart, double &oEnd);

    //return 1 if a comb is degenerated i.e. the domain defined by its limits is smaller than the resolution.
            CATLONG32  IsDegenerated            (CATLONG32 iRankOfCurve);

    //if oIndStart and oIndEnd are equal to -1, this mean that there is no constraint on the comb.
            void       GetIndexesOfConstraints  (CATLONG32 iStartRankOfCurve, CATLONG32 iEndRankOfCurve,
                                                 CATLONG32 &oIndStart, CATLONG32 &oIndEnd, CATLONG32 &oInnerStart, CATLONG32 &oInnerEnd);

            void       CheckGlobalLaw();

    // determine si un comb est par lui meme deformable ou si 
    // la deformation doit etre faite par FrFComb
            CATBoolean IsActiveAngleLaw(int iIndexComb);

    //========================================================================================================
    // Data

  private:

    const CATTolerance&               _TolObject;
          CATFrFMultiCombDebug      * _Debug;
    // Options
          CATLONG32                   _IsUpToDate;                   // 0 (pas a jour) ou 1 (a jour)
          CATLONG32                   _IsClosed;                     // 0 (ouvert)     ou 1 (ferme)
          CATLONG32                   _Normalize;
          CATLONG32                   _Create3DComb;
          CATLONG32                   _GlobalLengthLaw;              // Creation d'une loi globale (i.e. 0 non, 1 oui).
          CATBoolean                  _ForceLocalLawForBoundarySurface_OnTEST;// flage permetatnt de forcele calcul d'un loi local. c'est necessaire pour la mise en compatibilite.
                                                                              // cela demande a etre mieux compris  

          CATLONG32                   _LocalizeDeformation;          // To localization the comb deformation (TRUE is default)
          CATLONG32                 * _AdvancedLocalizeDeformation;  // To LocalizeDeformation only on comb that need to be updated :
                                                                     // 0 No Localization / 1 means Localization.

          double                      _TolForLawDef;                 // Tolerance pour le calcul de la loi de deformation
          CATLONG32                   _LevelForAdvancedDefCompute;   // Niveau pour l'activation du calcul de la loi localisee avancee.

          CATLONG32                 * _NoCheckOfSensOfDir;           // Cette donnee membre me permet de savoir si les peignes sont C0 entre eux. 1=> C0, 0=>C1
          CATLONG32                 * _NoC0CorrectionOption;         // Permet de dire en une connexion donnee si l'on veut une correction ou pas.
                                                                     // Par defaut toutes les connexions sont rendues C0 (_NoC0CorrectionOption=0).

          double                      _LimitC0CorrectionAngle;       // Valeur par defaut = CATPI, i.e on corrige tout. REMARQUE IMPORTANTE : si
                                                                     // il y a contradiction entre cette valeur et le tableau precedent, on ne corrige pas.

    // Internal
          CATFrFComb               ** _Comb;                         // Les Combs
          CATListOfInt                _ListOfOrn;                    // Les Orientations

                                                                     // _ArrayOfDeriv and _ArrayOfDerivExt:
                                                                     //   (before) - Dim=4 : 0->GlobalParam , 1,..,3->Coordinates
                                                                     //   (now)    - Dim=5 : 0->GlobalParam , 1,..,3->Coordinates, Norm
          CATMathSetOfPointsND      * _ArrayOfDeriv;                 // To store Input    Direction 
          CATMathSetOfPointsND      * _ArrayOfDerivExt;              // To store Internal Direction

          CATLONG32                 * _TabOfNewCrossDeriv;           // To store if the crossDeriv  has been modified or not (0 No, 1 Yes).
          CATMathSetOfPointsND      * _ArrayOfCrossDerivExt;         // To store External creossderiv
          CATLONG32                 * _TabOfNewCrossG2Norm;          // To store if the crossG2Norm has been modified or not (0 No, 1 Yes).
          CATMathSetOfPointsND      * _ArrayOfCrossG2NormExt;        // To store External crossG2Norm
          CATListOfDouble           * _ArrayOfNormalG2Value;         // To store G2 value on normal direction

          double                      _ParamInter;                   // Largeur de l'espace parametrique du multicomb

          CATLaw                    * _GlobalLawOfNorms;             // Loi globale a detruire
          CATLaw                    * _GlobalLawOfDerNormsOnV;       // Idem
          //                                                         // Peigne defini par la normale a l'"extrude" de la courbe suivant une direction
          CATMathVector               _PlaneNormal;
          CATLONG32                   _PlaneNormalIsSet;

          //                                                         // Gestion des numeros de connexions factices
          //                                                         // (a recevoir de la topologie: connexions separant des courbes identiques avant clonage)
          //                                                         // ce sont des numeros de connexions. 1 pour celle entre le 1er et le 2eme peigne
          CATListOfInt                _FakeConnectionNumbers;
          int                         _FakeConnectionNumbersComputed;// indique si les numeros de connexions factices ont ete calcules
          int                         _FakeConnectionTreatment;
  };
 
#endif
