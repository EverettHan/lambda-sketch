#ifndef CATMRUManager_h
#define CATMRUManager_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include <CATAfrFoundation.h>
#include <CATCallbackManager.h>
#include <CATUnicodeString.h>

class CATSettingRepository;

class ExportedByCATAfrFoundation CATMRUManager : public CATCallbackManager
{
public:

  CATDeclareClass;

  static CATMRUManager * GetMRUManager();
  
  ~CATMRUManager();
  
  CATUnicodeString GetMRU(int);
  CATUnicodeString GetMRUTitle(int);
  void SetMRU(const CATUnicodeString &);
  
  CATDeclareCBEvent(MRUModified);
  
private:
  
  CATMRUManager();
  
  CATUnicodeString BuildTitle(const CATUnicodeString &);
  
  CATUnicodeString _mru[5];
  CATUnicodeString _mruTitle[5];
  CATSettingRepository * _rep;
};

#endif
