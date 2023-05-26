#ifndef CATExtHybOperatorImp_h_
#define CATExtHybOperatorImp_h_

//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
#include "CATHybDef.h"
#include "CATExtHybOperator.h"
#include "CATHybOperatorImp.h"
#include "CATMathInline.h"
class CATListPtrCATCGMJournal;
class CATCX_AuthorizedAnomaliesForCGMOperator;
class CATTopSmartProjectCx14;


class ExportedByPBELight CATExtHybOperatorImp : public CATExtHybOperator
{
   
   friend class CATTopSmartProjectCx14;

   
protected:
   
   //-------------------------------------------------------------------------------------------------------
   // Constructeur 
   //   iOperateur peut etre NULL,  mais ca doit etre reserver au cas tres particuliers sous constructeur
   //   il faut dans ce cas s'empresser de retablir la definition avec la methode SetOperator
   //-------------------------------------------------------------------------------------------------------
   CATExtHybOperatorImp(CATGeoFactory* iFactory, CATTopData* iData, CATTopOperator * iOperateur = NULL);
   
   
public:
   
   // Destructor
   virtual ~CATExtHybOperatorImp();
   
   // Surcharge du new/delete
   CATCGMNewClassArrayDeclare;
   
   virtual int Run()=0;
   
   virtual CATBody* GetResult(CATCGMJournalList* iJournal);
   virtual CATBody* GetResult();
   
   short GetFreezeMode() const;
   void  SetFreezeMode(short mode=1);
   
   void   SetTolerance(double iTol);
   INLINE double GetTolerance() const;
   virtual void GetParametersForDynFilteringOfAnomalies(CATCX_AuthorizedAnomaliesForCGMOperator *piAuthorizedAnomaliesForCGMOperator);
   
   void  SetCheckReport(short mode=1);
   short GetCheckReport() const;

   void  SetAllCellsReport(short FullReportRequired = 0);
   short GetAllCellsReport() const;

   CATBody* GetWorkingBodyOp() const;                // Access the Working Body
   CATCGMJournalList* GetReport() const;             // Get the topological report

   // CGMReplay Management
   virtual CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
   virtual void WriteInput(CATCGMStream  & ioStream);
   virtual void RequireDefinitionOfInputAndOutputObjects();
   virtual void Dump(CATCGMOutput& os);
   
   // Debug
   short IsDumpActive();
   short IsDumpInputActive();
   short IsDumpLongActive();
   short IsDumpReportActive();
   short IsCheckJournalActive();
   short IsHybCheckActive();  
   short IsHybTimeActive();
  
   CATTopBooleanOperator * GetTopoOperator()   const;  // Get the TopologicalOperator
   CATCGMJournalList     * GetExternalReport() const;     // Get the topological Working report
   CATCGMJournalList     * GetInternalReport() const;     // Get the topological Working report

   void SetInternalReport(CATCGMJournalList * iInternal);
   void SetUserReport(CATCGMJournalList * iInternal);

   /** @nodoc  */
   void SetExternalReportIfUnset();

   /** @nodoc @nocgmitf */
   virtual void WriteNonBodyInputs(CATCGMStream & Str);

   /** @nodoc @nocgmitf */
   virtual void ReadNonBodyInputs(CATCGMStream & Str);

   /** @nodoc @nocgmitf */
   short      IsRunDone() const;
   //ADS21@BEGIN
   virtual void SetInputBody(CATBody * iNewInput, const int i);
   virtual CATBody * GetInputBody(const int i);
   //ADS21@END
protected:

   void                   RemoveWorkingBodyOp();
   void                   RemoveTargetBody();

   void                   EventuallyCallRattrapJournal();
   void                   EventuallyCallRattrapJournal_One(CATBody * iBody, CATCGMJournalList * iJournal);

   void                   FinalTreatmentOnResults(ListPOfCATBody & iBodies, CATListPtrCATCGMJournal & iJournals);
   void                   FinalTreatmentMonoResult(CATBody *& iBody, CATCGMJournalList * iJournal);
   void                   FinalTreatmentOnTargetBody();

   void                   DeclareTargetBodyAsResult();

   virtual CATBody      * GetTheResult(CATCGMJournalList * ioJournal);

   CATBody              * GetTargetBody() const; 
   void                   SetTargetBody(CATBody* NewBody, int iRemove=1);           
   void                   SetWorkingBodyOp(CATBody* NewBody, int iRemove=1);          
   CATTopCheckJournal   * GetReportChecker() const;     
   int                    IsCellsLink(CATCell* Cell1, CATCell* Cell2, CATBody* Body=NULL);
   void                   FindFirstConnexCells(CATLISTP(CATCell)& iCells, CATLISTP(CATCell)& ConnexCells, CATBody* Body=NULL);
   
   void       SetRunDone(short status=1);
   CATVertex* MakeIsolateVertex(CATBody* bodyforcellcreation, CATPoint* point); 
   CATEdge*   MakeIsolateEdge(CATBody* bodyforcellcreation, CATCurve* curve, CATCrvLimits* limits=NULL); 
   CATVertex* TryToMergeVertices(CATVertex* Vx, CATCell* Cell);
   CATVertex* TryToMergeVertices(CATVertex* Vx1, CATVertex* Vx2);
   
   short IsCellToReport(CATCell* iCell, CATBody* iBody);

   void HybOpeReport(CATCGMJournal::Type    iType,
                     CATCell*               iBeforeObjects,
                     CATCell*               iAfterObjects=NULL,
                     CATCGMJournalInfo*     iOptionalInfo=NULL,
                     CATBody*               iBody=NULL); 

   void ReportCreationOnDomain(CATDomain*   iDomain, CATBody* iBody=NULL);
   void ReportKeepOnDomain(CATDomain*   iDomain, CATBody* iBody=NULL);
   void ReportDeletionOnDomain(CATDomain*   iDomain, CATBody* iBody=NULL);
   void ReportCreationOnDomainBoundary(CATDomain*   iDomain, CATBody* iBody=NULL);
   void ReportKeepOnDomainBoundary(CATDomain*   iDomain, CATBody* iBody=NULL);
   void ReportDeletionOnDomainBoundary(CATDomain*   iDomain, CATBody* iBody=NULL);
   void ReportCreationOnElem(CATCell* cellBefore, CATCell* cellAfter, CATBody* iBody=NULL);
   void ReportKeepOnElem(CATCell* cell, CATBody* iBody=NULL);
   void ReportDeletionOnElem(CATCell* cell, CATBody* iBody=NULL);
   void ComputeBoundaryOnJournal(CATCGMJournal::Type iType,CATDomain* iDomain, CATBody* iBody=NULL);
   
   virtual void SetInputsToReportChecker();

   virtual void FinalizeOutput(CATBody * iOutputBody);
   virtual void RattrapJournal(CATCGMJournalList * ioJournal, CATBody * body, CATLISTP(CATBody) & InputBodies);

  INLINE void SetNoRattrapJournalInGetResult();
  INLINE CATBoolean NoRattrapJournalInGetResult();

  INLINE void SetNoFinalizeOutputInGetResult();
  INLINE CATBoolean NoFinalizeOutputInGetResult();

  void EventuallyCheckTheReport();
   
   static int IsRunningInOdt();
   
   // Data
   CATTopBooleanOperator*   _TopOper;         // the TopologicalOperator services ...
   CATBody*                 _TargetBody;      // the target Docking Body
   CATCGMJournalList*       _ExternalReport;  // the topological External report (comming from oper)
   CATCGMJournalList*       _InternalReport;  // the topological Internal report (for internal use)
   CATTopCheckJournal*      _ReportChecker;   // the report Checker
   double                   _Tolerance;       // the resolution ...
   short                    _RunDone;         // Run management 
   short                    _CheckReportmode; // Check Report Management
   short                    _AllCellsReport;  // 1 if we Need a full report (All cells are reporting)
                                              // else 0
   short                    _ReportEmbedded;  // For InternalReport Desallocation
                                              //    0 at beginning, 
                                              //    1 when InternalReport is embedded in _ExternalReport
	 CATBoolean               _InsertJournalAttheEndOfRun;

   // Variables de pilotage du debug
   short                    _WithInputDump;
   short                    _WithDump;
   short                    _WithLongDump;
   short                    _WithReportDump;
   short                    _WithReportCheck;
   short                    _WithHybCheck;
   short                    _WithHybTime;
  
private :

   CATBody*                 _WorkingBodyOp;   // the working Body
   CATBoolean               _NoRattrapJournalInGetResult;
   CATBoolean               _NoFinalizeOutputInGetResult;

   CATCGMJournalList*       _UserReport;      // DEPRECATED ! ! ! ! ! ! ! !

   CATBoolean               _ExternalReportFilled;
  
};

INLINE void CATExtHybOperatorImp::SetNoRattrapJournalInGetResult()
{
   _NoRattrapJournalInGetResult = TRUE;   
}

INLINE CATBoolean CATExtHybOperatorImp::NoRattrapJournalInGetResult()
{
   return _NoRattrapJournalInGetResult;   
}

INLINE void CATExtHybOperatorImp::SetNoFinalizeOutputInGetResult()
{
   _NoFinalizeOutputInGetResult = TRUE;   
}

INLINE CATBoolean CATExtHybOperatorImp::NoFinalizeOutputInGetResult()
{
   return _NoFinalizeOutputInGetResult;   
}

INLINE double CATExtHybOperatorImp::GetTolerance() const
{
  return _Tolerance;
}

#endif
