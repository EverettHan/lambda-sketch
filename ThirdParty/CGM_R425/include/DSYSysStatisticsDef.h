# ifndef _DSYSYSSTATDEF
# define _DSYSYSSTATDEF

#include "CATLib.h"
#include "DSYSysFlag.h"
#include "DSYSysTSStatisticsDef.h"

// COPYRIGHT DASSAULT SYSTEMES 2008



/************************************************************************/
/* Statistics field definitions                                         */
/************************************************************************/
/** Statistics identifiers */
enum
{
  OCC_STAT = 0    /* 0 */
, SUM_STAT        /* 1 */
, AVG_STAT        /* 2 */
, MIN_STAT        /* 3 */
, MAX_STAT        /* 4 */
, VAR_STAT        /* 5 */
, STD_STAT        /* 6 */
, STR_STAT        /* 7 */
};

/** Array of statistics tag names */
static const char* const S_pStatisticsFieldNames[] =
{
  "statocc" /* 0 */
, "statsum" /* 1 */
, "statavg" /* 2 */
, "statmin" /* 3 */
, "statmax" /* 4 */
, "statvar" /* 5 */
, "statstd" /* 6 */
, "statstr" /* 7 */
};

/** Statistics field name defines */
#define OCC_STATISTICS_FIELDNAME      S_pStatisticsFieldNames[OCC_STAT]
#define SUM_STATISTICS_FIELDNAME      S_pStatisticsFieldNames[SUM_STAT]
#define AVG_STATISTICS_FIELDNAME      S_pStatisticsFieldNames[AVG_STAT]
#define MIN_STATISTICS_FIELDNAME      S_pStatisticsFieldNames[MIN_STAT]
#define MAX_STATISTICS_FIELDNAME      S_pStatisticsFieldNames[MAX_STAT]
#define VAR_STATISTICS_FIELDNAME      S_pStatisticsFieldNames[VAR_STAT]
#define STD_STATISTICS_FIELDNAME      S_pStatisticsFieldNames[STD_STAT]
#define STR_STATISTICS_FIELDNAME      S_pStatisticsFieldNames[STR_STAT]

/************************************************************************/
/* Statistics flags definitions                                         */
/************************************************************************/

/** Statistics manager flags */
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagMgrDftActive          , DSYSysUI64PostFix(0x0000000000000001)/* CATStatsMgrDftActive */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagMgrDftNoDefault       , DSYSysUI64PostFix(0x0000000000000002)/* CATStatsMgrDftNoDefault */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagMgrIgnoreSettings     , DSYSysUI64PostFix(0x0000000000000004)/* CATStatsMgrIgnoreSettings */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagMgrExpliciteBuffer    , DSYSysUI64PostFix(0x0000000000000008)/* CATStatsMgrExpliciteBuffer */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagMgrLimitedFSize       , DSYSysUI64PostFix(0x0000000000000010)/* CATStatsMgrLimitedFSize */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagMgrRemoveFromList     , DSYSysUI64PostFix(0x0000000000000020)/* CATStatsMgrRemoveFromList */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagMgrStatsScheduling    , DSYSysUI64PostFix(0x0000000000000040));
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagMgrStatsUsageCollect  , DSYSysUI64PostFix(0x00000000000000A0));

/** Statistics setting options flags */
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagDftOptionIdentify       , DSYSysUI64PostFix(0x0000000000010000)/* CATStatsDftOptionIdentify */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagDftOptionActive         , DSYSysUI64PostFix(0x0000000000020000)/* CATStatsDftOptionActive */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagDftOptionNoFieldNames   , DSYSysUI64PostFix(0x0000000000040000)/* CATStatsDftOptionNoFieldNames */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagDftOptionSetSeparator   , DSYSysUI64PostFix(0x0000000000080000)/* CATStatsDftOptionSetSeparator */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagDftOptionCumulative     , DSYSysUI64PostFix(0x0000000000100000)/* CATStatsDftOptionCumulative */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagDftOptionSuspendable    , DSYSysUI64PostFix(0x0000000000200000)/* CATStatsDftOptionSuspendable */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagActive                  , DSYSysUI64PostFix(0x0000000000000001)/* CATStatsActive */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagExpliciteActivation     , DSYSysUI64PostFix(0x0000000000000002)/* CATStatsExpliciteActivation */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagIdentify                , DSYSysUI64PostFix(0x0000000000000004)/* CATStatsIdentify */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagAtLeast1Event           , DSYSysUI64PostFix(0x0000000000000008)/* CATStatsAtLeast1Event */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagCumulative              , DSYSysUI64PostFix(0x0000000000000010)/* CATStatsCumulative */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagSettingsFile            , DSYSysUI64PostFix(0x0000000000000020)/* CATStatsSettingsFile */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagSettingsRead            , DSYSysUI64PostFix(0x0000000000000040)/* CATStatsSettingsRead */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagSettingsAlreadyRead     , DSYSysUI64PostFix(0x0000000000000080)/* CATStatsSettingsAlreadyRead */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagSuspendable             , DSYSysUI64PostFix(0x0000000000000100)/* CATStatsSuspendable */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagAlreadyOpened           , DSYSysUI64PostFix(0x0000000000000200)/* CATStatsAlreadyOpened */);

/** Statistics optional field flags */
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtCPUS, DSYSysUI64PostFix(0x0000000000010000)/* CATStatsFmtCPUS */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtELPS, DSYSysUI64PostFix(0x0000000000020000)/* CATStatsFmtELPS */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtRTIM, DSYSysUI64PostFix(0x0000000000040000)/* CATStatsFmtRTIM */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtUPID, DSYSysUI64PostFix(0x0000000000080000)/* CATStatsFmtUPID */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtUSER, DSYSysUI64PostFix(0x0000000000100000)/* CATStatsFmtUSER */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtHOST, DSYSysUI64PostFix(0x0000000000200000)/* CATStatsFmtHOST */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtTHEM, DSYSysUI64PostFix(0x0000000000400000)/* CATStatsFmtTHEM */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtTIME, DSYSysUI64PostFix(0x0000000000800000)/* CATStatsFmtTIME */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtWKBN, DSYSysUI64PostFix(0x0000000000008000)/* CATStatsFmtWKBN */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtCMND, DSYSysUI64PostFix(0x0000000000004000)/* CATStatsFmtCMND */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtMSGE, DSYSysUI64PostFix(0x0000000000002000)/* CATStatsFmtMSGE */);

/** Statistics log format flags */
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtDefault              , DSYSysUI64PostFix(0x0000000000000000)/* CATStatsFmtDefault */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtNoFieldNames         , DSYSysUI64PostFix(0x0000000010000000)/* CATStatsFmtNoFieldNames */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtNoThematics          , DSYSysUI64PostFix(0x0000000080000000)/* CATStatsFmtNoThematics */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtHTML                 , DSYSysUI64PostFix(0x0000000020000000)/* CATStatsFmtHTML */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtSeconds              , DSYSysUI64PostFix(0x0000000001000000)/* CATStatsFmtSeconds */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtNumDates             , DSYSysUI64PostFix(0x0000000040000000)/* CATStatsFmtNumDates */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtNumDatesMillisecond  , DSYSysUI64PostFix(0x0000000000000100)/* CATStatsFmtNumDatesMillisecond */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtNumDates1970UTC      , DSYSysUI64PostFix(0x0000000000000200)/* DSYSysStatsFlagFmtNumDates1970UTC */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtCBE                  , DSYSysUI64PostFix(0x0000000002000000)/* CATStatsFmtCBE */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtWMI                  , DSYSysUI64PostFix(0x0000000100000000)/* CATStatsFmtWMI */);

/** Gravity level flags for error log */
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtABND, DSYSysUI64PostFix(0x0000000000001000)/* CATStatsFmtABND */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtCERR, DSYSysUI64PostFix(0x0000000000000800)/* CATStatsFmtCERR */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtWARN, DSYSysUI64PostFix(0x0000000000000400)/* CATStatsFmtWARN */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtCOMT, DSYSysUI64PostFix(0x0000000008000000)/* CATStatsFmtCOMT */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtUREP, DSYSysUI64PostFix(0x0000000004000000)/* CATStatsFmtUREP */);

/** Statistics suspension flags */
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagCPUReservationSuspend    , DSYSysUI64PostFix(0x0000000000000001)/* CATStatsCPUReservationSuspend */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagStealSuspension          , DSYSysUI64PostFix(0x0000000000000004)/* CATStatsStealSuspension */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagSystemSuspension         , DSYSysUI64PostFix(0x0000000000000008)/* CATStatsSystemSuspension */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagApplicativeSuspension    , DSYSysUI64PostFix(0x0000000000000002)/* CATStatsApplicativeSuspension */);
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagSuspendedForAnyReason    ,  ( DSYSysStatsFlagStealSuspension
                                                                      | DSYSysStatsFlagSystemSuspension
                                                                      | DSYSysStatsFlagApplicativeSuspension));

/** PCS statistics fields flags */
DSY_CONST_IFLAG_TO_SYSFLAG(DSYSysStatsFlagFmtMEMU, DSYSysUI64PostFix(0x0000000000000200)/* CATStatsFmtMEMU */);

/************************************************************************/
/* Thematics definitions                                                */
/************************************************************************/

/** Statistics error code */
#define CATStatsErrROFInvalidPolicy       1
#define CATStatsErrROFInvalidActivation   2
#define CATStatsErrROFInvalidPort         3
#define CATStatsErrROFInvalidOutput       4
#define CATStatsErrROFInvalidLine         5
#define CATStatsErrROFInvalidFile         6
#define CATStatsErrInvalidDir             7
#define CATStatsErrInvalidEnvDir          8
#define CATStatsErrInvalidSettingsLevel   9
#define CATStatsErrNoSettingRepository    10
#define CATStatsErrROFInvalidBufferLen    11
#define CATStatsErrROFInvalidMaxLimit     12
#define CATStatsErrROFInvalidNbCopies     13
#define CATStatsErrROFInvalidCopyDir      14
#define CATStatsErrRelease                15

#define STATSDEFAULTFILE                  "default_file"
#define STATSDEFAULTDIRECTORY             "default_directory"


/************************************************************************/
/* Thematics enum definitions                                           */
/************************************************************************/

// CATSysStatistics Time Unit
// --------------------------
/**
 * Time units for the statistics.
 * @param Millisecond
 *   durations are outputed in milliseconds
 * @param Second
 *   durations are outputed in seconds
 */
enum CATSysStatisticsTimeUnit { Millisecond, Second };


// CATSysStatistics Date Format
// ----------------------------
/**
 * Date formats for the statistics.
 * @param StandardDate
 *   date is outputed using the standart date format ( Mon Jan 1 08:00.00 2000 )
 * @param NumericalDate
 *   date is outputed using the numerical date format ( 2000.001.08.00.00 )
 * @param NumericalDateMillisecond
 *   date is outputed using the numerical date format ( 2000.001.08.00.00.000 )
 * @param NumericalDate1970UTC
 *   date is outputed using the numerical date using Unix timestamp format ( since 00:00 hours, Jan 1, 1970 UTC )
 */
enum CATSysStatisticsDateFormat { StandardDate, NumericalDate, NumericalDateMillisecond, NumericalDate1970UTC };


// CATSysStatistics Output Format
// ------------------------------
/**
 * Output formats for the statistics.
 * @param StandardOutput
 *   default output 
 * @param NoThematics
 *   the thematic name is not repeated on each line
 */
enum CATSysStatisticsOutputFormat { StandardOutput, NoThematics };

// CATSysStatistics Output Type
// ----------------------------
/**
 * Output type for the statistics.
 * @param Default
 *   default output
 * @param Console
 *   Console output
 * @param File
 *   File output
 * @param Port
 *   Socket output
 */
enum CATSysStatisticsOuputType { DefaultOuput = 0, ConsoleOuput, FileOuput, PortOuput };

// CATSysStatisticsFormat
// ----------------------
/**
 * Output format type for the statistics.
 * @param StandardFormat
 *   Standard format type
 * @param NoFieldsNameFormat
 *   Format without any fields
 * @param CBEFormat
 *   CBE format type
 * @param WMIFormat
 *   WMI format type
 */
enum CATSysStatisticsOuputFormatType { StandardFormat = 1, NoFieldsNameFormat, CBEFormat, WMIFormat };

// CATUTCTimeStruct
// ----------------
/**
 * UTC time structure
 */
#ifdef __cplusplus
extern "C" {
#endif
struct DSYSysStatsUTCTimeStruct
{
  /// Time
  CATTimeValue Time;

  /// Time complement
  CATLONG32 Bias;
};
#ifdef __cplusplus
};
#endif

/************************************************************************/
/* Misceanellous definitions                                           */
/************************************************************************/

#define _SaferSettings
#define FreeSettingRepo( a )

# endif /* _DSYSYSSTATDEF */
