#ifndef __CATComponentIdPersistencyInformation_H
#define __CATComponentIdPersistencyInformation_H
/**
 * @level Private
 * @usage U1
 */

#include "CATPLMID.h"
#include "CATBoolean.h"

class CATComponentIdPersistencyInformation
{
public:
  CATComponentIdPersistencyInformation(const CATPLMID & iPLMID, CATBoolean iRestoreFromRepository) :_PLMID(iPLMID), _RestoreFromRepository(iRestoreFromRepository) {}
  inline const CATPLMID& GetPLMID() const { return _PLMID; }
  inline CATBoolean RestoreFromRepository() const { return _RestoreFromRepository; }
private:
  CATPLMID _PLMID;
  CATBoolean _RestoreFromRepository;
};

#endif
