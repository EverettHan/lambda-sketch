#ifndef PLMMaintenanceMessageIterator_h
#define PLMMaintenanceMessageIterator_h

#include "CATOMYCommunication.h"
#include "IUnknown.h"
#include "CATWTypes.h"

class PLMMaintenanceMessageStorage;
class PLMMaintenanceMessageStreamId;
class CATStorage;

class ExportedByCATOMYCommunication PLMMaintenanceMessageIterator
{
public:
  PLMMaintenanceMessageIterator(const PLMMaintenanceMessageStorage & iMsgStorage);
  // return S_OK if an new Id have been retrived, S_FALSE if we reached the end.
  HRESULT GetNextMessageStreamId(PLMMaintenanceMessageStreamId & oMsgStreamId);
private:
  CATStorage * _Storage;
  int _ShouldBeInitiliazed;

  HRESULT ConvertSTATSTGToStreamId(STATSTG & stat,PLMMaintenanceMessageStreamId & oMsgStreamId);
};
#endif
