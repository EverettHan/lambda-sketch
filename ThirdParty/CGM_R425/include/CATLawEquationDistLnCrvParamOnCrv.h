/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES  2000
//=============================================================================
//
// CATLawEquationDistLnCrvParamOnCrv
// Evaluation de la distance projetee entre une line reference
// et une courbe en fonction du pourcentage d'abscisse curviligne
// sur la definition
//
//=============================================================================
// 08/11/00 XGN Creation                                                    XGN
// 12/10/18 NLD Mise au propre complète
//              Regroupement des méthodes puis des données
//              Homogeneisation et correction des notations
//              Ajout Init()
// 22/10/18 NLD GetCurveParamFromRatio() remplace GetParamFromLength() (simple renommage)
// 31/10/18 NLD Plus de valeur par défaut à l'argument iTolObject
// 07/11/18 NLD Ajout _FactoryTolObject
//=============================================================================
#ifndef CATLawEquationDistLnCrvParamOnCrv_h
#define CATLawEquationDistLnCrvParamOnCrv_h 

#include "CATMathDef.h"
#include "CATMathFunctionX.h"

#include "CATUnicodeString.h"

#include "FrFObjects.h"
#include "CATMathBasisFunctionX.h"
#include "CATTolerance.h"

class CATCurve;
class CATCrvParam;

class CATMathPoint;
class CATMathVector;

class CATCrvLengths;
class CATSoftwareConfiguration;

class ExportedByFrFObjects CATLawEquationDistLnCrvParamOnCrv : public CATMathBasisFunctionX
{
public:


  // ATTENTION: au 221018 l'appelant GSD (CATGSMLawDistProjCke) ne passe PAS le bloc de tolerances

  // Constructor for a positive law
  //
  CATLawEquationDistLnCrvParamOnCrv                                 (      CATSoftwareConfiguration * iConfig        ,
                                                                           double                     wStart         ,
                                                                           double                     wEnd           ,
                                                                     const CATMathPoint             & StartPointLine ,
                                                                     const CATMathVector            & DirectionLine  ,
                                                                           CATPositiveLength          LengthRef      ,
                                                                           CATCurve                 * Curve          ,
                                                                     const CATCrvParam              & ParamStartCurve,
                                                                     const CATCrvParam              & ParamEndCurve  ,
                                                                     const CATTolerance             & iTolObject     ); // = CATGetDefaultTolerance());

  // Constructor for an algebraic law
  //  NormalLine must be orthogonal to DirectionLine, and in the same plane as the line and the curve.
  //  It indicates the positive sense.
  //
  CATLawEquationDistLnCrvParamOnCrv                                 (      CATSoftwareConfiguration * iConfig        ,
                                                                           double                     wStart         ,
                                                                           double                     wEnd           ,
                                                                     const CATMathPoint             & StartPointLine ,
                                                                     const CATMathVector            & DirectionLine  ,
                                                                           CATPositiveLength          LengthRef      ,
                                                                     const CATMathVector            & NormalLine     ,
                                                                           CATCurve                 * Curve          ,
                                                                     const CATCrvParam              & ParamStartCurve,
                                                                     const CATCrvParam              & ParamEndCurve  ,
                                                                     const CATTolerance             & iTolObject     ); // = CATGetDefaultTolerance());

  virtual ~CATLawEquationDistLnCrvParamOnCrv();
  
  void              SetName                                         (      CATUnicodeString         & iName          );

  CATMathClassId    IsA                                             () const;
  CATMathFunctionX* Duplicate                                       () const;
  CATMathFunctionX* DeepDuplicate                                   () const;
  
  CATBoolean        IsOption                                        (const CATMathOption              iOption         ) const;
  
  // iT n'est ni un ratio d'abscisse curviligne (entre 0 et 1), ni (encore moins) un pourcentage comme l'ancienne notation le suggerait; NLD121018)
  // mais un paramètre de l'intervalle [ 0, wEnd - wStart ] (wStart et wEnd reçus par le constructeur)                                   NLD221018
  double            Eval                                            (const double                   & iT              ) const;
  double            EvalFirstDeriv                                  (const double                   & iT              ) const;
  double            EvalSecondDeriv                                 (const double                   & iT              ) const;
  double            EvalThirdDeriv                                  (const double                   & iT              ) const;
  void              Eval                                            (const double                     iT              ,
                                                                     const CATMathOption              iOption         ,
                                                                           double                   * ioF             ,
                                                                           double                   * ioDf            = 0,
                                                                           double                   * ioD2f           = 0) const;

private:

  double            GetCurveParamFromRatio                          (      double                     iRatio          ,
                                                                           int                        iOrder          );

  void              EvalAtExtremity                                 (      double                     iT              ,
                                                                           double                     iEval           ,
                                                                     const CATMathOption            & iOption         ,
                                                                           double                   * ioDf            ,
                                                                           double                   * ioD2f           ) const;


  void              Init                                            (      CATSoftwareConfiguration * iConfig        ,
                                                                           double                     wStart         ,
                                                                           double                     wEnd           ,
                                                                     const CATMathPoint             & StartPointLine ,
                                                                     const CATMathVector            & DirectionLine  ,
                                                                           CATPositiveLength          LengthRef      ,
                                                                           CATCurve                 * Curve          ,
                                                                     const CATCrvParam              & ParamStartCurve,
                                                                     const CATCrvParam              & ParamEndCurve  ,
                                                                     const CATTolerance             & iTolObject     );


protected:
  CATSoftwareConfiguration * _Config;


private:
  // General data
  const CATTolerance     & _FactoryTolObject   ; // bloc tolerance associé à la factory de la courbe

  // Data for the curve
        CATCrvLengths    * _CrvLengths    ;
        CATCurve         * _Crv           ;
        double             _StartParamCrv ,
                           _EndParamCrv   ;
        int                _Orientation   ;
  const CATMathFunctionX * _EqCrv[3]      ;

  // Data for the line
        double             _PointCoord [3],
                           _VectorCoord[3];
        double             _VectorNorm    ;
  // Law name in UnicodeString data to specify error
        CATBoolean         _IsName        ;
        CATUnicodeString   _Name          ;

  // Optimization data to avoid recalculations
        double             _LambdaSave    ,
                           _wSave         ;
        double             _LengthCurve   ;

        double             _wStart        ,
                           _wEnd          ;

  // Options
        CATLONG32          _IsSigned      ;
        double             _SideVector [3];

};
#endif
