#ifndef CATDBEVENTPUBLISHER_H
#define CATDBEVENTPUBLISHER_H

// COPYRIGHT DASSAULT SYSTEMES 2001

#include "stdlib.h"
#include "CATCallbackManager.h"
/**
 * Specific CallbackManager for database events.
 * <b>Role</b>: declare specific database events.
 * 
 */
class CATDbEventPublisher;

class ExportedByJS0SCBAK CATDbEventPublisher : public CATEventSubscriber
{
  public:
  CATDeclareCBEvent(InvalidDBConnection);
  
  void Dispatch(CATCallbackEvent iEvent,
		CATNotification * iNotification);
  static CATDbEventPublisher * GetDbEventPublisher();
  
  private:
  static CATDbEventPublisher _Publisher;
} ;
#endif
