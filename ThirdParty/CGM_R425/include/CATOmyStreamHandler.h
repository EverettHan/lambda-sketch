#ifndef CATOmyStreamHandler_h
#define CATOmyStreamHandler_h

/**
 * @level Protected
 * @usage U3
 */

#include "CATOMYBaseSession.h"
#include "CATBaseUnknown.h"

class CATStorage;
class CATStream;
class CATUnicodeString;
class CATOmyStorageHandler;
class ExportedByCATOMYBaseSession CATOmyStreamHandler : public CATBaseUnknown
{
  CATDeclareClass;
public:
  CATOmyStreamHandler(CATOmyStorageHandler * iFatherHandler, CATStream * iStreamToManage);
  ~CATOmyStreamHandler();

  HRESULT Read  (char * iWhereToPutReadData, ULONG iLength, ULONG * iRead);
  HRESULT Write (const char * iWhatToWrite,  ULONG iLength, ULONG * iWriten);
  HRESULT Append(const char * iWhatToWrite,  ULONG iLength, ULONG * iWriten);

  CATStream * GetStream();
private:
  CATStream * _Stream;
  CATOmyStorageHandler * _Father;
};
#endif
