#ifndef CATINotificationReactive_H
#define CATINotificationReactive_H


// COPYRIGHT DASSAULT SYSTEMES 2000

#include "JS0FM.h"
#include "CATBaseUnknown.h"
#include "CATCommand.h"
#include "CATNotification.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByJS0FM IID IID_CATINotificationReactive;
#else
extern "C" const IID IID_CATINotificationReactive;
#endif

#define CATAnyCommandClientData (CATCommandClientData) (size_t) 0xdeadbeef

//----------------------------------------------------------------
// Class CATEventSubscriber             
//----------------------------------------------------------------
class ExportedByJS0FM CATINotificationReactive : public CATBaseUnknown
{
 
    CATDeclareInterface;

  public:
/**
 * Sets a callback for a given notification published by a given command.
 * The callback will be called on a given interface
 * @param iPublishingCommand
 *   The CATCommand instance that publishes the notification. 
 * @param iTypeOfEvent
 *   The type of event published by <tt>iPublishingCATCommand</tt>.
 * @param iInterfaceId
 *   The InterfaceId of the interface to use as callback
 * @param iMethodToExecute
 *   The method of the interface <tt>iInterfaceId</d> to execute 
 *   whenever <tt>iPublishingCATCommand</tt> publishes <tt>iTypeOfEvent</tt>.
 * @param iUsefulData
 *   Data to pass to <tt>iMethodToExecute</tt> and that can be useful
 *   to this method.
 */
    virtual CATCallback AddAnalyseNotificationCB(
                            CATCommand *     iPublishingCommand,
	                    const char * iPublishedNotification,
                            const IID &            iInterfaceId,
                       	    CATCommandMethod   iMethodToExecute,
	                    CATCommandClientData    iUsefulData=NULL)=0;
/**
 * Removes a callback set with AddAnalyseNotificationCB  for a given notification 
 * published by a given command.
 * Removes a callback for a given notification published by a given command.
 * @param iPublishingCommand
 *   The CATCommand instance that publishes the notification. 
 * @param iPublishedNotification
 *   The notification published by <tt>iPublishingCATCommand</tt>.
 * @param iInterfaceId
 *   The InterfaceId of the interface to use as callback
 * @param iUsefulData
 *   Data to pass to <tt>iMethodToExecute</tt> and that can be useful
 * to this method.
 */
  virtual  void RemoveAnalyseNotificationCB(
                            CATCommand *     iPublishingCommand,
	                    const char * iPublishedNotification,
                            const IID &            iInterfaceId,
	                    CATCommandClientData    iUsefulData=CATAnyCommandClientData)=0;


};
#endif
