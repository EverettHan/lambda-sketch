#ifndef CATKweDicoExtension_h
#define CATKweDicoExtension_h

// COPYRIGHT DASSAULT SYSTEMES 2009


#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"
#include "CATListValCATIType.h"
class CATIType_var;
class CATIInstance_var;


class ExportedByCATLifSpecs CATKweDicoExtension {
public:
	

	/**
	 * Some extensions on references are to be seen as extensions on the occurence. If a different type.<br>
     * The purpose of this method is to retrieve from the type of an extension, the type that is implicitely deduced on the occurence.<br>
	 * Not all extensions have a corresponding type for the occurrence.<br>
	 * @param iTypeOfExtension
	 * Type of extension.<br>
	 * @param oTypeOfOccurrence
	 * Type computed for the occurrence. May be NULL_var if the type of extension has no equivalent for the occurrence.<br>
	 * @return
	 *  <ol>
	 * 	 <li> S_OK	if we retrieved an occurrence
	 * 	 <li> S_FALSE if the type has no occurrence type equivalent (the  oTypeOfOccurrence is NULL_var)
	 * 	 <li> E_INVALIDARG otherwise.
	 *  </ol>
	 */
	static HRESULT RetrieveOccurrenceFromExtension(const CATIType_var &iTypeOfExtension,CATIType_var &oTypeOfOccurrence); 

	/**
	 * This service encapsulates the previous one. It scans the type supported by the object in argument and retrieves the occurences corresponding to the type, if any.<br>
	 * @param iReferenceObject
	 * Reference object.<br>
	 * @param oTypeOfOccurrence
	 * Type computed for the occurrence. May be NULL_var if the type of extension has no equivalent for the occurrence.<br>
	 * @return
	 *  <ol>
	 * 	 <li> S_OK	if we retrieved an occurrence
	 * 	 <li> S_FALSE if the type has no occurrence type equivalent (the  oTypeOfOccurrence is NULL_var)
	 * 	 <li> E_INVALIDARG otherwise.
	 *  </ol>
	 */
	static HRESULT RetrieveOccurrenceFromObject(const CATIInstance_var &iReferenceObject,CATListValCATIType_var& oListOfCATIType); 

	/**
	 * FOR TYPES CREATED BY CODE, this method is used to tag the occurrence type to be used for a given extension.
	 * @param iTypeOfExtension
	 * Type of extension.<br>
	 * @param iTypeOfOccurrence
	 * Type of occurence.<br>
	 * @return
	 *  <ol>
	 * 	 <li> S_OK	if service worked ok
	 * 	 <li> S_FALSE	if service worked ok but a value was already set !
	 * 	 <li> E_INVALIDARG otherwise
	 *  </ol>
	 */
	static HRESULT SetOccurrenceTypeOnType(const CATIType_var &iTypeOfExtension,const CATIType_var &iTypeOfOccurrence); 

private:
};

#endif 
