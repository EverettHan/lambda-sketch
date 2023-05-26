#ifndef CATSelectEndActivate_h
#define CATSelectEndActivate_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATNotification.h"
#include "CATAfrSelection.h"

class ExportedByCATAfrSelection CATSelectEndActivate : public CATNotification
{
  CATDeclareClass;

  public:
    CATSelectEndActivate();
    virtual ~CATSelectEndActivate();
};

#endif
