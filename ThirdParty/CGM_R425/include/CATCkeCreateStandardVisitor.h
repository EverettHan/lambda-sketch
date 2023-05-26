/**  	   	   	 
* @level Protected 	  	  	 
* @usage U1 	  	  	 
*/

#ifndef __CATCkeCreateStandardVisitor_H
#define __CATCkeCreateStandardVisitor_H

#include "CATIAV5Level.h"
#include "CATLifDictionary.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATIVisitor.h"

/**
 * relace CATICkeParmFactory::CreateStandardVisitor.
 */
ExportedByCATLifDictionary CATIVisitor_var CATCkeCreateStandardVisitor(const GUID& visitclsid,const CATLISTV(CATBaseUnknown_var)* listToFill);

#endif
