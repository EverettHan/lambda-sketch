#ifndef CATVidActionBarV3FlyOutStyle__H
#define CATVidActionBarV3FlyOutStyle__H

#include <VisuDialogEx.h>
#include <CATSYPDeclareEnumFactory.h>

/**
 * Define the possible state for the style of the flyout (either the main
 * button or the expander).
 */
class ExportedByVisuDialogEx CATVidActionBarV3FlyOutStyle
{
public:
  /**
   * Enumeration of the different visual style of the flyout.
   */
  enum State
  {
    /** Normal state: no border or highlight are displayed */
    Normal = 0,
    /** Borders around the flyout are displayed */
    Highlighted,
    /**
     * Borders around the flyout are displayed and the main button is
     * highlighted
     */
    Activated
  };
};

CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialogEx, CATVidActionBarV3FlyOutStyle__State);

#endif
