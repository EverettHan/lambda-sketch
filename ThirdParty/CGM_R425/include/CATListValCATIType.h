// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATListValCATICkeType.h
// Header definition of CATListValCATICkeType
//
//===================================================================
//
// Usage notes:
//
//===================================================================
#ifndef CATListOfCATIType_h
#define CATListOfCATIType_h


/** 
 * @CAA2Level L1
 * @CAA2Usage U1 
 */


/**
 * @collection CATLISTV(CATIType_var)
 * Collection class for Knowledge types.
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */

#include "CATLifSpecs.h"

#include "CATIType.h"

#include "CATLISTHand_Clean.h"

#include "CATLISTHand_AllFunct.h"

#include "CATLISTHand_Declare.h"

#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATLifSpecs

CATLISTHand_DECLARE( CATIType_var );

#endif


