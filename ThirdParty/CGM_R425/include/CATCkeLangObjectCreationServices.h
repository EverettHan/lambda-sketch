#ifndef CATCkeLangObjectCreationServices_H
#define CATCkeLangObjectCreationServices_H

#include "CATLifSpecs.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfCATString.h"
class CATIAdpPLMIdentificator;
class CATListPtrCATIAdpPLMIdentificator;
class CATIInstance_var;
class CATOmbLifeCycleRootsBag;
class CATIType_var;
class ExportedByCATLifSpecs CATCkeLangObjectCreationServices
{
public:
	static CATIInstance_var CreatePLMQueryResultObjectOccurrence(CATListPtrCATIAdpPLMIdentificator * iIDs, const CATListOfCATString &iAttrIds, const CATListOfCATUnicodeString &iAttrValues, const CATIType_var &iType, CATOmbLifeCycleRootsBag * iBag);
};
#endif

