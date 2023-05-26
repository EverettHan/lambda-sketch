#ifndef CATIComSidlStreamTubeServices_h
#define CATIComSidlStreamTubeServices_h

#include "CATComSidl.h"
#include "CATIComSidlStreamTube.h"
#include "CATIComSidlStreamTubeServices.h"
#include "CATBaseUnknown.h"
#include "CATHashDico.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATComSidl IID IID_CATIComSidlStreamTubeServices;
#else
extern "C" const IID IID_CATIComSidlStreamTubeServies;
#endif

class ExportedByCATComSidl CATIComSidlStreamTubeServices : public CATBaseUnknown
{
	CATDeclareInterface;
public:
	virtual HRESULT BeginTubeServices() = 0;
	virtual HRESULT EndTubeServices() = 0;
	virtual HRESULT GetInfo(const char *iInfoName, void** oInfoValue) = 0;
	virtual	HRESULT	Ping(double &oLatency, double &oPacketLos, CATULONG32 iNbPing = 1) = 0;
	virtual HRESULT SetTubeParameters(CATHashDico *iConnectionParameters) = 0;
	virtual HRESULT GetTubeParameters(CATHashDico *oConnectionParameters) = 0;
	virtual HRESULT Upload(double iLatency, double &oUploadInByteBySec) = 0;
	virtual HRESULT Download(double iLatency, double &oDownloadInByteBySec) = 0;
	virtual HRESULT Timeout() = 0;
	virtual HRESULT SetServerURL(const char *iServerUrl) = 0;
	virtual HRESULT SetMaxWaitingTimeout(int iMaxWaitingTimout) = 0;
};

CATDeclareHandler(CATIComSidlStreamTubeServices, CATBaseUnknown);

extern "C" ExportedByCATComSidl long CATComSidlCheckNetworkStatus(void *);

#endif
