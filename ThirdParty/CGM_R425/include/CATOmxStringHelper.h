
#ifndef __CATOmxStringHelper_h__
#define __CATOmxStringHelper_h__

#include "CATOmxKernel.h"
#include "CATOmxKeyString.h"
#include "CATOmxUTF8String.h"
#include "CATUnicodeString.h"
#include "DSYStringHelper.h"

class CATString;
class CATUnicodeString;
class CATOmxUTF8String;
class CATOmxKeyString;

/**
 * Helper functions to allow for efficient string conversions:
 *  + Move
 *  + Copy
 */
 
namespace DSY
{
  inline void Move(CATString &oDest, CATOmxKeyString &ioSource)
  {
    DSY::Copy(oDest,ioSource.asCUS());
    ioSource = CATOmxKeyString();
  }
  inline void Move(CATUnicodeString &oDest, CATOmxKeyString &ioSource)
  {
    oDest = ioSource.asCUS(); 
    ioSource = CATOmxKeyString();
  }
  inline void Move(CATString &oDest, CATOmxUTF8String &ioSource)
  {
    DSY::Copy(oDest,ioSource.asString());
    ioSource = CATOmxUTF8String();
  }
  inline void Move(CATUnicodeString &oDest, CATOmxUTF8String &ioSource)
  {
    oDest = ioSource.asString();
    ioSource = CATOmxUTF8String();
  }

  inline void Copy(CATString &oDest, const CATOmxKeyString &ioSource)
  {
    DSY::Copy(oDest,ioSource.asCUS()); 
  }
  inline void Copy(CATUnicodeString &oDest, const CATOmxKeyString &ioSource)
  {
    oDest = ioSource.asCUS(); 
  }
  inline void Copy(CATString &oDest, const CATOmxUTF8String &ioSource)
  {
    DSY::Copy(oDest,ioSource.asString()); 
  }
  inline void Copy(CATUnicodeString &oDest, const CATOmxUTF8String &ioSource) 
  {
     oDest =ioSource.asString(); 
  }
}

#endif  // __CATOmxStringHelper_h__


