
// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATVizDuration.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Apr 2003  Creation: jov
//===================================================================
#ifndef CATVizDuration_H
#define CATVizDuration_H

#include "SGInfra.h"
#include "CATLib.h"
#include "list.h"
#include "CATDataType.h"
#define MAX_CHAR_DURATION 128

//-----------------------------------------------------------------------
/**
 *
 */
class ExportedBySGInfra CATVizDuration
{
public:
  // Standard constructors and destructors
  // -------------------------------------
  CATVizDuration(char *i_name = 0);
  CATVizDuration (CATVizDuration &);
  virtual ~CATVizDuration ();

  CATVizDuration& operator=(CATVizDuration& i_duration);
  CATVizDuration& operator+=(CATVizDuration& i_duration);

  char *GetName();
  void SetName(char *i_pName);

  void AddChild(CATVizDuration* i_pChild);
  list <CATVizDuration> GetChildList();

  inline CATULONG32 GetCPUTime();
  inline CATULONG32 GetElapsedTime();

  inline void SetTimes(CATULONG32 iCPUTime, CATULONG32 iElapsedTime);

protected:

  CATULONG32  _CPUTime;
  CATULONG32  _ElapsedTime;

  char  _name[MAX_CHAR_DURATION];
  list <CATVizDuration> _childList;
};

inline CATULONG32 CATVizDuration::GetCPUTime()
{
  return _CPUTime;
}

inline CATULONG32 CATVizDuration::GetElapsedTime()
{
  return _ElapsedTime;
}

inline void CATVizDuration::SetTimes(CATULONG32 iCPUTime, CATULONG32 iElapsedTime)
{
  _CPUTime      = iCPUTime;
  _ElapsedTime  = iElapsedTime;
}

//-----------------------------------------------------------------------

#endif
