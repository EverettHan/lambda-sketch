#ifndef CATComUtil_h
#define CATComUtil_h


// COPYRIGHT DASSAULT SYSTEMES 2000

#include "JS0CORBA.h"
#include "IUnknown.h"

int ExportedByJS0CORBA CATComCmp(IUnknown*iO1,IUnknown*iO2);
int ExportedByJS0CORBA ConvertStringToGUID(const char*str,GUID &xx);
int ExportedByJS0CORBA ConvertGUIDToString(const GUID xx, char ** str);

#endif
