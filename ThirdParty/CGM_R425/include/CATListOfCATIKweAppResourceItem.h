#ifndef CATListOfCATIKweAppResourceItem_h
#define CATListOfCATIKweAppResourceItem_h

// COPYRIGHT Dassault Systemes 2007

// System framework
#include "CATLISTHand_Clean.h"

// KnowledgeInterfaces framework
#include "CATLifSpecs.h"
#include "CATIKweAppResourceItem.h"

#define CATLISTHand_Append
#define CATLISTHand_AppendList
#define CATLISTHand_Locate
#define CATLISTHand_RemovePosition
#define CATLISTHand_RemoveAll
#define CATLISTHand_QuickSort

// System framework
#include "CATLISTHand_Declare.h"

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATLifSpecs

CATLISTHand_DECLARE(CATIKweAppResourceItem_var)

#undef CATCOLLEC_ExportedBy

typedef CATLISTV(CATIKweAppResourceItem_var) CATListOfCATIKweAppResourceItem;

#endif // CATListOfCATIKweAppResourceItem_h
