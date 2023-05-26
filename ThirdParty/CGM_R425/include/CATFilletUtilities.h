#ifndef CATFilletUtilities_H
#define CATFilletUtilities_H

// COPYRIGHT DASSAULT SYSTEMES 2010
#include "Fillet.h"
#include "CATCollec.h"

class CATSoftwareConfiguration;
class CATBody;
class CATWire;
class CATFace;
class CATEdge;
class CATVertex;
class CATEdgeCurve;
class CATPCurve;
class CATCrvParam;
class CATMathPoint;
class CATTopRibMacroTool;
class CATLISTP(CATBody);

#include "ListPOfCATEdge.h"

#include "CATBoolean.h"
#include "IUnknown.h"

class ExportedByFillet CATFilletUtilities
{
public:

  enum  Method { Basic = 0, Advanced = 1 };

  static HRESULT IsACapFaceCandidate(CATSoftwareConfiguration* iConfig,                     
                                     CATBody*                  iBody,
                                     CATLISTP(CATEdge)        &iAllEdges,                   // All Edges to consider, must be a closed contour
                                     const CATBoolean          iCheckFor2SliverVertices,    // To check for "turning-back edge" (Fillet: TRUE, Chamfer: FALSE) 
                                     int                      &oIndexOfFeatureInoEdgesList, // between 0 and 2. Available only if iCheckSliverVertex (determined from SliverVertices)
                                     CATLISTP(CATEdge)         oEdgesList[3],               // Sides of the Face candidate, ordered according to iAllEdges (the first one is build from iAllEdges[1]). In oEdgesList[i], Edges are ordered according to the first edge in List
                                     CATBoolean                oPolygonSliverVertex[3][2],  // is side end vertex Sliver ?
                                     CATEdge*                  oNextEdge[3][2],             // edge adjacent to side on both side
                                     CATVertex*                oEndVertex[3][2]);           // side end vertex


  static CATBoolean IsATriangularCapFace(CATSoftwareConfiguration* iConfig,                     
                                         CATBody*                  iBody,
                                         CATLISTP(CATEdge)        &iAllEdges,                   // All Edges to consider, must be a closed contour
                                         const CATBoolean          iCheckFor2SliverVertices,    // To check for "turning-back edge" (Fillet: TRUE, Chamfer: FALSE) 
                                         int                      &oIndexOfFeatureInoEdgesList, // between 0 and 2. Available only if iCheckSliverVertex (determined from SliverVertices)
                                         CATLISTP(CATEdge)         oEdgesList[3],               // 3 Sides of the triangular Face, ordered according to iAllEdges (the first one is build from iAllEdges[1]). In oEdgesList[i], Edges are ordered according to the first edge in List
                                         CATBoolean                oTriangleSliverVertex[3][2], // is side end vertex Sliver ?
                                         CATEdge*                  oNextEdge[3][2],             // edge adjacent to side on both side
                                         CATVertex*                oEndVertex[3][2] );          // side end vertex
                                                                                         

  static void PropagateEdgeOnSmoothVertices(CATSoftwareConfiguration* iConfig,
                                            CATBody*                  iBody,
                                            CATLISTP(CATEdge)        &ioAllEdges,
                                            CATWire*                  iWireToFillUp,
                                            CATLISTP(CATEdge)        &ioAssembledEdges,
                                            CATBoolean                oSliverVertex[2],
                                            CATEdge*                  oNextEdge[2],
                                            CATVertex*                oEndVertex[2]);

  static HRESULT CreateLimitingBodyForGivenRadius(CATSoftwareConfiguration* iConfig,
                                                  CATFace *iFace, 
                                                  double iRadius,
                                                  CATLISTP(CATBody) &oListOfLimitingBodies,
                                                  double *iPrecision = NULL,
                                                  CATFilletUtilities::Method = Basic,
                                                  double *iLinearTol = NULL);

  static CATBody * CreateLimitingBodyForAGivenParam(CATSoftwareConfiguration* iConfig,
                                                    CATFace      *iFilletFace,
                                                    CATEdge      *iTrackEdge,
                                                    CATEdgeCurve *iEdgeCurve,
                                                    CATPCurve    *iTrackEdgePCurve, 
                                                    double        iGlobalParamOnPCurve,
                                                    double        iRadius);

  static int GetDualRollingSupportNumber(CATTopRibMacroTool* iMacroTool, const int iSide); // returns the other side

  // Local test using homotopy
  static HRESULT DoesNeedAKeepEdge(CATSoftwareConfiguration& iConfig, CATBody& iBody, CATEdge& iEdge, const double iRadius, CATMathPoint& iPosition);

  // Global test 
  static HRESULT DoesNeedAKeepEdge(CATSoftwareConfiguration& iConfig, CATBody& iBody, const ListPOfCATEdge& iEdges, const double iRadius, const int iSampling); // iSampling = 0 => full test with DynFillet

  //static HRESULT GetRadiusAtPoint(CATSoftwareConfiguration* iConfig,
  //                               CATBody * iCreationBody, 
  //                               CATBody * iInitialBody,
  //                               CATLISTP(CATDynFilletRibbon) & iFilletSpecs,
  //                               CATDynFilletRadius *&ioRadius);

  //static CATEdgeRibbon *GetEdgeRibbonFromSpecs (CATSoftwareConfiguration* iConfig,
  //                                              CATBody * iResult, 
  //                                              CATBody * iSpecsBody,
  //                                              CATEdge *iEdge, 
  //                                              CATLISTP(CATDynFilletRibbon) &iEdgeFilletsSpecs,
  //                                              CATLISTP(CATDynFilletRibbon) *iEdgeFilletsNotToLookAt,
  //                                              CATBoolean &iTestWithoutParting, 
  //                                              CATDynEdgeFilletRibbon *&oFoundSpec,                                                         
  //                                              CATListPV &oRadiusAlloues,
  //                                              CATBoolean &oVariable);

};

#endif
