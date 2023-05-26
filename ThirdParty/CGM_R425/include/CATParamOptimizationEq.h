// COPYRIGHT DASSAULT SYSTEMES 2002 
//=============================================================================
//
// CATParamOptimizationEq: 
//
//=============================================================================
//
// Usage notes:
// MMO : Je laisse l'ancienne version de CreateCATParamOptimizationEq()
// le temps de faire migrer 
// FreeFormOperators.tst\FrFFittingTSTSh.m\src\CATFitToPtsAndDerivTest07.cpp
//
//=============================================================================
// 29/12/03 : MMO : Versionning pour CATDistanceMinPtCrv (Ajout de _Config)
// 01/01/01 : DJ  : Creation
//=============================================================================

#ifndef CATParamOptimizationEq_H
#define CATParamOptimizationEq_H

#include "CATParamOptimizationEq.h"
#include "CATCurve.h"
#include "CATNurbsCurve.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATMathDirection.h"
#include "CATKnotVector.h"
#include "CATMathMxNMatrix.h"
#include "CATMathMxNBandMatrix.h"
#include "CATMathSetOfPoints.h"
#include "FrFFitting.h"
#include "CATGeoFactory.h"

class CATSoftwareConfiguration;

//-----------------------------------------------------------------------------

class ExportedByFrFFitting CATParamOptimizationEq
 
{

public :
        
    virtual ~CATParamOptimizationEq () {} ;
    
/**
 * Before Run().
 */

    virtual void SetCPAndKnotVector (const CATMathSetOfPoints  * iCtrPt, 
                                     const CATKnotVector       * iKvU )     = 0 ;

//  Geometric continuity at ends: 
//  Let D, S ant T be first, second and third derivative and set h = 1/|D|.
//  Now, curvatures for G2 continuity (Cr) are given as D^S*h*h*h.
//  For G3 continuity, give DCr by D^(T-3*S*D*S*h*h)*h*h*h*h.
//  Of course, if DCr is set, Cr must be set and if Cr is set, TG must be set!
    virtual void SetTargetData (CATLONG32                iNbPoints,
                                const CATMathPoint     * iArrayOfTargetPt,
                                const CATMathDirection * iFirstEndTG  = NULL,
                                const CATMathDirection * iLastEndTG   = NULL,
                                const CATMathVector    * iFirstEndCr  = NULL,
                                const CATMathVector    * iLastEndCr   = NULL,
                                const CATMathVector    * iFirstEndDCr = NULL,
                                const CATMathVector    * iLastEndDCr  = NULL ) = 0 ;

// If target is given by Reference curve "iNbGridPtsPerCtrPt" must be set at next method.
    virtual void SetTargetData ( CATCurve * iRefCurve )                     = 0 ;

    virtual void SetCurrentCurve(CATNurbsCurve * iCurve,
                                 CATLONG32            iNbGridPtsPerCtrPt = 6 )   = 0 ;

/**
 * Run() :
 */
    virtual void Run()                                                      = 0 ;
    
/**
 * After Run()
 */

    virtual double GetMeanDuLength ()                                       = 0 ; 

    virtual void GetMaxDeviation(double & oMaxdev,
                                 CATLONG32   & oPointInd,
                                 double & oParam )                          = 0 ;

    virtual double GetParamDegeneration ( CATMathDirection * iRoughDir )    = 0 ;

    virtual void GetPtFittingEq (CATMathMxNBandMatrix *& oCoef,
                                 double               *& oKnotCoef,
                                 double               *& oRHS )             = 0 ;                    

    virtual void GetSmoothingEqTypeIII (CATMathMxNBandMatrix *& oCoef,
                                        double               *& oKnotCoef,
                                        double               *& oRHS )      = 0 ;                    

    
    virtual void GetSmoothingEq (double                  iSmoothCoefOnPoints,
                                 double                  iSmoothCoefOnTangents,
                                 double                  iSmoothCoefOnCurvatures,
//                                 double                  iForceOnDerivLength,
                                 CATMathMxNBandMatrix *& oCoef,
                                 double               *& oKnotCoef,
                                 double               *& oRHS )             = 0 ;                 
    
/**
 * Used to handle curvature at curve ends.
 */    
    virtual void GetEndCurvatureEq (CATLONG32                    iBandWidth,
                                    CATMathMxNBandMatrix *& oECCoef,
                                    double               *& oECKnotCoef,
                                    double               *& oECRHS )        = 0 ; 
    
/**
 * These two method only needs previous use of SetCPAndKnotVector(...).
 */    
    virtual void GetStiffCoef   (CATMathMxNBandMatrix *& oStiffCoef )       = 0 ;

    virtual void RegularPolygon (CATMathMxNBandMatrix *& oRegPol,
                                 double               *& oRHSRPol )         = 0 ; 

};

ExportedByFrFFitting CATParamOptimizationEq * CreateCATParamOptimizationEq(CATSoftwareConfiguration * iConfig) ;

ExportedByFrFFitting CATParamOptimizationEq * CreateCATParamOptimizationEq() ; // Ancienne version a tuer 

#endif
