// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATVidCtlNotepadTools.h
// Header definition of CATVidCtlNotepadTools
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Sep 2011  Creation: 3dPLM
//===================================================================
#ifndef CATVidCtlNotepadTools_H
#define CATVidCtlNotepadTools_H

#include <VisuDialog.h>
#include "CATVidCtl.h"
#include "CATUnicodeString.h"
#include "CATBaseUnknown_WR.h"
#include "CATListOfInt.h"
#include "CATVidCtlTextEditor.h"
#include "CATVidCtlSimpleCombo.h"
#include "CATVid.h"
#include "CATVidRGBA.h"
#include "CATSettingRepository.h"
#include "CATVidCtlTab.h"
#include "CATSYPHashMap.h"
#include "CATVidCtlStack.h"
#include "CATVidLayGridConstraints.h"
#include "CATVidLayLayer.h"
#include "CATVidCtlPopup.h"
#include "CATVidLayGrid.h"
#include "CATRscCatalog.h"
#include "CATMsgCatalog.h"

class CATSYPCursorEventArgs;
class CATSYPSelectionEventArgs;
/**
 * This widget provides a standard set of command buttons to be used with rich text editor.
 * <b>Role</b>:
 * A notepad tools consist of command icons (such as Bold, Italic etc). They are used to 
 * perform corresponding actions on rich text editor (see @ref CATVidCtlTextEditor).
 * Currently these tools are used by Notepad widget (see @ref CATVidCtlNotepad)
 * It pilots the editor to allow to specify a style to apply when inserting text outside
 * of the bounds of a word. @see CATVidCtlTextEditor#SetStyleForCharInsertion
 * <br>
 * @ingroup VIDControls
 */
class ExportedByVisuDialog CATVidCtlNotepadTools: public CATVidCtl
{
  CATDeclareClass;
  
public:
  /**Constructor*/
  CATVidCtlNotepadTools();
  /** Destructor */
  virtual ~CATVidCtlNotepadTools();

  /**
  * Set bold style for text 
  * @param i_BoldFlag
  * The bold style for text 
  * <br>
  * <b>Legal values</b> 
  *   <dl>
  *   <dt><tt>0</tt><dd> to have regular text 
  *   <dt><tt>1</tt><dd> to have bold text 
  * </dl>
  */
  void SetBoldFlag( const CATBoolean& i_BoldFlag);

  /**
  * @return current value of bold style for text 
  * <br>
  * <b>Legal values</b> 
  *   <dl>
  *   <dt><tt>0</tt><dd> regular style 
  *   <dt><tt>1</tt><dd> bold style 
  * </dl>
  */
  CATBoolean GetBoldFlag() const;

  /**
  * Set italic style for text 
  * @param i_ItalicFlag
  * The italic style for text 
  * <br>
  * <b>Legal values</b> 
  *   <dl>
  *   <dt><tt>0</tt><dd> to have regular text 
  *   <dt><tt>1</tt><dd> to have italic text 
  * </dl>
  */
  void SetItalicFlag( const CATBoolean& i_ItalicFlag);

  /**
  * @return current value of italic style for text 
  * <br>
  * <b>Legal values</b> 
  *   <dl>
  *   <dt><tt>0</tt><dd> regular style 
  *   <dt><tt>1</tt><dd> Italic style 
  * </dl>
  */
  CATBoolean GetItalicFlag() const;
  
  void SetUnderlineFlag( const CATBoolean& i_UnderlineFlag);
  CATBoolean GetUnderlineFlag() const;

  void SetStyleCopyState( const CATBoolean& i_StateFlag);
  CATBoolean GetStyleCopyState() const;
  
  CATBoolean GetCanPaste(); // const -- can't be const as GetMotifDialog is not const :(
  CATBoolean GetSelectionPresent() const;
  
  /**
   * Set text color
   * @param i_TextColor
   * Color of the text (see @ref CATVidRGBA)
   */
  void SetTextColor( const CATVidRGBA& i_TextColor);
  /**
   * @return currect text color (see @ref CATVidRGBA)
   */
  CATVidRGBA GetTextColor() const;

  /**
   * Sets text height for selected text.
   * @param i_FontHeight
   * Font height for text
   */
  void SetFontHeight( CATUnicodeString& i_FontHeight);
  /**
   * @return current value of font height 
   */
  CATUnicodeString GetFontHeight() const;

  /**
   * Sets text editor
   * @param i_pTextEditor
   * The rich text editor component
   */
  void SetTextEditor(CATVidCtlTextEditor* i_pTextEditor);
  /**
   * @return current text editor
   */
  CATVidCtlTextEditor* GetTextEditor() const;

  /**
   * Sets text font for selected text
   * @param i_FontFamily
   * Font family name for text
   */
  void SetFontName( CATUnicodeString& i_FontName);

   /**
   * @return  text font name
   */
  const CATUnicodeString& GetFontName();

  /**
  * Tooltip management
  */

  /*
  * Font Name and Font Size combos shall be available if FontNameAndSizeCombosVisibilityFlag is set to TRUE. 
  * The default value of the FontNameAndSizeCombosVisibilityFlag is FALSE.
  */
  void SetFontNameAndSizeCombosVisibilityFlag(const CATBoolean& i_FontNameAndSizeCombosVisibilityFlag = FALSE);
  
  /**
  * Sets color for editor's background
  * @param i_backgroundColor
  * color of the editor background
  */
  void SetBackgroundColor( const CATVidRGBA& i_BackgroundColor);

	
	private:
	
	void OnClickSpecialCharacterCB(CATBaseUnknown * i_pSender, CATSYPCursorEventArgs* i_pArgs);
	CATVidLayGrid* AddSpecialCharactersToGrid(CATVidLayGrid *pGrid);
  void AddSpecialCharacterToMap(CATUnicodeString i_SpecialCharacter);		
  void RemoveSpecialCharacterFromMap(CATUnicodeString i_SpecialCharacter);
	void UpdateFavourites(int numberOfSpecialCharacter);		
	void AddSpecialCharacterToFavourites(CATUnicodeString i_SpecialCharacter);
	void WriteSpecialCharacterToRepository();
	void ReadSpecialCharacterFromRepository();
	void CopyMap(CATSYPHashMap<CATUnicodeString, int> *Source, CATSYPHashMap<CATUnicodeString, int> *Destination);
	CATVidLayGrid* AddFavouritesToGrid(CATVidLayGrid *pGrid);
	void InitializeSpecialCharacter();
	const char* GetKey();
	void AddSpecialCharacterNlsAPI();

	public:	
	CATUnicodeString GetSpecialCharacterTooltip();
  CATBoolean GetFontNameAndSizeCombosVisibilityFlag();
  CATUnicodeString GetBoldChkBTooltip();
  CATUnicodeString GetItalicChkBTooltip();
  CATUnicodeString GetUnderlineChkBTooltip();
  CATUnicodeString GetFontHtUpBtnTooltip();
  CATUnicodeString GetFontHtDownBtnTooltip();
  CATUnicodeString GetTextColorBtnTooltip();
  CATUnicodeString GetStyleCopyChkBtnTooltip();
  CATUnicodeString GetCutBtnTooltip();
  CATUnicodeString GetCopyBtnTooltip();
  CATUnicodeString GetPasteBtnTooltip();
  CATUnicodeString GetAlignLeftBtnTooltip();
  CATUnicodeString GetAlignRightBtnTooltip();
  CATUnicodeString GetAlignCenterBtnTooltip();
  CATUnicodeString GetBackgroundColorBtnTooltip();
  const CATVidRGBA& GetBackgroundColor();

	void DisplaySpecialCharacterPopup(const CATUnicodeString &i_eventName, const CATBaseUnknown_var &i_input, CATBaseUnknown_var &o_output);
  void IncreaseFontHeight(const CATUnicodeString &i_eventName, const CATBaseUnknown_var &i_input, CATBaseUnknown_var &o_output);
  void DecreaseFontHeight(const CATUnicodeString &i_eventName, const CATBaseUnknown_var &i_input, CATBaseUnknown_var &o_output);
  void DoCut(const CATUnicodeString &i_eventName, const CATBaseUnknown_var &i_input, CATBaseUnknown_var &o_output);
  void DoCopy(const CATUnicodeString &i_eventName, const CATBaseUnknown_var &i_input, CATBaseUnknown_var &o_output);
  void DoPaste(const CATUnicodeString &i_eventName, const CATBaseUnknown_var &i_input, CATBaseUnknown_var &o_output);
  void FontNameCB(const CATUnicodeString &i_eventName, const CATBaseUnknown_var &i_input, CATBaseUnknown_var &o_output);
  void FontHeightCB(const CATUnicodeString &i_eventName, const CATBaseUnknown_var &i_input, CATBaseUnknown_var &o_output);
  void AlignLeftCB(const CATUnicodeString &i_eventName, const CATBaseUnknown_var &i_input, CATBaseUnknown_var &o_output);
  void AlignCenterCB(const CATUnicodeString &i_eventName, const CATBaseUnknown_var &i_input, CATBaseUnknown_var &o_output);
  void AlignRightCB(const CATUnicodeString &i_eventName, const CATBaseUnknown_var &i_input, CATBaseUnknown_var &o_output);
  
  void SetAlignment(CATVid::Alignment iAlignment);
  CATVid::Alignment GetAlignment();
  
  CATVidCtlSimpleCombo* _pFontHeightCombo;
  CATVidCtlSimpleCombo* _pFontNameCombo; 
  
protected:
     virtual void TemplateDataUpdated();
 
private:
  void UpdateEditor(const CATVidTextStyle &i_TextStyle);
  void UpdateToolbar(CATBaseUnknown * i_pSender, CATSYPCursorEventArgs* i_pArgs);
  void UpdateToolbarOnSelection(CATBaseUnknown * i_pSender, CATSYPSelectionEventArgs* i_pArgs);   
  void UpdateOnRelease(CATBaseUnknown * i_pSender, CATSYPSelectionEventArgs* i_pArgs);

  CATBoolean _styleCopyState;
  CATVidTextStyle _charStyle;
  CATVidRGBA _backgroundColor;
  CATVid::Alignment _alignment;

  void GetCursorPositionAndAnchor();
  void UpdateOnComboPreDropDownCB(CATBaseUnknown * i_pSender, CATSYPSelectionEventArgs* i_pArgs);
  void UpdateOnComboCloseCB(CATBaseUnknown * i_pSender, CATSYPSelectionEventArgs* i_pArgs);
  void UpdateOnEditingFinishedCB(CATBaseUnknown * i_pSender, CATSYPSelectionEventArgs* i_pArgs);
  void KeepFocusAndSelection();
  int _cursorPosition, _cursorAnchor;

  CATSYPHashMap<CATUnicodeString, int> *_clickCountMap;
  CATSYPDynArray<CATUnicodeString> *_favourites;
  CATVidCtlPopup *_pSpecialCharacterPopup;
  CATBoolean _initializeSpecialCharacterFlag;

  int _updatingToolbar;

  CATBaseUnknown_WR _textEditor;
  CATListOfInt _fontHeights;
  CATBoolean _FontNameAndSizeCombosVisibilityFlag;

  // Copy constructor and assignment operator
  // ----------------------------------------
  CATVidCtlNotepadTools (CATVidCtlNotepadTools &);
  CATVidCtlNotepadTools& operator=(CATVidCtlNotepadTools&);
};
//-----------------------------------------------------------------------

#endif
