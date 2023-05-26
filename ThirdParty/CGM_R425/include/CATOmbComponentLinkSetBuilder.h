/**
* @level Private
* @usage U1
*/
#ifndef _CATOmbComponentLinkSetBuilder_H
#define _CATOmbComponentLinkSetBuilder_H

#include "CATOmbLinkTraderForRestrictedAccess.h"
#include "IUnknown.h"
#include "CATListOfCATUnicodeString.h"
#include "CATBoolean.h"
#include "CATOmxOHMap.h"
#include "CATOmbRelationRuleManager.h"
#include "CATOmxAutoPtr.h"
#include "CATOmxArray.h"

class CATComponentId;
class CATOmbComponentLinkSet;
class CATSysSimpleHashTable;
class CATOmbRelationMetaData;

/**
* class managing a set of PLM links
*/
class ExportedByCATOmbLinkTraderForRestrictedAccess CATOmbComponentLinkSetBuilder
{
public:
  static CATOmxAutoPtr<CATOmbComponentLinkSetBuilder> Create(const CATComponentId& cid);
  ~CATOmbComponentLinkSetBuilder();

  CATOmxArray<CATUnicodeString> GetLinkSetIdentifiers() const;

  CATOmbComponentLinkSet& GetLinkSet(const CATUnicodeString & iLinkSetIdentifier);

private:
  CATUnicodeString ComputeLinkSetIdentifier(const CATOmbRelationMetaData& iRMD);
  CATOmbComponentLinkSetBuilder(const CATComponentId& iComId);
  CATOmbComponentLinkSet & LocateOrCreate(const CATUnicodeString & iIdentifier);

  const CATComponentId m_cid;
  CATOmbRelationRuleManager m_ruleManager;
  CATOmxOHMap<CATUnicodeString, CATOmbComponentLinkSet*, CATOmxDefaultCollecManager<CATUnicodeString>::manager, naive_manager> m_sets;
};

#endif
