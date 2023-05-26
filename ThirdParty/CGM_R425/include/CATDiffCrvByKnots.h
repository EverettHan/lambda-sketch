/**
 * COPYRIGHT DASSAULT SYSTEMES 2001 
 *==========================================================================
 *
 * CATDiffCrvByKnots: 
 * Differentiate a nurbs curve with respect to variable knots 
 *
 *==========================================================================
 *
 * Usage notes:
 *
 * The object is intended for repeated use without new internal allocations.
 * Thus only advanced use, is considered.
 * Internal initializations are done, only at "Run()" after "SetParameter-
 * Points(...)" and/or "SetKVData(...)". Use this fact to save CPU work. 
 * The control points of the curve to be differentiated may be selected 
 * (itteratively) from a grid. 
 *
 * The curve derivatives at the endpoints may be fixed (default). In turn 
 * this implies: 
 *    If the knot, next to the end knot, moves the control point, next to
 *    the curve end, must also move. This yields a particular constrained
 *    derivative, useful at curve fitting.
 *
 * The output:
 *
 * The result is a MxN band matrix where the first 3*iNbPar rows are curve
 * points differentiated with respect to free knots. Its (3*i, j) element is 
 * the i*th points x-coordinate differentiated with respect to the j:th free 
 * knot. Its (1+3*i, j) element is the corresponding y-coordinated differen-
 * tiated by the j:th free knot etc. 
 * If "SetApplyToCrvDerivativeUpToOrder( 1 )" (default) the following 
 * 3*iNbPar rows are the curve first derivatives, in turn differentiated 
 * with respect to free knots. 
 * If "SetApplyToCrvDerivativeUpToOrder( 2 )" the second curve derivatives 
 * are also differentiated and occurs in the third 3*iNbPar groups of rows.
 *
 * The matrix is filled ( row length = band width ) due to the particular
 * use planned (Fev -01). 
 *
 *========================================================================== 
 * Fev 01     Creation                  Daniel Johansson
 *========================================================================== 
 */

#ifndef CATDiffCrvByKnots_H
#define CATDiffCrvByKnots_H

#include <iostream.h>
#include "CATDiffCrvByKnots.h"
#include "CATMathGridOfPoints.h"
#include "CATMathSetOfPoints.h"
#include "CATMathMxNBandMatrix.h"
#include "CATKnotVector.h"
#include "FrFFitting.h"
#include "CATCGMVirtual.h"

class ExportedByFrFFitting  CATDiffCrvByKnots : public CATCGMVirtual
{
    
public :
    
/**
 * destructor
 */
    virtual ~CATDiffCrvByKnots() {} ;    
             
/**
 * Before run:
 */    
    virtual void SetCurveControlPoints ( const CATMathGridOfPoints  *iCtrPt )  = 0 ;
    virtual void ChooseUCurveFromGrid  ( const CATLONG32 iIndCurveInUDirection )      = 0 ;
    virtual void ChooseVCurveFromGrid  ( const CATLONG32 iIndCurveInVDirection )      = 0 ;

    virtual void SetCurveControlPoints ( const CATMathSetOfPoints  *ioCtrPt )  = 0 ;

    virtual void SetParameterPoints    ( const CATLONG32 iNbPar, const double *iParam ) = 0 ;
    
    virtual void SetKVData             ( CATKnotVector *iKV, const CATLONG32 *iFreeKnots )      = 0 ;

    virtual void SetFixedEndDerivatives ( const CATLONG32 iYes = 1 )                = 0 ;

    virtual void SetApplyToCrvDerivativeUpToOrder ( const CATLONG32 iOrder = 1 )    = 0 ;

/**
 * Run ...
 */
    virtual void Run() = 0 ;

/**
 * After run:
 * The matrix oResult belongs to this object and may not be deleted.
 */
    virtual void GetResult ( CATMathMxNBandMatrix *&oResult )  = 0 ;
 
} ;

/**
 * Creator ...
 */

ExportedByFrFFitting CATDiffCrvByKnots * CreateCATDiffCrvByKnots() ;

#endif




