#ifndef UIVCoreTimer_H
#define UIVCoreTimer_H

#include <UIVCoreTools.h>
#include <CATLib.h>

#include <time.h>

#ifndef _WINDOWS_SOURCE
#include <stdlib.h>
#include <CATUniStd.h>
#include <string.h>
#include <sys/time.h>
#endif

class UIVCoreTimer
{

public:

  UIVCoreTimer()
  {
#ifdef _WINDOWS_SOURCE
  _startTime = 0;
#endif
  }

  ~ UIVCoreTimer() {}

  void Reset()
  {
#ifdef _WINDOWS_SOURCE
    _startTime = GetCurrentTime();
#else
    gettimeofday(&_startTimeVal, NULL);
#endif
  }

  CATULONG32 GetTime()
  {
#ifdef _WINDOWS_SOURCE
    return GetCurrentTime() - _startTime;
#else
    struct timeval currentTimeVal;
    gettimeofday(&currentTimeVal, NULL);
    return (currentTimeVal.tv_sec - _startTimeVal.tv_sec) * 1000 + (currentTimeVal.tv_usec - _startTimeVal.tv_usec) / 1000.f;
#endif
  }

private:
#ifdef _WINDOWS_SOURCE
  DWORD _startTime;
#else
  struct timeval _startTimeVal;
#endif

};

#endif
