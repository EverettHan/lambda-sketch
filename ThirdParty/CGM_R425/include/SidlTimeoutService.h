#ifndef SidlTimeoutService_h
#define SidlTimeoutService_h

#include "CATComSidl.h"
#include "CATHashDico.h"

extern "C" ExportedByCATComSidl long CATComSidlCheckNetworkTimeout();
extern "C" ExportedByCATComSidl long GetPingThreadTimerFromTread(double &oTimeout);
extern "C" ExportedByCATComSidl HRESULT CATComSidlCheckNetworkTimeoutInit(CATHashDico *iParams);
extern "C" ExportedByCATComSidl int CATComSidlCheckNetworkTimeoutOnExit(int iExitCode);


#endif
