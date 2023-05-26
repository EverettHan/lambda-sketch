#ifndef CATSysCtrlCreate_h
#define CATSysCtrlCreate_h

// COPYRIGHT DASSAULT SYSTEMES 2003

#include <stdio.h>
#include "IUnknown.h"
#include "JS0CORBA.h"

/**
 * Class used to create .Ctrl files.
 */
class ExportedByJS0CORBA CATSysCtrlCreate
{
public:
  static HRESULT AddCtrlInfo(const char *iFwName , const char *iLibName );
  static void Write(FILE *TheOutput);
  static const char * GetCtrlName();
};

#endif // CATSysCtrlCreate_h




