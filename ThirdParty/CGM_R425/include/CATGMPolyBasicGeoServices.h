/* -*-C++-*-*/
#ifndef CATGMPolyBasicGeoServices_H
#define CATGMPolyBasicGeoServices_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2017
//
// CATGMPolyBasicGeoServices 
//
// DESCRIPTION :
// 
//   Services to retrieve :
//     the relative location of a point on a GeoPolyCurve
//     the relative location of a Vertex on Edges and Faces
//     the minimized dimension of the oriented bounding box : Point, Line, Plane, Volume
// 
//
// History
//
// January. 2017 DPS Creation
//
//=============================================================================

#include "GMPolyBodyServices.h" // ExportedBy

#include "ListPOfCATCell.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "CATListOfInt.h"
#include "CATListValCATCrvParam.h"
#include "CATListValCATPolySurfParam.h"

#include "CATGMPolyParamTools.h"

#include "CATTopDefine.h"
#include "CATBoolean.h"
#include "CATSysBoolean.h"


class CATSoftwareConfiguration;
class CATGeoPolyCurve;

class CATTopology;
class CATBody;
class CATFace;
class CATEdge;
class CATVertex;

class CATCrvParam;
class CATSurParam;
class CATPolySurfParam;

class CATMathPoint;
class CATMathLine;
class CATMathPlane;
class CATMathOBB;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBodyServices CATGMPolyBasicGeoServices
{

public:

  // ==========================================================================================================================================================================================================================
  //   Relative location of a point on a GeoPolyCurve
  // ==========================================================================================================================================================================================================================

  // Service to locate a MathPoint on a PolyCurve, returns TRUE if point could be located, FALSE otherwise (no location or multiple locations)
  // optional argument oLogicalPosition : -1 means that the Point starts the Curve, +1 : the Point ends the Curve, else 0 for inside
  static CATBoolean LocatePointOnPolyCurve(CATSoftwareConfiguration * iConfig, const CATMathPoint & iPoint, CATGeoPolyCurve & iPolyCurve, double iTol, CATCrvParam & oCrvParam, int * oLogicalPosition=NULL);

  // Service to locate a MathPoint on a PolyCurve, returns TRUE if point could be located (even with multiple locations), FALSE otherwise (no location)
  // optional argument oLogicalPositions : -1 means that the Point starts the Curve, +1 : the Point ends the Curve, else 0 for inside
  static CATBoolean LocatePointOnPolyCurve(CATSoftwareConfiguration * iConfig, const CATMathPoint & iPoint, CATGeoPolyCurve & iPolyCurve, double iTol, CATLISTV(CATCrvParam) & oCrvParams, CATListOfInt * oLogicalPositions=NULL);

  // Service to project a MathPoint on a PolyCurve, returns TRUE if point could be projected, FALSE otherwise (no projections or multiple results)
  // optional argument oLogicalPosition : -1 means that the Point starts the Curve, +1 : the Point ends the Curve, else 0 for inside
  static CATBoolean ProjectPointOnPolyCurve(CATSoftwareConfiguration * iConfig, const CATMathPoint & iPoint, CATGeoPolyCurve & iPolyCurve, double &oDistMin, CATCrvParam & oCrvParam, int * oLogicalPosition=NULL);

  // Service to project a MathPoint on a PolyCurve, returns TRUE if point could be projected (even with multiple results), FALSE otherwise (no projection)
  // optional argument oLogicalPositions : -1 means that the Point starts the Curve, +1 : the Point ends the Curve, else 0 for inside
  static CATBoolean ProjectPointOnPolyCurve(CATSoftwareConfiguration * iConfig, const CATMathPoint & iPoint, CATGeoPolyCurve & iPolyCurve, double &oDistMin, CATLISTV(CATCrvParam) & oCrvParams, CATListOfInt * oLogicalPositions=NULL);

  // Service to retrieve points on a PolyCurve from a Point2D which is the result of their projection on a planar screen.
  // optional argument oZValues : associate the Z height to each CrvParam solution, according to the planar axis
  // returns TRUE if at leat one point could be retrieved (even with multiple solutions), FALSE otherwise (no solution)
  static CATBoolean RetrievePolyCrvPtsFromProjectedPt(CATSoftwareConfiguration * iConfig, CATMathPlane & iPlanarScreen, CATMathPoint2D & iPt2D, CATGeoPolyCurve & iPolyCurve, double iTol, 
    CATLISTV(CATCrvParam) & oCrvParams, CATListOfDouble * oZValues=NULL);


public:

  // ==========================================================================================================================================================================================================================
  //   Relative location of a Vertex on Edges and Faces
  // ==========================================================================================================================================================================================================================


  // Retrieve the full parametric description of a vertex belonging a body
  static HRESULT RetrieveParamsOnCellsBoundedByVertex(CATVertex &iVtx, CATBody & iShellBodyOwner, CATSoftwareConfiguration * iConfig,
                                                      CATLISTP(CATEdge) &oIncidentEdges, CATLISTV(CATCrvParam) &oCrvParams, 
                                                      CATLISTP(CATFace) &oIncidentFaces, CATLISTV(CATPolySurfParam) &oSurfParams);

  // Not avalaible on V5 Releases, only V6 from R2017x
  // Locate a given vertex onto a body and retrieve its equivalent parametric description on this body
  static HRESULT RetrieveParamsOnCellsAtVertexlyingOn(CATVertex &iVtxLyingOn, CATBody & iShellBodySupport, CATSoftwareConfiguration * iConfig,
                                                      CATVertex       * &oShellBodyVertex,
                                                      CATLISTP(CATEdge) &oShellBodyEdges, CATLISTV(CATCrvParam) &oCrvParams, 
                                                      CATLISTP(CATFace) &oShellBodyFaces, CATLISTV(CATPolySurfParam) &oSurfParams);


  // Not avalaible on V5 Releases, only V6 from R2017x
  // Locate a given vertex onto a set of faces
  // returns the cell with the smallest dimension, and its incident cells with equivalent parameters
  // if the given vertex is located on a face, oFaceVtx will be null and oFaceEdges empty, oFaceEdges will contain the face
  // if the given vertex is located on an edge, oFaceVtx will be null and oFaceEdges will contain the edge and oFaces its incident faces
  // if the given vertex is located on a vertex, oFaceEdges will contain its incident edges and oFaces its incident faces
  static CATBoolean LocateVertexOnSetOfPolyFaces(CATSoftwareConfiguration * iConfig, CATVertex * iVertexToLocate, const CATLISTP(CATFace) &iListOfFaces, double iTol,
                                                 CATVertex       * &oFaceVtx, 
                                                 CATLISTP(CATEdge) &oFaceEdges, CATLISTV(CATCrvParam) &oEdgeCrvParams, 
                                                 CATLISTP(CATFace) &oFaces, CATLISTV(CATPolySurfParam) &oFaceSurfParams);

  
  // Not avalaible on V5 Releases, only V6 from R2017x
  // Service to locate a point on a set of faces
  // (candidate to be the polyhedral delegation of CATSearchPointOnFaces API)
  static CATBoolean LocateVertexOnPolyFaces(CATSoftwareConfiguration * iConfig, CATVertex * iVertex, const CATLISTP(CATFace) &iListOfFaces, double iTol,
                                            CATSurParam & oOnFaceParam, int & oNumFace, CATCrvParam & oOnEdge, CATEdge *& oEdge);

    
public:

  // ==========================================================================================================================================================================================================================
  //   Minimized dimension of the oriented bounding box : Point, Line, Plane, Volume ?
  // ==========================================================================================================================================================================================================================

  // Service to retrieve the minimal mathematical definition of an input OBB (Oriented Bounding Box)
  // returns -1 if the box is empty, 0 if the box is a point, 1 if the box is linear, 2 if the box is planar, 3 if the box is a volume
  // oPt, oLine, oPlane have no sense if their dimension doesn't match with the returned value
  static int ComputeMinimalBoxDimension(CATSoftwareConfiguration * iConfig, CATMathOBB & iOBB, double iTol, CATMathPoint * oPt=0, CATMathLine * oLine=0, CATMathPlane * oPlane=0);

  static CATBoolean ComputeMedianPlane(CATSoftwareConfiguration * iConfig, CATMathOBB & iOBB, double iTol, CATMathPlane & oPlane);
  static CATBoolean ComputeMedialAxis(CATSoftwareConfiguration * iConfig, CATMathOBB & iOBB, double iTol, CATMathLine & oLine);

  // Service to retrieve the minimal mathematical definition of the OBB (Oriented Bounding Box) of a topological object
  // returns -1 if the box is empty, 0 if the box is a point, 1 if the box is linear, 2 if the box is planar, 3 if the box is a volume
  // oPt, oLine, oPlane have no sense if their dimension doesn't match with the returned value
  static int ComputeMinimalTopoBoxDimension(CATSoftwareConfiguration * iConfig, CATTopology & iPolyTopObject, double iTol, CATMathPoint * oPt=0, CATMathLine * oLine=0, CATMathPlane * oPlane=0, CATMathOBB * oOBB=0);

  // Service to retrieve the minimal mathematical definition of the OBB (Oriented Bounding Box) of a topological object
  // returns -1 if the box is empty, 0 if the box is a point, 1 if the box is linear, 2 if the box is planar, 3 if the box is a volume
  // oPt, oLine, oPlane have no sense if their dimension doesn't match with the returned value
  static int ComputeMinimalTopoBoxDimension(CATSoftwareConfiguration * iConfig, ListPOfCATCell &iCells, CATListOfInt &iSides, double iTol, CATMathPoint * oPt=0, CATMathLine * oLine=0, CATMathPlane * oPlane=0, CATMathOBB * oOBB=0);

  // Service to retrieve the equivalent point definition of the OBB (Oriented Bounding Box) of a topological object
  static CATBoolean RetrieveEquivalentPoint(CATSoftwareConfiguration * iConfig, CATTopology & iPolyTopObject, double iTol, CATMathPoint &oPt3D);
  
  // Service to retrieve the linear definition of the OBB (Oriented Bounding Box) of a topological object
  static CATBoolean RetrieveEquivalentLine(CATSoftwareConfiguration * iConfig, CATTopology & iPolyTopObject, double iTol, CATMathLine &oLine3D);

  // Service to retrieve the planar definition of the OBB (Oriented Bounding Box) of a topological object
  static CATBoolean RetrieveEquivalentPlane(CATSoftwareConfiguration * iConfig, CATTopology & iPolyTopObject, double iTol, CATMathPlane &oPlane);

  // Service to know if a topology is on the input plane iPlane
  static CATBoolean IsTopologyOnPlane(CATSoftwareConfiguration * iConfig, CATTopology & iPolyTopObject, double iTol, CATMathPlane &iPlane);

};

#endif
