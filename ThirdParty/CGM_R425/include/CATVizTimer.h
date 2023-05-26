// COPYRIGHT DASSAULT SYSTEMES 2012

#ifndef CATVizTimer_h
#define CATVizTimer_h

#include "SGInfra.h"
#include "CATSysElapseTime.h"

/**
 * The CATVizTimer class provides a timer with microsecond precision.
 * The accuracy of the timer depends on the underlying operating system
 * and hardware.
 */
class ExportedBySGInfra CATVizTimer
{
public:
  /**
   * Default constructor.
   */
  CATVizTimer();

  /**
   * Starts the timer. This has no effect if the timer
   * is allready started.
   */
  void Start();

  /**
   * Stops the timer. This has no effect is the timer
   * is allready stoped.
   */
  void Stop();

  /**
   * Resets the timer. If the timer was started, it will be stoped
   */
  void Reset();

  /**
   * Returns the elapsed time since the last call to Reset.
   * Time intervals during which the timer was stopped are not
   * taken into account.
   */
  CATULONG64 GetTicks() const;

private:
  CATULONG64 _startTicks;
  CATULONG64 _ticks;
  bool _stoped;

  mutable CATSysElapseTime _sysTimer;

  CATULONG64 GetSystemTicks() const;

  CATVizTimer(const CATVizTimer&);
  void operator = (const CATVizTimer&);
};

#endif  // CATVizTimer_h
