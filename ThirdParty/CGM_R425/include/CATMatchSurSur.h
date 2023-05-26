// COPYRIGHT DASSAULT SYSTEMES AG 1999
//==========================================================================
//
// CATMatchSurSur:
// Interface class of the Match Surface Surface Operator,
// which implements the both option for the matching command
//
//==========================================================================
//
// Usage notes:
//
//========================================================================== 
// Aug 99  Creation                      FLM
// 16/11/05 CCK : code non teste -> mise en commentaire pour la grande operation
//                coverage
//========================================================================== 
/*
#ifndef CATMatchSurSur_H
#define CATMatchSurSur_H

#include "FrFAdvancedOpeSur.h"
#include "CATFreeFormDef.h"
#include "CATTransitionCheckingCommand.h"
#include "CATCGMVirtual.h"

typedef enum { CATAnalyticMatch, 
               CATGeometricMatch, 
               CATUnknownMatch } CATMatchMode;

class CATPLine;
class CATLaw;
class CATMathDirection;


//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedOpeSur CATMatchSurSur : public CATCGMVirtual
{
  public :
  
    virtual ~CATMatchSurSur();
    //
    // Run
    //
    virtual void Run() = 0;
    virtual void TickRun () = 0;
    //
    //  Setting the  boundaries to be matched. It defines the surfaces, which
    //  will be modified
    //    valid values for edgeindex are 1 and 2
    //
    virtual void SetCurveToBeMatched(CATLONG32 edgeindex, const CATPLine *iCurve) = 0;

    // UseTheLastRunResult
    // The last run result defines the surfaces to be matched : the beginning
    // surfaces are changed. This allows a new match with the same operator, on
    // the modified geometry.
    virtual void UseTheLastRunResult() = 0;
    //
    // Connection Continuity
    // The default value is iContinuity = CATFrFPointCont
    virtual void SetConnectionContinuity(const CATFrFContinuity iContinuity) = 0;
    virtual CATFrFContinuity GetConnectionContinuity() const = 0; 

    // Manage the match factors
    // The range for ifactor is [0.0, 1.0]. The default value is 0.5.
    // ifactor --> 0.0 raise the influence of the 1st surface
    // ifactor --> 1.0 raise the influence of the 2nd surface
    virtual void SetMatchFactor(CATFrFContinuity iContinuity,double ifactor) = 0;
    virtual double GetMatchFactor(CATFrFContinuity iContinuity) const = 0;

    // Use the modified surface
    // Use the initial surface or the modified surface to compute the 
    // geometry (for tangent and curvature continuities).
    // For example : for a tangent continuity, in both modification mode,
    // the tangent direction can be computed with the initial surface tangent
    // directions OR with the new tangent directions, taking into account the
    // point continuity.
    // iModifiedSurface = 1 to use the modified surface,
    //                    0 to use the initial surface.
    // The default value is iModifiedSurface = 0.
    virtual void SetUseTheModifiedSurface(CATLONG32 iSurfIndex,CATLONG32 iModifiedSurface) = 0;
    virtual CATLONG32 GetUseTheModifiedSurface(CATLONG32 iSurfndex) = 0;

    // Manage the tangent mode
    // continuities
    // iTangentMode = 0 keep the position at the common border for 
    //                  computing the tangents
    //                1 the common border may be modified for computing
    //                  the tangents
    // The default value is iTangentMode = 0.
    virtual void SetTangentMode(CATLONG32 iTangentMode) = 0;
    virtual CATLONG32 GetTangentMode() const = 0;

    // Manage the curvature mode
    // curvature continuities
    // iCurvatureMode = 0 keep the position and tangents at the common 
    //                    border for computing the tangents
    //                  1 the common border and tangents may be modified 
    //                    for computing the tangents
    // The default value is iCurvatureMode = 0.
    virtual void SetCurvatureMode(CATLONG32 iCurvatureMode) = 0;
    virtual CATLONG32 GetCurvatureMode() const = 0;

    //
    // Matching Method
    // The default value is imatch = CATGeometricMatch
    //   also valid : CATAnalyticMatch
    virtual void SetMatchingMethod(const CATMatchMode imatch) = 0;
    virtual CATMatchMode GetMatchingMethod() const = 0; 
    //
    // Manage the opposite side continuity
    // The default value is iContinuity = CATFrFPointCont
    //    valid values for edgeindex are 1 and 2
    virtual void SetOppositeSideContinuity(CATLONG32 edgeindex, const CATFrFContinuity iContinuity) = 0;
    virtual CATFrFContinuity GetOppositeSideContinuity(CATLONG32 edgeindex) const  = 0;
    

    // Tangent Parameter (with a connection continuity >= 1)
    // The operator applys a law on the surfaces tangent norm. 
    // The default value is iLaw = constant law = 1.0.
    virtual void SetTangentParameter(CATLONG32 edgeindex, const CATLaw * iLaw) = 0;
    virtual void GetTangentParameter(CATLONG32 edgeindex, CATLaw *& oLaw) const = 0;

    // Tangent Direction (with a connection continuity >= 1)
    // The tangent direction of the surfaces may take three values : 
    //    * The surface tangent keeps its own direction (at a projection distortion),
    //      the tangent direction is FREE.
    //    * The tangent is collinear with the reference tangent,
    //      the tangent direction is COLLINEAR.
    //    * The angle is given by the user : a law is applied on the tangent
    //      direction in FREE mode.
    // iLaw is used only if iStartMode = iEndMode = FREE.
    // The default values are iStartMode = iEndMode = COLLINEAR.
    //                        iLaw = constant = 0.0
    virtual void SetTangentDirection(CATLONG32 edgeindex, const CATFrFTangentDirection iStartMode,
                     const CATFrFTangentDirection iEndMode,
                     const CATLaw * iLaw = 0) = 0;
    virtual void GetTangentDirection(CATLONG32 edgeindex, CATFrFTangentDirection & oStartMode,
                     CATFrFTangentDirection & oEndMode,
                     CATLaw * oLaw = 0) const = 0;
    // Manage the diffusion  
    // iDiffusion = 0 : Matching creates only a local deformation.
    // iDiffusion = 1 : Deformation will be diffused along the surfaces.
    virtual void SetDiffusion(CATLONG32 edgeindex, const CATLONG32 iDiffusion) = 0;
    virtual CATLONG32 GetDiffusion(CATLONG32 edgeindex) const = 0;

    // Homogenization
    // iHomogenization = 0 : the longitudinal degree/knotvector
    //                       of the corresponding surface will not be changed
    //                       automatically. Manual changes via SetLongitudinalDegree
    //                       are possible
    // iHomogenization = 1 : the longitudinal degree/knotvector
    //                       of the corresponding surface may be changed to 
    //                       improve the matching quality.
    // The default value is : iHomogenisation = 0
    virtual void SetHomogenization(CATLONG32 edgeindex, const CATLONG32 iHomogenisation) = 0;
    virtual CATLONG32 GetHomogenization(CATLONG32 edgeindex) const = 0;

    // Degrees
    // Longitudinal and transversal degrees constraints.
    // The SetLongitudinalDegree method should be called with Homogenization = 0.
    // The default values are the original degrees of the surfaces. 
    virtual void SetLongitudinalDegree(CATLONG32 edgeindex, CATLONG32 NLongi) = 0;
    virtual void SetTransversalDegree(CATLONG32 edgeindex, CATLONG32 NTrans) = 0;
    virtual void GetDegrees(CATLONG32 edgeindex, CATLONG32 &LongiD , CATLONG32 &TransD) const = 0;


    // ExtremitiesDirections
    // To have the extremities direction of the surfaces
    virtual void GetExtremitiesDirections(CATLONG32 edgeindex, CATMathDirection * oStartTangent,
                               CATMathDirection * oEndTangent,
                               double * oComputedAngles) = 0;
    // PlanarOption
    // To set/unset the planar option. The planar option consists in moving
    // the control points in one direction. This direction may be constant, 
    // given by the user ; or it may be the local tangent plane normal.
    // iMode = 0  -->  unset the planar option,
    // iMode = 1  -->  set the option, with the local tangent plane normal,
    // iMode = 2  -->  set the option, with a given constant direction : iDirection.
    virtual void SetPlanarOption(CATLONG32 edgeindex, CATLONG32 iMode, CATMathDirection * iDir = 0) = 0; 
   
    // Check the transition quality
    // To get the maximum deviations. 
    // Use CATTransitionCheckingCommand.h for the command and the result.
    virtual void GetMaxDeviation(CATTransitionCheckingCommand iCmd,
                                 CATTransitionDeviationResult &oDeviation) = 0;  
};
#endif
*/






