// COPYRIGHT Dassault Systemes 2015
//===================================================================
//
// CATListValUITypeHandler.h
// Header definition of CATListValUITypeHandler
//
//===================================================================
//
// Usage notes:
//
//===================================================================
#ifndef CATListOfUITypeHandler_h
#define CATListOfUITypeHandler_h


/**
 * @collection CATLISTV(UIPackage)
 * Collection class for UIPackage
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */



#include "PLMDictionaryNavServices.h"
#include "UITypeHandler.h"

#include "CATLISTV_Clean.h"

#define	CATLISTV_AppendList
#define	CATLISTV_InsertAt
#define	CATLISTV_ReSize
#define	CATLISTV_Locate
#define	CATLISTV_RemoveValue
#define	CATLISTV_RemovePosition
#define	CATLISTV_Compare
#define	CATLISTV_Replace
#define	CATLISTV_NbOccur
#define	CATLISTV_Intersection
#define	CATLISTV_Apply
#define	CATLISTV_RemoveDuplicatesCount
#define	CATLISTV_QuickSort

#include "CATLISTV_Declare.h"

#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByPLMDictionaryNavServices


CATLISTV_DECLARE( UITypeHandler );

#endif
