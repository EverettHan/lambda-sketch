#ifndef DraftUtilities_H
#define DraftUtilities_H


// COPYRIGHT DASSAULT SYSTEMES 2004
#include "Draft.h"
//#include "ExportedByCATFDGImpl.h"
#include "CATMath.h"
#include "CATBoolean.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATVertex.h"
#include "ListPOfCATCell.h"
#include "ListPOfCATBody.h"
#include "ListPOfCATDomain.h"
#include "CATListOfCATGeometries.h"
#include "CATTopDefine.h"
#include "CATMathConstant.h"
#include "CATCGMJournalList.h"
#include "CATTopOpInError.h"

class CATCell;
class CATVertex;
class CATEdge;
class CATFace;
class CATShell;
class CATWire;
class CATBody;

class CATGeoFactory;
class CATPCurve;
class CATSurParam;
class CATPointOnEdgeCurve;
class CATCurve;
class CATCrvParam;
class CATCrvLimits;
class CATSurface;
class CATPlane;
class CATPoint;

class CATMathVector;
class CATMathPoint;
class CATMathDirection;
class CATMathBox;
class CATMathSetOfPointsND;

class CATSoftwareConfiguration;
class CATTopologicalOperator;

class ExportedByDraft DraftUtilities{
  public:

  static CATBoolean GetVerticesOfWire(CATWire* iWire, CATLISTP(CATVertex) &oInternalVertices
                                      ,CATLISTP(CATVertex) &oEndVertices);

  static CATBoolean VerticesAreCoincident(CATVertex* iVertex1, CATVertex* iVertex2,const double &iTol);

  static void GetPointFromVertex(CATVertex* iVertex, CATMathPoint &oPoint );

  static CATBoolean ProjectPointOnCurve(CATGeoFactory* iGeoFactory, CATSoftwareConfiguration* iConfig
                                      ,CATCurve* iCurve ,const CATMathPoint &iPointToProject, const CATCrvLimits &iProjLimits
                                      ,CATCrvParam &oProjectParam);

  static CATBoolean CorrectMatterSideOfFace(CATFace* iFaceToCorrect, CATFace* iRefFace, CATEdge* iCommonEdge
                                           ,CATShell* iShell, CATBody* iBody);

  static CATBoolean CorrectMatterSideOfFaces(CATFace* iFace, CATLISTP(CATFace) &iFacesToCorrect
                                            ,CATShell* iShell, CATBody* iBody);

  static CATFace* GetOtherFace(CATEdge* iEdge, CATFace* iRefFace, CATBody* iBody, CATShell* iShell);

  static CATBoolean FindEdgesConfusedVertex(CATVertex* iRefVertex, CATLISTP(CATEdge) &iEdges, const double &iTol
                                           ,CATLISTP(CATEdge) &oEdges, CATLISTP(CATVertex) &oVertices);

  static void GetAllEdges(CATLISTP(CATFace) &iFaces,CATLISTP(CATEdge) &oEdges);

  static CATBoolean GetEdgesReachedFromBrdrVertex(CATVertex* iVertex, CATBody* iBody,CATLISTP(CATEdge) &oEdges
                                                 ,CATSoftwareConfiguration* iConfig);

  static CATBoolean CheckEdgeSharpness(CATEdge* iEdge, CATShell *iShell, CATBody *iBody 
                                      ,CATSoftwareConfiguration* iConfig,const double &iTol, CATBoolean &oIsSharp, CATFace *iOtherFace=0);
  
  static CATBoolean CreateWireFromCurves(CATGeoFactory* iGeoFactory, CATSoftwareConfiguration* iConfig
                                        ,CATLONG32 numCurves,CATCurve** pCurves,CATCrvLimits* pCrvLimits
                                        ,short* pOrients, CATBoolean iFreezeReuslt, CATBody* &oResultBody);

  static double DistancePointVertex(const CATMathPoint &iPoint, CATVertex* iVertex);

  static double SquareDistancePointVertex(const CATMathPoint &iPoint, CATVertex* iVertex);

  static CATBoolean GetBoundedBorderEdges(CATVertex* iVertex,CATShell* iShell,CATBody* iBody
                                          ,CATLISTP(CATEdge) &oBoundedEdges, CATLISTP(CATFace)* oFaces,
                                          CATSoftwareConfiguration* iConfig);

  static CATBoolean GetVIsoParameterEdgesDraft(CATLISTP(CATEdge) &iEdges,CATLISTP(CATFace) &iFaces
                                              ,CATLISTP(CATEdge) &oBoundedEdges, int iType = 0);

  static CATBoolean ReplaceVertex(CATEdge* iEdge, CATVertex* iOldVertex, CATVertex* iNewVertex);

  static CATBoolean DetachFacesAtVertex(CATVertex* iVertex, CATShell* iShell, CATBody* iBodyForShell
                                      ,CATLISTP(CATFace) &iRefFaces, CATBoolean FacesToKeep,
                                      CATSoftwareConfiguration* iConfig);

  static CATBoolean DetachFaceFromEdge(CATFace* iFace, CATEdge* iEdge, CATShell* iShell, CATBody* iBodyForShell
                                      ,CATSoftwareConfiguration* iConfig);

  static CATBoolean GetModifiedFaces(CATFace* iFace, CATCGMJournalList* iJournal,CATLISTP(CATFace) &oFaces, CATBoolean iExclusive = TRUE);

  static CATBoolean GetModifiedFace(CATFace* iFace, CATCGMJournalList* iJournal, CATFace* &oFace, CATFace** oOtherFace = 0, CATLISTP(CATFace) *iFacesToIgnore = 0);

  static CATBoolean AssignGroupsToFaces( CATLISTP(CATFace) &iRefFaces, CATLISTP(CATFace) &iFacesToGroup
                                      ,CATLISTP(CATFace)** &oGroupOfFaces);

  static CATBoolean HaveCommonEdge(CATFace *iFace1, CATFace* iFace2);

  static CATBoolean GetUIsoParameterEdgesSweep(CATLISTP(CATEdge) &iEdges,CATLISTP(CATFace) &iFaces
                                              ,CATLISTP(CATEdge) &oBoundedEdges, int iType );

  static CATBoolean EvalContinuityAtCommonVertex(CATEdge *iEdge1, CATEdge* iEdge2, CATTopGeoContinuity  &oContinuity
                                                ,double *oGap = 0, CATVertex** oVertex = 0, CATVertex* iVertex = 0
                                                ,CATBoolean iEvaluate = TRUE, CATBoolean *oDefined = 0, double *oAng = 0);

  static CATBoolean AreCongruent(CATPoint* iPoint1, CATPoint* iPoint2, const double &iTol);

  static CATBoolean AreCongruent(CATPlane* iPlane1, CATPlane* iPlane2, const double &iTol);

  static void RotateDir(CATMathVector &ioDirToRotate,const CATMathPoint &iOrigin
                        ,const CATMathDirection &iAxis, const CATAngle &iAng);

  static CATBoolean JournalFindNumLast(CATCGMJournalList* iJournal, const CATCGMJournalRequest &iRequest
                                      ,CATFace* iFace, CATLISTP(CATFace) &iTargetFaces
                                      ,CATLISTP(CATGeometry) &iFacesToExclude, int &oNumLast, int *oMaxInfo = 0);

  static CATBoolean GetBoundedCells(CATVertex* iVertex, CATBody *iBody, CATGeometricType iReferenceType
                                    ,CATLISTP(CATGeometry) *iRefGeometry, CATLISTP(CATGeometry) &oBoundedGeom,
                                    CATSoftwareConfiguration* iConfig);

  static CATBoolean CreatePlaneBody(CATGeoFactory* iGeoFactory, CATSoftwareConfiguration* iConfig
                                           ,CATFace* iRefFace, double *iExtrapol, CATBody* &oBody);

  static CATBoolean DivideIntoG1Shells(CATGeoFactory* iGeoFactory,CATSoftwareConfiguration* iConfig
                                      ,CATBody* iBody, CATShell* iShell, CATLONG32 &oNumG1Shells );              

  static CATBoolean DivideIntoG1Shells(CATGeoFactory* iGeoFactory,CATSoftwareConfiguration* iConfig
                                      ,CATBody* iBody, CATShell* iShell, CATLONG32 &oNumG1Shells, CATLISTP(CATFace)*& oG1Shells);              

  static double DistanceVertexVertex(CATVertex* iVertex1, CATVertex* iVertex2);

  static CATBoolean IsFaceType(CATSoftwareConfiguration* iConfig, CATFace* iFace, CATGeometricType iRefType);

  static void GetAllFaces(CATShell *iShell, CATLISTP(CATFace) &oFaces);

  static CATBoolean CreateBodyFromCells(CATGeoFactory* iGeoFactory, CATSoftwareConfiguration* iConfig,
                                        CATLISTP(CATCell) &iCellList, CATBody* &oBody, CATLISTP(CATDomain)* oCreatedDomains = NULL);

  static CATBoolean ExtractErrDiagnostics(CATError* iErr, CATErrorId &oErrId
                                         ,CATLISTP(CATBody) &oErrBodies, CATLISTP(CATBody) &oContextBodies);

  static CATBoolean IsAPlane(CATSoftwareConfiguration* iConfig, CATSurface* iSurface, CATMathPoint* oPoint = 0, CATMathVector* oNormal = 0);

  static CATBoolean IsACylinder(CATSoftwareConfiguration* iConfig, CATSurface* iSurface, CATMathDirection* oAxis=0);

  static CATBoolean IsATabCylinder(CATSoftwareConfiguration* iConfig, CATSurface* iSurface, CATMathDirection* oAxis=0);

  static CATBoolean CreateConeFace(CATBody* iBody, CATFace* iRefDraftFace, double iEndRuleLength
                                  ,CATFace* &oConeFace, CATVertex* &oApexVertex, CATEdge* &oStartSlantBorder, CATEdge* &oEndSlantBorder);

  static CATBoolean SplitFace(CATTopologicalOperator *iTopOp,CATFace* iFace, double iSplitLength 
                             ,CATFace* &oNewFace, CATLISTP(CATEdge) &ioEdgesToSplit1
                             ,CATLISTP(CATEdge) &ioEdgesToSplit2, CATVertex* iRefVert1, CATVertex* iRefVert2
                             ,CATBoolean iIsParam = TRUE);

  static CATBoolean SplitEdgesAtParLength(CATTopologicalOperator *iTopOp,CATFace* iFace, double iSplitLength 
                                          ,CATLISTP(CATEdge) &ioEdgesToSplit, CATVertex* iRefVert, int &oFirstIndex
                                          ,CATBoolean iIsParam = TRUE);

  static CATBoolean SplitEdge(CATSoftwareConfiguration* iConfig, CATTopologicalOperator* iTopOp
                             ,CATCrvParam & iSplitPar, CATVertex* iRefVert, CATLISTP(CATEdge)& ioEdgesToSplit);

  static CATBoolean SplitFace(CATTopologicalOperator *iTopOp,CATFace* iFace, CATShell* iOwnShell, 
                              CATLISTP(CATEdge) &ioEdgesToSplit1, CATLISTP(CATEdge) &ioEdgesToSplit2, CATFace* &oNewFace);

  static CATBoolean SplitEdgesAtPoints(CATGeoFactory* iFactory, CATTopologicalOperator *iTopOp, CATSoftwareConfiguration* iConfig
                                        ,CATLISTP(CATEdge) &ioEdgesToSplit, CATMathSetOfPointsND *iSplitPoints
                                        ,const CATMathPoint &iRefPoint);

  static CATBoolean MergeEdges(CATTopologicalOperator *iTopOp, CATSoftwareConfiguration* iConfig, CATBoolean iKeepFirst
                              ,CATLISTP(CATEdge) &ioEdgesToMerge1,CATLISTP(CATEdge) &ioEdgesToMerge2, const CATMathPoint &iRefPoint);

  static void GetGeometryOnFace(CATVertex* iVertex, CATFace* iFace, CATEdge* iEdge, CATSurface* &oSurf, CATSurParam &oSurPar);

  static CATVertex* GetSingleCommonVertex(CATEdge* iEdge1, CATEdge* iEdge2);

  static void Get3DPointOnPCurve(const CATPCurve *iPCurve,CATCrvParam &iParam,CATMathPoint &oPoint
                                 ,const CATSurface* iSurf=NULL);

  static CATVertex* GetTopoNearestVertex(CATVertex* iVertex, CATFace* iFace, CATEdge* iEdge, CATEdge* iResultEdge);

  static CATBoolean GetCommonEdges(CATGeoFactory* iFactory, CATSoftwareConfiguration* iConfig, CATBody* iSuppBody
                                  ,CATShell* iSuppShell, CATLISTP(CATFace)& iFaces1, CATLISTP(CATFace)& iFaces2
                                  ,CATLISTP(CATEdge)& oEdges, int &oNbDomains, CATTopSharpness& oSharpness);

  static CATBody* IntersectShellShell(CATGeoFactory* iFactory, CATSoftwareConfiguration* iConfig, CATBody* iBody1, CATBody* iBody2);

  static void GetSupportFaces(CATBody* iBody, CATBody* iSupportBody, CATLISTP(CATFace)& oSupportFaces );

  static CATBoolean GetAdjacentFaces(CATSoftwareConfiguration* iConfig, CATGeoFactory* iFactory
                                    , CATLISTP(CATEdge) &iEdges, CATListOfInt &iEdgeOrient, CATBody* iFacesBody
                                    , CATLISTP(CATFace) &oFaces1, CATLISTP(CATFace) &oFaces2, CATBoolean iPropagateEdges=FALSE);

  static CATBoolean TreatCoincidentEndsOfWire(CATGeoFactory* iFactory, CATSoftwareConfiguration* iConfig, CATCGMJournalList* iJournal
                                            , CATBody* iSuppBody, const CATLISTP(CATDomain) &iWiresToTreat );

#ifdef SOU_DraftUtilities_Trials
  //if you want any of these methods, bring it out of SOU_DraftUtilities_Trials
  //don't remove protection of other methods
  static CATBoolean AssignGroupsToFaces( CATLISTP(CATFace) &iRefFaces, CATLISTP(CATFace) &iFacesToGroup
                                      ,CATListOfInt &oGroupIndexOfFaces);

  static CATBoolean CheckFaceType(ListPOfCATFace &iFaces, CATGeometricType iReferenceType);

  static CATBoolean FindCommonVertex(CATWire* iWire1, CATWire* iWire2, CATVertex* &oCommonVertex);  

  static CATBoolean FindConfusedVertex(CATVertex* iRefVertex, CATWire* iWire, const double &iTol
                                      , CATVertex* &oConfusedVertex, CATMathVector &oTangent);

  static CATBoolean FindSingleIntersectionPlnSur( CATGeoFactory* iFactory,CATSoftwareConfiguration* iConfig
                                                , CATPlane* iPlane, CATSurface *iSurface, const CATMathPoint &iInitPoint
                                                , const CATMathDirection &iRefDirection, const double &iTol
                                                , CATCurve *&oIntCurve); 
 static double GetBasicAngle(double iAngle);

 static void GetBox(const CATMathPoint &iPt1, const CATMathPoint &iPt2, CATMathBox &oBox);

 static CATBoolean PropagateEdge(CATEdge* iEdge, CATLISTP(CATVertex) &iStoppingVertices, CATLISTP(CATEdge) &iCandidateEdges
                                ,CATBody* iBody, CATLISTP(CATEdge) &oPropagEdges,
                                CATSoftwareConfiguration* iConfig);

 static CATBoolean WiresHaveConfusedEnds(CATWire* iWire1, CATWire* iWire2, const double &iTol
                                          ,CATBoolean &oOrient);

#endif

};

#endif
