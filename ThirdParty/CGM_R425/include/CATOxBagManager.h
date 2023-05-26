// COPYRIGHT Dassault Systemes 2013
#ifndef CATOxBagManager_H
#define CATOxBagManager_H

#include "ExportedByCATPLMTos.h"
#include "CATPLMID.h"
#include "CATBaseUnknown.h"
#include "CATBooleanDef.h"
#include "CATLISTV_CATComponentId.h"
#include "CATOmxOSet.h"
#include "CATPLMIDSet.h"

class CATPLMIDSet;
class CATProxySpace;
class CATComponentId;
class CATPLMBag;

/**
 * Tentative pour unifier la façon de mettre des Composants dans un BAG.
 * Le but est de remonter aux owners des entrees.
 * Remonte depuis les 3DShapes de 3DPart vers la 3DPart. Cependant, cela ne fonctionnera pas si le composant est en light ou en nav car les attributs necessaires sont manquants.
 * Dans ce cas, le composant sera ignore. C'est a l'appelant de gerer.
 */
class CATOxBagManager
{
public:
  //ODT specific, to be removed
  CATOxBagManager(const CATPLMIDSet & iComponents, const CATProxySpace & iDataspace) { Insert(iComponents.Iterator(), iDataspace); }
  //ODT specific, to be removed
  CATOxBagManager(const CATOmxArray<CATComponentId>& iComponents) { Insert(iComponents); }

  CATOxBagManager() = default;
  ~CATOxBagManager() = default;

  ExportedByCATPLMTos HRESULT Insert(const CATOmxOSet<CATPLMID>& iComponents, const CATProxySpace & iDataspace);
  //warning it does not an actual insertion, previous content is removed...
  HRESULT Insert(const CATOmxArray<CATComponentId>& iComponents)
  {
    _Components = iterator_const_cast(iComponents.ConstIterator());
    return S_OK;
  }

  ExportedByCATPLMTos HRESULT BagComponentSet(CATPLMBag & ioBag);

private:
  CATOmxOSet<CATComponentId> _Components;
};
#endif
