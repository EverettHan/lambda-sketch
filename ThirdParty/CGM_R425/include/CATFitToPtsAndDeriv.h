// COPYRIGHT DASSAULT SYSTEMES 1999 
//==========================================================================
//
// CATFitToPtsAndDeriv: .
//
//==========================================================================
//
// Usage notes: 
// The number of cotrol points associated to a knot vector must never be 
// greater than the number of grid points. In case of surface fitting this 
// applies the two parameter direction separatedly.
// 
// The Knot vector (or vectors) should agree with the parameters, iParU (and
// iParV) and should agree with the knot vector of the curve (or surface).
// The objective is the option to change multiplicities, to change degree or 
// to surpress nodes but NOT to change the parametrization interval.
//
// Weights on the derivatives increase (or decrease) tangency compliance on 
// expence of point deviation. Recomended: 1.0. 
//
//========================================================================== 
//   /11/99 DJn Creation                                    Daniel Johansson
// 11/07/18 NLD XScale
//              - reception iTolObject dans CreateCATFitToPtsAndDeriv()
//              Mise au propre
//              - reordonnancement logique des includes
//              - detabulation
//========================================================================== 

#ifndef CATFitToPtsAndDeriv_H
#define CATFitToPtsAndDeriv_H

#include <iostream.h>
#include "CATFitToPtsAndDeriv.h"

#include "CATTolerance.h"

#include "CATMathDef.h"
#include "CATMathVector.h"
#include "CATMathDirection.h"
#include "CATMathPoint.h"
#include "CATMath3x3Matrix.h" 
#include "CATMathMxNMatrix.h"
#include "CATMathMxNFullMatrix.h"
#include "CATMathGridOfPoints.h"
#include "CATMathSetOfPoints.h"

#include "CATKnotVector.h"

#include "CATGeometry.h"
#include "CATNurbsSurface.h"
#include "CATNurbsCurve.h"
#include "CATCrvParam.h"
#include "CATCrvEvalCommand.h"

#include "CATFrFUtiNurbs.h"

#include "CATMetaClass.h"
#include "FrFFitting.h"
#include "CATCGMVirtual.h"

//-----------------------------------------------------------------------------

class ExportedByFrFFitting CATFitToPtsAndDeriv : public CATCGMVirtual
 
{

public :
        
    virtual ~CATFitToPtsAndDeriv () {} ;
    
    virtual void Run() = 0 ;

    // If Optimizing, for instance by increasing degree is planned, call this
    // before calling Run. (Then some intermediate data can be reused.):
    virtual void SetOptimizingWillBeDone ( const CATLONG32 yes ) = 0 ;

    // If, and only if, curve fitting, omit *iKvV :
    virtual void SetOtherKnotVectors (const CATKnotVector *iKvU,    
                                      const CATKnotVector *iKvV = NULL ) = 0 ;

    // If, and only if, curve fitting, omit *iArrayOfDv :
    virtual void SetOtherArrays (const CATMathPoint  *iArrayOfPt,
                                 const CATMathVector *iArrayOfDu,
                                 const CATMathVector *iArrayOfDv = NULL ) = 0 ;

    // If, and only if, curve fitting, omit *iWeightOnDv : 
    virtual void SetOtherWeights (const double  iWeightOnDu,
                                  const double  iWeightOnDv = 0.0 ) = 0 ;

    //**** Analysis of result. Four methods. ****
    // Use after "Run" but before any change of arrays or any further change 
    // of the curve or the surface. 
    // (Evaluated in grid given by iParU (and, if surface, iParV)) 
    
    // These first two methods are faster:
    virtual CATLONG32    PointToleranceIsExceeded ( double iPtTolInLUnits ) = 0 ;
    virtual CATLONG32 TangencyToleranceIsExceeded ( double iTgTolInRadians ) = 0 ;
    
    // Index or indices of worst error point may be retrieved:
    virtual void GetPointErrors(double    &oPtErrorInLUnits, 
                                CATLONG32 *oIndU = NULL,
                                CATLONG32 *oInvV = NULL) = 0 ;

    // As "PointError" above but also, if surf fitting, (u,v)-direction of
    // the error may be retrieved. (True degrees only for small angles.):
    virtual void GetTangencyErrors(double    &oTgErrorInRadians, 
                                   CATLONG32 *oIndU = NULL,
                                   CATLONG32 *oIndV = NULL,
                                   double    *oDirU = NULL,
                                   double    *oDirV = NULL ) = 0 ;
    
};

// For Curve fitting:
ExportedByFrFFitting 
CATFitToPtsAndDeriv * CreateCATFitToPtsAndDeriv(const CATTolerance  &iTolObject,
                                                const CATMathPoint  *iArrayOfPt,
                                                const CATMathVector *iArrayOfDu,
                                                const double         iWeightOnDu,
                                                const CATKnotVector *iKvU,
                                                const CATLONG32      iNrParU,
                                                const double        *iParU,
                                                CATNurbsCurve       *ioNurbCrv ) ;

// For Surface fitting:
ExportedByFrFFitting
CATFitToPtsAndDeriv * CreateCATFitToPtsAndDeriv(const CATTolerance  &iTolObject,
                                                const CATMathPoint  *iArrayOfPt,
                                                const CATMathVector *iArrayOfDu,
                                                const CATMathVector *iArrayOfDv,
                                                const double         iWeightOnDu,
                                                const double         iWeightOnDv,
                                                const CATKnotVector *iKvU,
                                                const CATKnotVector *iKvV,
                                                const CATLONG32      iNrParU,
                                                const CATLONG32      iNrParV,
                                                const double        *iParU,
                                                const double        *iParV,
                                                CATNurbsSurface     *ioNurbSur ) ;

ExportedByFrFFitting
void Remove ( CATFitToPtsAndDeriv *&iCATFitToPtsAndDeriv ) ;
                                                
#endif




