#ifndef _CATLostCaptureNotif
#define _CATLostCaptureNotif

// COPYRIGHT DASSAULT SYSTEMES 2005

#include "CATNotification.h"
#include "CATVisFoundation.h"



class ExportedByCATVisFoundation CATLostCaptureNotif : public CATNotification
{
  CATDeclareClass;

  public:
    CATLostCaptureNotif();
    virtual ~CATLostCaptureNotif();
  
};

#endif
