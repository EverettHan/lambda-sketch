/**
 * @level Private
 * @usage U1
 */
#ifndef CATListValCATOmbPLMRelationshipSemantics_h
#define CATListValCATOmbPLMRelationshipSemantics_h
//===================================================================
// COPYRIGHT Dassault Systemes 2005
//=================================================================== 
// COPYRIGHT DASSAULT SYSTEMES 2005

class CATOmbPLMRelationshipSemantics;

/**
 * @collection CATLISTP(CATOmbPLMRelationshipSemantics)
 * Collection class for Unicode strings.
 */

// Clean previous functions requests
#include  <CATLISTV_Clean.h>
  
// Specify the function to take into account.
#define CATLISTV_Append
#define CATLISTV_RemoveValue
#define CATLISTV_RemovePosition
#define CATLISTP_RemoveAll
#define CATLISTV_Locate
 
// Get macros
#include  <CATLISTV_Declare.h>
  
// Define the NT DLL export macro
#include "CATObjectModelerBase.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATObjectModelerBase
  
// Declare the CATLISTP(CATOmbPLMRelationshipSemantics) type.
#include "CATOmbPLMRelationshipSemantics.h"
CATLISTV_DECLARE( CATOmbPLMRelationshipSemantics )
 
#endif


