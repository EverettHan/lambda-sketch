//===================================================================
 // COPYRIGHT Microsoft 2014
//===================================================================
// CATTopEvalEquation.h
// Header definition of class CATTopEvalEquation
//===================================================================
//
// Usage notes:
//
//===================================================================
// 2014/02/05 Creation: DBS
//===================================================================

#ifndef CATTopEvalEquation_H
#define CATTopEvalEquation_H

#include "MultiWireCoupling.h"

#include "CATBoolean.h"
#include "CATErrorDef.h" 
#include "CATListOfDouble.h" 

#include "CATMathPoint.h"
#include "CATTopEdgesNUplet.h"

class CATSoftwareConfiguration;
class CATGeoFactory;


class ExportedByMultiWireCoupling CATTopEvalEquation
{

public:

    
    // enum CATTopEvalEquationType
    //--------------------------------------
    // NOTE : add here new type to add new equation and add new inherited class 

    enum CATTopEvalEquationType
    {
      TopEvalEquationBarycentric     = 0,  // see CATTopEvalEquationBarycentric class
      TopEvalEquationBitangent       = 1,  // see CATTopEvalEquationBitangent class
      TopEvalEquationQuasiParallel   = 2   // see CATTopEvalEquationParallel class
    };



    // Constructor / destructor
    //-------------------------
    CATTopEvalEquation(CATSoftwareConfiguration * ipConfig,
                       CATGeoFactory            * ipFactory);

    virtual ~CATTopEvalEquation();
        
    /**
    *  Set the N-Uplets to eval the equation.
    *  @param ipNUplet
    *     input N-uplets.
    *  @return
    *     HRESULT
    *  Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT Set_N_Uplets (CATTopEdgesNUplet * ipNUplet);

    /**
    *  Get the N-Uplets.
    *  @param opNUplet
    *     output N-uplets.
    *  @return
    *     HRESULT
    *  Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT Get_N_Uplets (CATTopEdgesNUplet *& opNUplet);

    /**
    Get the list of weight
    */
    HRESULT Get_Weights (CATListOfDouble &oListWeight);

    /**
    Set the list of weight
    */
    HRESULT Set_Weights (CATListOfDouble &iListWeight);

    /**
    *  RunEquation.
    * @return
    *     HRESULT
    * Legal values : 
    *     - E_FAIL : if KO.
    *     - S_FALSE : if operation failed.
    *     - S_OK : if operation succeeded.
    */
    virtual HRESULT RunEquation () = 0;



protected:

    //-----------------------------------------------------------------
    // Data members
    //-----------------------------------------------------------------
    
    // in
    CATSoftwareConfiguration  * _pConfig;
    CATGeoFactory             * _pFactory;

    CATTopEdgesNUplet * _pNUplet;
    CATListOfDouble     _ListWeights;

};


#endif // CATTopEvalEquation_H



