#ifndef CATDebugMemory_H
#define CATDebugMemory_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATInstrument.h"
#ifdef  _CAT_DEBUG
class CATDebugMemory
{
  protected:
  static CATInstrument *Init();
  static void Change(const char *pt);

  public:
  static void AddPointer(void * Addr,   CATInstrument::KindClass EnumType, const char *ClassType=NULL);
  static void RemovePointer(void *Add, CATInstrument::KindClass EnumType,const char *ClassType=NULL );
  static void Start(const char *StringDebug=NULL);
  static void Stop(const char *StringDebug=NULL);
  static void Dump(CATInstrument::DumpMode iFlag,const char *StringDebug=NULL);

};
#endif
#endif
