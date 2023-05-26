#ifndef CATBRGlobalFunctions_h
#define CATBRGlobalFunctions_h

// COPYRIGHT Dassault Systemes 2005

#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"
#include "CATIBRExecutionServices.h"
#include "CATIBRUtilities.h"
#include "CATIPLMBusinessRuleDictionary.h"
#include "CATListOfCATUnicodeString.h"

/**        
 * Global services dealing with Business Rules.
 */  
class ExportedByCATLifSpecs CATBRGlobalFunctions
{      
public  :  

	/**
	* To get the BR execution services for level 1 usage (server or simple client customization).
	*
	* @return
	*  The BR execution services.
	*/
	static CATIBRExecutionServices_var GetBRExecutionServicesLevel1 ();

	/**
	* DO NOT USE: OBSOLETE: To get the BR execution services for level 2 usage (only client usage. For advanced scenario requiring deduction).
	*
	* @return
	*  The BR execution services.
	*/
	static CATIBRExecutionServices_var GetBRExecutionServices ();
	static CATIBRExecutionServices_var theGlobalDico;

	/**
	* To get the BR utilities for level 2 usage.
	*
	* @return
	*  The BR utilities.
	*/
	static CATIBRUtilities_var GetBRUtilities ();
	static CATIBRUtilities_var theGlobalDico2;

	/**
	 * Returns the PLM Business Rules Dictionary.
	 */
	static CATIPLMBusinessRuleDictionary_var GetBRDictionary();

	static int GetKweFullBR ();
	static int CATKweFullBR;

	/**
	 * Returns the list of BR Ids that can be invoked during other business rules execution.
	 * The objective of this service it to let coexistence mechanisms pre-load the BLs that can be invoked during their process
	 * @param iListToFill  
	 * List that is filled with the BR Ids
	 */
	 static void ListOfCoreBRIds (CATListOfCATUnicodeString &iListToFill); 

};

#endif // CATBRGlobalFunctions_h

