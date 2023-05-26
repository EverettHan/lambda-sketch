#ifndef __CATActivationTraces_h
#define __CATActivationTraces_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CNEXT_CLIENT
#  include "CATTraMacro.h"
TRAINIT (WksStack, "Workbench stack traces");
#  define SPrint(t)\
  if (Tra_WksStack.IsActive ())\
    Tra_WksStack.TraPrint t
#else
#  define SPrint(t)
#endif

#endif//__CATActivationTraces_h
