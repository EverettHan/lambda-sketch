#ifndef CATVidTabButtonEditedEventArgs_H
#define CATVidTabButtonEditedEventArgs_H

#include <VisuDialog.h>
#include <CATSYPEventArgs.h>
#include <CATBaseUnknown_WR.h>
class CATVidCtlTabButton;
class CATSYPEvent;

//-----------------------------------------------------------------------------
/** 
 * Event arguments for validated edition of a tab button.
 */
class ExportedByVisuDialog CATVidTabButtonEditedEventArgs: public CATSYPEventArgs
{
  CATDeclareClass;
public:
  /** 
   * Initialize this class.
   *
   * @param i_pEvent the dispatched event. Can't be @c NULL. 
   * 
   * @param i_pTabButton a pointer to the edited tab button. Cannot be @c NULL.
   */
  CATVidTabButtonEditedEventArgs(CATSYPEvent * i_pEvent, CATVidCtlTabButton * i_pTabButton);

  /** Destroy this class. */
  virtual ~CATVidTabButtonEditedEventArgs();

  /** @return a pointer to the tab button that has just been edited. */
  CATVidCtlTabButton * GetTabButton() const;

private:
CATVidTabButtonEditedEventArgs (CATVidTabButtonEditedEventArgs &);
CATVidTabButtonEditedEventArgs& operator=(CATVidTabButtonEditedEventArgs&);

  CATBaseUnknown_WR _wrTabButton;

};

//-----------------------------------------------------------------------

#endif
