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
// Global functions for load and operations in CATIA
//-----------------------------------------------------------------------------
// Creation by User pgc - Juin 97
//-----------------------------------------------------------------------------
#ifndef CATIALoadServices_h
#define CATIALoadServices_h

/*******************************************
 * THIS CODE MUST BE THE SAME IN V5 AND V6 *
 *     PLEASE REPORT MODIFICATIONS         *
 *******************************************/

#include "AC0CATPL.h"
#include "CATIContainer.h"
#include "CATIAModel.h"
#include "CATDocument.h"

#ifndef CATIAR212
ExportedByAC0CATPL int LoadDoc (const char* PathName, CATDocument* doc) ;
ExportedByAC0CATPL CATDocument*  GetDoc( CATILinkableObject_var & Link);
#else
inline CATDocument* GetDoc( CATILinkableObject_var & Link) {return NULL;}
#endif




#endif



