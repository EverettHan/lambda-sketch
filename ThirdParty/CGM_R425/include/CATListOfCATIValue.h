#ifndef CATListOfCATIValue_h
#define CATListOfCATIValue_h

// COPYRIGHT Dassault Systemes 2007

/** 
 * @CAA2Level L1
 * @CAA2Usage U1 
 */


/**
 * @collection CATLISTV(CATIValue_var)
 * Collection class for Knowledge values.
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */


// System framework
#include "CATLISTHand_Clean.h"

// KnowledgeInterfaces framework
#include "CATLifSpecs.h"
#include "CATIValue.h"

#define CATLISTHand_Append
#define CATLISTHand_AppendList
#define CATLISTHand_Locate
#define CATLISTHand_RemoveAll

// System framework
#include "CATLISTHand_Declare.h"

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATLifSpecs

CATLISTHand_DECLARE(CATIValue_var)

#undef CATCOLLEC_ExportedBy

typedef CATLISTV(CATIValue_var) CATListOfCATIValue;

#endif // CATListOfCATIValue_h
