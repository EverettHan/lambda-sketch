/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1997
//------------------------------------------------------------------------------
//      
// CATHybDocker : used to store Hybrid Operators data
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
//
#ifndef CATHybDocker_h
#define CATHybDocker_h

#include "HybOper.h"
//------------------------------------------------------------------------------
#include "CATHybDef.h"
#include "CATCGMJournal.h"

#include "ListPOfCATDomain.h"
#include "ListPOfCATCell.h"

class ExportedByHybOper CATHybDocker
{
public:
  //  Constructor
  CATHybDocker(CATGeoFactory* GeoFactory, 
	       CATBody* target=NULL, 
	       CATCGMJournalList* report=NULL);	

  //  Destructor
  ~CATHybDocker();     

  //  Methods 
  CATGeoFactory* GetFactory() const;                // Get the factory
  CATTopologicalOperator* GetTopoOperator() const;  // Get the TopologicalOperator
  CATBody* GetTargetBody() const;                   // Get the Target Body
  CATBody* GetWorkingBody() const;                  // Get the Working Body
  CATCGMJournalList* GetReport() const;             // Get the topological report
  CATCGMJournalList* GetExternalReport() const;     // Get the External report

  void SetReport(CATCGMJournalList* NewReport, int iRemove=1);           
  void SetTargetBody(CATBody* NewBody, int iRemove=1);           
  void SetWorkingBody(CATBody* NewBody, int iRemove=1);          

  // Manage working tolerance
  void SetTolerance(double);
  double GetTolerance()const;
  
  // Give information to Topological Report
  void Report(CATCGMJournal::Type    iType,
	      const CATGeometry*     iBeforeObjects,
	      const CATGeometry*     iAfterObjects=NULL,
	      CATCGMJournalInfo*     iOptionalInfo=NULL); 
 
  void ReportKeepOnDomain(CATDomain*   iDomain);
  void ReportDeletionOnDomain(CATDomain*   iDomain);
  void ReportCreationOnDomainBoundary(CATDomain*   iDomain);
  void ReportKeepOnDomainBoundary(CATDomain*   iDomain);
  void ReportDeletionOnDomainBoundary(CATDomain*   iDomain);
  void ReportCreationOnElem(CATGeometry* geomBefore, CATGeometry* geomAfter);
  void ReportKeepOnElem(CATGeometry* geom);
  void ReportDeletionOnElem(CATGeometry* geom);

  
  // Add cells in target body
  void AddCells(int nbCells, CATCell** cellsToAdd); 
  
  // Debug Tools
  CATHybDebug* GetHybDebug(); 
  void SetHybDebug(CATHybDebug* aDebug); 
  CATCGMActivateDebug* GetActivateDebug(); 

  void KeepReferenceElem(CATCell* ReferenceCell1, CATCell* ReferenceCell2, CATCell* ReferenceCell3=NULL);

  ListPOfCATCell* GetVertexList() const;
  ListPOfCATCell* GetEdgeList() const;
  ListPOfCATCell* GetFaceList() const;
  
  ListPOfCATCell* GetReferenceCellsFirstList() const;
  ListPOfCATCell* GetReferenceCellsSecondList() const;
  ListPOfCATCell* GetReferenceCellsThirdList() const;
  
  CATGeometry* VisuElement(CATGeometry* ElemToVisualize, int iRed=15, int iGreen=0, int iBlue=0); 

  CATBody* VisuElementInBody(CATBody* ElemToVisualize, int iRed=15, int iGreen=0, int iBlue=0); 
  CATBody* VisuElementInBody(CATDomain* ElemToVisualize, int iRed=15, int iGreen=0, int iBlue=0); 
  CATBody* VisuElementInBody(CATCell* ElemToVisualize, int iRed=15, int iGreen=0, int iBlue=0); 

protected:
  double		 _tolerance;
  CATGeoFactory*        _geoFactory;	// the current Geometrical factory
  CATTopologicalOperator*  _topOper;	// the TopologicalOperator services ...
  CATBody*              _targetBody;	// the target Docking Body
  CATBody*             _workingBody;	// the working Body
  CATCGMJournalList*  _ExternalReport;  // the topological External report (comming from oper)
  CATCGMJournalList*  _InternalReport;  // the topological Internal report (for internal use)
//  CATCGMJournalList*        _report;    // the topological report
  
  // des listes de cellules en association pour des correspondances rapides
  ListPOfCATCell*      _VertexList;
  ListPOfCATCell*      _EdgeList;
  ListPOfCATCell*      _FaceList;
  
  // des listes de cellules en association pour des correspondances rapides
  ListPOfCATCell*      _ReferenceCells1;
  ListPOfCATCell*      _ReferenceCells2;
  ListPOfCATCell*      _ReferenceCells3;

private:
  void ComputeBoundaryOnJournal(CATCGMJournal::Type iType,CATDomain* iDomain);
  
//  CATDomain*		_domains[3];	// used to store faces/edges/vertices
};
#endif










