// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCkePLMTypeAttrServices.h
// Header definition of CATCkePLMTypeAttrServices
//
//===================================================================
//
// Usage notes
//  deprecated: use CATCkePLMNavPublicServices instead. This class is used for the enum only
//
//===================================================================

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#ifndef CATCkePLMTypeAttrServices_H
#define CATCkePLMTypeAttrServices_H

// Module export
#include "CATLifSpecs.h"
#include "IUnknown.h"
#include "CATBoolean.h"
class CATIType_var;
class CATListValCATAttributeInfos;
class CATAttributeInfos;
class CATUnicodeString;

//-----------------------------------------------------------------------
/**
 * Services to access lists of attributes of a PLM Type, filtered by PLM criteria (mandatory, optional, identifier).<br>
 * deprecated: use CATCkePLMNavPublicServices instead. This class is used for the enum only
 * <b>Role</b>: A PLM Type implements the interfaces @href CATIType & @href CATIAttributesDescription, that completely describe its attributes. This class simply provides additional services for filtering those attributes easily
 * based on some criteria.
 * @see CATIType, CATIAttributesDescription, CATAttributeInfos
 */
class ExportedByCATLifSpecs CATCkePLMTypeAttrServices
{

  public:


    /**
	 * Enumerated value that defines the possible criteria that we will use to filter the list of attributes.<br>
	 * @param All
 	 * No filter, we want to access the full list of PLM attributes on the PLM type.
	 * @param Mandatory
	 * We want to produce the list of mandatory attributes only.
	 * @param Optional
	 * We want to produce the list of optional attributes only.
 	 * @param Identification
	 * We want to produce the list of attributes that are part of the identifier set of the object.
	 */
	  enum FilteringCriteria { All, Mandatory, Optional, Identification };
 
	/**
	 * @deprecated R211 CATCkePLMNavPublicServices::ListAttributesFromObject. Because you're likely to start from an object and not a type.<br>
	 * Retrieves the list of attributes of a PLM type that matches the criteria in input.
	 * @param iFilteringCriteria
     *   Filtering criteria to apply
	 * @param iType
     *   The input PLM type to be queried.
	 * @param oListAttr
	 *   The list of PLM attributes obtained. It is filled by the service. The service removes elements of the list in input first.
	 * @param iReadWriteOnly
	 *   Specify if we want to apply an additional filter to access only Read/Write attributes
	 *  <ol>
	 * 	 <li> TRUE if we want to obtain a list of the Read/Write attributes only.
	 * 	 <li> FALSE	(default value) if we do not want to apply this additional filter, and we want to obtain both Read Only attributes and Read/Write.
	 *  </ol>
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the input PLM type is invalid
	 * 	 <li> S_OK	if the list of attributes is valuated (even if empty)
	 *  </ol>
     */
	  static HRESULT ListAttributes		   (const CATCkePLMTypeAttrServices::FilteringCriteria iFilteringCriteria,
											const CATIType_var &iType, 
											CATListValCATAttributeInfos &oListAttr,
											CATBoolean iReadWriteOnly = FALSE);

	/**
	 * @deprecated R211 CATCkePLMNavPublicServices::FindAttributeFromType.<br>
	 * Retrieves if it exists, an attribute of a given name, of a PLM type that matches the criteria in input.
	 * @param iFilteringCriteria
     *   Filtering criteria to apply
	 * @param iType
     *   The input PLM type to be queried.
	 * @param iAttributeName
     *   The non-NLS name of the attribute.
	 * @param opAttr
	 *   The attribute, if found. The service allocates the object, so the given pointer must be NULL, and must be deleted after use.
	 * @param iReadWriteOnly
	 *   Specify if we want to apply an additional filter to access only Read/Write attributes
	 *  <ol>
	 * 	 <li> TRUE if we want to obtain a list of the Read/Write attributes only.
	 * 	 <li> FALSE	(default value) if we do not want to apply this additional filter, and we want to obtain both Read Only attributes and Read/Write.
	 *  </ol>
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the input PLM type is invalid
	 * 	 <li> S_OK	if calculation is ok, even if the attribute is not found (= NULL)
	 *  </ol>
     */
	  static HRESULT FindAttribute		   (const CATCkePLMTypeAttrServices::FilteringCriteria iFilteringCriteria,
											const CATIType_var &iType, 
											const CATUnicodeString& iAttributeName,
											CATAttributeInfos*& opAttr,
											CATBoolean iReadWriteOnly = FALSE);

    /**
    * Enumerated value that defines the possible PLM Mask that we will use to filter the list of attributes.<br>
    * @param MaskWrite
    * We want to produce the list of attributes for component modification purpose.
    * @param MaskQuery
    * We want to produce the list of attributes for full fledge query purpose.
    * @param MaskEZQuery
    * We want to produce the list of attributes for simplified query purpose.
    * @param MaskCreate
    * We want to produce the list of attributes for component creation purpose.
    * @param MaskRead
    * We want to produce the list of attributes for component display purpose.
    * @param MaskTree
    * We want to produce the list of attributes for tree display purpose.
    */
    enum PLMMaskCriteria {MaskWrite, MaskQuery, MaskEZQuery, MaskCreate, MaskRead, MaskTree};

    /**
    * @deprecated R211 CATCkePLMNavPublicServices::ListFilteredAttributesFromMaskAndObject or ListFilteredAttributesFromMaskAndType.
    * Retrieves the list of attributes of a PLM type that matches the PLM Mask criteria in input.
    * @param iKweType
    *   The input type to be queried.
    * @param iPLMMaskCriteria
    *   Filtering PLM Mask criteria to apply
    * @param oListFilteredAttr
    *   The list of PLM attributes obtained. It is filled by the service.
    *   The service removes elements of the list in input first.
    * @return
    *  <ol>
    * 	 <li> E_INVALIDARG if the input PLM type is invalid
    * 	 <li> E_FAIL if failure
    * 	 <li> S_OK if the list of attributes is valuated (even if empty)
    *  </ol>
    */
    static HRESULT ListFilteredAttributesFromMask (const CATIType_var& iKweType,
      const CATCkePLMTypeAttrServices::PLMMaskCriteria iPLMMaskCriteria,
      CATListValCATAttributeInfos &oListFilteredAttr);

};

//-----------------------------------------------------------------------

#endif

