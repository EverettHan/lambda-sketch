/* -*-c++-*- */
// -------------------------------------------------------------------
// IMO(c) Copyright Dassault Systemes 2004
//---------------------------------------------------------------------
// Responsable: JDP
//---------------------------------------------------------------------
// Source:  CATPLMConnectedHeader.cpp
//---------------------------------------------------------------------
// Contenu du source CATPLMConnectedHeader
// 
//  Header for commande allowed only with connexion to database
//
//---------------------------------------------------------------------
#ifndef CATPLMConnectedHeader_H 
#define CATPLMConnectedHeader_H 


#include "CATCommandHeader.h"
#include "CATAfrFoundation.h"


class ExportedByCATAfrFoundation CATPLMConnectedHeader : public CATCommandHeader

{
   CATDeclareClass;
   CATDeclareHeaderResources;
public:
   CATPLMConnectedHeader (const CATString & HeaderID,
      const CATString & loadName,const CATString & classname,void * argument,int state=CATFrmAvailable, int type=0);
   CATPLMConnectedHeader (CATCommandHeader * ipHeader);
   virtual ~CATPLMConnectedHeader ();
   void OnSettingsChange(CATCallbackEvent iEvt,void * iSrv,CATNotification * iNotif,CATSubscriberData iData,CATCallback iCB);
   void UpdateHeader();
   CATCommandHeader* Clone();
private:
   int _type;
   CATCallback _callback;
   CATString _loadname, _classname;
};
#endif
