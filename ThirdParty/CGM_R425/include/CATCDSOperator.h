// COPYRIGHT DASSAULT SYSTEMES 2002
//=============================================================================
//
// CATCDSOperator:
//   A base class for all internal modules.
//
//=============================================================================
//
// Usage notes:
//
//=============================================================================
//  Jun 2002  Creation
//=============================================================================

#ifndef CATCDSOperator_h
#define CATCDSOperator_h

#include "CATCDSVirtual.h"
#include <ctime>

#include "CATCDSBoolean.h"
#include "CATCDSUtilities.h"
#include "CATCDSGlobalParameters.h"
#include "CATCDSString.h"
#include "CATCDSInterruptDef.h"
#include "CATCDSDebug.h"

class CATCDSStream;

const int CATCDSRunSucceeded       = 0;
const int CATCDSRunFailed          = 1;
const int CATCDSRunPartiallySolved = 2;
const int CATCDSRunInconsistent    = 3;
const int CATCDSRunAborted         = 4;
const int CATCDSRunApproximated      = 5;

const int CATCDSValidateIdenticalSolutions = 0;
const int CATCDSValidateMoreSolutions      = 1;
const int CATCDSValidateLessSolutions      = 2;
const int CATCDSValidateDifferSolutions    = 3;
const int CATCDSValidateFailed             = 4;

class ExportedByCATCDSUtilities CATCDSOperator {
public:
  /**
   * Default constructor
   */
  CATCDSOperator();
  /**
   * Destructor
   */
  virtual ~CATCDSOperator();

  /**
   * Initialize the operator after creating environment.
   */
  virtual void InitWithEnv();

  /**
   * Runs the operator.
   * This method should not be overloaded for implementation
   * derived classes (RunOperator() is to be overloaded instead)
   * @return result of run
   *   <br><b>Legal values</b>:
   *     CATCDSRunSucceeded
   *     CATCDSRunFailed
   *     CATCDSRunPartiallySolved
   *     CATCDSRunInconsistent
   */
  int Run();

  /**
   * Set an interrupt class.
   * @param ipInterrupt
   *    the interrupt class pointer (see declaration in CATCDSInterruptDef.h)
   */
  virtual void SetInterrupt(CATCDSInterruptInterface* ipInterrrupt);

protected:
  /**
   * Runs the operator.
   * Pure virtual method to run the operator; to be overloaded for
   * implementation derived classes
   * @return result of run
   *   <br><b>Legal values</b>:
   *     CATCDSRunSucceeded
   *     CATCDSRunFailed
   *     CATCDSRunPartiallySolved
   *     CATCDSRunInconsistent
   *     CATCDSRunAborted
   */
  virtual int RunOperator() = 0;

  virtual CATCDSBoolean FilterReplay(int iMask) const {return FALSE;};

  CATCDSInterruptInterface* _pInterrupt;

public:
  /**
   * Returns current version of stream.
   */
  virtual int GetVersionOfStream() const;
#ifdef CDS_DEBUG
  /**
   * Checks input model and print error messages to the stream.
   * @param ioStream Stream for error messages
   * @return TRUE if success, FALSE otherwise
   */
  virtual CATCDSBoolean CheckInput(CATCDSStream & ioStream) const;
  /**
   * Checks output model and print error messages to the stream.
   * @param ioStream Stream for error messages
   * @return TRUE if success, FALSE otherwise
   */
  virtual CATCDSBoolean CheckOutput(CATCDSStream & ioStream) const;
  /**
   * Checks input model and print error messages to the stream.
   * @param ioStream Stream for error messages
   * @return TRUE if success, FALSE otherwise
   */
  virtual void WriteInput(CATCDSStream & ioStream) const;
  /**
   * Writes output model to the stream.
   * @param ioStream Stream to store output model
   */
  virtual void WriteOutput(CATCDSStream & ioStream) const;
  /**
   * Validates output
   * @param ioStream Stream to read output data.
   * @param iStreamVersion version of stream.
   * @return result of output validation.
   *   <br><b>Legal values</b>:
   *     CATCDSValidateIdenticalSolutions - if the output is consistent with solution.
   *     CATCDSValidateMoreSolutions      - if found more solutions than were in previous output.
   *     CATCDSValidateLessSolutions      - if found less solutions than were in previous output.
   *     CATCDSValidateDifferSolutions    - if number of solutions is equal but some of them aren't consistent.
   *     CATCDSValidateFailed             - if any other problems occur.
   */
#endif
  /**
   * Retrieves the name of the operator
   */
  virtual CATCDSString GetOperatorName() const = 0;
  /**
   * Retrieves the prefix of the operator
   */
  virtual CATCDSString GetOperatorShortName() const = 0;
  /**
   * Sets CDS level
   */
  virtual void SetCDSLevel(unsigned int iLevel);
  /**
   * Gets CDS level
   */
  unsigned int GetCDSLevel() const;
#ifdef CDS_DEBUG
  /**
   * Sets elapsed time
   */
  void SetTime(clock_t iTime);
  /**
   * Gets elapsed time
   */
  clock_t GetTime() const;

  void FixTime();

  void BeginMeasureTime();
  void EndMeasureTime();
#endif

private:

#ifdef CDS_DEBUG
  CATCDSBoolean _loaded;
  clock_t _time;
  static clock_t _sTotal;
  clock_t _begin;
  clock_t _current;
  clock_t _lost;
#endif
  unsigned int _level;

public:
  virtual void Remove() = 0;

#ifdef CDS_DEBUG
  void Debug_preprocess(CATCDSStream *& pStream, CATCDSStream *& pCheckStream, CATCDSStream *& pStreamPlayBack, clock_t &time_begin, clock_t &time_lost, clock_t &gtime_spent, clock_t &gtime_lost, int& prevTraceLevel);
  void Debug_postprocess(CATCDSStream *& pStream, CATCDSStream *& pCheckStream, CATCDSStream *& pStreamPlayBack, clock_t &time_begin, clock_t &time_lost, clock_t &gtime_spent, clock_t &gtime_lost, int Diagnostic, int prevTraceLevel);

  static void PrintElapsedTimes(CATCDSStream * ipCheckStream);

protected:
  struct ExportedByCATCDSUtilities OperatorInfo {
    CATCDSString _name;
    CATCDSString _shortName;
    const char* _pReplayExt;

    OperatorInfo * _pNext;

    clock_t _spentTime;
    int _nCalls;

    OperatorInfo(const CATCDSString & iName, const CATCDSString & iShortName, const char* ipReplayExt = 0);
  };

  virtual OperatorInfo & GetOperatorInfo() = 0;

private:
  static OperatorInfo * _pFirst;  // circular list of operator infos

public:
  // public for Solaris
  static void AddNewOperator(OperatorInfo * ipInfo);
#endif

private:
  CATCDSOperator(CATCDSOperator&);
  CATCDSOperator & operator = (CATCDSOperator&);
};

#ifdef CDS_DEBUG

// Used to declare a operator info inside operator implementation class
#define CATCDSDeclareOperator \
  public: \
  virtual void Remove() CATCDSOverride; \
  \
  CATCDSString GetOperatorName() const CATCDSOverride; \
  \
  CATCDSString GetOperatorShortName() const CATCDSOverride; \
  \
  protected: \
  virtual CATCDSOperator::OperatorInfo & GetOperatorInfo() CATCDSOverride; \
  \
  private: \
  static CATCDSOperator::OperatorInfo * _pInfo;

// Used to implement a operator info in cpp file of operator implementation class
#define CATCDSImplementOperator(iName, iShortName) \
  CATCDSOperator::OperatorInfo * iName::_pInfo = 0; \
  void iName::Remove() \
  { \
    CATRemove(this); \
  } \
  CATCDSOperator::OperatorInfo & iName::GetOperatorInfo() \
  { \
    if(!_pInfo) { \
      _pInfo = new CATCDSOperator::OperatorInfo(#iName, #iShortName, 0); \
    } \
    return *_pInfo; \
  } \
  CATCDSString iName::GetOperatorName() const \
  { \
    return #iName; \
  } \
  CATCDSString iName::GetOperatorShortName() const \
  { \
    return #iShortName; \
  }

#define CATCDSImplementOperatorExt(iName, iShortName, iReplayExt) \
  CATCDSOperator::OperatorInfo * iName::_pInfo = 0; \
  void iName::Remove() \
  { \
    CATRemove(this); \
  } \
  CATCDSOperator::OperatorInfo & iName::GetOperatorInfo() \
  { \
    if(!_pInfo) { \
      _pInfo = new CATCDSOperator::OperatorInfo(#iName, #iShortName, #iReplayExt); \
    } \
    return *_pInfo; \
  } \
  CATCDSString iName::GetOperatorName() const \
  { \
    return #iName; \
  } \
  CATCDSString iName::GetOperatorShortName() const \
  { \
    return #iShortName; \
  }

struct ExportedByCATCDSUtilities AutoMeasureTime {
  AutoMeasureTime(const CATCDSOperator * ipOperator)
  : _pOperator((CATCDSOperator*)ipOperator)
  {
    if (GetGlobalParameters().IsMeasureTime() && _pOperator)
      _pOperator->BeginMeasureTime();
  }
  ~AutoMeasureTime()
  {
    if (GetGlobalParameters().IsMeasureTime() && _pOperator)
      _pOperator->EndMeasureTime();
  }

private:
  CATCDSOperator * _pOperator;
};

#define CDSMeasureTime(ipOperator) AutoMeasureTime amt(ipOperator)
#define CDSFixTime(ipOperator) if (ipOperator) ipOperator->FixTime()

#else
#define CATCDSDeclareOperator \
  public: \
  virtual void Remove(); \
  \
  CATCDSString GetOperatorName() const; \
  \
  CATCDSString GetOperatorShortName() const;

#define CATCDSImplementOperator(iName, iShortName) \
  void iName::Remove() \
  { \
    CATRemove(this); \
  } \
  CATCDSString iName::GetOperatorName() const \
  { \
    return #iName; \
  } \
  CATCDSString iName::GetOperatorShortName() const \
  { \
    return #iShortName; \
  }

#define CATCDSImplementOperatorExt(iName, iShortName, iReplayExt) \
  void iName::Remove() \
  { \
    CATRemove(this); \
  } \
  CATCDSString iName::GetOperatorName() const \
  { \
    return #iName; \
  } \
  CATCDSString iName::GetOperatorShortName() const \
  { \
    return #iShortName; \
  }

#define CDSMeasureTime(ipOperator) 
#define CDSFixTime(ipOperator) 

#endif

#endif
