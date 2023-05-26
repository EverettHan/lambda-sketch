/**
* @quickReview SMT1 16:12:22
*/
// COPYRIGHT DASSAULT SYSTEMES 
//=============================================================================
//
// Deform constant fillet tracks to be CATG1
// Dedicated development on request of TMC
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
//         SMT1  Creation
//   12/22 SME31 Updates to compute G1TrackDeformation for VariableFillet
//=============================================================================

#ifndef CATCATG1TrackDeformationErrorFunctions_H
#define CATCATG1TrackDeformationErrorFunctions_H

#include "CATDataType.h"
#include "CATMathFunctionX.h"
#include "CATMathQuinticX.h"
#include "CATMathNormal.h"

#include "CATConnectTool.h"
#include "CATMathPiecewiseX.h"
#include "CATConnect.h"

class CATSurface;
class CATMathSetOfPointsND;

class G1DeformationErrorAngleFunc : public CATMathFunctionX
{
public:
    
   G1DeformationErrorAngleFunc(
                           CATConnectTool* iProfile,
                           CATSurface * iSupport,
                           CATMathSetOfPointsND* iParameters,
                           CATMathSetOfPointsND* iPoints,
                           CATMathSetOfPointsND* iTangent,
                           CATMathSetOfPointsND* iSecondDerivatives,
                           CATLONG32 iArcIndex, CATLONG32 iTrackIndex, CATLONG32 iCentreIndex);

   ~G1DeformationErrorAngleFunc();

   virtual CATMathClassId IsA() const {return "G1DeformationErrorAngleFunc";}
   virtual CATMathFunctionX * Duplicate() const {return NULL;}

   virtual double Eval           (const double & iT) const;

   virtual double EvalFirstDeriv (const double & iT) const;

protected:

   CATSurface * _Support;
   CATMathNormal _Normal;
   CATMathQuinticX _TrackQuintic[2], _CentreQuintic[3];
   double _StartParam;
};


class G1DeformationErrorRadiusFunc : public CATMathFunctionX
{
public:
    
   G1DeformationErrorRadiusFunc(
                        CATConnectTool* iProfile,
                        CATSurface * iSupport,
                        CATMathSetOfPointsND* iParameters,
                        CATMathSetOfPointsND* iPoints,
                        CATMathSetOfPointsND* iTangent,
                        CATMathSetOfPointsND* iSecondDerivatives,
                        double iRadius, CATMathFunctionX* iRadiusFunction, 
                        CATMathPiecewiseX* iSpinePiecewisePolynom,
                        CATLONG32 iArcIndex, CATLONG32 iTrackIndex, CATLONG32 iCentreIndex);

   virtual CATMathClassId IsA() const {return "G1DeformationErrorRadiusFunc";}
   virtual CATMathFunctionX * Duplicate() const {return NULL;}
   virtual double Eval(const double& iT) const;
   virtual double EvalFirstDeriv (const double & iT) const;

protected:
   CATSurface * _Support;
   CATMathQuinticX _TrackQuintic[2], _CentreQuintic[3];
   double _StartParam;
   double _Radius;
   CATConnectTool * _Profile;
   CATMathFunctionX* _RadiusFunction;
   CATMathPiecewiseX* _SpinePiecewisePolynom;

};

class G1DeformationErrorGapFunc : public CATMathFunctionX
{
public:
    
   G1DeformationErrorGapFunc(
                           CATConnectTool* iProfile,
                           CATSurface * iSupport,
                           CATMathSetOfPointsND* iParameters,
                           CATMathSetOfPointsND* iPoints,
                           CATMathSetOfPointsND* iTangent,
                           CATMathSetOfPointsND* iSecondDerivatives,
                           CATLONG32 iArcIndex, CATLONG32 iTrackIndex, CATLONG32 iContactIndex);

   virtual CATMathClassId IsA() const {return "G1DeformationErrorGapFunc";}
   virtual CATMathFunctionX * Duplicate() const {return NULL;}

   virtual double Eval           (const double & iT) const;

   virtual double EvalFirstDeriv (const double & iT) const;

protected:

   CATSurface * _Support;
   CATMathQuinticX _TrackQuintic[2], _ContactQuintic[3];
   double _StartParam;
};



#endif
