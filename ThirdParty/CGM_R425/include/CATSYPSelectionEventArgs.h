// COPYRIGHT Dassault Systemes 2012
//===================================================================
//  Jan 2012  Creation: 3dPLM
//===================================================================
#ifndef CATSYPSelectionEventArgs_H
#define CATSYPSelectionEventArgs_H
// Local
#include <VisuDialog.h>
#include <CATVidTextSelection.h>
// IntrospectionInfrastructure
#include <CATSYPEventArgs.h>

class CATSYPEvent;

/**
* Argument for CATVidCtlTextEditor::SelectionChanged event.
*
* The event is sent when selection in the editor is changed (using mouse or keyboard). 
* The argument contain new selection currently set on text editor.
*/
class ExportedByVisuDialog CATSYPSelectionEventArgs : public CATSYPEventArgs
{
public:
  /**
  * Constructor
  */
  CATSYPSelectionEventArgs(CATSYPEvent *i_pEvent, const CATVidTextSelection &iSelection);
  /**
  * Destructor
  */
  ~CATSYPSelectionEventArgs();

  /**
  * Get selection present in argument
  * @return current text editor selection
  */
  CATVidTextSelection GetSelection();

private:
  CATSYPSelectionEventArgs(CATSYPSelectionEventArgs&);
  CATSYPSelectionEventArgs& operator=(CATSYPSelectionEventArgs&);

  CATVidTextSelection _sel;
};

#endif // CATSYPSelectionEventArgs_H
