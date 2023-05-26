// COPYRIGHT Dassault Systemes 2011
//===================================================================
#ifndef CATVidTextSelection_H
#define CATVidTextSelection_H

#include <VisuDialog.h>
#include <CATBoolean.h>
#include <CATBaseUnknown.h>
#include <CATListOfCATUnicodeString.h>
/**
 * @c CATVidTextSelection class defines a selection of text, from a cursor position to another.
 * For example for text "Abcdefg", a CATVidTextSelection(2, 4) correspond to "cd" string.
 * Note: 
 * @li Legal values for cursor position range from 0 to 'Number of characters'
 * @li -1 represent extremities. Ex. (-1,2) represent selection of first two characters
 * @li (-2, -2) represents empty selection 
 * @li this class is not responsible to check validity of cursor positions
 * @see CATVidCtlTextEditor
 */
class ExportedByVisuDialog CATVidTextSelection
{
public:
  /**
  * Default constructor
  */
  CATVidTextSelection ();
  /**
  * Parameterized constructor
  * @param i_stCursorPosition start cursor position for selection
  * @param i_enCursorPosition end cursor position for selection
  */
  CATVidTextSelection (const int i_stCursorPosition, const int i_enCursorPosition);
  /**
  * Destructor
  */
  virtual ~CATVidTextSelection ();

  /**
  * Copy constructor
  */
  CATVidTextSelection (const CATVidTextSelection &i_original);
  /**
  * Assignment operator
  */
  CATVidTextSelection& operator=(const CATVidTextSelection& i_original);
  /**
  * Equality operator
  */
  CATBoolean operator==(const CATVidTextSelection& i_right) const;
  /**
  * Non-equality operator
  */
  CATBoolean operator!=(const CATVidTextSelection& i_right) const;

  /**
  * Sets the current selection range
  * @param i_stCursorPosition start cursor position for selection
  * @param i_enCursorPosition end cursor position for selection
  */
  CATBoolean Set(const int i_stCursorPosition, const int i_enCursorPosition);
  /**
  * Gets the selection range
  * @param o_stChar start cursor position for this selection
  * @param o_enChar end cursor position for this selection
  */
  void Get(int & o_stChar,int & o_enChar)const;
  /**
  * Gets the start cursor position for this selection
  * @return start cursor position 
  */
  int GetStart()const{return _stChar;}
  /**
  * Gets the end cursor position for this selection
  * @return end cursor position 
  */
  int GetEnd()const{return _enChar;}

  CATBoolean IsValid() const;
  void Reset();

private:
  int _stChar;
  int _enChar;
};
//-----------------------------------------------------------------------

extern "C" ExportedByVisuDialog 
HRESULT CATSYPCATVidTextSelectionFactory(const CATListOfCATUnicodeString& i_firstList, CATBaseUnknown_var &ospRc);

#endif
