// COPYRIGHT DASSAULT SYSTEMES 2002 
//==========================================================================
//
// CATDiffCrvByCPAndKnt: 
//
//==========================================================================
//
// Usage notes: 
//
//========================================================================== 
// Jan 01     Creation                  Daniel Johansson
//========================================================================== 

#ifndef CATDiffCrvByCPAndKnt_H
#define CATDiffCrvByCPAndKnt_H

#include "CATDiffCrvByCPAndKnt.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATMathDirection.h"
#include "CATKnotVector.h"
#include "CATMathMxNMatrix.h"
#include "CATMathSetOfPoints.h"
#include "FrFFitting.h"
#include "CATMathMxNBandMatrix.h"
#include "CATCGMVirtual.h"

//-----------------------------------------------------------------------------

class ExportedByFrFFitting CATDiffCrvByCPAndKnt : public CATCGMVirtual
 
{

public :
        
    virtual ~CATDiffCrvByCPAndKnt () {} ;
    
/**
 * Before Run() :
 */


/**
 * If "Get_d3CdU2dX_d3CdU2dT(...)" or "GetBasisValuesForD2()" is to be used, the 
 * third derivatives "iArrayOfCrvD3" must be given! 
 */
    virtual void SetCurrentCrvData(const CATMathSetOfPoints  * iCtrPt,
                                         CATLONG32             iNrParU, 
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
 * After Run(). The output objects must not be deleted :
 */
    virtual const CATLONG32            * GetXRowStruct      ( CATLONG32 iRowIndex )                   = 0 ;

    virtual       CATLONG32              GetXColStart       ( CATLONG32 iRowIndex )                   = 0 ;

    virtual       CATLONG32              GetXArrayInd       ( CATLONG32 iRowIndex )                   = 0 ;

    virtual const CATMathMxNBandMatrix * GetBasisValuesForPt()              = 0 ;

    virtual const CATMathMxNBandMatrix * GetBasisValuesForDu()              = 0 ;

/**
 * If "iFreeKnots" (given above by "SetKnotVector(...)") only contains zeroes, null 
 * pointers replace the T-derivatives in each of the following four methods:  
 */
    virtual void Get_dUdX_dUdT    (const double *& odUdX, 
                                   const double *& odUdT )                    = 0 ;

    virtual void Get_dCdX_dCdT    (const double *& odCdX,
                                   const double *& odCdT )                    = 0 ;

    virtual void Get_d2CdUdX_d2CdUdT (const double *& od2CdUdX,
                                      const double *& od2CdUdT )            = 0 ;

/**
 * If the third derivatives "iArrayOfCrvD3" are not given, null 
 * pointers are returned by the following two methods:  
 */
    virtual void Get_d3CdU2dX_d3CdU2dT (const double *& od3CdU2dX,
                                        const double *& od3CdU2dT )         = 0 ;

    virtual const CATMathMxNBandMatrix * GetBasisValuesForD2()              = 0 ;

    virtual const CATLONG32 GetDXSize()                                          = 0 ;


};

ExportedByFrFFitting CATDiffCrvByCPAndKnt * CreateCATDiffCrvByCPAndKnt() ;

                                                
#endif




