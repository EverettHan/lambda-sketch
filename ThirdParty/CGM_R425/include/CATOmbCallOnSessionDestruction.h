#ifndef __CATOmbCallOnSessionDestruction_H
#define __CATOmbCallOnSessionDestruction_H

#include "AC0XXLNK.h"
#include "IUnknown.h"

//call it olny once, if a new session is created/destroyed it will not be called again
#define OMB_CALL_ONCE 0x1
//call it each time a session is deleted
#define OMB_CALL_EACH_TIME 0x2
//call it at the start of session destruction
#define OMB_CALL_BEFORE 0x4
//call it at the end of session destruction
#define OMB_CALL_AFTER 0x8

/**
 * Register a function to call when CATSession is deleted
 * It does not require that CATSession already exist
 * but will not get called if no CATSession is created/deleted
 */
ExportedByAC0XXLNK int CATOmbCallOnSessionDestruction(void (*iFunction)(),int iFlags);

/**
 * Register the address of a STATIC IUnknown pointer to release when CATSession is deleted 
 * It does not require that CATSession already exist
 * but will not get called if no CATSession is created/deleted
 */
ExportedByAC0XXLNK int CATOmbReleaseOnSessionDestruction(IUnknown** iStaticPointer,int iFlags);

#endif
