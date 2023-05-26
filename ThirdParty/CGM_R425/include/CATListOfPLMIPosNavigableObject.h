// (C) Copyright Dassault Systemes - 2005
// -----------------------------------------------------------------------
// Interface declaration: CATListOfPLMIPosNavigableObject
// -----------------------------------------------------------------------
// Creation: 2005-12-12
// -----------------------------------------------------------------------
/**
 * @level Protected
 * @usage U1
 */

#ifndef _CATListOfPLMIPosNavigableObject_H_
#define _CATListOfPLMIPosNavigableObject_H_

#include "PLMIPosNavigableObject.h"
#include "ExportedByGUIDPLMPosBaseInterfaces.h"

#include "CATLISTV_Clean.h"
#define CATLISTV_Append
#define CATLISTV_Locate
#define CATLISTV_RemoveValue
#define CATLISTV_RemovePosition
#include "CATLISTV_Declare.h"
#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByGUIDPLMPosBaseInterfaces

CATLISTV_DECLARE( PLMIPosNavigableObject_var )

#undef  CATCOLLEC_ExportedBy


#endif
