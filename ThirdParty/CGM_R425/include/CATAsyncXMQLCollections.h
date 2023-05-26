#ifndef CATAsyncXMQLCollections_H
#define CATAsyncXMQLCollections_H

#include "CATAsyncXMQLTypes.h"
#include "CATPLMQueryFilterEnum.h"

#include "CATOmxArray.h"
#include "CATUnicodeString.h"
#include "CATOmxOHMap.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxClassManager.h"
#include "CATOmxCollecManager.h"
#include "CATOmxOSet.h"
#include "CATUuid.h"
#include "CATA5CsvRow.h"
#include "CATPLMServicesItf.h"
#include "CATPLMOmxCollections.h"

namespace CATAsyncXMQLCollections
{
  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrIterModeToOrderedOSetOfCUSHMap();
};

template <> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager<xMQLRequest::Args>::manager();
template <> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager<xMQLRequest::FileInfo>::manager();
template <> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager<xMQLRequest::BOProxy>::manager();
template <> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmxOSet<CATUuid> >::manager();
template <> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmxPair<int, float> >::manager();
template <> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmxPair<CATOmxOrderedOSet<CATUnicodeString>, bool> >::manager();

typedef CATOmxOHMap <
  xMQLRequest::EType,
  CATUnicodeString,
  CATOmxDefaultCollecManager<int>::manager,
  CATOmxDefaultCollecManager<CATUnicodeString>::manager > CATAsyncXMQLMultiStringMap;

typedef CATOmxOHMap <
  xMQLRequest::EType,
  CATOmxArray<CATUnicodeString>,
  CATOmxDefaultCollecManager<int>::manager,
  CATOmxDefaultCollecManager<CATOmxArray<CATUnicodeString> >::manager > CATAsyncXMQLMultiStringArrayMap;

// bool == 1 <=> All Types in OrderedOSet are IRPC types
// bool == 0 <=> At least 1 type in OrderedOset is an ER type
typedef CATOmxOHMap <
  xMQLRequest::EType,
  CATOmxPair<CATPLMOrderedOSetOfCUS, bool>,
  CATOmxDefaultCollecManager<int>::manager,
  CATOmxDefaultCollecManager<CATOmxPair<CATOmxOrderedOSet<CATUnicodeString>, bool > >::manager > CATAsyncXMQLMultiStringSetBoolPairMap;

typedef CATOmxOHMap <Iterative::Mode, CATPLMOrderedOSetOfCUS, CATOmxDefaultCollecManager<int>::manager, CATPLMOmxCollections::mngrOrderedOSetOfCUS> CATPLMIterModeToOrderedOSetOfCUSHMap;

typedef CATOmxOHMap <
  xMQLRequest::EType,
  CATPLMIterModeToOrderedOSetOfCUSHMap,
  CATOmxDefaultCollecManager<int>::manager, CATAsyncXMQLCollections::mngrIterModeToOrderedOSetOfCUSHMap > CATAsyncXMQLMultiIterModeStringSetHMapHMap;

typedef CATOmxOHMap <
  xMQLRequest::ListId,
  xMQLRequest::UuidList*,
  CATOmxDefaultCollecManager<unsigned int>::manager,
  naive_manager> CATAsyncXMQLUuidListMap;

typedef CATOmxOHMap <
  xMQLRequest::ListId,
  CATOmxOSet<CATUuid>,
  CATOmxDefaultCollecManager<unsigned int>::manager,
  CATOmxDefaultCollecManager<CATOmxOSet<CATUuid> >::manager> CATAsyncXMQLUuidSetMap;

typedef CATOmxArray<xMQLRequest::FileInfo, CATOmxDefaultCollecManager<xMQLRequest::FileInfo>::manager> CATAsyncFileInfoArray;
typedef CATOmxArray<xMQLRequest::BOProxy, CATOmxDefaultCollecManager<xMQLRequest::BOProxy>::manager> CATAsyncBOProxyArray;

typedef CATOmxOMap<CATUnicodeString, CATA5::CsvRow*, CATOmxDefaultCollecManager<CATUnicodeString>::manager, com_manager> CATPLMStringToCATA5CsvRow;

#endif
