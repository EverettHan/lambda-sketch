// COPYRIGHT Dassault Systemes 2014
//=============================================================================
//
// CATVidLanguageServices.h
// Header definition of CATVidLanguageServices
//
//=============================================================================
//  2014  Creation: LD5
//=============================================================================
#ifndef CATVidLanguageServices_H
#define CATVidLanguageServices_H

#include <CATUnicodeString.h>
#include <CATString.h>
#include <VisuDialog.h>
#include <CATSYPDeclareEnumFactory.h>

/**
 * @ingroup VIDCore
 */
/**
 * Class for all language-related VID services. 
 */
class ExportedByVisuDialog CATVidLanguageServices
{
public:
  /** Text wrapping rules to use, classified by language. */
  enum BreakRules
  {
    /**
     * The rules to use for the current UI language as returned by
     * @c CATNlsUtilities::GetUserInterfaceLanguageName(). Will correspond to 
     * one of the following rules.
     */
    UILanguageRules,
    /** 
     * Default rules for all latin-script-based languages. Can break before any 
     * space character and after specific no-space break characters.
     */
    WesternLatinRules,
    /**
     * Basic rules for ideographic far east languages. Can break before any 
     * space character and after any ideogram.
     */
    BasicIdeographicRules,
    /**
     * Japanese rules for text wrapping. Can break:
     * @li before any space character
     * @li after any ideograph, except if said ideograph: is located after a
     * leading character; is a following character; is an overflow character.
     */
    JapaneseRules
  };

public:
  /**
	 * @return a unicode string composed of all characters that are breakable,
   * but are no space characters.
   */
  static const CATUnicodeString & GetNoSpaceBreakableChars();

  /**
   * @param i_char any unicode character
   * 
   * @return @c TRUE if the character can be breaked at after, @c FALSE else.
   */
  static CATBoolean IsNoSpaceBreakableChar(const CATUnicodeChar & i_char);
 
  /**
   * @return a string composed of all breakable characters.
   */
  static CATUnicodeString GetBreakableChars();

  /**
   * @param i_char any unicode character
   * 
   * @return @c TRUE if the character can be breaked at before (space
   * character) or after (no space), @c FALSE else.
   */
  static CATBoolean IsBreakableChar(const CATUnicodeChar & i_char);
  
  /**
   * @return a unicode string composed of all the spaces characters.
   */
  static const CATUnicodeString & GetSpaceChars();

  /**
   * @param i_char any unicode character
   * 
   * @return @c TRUE if the character is a space (no newline) character,
   * @c FALSE else.
   */
  static CATBoolean IsSpaceChar(const CATUnicodeChar & i_char);

  /**
   * @return a unicode string composed of all the characters after which an
   * input text may be broken for wrapping.
   */
  static const CATUnicodeString & GetNewlineChars();

  /**
   * @param i_char any unicode character
   * 
   * @return @c TRUE if the character is a newline character, @c FALSE else.
   */
  static CATBoolean IsNewlineChar(const CATUnicodeChar & i_char);

  /**
   * Finds the nearest cursor position where a text can be wrapped. Once a 
   * breakable character is found, break cursor will be positioned before it if
   * the breakable character is a space, after it else.
   *
   * @param Examples:
   * @li <tt>FindNextBreak("How are you?") = 3</tt>
   * @li <tt>FindNextBreak("How are you?", 4) = 7</tt>
   * @li <tt>FindNextBreak("How are you?", 8) = -1</tt>
   * @li <tt>FindNextBreak("How are you?", 8, TRUE) = 7</tt>
   * @li <tt>FindNextBreak("How are you?", 0, TRUE) = -1</tt>
   * @li <tt>FindNextBreak("hey/hey/hey") = 4</tt>
   *
   * @param i_text the text to examine
   *
   * @param i_fromCursorPos the position of the cursor from which to search;
   * @c 0 is before <tt>i_text[0]</tt>, @c 1 is between <tt>i_text[0]</tt> and
   * <tt>i_text[1]</tt>... 
   *
   * @param i_reverseDirection default value is @ FALSE; put to @c TRUE to
   * search backwards in the text, before the cursor. 
   *
   * @param i_rules the wrapping rules to use to find the next break.
   *
   * @return the nearest cursor position from @c i_cursorPos where the text can
   * be broken; <tt>-1</tt> if no breakable position has been found. 
   */
  static int FindNextBreak(const CATUnicodeString& i_text, int i_cursorPos = 0, CATBoolean i_reverseDirection = FALSE, BreakRules i_rules = UILanguageRules);

  /**
   * Finds the first character that is not a space.
   *
   * @param i_text the string to consider.
   *
   * @param i_cursorPos the position of the cursor from which to search.
   * Default value is @c 0.
   *
   * @param i_reverseDirection default value is @ FALSE; put to @c TRUE to
   * search backwards in the text, before the cursor. 
   *
   * @return the index of the next non-space character; -1 if it has not been
   * found.
   */
  static int FindNextNoSpaceChar(const CATUnicodeString& i_text, int i_cursorPos = 0, CATBoolean i_reverseDirection = FALSE);

  /**
   * Finds the first character that is a space.
   *
   * @param i_text the string to consider.
   *
   * @param i_cursorPos the position of the cursor from which to search.
   * Default value is @c 0.
   *
   * @param i_reverseDirection default value is @ FALSE; put to @c TRUE to
   * search backwards in the text, before the cursor. 
   *
   * @return the index of the next space character; -1 if it has not been
   * found.
   */
  static int FindNextSpaceChar(const CATUnicodeString& i_text, int i_cursorPos = 0, CATBoolean i_reverseDirection = FALSE);

  /**
   * Finds the first character that is a space or a newline.
   *
   * @param i_text the string to consider.
   *
   * @param i_cursorPos the position of the cursor from which to search.
   * Default value is @c 0.
   *
   * @param i_reverseDirection default value is @ FALSE; put to @c TRUE to
   * search backwards in the text, before the cursor. 
   *
   * @return the index of the next space or newline character; -1 if it has not been
   * found.
   */
  static int FindNextSpaceOrNewlineChar(const CATUnicodeString& i_text, int i_cursorPos = 0, CATBoolean i_reverseDirection = FALSE);
  /**
   * Finds the first character that is a space or a newline.
   *
   * @param i_text the string to consider.
   *
   * @param i_cursorPos the position of the cursor from which to search.
   * Default value is @c 0.
   *
   * @param i_reverseDirection default value is @ FALSE; put to @c TRUE to
   * search backwards in the text, before the cursor. 
   *
   * @return the index of the next space or newline character; -1 if it has not been
   * found.
   */
  static int FindNextSpaceOrNewlineChar(const CATUnicodeString& i_text, int i_cursorPos, CATBoolean i_reverseDirection, CATBoolean& o_newlineFlag);

  /**
   * @param i_text the string that must be wrapped.
   *
   * @param i_cursorPos any cursor position from <tt>1</tt> to
   * <tt>i_text.GetLengthInChar()-1</tt>.
   *
   * @param i_rules the wrapping rules to use to allow / disallow a break.
   *
   * @return @c TRUE if a break can be taken in the text at the input cursor
   * position, @c FALSE else.
   */
  static CATBoolean CanBreak(const CATUnicodeString& i_text, int i_cursorPos = 0, BreakRules i_rules = UILanguageRules);

  /**
   * A line of text cannot end with any leading character.
   *
   * @return a unicode string composed of all leading characters of the
   * current UI language. Empty if @ref #IsUIInFarEastLanguage is @c FALSE.
   */
  static const CATUnicodeString & GetLeadingChars(BreakRules i_rules = UILanguageRules);

  /**
   * @param i_char any unicode character
   * 
   * @return @c TRUE if the character is a leading character, @c FALSE else.
   */
  static CATBoolean IsLeadingChar(const CATUnicodeChar & i_char, BreakRules i_rules = UILanguageRules);

  /**
   * A line of text cannot begin with any following character.
   *
   * @return a unicode string composed of all leading characters of the
   * current UI language. Empty if @ref #IsUIInFarEastLanguage is @c FALSE.
   */
  static const CATUnicodeString & GetFollowingChars(BreakRules i_rules = UILanguageRules);

  /**
   * @param i_char any unicode character
   * 
   * @return @c TRUE if the character is a leading character, @c FALSE else.
   */
  static CATBoolean IsFollowingChar(const CATUnicodeChar & i_char, BreakRules i_rules = UILanguageRules);

  /**
   * Overflow characters are allowed to extend past the right or bottom margin.
   * A line of text cannot begin with them.
   *
   * @return a unicode string composed of all leading characters of the
   * current UI language. Empty if @ref #IsUIInFarEastLanguage is @c FALSE.
   */
  static const CATUnicodeString & GetOverflowChars(BreakRules i_rules = UILanguageRules);

  /**
   * @param i_char any unicode character
   * 
   * @return @c TRUE if the character is a leading character, @c FALSE else.
   */
  static CATBoolean IsOverflowChar(const CATUnicodeChar & i_char, BreakRules i_rules = UILanguageRules);

  /** 
   * @return @c TRUE if the UI is displayed in Simplified Chinese, Japanese or
   * Korean; 0 else. 
   */
  static CATBoolean IsUIInFarEastLanguage();

  /**
   * @return the break rules used for the UI, depending on the language of NLS.
   */
  static CATVidLanguageServices::BreakRules GetUIBreakRules();

  /**
   * @param i_rules any wrapping break rules.
   *
   * @return @c i_rules if different from @ref #UILanguageBreakRules, the
   * underlying break rules else.
   *
   * @see #GetUIBreakRules
   */
  static BreakRules ComputeRules(BreakRules i_rules);

  /**
   * @param i_s a text of size >= <tt>i_n</tt>.
   * @param i_n the number of characters to take into consideration to find out
   * which break rules would be better. If greater than the size of the text or <tt>-1</tt> (default),
   * the text will be fully examined.
   *
   * @return which break rule is the most adapted to the input text, depending
   * on the current UI break rules and the <tt>i_n</tt> first letters of <tt>i_s</tt>.
   *
   * @see #GetUIBreakRules 
   */
  static BreakRules GuessRules(const CATUnicodeString & i_s, int i_n = -1);

  /**
   * For debug purposes. Prints the content of a @c CATUnicodeString converted
   * into UC characters.
   */
  static void PrintUCChars(const CATUnicodeString & i_text);

  static int IsRecord();

protected:
  /**
   * Destructor. 
   *
   * @c CATVidLanguageServices contains exclusively static functions: it is not 
   * meant to be instanciated.
   */
  virtual ~CATVidLanguageServices() {}

private:

  /**
   * @param i_language the language to use, as returned by 
   * @c CATNlsUtilities::GetUserInterfaceLanguageName(). 
   *
   * @return the best matching break rules available for input language.
   * Never returns @ref #UILanguageRules. If the language is not known, returns
   * @ref #WesternLatinRules. 
   */
  static BreakRules LanguageToBreakRules(const CATString & i_language);

  /**
   * @param i_rules any wrapping break rules.
   * @param i_s an excerpt of the text to wrap.
   *
   * @return @c i_rules if different from @ref #UILanguageBreakRules, a guess on
   * which break rule is the most adapted to the excerpt text else.
   *
   * @see #GetUIBreakRules
   * @see #GuessRules
   */
  static BreakRules ComputeRules(BreakRules i_rules, const CATUnicodeString & i_s);

  /**
   * @param i_s a text to examine
   * @param i_n the number of letters to take into consideration. If greater than
   * the size of the text or <tt>-1</tt> (defaut), the text will be fully examined.
   *
   * @return the ratio of latin characters in the <tt>i_n</tt> first letters of
   * the text (the ratio is between 0 and 1)
   */
  static float GetLatinCharactersRatio(const CATUnicodeString & i_s, int i_n = -1);

  /**
   * @param i_char any character
   *
   * @return @c TRUE if the character is a latin character, @c FALSE else
   */
  static CATBoolean IsLatinCharacter(const CATUnicodeChar & i_char);

  /**
   * Constructor. 
   *
   * @c CATVidLanguageServices contains exclusively static functions: it is not 
   * meant to be instanciated.
   */
  CATVidLanguageServices() {}
  /**
   * Copy constructor. 
   *
   * @c CATVidLanguageServices contains exclusively static functions: it is not 
   * meant to be instanciated.
   */
  CATVidLanguageServices(const CATVidLanguageServices &i_original);
  /**
   * Equal operator. 
   *
   * @c CATVidLanguageServices contains exclusively static functions: it is not 
   * meant to be instanciated.
   */
  CATVidLanguageServices& operator=(const CATVidLanguageServices& i_original);

  friend class VisImmersiveDialogBehaviour;
};

CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialog, CATVidLanguageServices__BreakRules);

//-----------------------------------------------------------------------------
#endif
