#ifndef __CATILockBytes2Services_H
#define __CATILockBytes2Services_H

#include "CATILockBytes2.h"
#include "CATOmxPortability.h"
#include "CATDataType.h"
#include "VVSUtils.h"

class ExportedByVVSUtils CATILockBytes2Services
{
public:
  /**
   * Transfer content of the CATILockBytes2 to a memory buffer.
   * @param iILB2
   * @param iAlreadyOpened
   *   iILB2 is already opened.
   *   In this case, iILB2 will remain opened after call
   * @param iMaxSize
   *   maximum number of bytes to read.
   *   -1 means no limit
   *   else if number of bytes to read is greater than iMaxSize, the function fails
   * @param ioBuffer
   *   memory buffer
   *   if NULL in input it will be malloc'ed by this method
   * @param ioSize
   *   in input, the number of bytes contained by the CATILockBytes2, -1 means unknown
   *   in output, the number of bytes read.
   */
  static HRESULT ToMemory(CATILockBytes2* iILB2,int iAlreadyOpened,CATLONG64 iMaxSize,char*& ioBuffer,CATLONG64& ioSize);

  /**
   * Transfer content of the CATILockBytes2 to a memory buffer.
   * @param iILB2
   * @param oBuffer
   *   it will be malloc'ed by this method
   * @paramioSize
   *   the number of bytes read.
   */
  static HRESULT ToMemory(CATILockBytes2* iILB2,char*& oBuffer,CATLONG64& oSize);


  /**
   * Wrap a CATILockBytes2 to a CATILockBytes2 implementation using an internal buffer.
   */
  static HRESULT WrapInBufferedILockBytes2(CATOmxSR<CATILockBytes2>& ioILB2,CATLONG64 iBufferSize=-1);

  /**
   * Unwrap a CATILockBytes2 wrapped by previous method.
   */
  static HRESULT UnWrapBufferedILockBytes2(CATOmxSR<CATILockBytes2>& ioILB2);
};

#endif
