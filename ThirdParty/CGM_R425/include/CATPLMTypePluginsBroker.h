#ifndef CATPLMTypePluginsBroker_H
#define CATPLMTypePluginsBroker_H

#include "CATOmxNonNullComPtr.h"
#include "CATOmxSharable.h"
#include "CATOmxIter.h"
#include "CATPLMIdentificationAccess.h"
class CATPLMTypeH;

class CATPLMTypePluginsBrokerInternal : public CATOmxSharable
{
public:
  ExportedByCATPLMIdentificationAccess static CATOmxNonNullComPtr<CATPLMTypePluginsBrokerInternal> Create(const CATMetaClass& iIID);

  virtual CATOmxIter<IUnknown> QueryPlugins(const CATPLMTypeH& type) = 0;
};

template<class IPlugin>
class CATPLMTypePluginsBroker
{
  CATOmxNonNullComPtr<CATPLMTypePluginsBrokerInternal> m_impl;
public:
  CATPLMTypePluginsBroker() :m_impl(CATPLMTypePluginsBrokerInternal::Create(*IPlugin::MetaObject())) {}

  CATOmxIter<IPlugin> QueryPlugins(const CATPLMTypeH& type)
  {
    return iterator_static_cast<IPlugin>(m_impl->QueryPlugins(type));
  }
};

#endif
