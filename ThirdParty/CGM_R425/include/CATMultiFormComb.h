// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================
//
// CATMultiFormComb :
//
//=============================================================================
//
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
//    06 00 ndn Creation
// 04 04 03 MNA Ajout de SetSoftwareConfiguration
// 22/11/11 NLD Ajout Init()
//              Suppression du constructeur sans CATSoftwareConfiguration
// 26/11/12 NLD XScale. L'argument iTol ne prend plus de valeur par defaut
// 28/05/13 NLD _Fact devient _Factory
//=============================================================================
#ifndef CATMultiFormComb_H
#define CATMultiFormComb_H

#include "CATMathVectorialFunctionX.h"
#include "FrFOpeCrv.h"
#include "CATParameterizationOption.h"

#include "CATTolerance.h"

class CATSoftwareConfiguration;
class CATSoftwareConfiguration;
class CATGeoFactory;
class CATFrFComb;
class CATFrFMultiComb;
class CATFrFNurbsMultiForm;
class CATKnotVector;

//-----------------------------------------------------------------------------
class ExportedByFrFOpeCrv CATMultiFormComb : public CATMathVectorialFunctionX
{
public :
  
  //=================
  //  M E T H O D S  
  //=================
  // Constructor
  //------------
  /* NLD221111
  CATMultiFormComb(      CATGeoFactory    *  iFact,
                         CATLONG32           NbMultiComb,
                   const CATFrFMultiComb **  iMultiComb);
  */
  CATMultiFormComb(      CATSoftwareConfiguration *  iSoftwareConfiguration,
                         CATGeoFactory            *  iFact,
                         CATLONG32                   NbMultiComb,
                   const CATFrFMultiComb         **  iMultiComb,
                   const CATTolerance              & iTol);

  //DO NOT USE ANYMORE...
  //UN SEUL APPEL A ERADIQUER AU 22/11/11
  CATMultiFormComb(      CATGeoFactory   * iFact,
                   const CATFrFMultiComb * iMultiComb);


  // Destructor
  //-----------
  virtual ~CATMultiFormComb();

  void SetG0MaxDeviation(double iTolG0);
  void SetG1MaxDeviation(double iTolG1);

  double GetG0MaxDeviation();
  double GetG1MaxDeviation();

  //Default is keep paramaterization.
  void ImposeSameParametrization(CATParameterizationOption iParameterizationOption);

  //Just for approximation step.
  void SetRatio(double iRatioOnComb);

  //Specify the kind of approximation used : 0 -> V4 Fitting (default)
  //                                         1 -> V5 Approx (highly recommanded)
  void SetKindOfApprox(CATLONG32 iApproxMode);

  // param  iDegree 
  // the required degree of the result surface 
  // param  iNumberOfPatch
  // the required maximum number of patches of the result surface
  // Only available with SetKindOfApprox(1)
  void SetSurfaceParameters ( int iDegree, int iNumberOfPatch);

  void SetSoftwareConfiguration(CATSoftwareConfiguration * iSoftwareConfig);


  //Get the resulting multiform.
  CATFrFNurbsMultiForm * GetMultiFormForOneComb(CATLONG32 iRank,const CATKnotVector * iImposeKnotVector=0);

  CATFrFNurbsMultiForm * GetMultiForm(const CATKnotVector * iImposeKnotVector=0);

protected:

   void Init                (CATGeoFactory              *  iFactory);

  //inheritance.
  CATBoolean IsOption       (const CATMathOption           iOption) const;
  void       Eval           (const double                  iX,
                                   double               *  oFX) const;
  void       EvalFirstDeriv (const double                  iX,
                                   double               *  oDFX) const; 
  CATLONG32  FitOneComb     (      CATFrFNurbsMultiForm *& oNewMult);
  void       ComputeDegeneratedMultiForm(CATFrFNurbsMultiForm *&oNewMult );

  //datas
  //--------------------------------------------------------
  //Input
  CATGeoFactory            *_Factory;
  CATLONG32                 _NbMultiComb;

  //--------------------------------------------------------
  //Options by Set.
  double                    _TolC0,
                            _TolG1;
  double                    _RatioOnComb;
  CATParameterizationOption _ParameterizationOption;

  //Kind of Approx used. Default is 0 -> V4 fitting
  //1 -> V5 Approx.
  CATLONG32                 _ApproxMode;
  CATLONG32                 _MDegree;
  CATLONG32                 _NumberOfPatch;

  //--------------------------------------------------------
  //Output
  CATFrFMultiComb         **_MultiComb;
  double                    _ErrC0 ,
                            _ErrG1;

  //--------------------------------------------------------
  //Internals
  const CATFrFComb         *_Comb; //Current Comb.
  double                    _RatioParam,
                            _sp,
                            _ep;
  double                    _ParametricSpace;
  CATLONG32                 _MigrMulti; //1 -> old constructor, 0 -> new with array of combs.

  CATSoftwareConfiguration *_SoftwareConfig;

};

#endif

