// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
//  Nov 2005  Creation: LJE
//
//===================================================================
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIPLMNavEntity_H
#define CATIPLMNavEntity_H

#include "CATPLMComponentInterfaces.h"

#include "CATBaseUnknown.h"

#include "CATListOfCATUnicodeString.h"
#include "CATPLMCoreType.h"

extern ExportedByCATPLMComponentInterfaces IID IID_CATIPLMNavEntity;

/**
 * Interface to retrieve general information on an Entity.
 */
class ExportedByCATPLMComponentInterfaces CATIPLMNavEntity: public CATBaseUnknown
{
	CATDeclareInterface;

	public:
		
		/**
		 * Retrieves the client core type of the Entity.
		 * @param oType
		 *   The core type.
		 * @return
		 *   HRESULT
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>S_OK</dt>
		 *     <dd>The type is successfully returned.</dd>
		 *     <dt>E_FAIL</dt>
		 *     <dd>The Entity is not valid or the state of the system is not correct for this operation.</dd>
		 *     <dt>E_UNEXPECTED</dt>
		 *     <dd>There is an unexpected failure.</dd>
		 *   </dl>
		 */
		virtual HRESULT GetPLMCoreType(CATPLMCoreType & oType) = 0;
		
		
		/**
		 * Retrieves the values of a list of public attributes attached to the Entity.
		 *   WARNING: this list is usable for information and display, not for attribute management.
		 * @param ioAttributeNameList
		 *   The list of attributes' internal name.
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>Empty</dt>
		 *     <dd>All the public attributes names and values have to be returned.</dd>
		 *     <dt>Filled</dt>
		 *     <dd>Only the values of the attributes which name is in this list have to be returned. In this case the list is not modified.</dd>
		 *   </dl>
		 * @param oAttributeValueList
		 *   The list of attributes' value. It is is cleaned before treatment.
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>Filled</dt>
		 *     <dd>The list of values of required attributes. This list has the same size than the previous one.</dd>
		 *   </dl>
		 * @return
		 *   HRESULT
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>S_OK</dt>
		 *     <dd>The list (Empty or Filled) is successfully returned.</dd>
		 *     <dt>E_INVALIDARG</dt>
		 *     <dd>The given ioAttributeNameList contains the name of an invalid attribute.</dd>
		 *     <dt>E_FAIL</dt>
		 *     <dd>The Entity is not valid or the state of the system is not correct for this operation.</dd>
		 *     <dt>E_UNEXPECTED</dt>
		 *     <dd>There is an unexpected failure.</dd>
		 *   </dl>
		 */
		virtual HRESULT GetPublicAttributes(
			CATListOfCATUnicodeString & ioAttributeNameList,
			CATListOfCATUnicodeString & oAttributeValueList) = 0;
		
};

CATDeclareHandler(CATIPLMNavEntity, CATBaseUnknown);

#endif
