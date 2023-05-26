// COPYRIGHT DASSAULT SYSTEMES 2007

#ifndef CATMostSeenPlaneOper_H
#define CATMostSeenPlaneOper_H

//#include "CATMathAxis.h"
class CATMathAxis;

#include "CATVisCommands.h"
#include "CATErrorDef.h" // HRESULT definition

class ExportedByCATVisCommands CATMostSeenPlaneOper
{
  public:

    CATMostSeenPlaneOper();
    ~CATMostSeenPlaneOper();

    virtual HRESULT SetAxis(const CATMathAxis & iAxis) = 0;

    virtual int Run() = 0;

    virtual HRESULT GetMostSeenPlane(short & oDir1, short & oDir2) = 0;
};

#endif


