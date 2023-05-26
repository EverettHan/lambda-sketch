#ifndef CATVidCtlImageAndLabelCombo_h
#define CATVidCtlImageAndLabelCombo_h

// COPYRIGHT Dassault Systemes 2005

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

/**
 * @ingroup VIDControls
 * 
 * @deprecated This class is deprecated ; use the CATVidCtlSimpleCombo class instead.
 */
class ExportedByVisuDialog CATVidCtlImageAndLabelCombo: public CATVidCtlBaseCombo
{
  CATDeclareClass;

public:

  static CATVidCtlImageAndLabelCombo* CreateImageAndLabelCombo(CATCommand *i_pParent, const CATString & i_pIdentifier);

  CATVidCtlImageAndLabelCombo(CATCommand *i_pParent, const CATString & i_pIdentifier, CATBoolean i_editableFlag = FALSE, CATDlgStyle i_editorStyle = NULL);
  CATVidCtlImageAndLabelCombo();

  /**
   * Sets a line (Label and PixelImage) to the given index, by inserting or modifying it.
   * If you set an ImageDimension, it will be used for the dimension of i_pImage.
   * If no ImageDimension have been specified, the size of i_pImage will be used.
   * Note that it can lead to odd behaviours if images on the combo don't all have the same size,
   * since it is not very well managed.
   * @return the index of the added or modified line
   */
  int SetLine(const CATUnicodeString& i_label, CATPixelImage* i_pImage = NULL, int i_index = -1, CATBoolean i_modifyFlag = FALSE);

  /**
   * Sets a line (Label and ResourceImage) to the given index, by inserting or modifying it.
   * You must have specified an ImageDimension (see #SetImageDimension), that will be used to display the given image i_resourceImage.
   * If you didn't, it will assert.
   * @return the index of the added or modified line
   */
  int SetLine(const CATUnicodeString& i_label, const CATUnicodeString& i_resourceImage, int i_index = -1, CATBoolean i_modifyFlag = FALSE);

  /**
   * Retrieves the line data (label and pixelImage) at the given index.
   */
  void GetLine(int i_index, CATUnicodeString& o_label, CATPixelImage*& o_pImage) const;

  int AddItems(const CATListOfCATUnicodeString& i_strings);

  /**
   * This property set the editability of the top line of the combo.
   */
   void SetEditableFlag(CATBoolean i_editableFlag);
   CATBoolean GetEditableFlag() const;

  /**
   * In case of an editable combo, this property holds the text of the top line editor.
   */
  void SetText(const CATUnicodeString& i_text);
  CATUnicodeString GetText() const;

  void SetImageDimension( const CATMathPoint2Df & i_dimension);
  const CATMathPoint2Df& GetImageDimension() const;

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
   * In case of an editable combo, this property holds the send of a 
   * notification when the keyboard is used.
   * Call GetKeybdEntry to recover the last keyboard entry.
   */
  void SetTextSearchEnableFlag(CATBoolean i_textSearchEnableFlag);
  CATBoolean GetTextSearchEnableFlag();

  /**
   * In case of an editable combo, return the last keyboard entry.
   */
  const CATUnicodeString& GetKeybdEntry() const;

  /**
   * Removes the item at the given index from the combobox. This will update the current index if the index is removed.
   * virtual from CATVidCtlBaseCombo   
   */
  virtual void ClearLine(int i_index);

  CATISYPCollection_var GetImageAndLabelItems();

  /**
   * Returns the event notification sent whenever the keyboard entry is modified by editing.
   */
  CATNotification *GetEditKeybdEntryNotification() const;

  /**
   * Returns the event notification sent whenever the editable top line is modified.
   */
  CATNotification *GetEditModifyNotification() const;

  /**
   * @name CATISYPCollection implementation
   */
  /*@{*/ 
	/** @copydoc CATISYPCollection#GetAt */
	virtual CATBaseUnknown_var GetAt(int i_index);
	/** @copydoc CATISYPCollection#GetCount */
	virtual int GetCount();
	/** @copydoc CATISYPCollection#Append */
	virtual void Append(const CATBaseUnknown_var &i_spObject);
	/** @copydoc CATISYPCollection#AppendList */
	virtual void AppendList(const CATSYPConstArray<CATBaseUnknown_var> &i_list);
	/** @copydoc CATISYPCollection#Remove */
	virtual void Remove(const CATBaseUnknown_var &i_spObject);
	/** @copydoc CATISYPCollection#RemoveList */
	virtual void RemoveList(const CATSYPConstArray<CATBaseUnknown_var> &i_list);
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

  virtual ~CATVidCtlImageAndLabelCombo();
  virtual void OnSelect();

private:

  // Copy constructor and equal operator
  CATVidCtlImageAndLabelCombo (CATVidCtlImageAndLabelCombo &);
  CATVidCtlImageAndLabelCombo& operator=(CATVidCtlImageAndLabelCombo& original);

  void _ClearTopLine();

  void OnEditCB(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData);
  void OnEditKeybdEntryNotificationCB(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData);
  CATVidWidget* CreateLine(const CATUnicodeString& i_label, CATPixelImage* i_pImage, CATBoolean i_editableFlag = FALSE, CATDlgStyle i_editorStyle = NULL);
  void BuildImageAndLabelCombo(CATBoolean i_editableFlag, CATDlgStyle i_editorStyle);

  CATUnicodeString _text;
  CATDlgStyle _editorStyle;
  CATMathPoint2Df _imageDimension;
  CATBoolean _editableFlag;
  CATBoolean _textSearchEnableFlag;
  CATLISTV(CATBaseUnknown_var) LineCollection;
};

#endif // CATVidCtlImageAndLabelCombo_h
