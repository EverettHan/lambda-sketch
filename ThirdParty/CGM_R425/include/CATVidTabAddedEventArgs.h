#ifndef CATVidTabAddedEventArgs_H
#define CATVidTabAddedEventArgs_H

#include <VisuDialog.h>
#include <CATSYPEventArgs.h>
#include <CATBaseUnknown_WR.h>
#include <CATString.h>
class CATVidCtlTabButton;
class CATVidWidget;
class CATSYPEvent;

//-----------------------------------------------------------------------------
/** 
 * Event arguments for tab button addition.
 */
class ExportedByVisuDialog CATVidTabAddedEventArgs: public CATSYPEventArgs
{
  CATDeclareClass;
public:
  /** 
   * Initialize this class.
   *
   * @param i_pEvent the dispatched event. Can't be @c NULL. 
   * @param i_pWidget a pointer to the widget of the added tab button. Cannot be @c NULL.
   * @param i_id ID of the edited tab page.
   */
  CATVidTabAddedEventArgs(CATSYPEvent * i_pEvent, CATVidWidget * i_pWidget, int i_Index);

  /** Destroy this class. */
  virtual ~CATVidTabAddedEventArgs();

  /** @return a pointer to the tab button that has just been added to the tab bar. */
  CATVidCtlTabButton * GetTabButton() const;

  /** @return the index of the tab page corresponding to the added tab. */
  int GetIndex() const { return _index; };

private:
   /** Copy constructor. */
  CATVidTabAddedEventArgs (CATVidTabAddedEventArgs &);
   /** Assignment operator. */
  CATVidTabAddedEventArgs& operator=(CATVidTabAddedEventArgs&);
  /** @see #GetTabButton */
  CATBaseUnknown_WR _wrWidget;
  /** @see #GetIndex */
  int _index;
};

//-----------------------------------------------------------------------

#endif
