#ifndef CATAttributePLMInfos_h
#define CATAttributePLMInfos_h

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "CATAttributeInfos.h"
#include "CATUnicodeString.h"
#include "CATIType.h"
#include "CATICkeParm.h"
#include "CATICkeUnit.h"
#include "CATListValCATICkeParm.h"

/**
* Class to be used to define attributes of a PLM type. <br>
* NOBODY SHOULD USE THIS CLASS EXCEPT the software that projects the metadata into Knowledge Dico. <br>
* <b>Role</b>: A PLM type is defined from the PLM Metadata.<br>
* <p>
*/

class ExportedByCATLifSpecs CATAttributePLMInfos : public CATAttributeInfos
{
public:
	/** copy constructor */
	CATAttributePLMInfos( const CATAttributePLMInfos& iInfos );

	/**
	* Constructor: this constructor is made for PLM attributes. It is not supposed to be use except by the services converting metadata to Knowledge dictionary.
	*
	* @param iType            Type the attribute is added to.
	* @param iName            Internal name of the attribute.
	* @param iNLSName         NLS (user) name of the attribute. 
	* @param isWriteable      TRUE if the attribute can be modified, else FALSE.
	* @param isComponent      TRUE if the attribute contains a component. If TRUE,
	*                         the component's owner should be the owner of the attribute, and its
	*                         name the attribute name.
	* @param isVisible        TRUE if the attribute is visible by the user, else FALSE. 
	* @param dummy            Not used.
	* @param isMandatory      TRUE if the attribute is mandatory, else FALSE. 
	* @param iDefaultValue    Default value. Must be of the same type as the attribute (it is not checked). The default value is copied 
	* @param iAutorizedValues List of authorized values. If not empty,iDefaultValue must be not null. Works with strings, doubles, integers, dimensions
	*                         For dimensions, the value mustn't precise the dimension. It is a double interpreted in MKS
	* @param iHelpValues      List of help values. Works with strings, doubles, integers, dimensions
	*                         For dimensions, the value mustn't precise the dimension. It is a double interpreted in MKS
	* @param iMaxLength       For strings. Max size to be shown in editors<br>
	* @param iAttributeAccess Only Use the Default Value = "".<br>
	*						  (Name of the CATIAttributeAccess implementation class used to
	*                         delegate the valuation of this particular attribute)
	* @param piListProperties additional user properties
	* Note finally, that by default, an attribute is not mandatory
	* @param isFacetted 
	* Is used as a facetted attribute in indexation/search
	*/
	CATAttributePLMInfos( const CATIType_var& iType,
					   const CATUnicodeString& iName,
					   const CATUnicodeString& iNLSName,
					   const boolean isWriteable,
					   const boolean isComponent,
					   const boolean isVisible,
					   const boolean isMandatory,
					   const CATICkeParm_var& iDefaultValue,
					   const CATListOfCATUnicodeString& iAutorizedValues,
					   const int iMaxLength,
					   const CATUnicodeString& iAttributeAccess = "",
					   const CATICkeUnit_var &iDefaultManipulationUnit = NULL_var,
					   const CATBoolean isControlledByModeler = TRUE,
					   const CATLISTV(CATICkeParm_var) *piListProperties = NULL,
					   const CATBoolean isFacetted = FALSE); // Attention,pour des raisons de performances, les properties (CATICkeParm) ne sont pas dupliques

	// Sorte de copy constructeur pour produire un attribut maske
	CATAttributePLMInfos(CATAttributeInfos &AttrToCopy,
					     const CATUnicodeString& iNLSName,
					     const boolean isWriteable,
					     const boolean isVisible,
					     const boolean isMandatory,
					     const CATICkeParm_var& iDefaultValue,
					     const CATListOfCATUnicodeString& iAutorizedValues,
					     const CATListOfCATUnicodeString& iHelpValues,
					     const int iMaxLength,
					     const CATICkeUnit_var &iDefaultManipulationUnit );

                                                                
	/** destructor */
	virtual ~CATAttributePLMInfos();

private:
	
};

#endif 
