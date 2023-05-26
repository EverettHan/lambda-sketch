#ifndef CATLISTV_CATPLMSynchronizationDomains_H
#define CATLISTV_CATPLMSynchronizationDomains_H

#include "CATPLMIdentificationAccess.h"
#include "CATOmxArray.h"
#include "CATOmxDefaultCollecManager.h"

class CATPLMSynchronizationDomainDatas;
template<>
ExportedByCATPLMIdentificationAccess CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMSynchronizationDomainDatas>::manager();

class CATListCATPLMSynchronizationDomainDatas : public CATOmxArray<CATPLMSynchronizationDomainDatas>
{
public:
  inline const CATPLMSynchronizationDomainDatas& operator[](int index) const { return CATOmxArray<CATPLMSynchronizationDomainDatas>::operator[](index); }
  inline       CATPLMSynchronizationDomainDatas& operator[](int index) { return CATOmxArray<CATPLMSynchronizationDomainDatas>::GetW(index); }
};


class CATPLMSynchronizationDomains;
template<>
ExportedByCATPLMIdentificationAccess CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMSynchronizationDomains>::manager();

class CATListCATPLMSynchronizationDomains : public CATOmxArray<CATPLMSynchronizationDomains>
{
public:
  inline const CATPLMSynchronizationDomains& operator[](int index) const { return CATOmxArray<CATPLMSynchronizationDomains>::operator[](index); }
  inline       CATPLMSynchronizationDomains& operator[](int index) { return CATOmxArray<CATPLMSynchronizationDomains>::GetW(index); }
};

#endif

