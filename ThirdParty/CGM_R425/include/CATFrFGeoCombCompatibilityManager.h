// COPYRIGHT DASSAULT SYSTEMES 2000
//==========================================================================
//
// Objet de mise en compatibilité des FrFComb 
// (normales et derivees croisees) entre 2 peignes ou plus.
// ATTENTION : - TOUS LES Rank COMMENCENT A 1 !
//==========================================================================
//   /04/00 NDN Creation
//   /11/01 MNA Modifications:
//              - Ajout de la methode EvalForcross : permet l'evaluation des derivees d'ordre 1 et 2
//                pour tout type de peigne,
//              - Ajout d'argument dans la methode Eval.
// 17/01/03 mna Ajout SetNoCompatOnComb()
// 07/08/03 mna Ajout _CGMLevel, ajout argument iSoftwareConfig aux constructeurs
//   /09/03 LVL Ajout GetCrossDerivative
// 26/11/09 JSX On renomme _Config en _JunctionCont
//              on passe une grosse partie des fonctions en Private
//              on ne fait plus joujou avec _Ind, une donnée membre n'est pas un indice de boucle
//              Ajout de l'argument idComb necessaire a certaines fonctions
// xx/02/10 JSX LoftG2 : Ajout de TargetSecondDerivative
// 01/12/11 NLD Ajout CATFrFGeoCombCompatibilityManagerIndexComputer()
// 20/12/11 NLD Suppression de SetSoftwareConfiguration() qui est bancale depuis le 07/08/03
//              et fort heureusement n'est pas utilisée
// 28/05/13 NLD _Fact devient _Factory
// 19/06/13 NLD Smart indent
// 20/06/13 NLD Revue, homoheneisation et clarification des notations;
//              - iRankOfComb      remplace iIndexOfComb      dans SetPriority() 
//              - iRankOfCrvInComb remplace iIndexOfCrvInComb dans le constructeur
//              la - toutefois meritoire - notation idComb (JSX041209) est remplacee apres verification dans tous les cas,
//              en argument par iRankOfComb     pour les methodes traitant un peigne 
//                          par iRankOfJunction pour les methodes traitant la jonction entre un peigne et le suivant
//              dans
//                - ComputeTargetNormal(), 
//                - TargetNormalCompatibility()
//                - ComputeTargetCrossDerivative()
//                - CrossDerivCompatibility()
//                - ComputeTargetSecondDerivative()
//                - HasCombCrossDerivTobeUpdated()
//              - iAtEnd remplace iWhere et AtEnd
// 26/08/22 JSX BoundarySurface : Ajout SetSwapUVMode et argument duV a SetDirection
//==========================================================================
#ifndef CATFrFGeoCombCompatibilityManager_H
#define CATFrFGeoCombCompatibilityManager_H

//---------------------------------------------------------------------------------------------------

#include "FrFOpeCrv.h"

class CATFrFMultiComb;
class CATCrvParam;
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATFrFGeoCombCompatibilityManagerIndexComputer;


#include "CATMathDirection.h"
#include "CATCGMVirtual.h"

//--------------------------------------------------------------------------
class ExportedByFrFOpeCrv CATFrFGeoCombCompatibilityManager : public CATCGMVirtual
  {
    //--------------------
    // General rules:
    //--------------------
    // - an integer iRank* variable is numbered starting at 1 

  friend class CATFrFGeoCombCompatibilityManagerIndexComputer;

  private: // Protection
    CATFrFGeoCombCompatibilityManager();
    CATFrFGeoCombCompatibilityManager(const CATFrFGeoCombCompatibilityManager &);
    void operator =                  (const CATFrFGeoCombCompatibilityManager &);

  public:
    //--------------------
    // Constructor
    //--------------------
    //                                                                                          // iRankOfCrvInComb et iParamOfCrvInComb
    //                                                                                          // sont dimensionnes a        [2*(iNbComb-1)]
    //                                                                                          // et decrivent chaque point de connexion 
    //                                                                                          // (en nombre (iNbComb-1) donc)
    //                                                                                          // par ses coordonnees (rang, parametre)
    //                                                                                          // au sein du peigne gauche
    //                                                                                          // puis au sein du peigne droit
    //                                                                                          // d'ou le dimensionnement    [2*(iNbComb-1)]
    //                                                                                          // qu'il faudrait voir plutot [2][(iNbComb-1)]
    //                                                                                          // d'apres analyse du code et des appelants, NLD200613
    CATFrFGeoCombCompatibilityManager(      CATGeoFactory      * iFactory             ,
                                            CATLONG32            iNbComb              ,
                                            CATFrFMultiComb   ** iCombToUpdate        ,
                                      const CATLONG32          * iRankOfCrvInComb     ,         // [2*(iNbComb-1)]
                                      const CATCrvParam        * iParamOfCrvInComb    ,         // [2*(iNbComb-1)]
                                      CATSoftwareConfiguration * iSoftwareConfig      = NULL );

    //--------------------
    // Destructor
    //--------------------
    virtual ~CATFrFGeoCombCompatibilityManager();


    //--------------------
    // Set
    //--------------------

    //iPriority =  0 -> lowest priority                                     i.e. maximum deformation ,
    //iPriority =  1 -> priority with respect to combs with a iPriority = 0 i.e. minimum deformation.
    //iPriority = -1 -> No deformation at all.
    void      SetPriority                  (CATLONG32            iRankOfComb,
                                            CATLONG32            iPriority            = 1);
    // Swap UV mode to work on a corner of a surface ( BoundarySurafec Project) 
    void      SetSwapUVMode(                CATLONG32            iRankOfComb );

    // Set Maximum Angular deformation  (radian)
    // if the computed laws implie a greater deformation, then nothing will be done.
    void      SetTolerance                 (double               iAngularTolerance);

    // Set the order you want to reach (C1 = 1 , C2 = 2).
    // (NLD030714 ?? = 3, voir JSX, appel depuis CATFrFExtractCombForSweep::ComputeCompatibilityProfileGuide())
    void      SetOrderOfCompatibility      (CATLONG32            iOrder);

    // permet d'indiquer si on a une MEC possible en debut ou fin de Comb : 0: no MEC, 1: MEC
    // (N.B fournir 2 valeurs par peigne NLD1906313)
    void      SetNoCompatOnComb            (CATLONG32         *  iNoCompatOnComb);

    //NLD201211 méthode foireuse void SetSoftwareConfiguration(CATSoftwareConfiguration * iSoftwareConfig);
    //---------------------------------
    // Get (LVL)
    //----------------------------------
    int       GetCrossDerivative           (CATMathVector      & oCross);

    //--------------------
    // Run
    //--------------------
    int       Run();


  private:
    // Fill and Check Data. Call the next methods.
    int       FillAndCheckData             ();
    int       ComputeEdgeContinuity        ();
    void      ComputeDefaultAngleTol       ();

    // For G1
    CATLONG32 ComputeTargetNormal          (CATLONG32            iRankOfJunction,
                                            CATMathDirection   & oNormal        );

    void      TargetNormalCompatibility    (CATLONG32            iRankOfJunction,
                                            CATMathDirection   & iNormal        );

    // For G2
    CATLONG32 ComputeTargetCrossDerivative (CATLONG32            iRankOfJunction,
                                            CATMathVector      & oDuv1          ,
                                            CATMathVector      & oDuv2          ,
                                            CATMathVector      & oDuv           );

    void      CrossDerivCompatibility      (CATLONG32            iRankOfComb    ,
                                            CATMathVector     *  oDuv1          ,
                                            CATMathVector     *  oDuv2          );

    CATLONG32 ComputeTargetSecondDerivative(CATLONG32            iRankOfJunction,
                                            CATMathVector      & oDuu1          ,
                                            CATMathVector      & oDvv1          ,
                                            CATMathVector      & oDuu2          ,
                                            CATMathVector      & oDvv2          );



    // TRUE if the comb is non modifiable.
    CATBoolean FixedComb                   (CATLONG32            iRankOfComb    ,
                                            CATLONG32            iAtEnd         );
    
    // To know if the considered border is free i.e nothing to do on it. Rank start from 1.
    CATBoolean IsFreeBorder                (CATLONG32            iRankOfComb    ,
                                            CATLONG32            iAtEnd)        ;
    // To know if there is a C0 Gap between two combs
    CATBoolean IsThereAGap                 (CATLONG32            iRank1         ,
                                            CATLONG32            iRank2         );

    // Cette methode permet de savoir si on effectue un update des peignes en prenant
    // en consideration les nouvelles derivees croisees ou si compte tenue des faibles
    // deviations il est inutile d'effectuer cet Update:
    //              - 1 : il faut faire un update et prendre en consideration les
    //                nouvelles derivees
    //              - 0 : il est inutile de faire un Update.
    //
    // Le parametre iAtEnd permet de savoir si on evalue la derivee croisee au debut (0), ou en fin de peigne.

    CATLONG32 HasCombCrossDerivTobeUpdated (CATLONG32            iRankOfComb    ,
                                            CATLONG32            iAtEnd         ,
                                      const CATMathVector      & iDir           );

    void      SetAngularTolerance          (double               iAngularTol    );

    // To evaluate a comb 
    //  iAtEnd = 1 -> eval at the end   of the comb,
    //  iAtEnd = 0 -> eval at the start of the comb.
    void      Eval                         (CATLONG32            iRankOfComb    ,
                                            CATLONG32            iAtEnd         ,
                                            CATMathPoint      *  Pt             ,
                                            CATMathVector     *  DU             = NULL,
                                            CATMathVector     *  DV             = NULL,
                                            CATMathVector     *  DUV            = NULL,
                                            CATMathVector     *  DUU            = NULL,
                                            CATMathVector     *  DVV            = NULL);

    void      EvalForCross                 (CATLONG32            iRankOfComb    ,
                                            CATLONG32            iAtEnd         ,
                                            CATMathPoint      *  Pt             ,
                                            CATMathVector     *  DU             = NULL,
                                            CATMathVector     *  DV             = NULL,
                                            CATMathVector     *  DUV            = NULL,
                                            CATMathVector     *  DUU            = NULL,
                                            CATMathVector     *  DVV            = NULL);

    void      EvalNormal                   (CATLONG32            iRankOfComb    ,
                                            CATLONG32            iAtEnd         ,
                                            CATMathDirection  *  N              ,
                                            CATMathVector     *  DNU            = NULL,
                                            CATMathVector     *  DNV            = NULL);

    // To set direction on a comb extremity.
    void      SetDirection                 (CATLONG32            iRankOfComb    ,
                                            CATLONG32            iAtEnd         ,
                                      const CATMathVector      & iDirV          ,
                                      const CATMathVector      & iNormal        ,
                                      const CATMathVector      * iDirU          );

    
//=========================================================================================
// DATA
//=========================================================================================
  protected:

    // Input Data
    CATGeoFactory              * _Factory;
    CATSoftwareConfiguration   * _SoftwareConfig;
    short                        _CGMLevel;

    CATLONG32                    _NbComb;
    CATFrFMultiComb           ** _MultiComb;
    int                        * _RankOfCrv;
    CATCrvParam                * _ParamOfCrv;

    // Options
    double                       _CosTol;
    double                       _AngularTol;
    CATLONG32                  * _TabOfMECPossible;  // 0 : pas de MEC / 1:Mise En Compatibilité. // savoir si on fait une MEC en debut et fin de Comb:    
    CATLONG32                  * _Prior;
    CATLONG32                    _Order;             // Max order to reach : 1->C1 (Normal , 2->C2 (Cross-Deriv compatibility)
    CATLONG32                  * _NormalMode;        // 0 :tangent comb (default) / 1 :normal comb / 2 :swapUV

    // Internal
    CATLONG32                  * _JunctionCont;      // Continuite de la jonction. (Jonction C0 ou G1)
 //    private:

  }; 
#endif
