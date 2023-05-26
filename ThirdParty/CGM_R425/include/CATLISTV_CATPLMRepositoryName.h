#ifndef CATLISTV_CATPLMRepositoryName_H
#define CATLISTV_CATPLMRepositoryName_H
/* -*-c++-*- */

/**
 * @level Private
 * @usage U3
 */
#include "CATPLMIdentificationAccess.h"
#include "CATPLMRepositoryName.h"
#include "CATLISTV_Clean.h"
#include "CATLISTV_Declare.h"

#include "CATOmxArray.h"

template<>
CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMRepositoryName>::manager();

class CATListValCATPLMRepositoryName: public CATOmxArray<CATPLMRepositoryName>
{
public:
  inline CATListValCATPLMRepositoryName() {}
  inline const CATPLMRepositoryName& operator[](int i) const {return CATOmxArray<CATPLMRepositoryName>::operator[](i);}
  inline       CATPLMRepositoryName& operator[](int i)       {return CATOmxArray<CATPLMRepositoryName>::GetW(i);}
  inline void RemoveAll(CATCollec::MemoryHandling iKeepAlloc = CATCollec::ReleaseAllocation) {CATOmxArray<CATPLMRepositoryName>::RemoveAll(iKeepAlloc != CATCollec::ReleaseAllocation);}
};

typedef CATListValCATPLMRepositoryName CATPLMRepositoryNames;


#endif
