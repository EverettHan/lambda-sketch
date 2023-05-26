// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATVidCtlRadioButton.h
// Header definition of CATVidCtlRadioButton
//
//===================================================================
//  Oct 2005  Creation: Code generated by the CAA wizard  jov
//===================================================================
#ifndef CATVidCtlRadioButton_H
#define CATVidCtlRadioButton_H

#include <VisuDialog.h>
#include <CATVidCtlCheckBox.h>
#include <CATVidColor.h>
#include <CATMathPointf.h>
#include <CAT4x4Matrix.h>
#include <CATVidLaySideAttachConstraints.h>

#include <CATUnicodeString.h>

//-----------------------------------------------------------------------
/**
 * @ingroup VIDControls
 * This widget provides a radiobutton with a text label and an icon.
 * @par Creation
 * @code
 * CATVidCtlRadioButton* pButton = CATVidCtlRadioButton::CreateRadioButton(myCommandParent, "ButtonName");
 * @endcode
 * @image html CATVidCtlRadioButton.png V6 theme
 * @image html CATVidCtlRadioButton-Bright.png V6 theme, bright ambiance
 * @image html CATVidCtlRadioButton-3DViaShape.png 3DViaShape
 */
class ExportedByVisuDialog CATVidCtlRadioButton: public CATVidCtlCheckBox
{
  CATDeclareClass;
public:
  /** Constructor */
  CATVidCtlRadioButton ();
  /** Constructor */
  CATVidCtlRadioButton (CATCommand *i_pParent, const CATString & i_pIdentifier);
  /** 
   * Factory to create a styled radiobutton in current theme 
   * @param i_pParent the parent of the button.
   * @param i_pIdentifier  The name of the button.
   */
  static CATVidCtlRadioButton* CreateRadioButton(CATCommand *i_pParent, const CATString & i_pIdentifier);
protected:
  /** Constructor */
  CATVidCtlRadioButton (CreateLetterFunc i_pCreateLetterFunc);
  /** Constructor */
  CATVidCtlRadioButton (CATCommand *i_pParent, const CATString & i_pIdentifier, CreateLetterFunc i_pCreateLetterFunc);
  /** Destructor */
  virtual ~CATVidCtlRadioButton ();
  virtual void SetCheckState_internal(const CATBoolean i_state);
private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidCtlRadioButton (CATVidCtlRadioButton &);
  CATVidCtlRadioButton& operator=(CATVidCtlRadioButton& original);
};
//-----------------------------------------------------------------------

#endif
