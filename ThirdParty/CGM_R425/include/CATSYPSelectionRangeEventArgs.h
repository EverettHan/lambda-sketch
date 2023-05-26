//===================================================================
// COPYRIGHT Dassault Systemes 2016/06/22
//===================================================================
// CATSYPSelectionRangeEventArgs.cpp
// Header definition of class CATSYPSelectionRangeEventArgs
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2016/06/22 Creation: EFM
//===================================================================
#ifndef CATSYPSelectionRangeEventArgs_H
#define CATSYPSelectionRangeEventArgs_H

#include <VisuDialog.h>
// IntrospectionInfrastructure
#include <CATSYPEventArgs.h>

class CATSYPEvent;

/**
 * Argument for CATVidCtlCodeEditor events.
 */

class ExportedByVisuDialog CATSYPSelectionRangeEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;

public:
  /**
   * Constructor
   */
  CATSYPSelectionRangeEventArgs(CATSYPEvent *i_pEvent, int iStartLine, int iStartChar, int iEndLine, int iEndChar);

  /**
   * Destructor
   */
  ~CATSYPSelectionRangeEventArgs();

  /**
   * Get start line
   * @return start line
   */
  int GetStartLine();

  /**
   * Get start character
   * @return start character
   */
  int GetStartChar();

  /**
   * Get end line
   * @return end line
   */
  int GetEndLine();

  /**
   * Get end character
   * @return end character
   */
  int GetEndChar();
 
private:
  CATSYPSelectionRangeEventArgs(CATSYPSelectionRangeEventArgs&);
  CATSYPSelectionRangeEventArgs& operator=(CATSYPSelectionRangeEventArgs&);

  int _startLine;
  int _startChar;
  int _endLine;
  int _endChar;
};

#endif
