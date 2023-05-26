// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
// 
// CATElfTimer :
// 
//=============================================================================
// Usage Notes : Manage Timers
//=============================================================================
// Dec. 98       Creation                        Anne-Sophie Taillandier
//=============================================================================

#ifndef CATElfTimer_h
#define CATElfTimer_h


#include "CATELFMathKernel.h"
#include <sys/types.h>

#ifdef _WINDOWS_SOURCE
#include <time.h>
#include <Windows.h>

#else
#include <sys/times.h>
#include <sys/time.h>
#include <limits.h>
#endif
#include <errno.h>

class ExportedByCATELFMathKernel CATElfTimer
{
  public :
    

    CATElfTimer();              // constructeur
    ~CATElfTimer();             // destructeur

    // lance le timer
    void Start();

    // stop le timer
    void Stop();

    // annule les temps cpu et elapsed 
    void Reset();

    // renvoie le temps cpu
    double GetCPU();

    // renvoie le temps elapsed
    double GetElapsed();
  
  protected :

    double    _CpuUsed;
    double    _Elapsed;
    int       _Working;

#ifdef _WINDOWS_SOURCE
    double IniElp;
    double IniCpu;
    HANDLE _ProcessHandle;
  private :
    double FileTimeAdd(FILETIME &kTime, FILETIME &uTime);
#else
    struct tms     tim_sta;
    struct tms     tim_sto;
    struct timeval initial_time;
    struct timeval end_time;
#endif
  

};


#endif
