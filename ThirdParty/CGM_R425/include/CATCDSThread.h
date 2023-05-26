// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
//
// CATCDSThread:
//   class for thread data, needed for parallel CDS
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  Apr 2005  Creation                         Nikolay Snytnikovint
//=============================================================================

#ifndef CATCDSThread_H
#define CATCDSThread_H

#include "CATCDSUtilities.h"

#ifdef _WINDOWS_SOURCE
  #ifndef WINAPI
    #define WINAPI __stdcall
  #endif
#else
  #define WINAPI
#endif

typedef unsigned int (WINAPI * THRFUNC_t)(void*);

class ExportedByCATCDSUtilities CATCDSThread {
public:
  CATCDSThread();
  CATCDSThread(int iId);
  virtual ~CATCDSThread();

  void SetId(int iId);
  int  GetId();

  virtual void SetThreadFunction(THRFUNC_t ipThreadFunction);
  virtual THRFUNC_t GetThreadFunction();

  virtual void SetThreadData(void* ipThreadData);
  virtual void* GetThreadData();

protected:
  int _threadId;
  THRFUNC_t _pThreadFunction;
  void* _pThreadData;
  int _idealProcIdx;
};

#endif
