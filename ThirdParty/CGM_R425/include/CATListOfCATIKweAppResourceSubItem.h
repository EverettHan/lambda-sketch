#ifndef CATListOfCATIKweAppResourceSubItem_h
#define CATListOfCATIKweAppResourceSubItem_h

// COPYRIGHT Dassault Systemes 2007

// System framework
#include "CATLISTHand_Clean.h"

// KnowledgeInterfaces framework
#include "CATLifSpecs.h"
#include "CATIKweAppResourceSubItem.h"

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

CATLISTHand_DECLARE(CATIKweAppResourceSubItem_var)

#undef CATCOLLEC_ExportedBy

typedef CATLISTV(CATIKweAppResourceSubItem_var) CATListOfCATIKweAppResourceSubItem;

#endif // CATListOfCATIKweAppResourceSubItem_h
