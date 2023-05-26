// COPYRIGHT DASSAULT SYSTEMES 1998
//==========================================================================
//
//  CATMultiCurveFunction :
//
//==========================================================================
//
// Usage notes:
//                MANDATORY : before use of ANY method, Run method has to be called.
//
//==========================================================================
// Jan. 01  Design                                PRG
// 21/02/07 NLD Ajout de _EpsgForParamEquality et _FactoryIfKnown
//              Ajout de iFactory en argument du constructeur
// 24/11/08 JSX Factorisation & simplifiation dans GetTabPerfoRank du code d'optimisation 
//              _lastParams et _lastParamsD1 regroupés dans _lastParams[2] 
//              mme chose pour 2 autres paires de tableaux
//==========================================================================
#ifndef CATMultiCurveFunction_H
#define CATMultiCurveFunction_H

#include "FrFOpeCrv.h"
#include "CATListOfCATMathCurveFunction.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATListOfDouble.h"
#include "CATCGMVirtual.h"
class CATGeoFactory ;

//--------------------------------------------------------------------------
class ExportedByFrFOpeCrv CATMultiCurveFunction  : public CATCGMVirtual
{
public :
  CATMultiCurveFunction(CATLONG32 nbCurves, CATGeoFactory* iFactory=0);
  virtual ~ CATMultiCurveFunction();

  CATLISTP(CATMathCurveFunction)* GetListOfMathCurveFunction()
    { return _listOfMathCurveFunctions; }

  CATListOfDouble* GetListOfLimits()
    { return _listOfLimits; }

  CATLONG32 GetNumberOfCurves()
    { return _nbCurves; }

  void Eval(double iParam, CATLONG32 iNum, CATMathPoint& point);
  void EvalFirstDeriv(double iParam, CATLONG32 iNum, CATMathVector& oResultD1);

  CATBoolean FirstDerivativeIsAvailable()
    {return _firstDerivativesAvailable;};

  void GetMaxLimits(double &oMin, double &oMax);
  virtual CATLONG32 Run();

  ///////////////////////////////////////////////////////////////////
  //To implement for inheritance.
  virtual void EvalND(double param, double* points) = 0;
  virtual void EvalNDFirstDerivatives(double param, double* firstDerivatives) = 0;
  //Check is done at the beginning of Run method.
  //If return is different from 0, means some data are incorrect.
  virtual CATLONG32 Check();
  //Don't forget to fill this data :
  //_firstDerivativesAvailable (default is 0->No)
  //_listOfLimits (default is [0 , 1] for all curves)
  ///////////////////////////////////////////////////////////////////
  

private:
  CATLONG32 GetTabPerfoRank(double iparam,CATLONG32 iNumTab);


protected :

  //Input et options.
  CATGeoFactory*                  _FactoryIfKnown ;
  CATLISTP(CATMathCurveFunction)* _listOfMathCurveFunctions;
  CATLONG32                       _nbCurves;
  CATBoolean                      _firstDerivativesAvailable;
  CATListOfDouble*                _listOfLimits;

private:
  //Optimisation.
  double*                         _lastParams[2];
  CATLONG32                       _allTablesUsed[2];
  CATLONG32*                      _lastParamNbEvaluations[2];
  double*                         _Points;
  double*                         _FirstDerivatives;
  double                          _EpsgForParamEquality;
};
#endif
