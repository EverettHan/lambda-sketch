//===================================================================
// COPYRIGHT Microsoft 2012/02/09
//===================================================================


#ifndef CATPLMRepositoryDefCollections_H
#define CATPLMRepositoryDefCollections_H

#include "CATOmxArray.h"
#include "CATPLMIdentificationAccess.h"
#include "CATOmxCollecManager.h"
#include "CATOmxDefaultCollecManager.h"

class RepositoryItemDef;
template<> ExportedByCATPLMIdentificationAccess CATOmxCollecManager& CATOmxDefaultCollecManager<RepositoryItemDef>::manager();
typedef CATOmxArray<RepositoryItemDef> RepositoryItemDef_array;

class RepositoryBranchDef;
template<> ExportedByCATPLMIdentificationAccess CATOmxCollecManager& CATOmxDefaultCollecManager<RepositoryBranchDef>::manager();
typedef CATOmxArray<RepositoryBranchDef> RepositoryBranchDef_array;

class RepositoryCheckoutResult;
template<> ExportedByCATPLMIdentificationAccess CATOmxCollecManager& CATOmxDefaultCollecManager<RepositoryCheckoutResult>::manager();
typedef CATOmxArray<RepositoryCheckoutResult> RepositoryCheckoutResult_array;

class RepositoryCheckinInput;
template<> ExportedByCATPLMIdentificationAccess CATOmxCollecManager& CATOmxDefaultCollecManager<RepositoryCheckinInput>::manager();
typedef CATOmxArray<RepositoryCheckinInput> RepositoryCheckinInput_array;


#endif

