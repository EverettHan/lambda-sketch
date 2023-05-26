// COPYRIGHT DASSAULT SYSTEMES 2002
//=============================================================================
//
// CATCDSString:
//   Comfortable class string with create-on-demand and copy-on-write technics.
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  Jul 2002  Creation                         Vladislav Kornienkoint
//=============================================================================

#ifndef CATCDSString_h
#define CATCDSString_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

#include "CATCDSUtilities.h"
#include "CATCDSBoolean.h"
#include "CATCDSArray.h"
#include "CATCDSListP.h"
#include "CATCDSDebug.h"
#include "CATCDSDeprecated.h"
#include "CATCDSArray.h"

#include "CATCDSDataType.h"

#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
#ifndef _EMSCRIPTEN_SOURCE
#include <iostream.h>
#else
#include <iostream>
using namespace std;
#endif
#endif

#if defined(_WINDOWS_SOURCE) || defined(_LINUX_SOURCE) ||  defined(_DARWIN_SOURCE) && defined(CATIAR420) || defined(__ibmxl__)
#include <string>
#endif

class ExportedByCATCDSUtilities CATCDSString {
  public:
    CATCDS_DEPRECATED("13/05/2016", "Please do not use empty() but CATCDSString().", static CATCDSString const empty() { return CATCDSString(); })

    struct str_t {
      char* _data;
      size_t _length;
      size_t _capacity;
    };

    CATCDSString();
    CATCDSString(const CATCDSString& S);
    CATCDSString(const CATCDSString& S, size_t n);
    CATCDSString(const char*         s);
    CATCDSString(const char*         s, size_t n);
    CATCDSString(char                c);
    CATCDSString(int                 i);
    CATCDSString(long                i);
    CATCDSString(long long           i);    
    CATCDSString(unsigned int        i);
    CATCDSString(unsigned long       i);
    CATCDSString(unsigned long long  i);
    CATCDSString(double              r, size_t w = 17);

#if defined(_WINDOWS_SOURCE) || defined(_LINUX_SOURCE) ||  defined(_DARWIN_SOURCE) && defined(CATIAR420) || defined(__ibmxl__)
    CATCDSString(std::string const &iS);
#endif

    CATCDSString(const str_t& str);

    ~CATCDSString() { clear(); }

    CATCDSBoolean operator ! () const { return isEmpty(); }

    CATCDSString& operator = (const CATCDSString& S);
    CATCDSString& operator = (const char*         s);
    CATCDSString& operator = (char                c);
    CATCDSString& operator = (int                 i) { return *this = CATCDSString(i); }
    CATCDSString& operator = (long                i) { return *this = CATCDSString(i); }
    CATCDSString& operator = (long long           i) { return *this = CATCDSString(i); }
    CATCDSString& operator = (unsigned int        i) { return *this = CATCDSString(i); }
	  CATCDSString& operator = (unsigned long       i) { return *this = CATCDSString(i); }
    CATCDSString& operator = (unsigned long long  i) { return *this = CATCDSString(i); }  	
    CATCDSString& operator = (double              r) { return *this = CATCDSString(r); }

    CATCDSString& operator += (const CATCDSString& S);
    CATCDSString& operator += (const char*         s);
    CATCDSString& operator += (char                c);
    CATCDSString& operator += (int                 i) { return *this += CATCDSString(i); }
    CATCDSString& operator += (long                i) { return *this += CATCDSString(i); }
    CATCDSString& operator += (long long           i) { return *this += CATCDSString(i); }
    CATCDSString& operator += (unsigned int        i) { return *this += CATCDSString(i); }
	  CATCDSString& operator += (unsigned long       i) { return *this += CATCDSString(i); }
    CATCDSString& operator += (unsigned long long  i) { return *this += CATCDSString(i); }    
    CATCDSString& operator += (double              r) { return *this += CATCDSString(r); }

    CATCDSString& set(const CATCDSString& S) { return *this = S; }
    CATCDSString& set(const CATCDSString& S, size_t n);
    CATCDSString& set(const char*         s) { return *this = s; }
    CATCDSString& set(const char*         s, size_t n);
    CATCDSString& set(char                c) { return *this = c; }
    CATCDSString& set(int                 i) { return *this = i; }
    CATCDSString& set(long                i) { return *this = i; }
    CATCDSString& set(long long           i) { return *this = i; }
    CATCDSString& set(unsigned int        i) { return *this = i; }
	  CATCDSString& set(unsigned long       i) { return *this = i; }
    CATCDSString& set(unsigned long long  i) { return *this = i; }    
    CATCDSString& set(double              r, size_t w = 17) { return *this = CATCDSString(r, w); }

    CATCDSString& add(const CATCDSString& S) { return *this += S; }
    CATCDSString& add(const CATCDSString& S, size_t n);
    CATCDSString& add(const char*         s) { return *this += s; }
    CATCDSString& add(const char*         s, size_t n);
    CATCDSString& add(char                c) { return *this += c; }
    CATCDSString& add(int                 i) { return *this += i; }
    CATCDSString& add(long                i) { return *this += i; }
    CATCDSString& add(long long           i) { return *this += i; }	  
    CATCDSString& add(unsigned int        i) { return *this += i; }
    CATCDSString& add(unsigned long       i) { return *this += i; }
    CATCDSString& add(unsigned long long  i) { return *this += i; }
    CATCDSString& add(double              r, size_t w = 17) { return *this += CATCDSString(r, w); }

    const char& operator [] (int pos) const { return str()[pos]; }

    const char* str() const { return _str._data ? _str._data : ""; }

    int len() const { return (int)_str._length; }
    void len(size_t newlen);
    CATCDSBoolean isEmpty() const { return len() == 0; }    
    void clear();

    CATCDSString& operator << (const CATCDSString& S) { return *this += S; }
    CATCDSString& operator << (const char*         s) { return *this += s; }
    CATCDSString& operator << (char                c) { return *this += c; }
    CATCDSString& operator << (int                 i) { return *this += i; }	  
    CATCDSString& operator << (long                i) { return *this += i; }	  
    CATCDSString& operator << (long long           i) { return *this += i; }	  
    CATCDSString& operator << (unsigned int        i) { return *this += i; }
    CATCDSString& operator << (unsigned long       i) { return *this += i; }
    CATCDSString& operator << (unsigned long long  i) { return *this += i; }
    CATCDSString& operator << (double              r) { return *this += r; }

#if defined(_WINDOWS_SOURCE) || defined(_LINUX_SOURCE) ||  defined(_DARWIN_SOURCE) && defined(CATIAR420) || defined(__ibmxl__)
    operator std::string() const;
#endif

    size_t size() const { return len()+1; }

    CATCDSString& lower();
    CATCDSString& upper();

    int find(const CATCDSString& pattern, int iFrom = 0) const;
    int find(char pattern, int iFrom = 0) const;
    int findLast(char pattern) const;
    CATCDSString subString(int from, int to = -1) const;
    void replace(char iChar, char iReplace);
    CATCDSString replace(CATCDSString const &iOld, CATCDSString const &iNew );

    CATCDSString trim(char iChar = ' ') const;
    CATCDSString trimLeft(char iChar = ' ') const;
    CATCDSString trimRight(char iChar = ' ') const;

    class ExportedByCATCDSUtilities token {
      friend class CATCDSString;

      public:
        token();
        ~token();

        void init();

              CATCDSString& getToken()       { return _tok; }
        const CATCDSString& getToken() const { return _tok; }

      private:
        token& operator = (const token&);

        size_t _cur;
        CATCDSString& _tok;
    };

    CATCDSBoolean getLine(token& curtok, char separator = '\n') const;
    CATCDSBoolean getLine(token& curtok, const CATCDSString& separator) const;
    CATCDSBoolean getToken(token& curtok, const CATCDSString& seps) const;

  private:
    str_t _str;

    void check();

    void ensureSize(size_t newlen);

    void doset(const char* s);
    void dosetn(const char* s, size_t n);
    void doset(char c);
    void doadd(const char* s, size_t lensrc);
    void doaddn(const char* s, size_t n);
    void doadd(char c);

    unsigned int& count() const { return (unsigned int&)_str._data[-(int)sizeof(unsigned int)]; }
    void incRef() const { count()++; }
    void decRef() const { count()--; }
    void link(const CATCDSString& S);
    void unlink();
};

CATCDSInline CATCDSString::CATCDSString() {
  _str._data = 0;
  _str._length = 0;
}

CATCDSInline CATCDSString::CATCDSString(const CATCDSString& S) {
  _str._data = 0;
  _str._length = 0;
  link(S);
}

CATCDSInline CATCDSString::CATCDSString(const CATCDSString& S, size_t n) {
  _str._data = 0;
  _str._length = 0;
  if (!S.isEmpty() && n > 0) {
    dosetn(S.str(), n);
    check();
  }
}

CATCDSInline CATCDSString::CATCDSString(const char* s) {
  _str._data = 0;
  _str._length = 0;
  if (s && s[0])
    doset(s);
}

CATCDSInline CATCDSString::CATCDSString(const char* s, size_t n) {
  _str._data = 0;
  _str._length = 0;
  if (s && s[0] && n > 0) {
    dosetn(s, n);
    check();
  }
}

CATCDSInline CATCDSString::CATCDSString(char c) {
  _str._data = 0;
  _str._length = 0;
  if (c)
    doset(c);
}

ExportedByCATCDSUtilities bool operator == (const CATCDSString& S, const CATCDSString& T);
ExportedByCATCDSUtilities bool operator == (const CATCDSString& S, const char*         s);
ExportedByCATCDSUtilities bool operator == (const char*         s, const CATCDSString& S);

CATCDSInline bool operator != (const CATCDSString& S, const CATCDSString& T) { return !(S == T); }
CATCDSInline bool operator != (const CATCDSString& S, const char*         s) { return !(S == s); }
CATCDSInline bool operator != (const char*         s, const CATCDSString& S) { return !(S == s); }

ExportedByCATCDSUtilities bool operator > (const CATCDSString& S, const CATCDSString& T);
ExportedByCATCDSUtilities bool operator > (const CATCDSString& S, const char*         s);
ExportedByCATCDSUtilities bool operator > (const char*         s, const CATCDSString& S);

CATCDSInline bool operator <= (const CATCDSString& S, const CATCDSString& T) { return !(S > T); }
CATCDSInline bool operator <= (const CATCDSString& S, const char*         s) { return !(S > s); }
CATCDSInline bool operator <= (const char*         s, const CATCDSString& S) { return !(s > S); }

ExportedByCATCDSUtilities bool operator >= (const CATCDSString& S, const CATCDSString& T);
ExportedByCATCDSUtilities bool operator >= (const CATCDSString& S, const char*         s);
ExportedByCATCDSUtilities bool operator >= (const char*         s, const CATCDSString& S);

CATCDSInline bool operator < (const CATCDSString& S, const CATCDSString& T) { return !(S >= T); }
CATCDSInline bool operator < (const CATCDSString& S, const char*         s) { return !(S >= s); }
CATCDSInline bool operator < (const char*         s, const CATCDSString& S) { return !(s >= S); }

ExportedByCATCDSUtilities CATCDSString operator + (const CATCDSString& S, const CATCDSString& T);
ExportedByCATCDSUtilities CATCDSString operator + (const CATCDSString& S, const char*         s);
ExportedByCATCDSUtilities CATCDSString operator + (const char*         s, const CATCDSString& S);

ExportedByCATCDSUtilities ostream& operator << (ostream& os, const CATCDSString& S);

ExportedByCATCDSUtilities unsigned int CATCDSStringHashIt(const CATCDSString& iObj) ;
ExportedByCATCDSUtilities int CATCDSStringHashCompare(const CATCDSString& iObj1, const CATCDSString& iObj2);

CATCDSARRAY_DECLARE(CATCDSString);
CATCDSLISTP_DECLARE_EXPORTED(CATCDSString, ExportedByCATCDSUtilities);
#endif
