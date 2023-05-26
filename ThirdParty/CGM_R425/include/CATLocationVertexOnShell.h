/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
// CATLocationVertexOnShell:
// Operator returns the location of a CATVertex on a CATShell. User can get the
// cell of the shell where the vertex is lying on.
//=============================================================================
// WARNING: Operator was early designed to be used with CATVertex that were not
//          granted with IsLyingOn() capacity. Nevertheless, it supports both cases.
//=============================================================================
// Usage notes:
// ------------
//            CATLocationVertexOnShell MyService(factory, ...);
//            if ( MyService.Run() )
//            {
//              CATVertex *GivenVertex = MyService.Next(NULL);
//              CATVertex *VertexSupport=NULL:
//              MyService.GetResult(&VertexSupport);
//            }
//=============================================================================
// Nov. 98   Creation                                   L. Mahe
// Jul. 99   Modification : IsLyingOn integration       L. Mahe
// 171100 NLD Ajout constructeur avec iTopData
//=============================================================================
#ifndef CATLocationVertexOnShell_h
#define CATLocationVertexOnShell_h

#include "AnalysisToolsLight.h"
#include "CATLocationTopology.h"
#include "CATListOfCATPoints.h"

class CATCrvParam;

//-----------------------------------------------------------------------------
class ExportedByAnalysisToolsLight CATLocationVertexOnShell : public CATLocationTopology
{
  public :
    //-------------------------------------------------------------------------
    // Constructor/Destructor
    //-------------------------------------------------------------------------
    CATLocationVertexOnShell( CATGeoFactory      *Factory,
                              CATTopData         *iTopData,
                              const CATBody      *BodyVertex,
                              CATVertexInVolume  *VertexDom,
                              const CATBody      *BodyShell,
                              CATShell           *Shell );
    // DO NOT USE: WILL DISAPPEAR:
    CATLocationVertexOnShell( CATGeoFactory      *Factory,
                              const CATBody      *BodyVertex,
                              CATVertexInVolume  *VertexDom,
                              const CATBody      *BodyShell,
                              CATShell           *Shell );
    ~CATLocationVertexOnShell();     

    //-------------------------------------------------------------------------
    // Run and Result Access
    //-------------------------------------------------------------------------
    int  Run(); // Returns 1 if computation is successfull, 0 if not.


  private :

    // Internal Methods
    //int  IsInFace(CATPointOnSurface *iPtOnSurf, CATFace *iFace);
    int  IsInFace(CATPointOnSurface *iPtOnSurf, CATFace *iFace,
                  CATEdge *&oEdgeSupport, CATCrvParam &oPrmOnEdge);
    
    void FindFaceInShell(CATPointOnSurface *iPtOnSurf,
                         CATFace * & oFaceSupport, CATEdge *&oEdgeSupport,
                         CATCrvParam &oPrmOnEdge);
    //void FindFaceInShell(CATPointOnSurface *iPtOnSurf,
    //                     CATFace * & oFaceSupport, int & oOnBoundary);
    
    //int  IsInEdge(CATPointOnSurface *iPtOnSurf,CATEdge *iEdge);
    //void FindEdgeInFace(CATPointOnSurface *iPtOnSurf, CATFace *iFaceSupport,
    //                    CATEdge * & oEdgeSupport, int & oOnBoundary);
    void FindVertexInEdge(CATEdge *iEdgeSupport,const CATCrvParam &iPrmOnEdge,
                          CATVertex * & oVertexSupport);
    //void FindVertexInEdge(CATEdge *iEdgeSupport, int iOnBoundary,
    //                      CATVertex * & oVertexSupport);
    
    void GetPointsOnSurface(CATVertex *iVertex, const CATLISTP(CATSurface) &iSurfaces,
                            CATLISTP(CATPoint) *oList);
    void GetPointsOnPCurve(CATVertex *iVertex, const CATLISTP(CATSurface) &iSurfaces,
                           CATLISTP(CATPoint) *oList);
    void FindSupportViaPointsOnSurface(const CATLISTP(CATPoint) &iList, CATCell *&oSupport);
    void FindSupportViaPointsOnPCurve(const CATLISTP(CATPoint) &iList, CATCell *&oSupport);
};
#endif










