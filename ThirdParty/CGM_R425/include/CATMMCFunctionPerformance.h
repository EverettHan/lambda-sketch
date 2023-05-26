#ifndef CATMMCFUNCTIONPERFORMANCE_H
#define CATMMCFUNCTIONPERFORMANCE_H

#include "CATMMediaCore2.h"

#include "CATUnicodeString.h"
#include <bitset>
#ifdef _WINDOWS_SOURCE
#include <sysinfoapi.h>
#endif
#include <iostream>

/**
  * @ingroup groupPotentialSysInfra
  * @brief Service/helper for performance analysis.
  */

class CATLapTimer {
public:
  CATLapTimer();
  CATLapTimer(char* ipName);
  ~CATLapTimer()                    { std::cout << _functionName.ConvertToChar() << " called {" << _counter << "} cumulatedTimer : " << _duration << std::endl; };

  void StartLap()                   {             GetCurrentLapDuration(); };
  void EndLap() { _duration += GetCurrentLapDuration(); _counter++;  };
  DWORD GetDurationCounter()        { return _duration; };

private:
  DWORD GetTimeFromStart()          ;
  DWORD GetCurrentLapDuration()     ;
  CATUnicodeString _functionName;
  DWORD _startTime, _lastLapTime, _duration;
  unsigned long long _counter;
};
CATLapTimer::CATLapTimer()
:_functionName("")
,_startTime(0)
,_lastLapTime(0)
,_counter(0)
{
#ifdef _WINDOWS_SOURCE
  _startTime = ::GetTickCount();
#endif
  _lastLapTime = _startTime;
}
CATLapTimer::CATLapTimer(char* ipName)
:_functionName(ipName)
,_startTime(0)
,_lastLapTime(0)
,_counter(0)
{
#ifdef _WINDOWS_SOURCE
  _startTime = ::GetTickCount();
#endif
  _lastLapTime = _startTime;
}
DWORD CATLapTimer::GetTimeFromStart()
{
#ifdef _WINDOWS_SOURCE
  return ::GetTickCount() - _startTime;
#else
  return 0;
#endif
}
DWORD CATLapTimer::GetCurrentLapDuration()
{
#ifdef _WINDOWS_SOURCE
  DWORD newLap = ::GetTickCount();
  DWORD    lap = newLap - _lastLapTime;
  _lastLapTime = newLap;
  return lap;
#else
  return 0;
#endif
}

class CATLapIncrement {
public:
  CATLapIncrement(CATLapTimer& iLapTimer):_lapTimer(iLapTimer), _dropLap(0) {              _lapTimer.StartLap(); };
  ~CATLapIncrement()                                                        { if(!_dropLap)_lapTimer.EndLap();   };
                                                                            
  void DropLap(bool iDrop=true)                                             {     _dropLap=iDrop;                };

private:
  CATLapIncrement();
  CATLapTimer& _lapTimer;
  bool  _dropLap;
};

// class ExportedByCATMMediaCore2 CATMMCFunctionPerformance
// {
// public:
// 
// };

class CATMaxValue {
public:
  CATMaxValue() :_functionName(""),_maxval(0) {};
  CATMaxValue(char* ipName) :_functionName(ipName), _maxval(0) {};
  ~CATMaxValue() { std::cout << _functionName.ConvertToChar() << " max value :" << _maxval << std::endl; };
  void Update(unsigned long long iVal) { if (iVal > _maxval) _maxval = iVal; };

private:
  CATUnicodeString _functionName;
  unsigned long long _maxval;
};

class CATStatValue {
public:
};

#endif
