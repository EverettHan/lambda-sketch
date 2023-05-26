#ifndef CATPLMMLPairAliasOrTypeNameObjPos_H
#define CATPLMMLPairAliasOrTypeNameObjPos_H

#include "CATOmxPair.h"
#include "CATOmxKeyString.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATPLMModelerLanguage.h"

typedef CATOmxPair<CATOmxKeyString,int> CATPLMMLPairAliasOrTypeNameObjPos;

template <> ExportedByCATPLMModelerLanguage CATOmxCollecManager&  CATOmxDefaultCollecManager< CATPLMMLPairAliasOrTypeNameObjPos >::manager();

#endif
