#ifndef __CATOxDLLUnloadTracker_H
#define __CATOxDLLUnloadTracker_H

#include "CATPLMIdentificationAccess.h"
#include "CATOmxPortability.h"

/**
 * frightening class dedicated to frightening usage
 * usage is forbidden
 */
class ExportedByCATPLMIdentificationAccess CATOxDLLUnloadTracker
{
public:
  CATOxDLLUnloadTracker();
  ~CATOxDLLUnloadTracker();

  static bool HasDLLUnloadStarted();
};

//get rid of warning LNK4221: This object file does not define any previously undefined public symbols, so it will not be used by any link operation that consumes this library
//#define OX_IMPLEMENT_DLL_UNLOAD_TRACKER static CATOxDLLUnloadTracker s_DLLUnloadSentinel
#define _OX_CONCATENATE3(a,b,c) a##b##c
#define OX_CONCATENATE3(a,b,c) _OX_CONCATENATE3(a,b,c)
#define OX_IMPLEMENT_DLL_UNLOAD_TRACKER const OMX_DLLEXPORT CATOxDLLUnloadTracker OX_CONCATENATE3(s_,_MK_MODNAME_,DLLUnloadTracker)

#endif
