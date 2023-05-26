/* COPYRIGHT DASSAULT SYSTEMES 2008 */


#ifndef CATSysDRMDriver_H
#define CATSysDRMDriver_H

#include "CATWTypes.h"
#include "CATErrorDef.h"
#include "CATSysDRMHR.h"
#include "CATUnicodeString.h"

#if defined __JS0DRMDOC
#define ExportedByJS0DRMDOC DSYExport
#else
#define ExportedByJS0DRMDOC DSYImport
#endif
#include "DSYExport.h"





class CATSysDRMDocument;


class ExportedByJS0DRMDOC  CATSysDRMDriver : public 
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
  CATSysDRMDriver():
#ifdef _TS_DRM
CATSysTSBaseUnknown(true),
#endif
_SysDRMDoc(0){};
  virtual ~CATSysDRMDriver();

  virtual HRESULT  SetDocument ( CATSysDRMDocument* iDoc);

 protected:
  CATSysDRMDocument *_SysDRMDoc;

};

#endif



