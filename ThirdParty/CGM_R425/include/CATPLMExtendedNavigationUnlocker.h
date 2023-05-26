#ifndef CATPLMExtendedNavigationUnlocker_H
#define CATPLMExtendedNavigationUnlocker_H

#include "CATPLMIdentificationAccess.h"
#include <stddef.h> // size_t
#include "CATOmxDeprecated.h"

class CATIPLMSpace;


enum CATPLMExtendedNavigationUnlockerMode { Unlock, DoNotUnlock };

/**
 * Normally objects loaded in "light" (no attribute available) or "navigation" (only naming attributes available) mode (@see CATPLMCompletionLevel)
 * are "hidden" (transformed into null pointers) by TOS API and as consequence by PC2/PLMModelerBase API
 *
 * Using a CATPLMExtendedNavigationUnlocker unlocks access to those objects until the CATPLMExtendedNavigationUnlocker instance scope ends.
 *
 * Notice that using CATPLMExtendedNavigationUnlocker unlocks access to everyone called during its lifetime duration
 *
 * Only instanciate this object on the stack.
 */
class ExportedByCATPLMIdentificationAccess CATPLMExtendedNavigationUnlocker
{
public:
  CATPLMExtendedNavigationUnlocker();

  /**
   * deprecated: do or do not unlock access
   * if you do not want to unlock access...do not use this object
   * else use default constructor
   */
  CATPLMExtendedNavigationUnlocker(CATPLMExtendedNavigationUnlockerMode iMode);

  /**
   * restore initial state
   */
  ~CATPLMExtendedNavigationUnlocker();

  OMX_DEPRECATED("broken pattern, use default constructor or do not use this class") inline void UnlockExtendedNavigation() { ++CATPLMExtendedNavigationUnlocker::UnlockersCount; }

private:
  CATPLMExtendedNavigationUnlocker(CATPLMExtendedNavigationUnlocker &) = delete;
  CATPLMExtendedNavigationUnlocker &operator=(CATPLMExtendedNavigationUnlocker &) = delete;

  friend class CATOxEntity;

  static int UnlockersCount;
  const int m_oldUnlockersCount;
};
#endif
