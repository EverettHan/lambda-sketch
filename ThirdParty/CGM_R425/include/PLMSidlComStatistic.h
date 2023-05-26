#ifndef PLMSidlComStatistic_H
#define PLMSidlComStatistic_H

//#include "CATComSidl.h"
#ifndef ExportedByCATComSidl
#if defined(__CATComSidl)
#define ExportedByCATComSidl DSYExport
#else
#define ExportedByCATComSidl DSYImport
#endif
#include "DSYExport.h"
#endif

#include "CATSysNetworkStat.h"
#include "CATErrorExit.h"

#include "CATSysNetworkStatisticsDataBase.h"

#include "CATSysElapseTime.h"
#include "CATEventSubscriber.h"

#include "CATMutex.h"

#ifdef __cplusplus
extern "C" {
#endif
typedef struct
{
    //SIDL
    //NbSendPacket; count of next field
    CATINTPTR* p_SendPacketSize; //SendPacketMinSize //SendPacketAvgSize
    //NbSendCompressPacketPtr; count of next field
    CATINTPTR* p_SendPacketCompressRatio; //SendMaxCompressRatio //SendAvgCompressRatio
    CATINTPTR* p_NbSendPacketOK;

    //NbRecievedPacket; count of next field
    CATINTPTR* p_RecievedPacketSize; //RecievedPacketMinSize //RecievedPacketAvgSize
    //NbRecievedCompressPacket; count of next field
    CATINTPTR* p_RecievedPacketCompressRatio; //RecievedMaxCompressRatio //RecievedAvgCompressRatio
    CATINTPTR* p_NbRecievedPacketOK;

    //NbRequest; count of next field
    CATINTPTR* p_RequestSize; //RequestMinSize //RequestAvgSize
    CATINTPTR* p_RequestNetSize; //RequestNetMinSize //RequestNetAvgSize
    CATINTPTR* p_RequestCompressRatio; //RequestMaxCompressRatio //RequestAvgCompressRatio
    CATINTPTR* p_RequestNbPacket; //RequestMinNbPacket //RequestAvgNbPacket

    //NbResponse; count of next field
    CATINTPTR* p_ResponseSize; //ResponseMinSize //ResponseAvgSize
    CATINTPTR* p_ResponseNetSize; //ResponseNetMinSize //ResponseNetAvgSize
    CATINTPTR* p_ResponseCompressRatio; //RequestMaxCompressRatio //RequestAvgCompressRatio
    CATINTPTR* p_ResponseNbPacket; //ResponseMinNbPacket //ResponseAvgNbPacket

    CATINTPTR* p_CurUploadByteRate;
    CATINTPTR* p_UploadByteRate; //UploadByteRateMax //UploadByteRateAvg
    CATINTPTR* p_NbPacketUsedForUploadByteRate;
    CATINTPTR* p_PacketUsedForUploadByteRateRatio;
    CATINTPTR* p_CurDownloadByteRate;
    CATINTPTR* p_DownloadByteRate; //DownloadByteRateMax //DownloadByteRateAvg
    CATINTPTR* p_NbPacketUsedForDownloadByteRate;
    CATINTPTR* p_PacketUsedForDownloadByteRateRatio;

    //Internal SIDL Stat
    CATINTPTR* p_SendCompressBufferSize; //Max //Min //Avg
    CATINTPTR* p_SendBufferSize; //Max //Min //Avg
    CATINTPTR* p_RecievedCompressBufferSize; //Max //Min //Avg
    CATINTPTR* p_RecievedBufferSize; //Max //Min //Avg
} CATComSidlStatsManager;
#ifdef __cplusplus
};
#endif

ExportedByCATComSidl int PLMSidlComOnExit(int iExitCode);

class ExportedByCATComSidl PLMSidlComStatistic 
{
private:
	PLMSidlComStatistic();
	~PLMSidlComStatistic();
	// increase the number of send failed or succeded
	HRESULT	SetSendPacketStatus(HRESULT ihr);

	// increase the number of reciev failed or succeded
	HRESULT	SetRecievedPacketStatus(HRESULT ihr);

	// Set he MIN or MAX data size by comparing old MIN and old MAX to the current size
	// also compute the MID data size (Add all size in a long long)
	HRESULT	SetSendDataSizeStatistic(CATULONG32 iSize);
	HRESULT	SetRecievedDataSizeStatistic(CATULONG32 iSize);

	HRESULT	SetSendCompressRatio(CATULONG32 iSize, CATULONG32 iCompSize);

	HRESULT	SetRecievedCompressRatio(CATULONG32 iSize, CATULONG32 iCompSize);

	HRESULT	SetSendCompressBufferSize(CATULONG32 iSize);
	HRESULT	SetSendBufferSize(CATULONG32 iSize);

	HRESULT	SetRecievedCompressBufferSize(CATULONG32 iSize);
	HRESULT	SetRecievedBufferSize(CATULONG32 iSize);
	HRESULT	PLMSidlComStatisticFlush(const char *iStatName, const char *iValueName, unsigned int iLevel, CATINTPTR* iStatPointer, unsigned long iStatType);

	HRESULT PLMSidlComStatisticInitAllStat(void);
	HRESULT PLMSidlComStatisticReleaseAllStat(void);
	HRESULT DisableStat();
	HRESULT EnableStat();

public:
	static PLMSidlComStatistic*	getInstance();
	static void                 releaseInstance();
    HRESULT                     PLMSidlComStatisticFlushAll();
	HRESULT						PLMSidlComStatisticFlushByRequest();
    HRESULT                     PLMSidlComStatisticResetRequestStat();
    HRESULT                     PLMSidlComStatisticResetAllStat();
	HRESULT						PLMSidlComHttpStreamStatisticsUpdateNotification(CATBoolean iNotif);
	HRESULT						PLMSidlComHttpStreamStatisticsUpdateNotificationUpload(CATBoolean iNotif);
	HRESULT						PLMSidlComHttpStreamStatisticsUpdateNotificationDownload(CATBoolean iNotif);

    HRESULT                     AddARequest();
	HRESULT                     AddAResponse();

	HRESULT						SetServerUrl(char *iUrl);
	char*						GetServerUrl();

	HRESULT						SetRefreshMode(bool iMode);

	HRESULT                     UpdateSendPacketStatistic(HRESULT ihr, CATULONG32 iSize, CATULONG32 iCompSize, bool iIsCompressed, CATULONG32 iBuffSize, CATULONG32 iCompBuffSize);
	HRESULT                     UpdateRecievedPacketStatistic(HRESULT ihr, CATULONG32 iSize, CATULONG32 iCompSize, bool iIsCompressed, CATULONG32 iCompBuffSize);

private:
    //Client statistic
	CATULONG32							_RequestSize;
	CATULONG32							_RequestNetSize;
    CATULONG32							_ResponseSize;
    CATULONG32							_ResponseNetSize;
    CATULONG32							_RequestNbPacket;
    CATULONG32							_ResponseNbPacket;
    CATComSidlStatsManager*				_NetStatisticsManager;
	CATSysNetworkStatisticsDataBase*	_pDataBase;
	int									_Level0;
	int									_Level1;
	int									_Level2;
	int									_Level3;
	char*								_ServerUrl;
	bool								_IsRefresh;
	bool								_AllStatInitialized;


    CATStatsEventId						_Id_SessionGeneric;
	CATMutex							_PLMSidlComStatisticMutex;

public:
	int									_IsStatEnable;
	//Server statistic
};

#endif
