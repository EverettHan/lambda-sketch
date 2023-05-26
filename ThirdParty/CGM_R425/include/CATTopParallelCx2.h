// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATTopologicalParallelCx2 :
// Implementation class for TopologicalParallel operator.
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// March 99  Creation                          JHN
// 02/12/08 NLD Utilisation de CATCGMOperatorDebug pour outillage standard de debug/mesure
//=============================================================================
#ifndef CATTopParallelCx2_H
#define CATTopParallelCx2_H

//#define ExtrapolParallel

#include "CATCGMOperatorDebug.h"
#include "CATTopParallelFreeze.h"
#include "CATMathDef.h"
#include "CATExtrapolParallelTool.h"
#include "CATTopDef.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATVertex.h" // Modified By : SUH : 2003:7:29
#include "CATDataType.h"
#include "CATListOfCATCrvParams.h"

#include "CATIACGMLevel.h"

class CATCurve;
class CATGeoFactory;
class CATMathVector;
class CATBody;
class CATShell;
class CATFace;
class CATSurface;
class CATDomain;
class CATVertexInFace;
class CATVertex;
class CATPointOnSurface;
class CATSurParam;
class CATSurLimits;
class CATCGMJournalList;
class CATAdvTopoOpeInputError;
class CATGeometry;
class CATFrFCompositeCurve;
class CATDistanceTool;
class CATICGMDistanceTool;
class CATICGMDistanceTool;
class CATFrFCompositeCurveMapping;
class CATLaw;
class CATWireTopOp;
class CleanCurveEdgeMap; // Modified By : SUH : 2003:7:29
class CATPointOnEdgeCurve;
class CATPointOnCurve;
class CATExtTopParallel;


//-----------------------------------------------------------------------------
class CATTopParallelCx2 : public CATTopParallelFreeze
{
 public:

  //--------------
  // Constructors 
  //--------------
  CATTopParallelCx2(CATGeoFactory *iFactory, CATTopData * iData,
					          CATBody *iCurve,CATBody *iSupport, CATDistanceTool * OffsetValue);

  CATTopParallelCx2(CATGeoFactory *iFactory, CATTopData * iData,
    CATBody *iCurve,CATBody *iSupport, CATICGMDistanceTool * OffsetValue);

  CATTopParallelCx2(CATGeoFactory *iFactory, CATTopData * iData,
					          CATExtrapolParallelTool * iOffsetValue, CATBody * iCurve);

  /** @nodoc */
  virtual ~CATTopParallelCx2();

  virtual void BuildExtremRound(CATBody * oCorner[2], CATBody * oPCenter[2], CATLONG32 iExtrem[2],CATLaw ** iMapLaws);

  //---------------
  // Basic methods 
  //---------------
  // non necessaire car Run() toujours declare 
  // CATCGMOperatorDebugRunResult(CATTopParallelCx2,CATTopParallelFreeze)
  int   Run();  
  CATBody *    GetResult();

#ifdef DEBUG
  CATBoolean HasConsistentResult(CATLONG32 & nberr, CATError **& Diagnostic)  const;
#endif

	void GetSide(CATOrientation & oOri);
	void SetSide (CATOrientation iOri);

  // virtual in CATTopParallelFreeze
  CATLONG32 SetSimplifyTool(CATSimplifyParallelTool* CurSimplif);

  //------------------------
  // Methods for CGM Replay 
  //------------------------
  static const CATString *GetDefaultOperatorId() { return &_OperatorId; }
  void SetIsNewLaw() { _iNewLaw = 1; }
  
protected :

  static CATString  _OperatorId;
  const  CATString *GetOperatorId();
  CATExtCGMReplay  *IsRecordable( short &LevelOfRuntime, short &VersionOfStream );
  void              WriteInput( CATCGMStream  &ioStream );
  void              Dump( CATCGMOutput &os );
  int               RunOperator();
  void              RequireDefinitionOfInputAndOutputObjects();

#ifdef CATIAR419
  /** @nodoc @nocgmitf */
  virtual int RunExactOperator();
  /** @nodoc @nocgmitf */
  virtual int RunPolyOperator();
  /** @nodoc @nocgmitf */
  CATExtTopParallel * GetTopParallelExtensible();
  /** @nodoc @nocgmitf */
  virtual void PrepareExtensionBeforeRun(CATExtTopParallel & iExtensible);
  /** @nodoc @nocgmitf */
  virtual void RetrieveOutputDataFromExtension(CATExtTopParallel & iExtensible);
#endif


  //--------------------------
  // Private Methods
  //--------------------------

private:
  //ST5 Wk15-2014: IR-282759 Composites - Necessary to recover correct inputs for Clean operator.
  HRESULT LayDownExtrapWireG1ForClean(CATGeoFactory     * iImplicitFacto, 
                                      CATTopData        * iData,
                                      CATCGMJournalList * ioJournal,
                                      CATBody           * iSupport,
                                      CATBody           *&ioWireG1);
  
  //Cut the wire on discontinuities of the law
  void CutOnLawDiscontinuity (CATGeoFactory * iFact,CATLaw * iCurLaw, CATLaw ** iMapLaws, 
                              CATLaw **& oMapLaws, CATBody * & oInitBody, CATCGMJournalList * iJourn, 
                              CATLISTP(CATCrvParam) * ioParamOfInsertedVtx = 0); // Modified By : SUH : 2003:10:3

  //run ini
  int RunIni(short level_to_execute, CATTopData * iData, CATLaw * CurLaw, CATCGMJournalList * IntJourn, CATLONG32 iG1Computation);

  //
  CATLONG32 TestMarche(CATLONG32 nbWiresG1,CATBody ** WiresG1,CATBody ** TabParallel, CATLONG32 * NumDebWire, CATLONG32 * NumFinWire);

  //twist treatment
  void ComputeBodyWithoutTwist(CATWireTopOp * Operateur,CATCGMJournalList * IntJourn, CATBody * & ParallelResu,
                               CATLONG32 & NumDebWire,CATLONG32 &NumFinWire, CATLONG32 * DescDeb,CATLONG32 * DescFin, 
                               CATLONG32 *& ResuDescDeb,CATLONG32 *& ResuDescFin);

  //AOV wk 22 2005 MacCabe (twist treatment:old method to manage twists to keep or not)
  void TwistToKeepOld(CATGeoFactory * ImplicitFacto,CATWire * CurWire,CATListOfInt & WrongEdges,CATLONG32 nbedges,
	                    CATLONG32 & isize,CATLONG32 idom,CATLONG32 & WrongSize,CATLONG32 NumDebWire,CATLONG32 NumFinWire);

  //AOV wk 22 2005 MacCabe (twist treatment:old method to manage twists, before Z treatment)
  void OldMethodForTwistTreatment(CATWire * CurWire,CATListOfInt WrongEdges,CATLONG32 & isize,CATBoolean FirstAssembly,
                                  CATLONG32 & nbedges,CATCGMJournalList * volatile & IntJourn,
                                  CATLISTP(CATGeometry) & iDeletedObjects,CATBody *& OldBodyDomain,CATDomain *& CurDom,
                                  CATBody * volatile & TwistBodies,CATLONG32 & WrongSize);

  //AOV wk 22 2005 MacCabe (twist treatment:cut around the twist)
  CATBody * SplitAroundTwistAndAssemble(CATLONG32 nbedges,CATWire * CurWire,CATPointOnCurve * PointOnCurve1,CATPointOnCurve * PointOnCurve2,
                                        CATEdge * AdjEdge[2],CATPointOnEdgeCurve * AdjEC1[2],CATPointOnEdgeCurve * AdjEC2[2],
                                        CATOrientation AdjOrient[2],CATLONG32 & SubstractEdges,CATLISTP(CATGeometry) & iDeletedObjects,
                                        CATCGMJournalList * volatile & IntJourn,CATLONG32 iadjacentEdge[2],
                                        CATCGMJournalList * volatile & TwistJournal,CATLONG32 WithEnhance=0,double AssembleTolerance=0.0);

  //AOV wk 22 2005 MacCabe (twist treatment:assemble all pieces of solution after cutting twist)
  CATBody * AssembleBeforeAndAfterTwist(CATGeoFactory * ImplicitFacto,CATTopData * MyData,ListPOfCATBody iBodiesToAssemble,
	                                    CATCGMJournalList * volatile & TwistJourn,CATLONG32 WithEnhance,double AssembleTolerance);

  //define if point is at the good distance from initial curve and on the good side
  CATLONG32 ComputeVtxInMatter(CATVertex * Vtx,double &Dist, double & Radius, CATMathVector * TgtOnVtx =NULL );

  //relimitation of solution on extremities by semi sphere
  void EraseExtremRound(CATTopData * iData, CATBody *& ioParallel, CATLONG32 *& ioDescDebWires,CATLONG32 *& ioDescFinWire,CATLaw ** MapLaws, CATLONG32 & oConfusion);

  //
  void DuplicateDistTool();

  //determine if twist must be kept
  CATLONG32 IsTwistToKeep(CATEdge *CurEdge[2],CATOrientation CurOrient[2], CATLONG32 iExtToTest);

  // -------------------------------Start : SUH : 2003:4:7 ----------------------------
  
  //Cleans _CurveLaid in 3D, cuts the body according to law discontinuity,
  // and splits into bodies, ... Each containing one G1 wire. This G1 wire may have slightly sharp 
  // (sharpness = 0.04 radian) vertice.ENSURE that _DistTool->GetType() > 2 before calling it to avoid a core dump.
  CATBody * CleanAndSplitToG1Wires(const short &iLevel_to_execute,
                                   CATTopData * iData, CATCGMJournalList * iIntJourn,
                                   CATLaw ** &oML, CATLONG32 &oNbLaws, CATLONG32 &oIsG1,
                                   const CATLONG32 &G1Measure, const int &G1Model,
                                   CATLISTP(CATBody) &iBodiesToRemove);

  //split _CurveLaid into G1 wires
  CATBody * SplitToG1Wires(const short &iLevel_to_execute, CATTopData * iData, const CATLONG32 &iG1Measure, const int &iG1Model, CATLONG32 &oIsG1);

  // Creates a mapping between edges of the bodies iBody2D and iBody3D
  void FindMaps3D2D(CATBody * iBody2D, CATBody * iBody3D, const CATLISTP(CATEdge) &iDEdges, 
                    const CATLISTP(CATVertex) &iMappedVtx, const CATLISTP(CATVertex) &iDMappedVtx,
                    const double &iTol, CleanCurveEdgeMap ** &oMaps3D2D, CATLONG32 &oNbMaps);

  void FindParam3D2D(CATBody * iBody3D,CATTopData * iTopData, CATPointOnEdgeCurve * iPOECToProject,
                     double iTol,CATEdge * iEdge3d, CATCrvParam * ioParam3d2d,CATCell ** ioSupportCell2);

  // REN wk48 2007. Gives extreme junction edges & its vertices from ParallelG1Sol and removes temporarily junction status,
  // so that these edges can be fixed during cleaning.
  void LocateExtremeJunctionEdgesAndVertices(CATBody * iParallelG1Body, CATLISTP(CATCell) * ioExtremeCells);

  // REN wk48 2007. The junction status is restored for edges, which were fixed before cleaning.
  void UpdateCellsToFix(CATBody * iCleanedBody,
                        CATLISTP(CATEdge) * iDEdges,
                        CATLISTP(CATVertex) * iMappedVtx,
                        CATLISTP(CATVertex) * iDMappedVtx, 
                        CATLISTP(CATCell) * ioCellsToFix);

  CATSoftwareConfiguration* GetSoftwareConfiguration();

  // Each domain of iBody is cleaned in 2D and assembled back. Domain numbered iNumDebWire and iNumFinWire...
  // are not cleaned if they represent twist parts (i.e. iNumDebWire and iNumFinWire are negative)
  // ENSURE that _DistTool->GetType() > 2 before calling it to avoid a core dump.  
  // iCellsToFix are the cells in ioBody which will not be cleaned.
  // set iIs3DClean to TRUE for a 3D Clean, default is 2D Clean on _Support.
  CATBoolean CleanOutputWire(CATBody * &ioBody, const short &iLevel_to_execute, CATCGMJournalList * iIntJourn,
                              const CATLONG32 &iNumDebWire = 0, const CATLONG32 &iNumFinWire = 0,
                              CATLISTP(CATCell) * iCellsToFix = NULL, CATBoolean iIs3DClean = FALSE);

  // When iBody contains one and only one wire domain, which auto-intersects, this creates a ...
  //multi-wire body such that the none of its wires auto-intersects. Output is NULL otherwise.
  CATBody * CreateBodyWithoutAI(CATBody * iBody);

  // For iEdge in iWire, finds support faces through Lying On information of iEdge. If iEdge has no...
  // Lying On info or no face is found, throw occurs. ...
  // Also decides and keeps face at right side if more than one faces are found.
  CATBoolean FindSupportFaces(CATEdge * iEdge, CATDomain * iWire, 
                              CATLISTP(CATCell) * oSuppFaces, CATListOfInt * oSurVsShell);

  //Cuts edge-maps according to LawDiscontinuity info iParamOfInsertedVtx
  void CutEdgeMaps(CATBody * iCutBody, const CATLISTP(CATCrvParam) &iParamOfInsertedVtx, CATLONG32 &ioNbMaps, CleanCurveEdgeMap ** &ioMaps3D2D);

  // -------------------End : SUH : 2003:4:7----------------------  

  //ST5 Wk13-12: Check euclidian solution validity after relimitation operation
  // Parallel solution extremities should either be Images of Input extremities or hit the shell border
  void CheckEuclParallelExtremitiesAfterRelimitation(CATGeoFactory * iImplicitFacto, CATTopData * iTopData, CATBody * iWireDeb, CATBoolean & oIsRelimSolValid);

  //wk 11 aov :tri sur les domaines solution suivant le side et la distance
  void SortOnDomainToKeep(CATBody * WireDeb,CATBody *& NewWireDeb,short level_to_execute,CATCGMJournalList *& IntJourn,CATLONG32 & ErasedDomain);

  //wk 11 2005 aov:test intersection wire - courbe initiale pour suppression des solutions 
  //qui sont a la mauvaise ditance ou du mauvais cote
  int TestInterWithOrig(CATWire * WireToTest);

  //wk 11 2005 aov:suppression des domaines invalides
  int SuppressInvalidDomain(CATGeoFactory * iFacto,CATTopData * iData,CATBody *& Parallel,CATListOfInt ListOfInvalidSol,CATLONG32 & nbsols,CATCGMJournalList *& IntJourn);

  //AOV wk 22 2005 MacCabe:quality measures traces from RLA
  void ComputeQualityMeasuresForRLA();

  //AOV wk 22 2005 MacCabe: retrieve celan option
  void RetrieveCleanOption(CATBoolean & Use3DCurve,CATLONG32 & CleanOutputMode);

  //AOV wk 22 2005 MacCabe: special treatment when offset is nul
  void CheckIfIdentity(CATTopData * NewData,CATCGMJournalList * volatile & IntJourn,CATLONG32 & identique,double & valoffset);

  //AOV wk 22 2005 MacCabe: treatment on law and cutting of the curve on discontinuities of teh law on old level)
  void ComputeAndCutOnMappingLaws(CATGeoFactory * ImplicitFacto,CATTopData * iData,CATCGMJournalList * volatile & IntJourn,
	                                CATLONG32 & nblaws,CATLaw ** volatile & MapLaws);

  //AOV wk 22 2005 MacCabe : special treatment if solution is a closed Wire
  void CheckIfOnlyOneClosedG1Wire(CATLONG32 nbWiresG1,int G1Measure,int G1Model,double valoffset,CATLaw ** MapLaws,
	                                CATBody * BodyOfG1,CATLONG32 tempIsG1Wire,CATLONG32 & IsG1Wire);

  //AOV wk 22 2005 MacCabe:  treatment when no solution
  void ManageNoSolution(CATGeoFactory * ImplicitFacto,CATTopData * iData,CATBody * CurParallelResult,CATBody * BodyWireIni,
	                      CATBody * BoundingWires,CATLaw ** MapLaws,CATLONG32 numfirstlaw,CATBody * TabWiresG1);
    
  //AOV wk 22 2005 MacCabe : build report
  void MakeReport(CATCGMJournalList * volatile & IntJourn,CATError * volatile & StockErr,CATVertex * iv1,CATVertex * iv2,CATBody * BoundingWires);

  //AOV wk 22 2005 MacCabe : udate vertices in report after computation of parallel solutions
  void UpdateVerticesInReport(CATCGMJournalList * volatile & IntJourn,CATCGMJournalList * volatile & StoreJourn,CATVertex * iv1,CATVertex * iv2,
	                            CATBody * CurParallelResult,CATBoolean Use3DCurve,CATBody * BodyWireIni,CATLONG32 nbWiresG1);

  //AOV wk 22 2005 MacCabe : check if solution on border of the support
  void CheckIfSolOnBorderOfSupport(CATGeoFactory * ImplicitFacto,CATTopData * iData,CATLONG32 nbsols,CATLONG32 & err,
	                                 CATLONG32 *& DescDeb,CATLONG32 *& DescFin,CATBody * CurParallelResult,
								                   CATLONG32 nbWiresG1,CATLONG32 NumDebWireiG1,CATLONG32 NumFinWireiG1,
								                   CATWireTopOp * Operateur,CATBody * volatile & BodyErr);

  //AOV wk 22 2005 MacCabe : error treatment after retrieving G1 parallels solutions
  void ErrorTreatment(CATGeoFactory * ImplicitFacto,CATLONG32 err,CATLONG32 nbWiresG1,short level_to_execute,
	                    CATLONG32 nbsols,CATLONG32 *& DescDeb,CATLONG32 *& DescFin,CATBody *& TabParalleliG1,
					            CATBody * TabWiresG1iG1,CATBody * volatile & BodyErr,CATLONG32 & NumDebWireiG1,CATLONG32 & NumFinWireiG1);

  // S9L : Thick Wire - Point Discontinuous Law : Start
  // Split edges at point discontinuity
  void SplitEdgeAtPointDiscontinuity(CATGeoFactory * ipFactory,
                                    CATTopData * ipTopData,
                                    CATLaw * ipCurLaw,
                                    CATBody *& opCutBody);
  // S9L : Thick Wire - Point Discontinuous Law : End

  int TreatOverlappedEdgesInWire(CATWireTopOp* Operateur, CATCGMJournalList* IntJourn, CATBody*& ParallelResu,
    CATLONG32& NumDebWire, CATLONG32& NumFinWire, CATLONG32* DescDeb, CATLONG32* DescFin,
    CATLONG32*& ResuDescDeb, CATLONG32*& ResuDescFin); //D1A Aug 2022 : TMC G1 discontinuity in results

	// Extrapolate the result up to support boundary based on mode to extrapolate 
  void ExtrapolateUpToSupportBoundary(CATCGMJournalList * IntJourn);

  //For managing the throw for complete result for planar support
  int RunInternal();

  //Start - CompleteSolForPlanarSupport methods
  //To check if the solution is incomplete for a planar support
  CATBoolean IsSolIncomplete(CATBody ** TabWiresG1,
                             int nbWiresG1 ,
                             CATSoftwareConfiguration * CurConfig,
                             double offset);

  //For finding relative directions of input and output solution wire
  int RelativeOrientationOfIOWires(CATEdge* inputEdge,
                                   CATEdge* outputEdge,
                                   CATWire* pInputWire,
                                   CATWire* pOutputWire);

  //Journal Modifications for complete result for planar support
  void ProjectionAndJournalModifs( CATCGMJournalList* IntJourn,
                                   CATCGMJournalList* BufferJourn);

  //To fetch data necessary for CATPositionPtLoop
  void GetDomainData(CATDomain*& iDomain,
                     CATPCurve**& ioPCrv,
                     CATCrvParam*& ioStartParam,
                     CATCrvParam*& ioEndParam,
                     int& oNbcells);

  //To find the outermost domain of shell boundary
  int GetLargestDomainIndex(CATBody* iBody);

  //To check if the extrapolated portions of the wire are intersecting shell boundary.
  CATBoolean AreExtrapolsIntersecting(const CATMathPoint & iStrtPtPrev,
                                      const CATMathPoint & iEndPtPrev,
                                      const CATMathPoint & iStrtPtNxt,
                                      const CATMathPoint & iEndPtNxt);

  //This method returns the start and end of the output body depending on the 
  void GetExtremitiyWRTOrientations(CATBody* pParallelBody,
                                    CATCGMJournalList* pProjJourn,
                                    CATCGMJournalList* pParallelJourn,
                                    CATVertex*& pStrtVertex,
                                    CATVertex*& pEndVertex);
  //End - CompleteSolForPlanarSupport methods

  CATBody                 * _TargetBody;
  CATBody                 * _Ref;
  CATExtrapolParallelTool * _CreateAngleTool;
  //CATBody                 * _Curve; // S9L : Parallel Extrapolaiton : Moved to CATTopParalleFreeze
  CATBody                 * _CurveLaid;
  CATLaw                  **_CurveLaidMapLaws;
  //CATBody                 * _Support; // S9L : Parallel Extrapolaiton : Moved to CATTopParalleFreeze
  CATDistanceTool         * _DistTool;
  CATICGMDistanceTool     * _IDistTool;
  int                       _HasBeenRead;
  int                       _NewDistTool;
  int                       _NewExtrapol;
  CATLONG32                 _iNewLaw;
  int                       _IsGivenParTool;//1 if a CATExtrapolParallelTool was a user made one.
  CATBoolean                _CleanWire;
  CATLONG32                 _NbEdgesOfCurveLaid;

  //Cells which should be spared by CleanOutput
  //For Round extrapolation, these are the computed corner-edges. This is done:
  // 1) to have symmetric corners
  // 2) to avoid unnecessary NURBSization of lines neighbouring round corners by CleanCrv (NewParallel_WireShell_Case1_C100::RI305525_C100)
  //For Linear/G1 extrapolation, these are the (sharp) vertices, found as intersection of G1 results.
  CATLISTP(CATCell)       _CellsNotToClean;  // Modified By : SUH : 2004:7:12

  CATBody* volatile _BufferBody;
  CATBody* volatile _PseudoSupport;
  CATBody* _Boundary;
  CATLONG32 _OuterDomainId;
};
#endif

