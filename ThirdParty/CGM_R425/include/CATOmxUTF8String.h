#ifndef __CATOmxUTF8String_h__
#define __CATOmxUTF8String_h__

#include "CATOmxKernel.h"
#include "CATOmxPortability.h"

class CATUnicodeString;
class CATOmxKeyString;
class CATOmxTextStream;
struct CATOmxUTF8StringInternal;

/**
 * This class can be used to easily handle an utf8 string.
 * const char * arguments are supposed to represent an utf8 string.
 * If a "len" argument is set to -1 the actual length is computed using strlen().
 * CATOmxUTF8String has COW behavior.
 * @href http://osmwebdsy/wiki/index.php/CATOmxUTF8String Usage
 */
class CATOmxUTF8String
{
  CATOmxUTF8StringInternal * m_shadow;
public:
  ExportedByCATOmxKernel CATOmxUTF8String();
  ExportedByCATOmxKernel CATOmxUTF8String(const CATOmxKeyString &);
  ExportedByCATOmxKernel CATOmxUTF8String(const CATOmxTextStream &);
  ExportedByCATOmxKernel CATOmxUTF8String(const CATUnicodeString &);

  ExportedByCATOmxKernel CATOmxUTF8String(const CATOmxUTF8String &);
  ExportedByCATOmxKernel CATOmxUTF8String & operator=(const CATOmxUTF8String &);

#ifdef DS_CXX11_SUPPORT_MOVE_SEMANTIC 
  CATOmxUTF8String(CATOmxUTF8String &&);
  CATOmxUTF8String & operator=(CATOmxUTF8String &&);
#endif

  ExportedByCATOmxKernel ~CATOmxUTF8String();

#if (__cplusplus >= 202002L) // bool will be necessary only starting from C++20 (202002L).
  ExportedByCATOmxKernel bool operator==(const CATOmxUTF8String &) const;
#else
  ExportedByCATOmxKernel int operator==(const CATOmxUTF8String &) const;
  int operator!=(const CATOmxUTF8String &) const;
#endif

#if (__cplusplus >= 201103L) // Will be necessary only starting from C++20 (202002L).
    template <typename _Ty> // Called for a source type _Ty only if _Ty is a CATUnicodeString.
    typename std::enable_if<std::is_same<_Ty, CATUnicodeString>::value, bool>::type operator== (const _Ty & iVal) const 
    {
        return !StrCompare(iVal); // Optimized version
    }
#endif

  /**
   * @param iUTF8String the utf8 input string
   * @param len the string len stands for compute len
   */
  ExportedByCATOmxKernel CATOmxUTF8String(char const * iUTF8String, int len = -1);

  /**
   * Maps the provided string (same as operator=(CATOmxUTF8String(iUTF8String, len)) tought with no additional copy when move semantics is missing).
   * @param iUTF8String the string to map
   * @param len use the specified len
   */
  ExportedByCATOmxKernel void Map(char const * iUTF8String, int len = -1);

  /**
   * Maps the provided string and marks it as ASCII (same as operator=(CATOmxUTF8String(iUTF8String, len)) tought with no additional copy when move semantics is missing).
   * @param iUTF8String the string to map
   * @param len use the specified len
   */
  ExportedByCATOmxKernel void MapAscii(char const * iUTF8String, int len = -1);

  /** Reads the string content from a file. */
  ExportedByCATOmxKernel HRESULT ReadFile(CATOmxUTF8String const & iFileName);

  /** Reads the string content from a file. */
  ExportedByCATOmxKernel HRESULT ReadFile(CATUnicodeString const & iFileName);

  /**
  * Reads the string content from a file.
  * WARNING: only in this method, argument << char const * iCurrentCodePageEncodedFileName >> is assumed to be encoded in the current code page.
  */
  ExportedByCATOmxKernel HRESULT ReadFile(char const * iCurrentCodePageEncodedFileName);

  /**
   * Create an empty isolated buffer of the fixed len.
   * It replace the old steal (unsafe) pattern.
   */
  ExportedByCATOmxKernel char * CreatePayload(int len);

  /** True if string is empty. */
  int IsNull() const;

  /** Returns the utf8 string length in bytes. */
  ExportedByCATOmxKernel int length() const;

  /** Returns the internal utf8 version of the string. */
  ExportedByCATOmxKernel char const * asChar() const;
  /** Returns the internal utf8 version of the string. */
  char const * CastToCharPtr() const;
  /** Returns the internal utf8 version of the string. */
  ExportedByCATOmxKernel char const * rawMeat() const;

  /** Returns the string as a CATUnicodeString. */
  ExportedByCATOmxKernel CATUnicodeString asString() const;
  /** Returns the string as a CATUnicodeString. */
  ExportedByCATOmxKernel operator CATUnicodeString() const;

  /** Return the string as a KeyString. */
  ExportedByCATOmxKernel CATOmxKeyString asKey() const;

  /** Returns the string hash value. */
  ExportedByCATOmxKernel CATHashKey GetHashKey() const;

  /** Creates an isolated (i.e. not shared) version of this string for inplace changes. */
  ExportedByCATOmxKernel CATOmxUTF8StringInternal & isolate();
  /** Creates an isolated (i.e. not shared) version of this string for inplace changes. */
  ExportedByCATOmxKernel char * Isolate();

  /** Escapes the string and returns the number of escaped bytes. */
  ExportedByCATOmxKernel int escape(char iDelim, CATBoolean jsonEscaping = FALSE);

  /** Trims whitespace after the last \n. */
  ExportedByCATOmxKernel void trim();

  /**
   * Return the position iChar in string.
   * strchr equivalent but return offset instead of pointer.
   * Use CATOmxRegex::Search for more complex pattern.
   */
  ExportedByCATOmxKernel int FindChar(char iChar) const;
  /**
   * Return the position of any iChar in string.
   * strstr equivalent but return offset instead of pointer.
   * Use CATOmxRegex::Search for more complex pattern.
   */
  ExportedByCATOmxKernel int FindCharset(const char iChars[]) const;
  /**
   * Ascii translate.
   * Replace all occurences of ASCII iOldChar by iNewChar
   * Use CATOmxRegex::Search for more complex pattern.
   */
  ExportedByCATOmxKernel HRESULT Translate(char iOldChar, char iNewChar);
  /**
   * Ascii translate.
   * Replace all occurences of ASCII iOldChars[i] by iNewChars[i]
   * Use CATOmxRegex::Search for more complex pattern.
   */
  ExportedByCATOmxKernel HRESULT Translate(char const iOldChars[], char const iNewChars[]);

  /** Comparison function by byte content. */
  ExportedByCATOmxKernel static int StrCompare(const CATOmxUTF8String & s1, const CATOmxUTF8String & s2);

  /** Case insensitive comparison. */
  ExportedByCATOmxKernel int iCompare(const char * iStr) const;
  /** Case insensitive comparison. */
  ExportedByCATOmxKernel int iCompare(const CATOmxUTF8String & iStr) const;

  /* Returns true if this string starts with the content of iSubString. */
  bool StartsWith(CATOmxUTF8String const & iSubString) const;
  /* Returns true if this string ends with the content of iSubString. */
  bool EndsWith(CATOmxUTF8String const & iSubString) const;

  /* Returns true if this string contains only ascii characters.*/
  ExportedByCATOmxKernel bool IsAscii() const;

private:
#if (__cplusplus >= 201103L) // Will be necessary only starting from C++20 (202002L).
  ExportedByCATOmxKernel int StrCompare(const CATUnicodeString & cus) const;
#endif
  void set_with_flags(const char *iUTF8String, int len, unsigned int flags);
  ExportedByCATOmxKernel bool RangeCompare(const CATOmxUTF8String & iSubString, int iCharCountToCompare) const;
};

ExportedByCATOmxKernel CATOmxUTF8String operator+(const CATOmxUTF8String & s1, const CATOmxUTF8String & s2);
ExportedByCATOmxKernel CATOmxUTF8String operator+(const char * s1, const CATOmxUTF8String & s2);
ExportedByCATOmxKernel CATOmxUTF8String operator+(const CATOmxUTF8String & s1, const char * s2);

#ifdef DS_CXX11_SUPPORT_MOVE_SEMANTIC 
inline CATOmxUTF8String::CATOmxUTF8String(CATOmxUTF8String && iStr)
{
  m_shadow = iStr.m_shadow;
  iStr.m_shadow = NULL;
}
inline CATOmxUTF8String & CATOmxUTF8String::operator=(CATOmxUTF8String && iStr)
{
  CATOmxUTF8StringInternal * tmp = m_shadow;
  m_shadow = iStr.m_shadow;
  iStr.m_shadow = tmp;
  return *this;
}
#endif

#if (__cplusplus < 202002L) // Will NOT be necessary only starting from C++20 (202002L).
inline int CATOmxUTF8String::operator != (const CATOmxUTF8String & s) const { return !operator==(s); }
#endif
inline int CATOmxUTF8String::IsNull() const { return length() == 0; }
inline char const * CATOmxUTF8String::CastToCharPtr() const { return asChar(); }

inline bool CATOmxUTF8String::StartsWith(CATOmxUTF8String const & iSubString) const { return RangeCompare(iSubString, iSubString.length()); }
inline bool CATOmxUTF8String::EndsWith(CATOmxUTF8String const & iSubString) const { return RangeCompare(iSubString, -iSubString.length()); }

#endif
