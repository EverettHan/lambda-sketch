#ifndef CATIPLMMLDicoNavNodeCollec_H
#define CATIPLMMLDicoNavNodeCollec_H

#include "CATPLMModelerLanguage.h"

#include "CATOmxCollecManager.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxList.h"

class CATIPLMMLDicoNavNode;

template <> ExportedByCATPLMModelerLanguage CATOmxCollecManager & CATOmxDefaultCollecManager < CATOmxList<CATIPLMMLDicoNavNode> >::manager();

#endif

