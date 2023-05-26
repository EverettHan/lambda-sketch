#ifndef CATOmyStreamLineReader_h
#define CATOmyStreamLineReader_h

#include "CATOMYCommunication.h"
#include "CATUnicodeString.h"

class CATOmyStreamHandler;
#define BUFFER_SIZE 256

class ExportedByCATOMYCommunication CATOmyStreamLineReader
{
public:
  CATOmyStreamLineReader(CATOmyStreamHandler * iStreamToParse);
  ~CATOmyStreamLineReader();

  /** 
  * Read a line from the stream.
  *
  * @param oLine [out]
  *   The line, with the \n if existing.
  *
  * @return
  *   <code>S_OK</code> if we found a line.
  *   <code>S_FALSE</code> if we have reached the end of the stream (oLine will be empty).
  *   <code>E_*</code> if we have encountered a problem.
  *
  */
  HRESULT ReadLine(CATUnicodeString & oLine);

private:
  HRESULT ReadAChunk();

  CATOmyStreamHandler * _Stream;
  char _Buffer[BUFFER_SIZE];
  ULONG _BufferSize, _PositionInBuffer;
};
#endif
