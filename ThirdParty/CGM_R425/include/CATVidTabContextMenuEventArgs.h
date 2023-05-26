#ifndef CATVidTabContextMenuEventArgs_H
#define CATVidTabContextMenuEventArgs_H

#include "VisuDialog.h"
#include "CATVidMouseAndKeyboardEventArgs.h"

class CATVidWidget;

/** @ingroup VIDGP
 * 
 * Class for redispatching the information contained in the arguments of a 
 * @ref CATVidCtl#ContextMenuRequired event that has been dispatched on a 
 * @ref CATVidCtlTabButton, along with the corresponding tab widget.
 */
class ExportedByVisuDialog CATVidTabContextMenuEventArgs : public CATVidMouseAndKeyboardEventArgs
{
  CATDeclareClass;

public:
  /** Destroy this class */
  virtual ~CATVidTabContextMenuEventArgs();
  /** 
   * Initialize this class with the arguments of a mouse event and/or with a 
   * keyboard event and a tab widget. 
   *
   * @param i_pEvent the dispatched event.
   * @param i_pMouseEventArgs the mouse event arguments.
   * @param i_pKeyboardEvent the keyboard event.
   * @param i_index the index that corresponds to the tab button where
   * a context menu is required.
   */
  CATVidTabContextMenuEventArgs(CATSYPEvent * i_pEvent, CATVidMouseEventArgs * i_pMouseEventArgs, CATKeybdEvent * i_pKeyboardEvent, int i_index);

  /** 
   * @return the index corresponding to the tab button where a
   * context menu is required.  
   */
  int GetIndex() const;

private:
  /** Copy constructor. */
  CATVidTabContextMenuEventArgs(const CATVidTabContextMenuEventArgs &);
  /** Assignment operator. */
  CATVidTabContextMenuEventArgs &operator=(const CATVidTabContextMenuEventArgs &);
private:
  /** @see #GetIndex */
  int _index;
};

#endif // CATVidTabContextMenuEventArgs_H
