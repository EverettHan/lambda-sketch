#ifndef _CATDrillStartNotif
#define _CATDrillStartNotif

// COPYRIGHT DASSAULT SYSTEMES 2005

#include "CATNotification.h"
#include "CATVisFoundation.h"

class ExportedByCATVisFoundation CATDrillStartNotif : public CATNotification
{
  CATDeclareClass;

  public:
    CATDrillStartNotif();
    virtual ~CATDrillStartNotif();
};

#endif
