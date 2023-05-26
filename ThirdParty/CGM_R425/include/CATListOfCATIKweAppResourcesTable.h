#ifndef CATListOfCATIKweAppResourcesTable_h
#define CATListOfCATIKweAppResourcesTable_h

// COPYRIGHT Dassault Systemes 2007

// System framework
#include "CATLISTHand_Clean.h"

// KnowledgeInterfaces framework
#include "CATLifSpecs.h"
#include "CATIKweAppResourcesTable.h"

#define CATLISTHand_Append
#define CATLISTHand_AppendList
#define CATLISTHand_Locate
#define CATLISTHand_RemoveAll

// System framework
#include "CATLISTHand_Declare.h"

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATLifSpecs

CATLISTHand_DECLARE(CATIKweAppResourcesTable_var)

#undef CATCOLLEC_ExportedBy

typedef CATLISTV(CATIKweAppResourcesTable_var) CATListOfCATIKweAppResourcesTable;

#endif // CATListOfCATIKweAppResourcesTable_h
