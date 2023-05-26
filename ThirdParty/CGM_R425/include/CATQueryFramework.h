#ifndef __CATQueryFramework
#define __CATQueryFramework


// COPYRIGHT DASSAULT SYSTEMES 2000

#include "JS0CORBA.h"

/**
 * Retrieves the name of the framework where the interface adhesion takes place.
 * @param impl 
 *   The implementation name.
 * @param interf
 *   The interface name.
 * @param defaut
 *   To specify if it is the default implementation of the interface.
 * @return the framework name.
 */
ExportedByJS0CORBA const char *CATQueryFramework(const char *impl,
					         const char *interf,
					         int defaut = 0);


/**
 * Retrieves the name of the framework where the interface adhesion takes place.
 * @param impl 
 *   The implementation guid.
 * @param interf
 *   The interface iid.
 * @param defaut
 *   To specify if it is the default implementation of the interface.
 * @return the framework name.
 */
ExportedByJS0CORBA const char *CATQueryFramework(const GUID &impl,
					         const IID &interf,
					         int defaut = 0);

/**
 * List all framework name actually known by Object Modeler.
* @return the list of framework name.
 */
class CATSysSimpleHashTable;
ExportedByJS0CORBA const CATSysSimpleHashTable * CATSysGetFwListFromCtrl();

#endif
