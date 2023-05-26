// (C) Copyright Dassault Systemes - 2005
// -----------------------------------------------------------------------
// Interface declaration: CATListOfPLMPosAny
// -----------------------------------------------------------------------
// 05:12:12 creation
// -----------------------------------------------------------------------
/**
 * @level Protected
 * @usage U1
 */

#ifndef _CATListOfPLMPosAny_H_
#define _CATListOfPLMPosAny_H_

//#ifndef _PLMPosAny_h
//#include "PLMPosAny.h"
//#endif
#include "ExportedByGUIDPLMPosBaseInterfaces.h"

#include "CATLISTV_Clean.h"
#define CATLISTV_Append
#define CATLISTV_Locate
#define CATLISTV_RemoveValue
#define CATLISTV_RemovePosition
#include "CATLISTV_Declare.h"
#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByGUIDPLMPosBaseInterfaces

CATLISTV_DECLARE( PLMPosAny )
typedef class CATLISTV( PLMPosAny ) CATListOfPLMPosAny;

#undef  CATCOLLEC_ExportedBy

//#include "CATListOfPLMIPosNavigableObject.h"

/** @nodoc */
/*
class CATListOfPLMIPosNavigableObject;
*/

/** @nodoc */
/*
ExportedByGUIDPLMPosBaseInterfaces 
HRESULT operator << (CATListOfPLMPosAny &oList, const CATListOfPLMIPosNavigableObject &iListObj);
*/

/** @nodoc */
/*
ExportedByGUIDPLMPosBaseInterfaces 
HRESULT operator >> (const CATListOfPLMPosAny &iList, CATListOfPLMIPosNavigableObject &oListObj);
*/

#endif
