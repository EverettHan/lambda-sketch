#ifndef CATPrintSetupInteractiveSolution_H
#define CATPrintSetupInteractiveSolution_H

#include "CATGMOperatorsInterfaces.h"
#include "CATPrintSetupAsyncOptions.h"

/* 
 * Abstract class for nesting interactive solution updates.
 * User must derive this class and implement its methods.
 */

class CATPrintSetupInteractiveSolution
{
public:
  virtual ~CATPrintSetupInteractiveSolution() = default;

  /*
   * Notify to user progression of nesting algorithm.
   * @param iProgressPercent A percentage value of progress.
   */
  virtual void NotifyProgress(double iProgressPercent) = 0;

  /*
   * The method will be called by the operator each time a new better solution is found.
   * User is free to read any data from the PrintSetup operator until this method returns
   * After data could be modified if another solution was found
   */
  virtual void NotifySolution() = 0;

  /*
   * @see CATPrintSetupAsyncOptions 
   */
  void SetStopAfterFirstIteration(bool iStopAfterFirstIteration);
  bool IsStopAfterFirstIteration() const;

  void SetFastRun(bool iFastRun);
  bool IsFastRun() const;

  void SetWaitCGM(bool iWait);
  bool IsWaitCGM() const;

  CATPrintSetupAsyncOptions const& GetOptions() const;
  void SetOptions(CATPrintSetupAsyncOptions const& iOptions);

private:
  CATPrintSetupAsyncOptions _options;
};

inline void CATPrintSetupInteractiveSolution::SetStopAfterFirstIteration(bool iStopAfterFirstIteration)
{
  _options.SetStopAfterFirstIteration(iStopAfterFirstIteration);
}

inline bool CATPrintSetupInteractiveSolution::IsStopAfterFirstIteration() const
{
  return _options.IsStopAfterFirstIteration();
}

inline void CATPrintSetupInteractiveSolution::SetFastRun(bool iFastRun)
{
  _options.SetFastRun(iFastRun);
}

inline bool CATPrintSetupInteractiveSolution::IsFastRun() const
{
  return _options.IsFastRun();
}

inline void CATPrintSetupInteractiveSolution::SetWaitCGM(bool iWait)
{
  _options.SetWaitCGM(iWait);
}

inline bool CATPrintSetupInteractiveSolution::IsWaitCGM() const
{
  return _options.IsWaitCGM();
}

inline CATPrintSetupAsyncOptions const& CATPrintSetupInteractiveSolution::GetOptions() const
{
  return _options;
}

inline void CATPrintSetupInteractiveSolution::SetOptions(CATPrintSetupAsyncOptions const& iOptions)
{
  _options = iOptions;
}

#endif
