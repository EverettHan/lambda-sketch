// COPYRIGHT DASSAULT SYSTEMES 1999 
//==========================================================================
//
// CATFitCurveToPtsAndDeriv: .
//
//==========================================================================
//
// Usage notes: 
// The number of cotrol points associated to a knot vector must never be 
// greater than the number of grid points. In case of surface fitting this 
// applies the two parameter direction separatedly.
// 
// The Knot vector should agree with the parameters, iParU, and should agree 
// with the knot vector of the curve.
// The objective is the option to change multiplicities, to change degree or 
// to surpress nodes but NOT to change the parametrization interval.
//
// Weights on the derivatives increase (or decrease) tangency compliance on 
// expence of point deviation. Recomended: 1.0. 
//
//========================================================================== 
// Nov 99     Creation                  Daniel Johansson
//========================================================================== 

#ifndef CATFitCurveToPtsAndDeriv_H
#define CATFitCurveToPtsAndDeriv_H

#include <iostream.h>
#include "CATFitCurveToPtsAndDeriv.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATMathDirection.h"
#include "CATMathGridOfPoints.h"
#include "CATMathSetOfPoints.h"
#include "CATMath3x3Matrix.h" 
#include "CATMathMxNMatrix.h"
#include "CATMathMxNFullMatrix.h"
#include "CATNurbsSurface.h"
#include "CATNurbsCurve.h"
#include "CATCrvParam.h"
#include "CATCrvEvalCommand.h"
#include "CATKnotVector.h"
#include "CATFrFUtiNurbs.h"
#include "CATMetaClass.h"
#include "CATGeometry.h"
#include "CATMathDef.h"
#include "FrFFitting.h"
#include "CATCGMVirtual.h"

//-----------------------------------------------------------------------------

class ExportedByFrFFitting CATFitCurveToPtsAndDeriv : public CATCGMVirtual
 
{

public :
        
    virtual ~CATFitCurveToPtsAndDeriv () {} ;
    
    virtual void Run() = 0 ;

    // If Optimizing, for instance by increasing degree is planned, call this
    // before calling Run. (Then some intermediate data can be reused.):
    //virtual void SetOptimizingWillBeDone ( const CATLONG32 yes ) = 0 ;

    virtual void SetOtherKnotVectors (const CATKnotVector *iKvU ) = 0 ;

    virtual void SetOtherArrays (const CATMathPoint  *iArrayOfPt,
                                 const CATMathVector *iArrayOfDu ) = 0 ;

    virtual void SetOtherArrays (const CATMathPoint     *iArrayOfPt,
                                 const CATMathDirection *iArrayOfUnitTang ) = 0 ;

    virtual void SetOtherWeights (const double  iWeightOnDu ) = 0 ;

    //**** Analysis of result. Four methods. ****
    // Use after "Run" but before any change of arrays or any further change 
    // of the curve. 
    // (Evaluated in grid given by iParU) 
    
    // These first two methods are faster:
    virtual CATLONG32    PointToleranceIsExceeded ( double iPtTolInLUnits ) = 0 ;
    virtual CATLONG32 TangencyToleranceIsExceeded ( double iTgTolInRadians ) = 0 ;
    
    // Index or indices of worst error point may be retrieved:
    virtual void GetPointErrors(double &oPtErrorInLUnits, 
                                CATLONG32   *oIndU = NULL) = 0 ;

    // As "PointError" above. (True angle only when small.):
    virtual void GetTangencyErrors(double &oTgErrorInRadians, 
                                   CATLONG32   *oIndU = NULL ) = 0 ;
    
};

// For Curve fitting using points and derivatives:
ExportedByFrFFitting 
CATFitCurveToPtsAndDeriv * CreateCATFitCurveToPtsAndDeriv(const CATMathPoint  *iArrayOfPt,
                                                          const CATMathVector *iArrayOfDu,
                                                          const double         iWeightOnDu,
                                                          const CATKnotVector *iKvU,    
                                                          const CATLONG32      iNrParU,
                                                          const double        *iParU, 
                                                          CATNurbsCurve       *ioNurbCrv ) ;

// For Curve fitting using points and unit tangents:
ExportedByFrFFitting 
CATFitCurveToPtsAndDeriv * CreateCATFitCurveToPtsAndDeriv(const CATMathPoint     *iArrayOfPt,
                                                          const CATMathDirection *iArrayOfUnitTangents,
                                                          const double            iWeightOnTang,
                                                          const CATKnotVector    *iKvU,    
                                                          const CATLONG32         iNrParU,
                                                          const double           *iParU, 
                                                          CATNurbsCurve          *ioNurbCrv ) ;


ExportedByFrFFitting
void Remove ( CATFitCurveToPtsAndDeriv *&iCATFitCurveToPtsAndDeriv ) ;
                                                
#endif




