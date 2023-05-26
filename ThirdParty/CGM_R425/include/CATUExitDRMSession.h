// COPYRIGHT DASSAULT SYSTEMES  2001
#ifndef CATUExitDRMSession_h
#define CATUExitDRMSession_h

#ifndef _TS_DRM
#include "CATBaseUnknown.h"
#else
#include "CATSysTSBaseUnknown.h"
#endif
#include "JS0ERROR.h"


class ExportedByJS0ERROR CATUExitDRMSession : public 
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
  
  public :
  
  /** @nodoc */
  CATUExitDRMSession();
  
  /** @nodoc */
  virtual ~CATUExitDRMSession();
  HRESULT  __stdcall QueryInterface(const IID &iIID,  void **oPPV);
 private:
#ifndef _TS_DRM
  CATBaseUnknown *_DRMDrvS;
#else
  CATSysTSBaseUnknown *_DRMDrvS;
#endif
};

#endif
