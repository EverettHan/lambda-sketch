//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2014
//===========================================================================
//                                                                           
//  DSYSysReconnectionDispatcher                                                     
//                                                                           
//  Usage Notes: Class Definition                                              
//===========================================================================
//  Creation novembre 2014                              adt              
//===========================================================================
#ifndef DSYSYSRECONNECTIONDISP_H
#define DSYSYSRECONNECTIONDISP_H

#include "JS0SETT.h"
#include "CATEventSubscriber.h"
#include "CATCallbackManager.h"
#include "CATUnicodeString.h"


class  ExportedByJS0SETT DSYSysReconnectionDispatcher : public CATCallbackManager
{
  CATDeclareClass;
  
 public:

  CATDeclareCBEvent(Relogin);
  
  
  static   DSYSysReconnectionDispatcher* GetDispatcher ();

 private:
   DSYSysReconnectionDispatcher();
  virtual ~DSYSysReconnectionDispatcher();

  static   DSYSysReconnectionDispatcher* _TheDisp;
 
};









class  ExportedByJS0SETT DSYSysReconnectionNotif : public CATNotification
{
  CATDeclareClass;
  
public:
  DSYSysReconnectionNotif ();
  virtual ~DSYSysReconnectionNotif();
  HRESULT Unstream ( char*  iBuff, size_t iLen);
  HRESULT Stream ( char*& oBuff, size_t &oLen);

  CATCallbackEvent			*_Evenement;
  CATUnicodeString			_Url;
  CATUnicodeString			_Cookie;
  DSYSysReconnectionNotif	*_Next;
  int						_ID;
};

#endif
