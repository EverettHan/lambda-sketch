#ifndef __CATOmxByteBuffer_h__
#define __CATOmxByteBuffer_h__

// ObjectModelerCollection
#include "CATOmxCxxPortability.h"
#include "CATOmxPortability.h"

/**
 * relatively efficient byte buffer
 *
 * usage:
 * CATOmxByteBuffer buffer;
 * buffer.Add(0x1);
 * buffer.Add(0x2);
 *
 * now buffer.m_len is 2 and buffer.m_bytes is {0x1, 0x2}
 */
class CATOmxByteBuffer
{
public:
  char* m_bytes;
  size_t m_len;
private:
  size_t m_maxSize;
  char m_aggregatedBytes[256]; //totally arbitrary size choice
public:
  inline CATOmxByteBuffer()
  {
    m_bytes = m_aggregatedBytes;
    m_maxSize = sizeof(m_aggregatedBytes);
    Clear();
  }

  inline void Add(char c)
  {
    if (m_len == m_maxSize)
      Reserve(2 * m_maxSize);
    m_bytes[m_len++] = c;
  }

  ExportedByCATOmxKernel void Reserve(size_t iReserve);

  inline void Clear() { m_len = 0; }

  ExportedByCATOmxKernel ~CATOmxByteBuffer();

#if OMX_CXX11 == 1
public:
  CATOmxByteBuffer(const CATOmxByteBuffer &) OMX_Cxx11_DELETE;
  CATOmxByteBuffer(CATOmxByteBuffer &&) OMX_Cxx11_DELETE;
  CATOmxByteBuffer & operator =(const CATOmxByteBuffer &) OMX_Cxx11_DELETE;
  CATOmxByteBuffer & operator =(CATOmxByteBuffer &&) OMX_Cxx11_DELETE;
#else
private:
  CATOmxByteBuffer(const CATOmxByteBuffer &); // Not implemented.
  CATOmxByteBuffer & operator =(const CATOmxByteBuffer &); // Not implemented.
#endif
};

#endif // __CATOmxByteBuffer_h__
