// COPYRIGHT DASSAULT SYSTEMES 2002
//=============================================================================
//
// CATCDSStream:
//   Class supports streaming in Replay mechanism.
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  Jun 2002  Creation
//=============================================================================

#ifndef CATCDSStream_h
#define CATCDSStream_h

#include "CATCDSUtilities.h"
#include "CATCDSBoolean.h"
#include "CATCDSStorage.h"
#include "CATCDSInline.h"
#include "CATCDSDebug.h"

#if defined(_EMSCRIPTEN_SOURCE) && defined(_EMSCRIPTEN_DEBUG)
#include "CATCDSString.h"
#endif

#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
#include <iostream.h>
#endif

#include <utility>

#if defined(_WINDOWS_SOURCE) || defined(_LINUX_SOURCE)
#include <string>
#endif

class CATCDSString;
class CATCDSManip;
class CATCDSStream;

ExportedByCATCDSUtilities CATCDSManip cdssetw(int w);
ExportedByCATCDSUtilities CATCDSManip cdssetprecision(int p);
ExportedByCATCDSUtilities CATCDSManip cdssetfill(char c);
ExportedByCATCDSUtilities CATCDSManip cdssetfixedfloatfield();
ExportedByCATCDSUtilities CATCDSStream& cdsendl(CATCDSStream& ioStream);

#define cdseof EOF
#define cdsends '\0'

class ExportedByCATCDSUtilities CATCDSStream {
public:
  enum CATCDSStreamType
  { 
    // File streams
    WriteOnly, 
    ReadWrite = WriteOnly, // pour le sketcher CATIA
    // String streams
    StringWriteOnly,
    // Custom stream
    Custom
  };

  // Custom stream (caller is responsible for streams life cycle)
  CATCDSStream(ostream *oStream);

  CATCDSStream(const CATCDSString & iStreamDef, const CATCDSStreamType iAccess, CATCDSBoolean iAppend = FALSE);
  CATCDSStream();

  ~CATCDSStream();

  void WriteLong(long iValue);
  void WriteShort(short iValue);
  void WriteInt(int iValue);
  void WriteDouble(double iValue);
  void WriteFixedSizeDouble(double iValue);
  void WriteString(const CATCDSString & iString);
  void WriteLine(const CATCDSString & iString);

  CATCDSBoolean ReadStringTo(const CATCDSString& iSeparators, CATCDSString & oString);

  void WriteHeader(const CATCDSString & iName, int iVersion);
  void WriteHeader(const CATCDSString & iName, int iVersion, unsigned int iLevel);

  //!nb compatibility only
  void WriteSections(CATCDSStorage::ReplayPart iPart = CATCDSStorage::rpAll);
  void WriteSections(CATCDSStorage::ReplayPart iPart/* = CATCDSStorage::rpAll*/, int iNumber/* = 0*/);

  void WriteDelimiter();

  void Flush();

  CATCDSStorage & GetStorage();
  const CATCDSStorage & GetStorage() const;

  void ChooseReplayPart(CATCDSStorage::ReplayPart iPart);
  void ChooseReplayPart(CATCDSStorage::ReplayPart iPart, int iNumber);

#if defined(_WINDOWS_SOURCE) || defined(_LINUX_SOURCE)
  CATCDSStream& operator << (std::string const &S);
#endif

  CATCDSStream& operator << (const CATCDSString& S);
  CATCDSStream& operator << (const char*         s);
  CATCDSStream& operator << (const void*         s);
  CATCDSStream& operator << (char                c);
  CATCDSStream& operator << (int                 i);
  CATCDSStream& operator << (long                i);
  CATCDSStream& operator << (long long           i);
  CATCDSStream& operator << (unsigned int        i);
  CATCDSStream& operator << (unsigned long       i);
  CATCDSStream& operator << (unsigned long long  i);
  CATCDSStream& operator << (double              d);
  template<class T1, class T2>
  CATCDSStream& operator << (std::pair<T1, T2> const& p);

  CATCDSInline CATCDSStream& operator << (CATCDSStream& (*m)(CATCDSStream&)) {return (*m)(*this);}

  void clear();
  CATCDSBoolean good() const;
  
  iostream* GetStream();
  ostream* GetOutputStream();

  void seek(long pos);

#if defined(_EMSCRIPTEN_SOURCE)
  void* GetImpl() {return this;}

  int GetVersionNumber() const;

  void ReadShort(short& ioShort, const char iReservedLabel[] = "");
  void ReadLong(long& ioLong, const char iReservedLabel[] = "");
  void ReadUChar(unsigned char& ioUChar, const char iReservedLabel[] = "");
  void ReadDouble(double& ioDouble, const char iReservedLabel[] = "");
  void ReadUChar(unsigned char* ioArrayUChar, const int iNbCells, const char iReservedLabel[] = "");

  void WriteUChar(const unsigned char iUChar, const char iReservedLabel[] = "");
  void WriteUChar(const unsigned char* iUCharArray, const int iNbCells, const char iReservedLabel[] = "");
#endif

protected:
  void DoWriteSections(CATCDSStorage::ReplayPart iPart, int iNumber);
  void DoWritePartSeparator(CATCDSStorage::ReplayPart iPart, int iNumber);

  ostream  *_poStream;

  CATCDSStreamType _streamType;

  CATCDSStorage _storage;

#if defined(_EMSCRIPTEN_SOURCE) && defined(_EMSCRIPTEN_DEBUG)
   CATCDSString _fileName;
#endif

  friend CATCDSStream& do_setw(CATCDSStream& s, int n);
  friend CATCDSStream& do_setprecision(CATCDSStream& s, int n);
  friend CATCDSStream& do_setfill(CATCDSStream& s, int n);
  friend CATCDSStream& do_cdssetfixedfloatfield(CATCDSStream& s, int dummy);
  friend ExportedByCATCDSUtilities CATCDSStream& cdsendl(CATCDSStream& ioStream);

protected:
  CATCDSStream(CATCDSStream const &);
  CATCDSStream& operator=(CATCDSStream const &);
};

class ExportedByCATCDSUtilities CATCDSManip
{  
public:
  CATCDSInline CATCDSManip(CATCDSStream& (*a)(CATCDSStream&,int), int v): _action(a), _value(v) {}
  friend ExportedByCATCDSUtilities CATCDSStream& operator<<(CATCDSStream&, const CATCDSManip&);

private:
  CATCDSStream& (*_action)(CATCDSStream&,int);
  int _value;
};
  
template<class T1, class T2>
CATCDSStream& CATCDSStream::operator<<(std::pair<T1, T2> const& p)
{
  return *this << "{" << p.first << ", " << p.second << "}";
}

#if defined(_EMSCRIPTEN_SOURCE) && defined(_EMSCRIPTEN_DEBUG)
#include <vector>

struct EmscriptenStream {
  CATCDSString _name;
  CATCDSString _data;
};

std::vector<EmscriptenStream> & GetEmscriptenStreams();

#endif

#endif

