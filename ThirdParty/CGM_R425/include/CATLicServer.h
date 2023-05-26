//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1996                                          
//===========================================================================
//                                                                           
//  CATLicServer                                                     
//                                                                           
//  Usage Notes: Class Definition                                                            
//===========================================================================
//  Creation Septembre 1996                                 adt              
//===========================================================================

#ifndef __CATLICSERVER
#define __CATLICSERVER

#include "CATEventSubscriber.h"
//#include "CATCommandDispatchCreate.h"
#include "CATLib.h"
#include "xcocpp.h"
#include "JS0LICS.h"


class ExportedByJS0LICS  CATLicServer : public CATEventSubscriber
{
public:
  CATLicServer ();
  virtual ~CATLicServer();
  
  int CheckLicense (char * oProductName);

private:
  void TestConnection (CATCallbackEvent,  void *,  CATNotification *,
			  CATSubscriberData,
			  CATCallback);

};

#endif
