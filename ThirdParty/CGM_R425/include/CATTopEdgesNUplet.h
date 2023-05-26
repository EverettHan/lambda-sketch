//===================================================================
 // COPYRIGHT Microsoft 2014
//===================================================================
// CATTopEdgesNUplet.h
// Header definition of class CATTopEdgesNUplet
//===================================================================
//
// Usage notes:
//
//===================================================================
// 2014/02/05 Creation: DBS
//===================================================================

#ifndef CATTopEdgesNUplet_H
#define CATTopEdgesNUplet_H

#include "MultiWireCoupling.h"

#include "CATBoolean.h"
#include "CATErrorDef.h" 

#include "CATListOfInt.h"
#include "CATListOfCATPointOnEdgeCurves.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"


class CATPointOnEdgeCurve;
class CATFace;
class CATEdge;
class CATGeoFactory;


class ExportedByMultiWireCoupling CATTopEdgesNUplet
{

public:

    

    // Constructor / destructor
    //-------------------------
    CATTopEdgesNUplet();
    virtual ~CATTopEdgesNUplet();
        
    /**
    * Copy constructor.
    */
    CATTopEdgesNUplet (const CATTopEdgesNUplet & iNUpletToCopy);

    /**
    *  Set the Input N-uplet.
    *  @param iListPointOnEdgeCurve
    *     input list of CATPointOnEdgeCurves
    *  @param iListIndexEdges
    *     input list of index of edges
    *  @param iListIndex
    *     input list of index of CATPointOnEdgeCurve of sample edge
    * @return
    *     HRESULT
    * Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT SetNUplet (CATLISTP(CATPointOnEdgeCurve) & iListPointOnEdgeCurve, 
                       CATListOfInt                  & iListIndexEdges, 
                       CATListOfInt                  & iListIndex, 
                       CATListOfInt                  & iListOrientation,
                       CATLISTP(CATEdge)             & iListEdges,
                       CATLISTP(CATFace)             & iListFaces,
                       CATListOfInt                  & iListOrientationFaces);

    /**
    *  Get the Input N-uplet.
    *  @param oListPointOnEdgeCurve
    *     output list of CATPointOnEdgeCurves
    * @return
    *     HRESULT
    * Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT GetNUplet (CATLISTP(CATPointOnEdgeCurve) & oListPointOnEdgeCurve);

    /**
    *  Get the Input N-uplet index.
    *  @param oListIndexEdges
    *     output list of index of edges
    * @return
    *     HRESULT
    * Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT GetNUpletIndexEdges (CATListOfInt & oListIndexEdges);

    /**
    *  Get the Input N-uplet index.
    *  @param oListIndex
    *     output list of index
    *  @return
    *     HRESULT
    *  Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT GetNUpletIndex (CATListOfInt & oListIndex);

    /**
    *  Get the Input N-uplet edges (corresponding POEC borders of this).
    *  @param oListEdges
    *     output list of edges
    *  @return
    *     HRESULT
    *  Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT GetNUpletEdges (CATLISTP(CATEdge) & oListEdges);


    /**
    *  Get the Input N-uplet faces (corresponding POEC borders of this).
    *  @param oListFaces
    *     output list of faces
    *  @param oListOrientationFaces
    *     output list of CATOrientation of CATFace vs Shell
    *  @return
    *     HRESULT
    *  Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT GetNUpletFaces (CATLISTP(CATFace) & oListFaces, 
                            CATListOfInt      & oListOrientationFaces);
    /**
    *  Get the Input N-uplet orientation.
    *  @param oListOrientation
    *     output list of orientation
    *  @return
    *     HRESULT
    *  Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT GetNUpletOrientation (CATListOfInt & oListOrientation);


    /**
    *  Get the uplet [iNUplet].
    *  @param iNUplet
    *     input index of NUplet
    *  @param oPointOnEdgeCurve
    *     output of CATPointOnEdgeCurves
    *  @param oIndexEdges
    *     output index of edge
    *  @param oIndex
    *     output index
    *  @param opEdge
    *     output of CATEdge
    *  @param opFace
    *     output of CATFace
    *  @param oOrientation
    *     output of CATOrientation
    * @return
    *     HRESULT
    * Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT GetUplet (int                    iNUplet, 
                      CATPointOnEdgeCurve *& opPointOnEdgeCurve, 
                      int                  & oIndexEdges, 
                      int                  & oIndex, 
                      CATEdge             *& opEdge, 
                      CATFace             *& opFace, 
                      int                  & oOrientation );


    /**
    *  Get the size of the NUplet.
    * @return
    *     int
    * Legal values : 
    *     - size > 0 : if OK.
    */
    int GetSize ();

    /**
    *  Sort NUplet with index of edges [1,2,...,N].
    *  @return
    *     HRESULT
    *  Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT Sort ();


    /**
    *  Is common uplet.
    *  @param iIndexUplet
    *     input index to see if the uplet at this index is same as this
    *  @param ipNUplet
    *     input NUplet
    * @return
    *     HRESULT
    * Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT IsCommonUplet(int iIndexUplet, CATTopEdgesNUplet * ipNUplet); 

    /**
    *  Is common uplet.
    *  @param ipNUplet
    *     input NUplet
    * @return
    *     HRESULT
    * Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT IsCommonUplet(CATTopEdgesNUplet * ipNUplet); 

    /**
    *  Set the Input quality.
    *  @param iQuality
    *     input quality
    * @return
    *     HRESULT
    * Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT SetQuality (double iQuality);

    /**
    *  Get the quality.
    *  @param oQuality
    *     output quality
    * @return
    *     HRESULT
    * Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT GetQuality (double & oQuality);

    /**
    *  Set Best Common.
    *  @param iIsBestCommon
    *     input boolean
    * @return
    *     HRESULT
    * Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT SetBestCommon (CATBoolean iIsBestCommon);

    /**
    *  Is Best Common.
    * @return
    *     CATBoolean
    * Legal values : 
    *     - TRUE : if best common.
    *     - FALSE : if no best common.
    */
    CATBoolean IsBestCommon ();

    /**
    *  Set visit info.
    *  @param iIsVisited
    *     input boolean
    * @return
    *     HRESULT
    * Legal values : 
    *     - E_FAIL : if KO.
    *     - S_OK : if operation succeeded.
    */
    HRESULT SetVisited (CATBoolean iIsVisited);

    /**
    *  Is Best Common.
    * @return
    *     CATBoolean
    * Legal values : 
    *     - TRUE : if best common.
    *     - FALSE : if no best common.
    */
    CATBoolean IsVisited ();

    /**
    *  Show this into iFactory for debug purpose.
    */
    void Show(CATGeoFactory* iFactory, const int iRed, const int iGreen, const int iBlue);

private:
    
    
    //-----------------------------------------------------------------
    // Data members
    //-----------------------------------------------------------------
    
    // in
    CATLISTP(CATPointOnEdgeCurve) _NUpletPointOnEdgeCurve;
    CATListOfInt                  _ListIndexEdges;
    CATListOfInt                  _ListIndex;
    CATListOfInt                  _ListOrientation;
    CATLISTP(CATEdge)             _NUpletEdgeLinkedPOEC;
    CATLISTP(CATFace)             _NUpletFaceLinkedPOEC;
    CATListOfInt                  _NUpletOrientationLinkedToPOEC;

    // out
    double                        _Quality;
    // data
    CATBoolean                    _IsBestCommon;
    CATBoolean                    _IsVisited;
};

#endif // CATTopEdgesNUplet_H



