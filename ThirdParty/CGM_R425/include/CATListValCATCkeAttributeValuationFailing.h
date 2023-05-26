// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATListValCATCkeAttributeValuationFailing.h
// Header definition of CATListValCATCkeAttributeValuationFailing
//
//===================================================================
//
// Usage notes:
//
//===================================================================
#ifndef CATListOfCATCkeAttributeValuationFailing_h
#define CATListOfCATCkeAttributeValuationFailing_h

/**
 * @collection CATLISTV(CATCkeAttributeValuationFailing)
 * Collection class for attribute failing info
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */

#include "CATLifSpecs.h"

#include "CATCkeAttributeValuationFailing.h"

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

#include "CATLISTV_Declare.h"

#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATLifSpecs

/**
* List of @href CATCkeAttributeValuationFailing .
*/

CATLISTV_DECLARE( CATCkeAttributeValuationFailing );

#endif
