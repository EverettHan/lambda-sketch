/**
 * @level Private
 * @usage U1
 */

#ifndef __CATOmxTextFileReader_H
#define __CATOmxTextFileReader_H

class CATIOmxBinaryStream;
class CATOmxUTF8String;

#include "CATOmxKernel.h"
#include "CATOmxPortability.h"
#include "CATOmxSR.h"
#include "CATUnicodeString.h"

/**
 * Helper for reading a text stream.
 * (Alternative for fopen/fgets/string conversions/fclose code sequences)
 *
 * Only UTF8 (and so ASCII) encoding is supported.
 * UTF8 BOM is supported.
 * Windows/unix (and mixed combinations) EOL conventions (\r\n vs \n) are supported.
 * Old mac EOL convention (\r) is not supported.
 * Validity of UTF8 content is checked (but can be disabled: OMX_NO_UTF8_CHECKS)
 * 
 * usage:
 * <pre>
 *   //ReadLine usage:
 *   CATUnicodeString str; //or CATOmxUTF8String
 *   CATOmxTextFileReader reader;
 *   HRESULT hr;
 *   if(SUCCEEDED(hr = reader.Open(path))
 *   {
 *     while(S_OK == (hr = reader.ReadLine(str)))
 *     {
 *       
 *     }
 *   }
 *   if(SUCCEEDED(hr))
 *   {
 *     ...
 *   }
 *
 *   //ReadAll usage:
 *   CATOmxUTF8String str; //or CATUnicodeString
 *   CATOmxTextFileReader reader;
 *   if(SUCCEEDED(CATOmxTextFileReader(path).ReadAll(str))
 *   {
 * 
 *   }
 * </pre>
 *   
 * Notice that it is possible to use this helper on any kind of stream
 * thanks to CATIOmxBinaryStream abstraction layer (see SetStream).
 */
class ExportedByCATOmxKernel CATOmxTextFileReader
{
  struct CATOmxTextFileReaderImpl& m_impl;
public:
  /**
   * Ctor.
   * If iFile is not empty, calls Open(iFile)
   * else Open or SetStream must be called prior to any method call.
   */
  CATOmxTextFileReader(const CATUnicodeString& iFile = CATUnicodeString());

  /**
   * Open iFile for reading.
   */
  HRESULT Open(const CATUnicodeString& iFile);

  /**
   * Bind reader to a stream.
   */
  CATOmxTextFileReader& SetStream(CATIOmxBinaryStream* iStream);

/** Disable UTF8 validity checks */
#define OMX_NO_UTF8_CHECKS    0x1
/** Disable EOL conversions in ReadAll */
#define OMX_NO_EOL_CONVERSION 0x2
/** Skip empty lines in ReadLine */
#define OMX_SKIP_EMPTY_LINES 0x4
  /**
   *  Change class behavior according to previous #define's.
   */
  CATOmxTextFileReader& SetFlags(unsigned int iFlags);

  /**Internal class to handle CATUnicodeString/CATOmxUTF8String, do not reference it directly*/
  struct StringRef
  {
    CATOmxUTF8String* pUTF8String;
    CATUnicodeString* pUnicodeString;
    inline StringRef(CATUnicodeString& iUCS): pUTF8String(NULL), pUnicodeString(&iUCS) {}
    inline StringRef(CATOmxUTF8String& iUTF8):pUTF8String(&iUTF8),pUnicodeString(NULL) {}
  private:
    StringRef();
  };

  /**
   * Read a line of the stream.
   * @param oLine
   *   Read line (CATUnicodeString or CATOmxUTF8String)
   *   EOL characters are removed
   * returns 
   *   S_OK on success
   *   S_FALSE if end of stream has been reached
   *   failure elsewhere (IO error, invalid UTF8 content)
   */
  HRESULT ReadLine(const StringRef& oLine);

  /**
   * Read all content of the stream.
   * @param oContent
   *   Read text (CATUnicodeString or CATOmxUTF8String)
   *   EOL characters are converted to UNIX EOL convention "\n" (unless OMX_NO_EOL_CONVERSION is used)
   * returns 
   *   S_OK on success
   *   failure elsewhere (IO error, invalid UTF8 content)
   */
  HRESULT ReadAll(const StringRef& oContent);

  ~CATOmxTextFileReader();
private:
  CATOmxTextFileReader(const CATOmxTextFileReader& );
  CATOmxTextFileReader& operator=(const CATOmxTextFileReader& );
};

#endif
