// COPYRIGHT DASSAULT SYSTEMES 1997 
//==========================================================================
//
// CATGeometricBlendSurface:
// Interface class of the Geometric Blend Surface Operator.
//
//==========================================================================
//
// Usage notes:
// This class can be used as is for simple Blend or derived
// in order to implement specific algorithm or capabilities.
//
//========================================================================== 
// Dec 97  Creation                      Paul-Alexandre Lourme --  alm 
// Jul 98  Modification                  Paul-Alexandre Lourme --  alm
//========================================================================== 

#ifndef CATGeometricBlendSurface_H
#define CATGeometricBlendSurface_H

#include "CATBlendSurface.h"
#include "CATBlendValue.h"
#include "FrFAdvancedOpeSur.h"
#include "CreateGeometricBlendSurface.h"

class CATFrFCompositeCurve;
class CATCrvParam;
class CATLaw;
class CATFrFCCvParam;
class CATMathInterval;
class CATMathPoint;
class CATMathSetOfPoints;
class CATMathDirection;
class CATFrFNurbsMultiForm;
#include "CATListOfInt.h"
#include "CATLISTP_CATMathVector.h"

//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedOpeSur CATGeometricBlendSurface : public CATBlendSurface
  {
  public :
    
    virtual ~CATGeometricBlendSurface();
    
    // Eval avec infos suplemetaire Points et Tg
    virtual void EvalOneShape(double iParam, CATLONG32 iDomain,
                              CATMathSetOfPoints * iPoints,
                              CATMathDirection * oNormalPlane) const = 0;
    // Set Level     
    // 7-> Niveau CXR7 
    // 8-> New Marching ( eval sur ouvert uniquement) 
    // 9-> NormalComb Sans DirectionnalSurface
    //10-> Impose directions : oriented limit
    //11-> Postprocessing using fill surfaces ( non actif )
    //12-> New Marching ( GlobalEps && points imposes )

    virtual void SetBlendSurfaceLevel(CATLONG32 iLevel)=0;

    // Set le Mode a cx2
    virtual void SetCx2()=0;

    //
    //  Setting the blend limit CompositeCurves 
    //
    virtual void SetCompositeCurve(const CATLONG32 iSide, const CATFrFCompositeCurve * iCompCurve)=0;
    //
    //  Set the different domains to compute the different surfaces
    //
    //  For each domain, a surface is computed.
    //  A domain is defined with a CATMathInterval (representing the 
    //  coupling parameter domain), and the indexes of the curves
    //  (to do the evaluations on the right curves of the composite-curves, 
    //  for each coupling domain).
    //
    virtual void SetDomains(CATLONG32 iNbDomains, CATMathInterval * iDomains, CATLONG32 * iStartCrvIndex, CATLONG32 * iEndCrvIndex) = 0;
    // cx7 uniquement
    virtual void SetDomainsG1(CATLONG32 iNbDomainsG1, CATLONG32 * inbSDom, CATLONG32 *iiPointed[2]=0) =0;
    virtual void FindDomainsG1() = 0;

    virtual void SetDirections(CATLONG32 iSide, 
                               const CATListOfDouble & iLiT,
                               const CATListOfInt & iLKind,
                               const CATListOfDouble & iLDir) = 0;
    //
    //  Set Limits and Constraint Points
    //
    //  Constraints points are usually imposed by the user
    //  iCCvLimits is an array of CATFrFCCvLimits[NbCCv]
    //  iCCvParam is an array of CATFrFCCvParam[NbImposedPoints][NbCCv]    
    //
    virtual void SetLimits(const CATFrFCCvLimits * iCCvLimits)=0;
    virtual void AddImposedPoints(const CATLONG32 iNumberOfPoints,      const CATFrFCCvParam ** iCCvParam)=0;
    virtual void RemoveCouplingPoints() = 0 ;
    virtual void RemoveOneCouplingPoint(const CATLONG32 iIndex) = 0;
    
    // Set Laws for Shape Constraints
    virtual void SetAngularLawPhi   (CATLONG32 iIndex, const CATLaw * iAngularLawPhi)=0;
    virtual void SetAngularLawTheta (CATLONG32 iIndex, const CATLaw * iAngularLawTheta)=0;
    virtual void SetTensionLawDsDu  (CATLONG32 iIndex, const CATLaw * iTensionLawDsDu)=0;
    virtual void SetTensionLawD2sDu2(CATLONG32 iIndex, const CATLaw * iTensionLawD2sDu2)=0;
    virtual void SetRadiusLaw       (const CATLaw * iRadiusLaw)=0;
    
    // Auther set and get methods
    virtual void SetPreview(CATLONG32 iPreview)=0;
    virtual CATLONG32 GetPreview() const=0;
    
    // Only for the Extrapol case
    virtual void ComputeUntilTransition(const CATMathPoint &iStart, const CATMathPoint &iEnd, CATLONG32 &oTrans) const = 0;

    
    // Set The Accuracy default=0=(tol=res)=freeform  Part=Gsm=1=(tol=res/10)
    virtual void SetHighAccuracyOption(CATLONG32 iAccuracy)=0;

    // Set the user tolerance
    // Used Only if HigAccuracyOption is set to 0
    virtual void SetToleranceForSurfaceCreation(double iTolSurface)=0; 
    
    // Set The Mode de calcul de la norme ( par defaut norme VW)
    // 0 : norme VW
    // 1 " norme GSD (elliptique 1)
    // 3: Conatant
    // 4 :Elliptiue 2
    virtual void SetNormeMode(CATLONG32 iMode)=0;
    
    // Set The IntersectionOptimization, default=0.
    // When user (blend between offset curvesfor example) knows
    // that there is no intersection between the Composite Curves 
    virtual void SetIntersectionOptimization(CATLONG32 iIntersectionOptimization)=0;
    
    // Set the internal continuity
    virtual void SetInternalContinuity(CATLONG32 nbCont,CATLONG32 *TabCont)=0;
    //
    // Get the multiform result
    virtual CATFrFNurbsMultiForm  * GetMultiForm() const = 0;
  };

#endif






