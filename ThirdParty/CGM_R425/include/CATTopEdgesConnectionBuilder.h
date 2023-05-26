//===================================================================
 // COPYRIGHT Microsoft 2014
//===================================================================
// CATTopEdgesConnectionBuilder.h
// Header definition of class CATTopEdgesConnectionBuilder
//===================================================================
//
// Usage notes:
//
//===================================================================
// 2014/02/05 Creation: DBS
//===================================================================

#ifndef CATTopEdgesConnectionBuilder_H
#define CATTopEdgesConnectionBuilder_H

#include "MultiWireCoupling.h"

#include "CATBoolean.h"
#include "CATErrorDef.h" 

#include "CATListOfDouble.h" 
#include "ListPOfCATTopEdgesNUplet.h"

class CATSoftwareConfiguration;
class CATGeoFactory;
class CATTopEdgesConnectionResult;
class CATTopEdgesNUplet;


class ExportedByMultiWireCoupling CATTopEdgesConnectionBuilder
{

public:

    //--------------------------------------------------------------------------------------
    // enum CATTopEdgesConnectionBuilderType
    //--------------------------------------------------------------------------------------
    // NOTE : add here new type to add new builder and add new inherited class 

    enum CATTopEdgesConnectionBuilderType
    {
      TopEdgesConnectionBuilderEdge    = 0,  // see CATTopEdgesConnectionBuilderEdge class
      TopEdgesConnectionBuilderNUplet  = 1   // see CATTopEdgesConnectionBuilderNUplet class
    };
    //--------------------------------------------------------------------------------------

    //--------------------------//
    // Constructor / destructor //
    //--------------------------//
    CATTopEdgesConnectionBuilder(CATSoftwareConfiguration * ipConfig,
                                 CATGeoFactory            * ipFactory);

    virtual ~CATTopEdgesConnectionBuilder();
        
    /**
    *  Set the list of N-Uplets.
    *  @param iListOfNUplets
    *     input list of N-uplets.
    *  @return
    *     HRESULT
    *  Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT SetList_N_Uplets (CATLISTP(CATTopEdgesNUplet) & iListOfNUplet);

    /**
    *  Get the list of N-Uplets.
    *  @param oListOfNUplet
    *     output list of N-uplets.
    *  @return
    *     HRESULT
    *  Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT GetList_N_Uplets (CATLISTP(CATTopEdgesNUplet) & oListOfNUplet);


    /**
    *  Sort List of N_Uplets.
    *     HRESULT
    *  Legal values : 
    *     - E_FAIL : if KO.
    *     - S_FALSE : if no result.
    *     - S_OK : if operation succeeded.
    */
    HRESULT SortList_N_Uplets ();


    /**
    *  Keep the best List of N_Uplets.
    *     HRESULT
    *  Legal values : 
    *     - E_FAIL : if KO.
    *     - S_FALSE : if no result.
    *     - S_OK : if operation succeeded.
    */
    HRESULT KeepBest_N_Uplets ();

    /**
    *  Build Result.
    *     HRESULT
    *  Legal values : 
    *     - E_FAIL : if KO.
    *     - S_FALSE : if no result.
    *     - S_OK : if operation succeeded.
    */
    virtual HRESULT BuildResult () = 0;

    /**
    *  Get the result.
    *  @param oResult
    *     output CATTopEdgesConnectionResult.
    *  @return
    *     HRESULT
    *  Legal values : 
    *     - E_FAIL : if KO.
    *     - S_FALSE : if no result.
    *     - S_OK : if operation succeeded.
    */
    virtual HRESULT GetResult (CATTopEdgesConnectionResult *& oResult);

    /**
    Set the list of weight
    */
    virtual HRESULT SetWeights (CATListOfDouble &iListWeight);

    /**
    Get the list of weight
    */
    virtual HRESULT GetWeights (CATListOfDouble &oListWeight);

    //------------------//
    // Debug methods    //
    //------------------//
    
    /** 
    * @nodoc
    */

    HRESULT DebugBuildDefaultResult ();

protected:

    //-----------------------------------------------------------------
    // Data members
    //-----------------------------------------------------------------
    
    // in
    CATLISTP(CATTopEdgesNUplet) _ListOfNUplet;
    CATListOfDouble _ListWeight;

    CATSoftwareConfiguration  * _pConfig;
    CATGeoFactory             * _pFactory;

    // out
    CATTopEdgesConnectionResult * _pEdgesConnectionResult;

};


#endif // CATTopEdgesConnectionBuilder_H



