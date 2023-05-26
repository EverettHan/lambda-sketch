//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2002
//==========================================================================
//
// REMARQUE : CATFrFGeneralComb est defini sur [0,1] et est toujours normé (*).
//            Ceci, quelque soit l'echelle de la Factory
//       (*)  ==> Exceptions
//                - CAT3DTangentFunction (normé, mais en abscisse curviligne)
//                  SetScaleOption(0, 1) OK
//                - CATNormalSurfaceComb (normé, mais en abscisse curviligne)
//                  (peigne externe)
//                  SetScaleOption(0, 1) OK
//                - CATQsrNormalsComb    (normé, mais en abscisse curviligne) (au 240120)
//                  SetScaleOption(0, 1) A FAIRE

// _________________________________________________________________
//  Objet n'ayant pas vocation a etre derivé hors FreeFormOperators
// _________________________________________________________________
//
// Un peigne a trois états potentiels
// 1 - initial
// 2 - avec lois de déformation issues de CATCombCleaner (via CATCombImprovement)
//     renseignées via SetDeformationLaw()
//     (cas général; le CATFrFSmoothedComb éventuel est geré en externe)
// 3 - final avec un CATFrFSmoothedComb
//     renseigné   via SetFinalRepresentation()
//     (cas rare;    le CATFrFSmoothedComb est alors injecté dans le peigne lui-même)
//                                                   documentation NLD290519
//
// | Certainement faudrait-il définir et vérifier les règles d'appel
// | des différentes méthodes d'évaluation (intervalles paramétriques)
// | et peut-etre distinguer des notations différentes du paramètre, pour les familles
// | F1 - Eval(), EvalFirstDerivative(), EvalSecondDerivative()
// | F2 - EvalPointOnSupport(), EvalTgtOnSupport()
// | F3 - EvalLaw(), EvalFirstDerivativeLaw(), EvalSecondDerivativeLaw()
// | F4 - FinalEval(), FinalEvalFirstDerivative(), FinalEvalSecondDerivative()
// | et ce pour les différents états du peigne
//  - F1 et F2 fonctionnent clairement    avec le meme paramétrage (voir CATMeanTangentFunction, voir CATNormalSurfaceComb)
//  - F1 et F3 fonctionnent clairement    avec le meme paramétrage (voir                       , voir CATNormalSurfaceComb)
//  - F1 et F4 semblent fonctionner aussi avec le meme parametrage (voir CAT3DTangentFunction::Eval) et c'est heureux
//  - EvalFirstDerivative() et EvalSecondDerivative() sur cette classe mère
//    ne sont clairement appelables,
//    à cause de leurs tests aux bornes _MinParam et _MaxParam,
//    qu'après une définition cohérente
//    via SetDefinitionInterval() de l'intervalle d'évaluation s'il n'est pas le défaut [0, 1]
//   NLD240120
//
//==========================================================================
// Sept  02 NDN : Creation                                               NDN
// 27/02/07 NLD : Migration vers CATFrFObject au lieu de CATFrFObjectVirtual
// 10/01/08 JSX : Ajout GetCATMathAttrScaleOption
// 07/02/08 NLD : _ScalingBehavior devient _ScalingBehavior_Private et devient prive
//                Ajout de SetScaleOption(), _ScalePowerX, _ScalePowerF, _PoweredScaleX, _PoweredScaleF
//                GetCATMathAttrScaleOption() renommee GetScaleOption()
// 04/03/09 JSX : Ajout du mode FinalRepresentation afin de smoother les peignes de tangence des profils
//                Les methodes FinalEvalxxx sont necessaires aux classes filles (la methode Eval reste virtuelle pure)
// 05/04/13 NLD : Ajout _Debug
// 17/05/19 NLD : XScale: documentation du ScaleOption par défaut et du fonctionnement par défaut
// 21/05/19 NLD : Ajout SetSupportOrientation(), GetSupportOrientation(), _OrnSupport
//                (utilitaires de stockage seulement, au bénéfice des classes filles)
// 24/05/19 NLD : Definition des règles et hypothèses sur les orientations
// 28/05/19 NLD : Ajout EvalPointOnSupport() pour permettre l'accrochage et la visualisation du peigne
// 29/05/19 NLD : Recensement/controle des utilisations de lois de deformation dans les classes derivées
//                Documentation des mécanismes associés aux déformations
//                Documentaiton des trois états des peignes
// 22/01/20 NLD : Ajout _Support et SetSupport(), GetSupport() pour MWE et peignes QSR
//==========================================================================
#ifndef CATFrFGeneralComb_H
#define CATFrFGeneralComb_H

// #define CATFrFGeneralComb_MandatoryEvalPointOnSupport "EN COURS NLD280519"

#include "FrFObjects.h"
#include "CATFrFObject.h"
#include "CATMathDef.h"
#include "CATMathAttrScaleOption.h"

class CATMathInterval;
class CATLaw;
class CATMathVector;
class CATFrFSmoothedComb;
class CATFrFGeneralCombDebug;
//--------------------------------------------------------------------------
class ExportedByFrFObjects CATFrFGeneralComb :public CATFrFObject
{
  //==========================================================================
  // Constructor
protected:
                                  CATFrFGeneralComb           (      CATFrFObject * FrFObject       ,
                                                                     CATLONG32      iFirstLevelToSet);

public:  
  //==========================================================================
  // Destructor
  virtual                        ~CATFrFGeneralComb           ();
  
  // Duplicate
  // ---------
  // Remarques NLD200519
  // - gestion vraiment sujette à caution, et à expliciter;
  // - en l'état actuel, le Duplicate() est entièrement à la charge des implémentations dérivées
  //   dans les classes filles, inégalement programmées
  // - aucune de ces implémentations n'assure la duplication des données de lissage (_SmoothedComb, ...)
  //   on pourra d'ailleurs se reporter à mon bilan dans CATNewNormalFunction::Duplicate()
  //   mais en fait cela se tient si l'on considere que le Duplicate() n'est appelé que dans CATCombImprovementCx2
  //   donc avant que n'existent ces données
  // - son rôle n'est pas clair
  // - appel potentiel par CATCombImprovementCx2::ShiftToPeriodic()
  //   et, sur l'ensemble des odts sweep et blend,
  //   seulement sur les derivations CATNewNormalFunction et CATMeanTangentFunction
  //   il y a une protection par le caractère fermé des peignes mais potentiellement tout type de peigne
  //   peut etre fermé et recevoir son indicateur de fermeture
  // - pas d'appel en revanche dans le contexte du CombCleaner
  //   il faut dire que celui-ci est TOUJOURS sous CATCombImprovementCx2
  // BILAN
  // - il faut implementer cette méthode dans toutes les dérivations
  // - il faut le faire de manière versionnée
  virtual CATFrFGeneralComb     * Duplicate                   () const;

  //==========================================================================
  // Scale Behaviour
  //==========================================================================
  // Default:  PowerScaleF = 0 : evaluation result is normed,   (==> scale independant: power 0 of factory scale)
  //           PowerScaleX = 0 : evaluation parameter on [0, 1] (==> scale independant: power 0 of factory scale)
  // Nota:     assuming that all three comb coordinates (X, Y, Z) have same scale behaviour, we have chosen
  //           to define a single value for all.
  //           Thus the F dimension of ScaleOption is 1 (and not 3)
  //           (comment added NLD100619)
          CATMathAttrScaleOption  GetScaleOption              () const;

          void                    SetScaleOption              (      CATMathAttrScaleOption& iOption) ;

  //==========================================================================
  // Definition interval of the comb.
  virtual void                    GetDefinitionInterval       (      CATMathInterval & oLimits)       const;
  virtual void                    SetDefinitionInterval       (const CATMathInterval & iLimits);
  
  //==========================================================================
  // Orientations management (NLD240519)
  // -----------------------
  // - _OrnComb,    SetCombOrientation(),    GetCombOrientation()    for the comb itself      (the vector field)
  // - _OrnSupport, SetSupportOrientation(), GetSupportOrientation() for the underlying curve (named "support")
  // CAUTION:
  // - these services are only given to help child classes for storing orientations
  // - no general utility on combs or list of combs (for example CombCleaner, CombImprovement)
  //   should manage these orientations
  // - the global parameterization of a list of CATFrFGenealComb must be a set of connex intervals
  //   (one per comb), (for example the curvilinear abscissa, or the curvilinear abscissa ratio of a composite curve)
  // - the support orientation must be handled only by child classes for evaluation
  //
  // (c'est ma compréhension de la chose, et donc mes recommandations,
  //  au vu de l'existant, ainsi que de la demande MWE pour CATNormalSurfaceComb et peignes similaires;
  //  si on veut gerer une liste de peignes issus d'un wire via une CCV, on a un parametrage global
  //  en abscisse curviligne (ou ratio d'abscisse curviligne) de cette liste, mais les domaines (intervalles de définition)
  //  des peignes successifs sont croissants et adjacents, le CombCleaner ne doit pas s'en soucier,
  //  et c'est chaque peigne qui éventuellement sait que, par exemple, sa courbe support est parcourue
  //  à paramètre décroissant)
  //
  // L'analogie avec la composite curve devrait convaincre le plus sceptique des lecteurs/utilisateurs
  //
  // ATTENTION
  // en consequence, pour moi, EvalTgtOnSupport() devrait rendre, d'un peigne à l'autre dans une liste,
  // des tangentes toujours de meme sens, et c'est donc à l'implementation dans la classe fille, le cas échéant,
  // de rendre une tangente reorientée;
  //|ce que ne fait pas au 240519 CATNormalSurfaceComb, que je considère comme BUGGEE et que je corrige donc)
  // Je confirme cela à la lecture de la plupart des implémentations 
  //
  // En fait cette méthode EvalTgtOnSupport(), dans sa définition, est une cote mal taillée; elle devrait probablement
  // rendre la derivée de la courbe réorientée, par rapport au paramètre iT, et donc tenir compte de la derivée du parametrage
  // mais comme en général elle rend une direction normée, cela n'est pas genant
  //
  //==========================================================================
  // To change the orientation of the comb ;         iOrientation=1(default) or -1.
  virtual void                    SetCombOrientation          (      CATLONG32        iOrientation);
  virtual CATLONG32               GetCombOrientation          ()                                      const;

  //==========================================================================
  // To change the orientation on the comb support ; iOrientation=1(default) or -1.
  // RESTRICTED OR TEMPORARY USE
  // NLD210519 pour MWE
  // voir responsabilités de cette orientation dans les évaluations, dans les nettoyages de peignes
  virtual void                    SetSupportOrientation       (      CATLONG32        iOrientation);
  virtual CATLONG32               GetSupportOrientation       ()                                      const;

  //==========================================================================
  // To change the comb support
  // RESTRICTED OR TEMPORARY USE
  // NLD220120 pour MWE
  // CAUTION:
  // - cycle life must be secured
  // - single call at beginning recommended
  // - to use in consistency with comb clean and deformation laws if any
  // - as for SetSupportOrientation(), EvalPointOnSupport(), ... 
  //   Support means a 1D geometry (curve, edge, ...) not a surface
  virtual void                    SetSupport                  (      CATGeometry*     iSupport);
  virtual CATGeometry           * GetSupport                  ()                                      const;

  //==========================================================================
  // To detect comb with degenerated parameterization (CATEpsg used tolerance on max limits)
  virtual CATLONG32               IsDegenerated               ()                                      const;
 
  //==========================================================================
  // To get the type of comb.
  virtual CATMathClassId          IsA                         ()                                      const = 0;

  //==========================================================================
  // Evaluators
  //==========================================================================
  // child classes evaluators should always take deformation laws into account   NLD290519
  virtual CATLONG32               Eval                        (double iT, CATMathVector & oDir      ) const = 0;
  virtual CATLONG32               EvalFirstDerivative         (double iT, CATMathVector & oDerivDir ) const;
  virtual CATLONG32               EvalSecondDerivative        (double iT, CATMathVector & oDersecDir) const;

  //  return tangent vector on supporting Curve
  // CAUTION:
  // - see above for orientations management; NLD240519)
  // - normalized vector or not? as of 270519:
  //   -     normalized in CATCircularSectionDirectionComb
  //   -     normalized in CAT3DTangentFunction
  //   -     normalized in CATNormalSurfaceComb
  //   - not normalized in CATMeanTangentFunction
  //   - not normalized in CATNewNormalFunction
  //   - not available  in CATNewSpineFunction
  //   -     normalized in CATQsrNormalsComb
  virtual void                    EvalTgtOnSupport            (double iT, CATMathVector & oDir      ) const = 0;
  
  //  return point on supporting curve
  //  not necessary for comb behaviour, but helpful for comb debug; must be implemented by child class
  //                                                                                   Ajout NLD290519
  #ifdef CATFrFGeneralComb_MandatoryEvalPointOnSupport
  virtual void                    EvalPointOnSupport          (double iT, CATMathPoint  & oPoint    ) const = 0;
  #else
  virtual void                    EvalPointOnSupport          (double iT, CATMathPoint  & oPoint    ) const;
  #endif

  //==========================================================================
  // Deformation
  //==========================================================================
  // deformation laws (one law for each coordinate)
  virtual void                    SetDeformationLaw           (CATLaw * iLaw[3]);
  virtual void                    RemoveDeformationLaw        ();
  virtual CATLaw               ** GetDeformationLaw           ();


  // Evaluators on deformation law.
  // - should be used inside child classes evaluators (no effect when no deformation law)    NLD290519
  //   (unless evaluators directly use _Law)
          void                    EvalLaw                     (double iT, CATMathVector & oDir      ) const;
          void                    EvalFirstDerivativeLaw      (double iT, CATMathVector & oDerivDir ) const;
          void                    EvalSecondDerivativeLaw     (double iT, CATMathVector & oDersecDir) const;

  // N.B use of deformation laws in evaluators, as of 290519 (study NLD290519)
  //   -     used       in,CATCircularSectionDirectionComb (fixed with no impact (previously not used): CombCleaner never used on this comb; NLD290519)
  //   -     used       in CAT3DTangentFunction         (through EvalLaw())
  //   -     used       in CATNormalSurfaceComb         (through EvalLaw()) (before Jan 20th 2020, through _Law)
  //   -     used       in CATMeanTangentFunction       (through EvalLaw())
  //   -     used       in CATNewNormalFunction         (through EvalLaw())
  //   -     used       in CATNewSpineFunction          (through EvalLaw())
  //
  //   -     used       in CATQsrNormalsComb            (through _Law)                             /// **** A REPRENDRE avec EvalLaw() ce sera mieux ****

  //==========================================================================
  // When the FinalRepresentation mode is set, the comb can no more be changed nor cleaned nor smoothed.
  // It can only be used for evaluation.
  // These methods are used when the comb is used by another comb. It is the way to obtain the smoothed version of this
  // complex object without changing his eval method.
          void                    SetFinalRepresentation      (CATFrFSmoothedComb *iSmoothedComb, CATLONG32 iCrvIndex);
          void                    SetEvalOnFinalRepresentation(CATBoolean          iActivateFinalEvaluation);

protected:
          void                    FinalEval                   (double iT, CATMathVector & oDir      ) const;
          void                    FinalEvalFirstDerivative    (double iT, CATMathVector & oDerivDir ) const;
          void                    FinalEvalSecondDerivative   (double iT, CATMathVector & oDersecDir) const;


  //==========================================================================
  // DATA
  //==========================================================================
protected:

  CATLONG32               _OrnComb;    // corresponding to SetCombOrientation.    Default is +1 (other possible value is -1)
  CATLONG32               _OrnSupport; // corresponding to SetSupportOrientation. Default is +1 (other possible value is -1)

  CATGeometry           * _Support;    // new data 220120 for QSR combs.

  //                                   // Intervalle de définition de ce peigne au sein d'un super-paramétrage d'une liste de peignes;
  //                                   // - défini par SetDefinitionInterval()
  //                                   // - defaut [0, 1] si pas d'appel
  //                                   // commentaires NLD240120
  double                  _MinParam,   // default is 0.
                          _MaxParam;   // default is 1.

  CATLaw                * _Law[3];

  //                                   // N.B à ce jour aucun accès à _PoweredScaleF, _PoweredScaleX par les classes filles;
  //                                   //     NLD210519
  //                                   //     directly managed by this class through SetScaleOption()
  //                                   //     not to be modified by child class
  double                  _PoweredScaleF,
                          _PoweredScaleX;

  //                                   // N.B à ce jour cette classe mère centralise ces données _Smoothed*,
  //                                   //     mais ne les utilise pas dans les évaluations,
  //                                   //     et s'en sert seule la classe fille CAT3DTangentFunction, qui est toutefois
  //                                   //     une importante classe des peignes
  //                                   //     NLD210519
  CATFrFSmoothedComb    * _SmoothedComb;
  CATLONG32               _SmoothedComb_IdCrv; // index de courbe dans _SmoothedComb
  CATBoolean              _SmoothedComb_Active;


private:
  CATMathAttrScaleOption  _ScalingBehavior_Private;//NLD070208 je tiens a ce qu'il reste prive

  CATLONG32               _ScalePowerF,
                          _ScalePowerX;

  CATFrFGeneralCombDebug* _Debug;
};
#endif
