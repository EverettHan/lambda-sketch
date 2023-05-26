#ifndef CATPLMRelationsLoader_H
#define CATPLMRelationsLoader_H

#include "CATBaseUnknown.h"
#include "CATCollec.h"

/**
* @level Private
* @usage U1
*/
#define AuthorizedModule                  999
#define CATPLMTos                         AuthorizedModule
#define TransitionEngine                  AuthorizedModule
#define CATPLMQueryResult                 AuthorizedModule
#define CATPLMTosRefresh                  AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATPLMRelationsLoader for non-infrastructure module
@error
#endif

#undef CATPLMTos
#undef TransitionEngine
#undef CATPLMQueryResult
#undef CATPLMTosRefresh

class CATIPLMRecordRead;
class CATIPLMIntegRecordRead;
class CATPLMSemanticRelation;
class CATComponentId;
class CATPLMPath;

#include "ExportedByCATPLMIdentification.h"
#include "CATBoolean.h"
#include "CATOmxList.h"
#include "CATOmxArray.h"

namespace CATPLMRelationsLoader
{
  HRESULT LoadRelations(const CATComponentId & iCID, const CATOmxArray<CATPLMSemanticRelation>& iSRList);

  HRESULT LoadRelationsFromRecord(const CATComponentId & iCID, CATIPLMRecordRead& iRecordRead);

  ExportedByCATPLMIdentification HRESULT LoadRelationsFromRecord(CATIPLMIntegRecordRead * iRecordRead);

  HRESULT LoadPaths(const CATComponentId& iCID, const CATOmxList<CATPLMPath>& iPaths);
  HRESULT LoadPathsFromRecord(const CATComponentId & iCID, CATIPLMRecordRead& iRecordRead);
};

#endif
