#ifndef RattrapJournalModeBoth_H
#define RattrapJournalModeBoth_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#ifdef _STATIC_SOURCE
#define	ExportedByBOIMPOPE
#elif defined(__BOIMPOPE)
#define ExportedByBOIMPOPE DSYExport
#else
#define ExportedByBOIMPOPE DSYImport
#endif
#include "DSYExport.h"

class CATCGMJournalList;
class CATListPtrCATGeometry;

ExportedByBOIMPOPE void RattrapJournalModeBoth ( CATCGMJournalList * iJournal                       , 
                                                 const int           iForgetConstructionObjects = 1 ,
                                                 const int           iFilter_Info0_ForEdges     = 0 ,
                                                 const int           iKeepLateralEdges          = 0 ,
                                                 const int           iRetainAndRestoreInfo      = 0 ,
                                                 const int           iProfileMaxDim             = 2);

ExportedByBOIMPOPE void ExtractObjectsWithInfo(CATCGMJournalList* journal, 
                                               CATListPtrCATGeometry &cellswithinfo1, 
                                               CATListPtrCATGeometry &cellswithinfo2);

#include "TopologicalOperatorsCommonDec.h"

#endif
