#ifndef CATOmbRegisterDeferredContainerInit_H
#define CATOmbRegisterDeferredContainerInit_H

#include "CATOmbSelectiveLoading.h"

class CATBaseUnknown;

/**
 * Register container deffered initialization
 * If container loading requires an additional load of data which is forbidden during an open or a switch operation
 * then registering it with method will cause CATInit::Init to be called at the very end of the open/switch operation (when loading data will be authorized).
 * Notice that this additional load should concern only "ressources" files, loading a product structure is forbidden and would result in poor performances
 *
 * @param:
 *   a container implementing CATInit
 * @return:
 *   true: container has been registered and Init will be called at the end of the transaction
 *   false: container has not been registered you should call your normal code
 *
 * the only legal usage of this API is the following:
 *
 * void MyContainerInit::Init(CATBoolean iDestroyExistingData)
 * {
 *    if(CATOmbRegisterDeferredContainerInit(this)) //depending on context CATOmbRegisterDeferredContainerInit may return false, meaning that we are not in open/switch context
 *      return; //Init will be called "later"
 * 
 *    //your initialisation code that requires additional ressources
 *    
 * }
 */
ExportedByCATOmbSelectiveLoading bool CATOmbRegisterDeferredContainerInit(CATBaseUnknown* iContainer);


#endif
