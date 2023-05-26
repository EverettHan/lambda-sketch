//========================================================================================================
// COPYRIGHT Dassault Systemes 2010
//========================================================================================================
//
//  CATOmyAsyncProcessWatchCAT.h
//  Watchat for the asynchronous process. It controls its behavior
//
//========================================================================================================

/**
 * @level Protected
 * @usage U1
 */

#ifndef _CATASYNCPROCESSWATCHCAT_H_
#define _CATASYNCPROCESSWATCHCAT_H_

#include "CATOMYCuteIO.h"

#include "CATBaseUnknown.h"     // For heritage
#include "CATMutex.h"
#include "CATConstantsForThreads.h"

#include "CATUnicodeString.h"   // For string manipulation before running the thread
#include "CATSysTSUnicodeString.h" // For string manip after running the thread

#define WatchCAT_OK 0x0L
#define WatchCAT_KILLED_BY_CATIA 0x01
#define WatchCAT_KILLED_BY_TIMEOUT 0x02

class ExportedByCATOMYCuteIO CATOmyAsyncProcessWatchCAT: public CATBaseUnknown{
public:
  // ####################################################################################################
  // Constructors and destructors
  // ####################################################################################################
  /**
   * Constructor of the CAT
   * @param iWhatchedProcess Process monitored
   */
  CATOmyAsyncProcessWatchCAT();
  virtual ~CATOmyAsyncProcessWatchCAT();

  // ####################################################################################################
  // Accessor & Mutators
  // ####################################################################################################
  /**
   * Gets the remaining time before the CAT kills the process
   * @param oRemainingTime The time before the CAT kills the process (in ms)
   * @return S_OK
   */
  HRESULT GetRemainingTime(CATULONG64& oRemainingTime);

  /**
   * Feeds the CAT, thats to say add time to the counter so that the process is
   * longer alive
   * @param iTime Time to add to the counter (in ms)
   * @return S_OK
   */
  HRESULT Feed(CATLONG32 iTime);

  /**
   * Sets the remaining time before the CAT kills the process
   * @param iRemainingTime The time before the CAT kills the process (in ms)
   * @return S_OK
   */
  HRESULT SetRemainingTime(CATLONG64 iRemainingTime);
  // ####################################################################################################
  // WatchCat Control
  // ####################################################################################################
  /**
   * Decide if the thread have to kill the process or not
   * @return TRUE in order to stop the process, else FALSE
   */
  CATBoolean HaveToKill(int* oCause)const;

  /**
   * Stops the WatchCat
   * @return E_FAIL if the Watchcat was already stopped, else S_OK
   */
  HRESULT Stop();

  /**
   * Checks if the watchcat as already been stopped
   * @return TRUE if already stopped, else FALSE
   */
  CATBoolean IsStopped();

  /**
   * Let the watchcat continue
   * @return E_FAIL if the watchcat was not stopped, else S_OK
   */
  HRESULT Continue();

  /**
   * Checks if the process has been asked to be killed
   * @return True if the process has been asked to suicid by catia, else false
   */
  CATBoolean AskedToSuicid()const;

  void AskToSuicid()const;

  /**
   * Sets the internal variable killFileName Only meant to be used temporarily,
   * waiting for a better architecture.
   * @param iKillFileName The file name to create to kill the process
   */
  void _SetKillFileName(CATUnicodeString iKillFileName);

  /**
   * Set the internal variable _sCauseOfDeathFileName
   * @param iCauseOfFileName The file name describing the cause of death
   */
  void SetCauseOfDeathFileName(CATUnicodeString& iCauseOfFileName) {_sCauseOfDeathFileName = iCauseOfFileName;}

  /**
   * Print the cause of death message in the cause of death file
   * @param iCauseOfDeath, cause of death message
   */
  void PrintfCauseOfDeathMsg(const char * iCauseOfDeath);

  /**
   * Scan the cause of death message in the cause of death file
   * @param oCauseOfDeath, cause of death message
   * @return TRUE if the cause of death file exists, FALSE otherwise
   */
  CATBoolean GetCauseOfDeathMsg(CATUnicodeString &oCauseOfDeath);

  /**
   * Delete the file that ask the whatcat to kill the process
   * @return
   *  - S_OK if the file existed and was correctly deleted
   *  - S_FALSE if the file was not asked supposed to be created
   *  - E_FAIL if the deletion did not happen well
   */
  HRESULT DeleteKillFile()const;

  /**
   * Dump a message, taking care of not using thread unsafe structures
   * @param message The message to display
   */
  void DumpMessage(const char * const message)const;

private:
  /** File to check in order to now if CATIA sent a kill order. */
  char* _sKillFileName;
  int _KillFileNameSize;

  /** File discribing the async process's cause of death */
  CATUnicodeString _sCauseOfDeathFileName;
  CATUnicodeString _sCauseOfDeath;

  /** The amount of time before killing the process (in ms) */
  CATLONG64 _RemainingTime;
  CATMutex _RemainingTimeMutex;

  // ####################################################################################################
  // Private methods
  // ####################################################################################################
  // For the copy methods not to be automatically constructed
  CATOmyAsyncProcessWatchCAT& operator = ( const CATOmyAsyncProcessWatchCAT&);
  CATOmyAsyncProcessWatchCAT(const CATOmyAsyncProcessWatchCAT&);
  FILE * _pOutputFile;

  // ####################################################################################################
  // WatchCat Control
  // ####################################################################################################
  /** Boolean saying if displaying messages (in the console or in a file)
   * It means :
   * 1 -> the watchCat write on the standard output (or in the file if given
   * a name via CATOmyAsyncMPConstants)
   * 0 -> don't write anything anywhere
   */
  char _verbose;
  /** Boolean inducing a deactivation of the watchCAT timer */
  char _killingDeactivated;
  /** Increase/Decrease the amount of time a client/server communication may take before the process times out**/
  int _PCSCoeff;

  /** Boolean used to check if the watchcat need to be stopped. */
  CATBoolean _Stop;
  CATMutex _StopMutex;
};

#endif
