// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
//  Dec 2005  Creation: LJE
//
//===================================================================
/**
 * @level Protected
 * @usage U2
 */
#ifndef CATPLMNavEntityAdapter_H
#define CATPLMNavEntityAdapter_H

#include "CATPLMComponentInterfaces.h"

#include "CATIPLMNavEntity.h"

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
//#include "CATPLMCoreType.h"

class CATIAdpType;

/**
* Adapter class for @href CATPLMComponentInterfaces.CATIPLMNavEntity interface.
*/
class ExportedByCATPLMComponentInterfaces CATPLMNavEntityAdapter : public CATIPLMNavEntity
{
	public:

		/** @nodoc */
		CATPLMNavEntityAdapter();

		/** @nodoc */
		virtual ~CATPLMNavEntityAdapter();

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavEntity#GetPLMCoreType
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
		virtual HRESULT GetPLMCoreType(CATPLMCoreType & oType);

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavEntity#GetPLMCoreType
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
		virtual HRESULT GetPLMType(CATIAdpType *& opiType);

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavEntity#GetPLMCoreType
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
		virtual HRESULT GetPublicAttributes(
			CATListOfCATUnicodeString & ioAttributeNameList,
			CATListOfCATUnicodeString & ioAttributeValueList);

	private:

		CATPLMNavEntityAdapter(const CATPLMNavEntityAdapter & iObjectToCopy);
		CATPLMNavEntityAdapter & operator = (const CATPLMNavEntityAdapter & iObjectToCopy);
};

#endif
