/**
* @level Private
* @usage U1
*/
#ifndef _CATOmbComponentLinkSet_H
#define _CATOmbComponentLinkSet_H

#include "IUnknown.h"
#include "CATUnicodeString.h"
#include "CATOmxArray.h"
#include "CATOmxList.h"
#include "CATOmbLinkTraderForRestrictedAccess.h"

class CATOmbRelationMetaData;
class CATOmbLink;
class CATOmbRelationInterface;
class CATDocument;
class CATOmbLinkSet;

/**
* class restoring PLM link
*/
class CATOmbComponentLinkSet
{
public:
  inline const CATUnicodeString& GetIdentifier() const { return m_id; }

  ExportedByCATOmbLinkTraderForRestrictedAccess HRESULT RestoreLinks(CATDocument& iDocument, CATOmbLinkSet*& oLinkSet);

  //not inline and not exported => cannot be used outside omb
  CATOmbComponentLinkSet(const CATUnicodeString& iIdentifier);
  ~CATOmbComponentLinkSet();
private:
  /* forbidden operations */
  CATOmbComponentLinkSet(CATOmbComponentLinkSet&);
  CATOmbComponentLinkSet& operator=(CATOmbComponentLinkSet&);

  const CATUnicodeString m_id;
  CATOmxList<CATOmbRelationInterface> m_relations;

  friend class CATOmbComponentLinkSetBuilder;
};

#endif
