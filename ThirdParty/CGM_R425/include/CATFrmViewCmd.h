#ifndef CATFRMVIEWCMD_H
#define CATFRMVIEWCMD_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATAfrFoundation.h"
#include "CATCommand.h"

class CATFrmLayout;
class CATFrmWindow;
class CATViewer;

class ExportedByCATAfrFoundation CATFrmViewCmd : public CATCommand
{
  public:
     CATFrmViewCmd(CATString * argument = NULL) ;
    ~CATFrmViewCmd() ;
   
    CATStatusChangeRC Activate   (CATCommand* FromClient, CATNotification* EvtDat);
    CATStatusChangeRC Desactivate(CATCommand* FromClient, CATNotification* EvtDat);
    CATStatusChangeRC Cancel     (CATCommand* FromClient, CATNotification* EvtDat);

  private:
     CATString         _argument;
     CATFrmLayout    * _curLayout;
     CATFrmWindow    * _curWindow;
     CATViewer       * _curViewer;
     CATCallback       _viewCallback;
     short             _compteur;

     void ViewCB(CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);
};
#endif
