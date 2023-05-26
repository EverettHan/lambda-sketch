#ifndef ParallelUtilities_H
#define ParallelUtilities_H


// COPYRIGHT DASSAULT SYSTEMES 2002
#include "RibbonLight.h"
#include "CATBoolean.h"
#include "ListPOfCATFace.h"
#include "CATCell.h"
#include "CATListOfCATSurParams.h"
#include "CATTopDefine.h"

// Modified By : SUH : 2004:7:8
#include "CATCGMJournalList.h"
#include "ListPOfCATCell.h"
#include "CATListOfCATPointOnEdgeCurves.h"

class CATBody;
class CATCell;
class CATVertex;
class CATEdge;
class CATFace;
class CATShell;

class CATGeoFactory;
class CATPCurve;
class CATEdgeCurve;
class CATSurParam;
class CATCrvParam;
class CATPointOnEdgeCurve;

class CATMathVector;

class CATSoftwareConfiguration;
class CATCouplingParallel;


//---------------------------------------------------------------------------
// ST5 Wk39-2013: Here GetLyingOn method is used for decision
//---------------------------------------------------------------------------
ExportedByRibbonLight void FindFacesSupport(CATCell *iCell, 
                                            CATBody *iBodyShell, 
                                            CATShell *iShell, 
                                            CATLISTP(CATCell) & oBoundingFaces,
                                            CATGeometry ** &oPCurve, 
                                            CATOrientation * &oGeomVsCell,
                                            CATOrientation * & oSurfaceVsShell);

//---------------------------------------------------------------------------
// Finds a Face in a shell where a cell is lied on, respective orientations 
// can be returned. The face found can be the following Cell of iPreviousFace 
// in the shell if the cell is lied on several faces ( ie border edge )
//
// ST5 Wk39-2013: Beware that GetLyingOn method is not called there; 
// Geometries (PCrv & Surface) bounding boxes are used for decision
//---------------------------------------------------------------------------
ExportedByRibbonLight CATFace * FindFaceSupportInShell(CATCell *iCell,
                                                       CATShell *iShell,
                                                       CATPCurve *&oPCurve,
                                                       CATOrientation *oGeomVsCell = 0,
                                                       CATOrientation *oSurfaceVsShell = 0,
                                                       CATFace *iPreviousFace = NULL);


//---------------------------------------------------------------------------
// ST5 Wk39-2013: Extension of above method to whole list of Face supports
// Geometries (PCrv & Surface) bounding boxes are used for decision
// Not implemented on CATVertexType cells
//---------------------------------------------------------------------------
ExportedByRibbonLight void FindAllFacesSupportInShell(CATCell *iCell, CATShell * iShell, 
                                                      CATLISTP(CATFace) & oSupportFaces,
                                                      CATLISTP(CATGeometry) & oPCurves, 
                                                      CATOrientation * & oGeomVsCell, 
                                                      CATOrientation * & oSurfaceVsShell);


//---------------------------------------------------------------------------
// Check if two vertices bounding two edges represent the same space geometry
// The two edges can be the same
//---------------------------------------------------------------------------
ExportedByRibbonLight CATBoolean AreSameVerticesOnEdge( CATGeoFactory *iFactory,
                                    CATVertex *iFirst, CATEdge *iFirstEdge,
                                   CATVertex *iSecond, CATEdge *iSecondEdge,
                                   CATSoftwareConfiguration *iConfig);

//------------------------------------------------------------------------------
// Search from a CATSurParam and a CATFace adjacents faces and corresponding 
// SurParam on them when the SurParam is on the boundary of the face.
// Empty lists are returned if not any. 
// WARNING : the calling function or method should delete each CATSurParam of the list
//------------------------------------------------------------------------------
ExportedByRibbonLight int FindAdjacentFaceFromParam ( CATGeoFactory *iFactory,
                                                 CATSoftwareConfiguration *iConfig,
                                                 CATBody * iBody,
                                                 CATFace *iFace, CATSurParam *iParam,
                                                 ListPOfCATFace &oNewFaces, CATLISTP(CATSurParam) &oNewParams,
                                                 double iTolerance,
                                                 CATMathVector * iDirection=NULL,
                                                 CATShell * iShell = 0, 
                                                 CATMathVector * iTangent = 0,
                                                 CATListOfDouble * oGapList = 0); // Modified By : SUH : 2003:6:7


// Start : SUH : 2003:6:7
//---------------------------------------------------------------------------
// Evaluates, on next face, a param in the direction iTangent and tangent at...
// this param, given a face and a point (iVertex) on the common edge of the...
// faces.
//---------------------------------------------------------------------------
ExportedByRibbonLight CATBoolean TopoGeodesicEvalTangent(CATGeoFactory * iFactory,
                                                    CATSoftwareConfiguration * iConfig,
                                                    CATShell      * iShell,
                                                    CATFace       * iFace_ref,
                                                    CATFace       * iFace_next,
                                                    CATEdge       * iEdge_int,
                                                    CATVertex     * iVertex,
                                                    CATMathVector & iTangent,
                                                    CATSurParam   & oParam,
                                                    CATMathVector & oTangent,
                                                    double        & oDistance,
                                                    CATBody       * iBody = NULL,
                                                    CATFace       ** oNextFace = NULL);

//---------------------------------------------------------------------------
// Evaluates, on next face, a param in the direction iTangent and tangent at...
// this param, given a face and a point (iPOEC) on the common edge of the...
// faces.
//---------------------------------------------------------------------------
ExportedByRibbonLight CATBoolean TopoGeodesicEvalTangent(CATGeoFactory * iFactory,
                                                    CATSoftwareConfiguration * iConfig,
                                                    CATShell      * iShell,
                                                    CATFace       * iFace_ref,
                                                    CATFace       * iFace_next,
                                                    CATEdge       * iEdge_int,
                                                    CATPointOnEdgeCurve * iPOEC,
                                                    CATMathVector & iTangent,
                                                    CATSurParam   & oParam,
                                                    CATMathVector & oTangent,
                                                    double        & oDistance,
                                                    CATBody       * iBody = NULL,
                                                    CATFace       ** oNextFace = NULL);
// End : SUH : 2003:6:7


ExportedByRibbonLight CATBoolean NewTopoGeodesicEvalTangent(CATGeoFactory * iFactory,
                                                    CATSoftwareConfiguration * iConfig,
                                                    CATShell      * iShell,
                                                    CATFace       * iFace_ref,
                                                    CATFace       * iFace_next,
                                                    CATEdge       * iEdge_int,
                                                    CATPointOnEdgeCurve * iPOEC,
                                                    CATMathVector & iTangent,
                                                    CATSurParam   & oParam,
                                                    CATMathVector & oTangent,
                                                    double        & oDistance,
                                                    CATEdge       * iOldEdge,
                                                    CATPCurve     ** oNewPCurve = NULL,
                                                    CATCrvParam   * oNewCrvParam = NULL,
                                                    CATFace       ** iInBetweenFace = NULL);

// REN wk20 2007
// Used when CATReportECrvSur fails to report pt
// Used specially when the pts to be reported are from two different edgecurves
ExportedByRibbonLight CATBoolean TopoGeodesicChangeFaceFromEdge(CATGeoFactory            * iFactory, 
                                                           CATSoftwareConfiguration * iConfig, 
                                                           CATBody                  * iBody, 
                                                           CATShell                 * iShell,
                                                           CATFace                  * ifirstFace,
                                                           CATFace                  * isecondFace,
                                                           CATMathVector            & iTangent,
                                                           CATEdge                  * iedge,
                                                           CATCrvParam              & iParam,
                                                           CATFace                  *& oFace,
                                                           CATCrvParam              & oNewResultParam, 
                                                           CATPCurve                *& oNewPCurve,
                                                           CATMathVector            & oTangent); 

ExportedByRibbonLight CATBoolean GetAdjFace(CATBody * iBody,CATFace *iFace, CATEdge *iEdge, CATFace *& oFace);


// Start : SUH : 2004:7:8
//---------------------------------------------------------------------------
// Finds the intersection vertices (between extrapolated G1 results) found...
// after relimitation. Using iJourn, it searches for the vertices created...
// in WireBody, from two edges. Returns TRUE if search successful
//---------------------------------------------------------------------------
ExportedByRibbonLight CATBoolean FindIntersectionVertices(CATBody * iWireBody, CATCGMJournalList * iJourn, CATLISTP(CATCell) &ioIntersVertices);
// End : SUH : 2004:7:8

// REN 2006 wk24
ExportedByRibbonLight void SetLimitsInCouplingParallel(CATGeoFactory *iFactory, CATEdgeCurve *iECrvFirst,
                                                                  CATEdgeCurve *iECrvSecond, CATEdgeCurve *ECrv,
                                                                  CATCouplingParallel *ioCouplingParOpe,
                                                                  CATLISTP(CATPointOnEdgeCurve) *ioPtOnECrv);
#endif
