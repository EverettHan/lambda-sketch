/**
 * @level Protected
 * @usage U1
 */

#ifndef CATLISTV_CATICKETYPE_VAR_H_
#define CATLISTV_CATICKETYPE_VAR_H_

#include "CATICkeType.h"

#include  "CATLISTV_Clean.h"

#define CATLISTV_RemoveValue
 
#include "CATLifDictionary.h"


// --------------------------------------------------------------------------
//                                  Get macros
// --------------------------------------------------------------------------
 
#include "CATLISTV_Declare.h"

// --------------------------------------------------------------------------
//                       Generate interface of collection-class
// --------------------------------------------------------------------------

#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATLifDictionary
  
CATLISTV_DECLARE( CATICkeType_var )
  
#endif
