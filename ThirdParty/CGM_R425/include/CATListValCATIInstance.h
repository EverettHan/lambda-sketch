// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATListValCATIInstance.h
// Header definition of CATListValCATIInstance
//
//===================================================================
//
// Usage notes:
//
//===================================================================
#ifndef CATLISTV_CATIInstance_var_H_
#define CATLISTV_CATIInstance_var_H_

/**
 * @collection CATLISTV(CATICkeObject_var)
 * Collection class for Knowledge objects.
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */



#include "CATLifSpecs.h"

#include "CATIInstance.h"

#include "CATLISTHand_Clean.h"

#define  CATLISTHand_Append
#define  CATLISTHand_AppendList
#define  CATLISTHand_InsertAt
#define  CATLISTHand_Locate
#define  CATLISTHand_eqOP
#define  CATLISTHand_neOP
#define  CATLISTHand_RemoveValue
#define  CATLISTHand_RemovePosition
#define  CATLISTHand_RemoveAll
#define  CATLISTHand_RemoveDuplicatesCount
#define  CATLISTHand_ReSize
#define	 CATLISTHand_QuickSort

#include "CATLISTHand_Declare.h"

#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATLifSpecs

CATLISTHand_DECLARE( CATIInstance_var )

#endif



