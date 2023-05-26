/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
// CATLocationVertexOnWire:
// Operator returns the location of a CATVertex on a CATWire. User can get the
// cell of the wire where the vertex is lying on.
//=============================================================================
//
//        ------------------------------------------
// ****** OUT OF ORDER. All code inactive since 2003. NLD121115 *****
//        ------------------------------------------
//
//=============================================================================
// WARNING: Operator was early designed to be used with CATVertex that were not
//          granted with IsLyingOn() capacity. Nevertheless, it supports both cases.
//=============================================================================
// Usage notes:
// ------------
//            CATLocationVertexOnWire MyService(factory, ...);
//            if ( MyService.Run() )
//            {
//              CATVertex *GivenVertex = MyService.Next(NULL);
//              CATVertex *VertexSupport=NULL:
//              MyService.GetResult(&VertexSupport);
//            }
//=============================================================================
// Dec.  98 LMH Creation                                                L. Mahe
// Jul.  99 LMH Modification : IsLyingOn integration
// 17/11/00 NLD Ajout constructeur avec iTopData
// 12/11/15 NLD Suppression du constructeur sans iTopData
//=============================================================================
#ifndef CATLocationVertexOnWire_h
#define CATLocationVertexOnWire_h

#include "AnalysisToolsLight.h"
#include "CATLocationTopology.h"
#include "CATCrvParam.h"

#define CATLocationVertexOnWire_GeneralShunt "NLD121115 pour faire proprement le shunt anciennement tout pourri"

//-----------------------------------------------------------------------------
class ExportedByAnalysisToolsLight CATLocationVertexOnWire : public CATLocationTopology
{
  public :
    //-------------------------------------------------------------------------
    // Constructor/Destructor
    //-------------------------------------------------------------------------
    CATLocationVertexOnWire(       CATGeoFactory      * Factory   ,
                                   CATTopData         * iTopData  ,
                             const CATBody            * BodyVertex,
                                   CATVertexInVolume  * VertexDom ,
                             const CATBody            * BodyWire  ,
                                   CATWire            * Wire      );

    ~CATLocationVertexOnWire();

    //-------------------------------------------------------------------------
    // Run and Result Access
    //-------------------------------------------------------------------------
    int  Run(); // Returns 1 if computation is successfull, 0 if not.

#ifndef CATLocationVertexOnWire_GeneralShunt

    private :
    CATTopData * _Data;

    // InternalMethods
    void FindEdgeInWire            ( CATVertex    *  iVertex     ,
                                     CATEdge      *& oEdgeSupport,
                                     CATCrvParam   & oPrmOnCurve );

    void IsEdgeCurveInWire         ( CATEdgeCurve *  iEdgeCurve  ,
                                     CATCrvParam     iPrmOnECrv  ,
                                     CATEdge      *& oEdgeSupport,
                                     CATCrvParam   & oPrmOnEdge  );

    void IsEdgeCurveContainedByWire( CATEdgeCurve *  iEdgeCurve  ,
                                     CATCrvParam     iPrmOnECrv  ,
                                     CATEdge      *& oEdgeSupport,
                                     CATCrvParam   & oPrmOnEdge  );

    void IsEdgeCurveLinkedToWire   ( CATEdgeCurve *  iEdgeCurve  ,
                                     CATCrvParam     iPrmOnECrv  ,
                                     CATEdge      *& oEdgeSupport,
                                     CATCrvParam   & oPrmOnEdge  );

    void IsCurveReferencedByWire   ( CATCurve     *  Curve       ,
                                     CATCrvParam     iPrmOnECrv  ,
                                     CATEdge      *& oEdgeSupport,
                                     CATCrvParam   & oPrmOnEdge  );

    CATLONG32 GetPosition          ( CATCrvParam     iPrm        ,
                                     CATCurve     *  iCurve      ,
                                     CATCrvParam     iStart      ,
                                     CATCrvParam     iEnd        );

#endif
};
#endif










