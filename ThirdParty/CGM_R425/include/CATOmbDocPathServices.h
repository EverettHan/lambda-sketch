#ifndef		CATOmbDocPathServices_h
#define		CATOmbDocPathServices_h
/**
 * @level Protected 
 * @usage U1
 */



#include "ExportedByAC0XXLNKForRestrictedClients.h"
#include "CATUnicodeString.h"


class ExportedByAC0XXLNK CATOmbDocPathServices
{
public:
/**
* Retrieve the latetype for a file.
*
* @param iFilePath [in]
*   The path of a file.
* @param oLateTypeFromFilePath [out]
*	The latetype computed from the file path.
* @param oLateTypeFromDocumentItself [out]
*	The latetype of the document.
*
* @return
*   SUCCEEDED codes:
*	     S_OK   : the both latetypes are is retrieved.
*	     S_FALSE : the computed latetype if retrieved
*   FAILED codes:
*      CATLIBHRESULT(ERROR_FILE_NOT_FOUND) : File Does not exist or is a directory
*      E_FAIL : impossible to retrieve both latetypes.
*/
	static HRESULT RetrieveDocumentType(const CATUnicodeString& iFilePath, CATUnicodeString& oLateTypeFromFilePath, CATUnicodeString & oLateTypeFromDocumentItself);
	
};



#endif
