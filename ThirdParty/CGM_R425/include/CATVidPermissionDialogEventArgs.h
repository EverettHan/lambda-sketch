//===================================================================
// COPYRIGHT Dassault Systemes 2022-10-19
//===================================================================
// 2022-10-19 Creation: HBA11
//===================================================================

#ifndef CATVidPermissionDialogEventArgs_H
#define CATVidPermissionDialogEventArgs_H

// VisuImmersiveDialog
#include <VisuDialog.h>
// SystemTS
#include <DSYString.h>
// UIVCoreTools
#include <CATSYPEventArgs.h>
// std
#include <stdint.h>

class CATSYPEvent;
class CATVidCtlWebViewer;

/**
 * Dispatching arguments for handling the dialog before a permission request starts.
 * Call @ref #Consume to mark the event as handled and to override the default dehavior.
 */
class ExportedByVisuDialog CATVidPermissionDialogEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;

public:
  CATVidPermissionDialogEventArgs(CATSYPEvent*,
                                CATVidCtlWebViewer*,
                                const uint32_t,
                                const CATUnicodeString&);
  ~CATVidPermissionDialogEventArgs();

  /**
   * Possible behaviors for permission request.
   */
  enum Response {
    // Accept the permission request as an explicit user action.
    RE_ACCEPT = 0,
    // Deny the permission request as an explicit user action.
    RE_DENY,
    // Dismiss the permission request as an explicit user action.
    RE_DISMISS,
    // Ignore the permission request. If the prompt remains unhandled
    RE_IGNORE
  };

  /**
   * Selects a behavior and starts the permission request.
   * @param i_response
   *   The selected behavior. 
   */
  void Continue(const Response i_response);

  /**
   * Returns the origin address for the permission request.
   */
  const CATUnicodeString& GetOriginURL() const;

  /**
   * Returns a unique value for the permission type.
   */
  uint32_t GetPermissionType() const;

private:
  CATVidPermissionDialogEventArgs();
  CATVidPermissionDialogEventArgs(const CATVidPermissionDialogEventArgs&);
  CATVidPermissionDialogEventArgs& operator=(CATVidPermissionDialogEventArgs&);

  CATVidCtlWebViewer*    _pWebViewer;

  const CATUnicodeString _originURL;
  const uint32_t         _permissionType;
};

#endif // ! CATVidPermissionDialogEventArgs_H
