#ifndef CATTimer_H
#define CATTimer_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2008
/**
 * @level Private
 * @usage U1
 */
//-------------------------------------------------------------------------------------------------
//     To be up to date with public services and best so far practices
//        have a look on CATTimeSpan and CATTimerId from System API  
//        contact Performance Capability Scalability interlocutor
//
//     To avoid Tessellation or HLR prerequisite , have a look on internal migration CGM
//       Mathematics\ProtectedInterfaces\CATechTimer.h
//-------------------------------------------------------------------------------------------------
#include "HLRTools.h"
#include "CATechTimer.h"
#include "CATMathInline.h"
 
class ExportedByHLRTools CATTimer : public CATechTimer
{
public:

  CATTimer();
  ~CATTimer();

  // Starting the timer
  void Start();

  // Stoping the timer
  void Stop();

  // Resets the elapsed and CPU time
  void Reset();

  // Getting the elapsed time (in miliseconds)
  CATLONG32 GetElapsed();

  // Getting the CPU time
  // CATLONG32 GetCPU();
  double GetCPU();
};

 
#endif
