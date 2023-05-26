#ifndef PERFO_STEP_H
#define PERFO_STEP_H
#include "CATUnicodeString.h"
#include "CATSysBoolean.h"
#include "CATLib.h"
#include "CATObjectModelerBase.h"

ExportedByCATObjectModelerBase float GetUsedMemoryMo();

class ExportedByCATObjectModelerBase PerfoStep
{
  CATUnicodeString m_stepName;
  float m_usedMemoryMo;
  CATBoolean m_monitored;
  CATTimerId m_timerId;
public:
  PerfoStep(const char* iName, CATBoolean iMonitored = TRUE);
  ~PerfoStep();
};

#endif //PERFO_STEP_H

