//===================================================================
 // COPYRIGHT Microsoft 2014
//===================================================================
// CATTopEvalQuality.h
// Header definition of class CATTopEvalQuality
//===================================================================
//
// Usage notes:
//
//===================================================================
// 2014/02/05 Creation: DBS
//===================================================================

#ifndef CATTopEvalQuality_H
#define CATTopEvalQuality_H

#include "MultiWireCoupling.h"

#include "CATBoolean.h"
#include "CATErrorDef.h" 


class CATTopEvalEquation;
class CATSoftwareConfiguration;
class CATGeoFactory;


class ExportedByMultiWireCoupling CATTopEvalQuality
{

public:

    
    // enum CATTopEvalQualityType
    //--------------------------------------
    // NOTE : add here new type to add new quality and add new inherited class 

    enum CATTopEvalQualityType
    {
      TopEvalQualityBarycentric     = 0,  // // see CATTopEvalQualityBarycentric class
      TopEvalQualityBitangent       = 1,  // // see CATTopEvalQualityBitangent class
      TopEvalQualityQuasiParallel   = 2   // // see CATTopEvalQualityQuasiParallel class
    };


    // Constructor / destructor
    //-------------------------
    CATTopEvalQuality(CATSoftwareConfiguration * ipConfig,
                      CATGeoFactory            * ipFactory);

    virtual ~CATTopEvalQuality();
        

    /**
    *  Set the EvalEquation.
    *  @param ipEvalEquation
    *     input eval equation.
    * @return
    *     HRESULT
    * Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT SetEvalEquation (CATTopEvalEquation * ipEvalEquation);

    /**
    *  RunQuality.
    * @return
    *     HRESULT
    * Legal values : 
    *     - E_FAIL : if KO.
    *     - S_FALSE : if operation failed.
    *     - S_OK : if operation succeeded.
    */
    virtual HRESULT RunQuality () = 0;

    /**
    *  SetQuality.
    *  @param iQuality
    *     input quality.
    * @return
    *     HRESULT
    * Legal values : 
    *     - E_FAIL : if KO.
    *     - S_FALSE : if operation failed.
    *     - S_OK : if operation succeeded.
    */
    virtual HRESULT SetQuality (double iQuality);

    /**
    *  GetQuality.
    *  @param oQuality
    *     output quality.
    * @return
    *     HRESULT
    * Legal values : 
    *     - E_FAIL : if KO.
    *     - S_FALSE : if operation failed.
    *     - S_OK : if operation succeeded.
    */
    virtual HRESULT GetQuality (double & oQuality);

    /**
    *  Set Quality distance to eval the quality.
    *  @param iQuality
    *     input quality.
    * @return
    *     HRESULT
    * Legal values : 
    *     - E_FAIL : if KO.
    *     - S_FALSE : if operation failed.
    *     - S_OK : if operation succeeded.
    */
    virtual HRESULT SetQualityDistance (double iQualityDistance);

    /**
    *  Get Quality distance.
    *  @param oQuality
    *     output quality.
    * @return
    *     HRESULT
    * Legal values : 
    *     - E_FAIL : if KO.
    *     - S_FALSE : if operation failed.
    *     - S_OK : if operation succeeded.
    */
    virtual HRESULT GetQualityDistance (double & oQualityDistance);

protected:

    //-----------------------------------------------------------------
    // Data members
    //-----------------------------------------------------------------
    

    // in
    CATSoftwareConfiguration  * _pConfig;
    CATGeoFactory             * _pFactory;

    CATTopEvalEquation * _pEvalEquation;

    // out
    double               _Quality;
    double               _QualityDistance;

};

#endif // CATTopEvalQuality_H



