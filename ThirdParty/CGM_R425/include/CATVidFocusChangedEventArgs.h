#ifndef CATVidFocusChangedEventArgs_h
#define CATVidFocusChangedEventArgs_h

// COPYRIGHT Dassault Systemes 2014

// VisuImmersiveDialog framework
#include <VisuDialog.h>

// UIVCoreTools framework
#include <CATSYPEventArgs.h>
#include <UIVCoreToolsInline.h>

// System framework
#include <CATBoolean.h>

class CATSYPEvent;

/**
 * Argument for CATVidCtlLineEditor::EditingFinished event.
 *
 * The event is sent when the focus on a widget has changed (focus given or focus lost).
 */
class ExportedByVisuDialog CATVidFocusChangedEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;

public:

  /**
  * Constructor
  */
  CATVidFocusChangedEventArgs(CATSYPEvent *i_pEvent, CATBoolean i_tabKeyActivation);
  /**
  * Destructor
  */
  virtual ~CATVidFocusChangedEventArgs();

  /**
  * Get selection present in argument
  * @return current text editor selection
  */
  INLINE CATBoolean GetTabKeyActivation() const {return _tabKeyActivation;}

private:

  CATVidFocusChangedEventArgs(CATVidFocusChangedEventArgs&);
  CATVidFocusChangedEventArgs& operator=(CATVidFocusChangedEventArgs&);

  CATBoolean _tabKeyActivation;
};

#endif // CATVidFocusChangedEventArgs_h
