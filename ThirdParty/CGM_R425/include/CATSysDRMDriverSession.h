/* COPYRIGHT DASSAULT SYSTEMES 2008 */


#ifndef CATSysDRMDriverSession_H
#define CATSysDRMDriverSession_H

#include "CATWTypes.h"
#include "CATErrorDef.h"
#include "CATSysDRMHR.h"
#ifndef _TS_DRM
#include "CATBaseUnknown.h"
#else
#include "CATSysTSBaseUnknown.h"
#endif

#if defined __JS0DRMDOC
#define ExportedByJS0DRMDOC DSYExport
#else
#define ExportedByJS0DRMDOC DSYImport
#endif
#include "DSYExport.h"



class ExportedByJS0DRMDOC  CATSysDRMDriverSession : public 
#ifndef _TS_DRM
CATBaseUnknown
#else
CATSysTSBaseUnknown
#endif
{
#ifndef _TS_DRM
  CATDeclareClass;
#else
CATSysTSDeclareClass;
#endif

public:
  CATSysDRMDriverSession():
#ifdef _TS_DRM
CATSysTSBaseUnknown(true),
#endif
_SysDRMSession(0){};
  virtual ~CATSysDRMDriverSession();

  virtual HRESULT  SetSession ( 
#ifndef _TS_DRM
CATBaseUnknown* iSession
#else
CATSysTSBaseUnknown* iSession 
#endif
);

 protected:
#ifndef _TS_DRM
  CATBaseUnknown *_SysDRMSession;
#else
  CATSysTSBaseUnknown *_SysDRMSession;
#endif

};

#endif



