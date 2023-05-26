// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATVidCtlLineEditorUI.h
// Header definition of CATVidCtlNotepad
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Sep 2011  Creation: 3dPLM
//===================================================================
#ifndef CATVidCtlNotepad_H
#define CATVidCtlNotepad_H

#include <VisuDialog.h>
#include "CATVidCtl.h"
#include "CATUnicodeString.h"
#include "CATBaseUnknown_WR.h"

class CATVidCtlTextEditor;

/**
 * This widget provides a rich text editor with basic manipulation commands 
 * accessible via a toolbar.
 *
 * @par Customization 
 * @li User can select position of toolbar (Top or Bottom). Default is Top. see #CreateNotepad.
 * 
 * @par Creation
 * @code
 * CATVidCtlNotepad* pNotepad = CATVidCtlNotepad::CreateNotepad(myCommandParent, "NotepadName", "TemplateName", "VariationName");
 * @endcode
 * @ingroup VIDControls
 * @see CATVidCtlTextEditor
 */
class ExportedByVisuDialog CATVidCtlNotepad: public CATVidCtl
{
  CATDeclareClass;
  
public:

  /**
  * Constructs a CATVidCtlNotepad with standard style.
  * @param i_pParent The parent of the widget.
  * @param i_pIdentifier The name of the widget.
  * @param i_template Name of the template. Must be @c Default.
  * @param i_variation Variation name. Can be @c ToolbarAtBottom if toolbar should be at bottom otherwise empty string will create toolbar at top (Default behavior).
  */
  static CATVidCtlNotepad* CreateNotepad(CATCommand *i_pParent, const CATString & i_pIdentifier, const CATUnicodeString &i_template, const CATUnicodeString &i_variation);
  
  /**
  * Constructor 
  */ 
  CATVidCtlNotepad();
  /**
  * Destructor
  */   
  virtual ~CATVidCtlNotepad();

  /**
   * Get text editor associated with this Notepad. Note: AddRef is not done on returned pointer.
   * User should use weak ref (@ref CATBaseUnknown_WR) to store returned pointer.
   * @return current text editor (see @ref CATVidCtlTextEditor)
   */
  CATVidCtlTextEditor* GetTextEditor() const;

  /**
   * @copydoc l_CATVidCtl#TemplateDataUpdated
   * Here are the mandatory "syp:named" objects : 
   * @li Editor [CATVidCtlTextEditor]
   * And the optional ones :
   * @li Toolbar [CATVidCtlNotepadTools]
   */
  virtual void TemplateDataUpdated();

  /*
    You can set visibility of Font name and font height combo boxes. By default FontComboVisibilityFlag is False.
  */
  void SetFontComboVisibilityFlag(const CATBoolean i_FontComboVisibilityFlag);
  const CATBoolean& GetFontComboVisibilityFlag();


private:
  // Copy constructor and assignment operator
  // ----------------------------------------
  CATVidCtlNotepad (CATVidCtlNotepad &);
  CATVidCtlNotepad& operator=(CATVidCtlNotepad&);

  CATBaseUnknown_WR _textEditor;
  CATBoolean _FontComboVisibilityFlag;
  
};
//-----------------------------------------------------------------------

#endif
