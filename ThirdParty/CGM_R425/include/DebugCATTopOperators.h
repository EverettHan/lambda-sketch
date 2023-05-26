#ifndef DebugCATTopOperators_H
#define DebugCATTopOperators_H

#include "BO0SWEEP.h"
class CATString;
//=============================================================================
//  Export CATDebugSweep for use in workbench
//=============================================================================

class ExportedByBO0SWEEP DebugCATTopOperators
{
public:
   static int CATDebugSweepGetNumber();
   static CATString CATDebugSweepGetName(int);
   static CATString CATDebugSweepGetComment(int);
};

#endif
