
#ifndef CATPLMIDMINORCOLLECTMANAGER_H_
#define CATPLMIDMINORCOLLECTMANAGER_H_

#include "CATPLMIDCollecManager.h"
#include "CATPLMIdentificationAccess.h"

class CATPLMIDMinorCollectManager
{
public:
  /**
   * manager for CATPLMID
   * hashing and comparison is based on majorid only
   */
  ExportedByCATPLMIdentificationAccess static CATOmxCollecManager& manager();
};

#endif /* CATPLMIDMINORCOLLECTMANAGER_H_ */
