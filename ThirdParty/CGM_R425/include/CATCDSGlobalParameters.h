// COPYRIGHT DASSAULT SYSTEMES 2002
//=============================================================================
//
// CATCDSGlobalParameters:
//   Class with only instance which contains global parameters such as ReplayMode.
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  Jun 2002  Creation
//=============================================================================

#ifndef CATCDSGlobalParameters_h
#define CATCDSGlobalParameters_h

#include "CATCDSUtilities.h"
#include "CATCDSBoolean.h"
#include "CATCDSString.h"
#include "CATCDSInline.h"
#include "CATCDSDebug.h"

#include <time.h>

class CATCDSStream;
class CATCDSUnderPlayBack;

/*

  CATCDSLevel:
    default value:  Open configuration
                      (value is updated every CGM delivery, see GlobalParameters.cpp, GetCDSFullOpenConfigurationLevel())
    if set to 0:    Void closed configuration
                      (level before versionning: CDS_10W36)
    if set to any
    positive value: Closed configuration
                      (if value less than default value; otherwise open configuration will be launched)

  CATCDSHFLevel:
    default value:  Open configuration
                      (value is updated every CGM delivery, see GlobalParameters.cpp, GetCDSHFOpenConfigurationLevel())
    if set to 0:    No HF level
    if set to any
    positive value: Closed configuration
                      (if value less than default value; otherwise open configuration will be launched)

  CATCDSForceOpenConfigurationLevels:
    if set to TRUE: force open configuration levels in CDS operators
    otherwise use the input levels (if any)

 * Infrastructure environment variables

  CATCDSReplayMode used as a mask:
    bit 0 - input model will be written to CDSReplay file.
    bit 1 - output model will be written to CDSReplay file.
    default: 0 (no models will be written)

  CATCDSReplayMethod:
    if set to FULL - input (and output) models will be written for all operators.
    if set to SI, AD, EG, ES, GD, GU or IM - input (and output) model for this operator
      will be written in CDSReplay file.
    default: ONCE (only first Operator::Run will generate models (if CATCDSReplayMode != 0))

  CATCDSReplayPath:
    if set to e.g. "E:\TMP" - save all CDSReplay files in this directory,
    otherwise save it under Globals->GetReplayFile name.
    default: E:\TMP (if not in ODT mode)

  CATCDSReplayPrefix:
    added to Replay filename.
    default: CATCDS (if not in ODT mode)

  CATCDSInputPath:
    if set to e.g. "E:\TMP\Input" - read data from CDSReplay files in this directory
      and substitute loaded data in RunOperator.
    default: empty

  CATCDSScriptMode:
    if set to FULL   - detailed script for multiple test will be written to CDSScript file
    if set to SIMPLE - simplifyed script for multiple test will be written to CDSScript file
    if set to NONE   - script willn't be written
    default: NONE

  CATCDSValidateMode:
    if set to COMPARE       - Constraint Solver will compare solution with some accuracy.
    if set to VALIDATE      - Constraint Solver will validate solution.
    if set to REGRESS       - Constraint Solver will validate solution and compare with original.
    if set to SIMPLECOMPARE - Constraint Solver will compare solution in simple mode.
    if set to NONE          - ReplayTest won't validate solutions.
    default: COMPARE (comparing transformations)

  CATCDSValidateDiagnostics:
    if set to TRUE - ReplayTest will check diag states for overdefined and inconsistent.
    default: FALSE

  CATCDSValidateMUC:
    if set to TRUE - ReplayTest will check moving objects.
    default: TRUE

  CATCDSReferenceMode:
    if set to TRUE - validating reference solution (Transformation section in Input part).
    default: FALSE (validating output transformation)

  CATCDSCheckMode:
    if set to TRUE - check data before and after RunOperator and write info in .cio
    default: FALSE (no checks is done)

  CATCDSMeasureTime:
    if set to TRUE - measure pure time for each RunOperator, total pure time, total lost time
    and and write these times in .cio
    default: FALSE (no times are measured)

  CATCDSAssertMode:
    if set to NONE - CATCDSAssert* macros will be silent.
    if set to TRACE - CATCDSAssert* macros will save traces.
    if set to ASSERT - CATCDSAssert* macros will save traces & call assert(0).
    if set to BREAK - CATCDSAssert* macros will break to debugger.
    default: NONE (no assert)

  CATCDSTraceLevel:
    if set to 1..5 - generates traces.
    default: 0 (no traces)

  CATCDSGenerateStatus
    if set TRUE - Generate a dot status file

  CATCDSTestName:
    test name pattern.
    default: * (all tests)

  CATCDSSkipTime:
    if value is set to number - tests will be skipped if reference time more than number.
    default: 0 (all tests except reserved time 9999)

  CATCDSRoundMode:
    Set FPU rounding mode.
    Available values: NEAR, UP, DOWN, TRUNC
    default: NEAR

  CATCDSPrecMode:
    Set FPU precision (Win/Intel, Linux/Intel only)
    Available values: SINGLE, DOUBLE, HIGH
    default: DOUBLE
*/

#undef CATCDSGlobalParameters_Pass
#define CATCDSGlobalParameters_Pass 0
#include "CATCDSGlobalParameters_inc.h"

enum CATCDSValidateMode {
  vmCompare,
  vmValidate,
  vmRegress,
  vmSimpleCompare,
  vmNone
};

enum CATCDSScriptMode {
  smFull,
  smSimple,
  smNone
};

enum CATCDSAssertMode {
  amNone,
  amTrace,
  amAssert,
  amBreak,
  amLoop
};

enum CATCDSRoundMode {
  rmNear,
  rmUp,
  rmDown,
  rmTrunc
};

enum CATCDSPrecMode {
  pmSingle,
  pmDouble,
  pmHigh
};

class ExportedByCATCDSUtilities CATCDSGlobalParameters {
public:
  CATCDSGlobalParameters();
  ~CATCDSGlobalParameters();

  // Use these functions only for creation of CATConstraintSolver or SI.
  unsigned int GetCDSFullOpenConfigurationLevel(); 
  unsigned short GetCDSOpenConfigurationLevel();
  void GetCDSOpenConfigurationLevels(unsigned short & oLevel, unsigned short & oHFLevel);

  // Calculation environment variables

#undef CATCDSGlobalParameters_Pass
#define CATCDSGlobalParameters_Pass 2
#include "CATCDSGlobalParameters_inc.h"

  // Infrastructure environment variables

#if !defined(_EMSCRIPTEN_SOURCE) || defined(_EMSCRIPTEN_DEBUG)
  int GetReplayMode() const;
#else
  int GetReplayMode() const {return 0;}
#endif
  void SetReplayMode(int iMode);
  void FlushReplayMode();
  void ResetReplayMode();

  CATCDSBoolean GetFMA3Disable() const;

  CATCDSUnderPlayBack * IsUnderPlayBack();

  const CATCDSString& GetReplayMethod() const;
  void SetReplayMethod(const CATCDSString& iMethod);

  const CATCDSString & GetReplayPath() const;
  void SetReplayPath(const CATCDSString& iPath);

  const CATCDSString & GetReplayPrefix();
  void SetReplayPrefix(const CATCDSString& iPrefix);

  CATCDSString const & GetReplaySuffix();
  void SetReplaySuffix(const CATCDSString& iSuffix);

  const CATCDSString& GetReplayFileName();
  void SetReplayFileName(const CATCDSString& iFileName);
  void GenerateNextReplayName(const CATCDSString& iSuffix);
  CATCDSString GetReplayFullName();

  CATCDSBoolean IsReplayPlugMode() const;
  void SetReplayPlugMode(CATCDSBoolean iMode);

  CATCDSBoolean IsForceOpenConfigurationLevels() const; // FCX 01.2020

  CATCDSBoolean IsReplayUserNames() const; // FCX 07.2020

  const CATCDSString& GetNCGMFileName() const;
  void SetNCGMFileName(const CATCDSString& iName);

  const CATCDSString& GetInputPath() const;
  void SetInputPath(const CATCDSString& iPath);

  void SetOutFile(const CATCDSString & iOutFile);

  CATCDSScriptMode GetScriptMode() const;
  void SetScriptMode(CATCDSScriptMode iMode);

  CATCDSString GetScriptFileName();
  CATCDSString GetScriptFullName();
  void SetScriptFileName(const CATCDSString& iFileName);
  void GenerateNextScriptFileName();
  void SetReplayFileNameForScript(const CATCDSString& iScriptFile, int iReplayIdx);

  CATCDSValidateMode GetValidateMode() const;
  void SetValidateMode(CATCDSValidateMode iMode);

  CATCDSBoolean IsValidateMUC() const;
  void SetValidateMUC(CATCDSBoolean iMode);

  CATCDSBoolean IsValidateDiagnostics() const;
  void SetValidateDiagnostics(CATCDSBoolean iMode);

  CATCDSBoolean GetReferenceMode() const;
  void SetReferenceMode(CATCDSBoolean iMode);

  CATCDSBoolean GetCheckMode() const;
  void SetCheckMode(CATCDSBoolean iMode);

  int GetCheckIndent() const;
  int IncCheckIndent();
  int DecCheckIndent();

  int GetICIndent() const;
  int IncICIndent();
  int DecICIndent();

  void OpenCheckStream(const CATCDSString& iFileName);
  CATCDSStream * GetCheckStream();
  void CloseCheckStream();

  CATCDSStream * GetTraceStream();
  CATCDSStream * GetErrorStream();
  CATCDSStream * GetDumpStream();

  CATCDSBoolean IsMeasureTime() const;
  void SetMeasureTime(CATCDSBoolean iMode);

  clock_t GetSpentTime() const;
  void SetSpentTime(clock_t iTime);

  clock_t GetLostTime() const;
  void SetLostTime(clock_t iTime);

#ifdef CDS_DEBUG
  CATCDSAssertMode GetAssertMode() const;
  void SetAssertMode(CATCDSAssertMode iMode);

  CATCDSInline int GetTraceLevel() const {
    return _values._traceLevel;
  }
  void SetTraceLevel(int iLevel);
  void ResetTraceLevel();
#endif

  CATCDSBoolean GetGenerateStatus() const;
  void SetGenerateStatus(CATCDSBoolean iMode);
  
  int GetThreadNumber() const;
  void SetThreadNumber(int iThreadNumber);

  void OpenStatusStream(const CATCDSString& iFileName);
  CATCDSStream * GetStatusStream();
  void CloseStatusStream();
  
  int GetRunCount() const;
  void SetRunCount(int iCount);
  int IncRunCount();

  int GetNestingLevel() const;
  void SetNestingLevel(int iLevel);

  CATCDSBoolean GetTestMode() const;
  void SetTestMode(CATCDSBoolean iMode);

  CATCDSBoolean IsDiagNotRun() const;
  void SetDiagNotRun(CATCDSBoolean iNotRun);

  void Save();
  void Restore();

  void InitializeEnv();
  void InitializeFPU();
  void Initialize();

private:
  unsigned int _level;

  struct ExportedByCATCDSUtilities CustomValues {
    unsigned int _level;

    // Calculation environment variables

#undef CATCDSGlobalParameters_Pass
#define CATCDSGlobalParameters_Pass 1
#include "CATCDSGlobalParameters_inc.h"


    // Infrastructure environment variables

    int _replayMode, _savedReplayMode;
    CATCDSString _replayMethod;
    CATCDSString _replayPath;
    CATCDSString _replayPrefix;
    CATCDSString _replaySuffix;
    CATCDSString _inputPath;
    CATCDSBoolean _unlockTraces;
    CATCDSBoolean _replayPlugMode;
    CATCDSBoolean _FMA3Disable;
    CATCDSBoolean _ForceOpenConfigurationLevels; // FCX 01.2020
    CATCDSBoolean _replayUserNames; // FCX 07.2020

    CATCDSString _OutputFile;

    CATCDSScriptMode _scriptMode;

    CATCDSValidateMode _validateMode;
    CATCDSBoolean _validateMUC;
    CATCDSBoolean _validateDiagnostics;
    CATCDSBoolean _referenceMode;
    CATCDSBoolean _checkMode;
    CATCDSBoolean _measureTime;
    CATCDSBoolean _generateStatus;
    
    CATCDSAssertMode _assertMode;
    int _traceLevel, _traceLevelGlobal;

    CATCDSRoundMode _roundMode;
    CATCDSPrecMode _precMode;

    int _threadNumber;

    void Initialize();
    void InitializeEnv();
  };

  int _savedReplayMode;

  int _generatedNumber;
  CATCDSString _replayFileName;
  CATCDSString _generatedFileName;
  CATCDSString _ncgmFileName;

  int _generatedScriptNumber;
  CATCDSString _scriptFileName;

  clock_t _spentTime, _lostTime;

  int _runCount;
  int _nestingLevel;

  CATCDSBoolean _testMode;

  CATCDSBoolean _isDiagNotRun;

  CustomValues _values, _savedValues;
  
  int _checkIndent;
  int _ICIndent;
  CATCDSStream* _pCheckStream;
  CATCDSStream* _pStatusStream;
  CATCDSStream* _pTraceStream;
  CATCDSStream* _pErrorStream;
  CATCDSStream* _pDumpStream;
};

ExportedByCATCDSUtilities CATCDSGlobalParameters & GetGlobalParameters();

ExportedByCATCDSUtilities const char * GetCDSVersion();

#endif
