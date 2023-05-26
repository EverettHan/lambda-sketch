#ifndef CATPLMCheckValuesServices_h
#define CATPLMCheckValuesServices_h

#include "CATPLMIntegrationAccess.h"
#include "CATErrorDef.h"
#include "CATICkeParm.h"

class CATUnicodeString;
class CATIType;



/**
 * @level Private
 * @usage U1
 */

/**
 * This service class groups the methods that allow to check the length of string values on a component / length defined in
 * / metadata in order to save in a repository.
 */


class ExportedByCATPLMIntegrationAccess CATPLMCheckValuesServices
{
 public :
 


	 /** Returns the string value complying with meta data definition in term of length
	 *
     * <br><b>Role</b>: Returns the string value complying with meta data definition in term of length in order to save the component in a repository.
     * @param iType [in]
     *   The CKE type is needed to access to dictionary.
	 * @param iAttribute [in]
     *   The access on attribute value. Its type must be string. 
     * @param oValue [out]
     *   The attribute value with a length compliant with metadata. The attribute value read in the session is truncated if its length is not 
	 *   compliant with metadata.
	 * @return
	 *   <ul>
	 *   <li><tt>S_OK</tt>: if the value has been successfully read and truncated .</li> 
	 *   <li><tt>S_FALSE</tt>: if the value has been successfully read and if the length value is compliant (no truncature done) o.</li> 
	 *   <li><tt>S_FALSE</tt>: if the value has been successfully read and if the attribute belongs to the identifier set.</li> 
	 *   <li><tt>E_FAIL</tt>: A fatal error happened during the core treatment. Nothing was done during the operation.</li>
	 *   <li><tt>E_INVALIDARG</tt>: Either iComponent is NULL or iAttribute is NULL or iAttribute has not a string type.</li>
	 *   </ul>
	 */
  static HRESULT RetrieveCompliantStringValue(CATIType *& iType, const CATICkeParm_var&  iAttribute, CATUnicodeString &oValue );
 
 

  
 private :
  CATPLMCheckValuesServices();
  ~CATPLMCheckValuesServices();

};

#endif
