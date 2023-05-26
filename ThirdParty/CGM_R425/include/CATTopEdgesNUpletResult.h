//===================================================================
 // COPYRIGHT Microsoft 2014
//===================================================================
// CATTopEdgesNUpletResult.h
// Header definition of class CATTopEdgesNUpletResult
//===================================================================
//
// Usage notes:
//
//===================================================================
// 2014/02/05 Creation: DBS
//===================================================================

#ifndef CATTopEdgesNUpletResult_H
#define CATTopEdgesNUpletResult_H

#include "MultiWireCoupling.h"

#include "CATBoolean.h"
#include "CATErrorDef.h" 


#include "CATListOfCATCurves.h"
#include "CATListOfCATCrvParams.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "CATListOfInt.h"


class CATCurve;
class CATCrvParam;
class CATFace;
class CATEdge;
class CATGeoFactory;
class CATCGMStream;
class CATCGMOutput;


class ExportedByMultiWireCoupling CATTopEdgesNUpletResult
{

public:

    

    // Constructor / destructor
    //-------------------------
    CATTopEdgesNUpletResult();

    CATTopEdgesNUpletResult(CATLISTP(CATCurve)    & iListCurve, 
                            CATLISTP(CATCrvParam) & iListCrvParam,
                            CATLISTP(CATEdge)     & iListEdge,
                            CATLISTP(CATFace)     & iListFace,
                            CATListOfInt          & iListOrientationFace);

    virtual ~CATTopEdgesNUpletResult();
        

    /**
    *  Get the Input N-uplet.
    *  @param oListCurve
    *     output list of CATCurve
    *  @param oListCrvParam
    *     output list of CATCrvParam
    * @return
    *     HRESULT
    * Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT GetNUplet (CATLISTP(CATCurve)    & oListCurve, 
                       CATLISTP(CATCrvParam) & oListCrvParam);

    /**
    *  Get the Input N-uplet Edge.
    *  @param oListEdge
    *     output list of CATEdge
    * @return
    *     HRESULT
    * Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT GetNUpletEdges (CATLISTP(CATEdge) & oListEdge);

    /**
    *  Get the Input N-uplet Face and Orientation.
    *  @param oListFace
    *     output list of CATFace
    *  @param oListOrientationFace
    *     output list of CATOrientation
    * @return
    *     HRESULT
    * Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT GetNUpletFaces (CATLISTP(CATFace) & oListFace, 
                            CATListOfInt      & oListOrientationFace);

    // For CGMReplay
    void Stream( CATCGMStream  & oStr, int iVersion );
    void UnStream( CATCGMStream  & iStr, int iVersion, CATGeoFactory * iFactory, double iScaleFactor = 1. );
    void Dump( CATCGMOutput & oStr );
    CATBoolean IsEquivalentTo( CATTopEdgesNUpletResult & iOtherNUplet, CATGeoFactory * iFactory ) const;

private:
    
    
    //-----------------------------------------------------------------
    // Data members
    //-----------------------------------------------------------------
    
    // out
    CATLISTP(CATCurve)      _ListCurve;
    CATLISTP(CATCrvParam)   _ListCrvParam;
    CATLISTP(CATEdge)       _ListEdge;     // linked edge
    CATLISTP(CATFace)       _ListFace;     // linked face
    CATListOfInt            _ListOrientationFace;
    
};

#endif // CATTopEdgesNUpletResult_H



