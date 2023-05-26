#ifndef __CATCkeObjectOrInstance_H
#define __CATCkeObjectOrInstance_H

#include "CATIAV5Level.h"

//dummy typedef to avoid problem with signatures that changed in phase 2

#ifndef CATIAR206
#include "CATIInstance.h"
typedef CATIInstance CATCkeObjectOrInstance;
typedef CATIInstance_var CATCkeObjectOrInstance_var;
#else
#include "CATICkeObject.h"
typedef CATICkeObject CATCkeObjectOrInstance;
typedef CATICkeObject_var CATCkeObjectOrInstance_var;
#endif

#endif
