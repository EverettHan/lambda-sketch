/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES  2000
//=============================================================================
//
// CATLawEquationDistCrv
//
// Evaluation de la distance projetee entre une line reference
// et une courbe en fonction du ratio d'abscisse curviligne
// sur la reference
// (ratio et non pourcentage; correction NLD070220)
//
// En fait c'est un peu plus compliqué.
// Dans une utilisation pratique, on va construire plusieurs fonctions de ce type,
// aux différentes cellules d'une topologie, avec un paramétrage global
// cohérent de l'ensemble de ces fonctions, en ratio d'abscisse curviligne,
// en vue de contruire une loi composée unique, sur base de ces fonctions,
// paramétrée, donc, sur [0, 1]
// NLD070220
//
//=============================================================================
// 11/12/07 NLD Ajout _h1, _h2 pour mise au Scale des CATMathh1 CATMathh2
// 02/05/08 NLD Ajout Init(), ce qui n'est pas du luxe
// 12/11/08 NLD Ajout _BorderLineRattrap
//              Ajout _TolLineLimits
// 13/11/08 NLD Ajout _BorderLineRattrapCallLevel
// 22/10/18 NLD Mise au propre complète; smart indent
//              Regroupement des méthodes puis des données
//              Homogeneisation et correction des notations
// 31/10/18 NLD Plus de valeur par défaut à l'argument iTolObject
// 06/11/18 NLD Stream/UnStream (1/n)
//              Ajout GetDirectComponents(), _IsStreamable(), GetStreamType(), Stream()
//              Ajout CATFunctionXUnStream_LawEquationDistCrv()
// 07/11/18 NLD Stream/UnStream (2/n)
//              - ajout _FactoryTolObject
//              Suppression de _h1 et _h2
// 09/11/18 NLD Ajout GetCurveParamFromLineParam()
// 06/02/20 NLD Ajout _LoadedFromReplay, SetLoadedFromReplay()
//              Ajout _ListGeometriesToDelete
//              Ajout _StartPointLine et _EndPointLine
//              Ajout _StartPointCrv  et _EndPointCrv
// 07/02/20 NLD Renommage de _StartPointLine et _EndPointLine
//              en           _LineStartPoint et _LineEndPoint
//              (pour eviter les confusions avec l'argument StartPointLine)
//              et        de  _StartPointCrv  et _EndPointCrv
//              en            _CrvStartPoint  et _CrvEndPoint
//              Documentation des notations T, F, Lambda, W
//              XScale: indication des puissances du scale pour chacune des variables
// 11/02/20 NLD Ajout EvalBorderLine() (isolation du code de Eval())
//              Ajout _SquareVectorNorm
//=============================================================================

#ifndef CATLawEquationDistCrv_h
#define CATLawEquationDistCrv_h 

#include "FrFObjects.h"

#include "CATUnicodeString.h"

#include "CATTolerance.h"

#include "CATMathDef.h"
#include "CATMathPoint.h"

#include "CATMathFunctionX.h"
#include "CATMathBasisFunctionX.h"
#include "CATListOfCATGeometries.h"

class CATCurve;
class CATCrvParam;

class CATMathPoint;
class CATMathVector;
class CATSoftwareConfiguration;

class ExportedByFrFObjects CATLawEquationDistCrv : public CATMathBasisFunctionX
{
  // -------
  // NOTATIONS
  // -------
  // Je demele et explicite ici les notations internes et externes, et j'indique le cas échéant la puissance de l'eechelle
  // avec laquelle varie chaque type de variable (S0: indépendant de l'échelle, S1: variant comme la puissance 1 de l'echelle)
  // T, iT                             : paramètre d'evaluation               S0
  // F, iF, ioF                        : résultat  d'evaluation (distance)    S1
  // Lambda     (= T + _StartParamLine): paramètre sur droite                 S0
  // W                                 : paramètre global sur courbe          S1
  //                                                                                                  NLD070220


  // -------
  // METHODS
  // -------
public:


  // ATTENTION: (NLD231018) (NLD071118)
  // - la migration sur CATMathBasisFunctionX avec l'ajout de l'argument iTolObject est une operation IEY110107
  //    dont je ne sais pas si elle a fait l'objet d'une information à notre application GSD
  // - au 221018 l'appelant GSD (CATGSMLawDistProjCke) ne passe PAS le bloc de tolerances
  // - c'est la cause de dysfonctionnements à echelle 100 GenieCivil/RailDesign
  //   (que j'identifie et fais corriger)
  // - GSD passant par CATPGMCreateLawEquationDistCrv(), je supprime ici la valeur par defaut CATGetDefaultTolerance()
  //   dans les constructeurs et c'est dans CATPGMCreateLawEquationDistCrv() que je mets cette valeur par defaut
  // - par ailleurs j'introduis dans le code un rattrapage versionné privilegiant le bloc tolerances issu de la courbe
  //   pour la construction de la classe mère
  // - enfin j'introduis une variable _FactoryTolObject qui est, independamment du versionning,
  //   toujours bonne car toujours égale au bloc issu de la courbe

  // Constructor for a positive distance law
                            CATLawEquationDistCrv                   (      CATSoftwareConfiguration * iConfig        ,
                                                                           double                     StartParamLine , // S0
                                                                           double                     EndParamLine   , // S0
                                                                     const CATMathPoint             & StartPointLine , // S1
                                                                     const CATMathVector            & DirectionLine  , // S0
                                                                           CATPositiveLength          LengthRef      , // S1
                                                                           CATCurve                 * Curve          ,
                                                                     const CATCrvParam              & ParamStartCurve,
                                                                     const CATCrvParam              & ParamEndCurve  ,
                                                                     const CATTolerance             & iTolObject     );

  // Constructor for an algebraic law
  //  NormalLine must be orthogonal to DirectionLine, and in the same plane as the line and the curve.
  //  It indicates the positive sense.
                            CATLawEquationDistCrv                   (      CATSoftwareConfiguration * iConfig        ,
                                                                           double                     StartParamLine , // S0
                                                                           double                     EndParamLine   , // S0
                                                                     const CATMathPoint             & StartPointLine , // S1
                                                                     const CATMathVector            & DirectionLine  , // S0
                                                                           CATPositiveLength          LengthRef      , // S1
                                                                     const CATMathVector            & NormalLine     , // S0
                                                                           CATCurve                 * Curve          ,
                                                                     const CATCrvParam              & ParamStartCurve,
                                                                     const CATCrvParam              & ParamEndCurve  ,
                                                                     const CATTolerance             & iTolObject     );

  virtual                  ~CATLawEquationDistCrv();
   
          void              SetName                                 (      CATUnicodeString         & iName          );

          CATMathClassId    IsA                                     ()                                                    const;

          CATMathFunctionX* Duplicate                               ()                                                    const;

          CATMathFunctionX* DeepDuplicate                           ()                                                    const;

          CATBoolean        IsOption                                (const CATMathOption              iOption        )    const;

          double            Eval                                    (const double                   & iT             )    const;

          double            EvalFirstDeriv                          (const double                   & iT             )    const;

          double            EvalSecondDeriv                         (const double                   & iT             )    const;

          double            EvalThirdDeriv                          (const double                   & iT             )    const;

          void              Eval                                    (const double                     iT             ,
                                                                     const CATMathOption              iOption        ,
                                                                           double                   * ioF            ,
                                                                           double                   * ioDf           = 0,
                                                                           double                   * ioD2f          = 0) const;

          void              SetLoadedFromReplay                     (); // Internal Use

  //-----------------------------------------------------------------
  // Stream management (see also UnStream, forward)
  //-----------------------------------------------------------------
  virtual int               GetDirectComponents                     (const int                        iSizeOfComponents,
                                                                     const CATMathFunctionGeneral **  ioComponents     )  const;

  virtual CATBoolean        _IsStreamable                           (const CATCGMStreamVersion        iTargetVersion   ,
                                                                           CATBoolean               & ioReversible     )  const;

  virtual short             GetStreamDomainType                     (      char                       ioDomain      [3])  const ;

  virtual void              Stream                                  (      CATMathStream            & Str              ,
                                                                     const char                       iLabelReserved[] )  const ;

  //-----------------------------------------------------------------

private:
          void              EvalAtExtremity                         (      double                     iT             ,
                                                                           double                     iF             , // NLD221018 anciennement iEval
                                                                     const CATMathOption            & iOption        ,
                                                                           double                   * ioDf           ,
                                                                           double                   * ioD2f          ) const;

          int               EvalBorderLine                          (      double                     iT             ,
                                                                     const CATMathOption            & iOption        ,
                                                                           double                   * ioF            ,
                                                                           double                   * ioDf           = 0,
                                                                           double                   * ioD2f          = 0) const;

          void              GetCurveParamFromLineParam              (      double                     iLambda        ,
                                                                           double                   & oW             ,
                                                                           int                      & oOK            ) const;

          void              CheckLineLimits                         ();

          void              Init                                    (      CATSoftwareConfiguration * iConfig        ,
                                                                           double                     StartParamLine ,
                                                                           double                     EndParamLine   ,
                                                                     const CATMathPoint             & StartPointLine ,
                                                                     const CATMathVector            & DirectionLine  ,
                                                                           CATPositiveLength          LengthRef      ,
                                                                     const CATMathVector            * NormalLine     , // optionnel
                                                                           CATCurve                 * Curve          ,
                                                                     const CATCrvParam              & ParamStartCurve,
                                                                     const CATCrvParam              & ParamEndCurve  ,
                                                                     const CATTolerance             & iTolObject     );

protected:

         CATSoftwareConfiguration * _Config             ;

  // -------
  // DATA
  // -------

private:

  // General data
  // ------------
   const CATTolerance             & _FactoryTolObject   ; // bloc tolerance associé à la factory de la courbe

  // Data for the curve
  // ------------------
  //                                                      // N.B j'indique le cas échéant la puissance du Scale S de chaque donnée;
  //                                                      //     en général S0 (independant de l'echelle)
  //                                                      //     ou bien    S1 (variant comme la puissance 1 de l'echelle)
  //                                                      //     NLD070220
         CATCurve                 * _Crv                ; // A renommer _Crv_DoNotUse (eviter les accès directs, passer par _EqCrv)
         double                     _StartParamCrv      ,
                                    _EndParamCrv        ;
   const CATMathFunctionX         * _EqCrv           [3];
         CATMathPoint               _CrvStartPoint      ; // deduit des entrées
         CATMathPoint               _CrvEndPoint        ; // deduit des entrées

  // Data for the line
  // -----------------
         double                     _inputStartParamLine, // deduit des entrées (swap éventuel)                S0
                                    _inputEndParamLine  ; // deduit des entrées (swap éventuel)                S0
         double                     _StartParamLine     , // deduit des entrées (swap éventuel + ajustement)   S0
                                    _EndParamLine       ; // deduit des entrées (swap éventuel + ajustement)   S0
         double                     _PointCoord      [3], // entrée             (            StartPointLine)   S1
                                    _VectorCoord     [3]; // deduit des entrées (LengthRef * DirectionLine)    S1
         double                     _SquareVectorNorm   ; // carré de la norme de _VectorCoord                 S2
         CATMathPoint               _LineStartPoint     ; // deduit des entrées (swap éventuel)                S1
         CATMathPoint               _LineEndPoint       ; // deduit des entrées (swap eventuel)                S1


  // Law name in UnicodeString data to specify error
         CATBoolean                 _IsName             ;
         CATUnicodeString           _Name               ;

  // Optimization data to avoid recalculations
         double                     _LambdaSave         ; //                                                   S0
         double                     _wSave              ; //                                                   S1

  // Options
         CATLONG32                  _IsSigned;
         double                     _SideVector      [3]; //                                                   S0



  // Level for internal versionning.
  //  Level 0: default level.
  //  Level 1: tolerance = factory resolution for CheckLineLimits treatments.
  //  Level 2: XScale fixes
  //  Level 3: test domain size in finite difference
  //  Level 4: special treatment at line borders (basic   : V1)
  //  Level 5: special treatment at line borders (enhanced: V2)
  //  Level 6: tolerance extended for CheckLineLimits treatments.
         CATLONG32                  _Level              ;
  // 
         int                        _BorderLineRattrap  ;
         int                        _BorderLineRattrapCallLevel ;
  //     double                     _h1                 , //NLD071118 n'a jamais servi
  //                                _h2                 ; //NLD071118 n'a jamais servi
         double                     _TolLineLimits      ; //                                                   S0

         int                        _LoadedFromReplay   ;
         CATLISTP(CATGeometry)      _ListGeometriesToDelete;


};


//-----------------------------------------------------------------
// UnStream management (see also Stream, above)
//-----------------------------------------------------------------
/**
   * @nodoc   internal use.
   * @nocgmitf
   */
// On pourrait utiliser le type CATFunctionXUnStream
// ExportedByFrFObjects
// extern "C"  ExportedByFrFObjects CATMathFunctionX* CATFunctionXUnStream_LawEquationDistCrv(CATMathStream& Str, const char iLabelReserved[]);

#endif
