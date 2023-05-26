#ifndef UAPanelsController_H
#define UAPanelsController_H
#include "ExportedByUACommands.h"
//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2015
//------------------------------------------------------------------------------
// fw AfrFoundation
// CATAfrHelpAndDoc.m
// protected
//------------------------------------------------------------------------------
// Class UAPanelsController
// > CATCommand
// > > CATEventSubscriber
// > > > CATBaseUnknown
//------------------------------------------------------------------------------
// Abstract: UAPanelsController is the command managing UA Panel display and content
//------------------------------------------------------------------------------

// System framework
#include "CATCommand.h" 
#include "CATUnicodeString.h"
#include "CATBoolean.h"

class CATVidFraPanel;
class UAPanel;
class CATSYPEventArgs;

/**
 *  Class representing the Chooser command.
 */
class ExportedByUACommands UAPanelsController: public CATCommand
{

  CATDeclareClass;

public:

  /**
  * Constructs a Tutorial Chooser command.
  */
  UAPanelsController ();

  // Standard destructor
  virtual ~UAPanelsController ();

  // Get Unique instance
  static UAPanelsController * GetController ();

  //---------------------------------------------------------------------------
  /**
  * Enables the user assistance help panel.
  * <br><b>Role</b>: This function enables the user assistance panel display.
  * @return
  * Returns always S_OK.
  */
  HRESULT EnableUAPanelHelp ();

  //---------------------------------------------------------------------------
  /**
  * Disables the user assistance help panel.
  * <br><b>Role</b>: This function disables the user assistance panel display.
  * @return
  * Returns always S_OK.
  */
  HRESULT DisableUAPanelHelp ();

  //---------------------------------------------------------------------------
  /**
  * Shows the user assistance help panel.
  * <br><b>Role</b>: This function shows the user assistance panel.
  * @return
  * Returns always S_OK.
  */
  HRESULT ShowUAPanelHelp ();

  //---------------------------------------------------------------------------
  /**
  * Hides the user assistance help panel.
  * <br><b>Role</b>: This function hides the user assistance panel.
  * @return
  * Returns always S_OK.
  */
  HRESULT HideUAPanelHelp (CATBoolean iUserAction = FALSE);

  //---------------------------------------------------------------------------
  /**
  * Displays the user assistance help panel with current context.
  * <br><b>Role</b>: This function updates and displays the user assistance panel with current context.
  * @return
  * Returns always S_OK.
  */
  HRESULT DisplayUAPanelHelp (CATBoolean iForce = FALSE);

  //---------------------------------------------------------------------------
  /**
  * Displays the user assistance help panel.
  * <br><b>Role</b>: This function displays the user assistance panel with given parameters.
  * @return
  * Returns always S_OK.
  */
  HRESULT DisplayUAPanelHelp (const CATUnicodeString & iPanelHelpURL, const CATUnicodeString & iWebHelpURL, const CATUnicodeString & iAppWebHelpURL);

  //---------------------------------------------------------------------------
  /**
  * Indicates that a panel is being deleted.
  * <br><b>Role</b>: This function indicates that a UAPanel is being deleted.
  * @return
  * Returns always S_OK.
  */
  HRESULT UAPanelDeleted (UAPanel * _panel);

  //---------------------------------------------------------------------------
  /**
  * Indicates that the context has changed.
  * <br><b>Role</b>: This function requests to update the UA panel content or status.
  * @return
  * Returns always S_OK.
  */
  HRESULT UpdatePanelHelp ();

  //---------------------------------------------------------------------------
  /**
  * Displays more help link.
  * <br><b>Role</b>: This function displays the WebHelp associated to the current PanelHelp.
  * @return
  * Returns always S_OK.
  */
  HRESULT DisplayMoreHelp ();

private:

  CATBoolean _bUAPanelHelpEnabled;
  CATBoolean _bUAPanelHelpShown;

  CATUnicodeString _MoreHelpWebHelpURL;

  CATVidFraPanel * _FraPanelHelp;
  UAPanel * _UAPanelHelp;

  HRESULT DisplayDefaultUAPanelHelpTopic ();
  HRESULT CreateUAPanelHelp ();
  void ClosePanelHelp ();

  // Called when the window is destroyed
  void UserClosePanelHelp (CATCallbackEvent  iPublishedEvent,
                           void *            iPublishingObject,
                           CATNotification * iNotification,
                           CATSubscriberData iClientData,
                           CATCallback       iCallback);
  // Called when the current command ( started through a command header) ends
  /*
  void OnCurrentCmdEnd (CATCallbackEvent  iPublishedEvent,
                        void *            iPublishingObject,
                        CATNotification * iNotification,
                        CATSubscriberData iClientData,
                        CATCallback       iCallback);
                        */
  // Called when an exclusive or shared command (started through a command header) is activated
  void OnCmdActivated (CATCallbackEvent  iPublishedEvent,
                       void *            iPublishingObject,
                       CATNotification * iNotification,
                       CATSubscriberData iClientData,
                       CATCallback       iCallback);
  // Called when registered helpid (by Undefined commands) changes
  void OnHelpIdChanged (CATCallbackEvent  iPublishedEvent,
                        void *            iPublishingObject,
                        CATNotification * iNotification,
                        CATSubscriberData iClientData,
                        CATCallback       iCallback);
  // Called when the current tab ends
  void OnTabChanged (CATCallbackEvent  iPublishedEvent,
                     void *            iPublishingObject,
                     CATNotification * iNotification,
                     CATSubscriberData iClientData,
                     CATCallback       iCallback);
  // Called when the workbench changes
  void OnWorkbenchSwitch (CATCallbackEvent  iPublishedEvent,
                          void *            iPublishingObject,
                          CATNotification * iNotification,
                          CATSubscriberData iClientData,
                          CATCallback       iCallback);
  // Called when the user clicks on the close button in the box
  void OnClosedPanelHelp (CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);

  // Standard copy constructor and assignment operator
  UAPanelsController (const UAPanelsController &);
  UAPanelsController & operator = (const UAPanelsController &);

  friend void UAPanelsControllerAwakeOnIdle (CATCommand *, int, void *);
  friend void UAPanelsControllerDisplayOnIdle (CATCommand *, int, void *);

};

#endif
