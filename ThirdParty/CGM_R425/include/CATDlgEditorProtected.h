#ifndef CATDLGEDITORPROTECTED_H
#define CATDLGEDITORPROTECTED_H
#include "DI0PANV2.h"
#include "CATBoolean.h"
#include "CATDlgUtility.h"

class CATNotification;
class CATDlgEditor;
class CATUnicodeString;
class CATChar;

// new style 
#define CATDlgEdtRich             (1 << 30)
class ExportedByDI0PANV2 CATDlgEditorProtected
{
  public :
    static void SetFontName(CATDlgEditor* edit, const CATUnicodeString& fontName);
    static void SetFontHeightInPixels(CATDlgEditor* edit, int height);
    static void SetFontHeight(CATDlgEditor* edit, int height /* in twips */);
    static void SetFontColor(CATDlgEditor* edit, unsigned char iRed, unsigned char iGreen, unsigned char iBlue);
    static void SetTextColor(CATDlgEditor* edit, unsigned char iRed, unsigned char iGreen, unsigned char iBlue, int iFirstCharacterIndex, int iLastCharacterIndex);
    static CATNotification* GetKeyboardCtrlNotification(CATDlgEditor* edit, const CATChar& ctrlChar);
  /**
   * Activates or deactivates "Shift+Enter" INSTEAD of "Enter" as the way of adding a new line in a multiline CATDlgEditor. 
   *
   * A call to this method is ignored if the CATDlgEditor object has not the CATDlgEdtMultiline style.  
   *   
   * @param iEditor
   *  The dialog object.
   * @param iActive
   *  TRUE  : "Enter" is no longer taken into account by the CATDlgEditor. "Shift+Enter" must be used to create a new line.
   *  FALSE : the multiline CATDlgEditor object goes back to the default situation where "Enter" is used to create a new line.    
   */
  static void SetShiftEnterActive (CATDlgEditor * iEditor, CATBoolean iActive);
   /**
   * Activates or deactivates "Quick Edit Mode"
   *
   * "Quick Edit mode" is relevant only for a CATDlgEditor embedded in a CATDlgDialog Dialog Box 
   * 
   * When "Quick Edit mode" is active, the following keys have a special processing : 
   * Left, Up, Right, Bootom, Page Up, Page Down, Home and End.
   * When one of these keys is pressed whereas a CATDlgEditor in Quick Edit mode has the
   * keyboard focus, then :
   * - The OK button of the CATDlgDialog embedding the CATDlgEditor is activated.
   * - The keyboard focus is given to the graphic window of the current CATViewer of the current MDI child window, if such a viewer exists.
   * - The current keyboard event is forwarded to this new focus owner, if it exists.        
   *
   * @param iEditor
   *  The dialog object.
   * @param iActive
   *  TRUE  : activates "Quick Edit mode"
   *  FALSE : deactivates "Quick Edit mode"
   */
  static void SetQuickEditMode(CATDlgEditor * iEditor, CATBoolean iQuickEdit);

   /**
   * provisional => signature may change !
   *
   * Gets the image of a text just like it is displayed in a CATDlgEditor.
   *
   * Implemented on Windows only. 
   *
   * @param iEditor
   *  the dialog object.
   * @param iDef
   *  specifies if the output dimensions will describe the Client rectangle of the CATDlgEditor or the Text Bounding rectangle.
   * @param oWidth
   *  image width in pixels
   * @param oHeight
   *  image height in pixels
   * @param oImage
   *  address of the pixels. Dimension is 4*oWidth*oHeight.
   *  Allocated by the callee. To be deallocated by the caller through delete [].
   *
   */
  enum RectangleDefinition {EditorClientRectangle, TextRectangle};
  static void GetTextImage(CATDlgEditor* iEditor, RectangleDefinition iDef,  int& oWidth, int& oHeight, unsigned char* & oImage );  

  /**
   * Add a callback that will receive the press down events
   * on TAB key (or Shift-TAB key).
   * @note 
   * If a callback has been set then the default handling of the TAB
   * key is no more called. That means that setting a callback will
   * prevent TAB from changing the focus.
   * @note
   * This new functionality is provided for the integration of the
   * Visualization Immersive Dialog @ref CATVidCtlEditor component.
   * Please contact Dialog team before using this functionality in
   * an other context.
   * @param i_pEditor the editor instance. Must not be @c NULL.
   * @param i_pCallback the callback. Can be @c NULL, in that case
   * the behavior is the same as before @c SetTabCallback was called.
   * @param i_pData some user data that will be given back as-is when
   * the callback is called.
   */
  static void SetTabCallback(CATDlgEditor *i_pEditor, void (*i_pCallback)(int i_shiftDown, void *i_pData), void *i_pData);
  /**
   * Add a callback that will receive the press down and press up events
   * on ENTER key.
   * @note
   * Setting a callback will NOT prevent the default handling of 
   * the ENTER key to be called.
   * @note
   * The callback will be called on press down event BEFORE the code
   * dispatching the @ref #GetEditModifyNotification notification is called.
   * @note
   * On both unix and windows, if the user keep the enter key down, the 
   * callback will be called multiple times with down events before being
   * called with an up event when the key is finally released.
   * @note
   * You may never receive the key up event after a key down. For example:
   *   - if the focus has changed after the key has been pressed (with a
   *     mouse click for example)
   *   - if a modifier key has been pressed before the key is released (for
   *     example the user press ENTER, keeping it pressed she/he then 
   *     press CTRL and finally the user releases ENTER; in that case
   *     the callback is never called on key up).
   * @note
   * You may also receive a key up event without having received a
   * key down. For example:
   *   - if the focus was given to the editor while the key was pressed
   *   - if a modifier key was pressed when the ENTER key has been pressed.
   *
   * @note
   * This callback is only called if the component is either single line,
   * or multiline with @ref #IsShiftEnterActive @c TRUE. If @ref #IsShiftEnterActive
   * is @c FALSE and this component is multiline, then the callback will
   * never be called (in that case ENTER key is used to insert a new line
   * and there is no key to validate the editor content; only losing focus
   * validates the editor).
   * @note
   * This new functionality is provided for the integration of the
   * Visualization Immersive Dialog @ref CATVidCtlEditor component.
   * Please contact Dialog team before using this functionality in
   * an other context.
   * @param i_pEditor the editor instance. Must not be @c NULL.
   * @param i_pCallback the callback. Can be @c NULL, in that case
   * the behavior is the same as before @c SetEnterCallback was called.
   * @param i_pData some user data that will be given back as-is when
   * the callback is called.
   */
  static void SetEnterCallback(CATDlgEditor *i_pEditor, void (*i_pCallback)(int i_down, void *i_pData), void *i_pData);
  /**
   * Add a callback that will receive the press down and press up events
   * on ESCAPE key.
   * @note 
   * If a callback has been set then the default handling of the ESCAPE
   * key is no more called.
   * @note
   * On both unix and windows, if the user keep the enter key down, the 
   * callback will be called multiple times with down events before being
   * called with an up event when the key is finally released.
   * @note
   * You may never receive the key up event after a key down. For example:
   *   - if the focus has changed after the key has been pressed (with a
   *     mouse click for example)
   *   - if a modifier key has been pressed before the key is released (for
   *     example the user press ESCAPE, keeping it pressed she/he then 
   *     press CTRL and finally the user releases ESCAPE; in that case
   *     the callback is never called on key up).
   * @note
   * You may also receive a key up event without having received a
   * key down. For example:
   *   - if the focus was given to the editor while the key was pressed
   *   - if a modifier key was pressed when the ESCAPE key has been pressed.
   *
   * @note
   * This new functionality is provided for the integration of the
   * Visualization Immersive Dialog @ref CATVidCtlEditor component.
   * Please contact Dialog team before using this functionality in
   * an other context.
   * @param i_pEditor the editor instance. Must not be @c NULL.
   * @param i_pCallback the callback. Can be @c NULL, in that case
   * the behavior is the same as before @c SetEscapeCallback was called.
   * @param i_pData some user data that will be given back as-is when
   * the callback is called.
   */
  static void SetEscapeCallback(CATDlgEditor *i_pEditor, void (*i_pCallback)(int i_down, void *i_pData), void *i_pData);

  /**
   * Fills an editor with an array of CATUnicodeString.
   * @param i_pEditor
   *   The editor instance. Must not be @c NULL.
   * @param i_pUStr
   *   The array of CATUnicodeString.
   * @param i_count
   *   The size of the array.
   * @param i_index 
   *   <br><b>Legal values</b>: <tt>0 (default)</tt> The lines are inserted at the beginning of editor.
   *   <tt>non nul value</tt> The lines are appended at the end of editor.
   * @return The count of inserted lines.
   */
  static int SetLines(CATDlgEditor *i_pEditor, const CATUnicodeString *i_pUStr, int i_count, int i_index=0);

  /**
   * Sets the line count.
   * @param i_pEditor
   *   The editor instance. Must not be @c NULL.
   * @param i_count
   *   The line count.
   */
  static void SetLineCount(CATDlgEditor *i_pEditor, int i_count);

  /**
   * Set focus on editor (only works on Windows)
   * @param iEditor the editor
   */
  static void SetFocus(CATDlgEditor * iEditor);


  static float getZoom(CATDlgEditor * iEditor);
};
#endif
