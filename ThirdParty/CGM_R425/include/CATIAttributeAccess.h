#ifndef CATIAttributeAccess_h
#define CATIAttributeAccess_h

// COPYRIGHT DASSAULT SYSTEMES 2000


// inherited class 
#include "CATBaseUnknown.h"

// load module
#include "CATLifSpecs.h"

#include "CATIValue.h"
#include "CATIInstance.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIAttributeAccess;
#else
extern "C" const IID IID_CATIAttributeAccess;
#endif


/**   
*  CATCkeBasicAdapter calls this interface for attributes that are not retrieved through
* CATIParmPublisher.
* @see CATIInstance
* @see CATIDynamicAttributes 
*/
class ExportedByCATLifSpecs CATIAttributeAccess : public CATBaseUnknown
{
public:
    /**
    * Gives the value of the iKey attribute on specified iObject.
    */
    virtual CATIValue* GetValue( CATIInstance* iObject,
        const CATUnicodeString& iKey) = 0;
    
    /**
    * Sets the value of the iKey attribute on specified iObject.
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the valuation has failed (attribute non existing on object, attribute of a bad type).
	* 	 <li> E_ACCESSDENIED if the valuation has failed (read only attribute, object not editable).
	* 	 <li> S_OK	if the attribute has been set successfully.
	*  </ol>
    */
    virtual HRESULT SetValue( CATIInstance* iObject,
        const CATUnicodeString& iKey,
        const CATIValue_var& iValue) = 0;
    
private:
    CATDeclareInterface;
}; 

CATDeclareHandler(CATIAttributeAccess, CATBaseUnknown);

#endif
