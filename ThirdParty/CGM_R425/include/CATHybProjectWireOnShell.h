/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1999
//------------------------------------------------------------------------------
//      
// class for Hybrid Projection Wire On Shell
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
//
#ifndef CATHybProjectWireOnShell_h
#define CATHybProjectWireOnShell_h

#include "CATHybProject.h"
#include "CATExtHybProject.h"
//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
#include "CATString.h"
#include "CATMathDef.h"

#include "ListPOfCATDomain.h"  // QPY

class CATCGMJournal;
class CATProjectionCrvSur;
class CATMapX;

class ExportedByPBELight CATHybProjectWireOnShell : public CATExtHybProject
{
public :
   
   //  Constructor
   CATHybProjectWireOnShell(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBody1, CATBody* iBody2, CATMathDirection* iDir);	
   
   // Surcharge du new/delete
   CATCGMNewClassArrayDeclare;

   //  Destructor
   ~CATHybProjectWireOnShell();
   
   //  Methods
   int Run();                               // Execution of the operator
   
   virtual CATBody* GetResult(CATCGMJournalList* iJournal);

  /** @nodoc CATCGMReplay ...*/
   static const CATString * GetDefaultOperatorId() { return & _OperatorId; };
 
   virtual CATLONG32 SetSimplifyTool(CATSimplifyParallelTool * iCurSimplif);	// QPY
   void SetTrapError(CATLONG32 iTrap);	
   
protected :
   
  /** @nodoc CATCGMReplay ...*/
  const CATString * GetOperatorId() const;
  
  /** @nodoc CATCGMReplay ...*/
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
  
  /** @nodoc CATCGMReplay ...*/
  int RunOperator();

  int RunNewLayDownOperator();

   int ComputeProjection(CATWire* Wire, CATShell* Shell);
   int ComputeProjection(CATWire * iWire, CATEdge* iEdge, CATFace* iFace);
   
   // Trim the geometrical result according to the topology
   int TopologicalTrimming(CATWire        * iWire, 
                           CATEdge        * iEdge, 
                           CATFace        * iFace, 
                           CATPCurve      * iPCurve, 
                           CATMapX        * iMapping, 
                           CATOrientation   iPCurveVsEdgeCurveToProject,
                           CATCrvLimits   * iLimits);
   int TopologicalTrimming(CATWire           * iWire,
                           CATEdge           * iEdge,
                           CATFace           * iFace,
                           CATPointOnSurface * iPtOnSur,
                           int                 iSolutionIsDegenerated);
   
   /**
   * The method to call.
   *   @param CurrentBody
   *     Input and output argument.
   *     Initially, it is the result of the projection of the input wire onto the input surface.
   *     In the end, its two sides have been extrapolated until the the input surface's boundary and it becomes the final result.
   *   @param Journal
   *     Input and output argument.
   *     The topological journal.
   */
   CATBoolean BuildExtrapolation(CATBody *& CurrentBody, CATCGMJournalList *Journal);

   // stabilisation de l'orientation du Body resultat
   int StabilizeOrientation(CATBody* aBodyToStabilize, CATBody* StabilizedBody);
   int CheckWireOrientation(CATWire* WireToCheck, CATWire* WireReference);
   
   // stabilisation du point de fermeture des wires
   int StabilizeWireClosure(CATWire* WireToCheck, CATWire* WireReference);
   CATVertex* GetClosingVertex(CATWire* Wire);
   CATVertex* MatchVertexOnWire(CATVertex* v, CATWire* wire);
   int MatchVertices(CATVertex* v1, CATVertex* v2);

   // calcul de la distance entre l'edge a projeter et son resultat
   double ComputeDistance(CATEdge* Edge, CATPCurve* PCurve);
   
   void MakeReport();
   void MakeVertexReport(CATBody* targetBody, CATVertex* Vx_to_report, CATEdge* Edge, int start_or_end);
   int  IsVerticesMatchByProject(CATVertex* Vx_to_Project, CATVertex* Vx_Candidate_Result);
   int  IsVerticesMatchByProject2(CATVertex* Vx_to_Project, CATVertex* Vx_Candidate_Result, CATEdge* adjacent_edge_Result);
//   int  IsVerticesMatchByLine(CATVertex* Vx_to_Project, CATVertex* Vx_Candidate_Result, CATEdge* adjacent_edge_Result);

	CATBody * Clean3DInputWire(CATBody * iBodyToClean, CATBody * iBodySupport, double iTolerance, double iAngleTol, 
								double * iCR, double &oMaxReachedDeformation, CATCGMJournalList * oJournal);		// QPY
  CATBody * ContinuousInputWire(CATBody* iBodyToClean, CATBody* iBodySupport, CATCGMJournalList* oJournal);
  int       ToBeContinuous(CATWire * iOneWire, CATBody* iBodyToClean, CATBody* iBodySupport);
	void      CleanOutputWire(CATBody * iBodyToClean, CATBody * iBodySupport, double iTolerance, double iAngleTol, 
								double * iCR, double &oMaxReachedDeformation, CATCGMJournalList * oJournal);		// QPY

	void SetCleanParameters(double & iAngleTol, double * iCR);  // QPY
	void FindCellsToFix(CATBody * iBodyToClean, CATBody * iBodySupport,	CATLISTP(CATCell) & oCellsLyingOnSupport);  // QPY
	void FindVertexToFix(CATLISTP (CATBody) & iBodyWireList, CATLISTP(CATCell) & oVertexToFix);		// QPY
	void SplitBodyToClean(CATBody * iBodyToClean, CATLISTP(CATBody) & oBodyWireToClean, CATLISTP(CATDomain) & oDomainNotToClean);	// QPY
	void SplitBodySupport(CATBody * iBodySupport, CATLISTP (CATDomain) & oShellsSupport);  // QPY
	int FindBodySupport(CATBody * iBodyWireToClean, CATLISTP(CATDomain) & iShellsSupport, CATBody * oBodySupportClean);  // QPY
	void UpdateDistanceTab(CATCGMJournalList * iInputCleaningJournal, CATCGMJournalList * iOutputCleaningJournal);  // QPY
  
  virtual void RattrapJournal(CATCGMJournalList * ioJournal, CATBody *body, CATLISTP(CATBody)& InputBodies);


   // Datas
   CATEdge*                  _EdgeToProject; // the current cell to project
   CATFace*                    _FaceSupport; // the current cell support
   CATCurve*                _CurveToProject; // the geometry to project
   CATSurface*              _SurfaceSupport; // the geometry support
   CATProjectionCrvSur* _GeomCrvSurOperator; // the Geometrical curve/surface Projection Operator
 
   CATSimplifyParallelTool*   _CurSimplTool;    // QPY
   CATLONG32                  _TrapError;    // JHN

private:
    void ProjectWireOnShellPosage(CATTopData* iTopData, CATLONG32 iSmooth);
    void ProjectWireOnShell(CATTopData* iTopData, CATLONG32 iSmooth);
    void ProjectWireOnShellOld(CATTopData* iTopData);

    //void HandleThrow();


	static CATString _OperatorId;  
};
#endif
