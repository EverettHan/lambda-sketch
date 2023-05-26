#ifndef CATIPLMSessionManagerListener_H
#define CATIPLMSessionManagerListener_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Private
 * @usage U3
 */

#include "CATOmxSharable.h"
#include "ExportedByCATPLMIdentification.h"

class CATComponentId;

/**
 * Inform PLMModelerBase that the session has been modified
 * Must be implemented by PLMModelerBase and noone else
 * Must be called by CATPLMIdentification and noone else
 */
class CATIPLMSessionManagerListener : public CATOmxSharable
{
public:
  enum TargettedOperation { ToLoad, ToUnload, ToReplace, ToDelete, ToCreate };

  enum CommittedOperation { Loaded = ToLoad, Unloaded = ToUnload, Replaced = ToReplace, Deleted = ToDelete, Created = ToCreate };

  virtual void StartingNotificationsBeforeModelAlterations() = 0;

  virtual void NotificationBeforeModelAlterations(TargettedOperation iTargettedOperation, const CATComponentId & iComponent) = 0;

  virtual void EndingNotificationsBeforeModelAlterations() = 0;

  virtual void StartingNotificationsAfterModelAlterations() = 0;

  virtual void NotificationAfterModelAlterations(CommittedOperation iCommittedOperation, const CATComponentId & iComponent) = 0;

  virtual void EndingNotificationsAfterModelAlterations() = 0;

  typedef CATIPLMSessionManagerListener* (*FactoryT)();
  static ExportedByCATPLMIdentification FactoryT Factory;
};

#endif
