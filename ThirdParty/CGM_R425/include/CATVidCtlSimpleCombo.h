#ifndef CATVidCtlSimpleCombo_h
#define CATVidCtlSimpleCombo_h

// COPYRIGHT Dassault Systemes 2013

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidCtlBaseCombo.h>
#include <CATVidEnum.h>

// MultimediaPixelImage framework
#include <CATPixelImage.h>

// Mathematics framework
#include <CATMathPoint2Df.h>

// Dialog framework
#include <CATDlgUtility.h>

// System framework
#include <CATBoolean.h>
#include <CATUnicodeString.h>
#include <CATListOfCATUnicodeString.h>
#include <CATLISTV_CATBaseUnknown.h>

#include <list.h>

class CATISYPCollection_var;
class CATSYPEvent;
class CATVidMdlCompletionProxy;

/**
 * @ingroup VIDControls
 * 
 * This class is the more simple way to have a combo box with text and/or icons as items.
 * It provides basic combo box behaviour : selecting a element puts it on the top line.
 * 
 * @par Editable combo
 * You can make it editable, which will make appear a text editor, that allows you
 * to enter your own text item (#SetEditableFlag).
 *
 * @par Auto-completion capability
 * When the combo box is editable, the Auto-completion capability is automatically enabled 
 * with a default filtering behaviour; when the end user types some letters of a word, the combo box
 * automatically displays the items matching the current typed string in its drop-down popup, 
 * letting the end user choosing among them the expected one.
 */
class ExportedByVisuDialog CATVidCtlSimpleCombo : public CATVidCtlBaseCombo
{
  CATDeclareClass;

public:

  static CATVidCtlSimpleCombo* CreateSimpleCombo(CATCommand *i_pParent, const CATString & i_pIdentifier, CATBoolean i_editableFlag = FALSE);

  CATVidCtlSimpleCombo(CATCommand *i_pParent, const CATString & i_pIdentifier, CATBoolean i_editableFlag = FALSE);
  CATVidCtlSimpleCombo();

  /**
   * Sets a line (Label and PixelImage) at the given index, by inserting or modifying it.
   * If you set an ImageDimension, it will be used for the dimension of i_pImage.
   * If no ImageDimension have been specified, the size of i_pImage will be used.
   * Note that it can lead to odd behaviours if images on the combo don't all have the same size,
   * since it is not very well managed.
   * @return the index of the added or modified line
   */
  int SetLine(const CATUnicodeString& i_label, CATPixelImage* i_pImage = NULL, int i_index = -1, CATBoolean i_modifyFlag = FALSE, const CATUnicodeString& i_tooltipShortHelp = "", const CATUnicodeString& i_tooltipLongHelp = "", const CATUnicodeString& i_tooltipTitle = "");

  /**
   * Sets a line (Label and ResourceImage) at the given index, by inserting or modifying it.
   * You must have specified an ImageDimension (see #SetImageDimension), that will be used to display the given image i_resourceImage.
   * If you didn't, it will assert.
   * @return the index of the added or modified line
   */
  int SetLine(const CATUnicodeString& i_label, const CATUnicodeString& i_resourceImage, int i_index = -1, CATBoolean i_modifyFlag = FALSE, const CATUnicodeString& i_tooltipShortHelp = "", const CATUnicodeString& i_tooltipLongHelp = "", const CATUnicodeString& i_tooltipTitle = "");

  /**
   * Retrieves the line data (label and pixelImage) at the given index.
   */
  void GetLine(int i_index, CATUnicodeString& o_label, CATPixelImage*& o_pImage) const;

  /**
   * Adds the given lines to the combo box.
   */
  int AddItems(const CATListOfCATUnicodeString& i_strings);

  /**
  * Adds the given lines to the combo box, containing texts, images and tooltips
  */
  int AddItems(const CATListOfCATUnicodeString& i_strings, const CATListOfCATUnicodeString& i_resourceImages, const CATListOfCATUnicodeString& i_tooltipShortHelps, const CATListOfCATUnicodeString& i_tooltipLongHelps= NULL, const CATListOfCATUnicodeString& i_tooltipTitles = NULL);

  /**
   * Specifies whether the top line of the combo box can be edited by the user or not.
   * By default, the EditableFlag property is set to FALSE.
   */
   void SetEditableFlag(CATBoolean i_editableFlag);

   /**
    * Returns TRUE if the top line of the combo box can be edited by the user, FALSE otherwise.
    */
   CATBoolean GetEditableFlag() const;

  /**
   * Specifies whether the auto completion capability is enabled when the combo box is editable or not.
   * By default, the AutoCompletionEnabledFlag property is set to TRUE.
   * @see SetEditableFlag
   */
   void SetAutoCompletionEnabledFlag(CATBoolean i_autoCompletionEnabledFlag);

   /**
    * Returns TRUE if the auto completion capability is enabled when the combo box is editable, FALSE otherwise.
    */
   CATBoolean GetAutoCompletionEnabledFlag() const;

   /**
    * Returns TRUE if the auto completion capability is available for this combo box, FALSE otherwise.
    * The auto completion is available when the following conditions are fulfilled :
    *   - the EditableFlag property is set to TRUE
    *   - the AutoCompletionEnabledFlag property is set to TRUE
    *   - the Completion proxy is not NULL
    */
   CATBoolean GetAutoCompletionEnabledState() const;

  /**
   * Sets the completion proxy model to use instead of the current one in order to auto complete text input for the combo box.
   * If i_pCompletionProxy is NULL, the auto completion capability is disabled.
   * By default, for an editable combo box with the AutoCompletionEnabledFlag property set to TRUE, a CATVidMdlCompletionProxy 
   * is automatically created : this default proxy performs case insensitive completion on the entire 'Text' property value of
   * each combo box item.
   * @see GetAutoCompletionEnabledFlag
   * @see SetEditableFlag
   */
  void SetCompletionProxy(CATVidMdlCompletionProxy * i_pCompletionProxy);

  /**
   * Returns the completion proxy model that is used to auto complete text input for the combo box.
   * @c AddRef has NOT been called on the returned pointer so the caller must NOT @c Release it.
   */
  CATVidMdlCompletionProxy * GetCompletionProxy() const;

  /**
   * In case of an editable combo, this property holds the text of the top line editor.
   */
  void SetText(const CATUnicodeString& i_text);
  CATUnicodeString GetText()const;

  /**
   * Sets the placeholder text that will be displayed when no text is entered in the top line editor.
   * It disappears when text is entered. This property is only used in case of an editable combo.
   * By default, the PlaceholderText property is set to the empty string.
   */
  void SetPlaceholderText(const CATUnicodeString& i_placeholderText);

  /**
   * Returns the placeholder text that will be displayed when no text is entered in the top line editor.
   */
  CATUnicodeString GetPlaceholderText() const;

  /**
   * In case of an editable combo, this property holds the selection of the 
   * top line editor. Return E_FAIL if the top line is not editable.
   * @param i_firstCharacterIndex
   *   The first char index;
   * @param i_lastCharacterIndex
   *   The last char index;
   */
  HRESULT SetSelection(int i_firstCharacterIndex, int i_lastCharacterIndex);

  /**
   * In case of an editable combo, this property holds the selection of the 
   * top line editor. Return E_FAIL if the top line is not editable.
   * Returns selection on the editor.
   * @param o_firstCharacterIndex
   *   The first char index;
   * @param o_lastCharacterIndex
   *   The last char index;
   */
   HRESULT GetSelection(int& o_firstCharacterIndex, int& o_lastCharacterIndex) const;

  /**
   * Sets the dimension of the image used by the combo box items.
   */
  void SetImageDimension(const CATMathPoint2Df & i_dimension);
  const CATMathPoint2Df& GetImageDimension() const;

  CATISYPCollection_var GetImageAndLabelItems();

  /**
  * Retrieves the line data at the given index.
  */
  CATISYPIntrospectable_var GetLineData(int i_index) const;

  /**
  * Returns the @c TextChanged event.
  * The @c TextChanged event is emitted whenever the text of the top line editor changes.
  * Unlike TextEdited(), this event is also sent when the text is changed programmatically, 
  * for example, by calling setText().
  * @par EventProperties
  *   - Name: @c "TextChanged"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* TextChanged();

  /**
  * Returns the @c TextEdited event.
  * The @c TextEdited event is emitted whenever the text of the top line editor is interactively edited. 
  * @par EventProperties
  *   - Name: @c "TextEdited"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* TextEdited();

  /**
  * Returns the @c TextActivated event.
  * The @c TextActivated event is emitted whenever the top line editor receives the focus.
  * @par EventProperties
  *   - Name: @c "TextActivated"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* TextActivated();

  /**
  * Returns the @c EditingFinished event.
  * The @c EditingFinished event is emitted whenever the top line editor loses the focus.
  * @par EventProperties
  *   - Name: @c "EditingFinished"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* EditingFinished();

  /**
  * Returns the @c ReturnPressed event.
  * The @c ReturnPressed event is emitted whenever the Return key is pressed 
  * (the top line editor should be in focus).
  * @par EventProperties
  *   - Name: @c "ReturnPressed"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* ReturnPressed();   

  /**
   * @name CATISYPCollection implementation
   */
  /*@{*/ 
  /** @copydoc CATISYPCollection#GetAt */
  virtual CATBaseUnknown_var GetAt( int i_index );
  /** @copydoc CATISYPCollection#GetCount */
  virtual int GetCount();
  /** @copydoc CATISYPCollection#Append */
  virtual void Append( const CATBaseUnknown_var &i_spObject );
  /** @copydoc CATISYPCollection#AppendList */
  virtual void AppendList( const CATSYPConstArray<CATBaseUnknown_var> &i_list );
  /** @copydoc CATISYPCollection#Remove */
  virtual void Remove( const CATBaseUnknown_var &i_spObject );
  /** @copydoc CATISYPCollection#RemoveList */
  virtual void RemoveList( const CATSYPConstArray<CATBaseUnknown_var> &i_list );
  /** 
    * Implementation of CATISYPCollection#Clear
    * @copydoc CATVidCtlBaseCombo#Clear
    * Clears the top line too. To keep the value of the top line unchanged, use CATVidCtlBaseCombo#ClearList instead.
    */
  virtual void Clear();
  /** @copydoc CATISYPCollection#Contains */
  virtual int Contains( const CATBaseUnknown_var &i_spObject );
  /** @copydoc CATISYPCollection#Append */
  virtual void Append( const CATLISTV(CATBaseUnknown_var) &i_list );
  /*@}*/

  const CATUnicodeString& GetImplicitCollection();

protected:

  virtual ~CATVidCtlSimpleCombo();
  virtual void OnSelect();

  virtual void TemplateDataUpdated();

private:

  // Copy constructor and equal operator
  CATVidCtlSimpleCombo (CATVidCtlSimpleCombo &);
  CATVidCtlSimpleCombo& operator=(CATVidCtlSimpleCombo& original);
	CATLISTV(CATBaseUnknown_var) _Memorykeeping;//This data aim is to ensure RetrieveSypNamedObject will work on a combo after a combo clearing.
	//Which was the case before cleaning l_CATVidCtlSimpleCombo::LineCollection data.
};

#endif // CATVidCtlSimpleCombo_h
