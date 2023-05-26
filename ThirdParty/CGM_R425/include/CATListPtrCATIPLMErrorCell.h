
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES  2003
//=============================================================================
//
// CATListPtrCATIPLMErrorCell
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
//
// FTS
//
//=============================================================================
/**
* @level Protected
* @usage U1
*/

#ifndef CATListPtrCATIPLMErrorCell_H
#define CATListPtrCATIPLMErrorCell_H

#include "CATIPLMErrorCell.h"
#include "CATPLMIntegrationInterfaces.h"
#include <CATLISTP_Clean.h> // Clean previous functions requests

#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATPLMIntegrationInterfaces

// Needed functions
#define CATLISTP_Append
//#define CATLISTP_Locate
//#define CATLISTP_InsertAt
//#define CATLISTP_RemovePosition
#define CATLISTP_RemoveAll

#include <CATLISTP_Declare.h> // Get macros
CATLISTP_DECLARE (CATIPLMErrorCell)


#endif

