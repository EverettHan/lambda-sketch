#ifndef CATCAfrMePreferencesNotificationManager_H
#define CATCAfrMePreferencesNotificationManager_H

// COPYRIGHT DASSAULT SYSTEMES 1999


#include "CATAfrProperties.h"
#include "CATCommand.h"
#include "CATCallbackManager.h"

void DestroyManager();
class  ExportedByCATAfrProperties CATCAfrMePreferencesNotificationManager: public CATCommand
{


public:

  /**
  * Event sent when the Me-Preference OK button pressed.
  * <br><b>Role:</b><br>this event is sent by the CATCAfrMePreferencesNotificationManager.
  * <br>Sample of callback:
  * <pre>
  * ::AddCallback(this,
  *              CATCAfrMePreferencesNotificationManager::GetPreferencesNotificationManager(),
  *	           CATCAfrMePreferencesNotificationManager::SETTINGS_SAVED(),
  *	           (CATSubscriberMethod)&MyClass::MyCBMethod,
  *	           NULL);
  * </pre>
  */
  CATDeclareCBEvent(SETTINGS_SAVED);

    /**
  * Event sent when the Me-Preference Apply button pressed.
  * <br><b>Role:</b><br>this event is sent by the CATCAfrMePreferencesNotificationManager.
  * <br>Sample of callback:
  * <pre>
  * ::AddCallback(this,
  *              CATCAfrMePreferencesNotificationManager::GetPreferencesNotificationManager(),
  *	           CATCAfrMePreferencesNotificationManager::SETTINGS_APPLIED(),
  *	           (CATSubscriberMethod)&MyClass::MyCBMethod,
  *	           NULL);
  * </pre>
  */
  CATDeclareCBEvent(SETTINGS_APPLIED);

    /**
  * Event sent when the Me-Preference Cancel button pressed.
  * <br><b>Role:</b><br>this event is sent by the CATCAfrMePreferencesNotificationManager.
  * <br>Sample of callback:
  * <pre>
  * ::AddCallback(this,
  *              CATCAfrMePreferencesNotificationManager::GetPreferencesNotificationManager(),
  *	           CATCAfrMePreferencesNotificationManager::SETTINGS_CANCLED(),
  *	           (CATSubscriberMethod)&MyClass::MyCBMethod,
  *	           NULL);
  * </pre>
  */
  CATDeclareCBEvent(SETTINGS_CANCLED);

  /**
  * Event sent when the Me-Preference RESET button pressed.
  * <br><b>Role:</b><br>this event is sent by the CATCAfrMePreferencesNotificationManager.
  * <br>Sample of callback:
  * <pre>
  * ::AddCallback(this,
  *              CATCAfrMePreferencesNotificationManager::GetPreferencesNotificationManager(),
  *	           CATCAfrMePreferencesNotificationManager::SETTINGS_RESET(),
  *	           (CATSubscriberMethod)&MyClass::MyCBMethod,
  *	           NULL);
  * </pre>
  */
  CATDeclareCBEvent(SETTINGS_RESET);




  /** @nodoc */  
  static CATCAfrMePreferencesNotificationManager * GetPreferencesNotificationManager();

private:
  // Copy constructor and assignement operator are declared private and not
  // implemented
  CATCAfrMePreferencesNotificationManager(const CATCAfrMePreferencesNotificationManager &);
  CATCAfrMePreferencesNotificationManager & operator= (const CATCAfrMePreferencesNotificationManager &);
  CATCAfrMePreferencesNotificationManager();

  ULONG __stdcall Release(){return CATBaseUnknown ::Release();};
  virtual ~CATCAfrMePreferencesNotificationManager();

  /** @nodoc */ 
  CATCallbackManager *  GetCallbackManager();

  static CATCAfrMePreferencesNotificationManager * _PreNotificatiofManager;
  CATCallbackManager * _MePrefNotificatioCallbackManager;

  void Send_SETTINGS_SAVED_Event();
  void Send_SETTINGS_APPLIED_Event();
  void Send_SSETTINGS_CANCLED_Event();
  void Send_SETTINGS_RESET_Event();

  friend void DestroyManager();
  friend class  CATCAfrPreferencesController;
};

#endif
