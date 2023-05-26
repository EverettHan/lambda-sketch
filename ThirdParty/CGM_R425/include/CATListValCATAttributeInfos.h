// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATListValCATAttributeInfos.h
// Header definition of CATListValCATAttributeInfos
//
//===================================================================
//
// Usage notes:
//
//===================================================================
#ifndef CATListOfCATAtributeInfos_h
#define CATListOfCATAtributeInfos_h
/** 
 * @CAA2Level L1
 * @CAA2Usage U1
 */


/**
 * @collection CATLISTV(CATAttributeInfos)
 * Collection class for Knowledge attributes.
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */



#include "CATLifSpecs.h"

#include "CATAttributeInfos.h"

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
#define	CATCOLLEC_ExportedBy	ExportedByCATLifSpecs


CATLISTV_DECLARE( CATAttributeInfos );

#endif
