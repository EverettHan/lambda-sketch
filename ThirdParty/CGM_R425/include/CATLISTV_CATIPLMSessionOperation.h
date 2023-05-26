/**
 * @level Protected
 * @usage U1
 */
/* -*-c++-*- */
#ifndef CATLISTV_CATIPLMSessionOperation_H
#define CATLISTV_CATIPLMSessionOperation_H
//==================================================================
// CATLISTV_CATIPLMSessionOperation.h
//
// PBV 
// COPYRIGHT DASSAULT SYSTEMES 2009
//==================================================================

// Exported by module
#include "CATPLMIntegrationInterfaces.h"

// Clean previous functions requests
#include "CATLISTV_Clean.h"

// Require needed functions
#define  CATLISTV_Append
#define  CATLISTV_RemoveValue

// Get macros
#include "CATLISTV_Declare.h"

// Generate interface of collection-class
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATPLMIntegrationInterfaces

CATLISTV_DECLARE( CATIPLMSessionOperation_var )

#endif
