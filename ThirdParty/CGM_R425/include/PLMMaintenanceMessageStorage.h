#ifndef PLMMaintenanceMessageStorage_h
#define PLMMaintenanceMessageStorage_h

#include "CATOMYCommunication.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "PLMMaintenanceMessageStreamId.h"
#include "CATBoolean.h"

class CATOmyStorageHandler;
class CATOmyStreamHandler;

class ExportedByCATOMYCommunication PLMMaintenanceMessageStorage
{
public:
  PLMMaintenanceMessageStorage(CATOmyStorageHandler * iStorage = NULL);
  ~PLMMaintenanceMessageStorage();
  
  PLMMaintenanceMessageStorage (PLMMaintenanceMessageStorage &);
  PLMMaintenanceMessageStorage& operator=(PLMMaintenanceMessageStorage&);

  void ReleaseStorage();

  HRESULT SetMessageStorage(CATOmyStorageHandler * iStorage);
  CATBoolean HasMessageStorage();

  CATOmyStreamHandler * GetLogInfoStream();
  CATOmyStreamHandler * GetMessageStream(const PLMMaintenanceMessageStreamId & iStreamId);
  CATBoolean HasMessageStream(const PLMMaintenanceMessageStreamId & iStreamId);

private:
  CATOmyStorageHandler * _Storage;
  CATUnicodeString _AuditLogName;
  friend class PLMMaintenanceMessageIterator;
};
#endif
