/**
 * @level Protected
 * @usage U1
 */
/* -*-c++-*- */
// CPPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
//  CATIAManageServices :
//  Services for Autosave execution in CATIA context
//
//
//================================================================
//  Usage notes
//   Services for making a autosave file dedicated to a document
//   and that will de self-sufficient in case of restart.
//   In that case, data will need some treatments
//
//
//================================================================
#ifndef CATIAManageServices_H
#define CATIAManageServices_H


#include "AC0CATPL.h"
#include "CATDocument.h"


//----------------------------------------------------------------
//  autosave according to CATIA format
//----------------------------------------------------------------
ExportedByAC0CATPL int RollDoc   (const char* PathName, CATDocument* doc) ;
ExportedByAC0CATPL int UnrollDoc (const char* PathName, CATDocument* doc) ;

//-----------------------------------------------------------------
// current model gestion
//-----------------------------------------------------------------
ExportedByAC0CATPL void* GiveCurrentModel () ;
ExportedByAC0CATPL void  SetCurrentModel  (void* CurrentModel) ;

#endif
