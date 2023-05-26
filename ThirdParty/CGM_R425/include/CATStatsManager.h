// COPYRIGHT DASSAULT SYSTEMES 2008

#ifndef CATStatsManager_H
#define CATStatsManager_H
/************************************************************************/
/* Defines                                                              */
/************************************************************************/
#define CATSTATS_DEFAULT_STRING_SIZE          128
#define CATSTATS_DEFAULT_TEMPBUFFER_SIZE      2048

/************************************************************************/
/* Global includes                                                      */
/************************************************************************/

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
#include "CATIStatsManager.h"
#include "CATIStatsThematics.h"
#include "DSYSysStatisticsDef.h"
#include "CATEventSubscriberTypedefs.h"

class CATStatsThematics;

class DSYSysStatsEventSlot;
class DSYSysStatsEventGroupSlot;
class DSYSysStatsEventStatisticSlot;
class DSYSysStatsSlotHandler;

class DSYSysStatsFileStream;
class DSYSysStatsFileStreamHandler;

/************************************************************************/
/* Functions prototypes                                                 */
/************************************************************************/

/************************************************************************/
/* Classes declaration                                                  */
/************************************************************************/
//===============================================================
// This class allows centralized management of CATStatsThematics
//===============================================================
class ExportedByJS03TRA CATStatsManager : public CATBaseUnknown
{
  ///////////////////////////////////////////
  ////// Types/Constants/Struct/Enum ////////
  ///////////////////////////////////////////
public:

  ///////////////////////////////////////////
  ///////////////// Methods /////////////////
  ///////////////////////////////////////////
public:
  /// CATBaseUnknown declarations
  CATDeclareClass;

public:
  /// Constructor (Default)
  CATStatsManager();

  /// Destructor
  virtual ~CATStatsManager();

  /// Obtain a statistics thematic interface
  virtual CATIStatsThematics* GetThematics( const char *iThematicsThem, int iReservedForNow  =0);

  /// Force the update of statistics to take into account tools/option changes
  virtual HRESULT UpdateConfiguration(int iReserved);

  /// Closes all statistics thematics and  dump the results
  virtual HRESULT CloseAll(int iReserved=0);

  /// Methods that allow the enumeration of actives Statistics for the ToolsOption
  virtual HRESULT GetFirstActiveStatisticName (CATUnicodeString& oName);
  virtual HRESULT GetNextActiveStatisticName (CATUnicodeString& oName);

  /// List the path of active statictics
  virtual HRESULT CollectStatisticsLogFilePath(CATListOfCATUnicodeString& oListOfPath, bool iActiveOnly = true);

public:
  /// Error managment
  void Error(int ErrorCode, int LineNo, const char *iInfo = NULL);

  /// Activate session thematics
  static HRESULT ActivateSessionThematics(const char* pAppName = NULL);

  /// Deactivate session thematics
  static HRESULT DeActivateSessionThematics(void);

public:
  /// Initialization
  HRESULT Initialize(void);

  /// System suspend
  HRESULT SystemSuspend(void);

  /// System Resume
  HRESULT SystemResume(void);

  /// Get status handler
  DSYSysFlag& GlobalStatus(void)
  { return m_Status; }

  /// Get default directory
  const char* GetDefaultDir(void);

  /// Get overall output file name
  CATUnicodeString& OverAllOutputFileName(void)
  { return m_OverAllOutputFileName; }

  /// Get buffer size
  size_t& BufferLength(void)
  { return m_BufferLength; }

  /// Get number maximum of files
  size_t& MaxNumberOfFiles(void)
  { return m_MaxNumberOfFiles; }

  /// Get file size maximum length
  size_t& MaxPerFileSize(void)
  { return m_MaxPerFileSize; }

  /// Get the directory for copy
  CATUnicodeString& NameOfCopyDirectory(void)
  { return m_CopyDirectory; }

  /// Get user name
  const char* GetUserName(void) const
  { return (const char *)m_pUserName; }

  /// Get host name
  const char* GetHostName(void) const
  { return (const char *)m_pHostName; }

  /// Get pid
  const char* GetPid(void) const
  { return (const char *)m_pBufPid; }

  /// Get event count
  size_t& EventNo(void)
  { return m_EventNo; }

  /// Analyse Option file path
  HRESULT AnalyseOptionFilePath(const char* pFileName);

  /// Stream handler management
  DSYSysStatsFileStream* GetStream(const char* pStreamId) const;
  DSYSysStatsFileStream* GetNewStream(void) const;

  /// Event slot management
  DSYSysStatsEventSlot* GetEventSlot(CATStatsEventId iSlotId);
  DSYSysStatsEventSlot* GetEmptyEventSlot(void);
  DSYSysStatsEventSlot* GetFirstEventSlot(void);
  DSYSysStatsEventSlot* GetNextEventSlot(void);

  /// Group event slot management
  DSYSysStatsEventGroupSlot* GetGroupSlot(CATStatsGroupId iSlotId);
  DSYSysStatsEventGroupSlot* GetEmptyGroupSlot(void);
  DSYSysStatsEventGroupSlot* GetFirstGroupSlot(void);
  DSYSysStatsEventGroupSlot* GetNextGroupSlot(void);

  /// Statistic event slot management
  DSYSysStatsEventStatisticSlot* GetEmptyStatisticSlot(void);

  /// Reset read settings flag for all thematics
  HRESULT ResetReadSettings(void);

  /// Chech value limits
  HRESULT CheckGlobalSettingsValues(void);

public:
  /// Get temporary string buffer
  char* GetTempString(size_t i = 0) const
  { return (char *)m_ppTempStringBuffer[i]; }

  /// Get temporary string buffer size
  size_t GetTempStringSize(void) const
  { return sizeof(m_ppTempStringBuffer[0]); }

  /// Get session time
  DSYSysStatsUTCTimeStruct& SessionTime(void)
  { return m_SessionTimeInfo; }

protected:
  /// Create a new thematic
  CATStatsThematics* GetThematicByName(const char* ipThematicName);

private:
  /// Set default values
  void SetMembersDefaultValue(void);

  /// Destroy members
  void ReleaseMembers(void);
  
  void callBackMethod(CATCallbackEvent iCBE, void* ipData, CATNotification*ipNotif, CATSubscriberData iData, CATCallback iCB);

  ///////////////////////////////////////////
  ///////////////// Members /////////////////
  ///////////////////////////////////////////
public:
  /// The S_StatsManager singleton
  static CATStatsManager* S_StatsManager;

  /// Action flag
  static int S_DoItOnce;

protected:
  /// Max size per file setting (if set)
  size_t m_MaxPerFileSize;

  /// Max number of files in copy directory
  size_t m_MaxNumberOfFiles;

  /// Buffer size (if set)
  size_t m_BufferLength;

  /// Table of thematics
  CATStatsThematics* m_ppThmTable[S_ActiveThematicsNamesCount];

  /// Session user name
  char m_pUserName[CATSTATS_DEFAULT_STRING_SIZE];

  /// Host name of the current session
  char m_pHostName[CATSTATS_DEFAULT_STRING_SIZE];

  /// Process identifier of the CATStatsManager
  char m_pBufPid[CATSTATS_DEFAULT_STRING_SIZE];

  /// Port de sortie si m_Output=PORT
  unsigned short m_Port;

  /// Default output type
  int m_Output;
  
  /// Default ouput file
  CATUnicodeString m_OverAllOutputFileName;

  /// Global status for all thematics
  DSYSysFlag m_Status;

  /// Slot handler engine
  DSYSysStatsSlotHandler* m_pSlotHandler;

  /// Slot handler engine
  DSYSysStatsSlotHandler* m_pGroupSlotHandler;

  /// Slot handler engine
  DSYSysStatsSlotHandler* m_pStatisticSlotHandler;

  /// Stream handler engine
  DSYSysStatsFileStreamHandler* m_pFileStreamHandler;

  /// Event counter (ensure first session log version)
  size_t m_EventNo;

  /// Session time
  DSYSysStatsUTCTimeStruct m_SessionTimeInfo;

private:
  /// Current Active thematics index
  size_t m_CurrentStatEnum;

  /// Path to the OptionFile (if any)
  CATUnicodeString m_OptionsFilePath;

  /// Default directory for statistics
  CATUnicodeString m_DefaultDir;

  /// Directory for multiple copy
  CATUnicodeString m_CopyDirectory;

private:
  /// Temporary buffer area
  char m_ppTempStringBuffer[2][CATSTATS_DEFAULT_TEMPBUFFER_SIZE];
};
#endif  // CATStatsManager_H
