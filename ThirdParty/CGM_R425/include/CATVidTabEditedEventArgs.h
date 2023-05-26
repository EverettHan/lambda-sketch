#ifndef CATVidTabEditedEventArgs_H
#define CATVidTabEditedEventArgs_H

#include <VisuDialog.h>
#include <CATSYPEventArgs.h>
#include <CATBaseUnknown_WR.h>
#include <CATString.h>
class CATVidWidget;
class CATSYPEvent;

//-----------------------------------------------------------------------------
/** 
 * Event arguments for validated edition of a tab button.
 */
class ExportedByVisuDialog CATVidTabEditedEventArgs: public CATSYPEventArgs
{
  CATDeclareClass;
public:
  /** 
   * Initialize this class.
   *
   * @param i_pEvent the dispatched event. Can't be @c NULL. 
   * @param i_pWidget a pointer to the widget of the edited tab page. Cannot be @c NULL.
   * @param i_id ID of the edited tab page.
   * @param i_label the new label of the edited tab.
   */
  CATVidTabEditedEventArgs(CATSYPEvent * i_pEvent, CATVidWidget * i_pWidget, const CATString& i_id, const CATUnicodeString & i_label);

  /** Destroy this class. */
  virtual ~CATVidTabEditedEventArgs();

  /** @return a pointer to the widget of the tab that has just been edited. */
  CATVidWidget * GetWidget() const;

  /** @return the ID of the tab page corresponding to the edited tab. */
  const CATString& GetIdentifier() const { return _id; };

  /** @return the new label of the edited tab */
  const CATUnicodeString& GetLabel() const { return _label; }

private:
CATVidTabEditedEventArgs (CATVidTabEditedEventArgs &);
CATVidTabEditedEventArgs& operator=(CATVidTabEditedEventArgs&);

  CATBaseUnknown_WR _wrWidget;
  CATString _id;
  CATUnicodeString _label;
};

//-----------------------------------------------------------------------

#endif
