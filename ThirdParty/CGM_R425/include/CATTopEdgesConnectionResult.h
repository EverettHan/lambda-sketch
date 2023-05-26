//===================================================================
 // COPYRIGHT Microsoft 2014
//===================================================================
// CATTopEdgesConnectionResult.h
// Header definition of class CATTopEdgesConnectionResult
//===================================================================
//
// Usage notes:
//
//===================================================================
// 2014/02/05 Creation: DBS
//===================================================================

#ifndef CATTopEdgesConnectionResult_H
#define CATTopEdgesConnectionResult_H

#include "MultiWireCoupling.h"

#include "CATBoolean.h"
#include "CATErrorDef.h" 


#include "ListPOfCATTopEdgesNUpletResult.h"
#include "CATMathPoint.h"
#include "CATLISTP_CATMathPoint.h"


class CATTopEdgesNUpletResult;
class CATBody;
class CATGeoFactory;
class CATCGMStream;
class CATCGMOutput;


class ExportedByMultiWireCoupling CATTopEdgesConnectionResult
{

public:


    // Constructor / destructor
    //-------------------------
    CATTopEdgesConnectionResult();
    virtual ~CATTopEdgesConnectionResult();
        
    

    /**
    *  Set the result N-Uplets.
    *  @param iListOfNUplet
    *     input list of N-uplets.
    *  @return
    *     HRESULT
    *  Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT SetResultList_N_Uplets (CATLISTP(CATTopEdgesNUpletResult) & iListOfNUplet);

    /**
    *  Get the result N-Uplets.
    *  @param oListOfNUplet
    *     output list of N-uplets.
    *  @return
    *     HRESULT
    *  Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT GetResultList_N_Uplets (CATLISTP(CATTopEdgesNUpletResult) & oListOfNUplet);

    /**
    *  Set the result Body.
    *  @param ipBodyresult
    *     input body.
    *  @return
    *     HRESULT
    *  Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT SetResultBody (CATBody * ipBodyResult);

    /**
    *  Get the result Body.
    *  @param opBodyresult
    *     output body.
    *  @return
    *     HRESULT
    *  Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT GetResultBody (CATBody *& opBodyResult);

    //------------------//
    // Debug methods    //
    //------------------//

    /** 
    * @nodoc
    */
    HRESULT SetResultList_N_UpletsPoint (CATLISTP(CATMathPoint) & iListOfNUpletPoint, 
                                         CATLISTP(CATMathPoint) & iListOfBarycenter);

    /** 
    * @nodoc
    */
    HRESULT GetResultList_N_UpletsPoint (CATLISTP(CATMathPoint) & oListOfNUpletPoint, 
                                         CATLISTP(CATMathPoint) & oListOfBarycenter);

    // For CGMReplay
    void Stream( CATCGMStream  & oStr, int iVersion );
    void UnStream( CATCGMStream  & iStr, int iVersion, CATGeoFactory * iFactory, double iScaleFactor = 1. );
    void Dump( CATCGMOutput & oStr );
    CATBoolean IsEquivalentTo( CATTopEdgesConnectionResult & iOtherResult, CATGeoFactory * iFactory ) const;

private:

    //-----------------------------------------------------------------
    // Data members
    //-----------------------------------------------------------------
    
    // out
    CATLISTP(CATTopEdgesNUpletResult)   _ListOfNUplets;
    CATBody                           * _pBodyResult;

    // out debug
    CATLISTP(CATMathPoint) _ListOfNUpletPoint;
    CATLISTP(CATMathPoint) _ListOfBarycenter;
};


#endif // CATTopEdgesConnectionResult_H



