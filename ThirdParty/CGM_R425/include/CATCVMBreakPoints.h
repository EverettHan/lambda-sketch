/* -*-c++-*- */
#ifndef CATCVMBreakPoints_H
#define CATCVMBreakPoints_H
// COPYRIGHT DASSAULT SYSTEMES  2007
#include "CATCVMSysObjects.h"
#include "CATDataType.h"

extern "C" ExportedByCATCVMSysObjects void catcvmfollowtag();   

class ExportedByCATCVMSysObjects CATCVMBreakPoints
{
public:
  static void CATCVMFollowTag(CATULONG32 iTag);
private:
  CATCVMBreakPoints();
  CATCVMBreakPoints(const CATCVMBreakPoints &);//Necessary to prevent unwanted automatic creation by compiler
  void operator = (const CATCVMBreakPoints &);
};

#endif
