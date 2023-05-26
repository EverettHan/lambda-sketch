// COPYRIGHT DASSAULT SYSTEMES 2003
#ifndef _CATDbSettings_h
#define _CATDbSettings_h

#if defined(__CATSysDbSettings)
#define ExportedByCATSysDbSettings DSYExport
#else
#define ExportedByCATSysDbSettings DSYImport
#endif
#include "DSYExport.h"

#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATDbListOfServer.h"

class  ExportedByCATSysDbSettings CATDbSettings : public CATBaseUnknown 
{
  friend class CATMarshallableDbSettings;
  CATDeclareClass;

  CATDbSettings(const CATDbSettings &);
  CATDbSettings & operator=(const CATDbSettings &);
  
  public :
  CATDbSettings ();
  ~CATDbSettings ();
  CATDbListOfServer * GetListOfServer() const;
  
  protected :
  int _Size;
  CATDbListOfServer _ListOfServer ;
};

#endif // _CATDbSettings_
