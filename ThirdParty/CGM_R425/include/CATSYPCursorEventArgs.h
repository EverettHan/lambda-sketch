// COPYRIGHT Dassault Systemes 2012
//===================================================================
//  Jan 2012  Creation: 3dPLM
//===================================================================
#ifndef CATSYPCursorEventArgs_H
#define CATSYPCursorEventArgs_H
// Local
#include <VisuDialog.h>
#include <CATVidTextStyle.h>
// IntrospectionInfrastructure
#include <CATSYPEventArgs.h>

class CATSYPEvent;

/**
 * Argument for CATVidCtlTextEditor::CursorPositionChanged event.
 *
 * The event is sent when cursor position in the editor is changed (using mouse or keyboard). 
 * The argument contain information about new cursor position (global index) in text editor and 
 * text style at that cursor position.
 */

class ExportedByVisuDialog CATSYPCursorEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;

public:

  /**
   * Constructor
   */
  CATSYPCursorEventArgs(CATSYPEvent *i_pEvent, int iCursorPos, const CATVidTextStyle &iCurrStyle);

  /**
   * Destructor
   */
  ~CATSYPCursorEventArgs();

  /**
   * Get current cursor position in terms of global character index
   * @return current cursor position
   */
  int GetGlobalCursorPosition();

  /**
   * Get current text style
   * @return text style at current cursor position
   */
  CATVidTextStyle GetTextStyle();

private:
  CATSYPCursorEventArgs(CATSYPCursorEventArgs&);
  CATSYPCursorEventArgs& operator=(CATSYPCursorEventArgs&);

  int _cursorPos;
  CATVidTextStyle _textStyle;
};

#endif
