#ifndef _CATDrillActivate
#define _CATDrillActivate

// COPYRIGHT DASSAULT SYSTEMES 2005

#include "CATActivate.h"
#include "CATVisFoundation.h"

class ExportedByCATVisFoundation CATDrillActivate : public CATActivate
{
    CATDeclareClass;

public:
    CATDrillActivate(CATNotification *iNotification);
    virtual ~CATDrillActivate();
};

#endif
