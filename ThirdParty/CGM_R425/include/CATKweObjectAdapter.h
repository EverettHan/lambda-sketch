// Copyright Dassault Systemes 2008
#ifndef CATKweObjectAdapter_H
#define CATKweObjectAdapter_H

#include "CATLifSpecs.h"

/** 
* @CAA2Level L1
* @CAA2Usage U2 
*/


// Adapter of CATICkeFeature and CATICkeObject
#include "CATICkeObject.h"
class CATICkeType_var;
class CATUnicodeString;

/**
* Class to be used as an adapter for objects that want to implement CATICkeFeature or CATICkeObject (or both).<br>
*
* In addition to extension, you must create one of the TIE object with 
* - TIEchain_CATICkeFeature
* - TIEchain_CATICkeObject
*/

class ExportedByCATLifSpecs CATKweObjectAdapter : public CATICkeObject
{
public:
	
	

	/**
	 * Constructor.
	 */
	CATKweObjectAdapter();
	
	/**
	 * Destructor.
	 */
	virtual ~CATKweObjectAdapter() ;
		
	//-------------------------------------------
	// Interface CATICkeObject implementation
	//-------------------------------------------
	/**
	* Returns the Logical name of the object. The logical name is a name that the end-user can give (modify) and that has no constraint of unicity.<br>
	* Default implementation relies on CATIAlias::GetAlias method.<br>
	* For objects in representation, it is usually sufficient. For PLM objects CATIAlias has been used to provide a computed name. That's why it cannot be used for logical name implementation.<br>
	* As a consequence, for PLM objects, this method MUST BE overriden.<br>
	* @param oLogicalName
	* Logical name in output
    * @return
	*  <ol>
	* 	 <li> E_ACCESSDENIED if the logical name cannot be read.
	* 	 <li> E_FAIL if the logical name cannot be read.
	* 	 <li> S_OK	if the logical name has been read successfully.
	*  </ol>
	*/
	virtual HRESULT  GetLogicalName    (CATUnicodeString &oLogicalName) const ;

	/**
	* Sets the Logical name of the object. The logical name is a name that the end-user can give (modify) and that has no constraint of unicity.<br>
	* Default implementation relies on CATIAlias::SetAlias method.<br>
	* For objects in representation, it is usually sufficient. For PLM objects CATIAlias has been used to provide a computed name. That's why it cannot be used for logical name implementation.<br>
	* As a consequence, for PLM objects, this method MUST BE overriden.<br>
	* @param iLogicalName Logical name in input
	* @return HRESULT
	*  <ol>
	* 	 <li> E_ACCESSDENIED if the valuation has failed (read only attribute, object not editable).
	* 	 <li> E_FAIL if the logical name cannot be set.
	* 	 <li> S_OK	if the logical name has been set successfully.
	*  </ol>
	*/
	virtual HRESULT  SetLogicalName    (const CATUnicodeString &iLogicalName) ;

	/**
	* Indicates if this object provides access to its simple attributes through generic methods CATCkeObjectAttrReadServices and CATCkeObjectAttrWriteServices.<br>
	* Default implementation returns FALSE. Can be overriden.<br>
	* @return indicates if this object provides access to its simple attributes through generic methods.
	*/
	virtual CATBoolean IsPublic () const ;

	//-------------------------------------------
	// Interface CATICkeFeature (to be selected in rules/formulas/checks
	//-------------------------------------------
	

 	/**
	 * Returns the type of the object.
	 * This type is used to check that the formula (rule or check) syntax is correct. 
	 * If your object implements CATIInstance, the classical implementation returns the CATIInstance::Type method.
	 * If not, usually the implementation consists in calling CATGlobalFunctions::GetTypeDictionary()->FindTypeSafe("TypeName","PackageName",oType)
	 * Default implementation returns the Feature type.
	 *
	 * @return the main type of the object. It is also a CATIType.
	 */
	virtual CATICkeType_var GetType    () const ;


 
private:

	CATKweObjectAdapter(const CATKweObjectAdapter&);
};

#endif
