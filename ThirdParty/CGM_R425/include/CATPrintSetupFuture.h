#ifndef CATPrintSetupFuture_H
#define CATPrintSetupFuture_H

#pragma warning( disable : 4355 )
#pragma warning(push,0)
#include <future>
#pragma warning(pop)

#include <chrono>

class CATPrintSetupFuture
{
public:
  CATPrintSetupFuture(std::shared_future<void> iFuture, std::shared_future<void> iNotifyFuture);
  CATPrintSetupFuture() = default;
  ~CATPrintSetupFuture() = default;
  CATPrintSetupFuture(CATPrintSetupFuture const &) = default;
  CATPrintSetupFuture& operator=(CATPrintSetupFuture const&) = default;
  CATPrintSetupFuture(CATPrintSetupFuture &&) = default;
  CATPrintSetupFuture& operator=(CATPrintSetupFuture &&) = default;

  /*
   * Default behavior is to wait that notification thread ends.
   * If Get or Wait are called in functions which have been called by notification thread 
   * CATPrintSetupInteractiveSolution::NotifyProgress or CATPrintSetupInteractiveSolution::NotifySolution
   * caller MUST set iWaitNotifyThread to false.
   */
  int Get(bool iWaitNotifyThread = true);
  void Wait(bool iWaitNotifyThread = true);

  template<class Duration> std::future_status WaitFor(Duration const&);
  template<class Time> std::future_status WaitUntil(Time const&);

  /*
   * Returns true if computations are ended and the result is immediatly available.
   * The result may be an exception thrown when calling Get.
   */
  bool IsReady() const;

private:
  std::shared_future<void> _future;
  std::shared_future<void> _notifyFuture;
};

inline CATPrintSetupFuture::CATPrintSetupFuture(std::shared_future<void> iFuture, std::shared_future<void> iNotifyFuture)
  : _future(std::move(iFuture))
  , _notifyFuture(std::move(iNotifyFuture))
{
}

inline int CATPrintSetupFuture::Get(bool iWaitNotifyThread)
{
  if (iWaitNotifyThread && _notifyFuture.valid())
    _notifyFuture.get();
  _future.get();
  return 0;
}

inline void CATPrintSetupFuture::Wait(bool iWaitNotifyThread)
{
  if (iWaitNotifyThread && _notifyFuture.valid())
    _notifyFuture.wait();
  _future.wait();
}

template<class Duration> 
std::future_status CATPrintSetupFuture::WaitFor(Duration const& iDuration)
{
  return _future.wait_for(iDuration);
}

template<class Time> 
std::future_status CATPrintSetupFuture::WaitUntil(Time const& iTime)
{
  return _future.wait_until(iTime);
}

inline bool CATPrintSetupFuture::IsReady() const
{
  return _future.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
}

#endif
