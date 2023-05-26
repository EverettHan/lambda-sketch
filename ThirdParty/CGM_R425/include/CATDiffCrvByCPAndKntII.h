// COPYRIGHT DASSAULT SYSTEMES 2002 
//==========================================================================
//
// CATDiffCrvByCPAndKntII: .
//
//==========================================================================
//
// Usage notes: 
//
//========================================================================== 
// Jan 01     Creation                  Daniel Johansson
//========================================================================== 

#ifndef CATDiffCrvByCPAndKntII_H
#define CATDiffCrvByCPAndKntII_H

#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATMathDirection.h"
#include "CATKnotVector.h"
#include "CATMathMxNMatrix.h"
#include "CATMathSetOfPoints.h"
#include "FrFFitting.h"
#include "CATCGMVirtual.h"

//-----------------------------------------------------------------------------

class ExportedByFrFFitting CATDiffCrvByCPAndKntII  : public CATCGMVirtual
 
{

public :
        
    virtual ~CATDiffCrvByCPAndKntII () {}
    
/**
 * Before Run().
 * Observe that all these settings, except "iArrayOfTargetPt", must be 
 * consistent with the current state of one particular curve. In other
 * case the results are useless!
 */

/**
 * If curvature are to be handeled, the third derivatives "iArrayOfCrvD3" must be given! 
 */
    virtual void SetCurrentCrvData(const CATMathSetOfPoints  * iCtrPt,
                                   CATLONG32                   iNrParU, 
                                   const double              * iParamU,
                                   const CATMathPoint        * iArrayOfCrvP,  
                                   const CATMathVector       * iArrayOfCrvDu,
                                   const CATMathVector       * iArrayOfCrvD2,
                                   const CATMathVector       * iArrayOfCrvD3 = NULL ) = 0 ;

    virtual void SetTargetData(const CATMathPoint      * iArrayOfTargetPt,
                               const CATMathDirection  & iFirstEndTG,
                               const CATMathDirection  & iLastEndTG )       = 0 ;

    virtual void SetKnotVector  (const CATKnotVector   * iKvU, 
                                 const CATLONG32       * iFreeKnots   )     = 0 ;

/**
 * Run() :
 */
    virtual void Run()                                                      = 0 ;
    
/**
 * After Run(). The output pointers must not be deleted :
 * If "iFreeKnots" (given above by "SetKnotVector(...)") only contains zeroes, null 
 * pointers replace the T-derivatives in each of the following four methods:  
 */

/**
 * X- and T-derivatives of curve points ("Pt").
 */
    virtual void Get_dPtdX_dPtdT ( const double *& odPtdX, 
                                   const double *& odPtdT )                 = 0 ; 

/**
 * Lengths ("Ln") of curve U-derivatives and their X- and T-derivatives.
 */
    virtual void Get_Ln_dLndX_dLndT ( const double *& oLn, 
                                      const double *& odLndX, 
                                      const double *& odLndT )              = 0 ;
/**
 * Unit tangents ("Tg") and their derivatives.
 */
    virtual void Get_Tg_dTgdX_dTgdT ( const double *& oTg, 
                                      const double *& odTgdX, 
                                      const double *& odTgdT )              = 0 ;

/**
 * Curvatures ("Cr") and their derivatives. If the third derivatives "iArrayOfCrvD3" 
 * are not given, null pointers are returned!  
 */
    virtual void Get_Cr_dCrdX_dCrdT ( const double *& oCr, 
                                      const double *& odCrdX, 
                                      const double *& odCrdT )              = 0 ;

/**
 * The X-drivatives are compactly given in arrays of doubles. These methods tells
 * the ordering of these derivatives. See its use! It's to messy to explain.
 */
    virtual const CATLONG32 * GetXRowStruct ( CATLONG32 iRowIndex )                   = 0 ;

    virtual CATLONG32 GetXColStart ( CATLONG32 iRowIndex )                            = 0 ;

    virtual CATLONG32 GetXArrayInd ( CATLONG32 iRowIndex )                            = 0 ;

};

ExportedByFrFFitting CATDiffCrvByCPAndKntII * CreateCATDiffCrvByCPAndKntII() ;

                                                
#endif




