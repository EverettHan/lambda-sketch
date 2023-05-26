#ifndef  CATCommunicatorFactory_H
#define  CATCommunicatorFactory_H

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @quickReview SGT JNM 01:11:20
 */


#include "CATICommunicatorFactory.h"
#include "CATMessageClass.h"
#include "CATICommMsg.h"


//==========================================================
class ExportedByCATSysCommunication CATCommunicatorFactory : public CATBaseUnknown
{
  CATDeclareClass;
  public:
  /**
   * GetConnection permits to instanciate a CATICommunicator object
   * which represents the bus in the calling processus
   * 
   */
  virtual CATICommunicator *GetConnection( CATBusDescriptor iDesc=CATDefaultBus);
  virtual CATBusDescriptor GetBusDescriptor( const char *iKey=NULL,const char *iHost=NULL);
 
  /** @nodoc */
  virtual HRESULT GetServiceMessage( CATBBServiceType iWantedService, CATICommMsg **oMessage,
	                                 const char *iServiceDependantArgument=NULL);

};

#endif
