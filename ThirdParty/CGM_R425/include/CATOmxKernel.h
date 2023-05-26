/**
 * @level Private
 * @usage U1
 */
#ifndef __CATOmxKernel_h__
#define __CATOmxKernel_h__
#include "CATOmxExport.h"
#ifdef	__CATOmxKernel
#define	ExportedByCATOmxKernel	DSYExport
#else
#define	ExportedByCATOmxKernel	DSYImport
#endif
class CATOmxCollecManager;
/**
 * memcpy manager sizeof(void*)
 * for any pointer size object
 */
extern ExportedByCATOmxKernel CATOmxCollecManager &naive_manager(); 
/**
 * IUnknown manager Manager
 * for any COM object.
 */
extern ExportedByCATOmxKernel CATOmxCollecManager &com_manager(); 
/**
 * sharable manager CATOmxSharable Manager
 */
extern ExportedByCATOmxKernel CATOmxCollecManager &sharable_manager(); 
typedef CATOmxCollecManager&(*CATOmxCollecManagerLocator)();
// set definition
template <class Type, CATOmxCollecManagerLocator CollecMgr> class CATOmxSet;
// iterator 
template <class Type> class CATOmxIter;
// Collection manager

template <class CATOmxSR_X> class CATOmxSR;
template <class Type> class CATOmxVector ;
// vector manager
#endif
