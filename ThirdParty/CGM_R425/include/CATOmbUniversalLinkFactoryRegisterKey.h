#ifndef CATOmbUniversalLinkFactoryRegisterKey_H
#define CATOmbUniversalLinkFactoryRegisterKey_H

/**
* @level Protected
* @usage U1
*/


/**
* Following IDs are attributed by Omb to applicative Function Call and Proxy factories. Each factory has its own ID. 
* Values must be added at the end of list before _FactoryRegisterKeySize. 
* Then _FactoryRegisterKeySize must be incremented.
* Do add a value only if you want to enable an application to create a new type of factory 
* (and of course if you are authorized to).
*/

static const int CATOmbTBFCFactoryID = 0 ;
static const int CATOmbTBProxyFactoryID = 1 ;
static const int CATOmbMmrDelegateFactoryID = 2;
static const int CATOmbMmrProxyFactoryID = 3;
// ... add a factory ID here ...
static const int CATOmbFactoryRegisterKeySize = 4;

#endif
