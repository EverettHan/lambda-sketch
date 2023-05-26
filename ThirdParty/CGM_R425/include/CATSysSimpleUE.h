#ifndef CATSysSimpleUE_h
#define CATSysSimpleUE_h
// COPYRIGHT DASSAULT SYSTEMES 2002
#include "IUnknown.h"
#include "JS0SCBAK.h"
#include "CATMacForIUnknown.h"
#include "CATGetEntryPoint.h"

class ExportedByJS0SCBAK CATSysSimpleUE : public CATBaseUnknown
{
  CATDeclareClass;
  public:
  static HRESULT ImplementedSimpleUserExit(const char *iInf);
  static void *GetUserExit( const char *ExitName, const char*FuncName);
};
#endif
