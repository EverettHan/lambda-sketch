#ifndef CATIAttributesDescription_h
#define CATIAttributesDescription_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/** 
* @CAA2Level L1
* @CAA2Usage U3
*/

// inherited class 
#include "CATBaseUnknown.h"

// load module
#include "CATLifSpecs.h"

#include "CATListValCATAttributeInfos.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIAttributesDescription;
#else 
extern "C" const IID IID_CATIAttributesDescription;
#endif

/**   
 * Interface to describe the attributes on a Knowledge type (most of the cases) or eventually on an object.<br>
 * <b>Role</b>: You can consult this interface to know the list of attributes on a Knowledge type (or an object implementing this interface).<br>
 * This interface is used in KnowledgeExpert to provide the list of attributes on a type and an object.<br>
 * This interface is multi-implemented.<br>
 * @see CATICkeObject, CATIType, CATIValue, CATAttributeInfos
 */
class ExportedByCATLifSpecs CATIAttributesDescription : public CATBaseUnknown
{
public:
	/**
	*	Returns the list of informations on attributes held by the Knowledge type.
	*   @param oListOfAttributeInfos : the list of informations on attributes
	*	@param recursively : if true, the output list will also contain the attributes given by the inheritance mechanism provided by CATIType
	*   @return classic HRESULT
	*/
	virtual HRESULT List( CATListValCATAttributeInfos* oListOfAttributeInfos, boolean recursively = 1 ) const = 0;
	/**
	*	Returns information about the attribute whose name is specified as argument.
	*   @param iName : the name of the attribute for which informations are required
	*	@param oAttributeInfos : the output informations about the attribute. This object is allocated
	*   @return classic HRESULT
	*/
	virtual HRESULT FindByName( const CATUnicodeString& iName, CATAttributeInfos*& oAttributeInfos ) const = 0;
	/**
	*	Returns information about the attribute whose NLS-name is specified as argument.
	*	@param iNLSName : the name of the attribute for which informations are required
	*	@param oAttributeInfos : the output informations about the attribute
	*   @return classic HRESULT
	*/
	virtual HRESULT FindByNLSName( const CATUnicodeString& iNLSName, CATAttributeInfos*& oAttributeInfos ) const = 0;

private:
  CATDeclareInterface;
}; 

CATDeclareHandler(CATIAttributesDescription, CATBaseUnknown);

#endif
