#ifndef __CATOmxRegex_h___
#define __CATOmxRegex_h___
/**
 * @level Private
 * @usage U1
 * COPYRIGHT DASSAULT SYSTEMES 2011
 * Status: production 
 * API Stability: unstable
 */
#include "CATOmxKernel.h"

#include "CATOmxPortability.h"
#include "CATOmxArray.h"
#include "CATOmxDefaultCollecManager.h"

class CATOmxUTF8String;
template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmxUTF8String>::manager();
struct CATOmxRegexInternal;
class CATOmxRegexFunctor;
/**
 * Compilation error context.
 */
struct CATOmxRegexError {
  /** the pattern that fail. */
  const char *m_pattern;
  /** a pointer inside the pattern. */
  const char *m_near;
  /** error description. */
  const char *m_error;
  /** complementary context. */
  char m_expected_char;
  /** return 1 if successfully compiled. */
  operator int() const { return m_error == 0; }
};

/** replace the '\\' by '/' usefull for c++ regex*/
#define OMXRE_USESLASH_FOR_ESCAPE 0x1

/**
 * usage 
 * CATOmxRegex x; 
 * CATAssert(x.Compile("`(/w+)`#(/d+)@`(/S+)`", OMXRE_USESLASH_FOR_ESCAPE) );
 * CATAssert(x.Match("`Foo`#1@`Albator.feat`));
 * CATAssert(x.GroupCount() == 3 )
 * CATAssert( x.Group(1) == "Foo" );
 * CATAssert( x.Group(2) == "1" );
 * CATAssert( x.Group(3) == "Albator.feat" );
 * CATAssert( x.Group(0) == "`Foo`#1@`Albator.feat`" ); // this is a match
 * 
 */
class ExportedByCATOmxKernel CATOmxRegex {
  friend class CATOmxRegexIter;

  CATOmxRegexInternal *re;
  CATOmxRegex(const CATOmxRegex&);
  CATOmxRegex&operator=(const CATOmxRegex&);
public:
  CATOmxRegex() { re=0; }
  ~CATOmxRegex();
  /**
  * Compile a regular expression. 
  * Returns an error structure containing information about a potential failure. Note that this structure can be cast as an integer, the result of the cast is 1 if the compilation is successfull, 0 otherwise.
  * Lazy (non-greedy) match (*? and +?) are NOT supported.
  * @param iPattern [in]
  *   The regular expression. 
  * @param iFlags [in]
  *   - no flags (i.e. 0)         : the escape character is the backslash \
  *   - OMXRE_USESLASH_FOR_ESCAPE : the escape character is the slash / (default)
  */
  CATOmxRegexError Compile(const CATOmxUTF8String &iPattern,unsigned int iFlags=OMXRE_USESLASH_FOR_ESCAPE);
  /**
  * Check if the input text matches the regular expression. 
  * Note that the whole text needs to match the regular expression. If you need to match a part of the input text, check the search function.
  * @param iText [in]
  *   Input text to match. 
  */
  CATBoolean Match(const CATOmxUTF8String &iText);
  /**
  * Check if a part of the input text matches the regular expression.
  * @param iText [in]
  *   Input text to search. 
  */
  CATBoolean Search(const CATOmxUTF8String &iText);
  /**
  * Basic substitution function. 
  * Allows to substitute the part of the input text matching a regular expression by another text.
  * @param iSub [in]
  *   Input text to substitute (may contains \1, \2, ..., \9 to retrieve capture groups).
  * @param iText [in]
  *   Input text to search. 
  * @param oText [out]
  *   Output text (may be the same as iText). 
  * @param iMaxSubstitutions [in]
  *   Number of max substitutions. Any value >= -1 are authorized values (-1 means all matches will be replaced). 
  */
  int Sub(const CATOmxUTF8String &iSub, const CATOmxUTF8String &iText, CATOmxUTF8String &oText, int iMaxSubstitutions);
  /**
  *  Substitution function with your own substitution function.
  *  @param iSubFunctor [in]
  *    The substitution functor allows you to specialize the substitution you need to perform on the input text.
  *    See CATOmxRegexFunctor for more information.
  *  @param iText [in]
  *    The input text
  *  @param oText [out]
  *    The output text (may be the same as iText). 
  **/
  void Substitute(CATOmxRegexFunctor & iSubFunctor, const CATOmxUTF8String & iText, CATOmxUTF8String & oText);
  /**
  * Split an input text in differents parts. Parts are separated by the input iSeparator. 
  * Note that if you want the input separator to be either the escape character (i.e. / or \) or the closing square bracket, you will need to escape it.
  * @param iText [in]
  *  The input text to split.
  * @param iSeparator [in]
  *   The input separator. 
  * @param oMatchTab [out]
  *   The output string array. 
  **/
  HRESULT Split(const CATOmxUTF8String &iText, const CATOmxUTF8String &iSeparator, CATOmxArray<CATOmxUTF8String>& oMatchTab);
  /**
  * Returns the number of matched group. 
  */
  int GroupCount() const;
  /** 
   * Returns a capture group.
   * Group(0) is the full capture string.
   **/
  const CATOmxUTF8String &Group(int n) const;
};


#endif
