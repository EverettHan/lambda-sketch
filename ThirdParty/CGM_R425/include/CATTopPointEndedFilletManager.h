#ifndef CATTopPointEndedFilletManager_H
#define CATTopPointEndedFilletManager_H

//===================================================================
// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATTopPointEndedFilletManager.h
// 		
//===================================================================
//  May 2005  Creation: TND
//===================================================================

#include "CATCGMNewArray.h"
#include "CATTopRibObject.h"
#include "CATVertex.h"
#include "ListPOfCATTopPropagationEdge.h"
#include "CATMathVector.h"
#include "CATBoolean.h"
#include "ListPOfCATCell.h"
#include "CATBody.h"
//#include "Ribbon.h"
#include "Fillet.h"
#include "CATGeoFactory.h"
#include "CATTopData.h"
#include "CATMathVector.h"
#include "ListPOfCATCell.h"
#include "CATEdge.h"
#include "CATSoftwareConfiguration.h"

/*
  This class takes a list of Super edge (in fact a ListPOfCATTopPropagationEdge) and a CATVertex (_VertexInCommun) in Input.
  It searches the edges who have the _VertexInCommun as extremities and are different from the ListPOfCATPropagationEdge.
  Then it forms a body by  extrapolating and extruding this edges.
*/

class ExportedByFillet CATTopPointEndedFilletManager:
  public CATTopRibObject
{
public:
  CATCGMNewClassArrayDeclare;      // Pool allocation

  CATTopPointEndedFilletManager(CATGeoFactory *Factory,CATTopData *TopData);
  virtual ~CATTopPointEndedFilletManager();

  //Initialise the VertexInCommun
  void SetVertexInCommun(CATVertex *iVertexInCommun);

  //Get the VertexInCommun
  CATVertex *GetVertexInCommun();

  //Initialise the _InputBody
  void SetInputBody(CATBody *iInputBody);

  //Initialise the list of Super Edge
  void SetPropagationEdgeList (ListPOfCATTopPropagationEdge &iPropagationEdge);

  //Get the list of Super Edge
  void GetPropagationEdgeList(ListPOfCATTopPropagationEdge &oPropagationEdge);

  //Get the ListOfCATCell _CellsToExtrapolate (The cell in _CellsToExtrapolate contain the VertexInCommun as extremities)
  void GetCellToExtrapolateList(ListPOfCATCell &oCellToExtrapolate);

  //Initialise the DistanceForExtrapolation
  void SetDistanceForExtrapolation(double iDistanceForExtrapolation);

  //Initialise variable _ContinuityExtrapolation
  void SetContinuityExtrapolation(int iContinuityExtrapolation);

  //Make all the traitments
  void Run();

  //Return _ResultBody
  CATBody *GetResult();

  // Return a boolean for color
  CATBoolean GetColor();

private:
  //Return the vector tangent to CATCell icell at the Vertex VertexOfCell
  CATMathVector GetVectorTangentFromCATCell(CATCell *iCell,CATVertex *VertexOfCell);

  //Take the vector tangent to the Super Edge at the _VertexInCommun
  CATMathVector GetVectorTangentToThePropagationEdgeAtIntersectionVertex();

  //Calcule the distance between two vertices
  double DistanceBetweenTwoVertices(CATVertex *iFirstVertex,CATVertex *iSecondVertex);

  //Calcul the distance of a curve
  double DistanceOfACurve(CATCell *iCell);

  //Fill the ListPOfCATCell _CellToExtrapolate
  void FillCellToExtrapolate(ListPOfCATCell &oCellToExtrapolate,CATMathVector &iVectorTangentInVertexInCommun);

  //Extrapol the body iBody at the vertex iVertexToExtrapolate
  CATBody *ExtrapolateBody(CATBody *iBody,CATVertex *iVertexToExtrapolate);

  //Select the edges which contain iVertex and are different of the edges iEdgeInitial
  void SelectEdgesWhichContainVertex(CATVertex *iVertex,ListPOfCATEdge &iEdgeInitial,ListPOfCATCell &oEdgeResult);

  // Select the Edge of iEdgeWhichContainVertex which prolonge the Edge iCell
  CATCell *SelectEdgeInContinuity(CATVertex *iVertexInCommun,CATCell *iCell,
    ListPOfCATCell &iEdgeWhichContainVertex,CATVertex *&oEndVertex);

  //Calculate the distance for Extrusion
  void ComputeDistanceForExtrusion();

  //Calculate a Vector who will serve for the calcul of extrusion's direction.
  // Other params will serve to calculate the body for extrusion
  CATMathVector CalculParamForExtrusionAndExtrapolBody(CATCell *iCell,CATVertex *&oVertex,int &oDirection,
    int iOrientationOfFirstCellAgainstVertexInCommun=0);

  //Extrude a Body in a CATMathDirection
  CATBody *ExtrudeBody(CATBody *iExtrapolBody, const CATMathDirection &iDirectionOfExtrude);

  //Create a ListPOfCATCell and a CATLISTOfInt (For the orientation) in order to create a Body (who will be extrapolate).
  //If iCell is too small (<_DistanceForExtrapolation) we try to prolonge the cell. (In this
  //method we must pay attention at the orientation of the edge in order to form a correct body).
  void CreateListInOrderToCreateABody(ListPOfCATCell &oListCATCell,CATListOfInt &oListOfOrientation,
    CATVertex *iVertexForExtrapolation,int iFirstOrientation,CATCell *iFirstCell,int iFirstOrSecondCellToExtrapolate=0);

  //If the extrude has failed we take a plan perpendicular to the tangent at the _VertexInCommun point
  CATBody *GetPlanePerpendicularToTheTangent(CATVertex *iVertex,CATMathVector &iVectorTangentAtSuperEdge);

  //Calculate a Body (which will form the _ResultBody) if the extrapolation failed.
  //( We prolonge _CellToExtrapolate[1] in tangent and we form a body)
  CATBody *GetBodyLine(CATCell *iCellWhichContainVertex,CATVertex *iVertexInCommun);

  //Take two bodies and form one body
  CATBody *TakeTwoBodiesAndFormOneBody(CATBody *iExtrapolateBody,CATBody *iLineBody);

private:
  //Vertex in commun
  CATVertex *_VertexInCommun;

  //ListP of SuperEdge
  ListPOfCATTopPropagationEdge _PropagationEdge;

  // Edges which contains the vertex and are different of the edges of the ListPOfCATTopPropagationEdge.
  // (Be careful: the angle between these edges and the vector tangent with the propagation edge must
  // be between [Pi/6,5Pi/] or [7Pi/6,11Pi/6])
  ListPOfCATCell _CellToExtrapolate;

  //Distance for extrapolation
  double _DistanceForExtrapolation;

  // Maximize the distance for extrapolation
  double _DistanceForExtrapolationDebug;

  //Distance for extrusion
  double _DistanceForExtrusion;

  CATGeoFactory *_Factory;
  CATTopData *_TopData;

  //Input Body
  CATBody *_InputBody;

  //Result Body
  CATBody *_ResultBody;

  //To extrapolate in continuity or in tangence (2 for continuity and 1 for tangence)
  int _ContinuityExtrapolation;

  //Boolean for color
  CATBoolean _Color;
};
#endif
