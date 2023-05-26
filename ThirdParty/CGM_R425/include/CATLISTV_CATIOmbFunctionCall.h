/**
 * @level Protected
 * @usage U1
 */
/* -*-c++-*- */
#ifndef CATLISTV_CATIOmbFunctionCall_H
#define CATLISTV_CATIOmbFunctionCall_H
//==================================================================
// CATLISTV_CATIOmbFunctionCall.h
//
// FRG 
// COPYRIGHT DASSAULT SYSTEMES 2009
//==================================================================

// Exported by module
#include "CATObjectModelerBase.h"

// Clean previous functions requests
#include "CATLISTV_Clean.h"

// Require needed functions
#define  CATLISTV_Append
#define  CATLISTV_RemoveValue

// Get macros
#include "CATLISTV_Declare.h"

// Generate interface of collection-class
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATObjectModelerBase

CATLISTV_DECLARE( CATIOmbFunctionCall_var )

#endif
