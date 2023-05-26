/**
 * @level Protected
 * @usage U1
 */
/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1997  
//-----------------------------------------------------------------------------
// ObjectModelerCATIA Global Functions
// 
//-----------------------------------------------------------------------------
// Usage Notes:
//
//
// Global functions for save and operations in CATIA
//-----------------------------------------------------------------------------
// Creation by User lbf - May 97
//-----------------------------------------------------------------------------
#ifndef CATIASaveServices_h
#define CATIASaveServices_h
#include "AC0CATPL.h"
#include "CATBaseUnknown.h"
#include "CATDocument.h"
#include "sequence_CATBaseUnknown.h"
#include "booleanDef.h"
#include "CATVVSUrl.h"
#include "CATBoolean.h"

ExportedByAC0CATPL SEQUENCE(CATBaseUnknown_ptr) GetListCont (CATDocument* doc, boolean ConsiderCompoundCont=TRUE) ;
ExportedByAC0CATPL int PutStreamInCATIA ( CATDocument* doc) ;
ExportedByAC0CATPL int SaveDoc (const char* PathName, CATDocument* doc) ;
int CloseZeroTransaction() ;
int CreateZeroTransaction() ;
int AddDocumentToZeroTransaction(CATDocument* doc) ;



#endif
