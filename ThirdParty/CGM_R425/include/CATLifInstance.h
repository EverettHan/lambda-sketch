// Copyright Dassault Systemes 2006
// load dedicated to instance volatile implementation
#if defined(__CATLifInstance)
#define ExportedByCATLifInstance DSYExport
#else
#define ExportedByCATLifInstance DSYImport
#endif
#include "DSYExport.h"
