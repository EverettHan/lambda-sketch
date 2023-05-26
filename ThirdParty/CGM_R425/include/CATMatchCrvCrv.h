// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATMatchCrvCrv:
// Interface class of the Match Curve Curve Operator.
//
//=============================================================================
//
// Usage notes:
// This class can be used as is for Match Curve Curve.
//
//============================================================================
// 02/12/11 : MWE : ajout de SetExtension/GetExtension et SetTangentMode/GetTangentMode
// August 1999  Creation                                               ALM
//=============================================================================

#ifndef CATMatchCrvCrv_H
#define CATMatchCrvCrv_H

#include "FrFOpeCrv.h"
#include "CATFreeFormDef.h"
#include "CATCGMVirtual.h"

class CATCurve;
class CATPoint;

//-----------------------------------------------------------------------------
class ExportedByFrFOpeCrv CATMatchCrvCrv  : public CATCGMVirtual
{
  public :
    
    virtual  ~CATMatchCrvCrv();
    //=======
    //  Run
    //=======
    virtual void Run() = 0;

    //=======================
    //  Configuration Methods
    //=======================

    // Manage the connection continuity
    // The default value is iContinuity = CATFrFPointCont.
    virtual void             SetConnectionContinuity(CATFrFContinuity iContinuity) = 0;
    virtual CATFrFContinuity GetConnectionContinuity() const = 0; 

    // Manage the opposide side continuities
    // The default value is iContinuity = CATFrFPointCont.
    virtual void             SetOppositeSideContinuity(CATLONG32 iCurveIndex, 
                                           CATFrFContinuity iContinuity) = 0;
    virtual CATFrFContinuity GetOppositeSideContinuity(CATLONG32 iCurveIndex) const = 0; 

    // Manage the match modification 
    // The available values for iCurveIndicator are :
    //    0 if the first curve is modified,
    //    1 if the second curve is modified,
    //    2 if both curves are modified.
    virtual void      SetMatchModification(CATLONG32 iCurveIndicator) = 0;
    virtual CATLONG32 GetMatchModification(CATLONG32 iCurveIndex) const = 0;

    // Manage the match reference
    // The available values for iCurveIndicator are :
    //    0 if the first curve is the reference for the iContinuity,
    //    1 if the second curve is the reference for the iContinuity,
    //    2 if both curves are used as references for the iContinuity.
    virtual void      SetMatchReference(CATFrFContinuity iContinuity,CATLONG32 iCurveIndicator) = 0;
    virtual CATLONG32 GetMatchReference(CATFrFContinuity iContinuity) const = 0;

    // Use the modified curve
    // Use the initial curve or the modified curve to compute the 
    // geometry (for tangent and curvature continuities).
    // For example : for a tangent continuity, in both modification mode,
    // the tangent direction can be computed with the initial curves tangent
    // directions OR with the new tangent directions, taking into account the
    // point continuity.
    // iModifiedCurve = 1 to use the modified curve,
    //                  0 to use the initial curve.
    // The default value is iModifiedCurve = 0.
    virtual void UseTheModifiedCurve(CATLONG32 iCurveIndex,CATLONG32 iModifiedCurve) = 0;
    //
    // in case of Both option the curves are extrapolated and the G0 point is the interstion 
    // if exists else it is the middle point of non extrapolated curves 
    virtual void  SetExtension( int iextend ) = 0;
    virtual int   GetExtension() const = 0;
    //
    // in case of Both option the G1 constraint is reached moving the G0 commun point
    virtual void  SetTangentMode( int iTangentMode ) = 0;
    virtual int   GetTangentMode() const = 0;

    // Manage the tangent tension
    // The default value is 1.
    virtual void   SetTangentTension(CATLONG32 iCurveIndex, double iTangentTension) = 0;
    virtual double GetTangentTension(CATLONG32 iCurveIndex) const = 0;
  
    // Manage the curvature tension
    // The default value is 1.
    virtual void   SetCurvatureTension(CATLONG32 iCurveIndex, double iCurvatureTension) = 0;
    virtual double GetCurvatureTension(CATLONG32 iCurveIndex) const = 0;

    // Manage the diffusion
    // The available values for iDiffusion are :
    //    0 : the deformation remains local,
    //    1 : the deformation is diffused along the curve.
    virtual void      SetDiffusion(CATLONG32 iCurveIndex, CATLONG32 iDiffusion) = 0;
    virtual CATLONG32 GetDiffusion(CATLONG32 iCurveIndex) const = 0;

    // Manage the orientation 
    virtual void SetDefaultOrientation(CATLONG32 iCurveIndex) = 0;
    virtual void ReverseOrientation(CATLONG32 iCurveIndex) = 0;

    // Manage the degree
    // The available values for iDegree are :
    //    -1 : the degree is chosen (increased if necessary) by the operator,
    //         in order to keep the specified continuities,
    //     0 : the degree is unchanged on the curve,
    //     N : the degree is set by the user.
    // The default value is 0.
    virtual void      SetDegree(CATLONG32 iCurveIndex, CATLONG32 iDegree) = 0;
    virtual CATLONG32 GetDegree(CATLONG32 iCurveIndex) const  = 0;
};
#endif





