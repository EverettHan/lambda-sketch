#ifndef CATPrintSetupAsyncOptions_H
#define CATPrintSetupAsyncOptions_H

class CATPrintSetupAsyncOptions
{
public:
  /*
   * When it has a meaning, the nesting algorithm will stop after finishing the firt iteration.
   * The user may still receive several updates on solve progress throug NotifyProgress or NotifySolution during
   * the first iteration.
   */
  void SetStopAfterFirstIteration(bool iStopAfterFirstIteration);
  bool IsStopAfterFirstIteration() const;

  /*
   * When enables nesting operators only runs fast algorithms.
   * The operator might not find the best solution.
   */
  void SetFastRun(bool iFastRun);
  bool IsFastRun() const;

  /*
   * Wait CGM operators are done before starting asynchronous computation
   * Default value is true
   */
  void SetWaitCGM(bool iWait);
  bool IsWaitCGM() const;

private:
  bool _stopAfterFirstIteration = false;
  bool _fastRun = false;
  bool _waitCGM = true;
};

inline void CATPrintSetupAsyncOptions::SetStopAfterFirstIteration(bool iStopAfterFirstIteration)
{
  _stopAfterFirstIteration = iStopAfterFirstIteration;
}

inline bool CATPrintSetupAsyncOptions::IsStopAfterFirstIteration() const
{
  return _stopAfterFirstIteration;
}

inline void CATPrintSetupAsyncOptions::SetFastRun(bool iFastRun)
{
  _fastRun = iFastRun;
}

inline bool CATPrintSetupAsyncOptions::IsFastRun() const
{
  return _fastRun;
}

inline void CATPrintSetupAsyncOptions::SetWaitCGM(bool iWait)
{
  _waitCGM = iWait;
}

inline bool CATPrintSetupAsyncOptions::IsWaitCGM() const
{
  return _waitCGM;
}

#endif // !CATPrintSetupAsyncOptions_H
