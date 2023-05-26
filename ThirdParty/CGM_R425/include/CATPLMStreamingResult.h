#ifndef _CATPLMStreamingResult_H
#define _CATPLMStreamingResult_H

// COPYRIGHT DASSAULT SYSTEMES 2009
/**
* @level Private
* @usage U1
*/

#include "CATLISTV_CATPLMStreamDefinition.h"

class CATPLMStreamingResult
{
public:
  CATListValCATPLMStreamDefinition m_SDsToStream, m_SDsToDelete;

  void RegisterStreamed(const CATPLMStreamDefinition& iSD) { m_SDsToStream.Append(iSD); }

  void RegisterToDelete(const CATPLMStreamDefinition & iSD) { m_SDsToDelete.Append(iSD); }
};

#endif
