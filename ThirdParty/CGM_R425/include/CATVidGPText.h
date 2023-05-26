// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATVidGPText.h
// Header definition of CATVidGPText
//
//===================================================================
//
//  Oct 2005  Creation: jov
//===================================================================
#ifndef CATVidGPText_H
#define CATVidGPText_H

#include <VisuDialog.h>
#include <CATVidGP.h>
#include <CATUnicodeString.h>
#include <list.h>
#include <CATVizPtrList.h>
#include <CATVidColor.h>
#include <CATFont.h>
#include <CATDlgUtility.h>
#include <CATSYPArray.h>
#include <CATVid.h>
#include <CATBoolean.h>
#include <CATVidMargin.h>
#include <CATVid.h>
#include <CATVidFontDescription.h>
#include "CATVidHyperlink.h"
#include <CATVidLanguageServices.h>
#include <CATVidHyperlink.h>
#include <CATSYPDeprecated.h>
class CATVidHyperlink;
class CATVidGPTextStyle;
class CATVidVisitor_SKIA;
class CATVidGPTextZone;
class LineAttributes;
class CATDrawRender;
class CATSYPOutputStream;
class CATSYPInputStream;
class CATVidTextStyle;
class CATVidTextUtilities;
class CATVidGPTextPrivateTester;
/**
* @ingroup VIDGP
*/
/**
* VID graphic primitive used to display multiline text, with partial attributes managment.
* It handle partial managment of underline, bold, color, font family attributes.
* 
* It is possible to add lines separately by calling #AddLine or #SetLine, or to set the full
* text with #SetText.
*
* @par String Transformation 
* If some line feeds are present in the CATUnicodeString, it will be cut
* into more than one line. Thus GetLine(i) following an AddLine could not provide
* the same CATUnicodeString.
* @par
* Furthermore, if some carriage returns are present in the string (\\r\\n), they
* will be internally transformed to sinple line feed \\n.
* 
* @par Space character managment
* If wrap mode is enabled, the GPText will cut the line just after the last word. 
* The remaining part of the text will begin at the begin of the next line, by skipping 
* all space characters before the first next word.
*
* @par Attributes managment
* Calling methods that modify attributes for full text will reset the partial settings of
* this attribute type, and set the given value as the default one.
* Inserting text at an index will automatically apply all attributes at the first character of 
* the current line to the added line.
* Adding text will automatically apply all attributes of the last character of 
* the text to the added line.
* Removing line will ensure that all attributes are correctly kept for the next lines.
* Resetting text will clear all attributes type, but will keep their default values.
*/
class ExportedByVisuDialog CATVidGPText: public CATVidGP
{
 CATDeclareClass;

public:
 /** Default Constructor, wich creates a non manipulable and with no wrap GPText*/
 CATVidGPText ();
 /**
 * Constructor.
 * @param i_useManipulatorFlag the flag that ensures that notifications will be sent.
 * @param i_wordWrapFlag the flag that controls the word wrap.
 */
 CATVidGPText (CATCommand *i_pParent, const CATString & i_pIdentifier, CATBoolean i_useManipulatorFlag, CATBoolean i_wordWrapFlag = FALSE);
 /**
 * Resets the current text, and all partial attributes, and set text with default values attributes.
 * This text can contain line feeds ('\\n'), involving new lines creation. 
 * Carriage returns + line feed ("\\r\\n") will be transformed into simple line feed.
 * @param i_text the text to assign to the widget.
 */
 void SetText( const CATUnicodeString &i_text);
 /**
 * @return the raw text, with its line feeds.
 */
 const CATUnicodeString& GetText();
 /**
 * Adds a line at the end of the text. That is adds a line feed and i_line
 * @param i_line the unicode string 
 */
 unsigned int AddLine(const CATUnicodeString& i_line);
 /**
 * Inserts a line in the text. That is adds a line and a line feed after
 * the line feed number "i_index". If i_index is upper the current line count, 
 * It will simply add the line to the end of the text, after a new line feed.
 * 
 * @par String Transformation 
 * If some line feeds are present in the CATUnicodeString, it will be cut
 * into more than one line. Thus GetLine(i) following an AddLine could not provide
 * the same CATUnicodeString.
 * @par
 * Further more, if some carriage returns are present in the string (\\r\\n), they
 * will be internally transformed to sinple line feed \\n.
 *
 * @param i_line the unicode string
 * @param i_index the line number to insert the new line. 0 for the first line, 
 *        GetLineCount() for the last.
 * @return the last line number after insertion.
 */
 unsigned int SetLine( const CATUnicodeString& i_line, unsigned int i_index );
 /**
 * Recover a line from its index.
 * @param i_index  the number of the line to recover. 
 *                 0 for the first line, GetLineCount()-1 for the last.
 * @return the line to recover.
 */
 CATUnicodeString GetLine(int i_index) const;
 /**
 * Remove the line at index i_index, that is remove the line and its ending line feed, if exisiting.
 * There will be no line feed for the last line.
 * @param i_index  the number of the line to clear. 
 *                 0 for the first line, GetLineCount()-1 for the last.
 */
 void ClearLine(unsigned int i_index);
 /**
 * Clears text and all partial attributes. Keep the default values set on it.
 */
 void Clear();
 /**
 * Removes the text located inside the given bounds.
 * Asserts if the bounds are out of the text range.
 */
 void RemoveTextFromBounds(int i_startCursorPosition, int i_endCursorPosition);
 /**
 * Inserts a text to the given cursor position
 * Asserts if i_cursorPosition is NULL.
 * If i_cursorPosition is bigger than the text length, text is happend.
 * @return the positon of a cursor at the end of the inserted texct.
 */
 int InsertText(const CATUnicodeString& i_text, int i_cursorPosition);
 /**
 * @return the number of line of the text.
 */
 int  GetLineCount() const;
 /**
 * Resets the font family of the whole text and sets the default with the given font name .
 * No test is done to check that the font name is valid.
 * @param i_fontFamilyName the font family name to apply.
 */
 void SetFontFamily(CATUnicodeString i_fontFamilyName);
 /**
 * @return the default font family name.
 */
 CATUnicodeString  GetFontFamily()const;
 /**
 * Resets the bold flag of the whole text and sets the default with the given flag.
 * @param i_bold the bold flag to apply.
 */
 void SetBold(CATBoolean i_bold);
 /**
 * @return the default bold flag.
 */
 CATBoolean GetBold() const;
 /**
 * Resets the underline flag of the whole text and sets the default with the given flag.
 * @param i_underline the underline flag to apply.
 */
 void SetUnderline(CATBoolean i_underline);
 /**
 * @return the default underline flag.
 */
 CATBoolean GetUnderline() const;
 /**
 * Resets the selected flag of the whole text and sets the default with the given flag.
 * @param  i_valuethe selected flag to apply.
 */
 void SetSelectionFlag(CATBoolean i_value);
 /**
 * @return the default selected flag.
 */
 CATBoolean GetSelectionFlag() const;
 /**
 */
 void SetHyperlink(const CATVidHyperlink& i_hyperlink);
 /**
 * 
 */
 const CATVidHyperlink& GetHyperlink() const{return _hyperlink;}
 /**
 * Resets the color of the whole text and sets the default with the given color.
 * @param i_color the color to apply.
 */
 void SetColor    (const CATVidColor& i_color); 
 /**
 * @return the default text color.
 */
 CATVidColor GetColor() const;
 /**
 * Resets the font size of the whole text and sets the default with the given font size.
 * @param  the font size to apply.
 */
 void SetFontSize(unsigned int i_fontSize);
 /**
 * @deprecated use GetFontSize instead!
 * @return the font size.
 */
 unsigned int GetFontSize() const;
 /**
 * Sets the color of the selection background.
 * @param i_color the color to apply.
 */
 void SetSelectionColor    (const CATVidColor& i_color); 
 /**
 * @return the color of the selection background.
 */
 const CATVidColor& GetSelectionColor() const;
 /**
 * Sets a color to a part of the text.
 * @param i_color the value to apply.
 * @param i_firstCharIndex the index of the first character to apply the attribute to.
 * @param i_nbChars the index of the first character to apply the attribute to.
 */
 void SetColor(const CATVidColor& i_color, unsigned int i_firstCharIndex, unsigned int i_nbChars);
 /**
 * Sets a selected state to a part of the text.
 * @param selected state the value to apply.
 * @param i_firstCharIndex the index of the first character to apply the attribute to.
 * @param i_nbChars the index of the first character to apply the attribute to.
 */
 void SetSelection(CATBoolean i_value, unsigned int i_firstCharIndex, unsigned int i_nbChars, int i_resetCurrentSelection=0);
 /**
 * Sets an Hyperlink to a part of the text.
 * @param i_firstCharIndex the index of the first character to apply the attribute to.
 * @param i_nbChars the index of the first character to apply the attribute to.
 */
 void SetHyperlink(const CATVidHyperlink& i_hyperlink, unsigned int i_firstCharIndex, unsigned int i_nbChars);

 void SetDefaultStyle(const CATVidTextStyle& i_style);
 CATVidTextStyle GetDefaultStyle() const;
 /**
 * Sets a style to a part of the text.
 * @param i_firstCharIndex the index of the first character to apply the attribute to.
 * @param i_nbChars the index of the first character to apply the attribute to.
 */
 void SetStyle(const CATVidTextStyle& i_style, unsigned int i_firstCharIndex, unsigned int i_nbChars);
 /**
 * Compute style that is applied to a text section. 
 */
 CATVidTextStyle GetStyle(unsigned int i_firstCharIndex, unsigned int i_nbChars);
 /**
 * Compute style by merging default style and overwritten style.
 */
 CATVidTextStyle GetFullStyle(unsigned int i_firstCharIndex, unsigned int i_nbChars);
 /**
 */
 void GetHyperlink(unsigned int i_firstCharIndex, unsigned int i_nbChars, CATVidHyperlink& o_hyperlink, int &o_startCursorPosition, int& o_endCursorPosition);
 /**
 * Sets a bold attribute to a part of the text.
 * @param i_bold the value to apply.
 * @param i_firstCharIndex the index of the first character to apply the attribute to.
 * @param i_nbChars the index of the first character to apply the attribute to.
 */
 void SetBold(CATBoolean i_bold, unsigned int i_firstCharIndex, unsigned int i_nbChars);
 /**
 * Sets a bold attribute to a part of the text.
 * @param i_bold the value to apply.
 * @param i_firstCharIndex the index of the first character to apply the attribute to.
 * @param i_nbChars the index of the first character to apply the attribute to.
 */
 void SetItalic(CATBoolean i_italic, unsigned int i_firstCharIndex, unsigned int i_nbChars);
 /**
 * Sets a underline attribute to a part of the text.
 * @param i_underline  value to apply.
 * @param i_firstCharIndex the index of the first character to apply the attribute to.
 * @param i_nbChars the index of the first character to apply the attribute to.
 */
 void SetUnderline(CATBoolean i_underline, unsigned int i_firstCharIndex, unsigned int i_nbChars);
 /**
 * Sets a font family name attribute to a part of the text.
 * @param i_fontFamily the value to apply.
 * @param i_firstCharIndex the index of the first character to apply the attribute to.
 * @param i_nbChars the index of the first character to apply the attribute to.
 */
 void SetFontFamily(const CATUnicodeString& i_fontFamily, unsigned int i_firstCharIndex, unsigned int i_nbChars);
 /**
 * Sets a font size to a part of the text.
 * @param i_fontSize the value to apply.
 * @param i_firstCharIndex the index of the first character to apply the attribute to.
 * @param i_nbChars the index of the first character to apply the attribute to.
 */
 void SetFontSize(int i_fontSize, unsigned int i_firstCharIndex, unsigned int i_nbChars);
 /**
 * Sets the left margin in pixel. Is taken into account in the computed minimum dimension.
 * @param i_leftMargin the left margin in pixel.
 */
 void SetLeftMargin(unsigned int i_leftMargin);
 /**
 * @return the left margin.
 */
 unsigned int GetLeftMargin() const;
 /**
 * Sets the right margin in pixel. Is taken into account in the computed minimum dimension.
 * @param i_rightMargin the right margin in pixel.
 */
 void SetRightMargin(unsigned int i_rightMargin);
 /**
 * @return the right margin.
 */
 unsigned int GetRightMargin() const;
 /**
 * Sets the top margin in pixel. Is taken into account in the computed minimum dimension.
 * @param i_topMargin the top margin in pixel.
 */
 void SetTopMargin(unsigned int i_topMargin);
 /**
 * @return the top margin.
 */
 unsigned int GetTopMargin() const;
 /**
 * Sets the bottom margin in pixel. Is taken into account in the computed minimum dimension.
 * @param i_bottomMargin the bottom margin in pixel.
 */
 void SetBottomMargin(unsigned int i_bottomMargin);
 /**
 * @return the bottom margin.
 */
 unsigned int GetBottomMargin() const;
 /** Gets the margin with one call*/
 void SetMargin(const CATVidMargin& i_margin);
 /** Gets the margin with one call*/
 const CATVidMargin& GetMargin() const;
 /**
 * Sets a alignment of the text
 *  AlignLeft   0
 *  AlignCenter 1
 *  AlignRight  2
 */
 void SetAlignment (CATVid::Alignment i_flag );
 /**
 * Returns a alignment of the text
 *  AlignLeft   0
 *  AlignCenter 1
 *  AlignRight  2
 */
 CATVid::Alignment  GetAlignment () const;
 /**
 * Sets a alignment of the text
 *  VAlignTop   0
 *  VAlignCenter 1
 *  VAlignBottom  2
 */
 void SetVerticalAlignment (CATVid::VAlignment i_flag );
 /**
 * Returns a alignment of the text
 *  VAlignTop   0
 *  VAlignCenter 1
 *  VAlignBottom  2
 */
 CATVid::VAlignment  GetVerticalAlignment () const;
 /**
 * @deprecated use SetFontSize instead.
 * Sets a cell height to a part of the text.
 * @param i_height the value to apply.
 * @param i_firstCharIndex the index of the first character to apply the attribute to.
 * @param i_nbChars the index of the first character to apply the attribute to.
 */
 SYP_DEPRECATED("Use CATVidGPText::SetFontSize instead ()")void SetHeight(int i_height, unsigned int i_firstCharIndex, unsigned int i_nbChars);
  // Set/Get crop policy
  void SetCropPolicy(CATVid::CropPolicy i_cropPolicy);
  CATVid::CropPolicy GetCropPolicy() const;
  void LimitLinesWithCrop(int i_nbLinesToShowWithCrop);

 void SetInterline(int i_interline);
 int GetInterline() const;
 int GetDeviceIndependentInterline();
 float GetScaleFactorForInterline();

 //---

private:
  int _nbLinesToShowWithCrop;
  unsigned int _cropPolicy        :2;
 CATBoolean _keyUp, _keyDown;
 CATBoolean _createParagraphOnEnterFlag;
 void SetParagraphOffset(int& yPx, int lineAttributes);
 void UpdateFirstCharInLineIndexAndlinePosYInPixel(int &firstCharInLineIndex, int &linePosYInPixel, int nbChar, int cellHeight , int pos, int lineFeedType );
public:
 void SetCreateParagraphOnEnterFlag(CATBoolean value);
 CATBoolean GetCreateParagraphOnEnterFlag();
 void SetKeyUpFlag(CATBoolean value);
 CATBoolean GetKeyUpFlag();
 void SetKeyDownFlag(CATBoolean value);
 CATBoolean GetKeyDownFlag();	
  CATBoolean Crop(int i_curLineNumber, CATVidGPTextStyle& iStyle, int iLastPrimitiveIndex, int iteratorPosition);
 //---

 // in dp (device independant pixels)
 class PickResult 
 {
 public:
  PickResult()
  {
   _overCharFlag=0;
   _firstCharInLineIndex=0;
   _lastCharInLineIndex=0;
   _currentCharIndex=0;
   _linePosition=0;
   _lineHeight=0;
   _characterOffset=0.f;
   _characterWidth = 0.f;
  }
  void SetOverCharFlag(CATBoolean i_overCharFlag){_overCharFlag=i_overCharFlag;}
  CATBoolean GetOverCharFlag() const{return _overCharFlag;}
  void SetFirstCharInLineIndex(int i_firstCharInLineIndex){_firstCharInLineIndex=i_firstCharInLineIndex;}
  int GetFirstCharInLineIndex() const{return _firstCharInLineIndex;}
  void SetLastCharInLineIndex(int i_lastCharInLineIndex){_lastCharInLineIndex=i_lastCharInLineIndex;}
  int GetLastCharInLineIndex() const{return _lastCharInLineIndex;}
  void SetCurrentCharIndex(int i_currentCharIndex){_currentCharIndex=i_currentCharIndex;}
  int GetCurrentCharIndex() const{return _currentCharIndex;}
  void SetLinePosition(int i_linePosition){_linePosition=i_linePosition;}
  int GetLinePosition() const{return _linePosition;}
  void SetLineHeight(int i_lineHeight){_lineHeight=i_lineHeight;}
  int GetLineHeight() const{return _lineHeight;}
  void SetCharacterOffset(float i_characterOffset){_characterOffset=i_characterOffset;}
  float GetCharacterOffset() const {return _characterOffset;}
  void SetCharacterWidth(float i_characterWidth){_characterWidth=i_characterWidth;}
  float GetCharacterWidth() const {return _characterWidth;}
 private:
  CATBoolean  _overCharFlag;
  int         _firstCharInLineIndex;
  int         _lastCharInLineIndex;
  int         _currentCharIndex;
  int         _linePosition;
  int         _lineHeight;
  float       _characterOffset;
  float       _characterWidth;
 };
 // in dp (device independant pixels)
 CATVidGPText::PickResult Pick(const CATMathPoint2Df& i_pickPoint);
 // in dp (device independant pixels)
 CATVidGPText::PickResult PickFromLetterIndex(int i_letterIndex);

 /**@nodoc*/
 void GetLine( CATUnicodeString& o_line, unsigned int i_index ) const;
 /**@nodoc. Use SetFontFamily*/
 void SetFont(CATUnicodeString i_fontName);
 /**@nodoc. Use GetFontFamily*/
 CATUnicodeString  GetFont()const;
 /**@nodoc*/
 void SetIntegerValue( int i_integerValue);
 /**@nodoc*/
 int  GetIntegerValue();
 /**@nodoc*/
 void SetFloatValue( float i_floatValue);
 /**@nodoc*/
 float GetFloatValue();
 /**@nodoc*/
 void SetDoubleValue( double i_doubleValue);
 /**@nodoc*/
 double GetDoubleValue();
 /**@nodoc*/
 void Empty();//use Clear.
 /**@nodoc. does nothing*/
 void SetTextColor(const CATVidColor& i_color);
 /**@nodoc. does nothing*/
 void SetItalic(CATBoolean i_italic);
 /**
 *@return the default italic flag.
 */
 CATBoolean GetItalic() const;
 /**
 * @deprecated: use SetFontSize instead of this one that sets in fact the cell height.
 * Resets the font height of the whole text and sets the default with the given cell height.
 * @param i_fontHeight the font height to apply.
 */
 SYP_DEPRECATED("Use CATVidGPText::SetFontSize instead ()") void SetFontHeight(unsigned int i_fontHeight);
 /**
 * @deprecated use GetFontSize instead!
 * @return the font height.
 */
 unsigned int GetFontHeight() const;
 /**
 * If the @c WordWrapFlag is @c TRUE, the text content wraps when it goes 
 * beyond the width of the @c CATVidGPText. On that case, the computed
 * minimum dimension is <tt>(0, textHeight)</tt>.<br/>
 *
 * The text does not wrap in two cases: 
 *
 * @li <tt>WordWrapFlag = FALSE</tt> and <tt>WordWrapThreshold = 0</tt>
 * @li <tt>WordWrapThreshold > 0</tt> and <tt>textWidth < WordWrapThreshold + WordWrapToleranceMargin</tt>
 *
 * with <tt>textWidth</tt> the length of the biggest line of the text when 
 * not wrapped. 
 *
 * @param i_wordWrapFlag the flag.
 */
 void SetWordWrapFlag(CATBoolean i_wordWrapFlag);
 /**
 * @return the wrap flag of the widget.
 */
 CATBoolean GetWordWrapFlag() const;
 /** 
 * @return The word wrap threshold.
 * @see #SetWordWrapThreshold
 */
 int GetWordWrapThreshold() const;
 /**
 * Sets a threshold for word wrapping. When <tt>WordWrapThreshold > 0</tt>, 
 * the text will not wrap as long as <br/>
 *
 * <tt>textWidth < WordWrapThreshold + WordWrapToleranceMargin </tt><br/>
 *
 * with <tt>textWidth</tt> the length of the biggest line of the text when 
 * not wrapped. If the text do not wrap, the minimum dimension of the 
 * @c CATVidGPText will be <tt>(textWidth, textHeight)</tt>. Else, it will
 * be <tt>(0, textHeight)</tt>. The text will wrap at 
 * <tt>WordWrapThreshold + ToleranceMargin</tt>
 *
 * Default value is <tt>0</tt>.
 *
 * @param i_iWidth a threshold for word wrapping.
 */
 void SetWordWrapThreshold(int i_iWidth);
 /**
 * @return the word wrap tolerance margin.
 * @see #SetWordWrapToleranceMargin
 */
 int GetWordWrapToleranceMargin() const;
 /**
 * Sets the word wrap tolerance margin. <br/>
 *
 * Default value is <tt>0</tt>.
 *
 * @param i_iToleranceMargin a tolerance margin for word wrap width.
 *
 * @see #SetWordWrapThreshold
 */
 void SetWordWrapToleranceMargin(int i_iToleranceMargin);
 /**
 * @param 
 * When the @c OptimizeMinimumDimensionFlag is up, the minimum width of
 * the @c CATVidGPText is set to: 
 * 
 * @li <tt>WordWrapThreshold + leftMargin + rightMargin</tt> in case 
 * the text must wrap and <tt>WordWrapThreshold > 0</tt>.
 * @li <tt>textWidth + leftMargin + rightMargin</tt> else, with 
 * <tt>textWidth</tt> the length of the biggest line of the unwrapped text.
 *
 * @param
 * Note that if @c OptimizeMinimumDimensionFlag is @c TRUE, @c WordWrapFlag 
 * is @c TRUE and no wrapping threshold has been defined, the text will not
 * wrap, as the minimum dimension will be set to the biggest line of the 
 * unwrapped text.
 * 
 * @see #GetOptimizeMinimumDimensionFlag
 */
 void SetOptimizeMinimumDimensionFlag(CATBoolean i_bOptimizeMinimumDimensionFlag);
 /**
 * @return @c TRUE if the minimum width is adjusted to the effective width of 
 * the text, @c FALSE else.
 * 
 * @see #SetOptimizeMinimumDimensionFlag
 */
 CATBoolean GetOptimizeMinimumDimensionFlag();
 /*
 * @return the number of lines that appear in the GPText.
 */
 int GetWrappedLinesCount() const;
 /**
 * Gets the height of a given line of the GPText. Asserts that 
 * @c i_iLineNumber is in [0, GetWrapLinesCount() - 1].
 *
 * @param i_iLineNumber the number of the line, 0 being the top line.
 *
 * @return the line height of a specific line of the GPText.
 *
 * @see GetWrappedLinesCount();
 */
 int GetWrappedLineHeight(int i_iLineNumber) const;

 /**
 * @return the current wrap policy of the widget depending on the values of
 * @c WordWrapFlag, @c WordWrapThreshold and @c WordWrapToleranceMargin. 
 */
 CATVid::WrapPolicy GetWordWrapPolicy() const;

 /**
 * @deprecated
 */
 void SetWordWrapPolicy(CATVid::WrapPolicy i_iWrapPolicy);
 /**
 * Fills an output stream with UTF-8 format XHTML 1.0 valid stream.
 * @param o_outputStream stream to be filled
 * Exports only the text contained by the two cursors if they are different of -1.
 * @see CATSYPOutputStream
 */
 void ExportInXHTML(CATSYPOutputStream& o_outputStream,int i_firstCursorPosition, int i_secondCursorPosition, CATBoolean forClipboard);

 CATUnicodeString TryParsingHTML(const CATUnicodeString& i_htmlText);
 void SetXHTML(const CATUnicodeString& i_htmlText);
 /** Inserts an XHTML formated text at cursorPosition in the GP.
 * @return the positon of a cursor at the end of the inserted texct.
 */
 int InsertXHTML(const CATUnicodeString& i_htmlText, int i_cursorPosition);
 /** Sets the new line at cursor position as a new paragraph. Asserts if the fiven index is not a newline char.*/
 void ModifyNewLineToNewParagraphAtIndex(int i_index);

 /**
 * Sets IgnoreCR flag. If the flag is set and the word wrap policy is nowrap, the text is displayed in a single line.
 * If the flag is set and wrap mode is other than NoWrap, wrapping is done as per specified policy and IgnoreCR has no effect.
 * If the IgnoreCR is not set and wrap mode is NoWrap, wrapping is done preventing the carriage returns.
 **/
 INLINE void SetIgnoreCR(CATBoolean i_bIgnoreCR){_bIgnoreCR = i_bIgnoreCR;}
 INLINE CATBoolean GetIgnoreCR(){return _bIgnoreCR;}

protected:
 virtual ~CATVidGPText ();
 CATVidGPText (CATVidGPText &);
 CATVidGPText& operator=(CATVidGPText&);
 virtual HRESULT BuildRep();
private:
 int BuildXHTML(const CATUnicodeString& i_string, int i_size, int i_simulateFlag, int i_cursorPosition, CATUnicodeString& o_text);
 friend class CATVidVisitor_SKIA;
 friend class l_CATVidGPText;
 friend class CATVidGPTextPrivateTester;

 /**
 * Internal update when the density changes.
 */
 void UpdateDensity();

 class AttributeTree
 {
 public:
  AttributeTree();
  ~AttributeTree();

  void AddTail(CATVidGPTextZone* i_pZone);
  void InsertAt(unsigned int i_key, CATVidGPTextZone* i_pZone);
  unsigned int Length()const; 
  CATVidGPTextZone* RemoveAt(unsigned int i_key);
  void Remove(CATVidGPTextZone* i_toRemove);
  void Empty();

  void InsertCharsAtPosition(int i_pos, int i_nbChars);
  void AppendChars(int i_nbChars);

  void InsertAtChar(unsigned int i_nbChar, CATVidGPTextZone* i_pZone);
  void ReplaceAtChar(unsigned int i_nbChar, CATVidGPTextZone* i_pZone);
  HRESULT GetNextZone(unsigned int i_nbChar, CATVidGPTextZone*& o_pTextZone, unsigned int& o_firstChar, unsigned int& o_index) const;
  HRESULT GetCurrentZone(unsigned int i_nbChar, CATVidGPTextZone*& o_pTextZone, unsigned int& o_firstChar, unsigned int& o_index, int i_testStrictly=1) const;
  HRESULT GetPosAndNbChars(unsigned int i_index, unsigned int& o_pos, unsigned int& o_nbChars) const;
  HRESULT GetIndexAtPosition(unsigned int i_pos, unsigned int& o_index);
  void RemoveChars(unsigned int i_pos, unsigned int i_nbChars);

  CATVidGPTextZone* operator[] (unsigned int i_index) const;

 private:
  CATVizPtrList<CATVidGPTextZone> _attributeList;
 };

private:
 CATUnicodeString ComputeTextStyleString(const CATVidGPTextStyle& i_style, 
  const CATVidGPTextStyle& i_refStyle,
  const CATBoolean considerAll) const;
 int GetLineIndexFromCursorPosition(int i_cursorPosition, unsigned int& o_firstCharInLine, CATVidGPTextZone*& o_pZone) const;
 float GetLongestSectionLength(); // in px (physical pixels)
 void ExtractInLineAttributes(const CATUnicodeString& i_line, CATVidGPText::AttributeTree& o_lineColors, CATUnicodeString& o_result);
 float ComputeWordPartDimension(const int i_index, const int i_nbChars); // in px
 int GetNextSection(int i_iteratorPos, int& o_lineFeedType, CATBoolean& o_lastLineFlag, CATVidGPTextStyle& o_style);
 int GetNextColorZone(int i_iteratorPos, CATVidColor& o_color, int& o_overwrittenFlag);
 int GetNextSelectionZone(int i_iteratorPos, CATBoolean& o_value, int& o_overwrittenFlag);
 int GetNextHyperlinkZone(int i_iteratorPos, CATVidHyperlink& o_value, int& o_overwrittenFlag);
 int GetNextWeightZone(int i_iteratorPos, CATBoolean& o_value, int& o_overwrittenFlag);
 int GetNextItalicZone(int i_iteratorPos, CATBoolean& o_value, int& o_overwrittenFlag);
 int GetNextFontSizeZone(int i_iteratorPos, int& o_value, int& o_overwrittenFlag); // in px
 int GetNextUnderlineZone(int i_iteratorPos, CATBoolean& o_value, int& o_overwrittenFlag);
 int GetNextFontFamilyZone(int i_iteratorPos, CATUnicodeString& o_value, int& o_overwrittenFlag);
 int GetNextLF(int i_iteratorPos, CATBoolean& o_paragraphFlag);
 unsigned int InternalSetLine( const CATUnicodeString& i_line, unsigned int i_index);  
 static CATBoolean TroncateAtSpaceToWidth(float i_availableWidthPx, int i_oneStandardCharacterWidth,
  CATUnicodeString& io_text, int& o_nbCharsRemoved, float& io_newWidthPx, 
  float& o_baseToTopHeightPx, const CATVidGPTextStyle& i_style, 
  const CATVidLanguageServices::BreakRules i_rules); // in px
 static CATBoolean TroncateAtFittingChracater(float i_availableWidthPx, int i_oneStandardCharacterWidth,
  CATUnicodeString& io_text, int& o_nbCharsRemoved, float& io_newWidthPx, const CATVidGPTextStyle& i_style); 
 static CATVidColor* ExtractColor(const CATUnicodeString& i_parsedColor);
 static void ExtractStringAndColor(CATUnicodeString& io_line, CATUnicodeString& o_result, CATVidColor** o_ppColor);

 void CleanRepresentation();

private:
 CATVid::Alignment _alignment;
 CATVid::VAlignment _verticalAlignment;
 CATVidColor _color;
 CATVidColor _selectionColor;
 CATVidHyperlink _hyperlink;
 CATUnicodeString _tooltip;
 CATBoolean _selectionFlag;
 CATBoolean _boldFlag;
 CATBoolean _underline;
 CATBoolean _italic;
 CATUnicodeString _fontFamily;
 CATUnicodeString _text;
 AttributeTree _lineFeeds;
 AttributeTree _selections;
 AttributeTree _colors;
 AttributeTree _weights;
 AttributeTree _underlines;
 AttributeTree _italics;
 AttributeTree _fontSizes;
 AttributeTree _fontSizesDP;
 AttributeTree _fontFamilies;
 AttributeTree _hyperlinks;

 int _mainYOffset;

 // In dp (device independant pixels)
 unsigned int _wishedTextHeightDP;
 // In dp 
 int _fontSizeDP;
 // In dp
 CATVidMargin _margin;
 // In dp
 int _interline;
 enum CATVIDGPTEXT_type {CATVIDGPTEXT_text=0, CATVIDGPTEXT_int, CATVIDGPTEXT_float, CATVIDGPTEXT_double};
 CATVIDGPTEXT_type _type;
 int _intValue;
 float _floatValue;
 double _doubleValue;
 int _maxLengthForTextPart;
 CATBoolean _bIgnoreCR;



 /**
 * When this flag is up and @c WordWrapThreshold and 
 * @c WordWrapToleranceMargin both equal <tt>0</tt>, make the words wrap at 
 * the end of the widget.
 */
 CATBoolean _wordWrapFlag;
 /**
 * The maximum width allowed for word wrapping in case the @c WordWrapPolicy
 * is @ref CATVid#Threshold or @ref CATVid#ToleranceMargin.
 */
 unsigned int _iWordWrapThreshold;
 /**
 * @c WordWrapThreshold + @c WordWrapToleranceMargin, if not <tt>0</tt>, is 
 * the maximum length allowed for a line of text before wrapping.
 */
 unsigned int _iWordWrapToleranceMargin;
 /**
 * When this flag is up, the minimum dimension is set to the width of the 
 * possibly wrapped text in the @c CATVidGPText.
 */
 CATBoolean _bOptimizeMinimumDimensionFlag;

 // For testing purposes
 friend class CATVIDTstCATVidGPTextTroncateLanguage;
};
//-----------------------------------------------------------------------------

#endif
