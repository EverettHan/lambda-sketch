// COPYRIGHT DASSAULT SYSTEMES 1999 
//==========================================================================
//
// CATFitSurfToPtsAndDeriv: .
//
//==========================================================================
//
// Usage notes: 
// The number of cotrol points associated to a knot vector must never be 
// greater than the number of grid points. This 
// applies the two parameter direction separatedly.
// 
// The Knot vectors should agree with the parameters, iParU and
// iParV. and should agree with the knot vector of the surface.
// The objective is the option to change multiplicities, to change degree or 
// to surpress nodes but NOT to change the parametrization intervals.
//
// Weights on the derivatives increase (or decrease) tangency compliance on 
// expence of point deviation. Recomended: 1.0. 
//
//========================================================================== 
// Nov 99     Creation                  Daniel Johansson
//========================================================================== 

#ifndef CATFitSurfToPtsAndDeriv_H
#define CATFitSurfToPtsAndDeriv_H

#include <iostream.h>
#include "CATFitSurfToPtsAndDeriv.h"
#include "CATMathGridOfPoints.h"
#include "CATMathSetOfPoints.h"
#include "CATNurbsSurface.h"
#include "CATNurbsCurve.h"
#include "CATCrvParam.h"
#include "CATCrvEvalCommand.h"
#include "CATMathPoint.h"
#include "CATKnotVector.h"
#include "CATMath3x3Matrix.h" 
#include "CATMathMxNMatrix.h"
#include "CATMathMxNFullMatrix.h"
#include "CATMathVector.h"
#include "CATMathDirection.h"
#include "CATFrFUtiNurbs.h"
#include "CATMetaClass.h"
#include "CATGeometry.h"
#include "CATMathDef.h"
#include "FrFFitting.h"
#include "CATCGMVirtual.h"

//-----------------------------------------------------------------------------

class ExportedByFrFFitting CATFitSurfToPtsAndDeriv : public CATCGMVirtual
 
{

public :
        
    virtual ~CATFitSurfToPtsAndDeriv () {} ;
    
    virtual void Run() = 0 ;

    virtual void SetOtherKnotVectors (const CATKnotVector *iKvU,    
                                      const CATKnotVector *iKvV ) = 0 ;

    virtual void SetOtherArrays (const CATMathPoint  *iArrayOfPt,
                                 const CATMathVector *iArrayOfDu,
                                 const CATMathVector *iArrayOfDv,
                                 const CATMathVector *iArrayOfDuv = NULL ) = 0 ;

    virtual void SetOtherWeights (const double  iWeightOnDu,
                                  const double  iWeightOnDv ) = 0 ;

    //**** Analysis of result. Four methods. ****
    // Use after "Run" but before any change of arrays or any further change 
    // of the surface. 
    // (Evaluated in grid given by iParU and iParV) 
    
    // These first two methods are faster. Returned 1 indicates exceeded, 0 not.:
    virtual CATLONG32    PointToleranceIsExceeded ( double iPtTolInLUnits ) = 0 ;
    virtual CATLONG32 TangencyToleranceIsExceeded ( double iTgTolInRadians ) = 0 ;
    
    // Index or indices of worst error point may be retrieved:
    virtual void GetPointErrors(double      &oPtErrorInLUnits, 
                                CATLONG32   *oIndU = NULL,
                                CATLONG32   *oInvV = NULL) = 0 ;

    // As "PointError" above but also (u,v)-direction of
    // the error may be retrieved. (True radians only for small angles.):
    virtual void GetTangencyErrors(double      &oTgErrorInRadians, 
                                   CATLONG32   *oIndU = NULL,
                                   CATLONG32   *oIndV = NULL,
                                   double      *oDirU = NULL,
                                   double      *oDirV = NULL ) = 0 ;
    
};

// Creator for Surface fitting. Cross derivatives ARE NOT given (but well estimated):

ExportedByFrFFitting
CATFitSurfToPtsAndDeriv * CreateCATFitSurfToPtsAndDeriv(const CATMathPoint    *iArrayOfPt,
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

// Creator for Surface fitting. Cross derivatives ARE given:

ExportedByFrFFitting
CATFitSurfToPtsAndDeriv * CreateCATFitSurfToPtsAndDeriv(const CATMathPoint    *iArrayOfPt,
                                                const CATMathVector *iArrayOfDu,
                                                const CATMathVector *iArrayOfDv,
                                                const CATMathVector *iArrayOfDuv,
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
void Remove ( CATFitSurfToPtsAndDeriv *&iCATFitSurfToPtsAndDeriv ) ;
                                                
#endif




