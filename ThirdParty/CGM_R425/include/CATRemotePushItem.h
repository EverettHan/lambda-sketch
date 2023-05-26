// COPYRIGHT Dassault Systemes 2004
#ifndef CATRemotePushItem_H
#define CATRemotePushItem_H

#include <CATDlgPushItem.h>
#include <CATCommand.h>
#include <CATString.h>
#include <CATView.h>

/**
 * CATRemotePushItem represents a choice within a contextual menu (CATDlgContextualMenu).  Under
 * normal circumstances, one would use a CATDlgPushItem.  However, in certain specialized
 * circumstances, one must provide callbacks for the menu item from a class that is not in the
 * dialog heirarchy of the CATDlgContextualMenu.  In particular, this can be true when the menu
 * is managed from the controller leg of an MVC architecture.  The CATDlgPushItem's activation
 * notification does not support this.  This class will capture that event and re-fire it, so
 * that the notification may be subrcribed to by AddCallback() instead of
 * AddAnalyseNotificationCB(), which only works within the CATDialog heirarchy.
 **/
class ExportedByCATView CATRemotePushItem: public CATDlgPushItem
{
    CATDeclareClass;
public:
    /**
     * Constructor
     **/
    CATRemotePushItem( CATDialog *iFather, const CATString &iName, int iStyle=0 );
    /**
     * Destructor
     **/
    virtual ~CATRemotePushItem( void );

    void OnPushed( CATCommand *, CATNotification *, CATCommandClientData );

    CATCallback RegisterItemActivatedEvent( CATEventSubscriber *iSubscriber,
                                            CATSubscriberMethod iMethod,
                                            CATSubscriberData iData );

    void UnregisterItemActivatedEvent( CATEventSubscriber *iSubscriber,
                                       CATCallback iActivateCallback );

protected:

private:
   CATDefineCBEvent( MenuItemActivated )

};

#endif
