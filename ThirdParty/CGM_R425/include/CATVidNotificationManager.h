#ifndef CATVidNotificationManager_H
#define CATVidNotificationManager_H

#include <VisuDialog.h>
#include <CATUnicodeString.h>
class CATSYPDataBlock;
class CATVidFraNotificationWindow;

/**
 * @ingroup VIDCore
 *
 * @par 
 * @c CATVidNotificationManager enqueues notification messages and displays
 * them in first in, first out order.
 *
 * @par
 * The content of notifications are defined by data-blocks and associated 
 * data-templates. Easy accessors are available for text-only notifications, 
 * that will use a text-only data-block with a default data-template.
 */
class ExportedByVisuDialog CATVidNotificationManager
{
public:
  /** Default display duration of a notification, in seconds: 2.0 sec. */
  static float const DefaultDuration;

public:
  /** @copydoc CATVidFraNotificationWindow#GetCurrentTextMessage */
  static CATUnicodeString GetCurrentTextMessage();
  /** @copydoc CATVidFraNotificationWindow#ShowTextMessage */
  static void ShowTextMessage(const CATUnicodeString & i_message, float i_duration = CATVidNotificationManager::DefaultDuration);
  /** @copydoc CATVidFraNotificationWindow#GetCurrentMessage */
  static CATSYPDataBlock * GetCurrentMessage();
  /** @copydoc CATVidFraNotificationWindow#ShowMessage */
  static void ShowMessage(CATSYPDataBlock * i_pDataBlock, const CATUnicodeString & i_styleSheet, const CATUnicodeString & i_dataTemplate, float i_duration = CATVidNotificationManager::DefaultDuration);
  /** @copydoc CATVidFraNotificationWindow#ClearMessages */
  static void ClearMessages();
  /** @copydoc CATVidFraNotificationWindow#IsEmpty */
  static CATBoolean IsEmpty();

protected:
  /** Destructor. */
  virtual ~CATVidNotificationManager();

private:
  /** Constructor. Purely static method class, not meant to be instantiated. */
  CATVidNotificationManager();
  /** Copy constructor. Not implemented. */
  CATVidNotificationManager (CATVidNotificationManager &);
  /** Assignment operator. Not implemented. */
  CATVidNotificationManager& operator=(CATVidNotificationManager & original);
  /** @return the not @c NULL singleton notification frame. */
  static inline CATVidFraNotificationWindow * GetFrame();
};
//-----------------------------------------------------------------------------

#endif

