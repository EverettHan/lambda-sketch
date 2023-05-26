// COPYRIGHT DASSAULT SYSTEMES 2001 
//==========================================================================
//
// CATFitKVOneStepCx2:
//
//==========================================================================
//
// Usage notes:
//
//========================================================================== 
// Mar 2001    Creation                  Daniel Johansson
//========================================================================== 

#ifndef CATFitKVOneStep_H
#define CATFitKVOneStep_H

#include "CATFitKVOneStep.h"
#include "CATDiffCrvByKnots.h"
#include "CATMathGridOfPoints.h"
#include "CATMathSetOfPoints.h"
#include "CATNurbsCurve.h"
#include "CATKnotVector.h"
#include "CATMathMxNBandMatrix.h"
#include "FrFFitting.h"
#include "CATCGMVirtual.h"

//-----------------------------------------------------------------------------

class ExportedByFrFFitting CATFitKVOneStep : public CATCGMVirtual

{
   
public :
        
    //destructor:    
    virtual    ~CATFitKVOneStep () {}  ;
    
    // before run: -----------------------------------------------
    
    //The curve to be differentiated may be selected from a grid
    virtual void SetGridOfData         ( const CATMathGrid *iGridOfData, const CATLONG32 iLevel = 2 ) = 0 ;
    virtual void WorkOnUCurvesFromGrid ( const CATLONG32 iNbUCurves, const CATLONG32 *iIndCurvesInUDirection ) = 0 ;
    virtual void WorkOnVCurvesFromGrid ( const CATLONG32 iNbVCurves, const CATLONG32 *iIndCurvesInVDirection ) = 0 ;

    virtual void SetSetOfData          ( const CATMathSetOf3DObjects *iSetOfData, const CATLONG32 iLevel = 2 ) = 0 ;

    virtual void SetControlPoints      ( CATMathSetOfPoints  *ioCtrPt = NULL ) = 0 ; 
    virtual void SetControlPoints      ( CATMathSetOfPoints **ioCtrPt = NULL ) = 0 ; 

    virtual void SetParameterPoints    ( const CATLONG32 iNbPar, const double *iParam ) = 0 ;
    
    virtual void SetKVData             ( const CATKnotVector *iKV, CATLONG32 *ioErr, const CATLONG32 *iFreeKnots = NULL ) = 0 ;

    virtual void SetWeight ( 
        const double   iMeanLnDeriv,
        CATLONG32      iSizeW,
        double        *iWeights,
        const double   iTolPt,
        const double   iTolTg = 0.0 ) = 0 ;

    virtual void SetSolvingMatrices ( 
        CATMathMxNBandMatrix *ioMatrixC,
        CATMathMxNBandMatrix *ioSolve,
        CATLONG32             iSizeF,
        CATLONG32            *iF ) = 0 ;

    // Run ...
    virtual CATLONG32 Run() = 0 ;
    
    // Mandatory after Run() to keep order of allocations 
    virtual void GetWeightAndF (  CATLONG32 &oSizeW, double *&oWeights, CATLONG32 oSizeF, CATLONG32 *&oF  ) = 0 ;
    
} ;

/**
 * Creator ...
 */

ExportedByFrFFitting CATFitKVOneStep * CreateCATFitKVOneStep() ;

#endif




