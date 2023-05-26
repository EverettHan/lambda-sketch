//===================================================================
// COPYRIGHT Dassault Systemes 2019-08-06
//===================================================================
// 2019-08-06 Creation: D6K
//===================================================================

#ifndef CATVidWebTypes_H
#define CATVidWebTypes_H

// VisuImmersiveDialog
#include <VisuDialog.h>
// IntrospectionInfrastructure
#include <CATSYPDeclareEnumFactory.h>

class l_CATVidCtlWebViewer;

namespace CATVidWeb
{
  // Possible behaviors to be applied when popup windows are opened by the current page.
  enum PopupBehavior
  {
    // Deny creation of all popup windows.
    // If `window.open` was used, it will return `null`.
    BlockPopups = 0,
    // Default behavior: allow popup windows to be created.
    OpenPopups,
    // Deny creation of popup windows, but navigate to their URL in the current view.
    // If `window.open` was used, it will return `null`.
    OpenPopupsInCurrentView
  };
} // namespace CATVidWeb

CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialog, CATVidWeb__PopupBehavior);

#endif // CATVidWebTypes_H
