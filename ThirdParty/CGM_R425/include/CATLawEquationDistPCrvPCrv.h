//==========================================================================
//
// CATLawEquationDistPCrvPCrv
//
// Evaluation of distance between a projection of a point(from PCurve1) on PCurveReference and PCurve2 
// along Normal direction to PCurveReference at this projected point
// (=constructor with 3 PCurves  iPCrv1, iPCrv2, iPCrvRef)
// Note that in the case where iPCrvRef and PCrv1 are identical 
// the evaluation is distance between PCrv1 and PCrv2 along normal direction of PCrv1
//
// Or
// Evaluation of distance between 2 PCurves : PCrvSup and PCrvInf, along Line defined by 
// projection of a point (from PcrvBase) on PCurveRef, and the Normal direction to PCurveReference 
// at this projected point 
// (=constructor with 4 PCurves iPCrvBase, PCrvInf, iPCrvSup, iPCrvRef)
// 
// Evaluation is signed, sign can be modified by caller using iOrientationFlag
// All PCurves must have the same support surface
//
// Carefull: Definition domain of CATLawEquationDistPCrvPCrv is [0, _LambdaEnd-_LambdaStart]
// this is to fit CATCompositeLaw Requirement
//
// Nota: evaluations may now be recorded with CGMReplay filter CATLawEquationDistPCrvPCrv
//
//==========================================================================
//   /12/06 PKC Creation                                                 PKC
// 11/12/07 NLD Ajout _MyMathh2
// 16/10/18 NLD Smart indent
// 17/10/18 NLD Ajout CreateRecorder() pour enregistrement des evaluations
// 24/10/18 NLD On renomme GetParamFromLength() en GetCurveParamFromRatio()
//==========================================================================

#ifndef CATLawEquationDistPCrvPCrv_h
#define CATLawEquationDistPCrvPCrv_h 


#include "FrFObjects.h"

#include "CATMathDef.h"
#include "CATMathFunctionX.h"
#include "CATUnicodeString.h"
#include "CATMathInterval.h"
#include "CATMathDirection.h"
#include "CATMathBasisFunctionX.h"

class CATSoftwareConfiguration;
class CATPCurve;
class CATCrvParam;
class CATSurface;
class CATCrvLengths;

class ExportedByFrFObjects CATLawEquationDistPCrvPCrv : public CATMathBasisFunctionX
{
public:

  // ATTENTION: (NLD231018)
  // - la migration sur CATMathBasisFunctionX avec l'ajout de l'argument iTolObject est une operation IEY120307
  //    dont je ne sais pas si elle a fait l'objet d'une information à notre application GSD
  // - au 221018 l'appelant (framework CATCompositesLightModel) ne passe PAS le bloc de tolerances

  // constructor 3 PCurves
  CATLawEquationDistPCrvPCrv(      CATSoftwareConfiguration*  iConfig         ,
                                   CATPCurve               *  iPCrv1          ,
                                   CATPCurve               *  iPCrv2          ,
                                   CATPCurve               *  iPCrvRef        ,
                             const CATCrvParam              & iPCrv1Start     ,
                             const CATCrvParam              & iPCrv1End       ,
                             const CATCrvParam              & iPCrv2Start     ,
                             const CATCrvParam              & iPCrv2End       ,
                             const CATCrvParam              & iPCrvRefStart   ,
                             const CATCrvParam              & iPCrvRefEnd     ,
                             const double                     iLambdaStart    ,
                             const double                     iLambdaEnd      ,
                             const short                      iOrientationFlag,
                             const CATTolerance             & iTolObject      = CATGetDefaultTolerance());

  // constructor 4 PCurves
  // input variables :
  // iPCrvBase    = PCurve corresponding to the ply section on which insert is applied.
  // iPCrvRef     = PCurve corresponding to the section of reference surface on which plies are defined
  // iPCrvInf     = PCurve corresponding locally to lower wire of insert
  // iPCrvSup     = PCurve corresponding locally to upper wire of insert 
  // iLambdaStart = curvilinear ratio corresponding to beginning point on iPCrvBase
  // iLambdaEnd   = curvilinear ratio corresponding to end       point on iPCrvBase
  // Note that iLambdaStart must be smaller than iLambdaEnd  
  // 0 <= iLambdaStart < iLambdaEnd <= 1
  // All CrvParam ‘Start’ are points corresponding to iLambdaStart position on each PCurve
  // All CrvParam ‘End’   are points corresponding to iLambdaEnd   position on each PCurve
  // iOrientationFlag = is a value -1, + 1 given by the caller to decide sign of Law.

  CATLawEquationDistPCrvPCrv(      CATSoftwareConfiguration*  iConfig         ,
                                   CATPCurve               *  iPCrvBase       ,
                                   CATPCurve               *  iPCrvInf        ,
                                   CATPCurve               *  iPCrvSup        ,
                                   CATPCurve               *  iPCrvRef        ,
                             const CATCrvParam              & iPCrvBaseStart  ,
                             const CATCrvParam              & iPCrvBaseEnd    ,
                             const CATCrvParam              & iPCrvInfStart   ,
                             const CATCrvParam              & iPCrvInfEnd     ,
                             const CATCrvParam              & iPCrvSupStart   ,
                             const CATCrvParam              & iPCrvSupEnd     ,
                             const CATCrvParam              & iPCrvRefStart   ,
                             const CATCrvParam              & iPCrvRefEnd     ,
                             const double                     iLambdaStart    ,
                             const double                     iLambdaEnd      ,
                             const short                      iOrientationFlag,
                             const CATTolerance             & iTolObject      = CATGetDefaultTolerance());

  // destructor
  virtual ~CATLawEquationDistPCrvPCrv();
  
  // to specify a name that will be put on Error that could be thrown be Eval Methods  
  void SetName(CATUnicodeString & iName);

  // Methods derivated from CATMathFunctionX
  CATMathClassId    IsA          ()                            const;
  CATMathFunctionX* Duplicate    ()                            const;
  CATMathFunctionX* DeepDuplicate()                            const;
  CATBoolean        IsOption     (const CATMathOption iOption) const;

  // Definition domain of CATLawEquationDistPCrvPCrv is [0, _LambdaEnd - _LambdaStart]
  // 0 < iPourcentAbsCurv < _LambdaEnd - _LambdaStart
  // iT replaces iPourcentAbsCurv NLD171018
  double Eval            (const double & iT) const;
  double EvalFirstDeriv  (const double & iT) const;
  double EvalSecondDeriv (const double & iT) const;
  double EvalThirdDeriv  (const double & iT) const;
  
  // private methods:
private:
  // Method to get Parameter on PCrv1 from Length Ratio (Length Ratio=input parameter of the CATMathFunctionX)
  // iRatio element of [_LambdaStart, _LambdaEnd]
  // iOrder to specify what is requiered :
  // 0: the param.
  // 1: the first derivative of the param with respect to the Length ratio.
  // 2: the second derivative of the param with respect to the Length ratio.
  // Note : Orientation of PCrv1 is handled here
  //        _PCrv1Lengths is created by first call to this method
  double GetCurveParamFromRatio(double iRatio, int iOrder); // NLD241018 anciennement GetParamFromLength()

  // to factorize code between 2 constructors
  void Set(      CATSoftwareConfiguration*  iConfig         ,
                 CATPCurve               *  iPCrv1          ,
                 CATPCurve               *  iPCrv2          ,
                 CATPCurve               *  iPCrvRef        ,
           const CATCrvParam              & iPCrv1Start     ,
           const CATCrvParam              & iPCrv1End       ,
           const CATCrvParam              & iPCrv2Start     ,
           const CATCrvParam              & iPCrv2End       ,
           const CATCrvParam              & iPCrvRefStart   ,
           const CATCrvParam              & iPCrvRefEnd     ,
           const double                     iLambdaStart    ,
           const double                     iLambdaEnd      ,
           const short                      iOrientationFlag);

  // to factorize code from Eval
  double ComputeIntersectionLinePCrv(const int iPCrvIndex, const double iLineOri[2], const double iLineDir[2]) const;

  // compute the tolerance at one extremity of the domain
  double ToleranceAtExtremity(      CATPCurve   *  iPCrv1 ,
                              const CATCrvParam  & iParam1,
                                    CATPCurve   *  iPCrv2 ,
                              const CATCrvParam  & iParam2);

  // method to centralize error throw in case of impossible evaluation
  // for debug 
  void    EvalError() const;

private:

  void    CreateRecorder();

  //data
protected:
        CATSoftwareConfiguration* _Config       ;

private:
  // Law name in UnicodeString data to specify error
        CATBoolean                _IsName       ;
        CATUnicodeString          _Name         ;

  // Data for PCrv1
        CATPCurve               * _PCrv1        ;
        double                    _PCrv1Start   ,
                                  _PCrv1End     ;
        double                    _LambdaStart  ,
                                  _LambdaEnd    ;
        CATCrvLengths           * _PCrv1Lengths ;
  const CATMathFunctionX        * _EqPCrv1  [3] ;
  const CATMathFunctionX        * _EqU1         ;
  const CATMathFunctionX        * _EqV1         ;

  // Other data for PCrv1
        short                     _PCrv1Orientation;
        double                    _LengthPCrv1  ;
        double                    _LengthPCrv1ByLambdaRange;
        double                    _LocalLengthDerivTerm;

  // Data for PCrv2
        CATPCurve               * _PCrv2        ;
        double                    _PCrv2Start   ,
                                  _PCrv2End     ;
        CATMathInterval           _DomainPCrv2  ;
  const CATMathFunctionX        * _EqPCrv2[3]   ;
  const CATMathFunctionX        * _EqU2         ;
  const CATMathFunctionX        * _EqV2         ;

  // Data for PCrv3
        CATBoolean                _IsPCrv3      ;
        CATPCurve               * _PCrv3        ;
        double                    _PCrv3Start   ,
                                  _PCrv3End     ;
        CATMathInterval           _DomainPCrv3  ;
  const CATMathFunctionX        * _EqPCrv3 [3]  ;
  const CATMathFunctionX        * _EqU3         ;
  const CATMathFunctionX        * _EqV3         ;

  // Data for PCrvRef
        CATPCurve               * _PCrvRef      ;
        double                    _PCrvRefStart ,
                                  _PCrvRefEnd   ;
        CATMathInterval           _DomainPCrvRef;
  const CATMathFunctionX        * _EqPCrvRef[3] ;
  const CATMathFunctionX        * _EqURef       ;
  const CATMathFunctionX        * _EqVRef       ;

  // Data Support
        CATSurface              * _Support      ;

  // Data orientation
        short                     _Orientation  ;

  // buffer
        double                    _LambdaSave   ;
        double                    _fSave        ;
        short                     _IsPlane      ;
        CATMathDirection          _Normal       ;

  // pour les pas de diff finies
        double                    _MyMathh1     ;
        double                    _MyMathh2     ;

};
#endif
