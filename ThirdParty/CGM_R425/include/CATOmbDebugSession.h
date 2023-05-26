#ifndef CATOmbDebugSession_H
#define CATOmbDebugSession_H

/**
* @level  Private
* @usage   U3
*/

#pragma message( "!!" )
#pragma message( "!! Stop including " __FILE__  ", this include is empty." )
#pragma message( "!!" )

#include "CATBaseUnknown.h"

class CATOmbDebugSession: public CATBaseUnknown
{
  public:
    static  CATOmbDebugSession* GetDebugSession(CATBoolean iWithSeparatedFolder = FALSE) {return NULL;}
};

//-----------------------------------------------------------------------

#endif
