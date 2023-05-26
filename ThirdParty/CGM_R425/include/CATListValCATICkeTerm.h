// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATListValCATICkeTerm.h
// Header definition of CATListValCATICkeTerm
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
#ifndef CATLISTV_CATICkeTerm_var_H_
#define CATLISTV_CATICkeTerm_var_H_

// COPYRIGHT DASSAULT SYSTEMES 2007


#include "CATLifSpecs.h"

#include "CATICkeTerm.h"

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

CATLISTHand_DECLARE(CATICkeTerm_var)

#endif


