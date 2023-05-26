/* -*-C++-*- */

#ifndef CATRibAdvInit_H
#define CATRibAdvInit_H

// COPYRIGHT DASSAULT SYSTEMES 2008

//------------------------------------------------------------------------------
//
// CATRibAdvInit
// Introduced to remove dependancy of CATRibInit on CATBlendParams
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Usage notes:
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Jun. 08    Creation                         SOU
//------------------------------------------------------------------------------

//#include "Ribbon.h"
#include "Fillet.h"
#include "CATRibInit.h"
#include "CATBlendParams.h"

class CATCGMJournalList;
class CATBody;
class CATDomain;
class CATCellHashTable;

#include "CATSafe.h"
CATSafeDefine(CATRibAdvInit);

class ExportedByFillet CATRibAdvInit : public CATRibInit
{
 public:

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  CATRibAdvInit(CATCGMJournalList * iJournal, CATBody * iCreationBody, CATSoftwareConfiguration * iConfig=NULL);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  virtual ~CATRibAdvInit();

  //------------------------------------------------------------------------------
  // Restore data
  //------------------------------------------------------------------------------
  virtual void RestoreSpecificContent(CATCGMJournalList * iEdgesJournal=NULL);

  virtual void SetSkinOptions (CATBlendParams& iparams);
  virtual CATBlendParams * GetSkinOptions ();
  virtual void Update(CATBody * iNewInitialBody, 
                      CATDomain* iNewInitialDomain,
                      CATCGMJournalList * iJournal, 
                      CATCellHashTable * iEdges=NULL,
                      CATCGMJournalList * iJournalOfficiel = NULL);

  virtual CATListOfKeepEdges * GetKeepEdges();
  virtual void GetAllCellsToWatch (ListPOfCATCell &oCellsToWatch, CATBody *iInitialBodyToUse);
  virtual CATBoolean ImplicitKeepEdgesMode();
  virtual CATBoolean EveryKeepEdgeConvexityMode();
  //virtual CATBoolean IsImplicitKeepInitialisationDone();

protected:

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------

  CATBlendParams       _Params;

};

#endif
