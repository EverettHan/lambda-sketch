/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
#ifndef  CATAdpCloneRequest_H
#define CATAdpCloneRequest_H

/**
* @level Private 
* @usage U1
*/
#include "CATPLMIntegrationAccess.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfCATString.h"
#include "CATIAdpPLMIdentificator.h"
#include "CATPLMID.h"

/**
* Class to manage the information required for cloning operations.
* <br><b>Role</b>: Acts as a container to consolidate the ID, attributes, and values
* that are required to clone an object.
*/
class   ExportedByCATPLMIntegrationAccess CATAdpCloneRequest  
{  
public :
	/**
	* <br><b>Role</b>: Constructs a clone request object given its CATIAdpPLMIdentificator and attributes.
	* @param iID [in]
	*   The CATIAdpPLMIdentificator to process.
	* @param const CATListOfCATString &iAttrs [in]
	*   The list of attribute names to be modified during the cloning process. This is
	*   used for specifying new values for identifier set attributes to ensure unicity.
	* @param const CATListOfCATUnicodeString &iValues [in]
	*   The corresponding list of values for the attributes named in the previous parameter.
	*/
	CATAdpCloneRequest(CATIAdpPLMIdentificator * iID, const CATListOfCATString &iAttrs, const CATListOfCATUnicodeString &iValues);
	
	/**
	* <br><b>Role</b>: Constructs a clone request object from a handler to a CATBaseUnknown and attributes.
	* @param ihObj [in]
	*   The handler to the object to process.
	* @param const CATListOfCATString &iAttrs [in]
	*   The list of attribute names to be modified during the cloning process. This is
	*   used for specifying new values for identifier set attributes to ensure unicity.
	* @param const CATListOfCATUnicodeString &iValues [in]
	*   The corresponding list of values for the attributes named in the previous parameter.
	*/
	CATAdpCloneRequest(CATBaseUnknown_var & ihObj, const CATListOfCATString &iAttrs, const CATListOfCATUnicodeString &iValues);

	~CATAdpCloneRequest();
	
	/**
	* PLMID of the object to clone
	*/
	CATPLMID id ;  
	/**
	* Attribute names to modify.
	*/
	CATListOfCATString attrs;
	/**
	* New values for the above attributes.
	*/
	CATListOfCATUnicodeString values;
	
	int operator == ( const CATAdpCloneRequest& other ) const;
	int operator != ( const CATAdpCloneRequest& other ) const;
};  

#include <CATLISTV_Clean.h>
#define CATLISTP_Append
#define CATLISTP_RemoveAll
#include <CATLISTV_Declare.h>
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATPLMIntegrationAccess
CATLISTV_DECLARE( CATAdpCloneRequest );
typedef CATLISTV( CATAdpCloneRequest ) CATListOfCATAdpCloneRequest;

#endif
