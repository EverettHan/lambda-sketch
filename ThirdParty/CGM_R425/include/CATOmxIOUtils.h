//===================================================================
// COPYRIGHT Dassault Systemes 2018/05/24
//===================================================================
// CATOmxIOUtils.cpp
// Header definition of class CATOmxIOUtils
//===================================================================
//
// Usage notes:
//
// IOUtils provides tools to manipulate input/output stream
// See also: CATWOmxBinaryStream
//
//===================================================================
//  2018/05/24 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATOmxIOUtils_H
#define CATOmxIOUtils_H

#include "CATOmxInputOutput.h"
#include "CATIOmxInputStream.h"
#include "CATOmxUTF8String.h"

class ExportedByCATOmxInputOutput CATOmxIOUtils
{
public:
  /*
  * Reads the input stream as an UTF8 string
  *
  * @return
  *   S_OK input stream read and utf string returned
  *   E_INVALIDARG given stream is NULL
  *   E_OUTOFMEMORY out of memory (string too big) -> use another way to read the string on the fly
  */
  static HRESULT ToString(CATIOmxInputStream* ipInputStream, CATOmxUTF8String& oUTF8String);
};

#endif
