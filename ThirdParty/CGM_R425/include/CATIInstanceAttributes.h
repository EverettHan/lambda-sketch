// The following will go AWAY because 
// it is to be replaced by CATIInstance alone
#ifndef CATIInstanceAttributes_h
#define CATIInstanceAttributes_h
/** @CAA2Required */
//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************

// COPYRIGHT DASSAULT SYSTEMES 2000

// load module
#include "CATLifSpecs.h"

// inherited class 
#include "IUnknown.h"
#include "CATUnicodeString.h"

#include "CATIValue.h"
#include "CATIInstance.h"

#include "CATIForwardsDecl.h"

// OLE IID
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIInstanceAttributes;
#else
extern "C" const IID IID_CATIInstanceAttributes;
#endif

/**   
 * Interface to read and write the attributes of objects.
 * <b>Role</b>: You can read and modify attributes on an object implementing this interface.<br>
 * The attributes have a name and a value.<br>
 * CATIDynamicAttributes is an interface that is used to add dynamic attributes on objects.<br>
 * If your object implements also CATIDynamicAttributes, you should be able to access those attributes 
 * from this interface.<br>
 * In LiteralFeatures framework, you can find CATCkeInstanceAdapter (or CATCkeBasicAdapter for extensions not implementing CATIInstance or CATIInstanciation) which is an 
 * adapter of those interfaces on feature objects.
 * @see CATIDynamicttributes
 * @see CATIType
 * @see CATIValue
 * @see CATIInstance
 */
class ExportedByCATLifSpecs CATIInstanceAttributes : public CATBaseUnknown
{
public :
	/**
	 *	Description: Sets an attributes value.
   	 *  @param iKey: the name of the attribute.
	 *  @param iValue: the value of the attribute.
	 */
	virtual HRESULT SetValue( const CATUnicodeString& iKey, const CATIValue_var& iValue ) = 0;

	/**
	 *	Description: Gets an attributes value.
   	 *  @param iKey: the name of the attribute.
	 *  @return [CATBaseUnknown#Release] iValue: the value of the attribute (an AddRef is done) It can return NULL.
	 */
	virtual CATIValue* GetValue( const CATUnicodeString& iKey ) = 0;


	/**
	 *	Description: Gets an attributes value.
   	 *  @param iKey: the name of the attribute.
	 *  @return [CATBaseUnknown#Release] the owner (an AddRef is done) It can return NULL.
	 */

	virtual CATIInstance* GetOwner() const = 0;

private:
  CATDeclareInterface;
}; 

CATDeclareHandler(CATIInstanceAttributes, CATBaseUnknown);

#endif
