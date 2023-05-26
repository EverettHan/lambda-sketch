// COPYRIGHT DASSAULT SYSTEMES 2013

#ifndef TimeUtilities_H
#define TimeUtilities_H

#include "CATVisFoundation.h"
#include "CATDataType.h"

// These services should be moved to a Framework used both by visualizaiton and IVDeviceCore (UIVCoreTools or System).
// These services help define a unified timestamp accross APIs so that events coming from iV devices can be compared to UI events and other events from external frameworks.

 /**
  * Retrieves the current system time.
  * For compatibility reasons accross OSes, the returned times is a signed 64-bit integer representing the number of milliseconds elapsed since the 1st of January 1970 (a common standard).
  * The returned value is therefore an absolute UTC date, which can be used for logging, streaming and interoperability.
  * This value can be negative to encode dates before 1970, but unless the system settings have been set to absurd values, such a situation should not occur.
  *
  * @return
  *   the number of milliseconds elapsed since the 1st of January 1970.
  */
ExportedByCATVisFoundation CATLONG64 VisGetSystemTime();

#endif
