#ifndef CATDLGFINDANDREPLACE_H
#define CATDLGFINDANDREPLACE_H

#include "CATDlgStandard.h"
#include "CATDlgDialog.h"

class CATDlgEditor;
class l_CATDlgFindAndReplace;

/**
 * popup windows to choose a date.
 * <b>Role</b>:
 * This dialog windows enables a end user to conveniently choose a date
 */

class ExportedByCATDlgStandard CATDlgFindAndReplace : public CATDlgDialog
{
  DeclareResource(CATDlgFindAndReplace, CATDlgDialog)

  public:
  /**
   * Constructs a Find And Replace panel.
   * @param iParent
   *   The parent of the object. It is an editor.
   * @param iObjectName
   *   The internal name of the object. Default is "FindAndReplace"
   * @param iStyle
   *   The style of the object
   * The style can be :
   *   <dl>
   *   <dt><tt>NULL</tt><dd> Then the style is CATDlgWndNoButton | CATDlgGridLayout.
   *   <dt><tt>CATDlgWndModal</tt><dd> for a modal window; no interaction is possible outside this window
   *   as long as it is displayed. The cursor changes to prevent from doing anything outside of the window.
   *   <dt><dd>Default value is CATDlgWndNoButton | CATDlgGridLayout
   *   </dl>
   */
  CATDlgFindAndReplace(CATDlgEditor *iFather,
    const CATString &iName = (char *)"FindAndReplace",
    CATDlgStyle iStyle=CATDlgWndNoButton|CATDlgGridLayout);

  virtual ~CATDlgFindAndReplace();

  /**
   * @nodoc
   * Requests the ClassName, IsA, and IsAKindOf methods to be created.
   */
  CATDeclareClass;

  private:
  /**
   * @nodoc
   */
  l_CATDlgFindAndReplace* _frameFindAndReplaceWindow;
};
#endif

