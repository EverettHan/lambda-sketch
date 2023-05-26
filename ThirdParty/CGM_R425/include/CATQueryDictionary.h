#ifndef CATQueryDictionary_h
#define CATQueryDictionary_h


// COPYRIGHT DASSAULT SYSTEMES 2000

#include "JS0CORBA.h"
#include "IUnknown.h"
#include "CATBoolean.h"

ExportedByJS0CORBA const CLSID * CATGetCLSIDFromName(const char*Name);
ExportedByJS0CORBA const IID   * QueryDicoIIDNameByName(const char*Name);
ExportedByJS0CORBA const char  * QueryDicoIIDNameByIID(const IID &iid);

ExportedByJS0CORBA HRESULT       CATSysGetLibNameFromCtlg(const char* iClassName,const char* iKey,const char*& oLibName); 

// Returns TRUE if the component iComponentName supports the interface iInterfaceName.
ExportedByJS0CORBA CATBoolean    DoesComponentSupportInterface(const char * iComponentName,const char * iInterfaceName);

#endif
