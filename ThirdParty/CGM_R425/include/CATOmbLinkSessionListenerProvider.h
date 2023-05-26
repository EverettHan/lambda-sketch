#ifndef CATOmbLinkSessionListenerProvider_H
#define CATOmbLinkSessionListenerProvider_H

#include "CATObjectModelerBase.h"
#include "CATIOmbLinkSessionListener.h"
#include "CATOmxIter.h"

class CATOmbLinkSessionListenerProvider
{
public:
  static CATOmxIter<CATIOmbLinkSessionListener> GetListeners();
  ExportedByCATObjectModelerBase static void Add(CATIOmbLinkSessionListener * iLinkSessionListerner);
};

#endif
