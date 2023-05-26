/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
#ifndef CATLISTV_CATIConvertEntity_H
#define CATLISTV_CATIConvertEntity_H
//==================================================================
// CATLISTV_CATIConvertEntity.h
//
// Frederic GEFFRELOT  -  MCAD/MCD/CMF 
// COPYRIGHT DASSAULT SYSTEMES 1999
//==================================================================

// Exported by module
#include "AD0XXBAS.h"

// Clean previous functions requests
#include "CATLISTV_Clean.h"

// Require needed functions
#define  CATLISTV_Append
#define  CATLISTV_RemoveValue

// Get macros
#include "CATLISTV_Declare.h"

// Generate interface of collection-class
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByAD0XXBAS

CATLISTV_DECLARE( CATIConvertEntity_var )

#endif
