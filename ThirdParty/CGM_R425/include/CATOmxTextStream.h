#ifndef __CATOmxTextStream_h__
#define __CATOmxTextStream_h__
// OS
#include <stdio.h>
#include <iosfwd>
// ObjectModelerCollection
#include "CATOmxAutoPtr.h"
#include "CATOmxDeprecated.h"
#include "CATOmxKernel.h"
#include "CATOmxKind.h"
#include "CATOmxPortability.h"
#include "CATOmxSR.h"
#include "CATOmxUTF8String.h"
class CATUnicodeString;
class CATOmxKeyString;
class _SEQUENCE_octet;
class CORBAAny;
typedef unsigned char octet;
typedef unsigned char CATBoolean;
class CATOmxOutputStream;
class CATOmxUTF8String;
class CATString;

/**
* A very basic text stream.
* The output encoding is UTF8.
* All input const char * are supposed to be valid UTF8 string.
*/
class ExportedByCATOmxKernel CATOmxTextStream
{
private:
  CATOmxSR<CATOmxOutputStream> m_output;
  signed short   m_indent;
  unsigned short m_flags; // For flags defined in CATOmxTextStreamFlags.h
  CATOmxAutoPtr<std::stringstream> m_stringStream;

  CATOmxTextStream(const CATOmxTextStream & iCopy);
  CATOmxTextStream & operator=(const CATOmxTextStream & iCopy);
public:
  /** @nodoc */
  void BeginLine();
  /** @nodoc */
  unsigned int GetIFlags() const { return m_flags; } // For flags defined in CATOmxTextStreamFlags.h 
  /** @nodoc */
  void SetIFlags(unsigned iFlags) { m_flags |= iFlags; } // For flags defined in CATOmxTextStreamFlags.h
  /** @nodoc */
  void ResetIFlags(unsigned iFlags) { m_flags &= ~iFlags; } // For flags defined in CATOmxTextStreamFlags.h

  // Method to activate consistent double to string conversion (see CATOmxFtoA).
  void ActivateConsistentDoubleStream();

  /** Raw write a byte. */
  void write(char c);
  /** Raw write a string. */
  void write(const char * c, int len = -1);
  /** Raw write a string. */
  void write(const CATOmxUTF8String & iStr);
  /** Indented write */
  CATOmxTextStream & iwrite(const char * c, int len = -1);

  CATOmxTextStream();

  ~CATOmxTextStream();
  /**
  * Control the number of tab to use to indent.
  * @delta if negative unindent
  */
  void Indent(int delta);

  /**
  * Quote a string use osml/c/c++ escaping convention using a \.
  *  backslash    \\
  *  quote        \' if iDelim is quote
  *  doublequote  \" if iDelim is doublequote
  *  backquote    \' if iDelim is backquote
  *  cr           \r
  *  lf           \n
  *  formfeed     \f
  *  backspace    \b
  *  any control char are escaped
  *  char upper than \x7f are not escaped because the stream is supposed to be UTF8 complient
  *
  * @param iDelim the selected delimeter can be :
  *     quote (')
  *     double quote (")
  *  or backquote (`) in this case the iStr
  *  is escaped only when iStr does not match the following regular expression ([$A-Za-z_][$A-Za-z_0-9]*)
  * @param iStr the string to output
  */
  CATOmxTextStream & quote(char iDelim, const CATUnicodeString & iStr);
  /**
  * Quote a string use osml/c/c++ escaping convention using a \.
  * @param iDelim see previous method
  * @param iStr the UTF8 encoded string to output
  */
  CATOmxTextStream & quote(char iDelim, const char * iStr);

  CATOmxTextStream & quote(char iDelim, const CATOmxUTF8String & iStr);
  CATOmxTextStream & quote(char iDelim, const CATOmxKeyString & iStr);
  /**
  * Stream and substitute iStr (<,>,&,") by (&lt;,&gt;,&amp;,&quot;).
  * '"' is substituted only if iDelim is set to '"'
  * @return the old state (usefull to restore it)
  */
  CATBoolean set_xml_escape(CATBoolean iXmlEscape);

  /**
  * Stream and substitute iStr (+,=,&,% and any non printable chars) by (%xx) and ' ' by '+'.
  * @param iEscape the new state
  * @return the old state (usefull to restore it)
  */
  CATBoolean set_url_escape(CATBoolean iEscape);
  /**
  * Use space instead of tab to indent
  * @param iSpace
  * @return the old state (usefull to restore it)
  */
  CATBoolean set_indent_with_space(CATBoolean iSpace);
  /** @nodoc */
  CATOmxTextStream & facet(const char * iKey);
  /** @nodoc */
  CATOmxTextStream & facet(const char * iKey, const CATUnicodeString & id, char iDelim = 0);
  /** @nodoc */
  CATOmxTextStream & facet(const char * iKey, const char * id, char iDelim = 0);
  void flush();

  /**
  * Write a hexadecimal binary stream the prefix is b'xxxx'.
  */
  CATOmxTextStream & binary(const octet * iVector, unsigned int iLength);
  /**
  * open '{' and indent.
  */
  CATOmxTextStream & begin_block();
  /**
  * close '}' and unindent.
  */
  CATOmxTextStream & end_block();

  /** output according to type. */
  CATOmxTextStream & operator <<(const CATINT32);
  /** output according to type. */
  CATOmxTextStream & operator <<(const CATUINT32);
#if !defined(PLATEFORME_DS64)
  /** output according to type. */
  CATOmxTextStream & operator <<(const CATLONG32);
  /** output according to type. */
  CATOmxTextStream & operator <<(const CATULONG32);
#endif
  /** output according to type. */
  CATOmxTextStream & operator <<(const CATLONG64);
  /** output according to type. */
  CATOmxTextStream & operator <<(const CATULONG64);
  /** output according to type. */
  CATOmxTextStream & operator <<(const double);
  /** output according to type. */
  CATOmxTextStream & operator <<(const float);
  /** output according to type. */
  CATOmxTextStream & operator <<(const CATUnicodeString &);
  /** output according to type. */
  CATOmxTextStream & operator <<(const CATString &);
  /** output according to type. */
  CATOmxTextStream & operator <<(const CATOmxKeyString &);
  /** output according to type. */
  CATOmxTextStream & operator <<(const CATOmxUTF8String &);
  /** output according to type. */
  CATOmxTextStream & operator <<(const char *);
  /** output according to type. */
  CATOmxTextStream & operator <<(const char);

  /**
  * Open iName as an output file .
  * @param iName the fileName (note ">stderr" redirect to stream to stderr
  * @return 1 if stream is opened, else 0
  */
  int Open(const CATOmxUTF8String & iName, CATBoolean append = FALSE);
  bool IsOpened() const;
  /** Closes file or deletes memory buffer. */
  int Close();
  /** Start a memory streaming instead of file streaming. */
  void StartMemory();
  /** Returns the size of the output, including EOS character. */
  int Size() const;
  /** Returns an UTF8 working string. */
  void GetOutputUTF8(CATOmxUTF8String & out) const;
  /** returns content as a CATOmxUTF8String. */
  CATOmxUTF8String ToUTF8String() const;
  /** returns content as a CATUnicodeString. */
  CATUnicodeString ToString() const;

  /** internal use set the output stream */
  void SetOutput(CATOmxOutputStream & iOutput);
  /** @nodoc */
  CATOmxOutputStream * GetOutput() { return m_output; }
  /** deal with typed number (internal use only). */
  void write_integer(CATLONG64 value, CATOmxKind iKind);

  CATBoolean SetJsonEscaping(CATBoolean on);

  CATOmxTextStream & ConvertDoubleToString(double iValue, HRESULT * oHR = NULL);
};

/**
 * allows to print a pointer
 * CATOmxTextStream stream;
 * void* ptr = ...
 * stream << CATOmxPrintPointer(ptr);
 */
struct CATOmxPrintPointer
{
  const void * const m_ptr;
  inline CATOmxPrintPointer(const void * ptr) :m_ptr(ptr) {}
};
ExportedByCATOmxKernel CATOmxTextStream & operator<<(CATOmxTextStream & out, const CATOmxPrintPointer & ptr);
ExportedByCATOmxKernel OMX_DEPRECATED("use CATOmxPrintPointer if you really intend to print an address") CATOmxTextStream & operator<<(CATOmxTextStream & out, const void * ptr);

/** output according to type. */
ExportedByCATOmxKernel CATOmxTextStream & operator<<(CATOmxTextStream & osm, const _SEQUENCE_octet & seq);
/** output according to type. */
ExportedByCATOmxKernel CATOmxTextStream & operator<<(CATOmxTextStream & osm, const CORBAAny & seq);
/** output according to type. */
ExportedByCATOmxKernel CATOmxTextStream & operator<<(CATOmxTextStream & osm, const class CATUuid & uuid);

/** output a '\n' and prepare to indent. */
ExportedByCATOmxKernel CATOmxTextStream & endl(CATOmxTextStream &);

/** force output stream flush. */
ExportedByCATOmxKernel CATOmxTextStream & flush(CATOmxTextStream &);
/** add automaticly a zero after '.' if needed. */
ExportedByCATOmxKernel CATOmxTextStream & float_with_zero(CATOmxTextStream &);
ExportedByCATOmxKernel CATOmxTextStream & json_mode(CATOmxTextStream &);
/** pedantic identifier. add '`' around token matching [a-z_]+ pattern. */
ExportedByCATOmxKernel CATOmxTextStream & pedantic_identifier(CATOmxTextStream &);

/** @nodoc */
ExportedByCATOmxKernel CATOmxTextStream & operator << (CATOmxTextStream &, CATOmxTextStream & (*)(CATOmxTextStream &));

ExportedByCATOmxKernel CATOmxTextStream & operator << (CATOmxTextStream & oss, const class CATOmxAny & cur);


/**
 * Standard way to dump a list of key/value inside a CATOmxTextStream.
 * Use case:
 * - CATOmxTextStream() << "One key/value" << CATOmxParameters().parm("key1", 1).end_block() --> "One key/value: { key1=1 }"
 * - CATOmxTextStream() << "Several key/value" << CATOmxParameters().parm("key2", "value").parm("key3", CATUuid(0)).end_block() --> "Several key/value: { key2=value, key3=0u00000000-0000-0000-0000000000000000 }"
 */
class CATOmxParameters
{
private:
  CATOmxTextStream m_tempStream;
  bool m_firstParm;
  ExportedByCATOmxKernel CATOmxTextStream & GetReadyPlayerOne(const char * key);
public:
  ExportedByCATOmxKernel CATOmxParameters();

  /**
   * Dump a key/value pair with format "key=value"
   * @param key key to dump.
   * @param value value to dump. Type of value must be compatible with "CATOmxTextStream() << value"
   * @return this instance of CATOmxParameters
   */
  template<typename T> CATOmxParameters & parm(const char * key, T const & value);

  /**
   * Will dump the final bracket and return a ready to dump text stream.
   * @return a ready-to-dump text stream
   */
  ExportedByCATOmxKernel CATOmxUTF8String end_block();
};

template<typename T> inline CATOmxParameters & CATOmxParameters::parm(const char * key, T const & value)
{
  GetReadyPlayerOne(key) << value;
  return *this;
}


#endif
