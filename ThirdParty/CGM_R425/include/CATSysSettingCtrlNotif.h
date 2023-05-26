#ifndef CATSysSettingCtrlNotif_H
#define CATSysSettingCtrlNotif_H

// COPYRIGHT DASSAULT SYSTEMES 2003


#include "JS0SETT.h"
#include "CATEventSubscriber.h"
#include "CATCallbackManager.h"

class CATSettingInfo;

/**
 * Notification sent by a setting controller.
 * <br><b>Role</b>: Objects of this class convey information about the 
 * modifications that have been occurred inside a setting controller which 
 * send an event when it is commited, saved, reseted.
*/
class ExportedByJS0SETT CATSysSettingCtrlNotif : public CATNotification
{
  CATDeclareClass;
  
public:
  CATSysSettingCtrlNotif();
/**
 * Creates a notification. 
 * @param iEvent [in]
 * the event as defined in @href CATSysSettingController#CATDeclareCBEvent
 * @param iInfo [in]
 * the @href CATSettingInfo associated with a given parameter for the event
 * Param_Updated
 */
  CATSysSettingCtrlNotif ( CATCallbackEvent iEvent, CATSettingInfo *iInfo);
  virtual ~CATSysSettingCtrlNotif();

/**
 * The dispatched event.
*/
  CATCallbackEvent *_Evenement;
/**
 * The CATSettingInfo structure of the controller's parameter that is
 * dispatching an event. It is null for the global event concerning
 * the whole controller.
*/
  CATSettingInfo *_Info;
};

#endif





