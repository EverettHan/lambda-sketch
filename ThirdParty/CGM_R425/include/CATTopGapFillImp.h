/* -*-c++-*- */
#ifndef CATTopGapFillImp_H_
#define CATTopGapFillImp_H_

#include "AdvancedDraft.h"
#include "CATTopGapFill.h"
#include "CATExtTopOperator.h"
#include "ListPOfCATEdge.h"
#include "CATVertex.h"
#include "ListPOfCATVertex.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATWire.h"
#include "CATCurve.h"
#include "CATSurface.h"
#include "CATWire.h"



class CATGeoFactory;
//class CATBody;
class CATFace;
class CATDomain;

//-----------------------------------------------------------------------------
class ExportedByAdvancedDraft CATTopGapFillImp : public CATExtTopOperator
//-----------------------------------------------------------------------------
{
 public:
  CATTopGapFillImp (CATGeoFactory*     iContainer,
                    CATBody*           iPart,
                    CATFace*           iFace1,
                    CATFace*           iFace2);
  

  ~CATTopGapFillImp();
  
  int Run();

  void SetPartingElement(CATBody* iParting);
  void SetWireOnBody(CATLISTP(CATWire) *iWilreList);
  void SetContinuityOnBody(int iCont);

  CATBody* GetResultBody();

  //VUC: 2010-02-02
  void RequireDefinitionOfInputAndOutputObjects();
  
  CATCGMNewClassArrayDeclare;        // Pool allocation

private:

  int RunOperator(); //RunOperator
  int RunOperator2(); //Operator specific to BSD

  CATBoolean GroupEdges(CATLISTP(CATEdge)* iEdgeList, 
                      CATLISTP(CATEdge)* ioEdgeList1, 
                      CATLISTP(CATEdge)* ioEdgeList2);

  CATBoolean GetOrderedData(CATLISTP(CATEdge)* iEdgeList,
                      CATLISTP(CATVertex)* ioEVertexList,
                      CATLISTP(CATVertex)* ioPVertexList,
                      CATLISTP(CATEdge)* ioCapDraftEdgesClassified1,
                      CATLISTP(CATEdge)* ioCapDraftEdgesClassified2);

  CATBoolean AppendEdge(CATEdge* iEdge, CATLISTP(CATEdge)* ioCapDraftEdgesClassified,
                      CATLISTP(CATFace)* CapDraftFacesClassified);
  double SquareDistanceVV(CATVertex* V1, CATVertex* V2);
  CATEdge* GetTransverseEdge(CATVertex* iVertex, int index, CATEdge ** oEdgeToAppend = NULL);
  CATEdge* GetContinuityEdge(CATVertex* iVertex, CATEdge* FirstEdge);

  CATEdgeCurve* CreateSplineBetweenVertices(CATLISTP(CATEdge)* iEdgeList, CATLISTP (CATVertex)* iVertexList, 
                      CATBoolean OneSideG1 = FALSE);

  CATBody* CreateProjection(CATEdgeCurve * iECurve, CATBody * iSupportBody);

  CATBody* CreateBodyFromEdge(CATEdgeCurve* iECurve);
  CATBody* CreateBodyFromSurface(CATSurface* iSurf);

  CATBody* CreateFill(const ListPOfCATBody & iFillBoundary, const ListPOfCATBody & iFillSupports, const CATListOfInt & iListCont);

  void CreateFillData(CATBody* ioBorder, int iCont, CATLISTP(CATBody)* ioBorderList, CATLISTP(CATBody)* ioSupportList,
                      CATListOfInt* ioContinuity, CATBoolean CheckPlaneSupport = FALSE);

  void CreateFillData(CATLISTP(CATEdge)* iBorderEdgeList, CATLISTP(CATFace)* iSupportFaceList, int iCont,
                      ListPOfCATBody* ioBorderList, ListPOfCATBody* ioSupportList, CATListOfInt* ioContinuity);

//  CATBody* SetOrientationOfFill(CATBody* iFillBody);

  CATBoolean GetOrientationOfFill(CATFace* iDraftFace, CATBody* iFillBody, CATBody* iJoinBody);

  CATBoolean GetDraftType(CATVertex* iVertex);
  CATBoolean IsVerticesOnSameSide(CATBody* iBodyOnParting, CATVertex* iV1, CATVertex* iV2);
  CATBoolean IsVerticesOnSameSide(CATFace* iFace1, CATFace* iFace2, CATVertex* iV1, CATVertex* iV2, CATMathDirection* iPullDir, 
    CATMathPoint* iMP1, CATMathPoint* iMP2, short* ioSameside);

  CATBody* CreateLayDown(CATBody* iToLay, CATBody* iSupport);

  CATBoolean IsEndVertex(CATEdge* iEdge, CATVertex* iVertex);
  CATVertex* GetOtherVertex(CATEdge* iEdge, CATVertex* iVertex);

  CATBody* JoinBodies(CATBody* iBody1, CATBody* iBody2);

  CATBody* SewSkinBody(CATBody* iBodyToSew, CATBoolean iSelectionSide);

  void UpdateGapFillJournal(CATBody * iFilledBody, int iSide);
  void PopulateJournalInfo(CATEdge* iEdge, int iSide);

  
  CATBody* _ResultBody;
  CATBody*  _BodyToFill;
  CATFace*  _Face1;
  CATFace*  _Face2;
  CATTopData _TopData;

  CATGeoFactory* _Factory;
  CATGeoFactory* _FactoryImpl;

  CATBody*  _PartingElement;
  CATLISTP(CATWire) *_BodyWireList;

  CATBoolean _IsBothSideFill;
  CATBoolean _IsBodyWirePresent;
  CATBoolean _IsRRDraft;
  CATBoolean _IsAttributesPresent;
  int        _ContinuityOnBody;

  CATLISTP(CATEdge) _CapBrdEdges[2];
  CATLISTP(CATFace) _CapDraftFaces[2]; //Cap Face Neighbour face on Draft
  CATLISTP(CATFace) _JournalFaceList[2];
  
};


#endif
