// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATVidPrivateTextUtilities.h
// Header definition of CATVidPrivateTextUtilities
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Feb 09  Creation: TUV
//===================================================================
#ifndef CATVidPrivateTextUtilities_H
#define CATVidPrivateTextUtilities_H

#include <CATUnicodeString.h>
#include <CATListOfCATUnicodeString.h>
#include <CATListOfInt.h>
#include <CATVizPtrList.h>
#include <VisuDialog.h>
#include <CATVidTextSelection.h>
#include <CATFreeType.h>
#include <CATSYPArray.h>
#include <CATVidFontDescription.h>
#include <CATSYPHashMap.h>

class CATVidTextStyle;
class CATFreeTypeTextGP;
class CATMathPoint2Df;
class CATListValCATUnicodeString;
class CATVidColor;
class CATFreeTypeTextFormat;
class CATVidFontDescription;
class CATDlgBlackBox;

/*
 *
 * Class CATVidTextureCreator
 *
 */
  class CATVidCharacterFontData
  {
  public:
    CATVidCharacterFontData()
    { 
      _fontHeight = 0;
      _fontFullHeight = 0;
      _fontDescent = 0;
      _fontTopHeight = 0;
      _fontCapHeight = 0;
    }
    CATVidCharacterFontData(int i_fontHeight,int i_fontFullHeight,int i_fontDescent, int i_fontTopHeight,int i_fontCapHeight)
    {
      _fontHeight = i_fontHeight;
      _fontFullHeight = i_fontFullHeight;
      _fontDescent = i_fontDescent;
      _fontTopHeight = i_fontTopHeight;
      _fontCapHeight = i_fontCapHeight;
    }
    CATVidCharacterFontData(const CATVidCharacterFontData& i_data)
    {
      _fontHeight = i_data._fontHeight;
      _fontFullHeight = i_data._fontFullHeight;
      _fontDescent = i_data._fontDescent;
      _fontTopHeight = i_data._fontTopHeight;
      _fontCapHeight = i_data._fontCapHeight;
    }
    const CATVidCharacterFontData& operator=(const CATVidCharacterFontData& i_data)
    {
      _fontHeight = i_data._fontHeight;
      _fontFullHeight = i_data._fontFullHeight;
      _fontDescent = i_data._fontDescent;
      _fontTopHeight = i_data._fontTopHeight;
      _fontCapHeight = i_data._fontCapHeight;
      return *this;
    }
    void Get(int& o_fontHeight,int& o_fontFullHeight,int& o_fontDescent, int& o_fontTopHeight,int& o_fontCapHeight)const
    {
      o_fontHeight = _fontHeight;
      o_fontFullHeight = _fontFullHeight;
      o_fontDescent = _fontDescent;
      o_fontTopHeight = _fontTopHeight;
      o_fontCapHeight = _fontCapHeight;
    }
  private:
    int _fontHeight;
    int _fontFullHeight;
    int _fontDescent;
    int _fontTopHeight;
    int _fontCapHeight;
  };

class ExportedByVisuDialog CATVidPrivateTextUtilities
{
public:
  static CATUnicodeString GetDefaultCIDFont();
  static CATUnicodeString GetDefaultSystemFont();

  static void GetCharacterFontInfo(int i_annotationType, int i_wishedCellHeight, int& o_cellHeight, int& o_ascender, int& o_fontSize, int& o_descender);

  static void GetFontMetrics(const CATUnicodeString& i_family, int i_boldFlag, int i_italicFlag, int i_fontSize, int& o_cellHeight,int& o_ascent, int& o_descent);
  static void GetFontMetrics(const CATVidFontDescription& i_fontDescription, int& o_cellHeight,int& o_ascent, int& o_descent);
  /**
   * Gets the cell height of a font from its font size.
   * @param i_fontSize the size of the font, i.e "cap height + descent"
   * @return the cell height, (that is "line height-external leading", or "ascent+descent", or "fontSize+internal leading"...)
   */
  static int GetCellHeightFromFontSize(const CATUnicodeString& i_family, int i_boldFlag, int i_italicFlag, int i_fontSize);
  /**
   * Gets the cell height (that is "line height-external leading", or "ascent+descent", or "fontSize+internal leading"...) of a font from a font description.
   */
  static int GetCellHeightFromFontDescription(const CATVidFontDescription& i_fontDescription);
  /**
   * Gets the size of a font from its cell height (that is "line height-external leading", or "ascent+descent", or "fontSize+internal leading"...).
   * @param i_cellHeight the cell height
   * @return  the size of the font, i.e "cap height + descent"
   */
  static int GetFontSizeFromCellHeight(const CATUnicodeString& i_family, int i_boldFlag, int i_italicFlag, int i_cellHeight);

  static void GetStringSize(const CATUnicodeString& i_string, const CATVidFontDescription& i_fontDescription, float& o_width, float& o_height);

  static void GetStringCropData(const CATUnicodeString& i_string, const CATVidFontDescription& i_fontDescription, float i_widthToFit, int& o_nbFittingCharacters, float& o_fittingWidth, float& o_fittingHeight);

  static CATFreeTypeTextGP* BuildTextGP(const CATMathPoint2Df& i_topLeftCorner, const CATUnicodeString& i_text, const CATVidFontDescription& i_fontDescription);

#ifdef VISU_ENABLE_FREETYPE
  // Returns the text format from the style
  static CATFreeTypeTextFormat* GetFreeTypeFormatFromStyle(CATVidTextStyle const& ipStyle);
  static CATFreeTypeTextFormat* GetFreeTypeFormat(CATUnicodeString const& iFamilyName, int iFontHeight, CATBoolean iBold, CATBoolean iItalic);
  static CATFreeTypeTextFormat* GetFreeTypeFormat(const CATVidFontDescription& i_fontDescription);
#endif

  // Returns list of supported FONTS
  static void GetSupportedFontList(CATListValCATUnicodeString & oSupportedFontList, bool iIncludeStrokeFonts = false);
  // Splits the string based on the given splitter
  static void GetSplittedString(const CATUnicodeString &i_String,const CATUnicodeString &i_SplitterString,CATVizPtrList <CATUnicodeString> &io_lineList,CATBoolean i_bAddSeparatorAsString /*= FALSE*/);
  // Returns the words in the given string
  static void GetWords(CATUnicodeString &i_String,CATUnicodeString &i_SplitterString,CATVizPtrList <CATUnicodeString> &io_lineList);
  // Checks if the given font is available 
  static CATBoolean  IsFontAvailable(CATUnicodeString& i_strName, bool iSearchStrokeFonts = false);
  // Returns the default font
  static CATUnicodeString GetDefaultFont();
  // Cleans the given list by deleting the objects inside
  static void CleanList(CATVizPtrList<CATUnicodeString> & i_wordCharList);
  // For parsing of color tag
  static void ExtractStringAndColor(CATUnicodeString& io_line, CATVizPtrList <CATUnicodeString> &io_lineList,CATVizPtrList<CATVidColor> &o_ListColor);
  // To copy text to Clipboard
  
  static void GetLineInfoForCharIndex(int i_charIndex,
                                                const CATUnicodeString& iStrText,
                                                int& o_lineStCursor,
                                                int& o_lineEndCursor,
                                                int& o_nextLineStartCursor, 
                                                int& o_previousLineEndCursor);

  static void GetWordInfoForCharIndex(int i_charIndex,
                                                const CATUnicodeString& iStrText,
                                                int& o_WordStCursor,
                                                int& o_WordEnCursor);

  /**
   * Compute the boundaries of a word of a string for a given char index.
   * If the index is a not a space or a new line, o_WordStCursor is the cursor position
   * in front of the word, and o_WordEnCursor is the cursor position just after the word.
   * o_nextWordStartCursor is the next first word character, or the next new line or the end of the text.
   * o_previousWordEndCursor can be the cursor position after the previous word or the previous new line, or 
   * 0, for the begin of the text.
   * If the index is a new line character, the boundaries are just around it.
   * If the index is a space, the previous word is recovered, or the previous new line.
   */
  static void GetWordInfoForCharIndex(int i_charIndex,
                                                const CATUnicodeString& iStrText,
                                                int& o_WordStCursor,
                                                int& o_WordEnCursor, 
                                                int& o_nextWordStartCursor, 
                                                int& o_previousWordEndCursor);

  static void RemoveCRs(CATUnicodeString& io_text);

#if defined(_WINDOWS_SOURCE)
  // To get HGLOBAL handle from CATUnicodeString.
  // Used to populate an IDataObject object (OLE related).
  static HANDLE CovertStringToHandle(const CATUnicodeString& i_text);
#endif

static int CompareCATUnicodeStrings(CATUnicodeString* ipS1, CATUnicodeString* ipS2); 
static void ReverseString(CATUnicodeString& io_string);
/** Don't use this method, use GetFontSizeFromCellHeight, that allow to allign font height with those of Tahoma.*/
static int ComputeFontSizeFromCellHeight(const CATUnicodeString& i_family, int i_boldFlag, int i_italicFlag, int i_cellHeight);

private:
  CATVidPrivateTextUtilities();
  ~CATVidPrivateTextUtilities();
  static void   RetrieveFontInformation();
  static CATVidColor* ExtractColor(const CATUnicodeString& i_s_parsedColor);

  /** Called by CATVidSessionCleaner at the end of the application*/
  static void CleanPrivateTextUtilitiesOnExit();
  friend class CATVidSessionCleaner;

  static CATListValCATUnicodeString  *_s_pFontNameList;
  static CATListValCATUnicodeString  *_s_pFontRegularList;
  static CATListValCATUnicodeString  *_s_pFontBoldVersion;
  static CATListValCATUnicodeString  *_s_pFontItalicVersion;
  static CATListValCATUnicodeString  *_s_pFontBoldItalicVersion;
  static CATListValCATUnicodeString  *_s_pStrokeFontNameList;
  static CATListValCATUnicodeString  *_s_pStrokeFontRegularList;
  static CATListValCATUnicodeString  *_s_pStrokeFontBoldVersion;
  static CATListValCATUnicodeString  *_s_pStrokeFontItalicVersion;
  static CATListValCATUnicodeString  *_s_pStrokeFontBoldItalicVersion;
  static CATUnicodeString            _s_strFont;

  static CATSYPHashMap<CATVidFontDescription, CATFreeTypeTextFormat*> _freeTypeFontSizeFormatMap;
  static CATSYPHashMap<CATVidFontDescription, CATFreeTypeTextFormat*> _freeTypeCellHeightFormatMap;
};
#endif
