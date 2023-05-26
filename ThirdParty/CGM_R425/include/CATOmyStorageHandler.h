#ifndef CATOmyStorageHandler_h
#define CATOmyStorageHandler_h

#include "CATOMYBaseSession.h"
#include "CATBaseUnknown.h"
#include "CATOmxMutex.h"

/**
* @level Protected
* @usage U4 CATOmyStorageHandler
*/

class CATStorage;
class CATStream;
class CATUnicodeString;
class CATOmyStreamHandler;
class ExportedByCATOMYBaseSession CATOmyStorageHandler : public CATBaseUnknown
{
  CATDeclareClass;
public:
  CATOmyStorageHandler(CATOmyStorageHandler * iFatherHandler, CATStorage * iStorageToManage, CATBoolean iCloseOnDelete=TRUE);
  CATOmyStorageHandler(const CATUnicodeString &iPathToStorage, DWORD iOpenMode, CATBoolean iCloseOnDelete=TRUE);
  ~CATOmyStorageHandler();
  CATOmyStorageHandler * OpenStorage(const CATUnicodeString &iStorageName, DWORD iOpenMode, CATBoolean iCloseOnDelete=TRUE);
  CATOmyStreamHandler * OpenStream(const CATUnicodeString &iStreamName, DWORD iOpenMode);
  CATBoolean HasStream(const CATUnicodeString &iStreamName);
  CATStorage * GetStorage();
  HRESULT Commit();
private:
  CATOmyStorageHandler * _Father;
  CATStorage * _Storage;
  CATBoolean _CloseOnDelete, _UnlockOnDelete;
  static CATOmx::mutex & mutex() { static CATOmx::mutex sMutex; return sMutex;}
};
#endif
