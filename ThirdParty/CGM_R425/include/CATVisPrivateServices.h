#ifndef CATVisPrivateServices_H
#define CATVisPrivateServices_H

#include "VisPrivateServices.h"
#include "CATEventSubscriber.h"

class CATGraphicWindow;
class ExportedByVisPrivateServices CATVisPrivateServices
{
public:
  static CATCallback AddBeginingDrawCB(
    CATBaseUnknown*     iEventSubscriber,
    CATGraphicWindow*   iWindow,
    CATSubscriberMethod iMethodToCall,
    CATSubscriberData   iClientData = NULL);

  static void RemoveBeginingDrawCB(
    CATBaseUnknown*     iEventSubscriber,
    CATGraphicWindow*   iWindow,
    CATSubscriberData  iClientData = NULL);

private:
  CATVisPrivateServices();
  ~CATVisPrivateServices();
};

#endif
