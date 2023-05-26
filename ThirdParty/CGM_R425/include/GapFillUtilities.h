/**
 * @COPYRIGHT DASSAULT SYSTEMES 2008
 */

 //=============================================================================
 //
 // COPYRIGHT   : DASSAULT SYSTEMES 2008
 //
 // April. 08	Creation                                                 BQJ
 //
 //  23/09/19 PKC passage de config dans GetNeutralWireIntersection
 //               idem CheckForOneSidedFill 
 //               idem ActualDraftLength
 //               idem GetInterSessionGFPairNN 
 //=============================================================================

#ifndef GapFillUtilities_h
#define GapFillUtilities_h

#include "BOIMPOPE.h"
#include "CATTopOperator.h"
#include "ListPOfCATFace.h"
#include "CATMathDirection.h"
#include "CATTopGapFillAttr.h"
#include "ListPOfCATVertex.h"

class CATEdge;
class CATBody;
class CATVertex;
class CATSoftwareConfiguration;


class ExportedByBOIMPOPE GapFillUtilities
{
public:

   static CATBoolean GetInterSessionGFPairNN(CATBody *ipBodyToFill, CATSoftwareConfiguration* iConfig, CATLISTP(CATGeometry) *iCurrentEndCapFaces, CATLISTP(CATFace) *iOldCapFaces,
                                             CATLISTP(CATGeometry) *ioCFPair1, CATLISTP(CATGeometry) *ioCFPair2, double *iTrackLengths);

   static CATBoolean GetInterSessionGFPairRR(CATBody *ipBodyToFill, CATLISTP(CATGeometry) *iCurrentEndCapFaces, CATLISTP(CATFace) *iOldCapFaces,
                                             CATLISTP(CATGeometry) *ioCFPair1, CATLISTP(CATGeometry) *ioCFPair2, double *iTrackLengths);

   static CATBoolean CheckEndCapFacePairing(CATLISTP(CATGeometry) *iCurrentEndCapFaces,
                                            CATLISTP(CATGeometry) *ioCFPair1, CATLISTP(CATGeometry) *ioCFPair2,
                                            double *iTrackLengths);

   static CATEdge* GetNextSmoothEdge(CATBody * iBody, CATVertex* iVertex, CATEdge* FirstEdge);

   static CATVertex* GetOtherVertex(CATEdge* iEdge, CATVertex* iVertex);

   static CATBoolean InitialFilteringOfCapFaces(CATLISTP(CATGeometry) *iCurrentEndCapFaces, CATLISTP(CATFace) *iOldCapFaces);

   static CATBoolean GetAttributeDetailsFromCapFaces(CATFace* iFace, double * oAngle = NULL, CATMathDirection* oPullDir = NULL, CATMathPoint* oPartingPoint = NULL, short * oDraftType = NULL);

   static void GetAllVertices(CATFace* iFace, CATLISTP(CATVertex) *ioVerticesList);

   static CATBoolean CategorizeVertices(CATLISTP(CATVertex) *iList, CATMathDirection* iPullDir, CATMathPoint *iPVertexMP,
                                        CATLISTP(CATVertex) *ioPV, CATLISTP(CATVertex) *ioV1, CATLISTP(CATVertex) *ioV2);

   static CATBoolean IsFacesCompatible(CATVertex* newVP, CATVertex* newV1, CATVertex* newV2,
                                       CATVertex* oldVP, CATVertex* oldV1, CATVertex* oldV2,
                                       CATMathDirection *iPullDir);

   static double DistVV(CATVertex* V1, CATVertex* V2);

   static void GetMathPlane(CATVertex* V1, CATVertex* V2, CATVertex* V3, CATMathPlane* ioMPlane);
   static double GetProjectedMeanDistance(CATMathPlane* iMPlane, CATVertex* V1, CATVertex* V2, CATVertex* V3);

   static CATLONG32 GetCandidateIndex(const CATListOfDouble & iDistPrj, const CATListOfDouble & iDistDir);

   static void RemoveGapFillAttributes(CATFace* iFace);

   static int GetCapFacePropagationData(CATBody * iBody, CATFace* iFace, CATEdge * ioPropagEdges[], CATVertex * ioStartvertices[]);

   // PKC 23/09/2019 passage config
   static CATVertex* GetNeutralWireIntersection(CATBody * iBody, CATSoftwareConfiguration* iConfig,  CATFace* iFace, double & oLength,
                                                CATLISTP(CATVertex) *iVertexList = NULL);

   static CATBoolean CheckForOneSidedFill(CATBody *ipBodyToFill, CATSoftwareConfiguration* iConfig, CATLISTP(CATGeometry) &iCurrentEndCapFaces,
                                          double *iTrackLengths, CATFace * oSpecialCapFaces[], CATLISTP(CATFace) &iOldCapFaces);

   static double ActualDraftLength(CATBody *ipBodyToFill, CATSoftwareConfiguration* iConfig, CATFace* iCFace);


};
#endif

