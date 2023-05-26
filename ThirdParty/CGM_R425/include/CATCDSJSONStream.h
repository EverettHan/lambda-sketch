// COPYRIGHT DASSAULT SYSTEMES 2016
//=============================================================================
//
// CATCDSJSONStream:
//   Class supports streaming in json format.
//
//=============================================================================
//  April 2016  Creation
//=============================================================================

#ifndef CATCDSJSONStream_h
#define CATCDSJSONStream_h

#include "CATCDSUtilities.h"
#include "CATCDSBoolean.h"
#include "CATCDSArray.h"
#include "CATCDSStream.h"

#include <string>

class CATCDSString;

class ExportedByCATCDSUtilities CATCDSJSONStream
{
public:
  CATCDSJSONStream(CATCDSStream &iStream, int iFirstEntity = TRUE, int iInitialIndent = 0) :
    _stream(iStream),
    _firstEntity(iFirstEntity),
    _indent(iInitialIndent),
    _Inline(FALSE)
  {
  }

  ~CATCDSJSONStream();

  void WriteObjectStart(CATCDSString const &iName, CATCDSBoolean iInline = FALSE);
  void WriteObjectEnd();

  void WriteArrayStart(CATCDSString const &iName);
  void WriteArrayEnd();

  template<class T>
  void Write(T const &iT)
  {
    Write(CATCDSString(), iT);
  }

  template<class T>
  void Write(CATCDSString const &iName, T const &iT)
  {
    WriteField(iName);
    _stream << iT;
  }

  struct Indent {
    Indent(int iDepth) : _depth(iDepth) {}

    Indent& operator++()
    {
      ++_depth;
      return *this;
    }

    Indent& operator--()
    {
      --_depth;
      return *this;
    }

    friend CATCDSStream& operator<<(CATCDSStream &iStream, Indent iIndent);

    int _depth;
  };

  void SetIndent(int iIndent)
  {
    _indent._depth = iIndent;
  }

  int GetIndent() const
  {
    return _indent._depth;
  }

private:
  void WriteStart(CATCDSString const &iName, char iChar, CATCDSBoolean iInline);
  void WriteEnd(char iChar);
  void WriteField(CATCDSString const &iName);

  CATCDSStream &_stream;
  CATCDSBoolean _firstEntity;
  Indent _indent;
  CATCDSBoolean _Inline;
};

template<>
ExportedByCATCDSUtilities void CATCDSJSONStream::Write<CATCDSString>(CATCDSString const &iName, CATCDSString const &iS);

template<>
ExportedByCATCDSUtilities void CATCDSJSONStream::Write<std::string>(CATCDSString const &iName, std::string const &iS);

template<>
ExportedByCATCDSUtilities void CATCDSJSONStream::Write<char const *>(CATCDSString const &iName, char const * const &iS);

template<>
ExportedByCATCDSUtilities void CATCDSJSONStream::Write<double>(CATCDSString const &iName, double const &d);

#endif

