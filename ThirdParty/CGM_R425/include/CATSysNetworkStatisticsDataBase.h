#ifndef CATSysNetworkStatisticsDataBase_H
#define CATSysNetworkStatisticsDataBase_H

// COPYRIGHT DASSAULT SYSTEMES 2008

/************************************************************************/
/* Defines                                                              */
/************************************************************************/

/** Network statistics indicators */
enum CATSysNetworkStatisticsIndicators
{
  /* Misceanellous */

  // First indicator (may not be used)
  First_NetworkStatIndex = 0

  /* Network statistics indicators */

  // SIDL
, NbSendPacket_NetworkStatIndex
, SendPacketMaxSize_NetworkStatIndex
, SendPacketMinSize_NetworkStatIndex
, SendPacketAvgSize_NetworkStatIndex
, NbSendCompressPacket_NetworkStatIndex
, SendMinCompressRatio_NetworkStatIndex
, SendMaxCompressRatio_NetworkStatIndex
, SendAvgCompressRatio_NetworkStatIndex
, NbSendPacketOK_NetworkStatIndex

, NbReceivedPacket_NetworkStatIndex
, ReceivedPacketMaxSize_NetworkStatIndex
, ReceivedPacketMinSize_NetworkStatIndex
, ReceivedPacketAvgSize_NetworkStatIndex
, NbReceivedCompressPacket_NetworkStatIndex
, ReceivedMinCompressRatio_NetworkStatIndex
, ReceivedMaxCompressRatio_NetworkStatIndex
, ReceivedAvgCompressRatio_NetworkStatIndex
, NbReceivedPacketOK_NetworkStatIndex

, NbRequest_NetworkStatIndex
, RequestMaxSize_NetworkStatIndex
, RequestMinSize_NetworkStatIndex
, RequestAvgSize_NetworkStatIndex
, RequestSizeSum_NetworkStatIndex
, RequestNetMaxSize_NetworkStatIndex
, RequestNetMinSize_NetworkStatIndex
, RequestNetAvgSize_NetworkStatIndex
, RequestNetSizeSum_NetworkStatIndex
, RequestMinCompressRatio_NetworkStatIndex
, RequestMaxCompressRatio_NetworkStatIndex
, RequestAvgCompressRatio_NetworkStatIndex
, RequestMaxNbPacket_NetworkStatIndex
, RequestMinNbPacket_NetworkStatIndex
, RequestAvgNbPacket_NetworkStatIndex

, NbResponse_NetworkStatIndex
, ResponseMaxSize_NetworkStatIndex
, ResponseMinSize_NetworkStatIndex
, ResponseAvgSize_NetworkStatIndex
, ResponseSizeSum_NetworkStatIndex
, ResponseNetMaxSize_NetworkStatIndex
, ResponseNetMinSize_NetworkStatIndex
, ResponseNetAvgSize_NetworkStatIndex
, ResponseNetSizeSum_NetworkStatIndex
, ResponseMinCompressRatio_NetworkStatIndex
, ResponseMaxCompressRatio_NetworkStatIndex
, ResponseAvgCompressRatio_NetworkStatIndex
, ResponseMaxNbPacket_NetworkStatIndex
, ResponseMinNbPacket_NetworkStatIndex
, ResponseAvgNbPacket_NetworkStatIndex

, NbSidlRequestForClientVersion_NetworkStatIndex
, SidlRequestForClientVersionRatio_NetworkStatIndex

, UploadByteRateMin_NetworkStatIndex
, UploadByteRateMax_NetworkStatIndex
, UploadByteRateAvg_NetworkStatIndex
, NbPacketUsedForUploadByteRate_NetworkStatIndex
, PacketUsedForUploadByteRateRatio_NetworkStatIndex

, DownloadByteRateMin_NetworkStatIndex
, DownloadByteRateMax_NetworkStatIndex
, DownloadByteRateAvg_NetworkStatIndex
, NbPacketUsedForDownloadByteRate_NetworkStatIndex
, PacketUsedForDownloadByteRateRatio_NetworkStatIndex

  // Internal SIDL Stats
, MaxSendCompressBufferSize_NetworkStatIndex
, MaxSendBufferSize_NetworkStatIndex
, MaxReceivedCompressBufferSize_NetworkStatIndex
, MaxReceivedBufferSize_NetworkStatIndex

  // Network Status SIDL Stats
, UploadByteRate_NetworkStatIndex
, DownloadByteRate_NetworkStatIndex
, Latency_NetworkStatIndex
, PacketLost_NetworkStatIndex

, UploadByteRateStatus_NetworkStatIndex
, DownloadByteRateStatus_NetworkStatIndex
, LatencyStatus_NetworkStatIndex
, PacketLostStatus_NetworkStatIndex
, GlobalNetworkStatus_NetworkStatIndex

  /* Misceanellous */

  // Last indicator (may not be used)
, Last_NetworkStatIndex
};

/************************************************************************/
/* Global includes                                                      */
/************************************************************************/

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
#include "JS03TRA.h"
#include "CATCallbackManager.h"

/************************************************************************/
/* Functions prototypes                                                 */
/************************************************************************/

/************************************************************************/
/* Classes declaration                                                  */
/************************************************************************/
/**
 * @CATSysNetworkStatisticsDataBase
 */
class ExportedByJS03TRA CATSysNetworkStatisticsDataBase : public CATBaseUnknown
{
  /// Declare implementation
  CATDeclareClass;

  ///////////////////////////////////////////
  ////// Types/Constants/Struct/Enum ////////
  ///////////////////////////////////////////
public:

  ///////////////////////////////////////////
  ///////////////// Methods /////////////////
  ///////////////////////////////////////////
public:
  /// Statistics Database Factory
  static CATSysNetworkStatisticsDataBase* GetNetworkStatisticsDataBase(void)
  {
    if ( CATSysNetworkStatisticsDataBase::S_pNetworkStatisticsDataBase == NULL )
      CATSysNetworkStatisticsDataBase::S_pNetworkStatisticsDataBase = new CATSysNetworkStatisticsDataBase();
    return CATSysNetworkStatisticsDataBase::S_pNetworkStatisticsDataBase;
  }

public:
  /// Commit a given entry at a given position in the embedded DB
  HRESULT Commit(unsigned int iPos, const double iEntry);

  /// Update a given entry at a given position in the embedded DB
  HRESULT Update(unsigned int iPos, double& oEntry) const;

public:
  /// Enable/disable
  void EnableSessionLog(bool iEnable = true)
  { m_SessionLogEnabled = iEnable; }

  /// Test if  enabled
  bool IsSessionLogEnabled() const
  { return m_SessionLogEnabled; }

public:
  /// Emit a notification with a given callback
  HRESULT EmitNotification(CATCallbackEvent iEventID);

  /// Declare updated statistics callback
  CATDeclareCBEvent(Statistics_Updated);

  /// Declare query statistics callback
  CATDeclareCBEvent(Statistics_StatusQuery);

private:
  /// Constructor
  CATSysNetworkStatisticsDataBase();

  /// Destructor
  virtual ~CATSysNetworkStatisticsDataBase();

  /// Copy constructor, not implemented
  CATSysNetworkStatisticsDataBase(const CATSysNetworkStatisticsDataBase& iObjectToCopy);

  /// Assignment operator, not implemented
  CATSysNetworkStatisticsDataBase & operator= (const CATSysNetworkStatisticsDataBase &iObjectToCopy);

  /// Initialize members
  void InitializeMembers(void);

  /// Release members
  void ReleaseMembers(void);

  /// Unfactory
  static int LetNetworkStatisticsDataBase(int iExitCode);

  ///////////////////////////////////////////
  ///////////////// Members /////////////////
  ///////////////////////////////////////////
protected:
#define CATSYS_NETWORK_STAT_DATABASE_SIZE         512
  /// The internal data base object
  double m_EmbeddedDataBase[CATSYS_NETWORK_STAT_DATABASE_SIZE];

  /// Flag to enable permanente network statistics log
  bool m_SessionLogEnabled;

private:
  /// Global network statistics singleton
  static CATSysNetworkStatisticsDataBase* S_pNetworkStatisticsDataBase;
};

//===============================================================
//===============================================================

/// Brand new call for the database object
#undef TheNetworkStatisticsDataBase
#define TheNetworkStatisticsDataBase    CATSysNetworkStatisticsDataBase::GetNetworkStatisticsDataBase

#endif  // CATSysNetworkStatisticsDataBase_H
