#ifndef _CATStyleProcessor_H
#define _CATStyleProcessor_H

#if defined(__CATStyleProcessor)
#define ExportedByCATStyleProcessor DSYExport
#else
#define ExportedByCATStyleProcessor DSYImport
#endif
#include "DSYExport.h"

#include <CATISYPTemplate.h>
#define CATISYPIntrospectablePrivate_var CATISYPTemplate_var

#endif
