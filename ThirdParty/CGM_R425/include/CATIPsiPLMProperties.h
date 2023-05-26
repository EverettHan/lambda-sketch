// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIPsiPLMProperties.h
// Define the CATIPsiPLMProperties interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================

/**
* @level Protected
* @usage U3
*/

#ifndef CATIPsiPLMProperties_H
#define CATIPsiPLMProperties_H

#include "PLMPSISessionInterfaces.h"
#include "CATBaseUnknown.h"

// System 
class CATString;

// PLMSessionInterfaces
class CATListValPLMPSIAttrValuation;
class CATListValPLMPSIAttrInfos;

// Knowledge
class CATIType;
class CATIValue;

extern ExportedByPLMPSISessionInterfaces IID IID_CATIPsiPLMProperties;
/**
 * Interface managing attributes of a Product Modeler entity.
 * <br><b>Role</b>: This interface enables to retrieve attributes information or to valuate attributes on a Product Modeler entity.
 * <br>This interface is implemented by following PLM features:
 * <ul>
 *	<li>Product Instance & Product Reference</li>
 *	<li>Representation Instance & Representation Reference</li>
 *	<li>Port</li>
 * </ul>
 */
class ExportedByPLMPSISessionInterfaces CATIPsiPLMProperties: public CATBaseUnknown
{
	CATDeclareInterface;

	public:

		/**
		 * Different kinds of filters for PLM attributes.
		 * @param Mandatory
		 *    Mandatory attributes.
		 * @param Identification
		 *    Attributes of the Identification Set.
		 * @param Optional
		 *    Optional Attributes.
		 */
		enum CATPLMPsiAttrCategoryFilter
		{
			Mandatory = 0,
			Identification = 1, 
			Optional = 2
		};

		/**
		 * Retrieves the value of an attribute using its name and the type of its PLM entity.<br>
     * This method is only defined for Reference and first Instance of PLM entities.
		 * @param iAttrName
		 *    The internal name of the attribute.
		 * @param ipiType
		 *    The Knowledge type of the PLM entity (in order to avoid naming conflict between attributes belonging to differents extensions).<br>
		 *    NULL can be specified to match any type.
		 * @param opiValue [out, CATBaseUnknown#Release]
		 *    The returned value of the property attribute.<br>
     *    In some cases, it could be NULL when
		 *    <ul>
		 *       <li>the value is equal to zero</li>
		 *       <li>or the value is an empty string</li>
		 *    </ul>
		 * <br>
		 *    This value could be multi-valuated.
		 *    In such case, the returned value must be transformed in @href CATIList in order to get all values.
		 *    @example
		 *    <br>For example:
		 *    <pre>
		 *    CATIPsiPLMProperties * pPLMProp = ...;
		 *    CATIValue * opValue = NULL;
		 *    if(SUCCEEDED(pPLMProp->GetValue(iAttrName,NULL,opValue)))
		 *    {
		 *      if(opValue)
		 *      {
		 *        CATIList_var hList=opValue;
		 *        if(!hList)
		 *           // It is a mono-valuated attribute
		 *        else
		 *           // It is a multi-valuated attribute
		 *        opValue->Release();
		 *        opValue = NULL;
		 *      }
		 *    }
		 *    </pre>
		 * @return
		 *    <ul>
		 *    <li> E_FAIL if</li>
		 *        <ul>
		 *           <li>the Knowledge type is not supported by the PLM entity</li>
		 *           <li>or the attribute does not exists</li>
		 *           <li>or this method is called on another object than a Reference or a first Instance</li>
		 *        </ul>
		 *    <li> S_OK if the internal name is found. Nevertheless, in some cases (explained above), the returned value can be a NULL pointer. </li>
		 *    </ul>
		 */
		virtual HRESULT GetValue(const CATString& iAttrName, CATIType* ipiType, CATIValue*& opiValue) = 0;

		/**
		 * Sets the value of an attribute using its name and the type of its PLM entity.<br>
     * This method is only defined for Reference and first Instance of PLM entities.
		 * @param iAttrName
		 *    The internal name of the attribute.
		 * @param ipiValue
		 *    The value of the attribute.
		 * @param ipiType
		 *    The Knowledge type of the PLM entity (in order to avoid naming conflict between attributes belonging to differents extensions).<br>
		 *    NULL can be specified to match any type.
		 * @return
		 *    <ul>
		 *    <li> E_FAIL if</li>
		 *        <ul>
		 *           <li>the Knowledge type is not supported by the PLM entity</li>
		 *           <li>or the attribute does not exists</li>
		 *           <li>or the value of the attribute is NULL</li>
		 *           <li>or this method is called on another object than a Reference or a first Instance</li>
		 *        </ul>
		 *    <li> S_OK if the value is successfully set </li>
		 *    </ul>
		 */
		virtual HRESULT SetValue(const CATString& iAttrName, const CATIValue* ipiValue, CATIType* ipiType) = 0;

		/**
		 * Retrieves the list of mandatory/identification/optional attributes information for a typed PLM entity.<br>
     * This method is only defined for Reference and first Instance of PLM entities.
		 * @param olAttrInfos
		 *    The list of attributes informations.
		 * @param iCategory
		 *    The category of attributes to be retrieved. 
		 * @return
		 *    <ul>
		 *    <li> E_FAIL if this method is called on another object than a Reference or a first Instance </li>
		 *    <li> S_OK if no errors occured (the list of attributes informations could be empty if no match was found) </li>
		 *    </ul>
		 */
		virtual HRESULT GetListAttrInfos(CATListValPLMPSIAttrInfos& olAttrInfos, CATPLMPsiAttrCategoryFilter iCategory) = 0;

		/**
		 * Retrieves the list of mandatory/identification/optional attributes values for a typed PLM entity.<br>
     * This method is only defined for Reference and first Instance of PLM entities.
		 * @param olAttrValues
		 *    The list of attributes values.
		 * @param iCategory
		 *    The category of attributes to be retrieved.
		 * @return
		 *    <ul>
		 *    <li> E_FAIL if this method is called on another object than a Reference or a first Instance </li>
		 *    <li> S_OK if no errors occured (the list of attributes values could be empty if no match was found) </li>
		 *    </ul>
		 */
		virtual HRESULT GetListValues(CATListValPLMPSIAttrValuation& olAttrValues, CATPLMPsiAttrCategoryFilter iCategory) = 0;
};

CATDeclareHandler( CATIPsiPLMProperties, CATBaseUnknown );
//------------------------------------------------------------------

#endif
