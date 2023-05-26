#ifndef CATLISTP_CATEDITOR_PAGE_H
#define CATLISTP_CATEDITOR_PAGE_H
///////////////////////////////////////////////////////////////////////////////
// COPYRIGHT DASSAULT SYSTEMES  2008                                         //
// ========================================================================= //
//                                                                           //
// CATLISTV :                                                                //
//                                                                           //
// Base class for CATLISTP of  CATEditorPage								 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//
// --------------------------------------------------------------------------
//                       Clean previous functions requests
// --------------------------------------------------------------------------
//
#include "CATLISTP_Clean.h"
#include "CATAfrProperties.h"
//
// --------------------------------------------------------------------------
//                           Require needed functions
// --------------------------------------------------------------------------
//
#define  CATLISTP_Append
#define  CATLISTP_ApplyDelete
#define  CATLISTP_Locate
#define  CATLISTP_RemoveValue
#define  CATLISTP_RemovePosition
#define  CATLISTP_RemoveAll
//
// --------------------------------------------------------------------------
//                                  Get macros
// --------------------------------------------------------------------------
//
#include "CATLISTP_Declare.h"
//
// --------------------------------------------------------------------------
//                       Generate interface of collection-class
// --------------------------------------------------------------------------
//

class CATEditorPage;

#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATAfrProperties

CATLISTP_DECLARE( CATEditorPage )

#endif



