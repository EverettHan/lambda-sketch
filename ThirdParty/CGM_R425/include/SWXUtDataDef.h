#ifndef SWXUTDATADEF_H
#define SWXUTDATADEF_H

#ifndef _WINDOWS_SOURCE

//Get abs function
#include <stdlib.h>

//These are common data types that are included in WinDef.h
#include <stdint.h>
typedef unsigned int        UINT;

// NULL, HRESULT, etc on gcc
#include "CATSysErrorDef.h"
#include "CATSysDataType.h"

#include "SWXUtMacForOverride.h"

#endif //_WINDOWS_SOURCE
#endif //SWXUTDATADEF_H


