#ifndef CATListOfCATIKweAppResourceCriterion_h
#define CATListOfCATIKweAppResourceCriterion_h

// COPYRIGHT Dassault Systemes 2007

// System framework
#include "CATLISTHand_Clean.h"

// KnowledgeInterfaces framework
#include "CATLifSpecs.h"
#include "CATIKweAppResourceCriterion.h"

#define CATLISTHand_Append
#define CATLISTHand_AppendList
#define CATLISTHand_Locate
#define CATLISTHand_RemoveAll

// System framework
#include "CATLISTHand_Declare.h"

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATLifSpecs

CATLISTHand_DECLARE(CATIKweAppResourceCriterion_var)

#undef CATCOLLEC_ExportedBy

typedef CATLISTV(CATIKweAppResourceCriterion_var) CATListOfCATIKweAppResourceCriterion;

#endif // CATListOfCATIKweAppResourceCriterion_h
