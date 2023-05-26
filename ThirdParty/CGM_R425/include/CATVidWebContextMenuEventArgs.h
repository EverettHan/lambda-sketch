//===================================================================
// COPYRIGHT Dassault Systemes 2016-12-15
//===================================================================
// 2016-12-15 Creation: D6K
//===================================================================

#ifndef CATVidWebContextMenuEventArgs_H
#define CATVidWebContextMenuEventArgs_H

// VisuImmersiveDialog
#include <VisuDialog.h>
// UIVCoreTools
#include <CATSYPEventArgs.h>
#include <CATSYPArray.h>

class CATSYPEvent;
class CATVidActionGroup;

/**
 * Dispatching arguments for handling context menus triggered by a web view.
 * Call @ref #Consume to mark the event as handled and allow the web view to display a customized menu.
 */
class ExportedByVisuDialog CATVidWebContextMenuEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;

public:
  explicit CATVidWebContextMenuEventArgs(CATSYPEvent*);
  ~CATVidWebContextMenuEventArgs();

  /**
   * Location choice for additional menu actions.
   */
  enum DisplayMode {
    // New actions will be added after the base menu.
    DISP_AFTER = 0,
    // New actions will be added before the base menu.
    DISP_BEFORE,
    // New actions will replace the base menu.
    DISP_OVERRIDE
  };

  /**
   * Copies the properties from another instance, except the event and the origin.
   * If some of them can be addref'd, this method will do it.
   * @param i_other
   *   The other instance to make the copies from.
   */
  void Copy(const CATVidWebContextMenuEventArgs& i_other);
  /**
   * Chooses where the new menu actions should be located, relative to the base menu built by the web view.
   * @param i_mode
   *   The new way the additional menu actions will be displayed.
   */
  void SetDisplayMode(const DisplayMode i_mode);
  /**
   * Indicates where the new menu actions will be displayed, relative to the base menu built by the web view.
   */
  DisplayMode GetDisplayMode() const;
  /**
   * Adds a group of menu actions to be merged with the base menu built by the web view.
   * @param i_pGroup
   *   A group of actions to add to the base menu, or replace it with.
   */
  void AddActionGroup(CATVidActionGroup* i_pGroup);
  /**
   * Returns all the action groups that will be merged with the base menu built by the web view.
   */
  const CATSYPConstArray<CATVidActionGroup*>& GetActionGroups() const;

private:
  CATVidWebContextMenuEventArgs();
  CATVidWebContextMenuEventArgs(const CATVidWebContextMenuEventArgs&);
  CATVidWebContextMenuEventArgs& operator=(const CATVidWebContextMenuEventArgs&);

  CATSYPDynArray<CATVidActionGroup*> _actionGroups;
  DisplayMode                        _displayMode;
};

#endif // CATVidWebContextMenuEventArgs_H
