#ifndef CATIDynamicAttributes_h
#define CATIDynamicAttributes_h

// COPYRIGHT DASSAULT SYSTEMES 2000

// inherited class 
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

// used interfaces
#include "CATIValue.h"
#include "CATIType.h"

// load module and forwards declarations
#include "CATLifSpecs.h"
#include "CATIForwardsDecl.h"

// OLE IID
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIDynamicAttributes;
#else
extern "C" const IID IID_CATIDynamicAttributes;
#endif


/**   
 * Interface to add dynamic attributes to objects.
 * <b>Role</b>: You can add persistant attributes on an object implementing this interface.<br>
 * The attributes that are added, have a name, a type and a value.<br>
 * You can remove the attributes afterwards or rename them.<br>
 * You must implement this interface if you want to support this behaviour.<br>
 * This interface is used in KnowledgeAdvisor to interactively add attributes on objects.<br>
 * Watch Out: if you implement this interface on an object, you should also implement
 * CATIInstance.<br>
 * This interface returns the list of attributes on a specific object, and if an attribute
 * is added through CATIDynamicAttributes, it should be returned in CATIInstance.<br>
 * At last, this interfaces allows a user to add the support of a type to the object.<br>
 * The meaning of that is that a given object that implements this interface can be seen
 * as belonging to a new type.<br>
 * For example, if I add a Diameter and a Depth to an object, I may want to see it
 * as a Hole.
 * Watch out: You should also implement CATIInstance on this object<br>
 * CATIInstance returns the list of types supported by this object.<br>
 * If a type is added on the object, it should be seen through CATIInstance.
 * In LiteralFeatures framework, you can find CATCkeInstanceAdapter which is an 
 * adapter of those interfaces on feature objects. (see also CATCkeBasicAdapter which is the light ancestor (no attribute data) of CATCkeInstanceAdapter).
 * @see CATIInstance
 * @see CATIType
 * @see CATIValue
 * @see CATIInstance
 */
class ExportedByCATLifSpecs CATIDynamicAttributes : public CATBaseUnknown
{
public :

	/**
	 *	Description: Use this method to dynamically add an attribute to an instance.
   	 *  @param iKey: the name of the attribute which will be used by the GetValue method of CATIInstance to retrieve the attribute on the instance.
	 *  @param iType: the type of the attribute which is being added.
	 *  @param iValue: the value of the attribute which is being added
	 */
	virtual HRESULT Add( const CATUnicodeString& iKey, const CATIType_var& iType, const CATIValue_var& iValue, boolean iIsComponent ) = 0;

	/**
	 *	Description: Removes an attribute from its name.
   	 *  @param iKey: the name of the attribute.
	 */
	virtual HRESULT Remove( const CATUnicodeString& iKey ) = 0;

	/**
	 *	Description: Renames an attribute.
   	 *  @param iOldKey: the old name of the attribute.
	 *  @param iNewKey: the new name of the attribute.
	 */
	virtual HRESULT Rename( const CATUnicodeString& iOldKey, const CATUnicodeString& iNewKey ) = 0;

	/**
	 *	Description: Add the support of a type.
   	 *  @param iTypeAdded: type added.
	 */
	virtual HRESULT AddTypeSupport ( const CATIType_var &iTypeAdded) = 0;

	/**
	 *	Description: Remove the support of a type.
   	 *  @param iTypeRemoved: type added.
	 */
	virtual HRESULT RemoveTypeSupport ( const CATIType_var &iTypeRemoved) = 0;


private:
  CATDeclareInterface;
}; 

CATDeclareHandler(CATIDynamicAttributes, CATBaseUnknown);

#endif
