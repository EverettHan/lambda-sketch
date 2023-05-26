// COPYRIGHT DASSAULT SYSTEMES 2003
//==========================================================================
//
//==========================================================================
// Cet Objet permet de recuperer un objet Peigne issu d'un smooth :
//        Il comprend une Ccv (courbe ou se balade l'extremite du vecteur),
//        un Mapping, un parametre.
//
//   /04/03 MNA Creation
//   /12/03 NDN Add new constructor to support old smoothed combs
// 23/06/09 NLD Ajout _PowerScaleX, _PowerScaleF
//              _CombCCVLength est renomme _CombParamFactor
//              Ajout _Scale
// 22/11/11 NLD Ajout Init()
// 23/05/19 NLD Mise au propre; smart indent
//              On revoit les notations antédiluviennes approximatives:
//              les évaluations demandent des index de courbes et non des numéros
//==========================================================================
#ifndef CATFrFSmoothedComb_H
#define CATFrFSmoothedComb_H

#include "FrFAdvancedOpeCrv.h"

#include "CATDataType.h"
#include "CATListOfInt.h"
#include "CATListOfDouble.h"
#include "CATBoolean.h"

#include "CATMathAttrScaleOption.h"

#include "CATCGMVirtual.h"

class CATFrFCompositeCurve;
class CATFrFCompositeCurveMapping;
class CATMathVector;
class CATFrFCCvParam;


//--------------------------------------------------------------------------
class ExportedByFrFAdvancedOpeCrv CATFrFSmoothedComb : public CATCGMVirtual
{
public:
                        CATFrFSmoothedComb  (      CATFrFCompositeCurve        *  iSmoothCcv,
                                                   CATFrFCompositeCurveMapping *  iSmoothMapping,
                                             const CATListOfInt                 & iShiftMap,
                                             const CATListOfDouble              & iShiftParam,
                                             const CATMathAttrScaleOption       & ScaleBehaviour) ;

                        // DO NOT USE; only one use at very old CGM level; NLD220519
                        CATFrFSmoothedComb  (      CATFrFCompositeCurve        * iSmoothCcv[2]) ;

                        CATFrFSmoothedComb  (const CATFrFSmoothedComb          * iToCopy);

  virtual              ~CATFrFSmoothedComb  ();

  // N.B Les évaluations se font via
  //     iCrvIndex : index (et non pas numéro) de la courbe dans la ccv , commençant à 0
  //     iT        : paramètre global sur cette courbe
  //     NLD230519
             void       EvalNormal          (      int                           iCrvIndex,
                                                   double                        iT       ,
                                                   CATMathVector               & oDir     );

             CATBoolean EvalNormalDerivative(      int                           iCrvIndex,
                                                   double                        iT       ,
                                                   CATMathVector               & oDir     ,
                                                   CATMathVector               & oDerDir  );

             void       EvalNormal          (      CATFrFCCvParam             *  iCCvP    ,
                                                   CATMathVector               & oDir     );

private :
             void       Init                ();

  CATFrFCompositeCurve*         _SmoothCcv;
  CATFrFCompositeCurve*         _SmoothCcv2nd;
  CATListOfInt                  _ShiftMapp;
  CATListOfDouble               _ShiftParam;
  CATFrFCompositeCurveMapping * _Mapping;
  double                        _CombParamFactor;// ancien _CombCCVLength
  int                           _PowerScaleX,
                                _PowerScaleF;
  double                        _Scale;
};
#endif
