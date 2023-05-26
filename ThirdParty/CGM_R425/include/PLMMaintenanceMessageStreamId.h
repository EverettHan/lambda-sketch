#ifndef PLMMaintenanceMessageStreamId_h
#define PLMMaintenanceMessageStreamId_h

#include "CATUnicodeString.h"
#include "CATOMYCommunication.h"
#include "IUnknown.h"

enum PLMMaintenanceMessageStreamType{output, input, callstack};
const CATUnicodeString ExportedByCATOMYCommunication ConvertMessageTypeToString(PLMMaintenanceMessageStreamType iType);
HRESULT ExportedByCATOMYCommunication ConvertStringToMessageType(const CATUnicodeString &iTypeConvertedToString,
                                                                 PLMMaintenanceMessageStreamType &oType);

class ExportedByCATOMYCommunication PLMMaintenanceMessageStreamId
{
public:
  PLMMaintenanceMessageStreamId(const CATUnicodeString &iProcessorClass, int iIndex, PLMMaintenanceMessageStreamType iType);
  PLMMaintenanceMessageStreamId();

  CATUnicodeString ConvertToString() const;
  HRESULT BuildFromString(const CATUnicodeString &iIdConvertedToString);

  inline CATUnicodeString GetMessageProcessorClass() const {return _ProcessorClass;};
  inline int GetMessageIndex() const {return _Index;};
  inline PLMMaintenanceMessageStreamType GetMessageType() const {return _Type;};

private:
  CATUnicodeString _ProcessorClass;
  int _Index;
  PLMMaintenanceMessageStreamType _Type;

  int ExtractTokens(const CATUnicodeString &iIdConvertedToString,CATUnicodeString tokens[3]);
};
#endif
