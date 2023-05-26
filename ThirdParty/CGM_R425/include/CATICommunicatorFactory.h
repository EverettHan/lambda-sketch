#ifndef CATICommunicatorFactory_H
#define CATICommunicatorFactory_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#if !defined(_MSC_VER) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
# include "CATICommunicator.h"
#if !defined(_MSC_VER) || defined(__clang__)
#pragma GCC diagnostic pop
#endif

#include "CATMacForRtti.h"



/** 
 * CATICommunicatorFactory is the class factory of the class
 * CATICommunicator
 *
 */
class  ExportedByCATSysCommunication CATICommunicatorFactory : public IUnknown
{
  CATDeclareClass_Deprec;
  public:
  /**
   * GetConnection permits to instanciate a CATICommunicator object
   * which represents the bus in the calling processus
   * 
   */
  static  CATICommunicator *GetConnection( CATBusDescriptor iDesc=CATDefaultBus);
};

#endif

