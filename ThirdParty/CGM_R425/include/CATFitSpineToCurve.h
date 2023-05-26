/**
 * COPYRIGHT DASSAULT SYSTEMES 2001 
 *==========================================================================
 *
 * CATFitSpineToCurve: 
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
 * Mar 01     Creation                  Daniel Johansson
 *========================================================================== 
 */

#ifndef CATFitSpineToCurve_H
#define CATFitSpineToCurve_H

#include "CATFitSpineToCurve.h"
#include "CATCurve.h"
#include "CATNurbsCurve.h"
#include "CATGeoFactory.h"
#include "CATKnotVector.h"
#include "FrFFitting.h"
#include "CATCGMVirtual.h"

class ExportedByFrFFitting  CATFitSpineToCurve : public CATCGMVirtual
{
    
public :
    
    /**
    * destructor
    */
    virtual ~CATFitSpineToCurve() {} ;    
    
    /**
    * Before run:
    */    
    
    virtual void SetCurve( const CATCurve *iPreSpine, CATKnotVector *iStartKV = NULL ) = 0 ; 
    
    /**
    * Run:
    */        
    virtual CATLONG32 Run() = 0 ;
    /**
    * After run:
    */    
    
    virtual void GetSpine( CATNurbsCurve *&oSpine ) = 0 ; 
} ;

/**
* Creator ...
*/

ExportedByFrFFitting CATFitSpineToCurve * CreateCATFitSpineToCurve(const CATCurve   *iPreSpine,
                                                                   const double      iTolPt,
                                                                   const double      iTolTg,
                                                                   const CATLONG32   iMaxDeg,
                                                                   CATGeoFactory    *iFactory) ;

#endif




