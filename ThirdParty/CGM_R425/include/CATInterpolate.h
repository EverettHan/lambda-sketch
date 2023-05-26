
//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2002
//===================================================================
//
// CATInterpolate :
// Cubic interpolation in simple table of values and derivatives 
//
//===================================================================
// Usage notes:
//
//===================================================================
// Dec 02   Creation                         D. Johansson
//===================================================================

#ifndef CATInterpolate_H  
#define CATInterpolate_H 

#include "FrFFitting.h"
#include <stdlib.h>
#include "CATDataType.h"
#include "CATCGMVirtual.h"

class ExportedByFrFFitting CATInterpolate : public CATCGMVirtual

{    
 public:

/**
 * Object management
 */

     virtual ~CATInterpolate () {} ;

/**
 * Refill ?
 */    
    virtual void Reset() = 0 ;

/**
 * The iPdata and iDdata are supposed to have length corresponding 
 * to iDiffOffset. See CreateCATInterpolate(...).
 */    
    virtual void AddNextRow ( double iU, double *iPdata, double *iDdata, double *iSdata = NULL ) = 0 ;

/**
 * The table may initillay been filled backwards, i.e. by descending iU. Then, before
 * you fill in ascending order and before evaluation, this metod must be used: 
 */
    virtual void ReverseTableRows () = 0 ;

/**
 * Evaluation of the interpolation table. 
 * Differentiation is done at iDerivLevel. Zero gives point evaluation.
 * Evaluation of point elements from colum iStartCol to, but not including, iEndColP1 ( P1 = +1 ).
 * The derivative elements are included internaly in the evaluation, by the use of iDiffOffset.
 * ioRes is supposed to be of length iEndColP1 - iStartCol (at least).
 */
    virtual void Eval( 
        double    iU, 
        CATLONG32 iStartCol, 
        CATLONG32 iEndColP1, 
        CATLONG32 iDerivLevel, 
        double   *ioRes ) = 0 ;

/**
 * Local evaluation of extern data (during the creation of the table).
 * Differentiation at iDerivLevel. Zero gives point evaluation.
 * Evaluation of elements from colum iStartCol to, but not including, iEndColP1 ( P1 = +1 ).
 * if iEndColP1 == 0, the value of "iDiffOffset" is assumed. (see the creator below.) 
 * ioRes is supposed to be of length iEndColP1 - iStartCol (at least).
 * *iP0, *iD0 ... and iDeltaU define the cubic function to be evaluated at iLocalU. 
 */
    virtual void EvalExtern(
        double     iLocalU, 
        double     iDeltaU, 
        double    *iP1, 
        double    *iD1,  
        double    *iP2, 
        double    *iD2, 
        CATLONG32  iDerivLevel, 
        double    *ioRes,
        CATLONG32  iStartCol = 0,
        CATLONG32  iEndColP1 = 0 ) = 0 ; 

    virtual void EvalExtern(
        double    iLocalU, 
        double    iDeltaU, 
        double   *iP1, 
        double   *iD1, 
        double   *iS1, 
        double   *iP2, 
        double   *iD2, 
        double   *iS2, 
        CATLONG32 iDerivLevel, 
        double   *ioRes,
        CATLONG32 iStartCol = 0,
        CATLONG32 iEndColP1 = 0 ) = 0 ; 
  
} ;

/**
 * Creator
 * iNbRows are supposed to be 1 + number of expected segments.
 * Interpolation is cubic if iQuintic = 0, otherwise quintic.
 * iNbCol is supposed to be (2 + iQintic) * iDiffOffset Point data 
 * are supposed to be in the first iDiffOffset number of columns
 * and the corresponding U-derivatives in the remaining columns.
 */
ExportedByFrFFitting  
CATInterpolate * CreateCATInterpolate( CATLONG32 iNbRows, CATLONG32 iNbCol, CATLONG32 iDiffOffset, CATLONG32 iQuintic = 0 ) ;     

#endif  
