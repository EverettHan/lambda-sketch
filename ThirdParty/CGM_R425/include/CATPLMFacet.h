// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATPLMFacet.h
//
//===================================================================
//
// Usage notes:
//
//  June 2011  Creation: FBN
//  March 2017 R420 removed JRZ
//===================================================================
#include "CATPLMFTSAvailable.h"
#include "CATIAV5Level.h"
#ifdef FTSAvailable

#ifndef CATPLMFacet_H
#define CATPLMFacet_H
#include "CATBaseUnknown.h"
#include "CATPLMServicesItf.h"
#include "CATUnicodeString.h"
#include "CATString.h"
#include "CATOmxVector.h"
#include "CATPLMTypeId.h"

/**
* @level Protected
* @usage U2
*/

/** @nodoc */
class ExportedByCATPLMServicesItf CATPLMFacetValue : public CATBaseUnknown
{
	friend class CATPLMFacet;

public:
	/** 
	 * @deprecated
	 */
	HRESULT GetId(CATString &oId);

	/** 
	 * Retrieve the FacetValue value.
	 * @param oValue
	 *     Value of the FacetValue.
	 * @return
	 *     Error code of function :
	 *     <dl>
	 *       <dt>S_OK</dt>
	 *       <dt>E_FAIL </dt>
	 *     </dl>
	 */
	HRESULT GetValue(CATUnicodeString &oValue);

	/** 
	 * Get estimated number of objects implementing this FacetValue.
	 * @return
	 *     number of objects
	 */
	int     Count();

private:
	CATPLMFacetValue(CATUnicodeString &iValue, int iCount);
	virtual ~CATPLMFacetValue();
	CATUnicodeString value;
	int count;
};

/** @nodoc */
class ExportedByCATPLMServicesItf CATPLMFacet : public CATBaseUnknown
{
	friend class CATPLMDataSetQueryHandler;// M1 implementation
	friend class CATPLMDebugSearchQueryHandler;// TST Provider implementation

public:
	/** 
	 * @deprecated
	 */
	HRESULT GetId(CATString &oId);

	/** 
	 * Retrieve the Facet name.
	 * @param oName
	 *     Name of the Facet.
	 * @return
	 *     Error code of function :
	 *     <dl>
	 *       <dt>S_OK</dt>
	 *       <dt>E_FAIL </dt>
	 *     </dl>
	 */
	HRESULT GetName(CATUnicodeString &oName);

	/** 
	 * Retrieve the associated extension type, if any.
	 * @param oExtType
	 *     Name of the Facet.
	 * @return
	 *     Error code of function :
	 *     <dl>
	 *       <dt>S_OK</dt>
	 *       <dt>E_FAIL </dt>
	 *     </dl>
	 */
	HRESULT GetExtensionType(CATPLMTypeId &oExtType);

	/** 
	 * Retrieve facet values.
	 * Life cycle:
	 *     - each element of the returned oValues array must be released
	 *     - oValues must be deleted
	 *
	 * @sample
	 *   CATPLMFacetValue **values  = NULL;
	 *   int                nbValues = 0;
	 *   if (SUCCEEDED(facet->GetValues(values, nbValues))) {
	 *       for (int i=0;i<nbValues;i++) {
	 *           if (values[i]) {
	 *               ...
	 *               CATSysReleasePtr(values[i]);
	 *           }
	 *       }
	 *       delete []values;
	 *       values = NULL;
	 *   }
	 *
	 * @param oValues
	 *     List of values. Each element must be released, array must be deleted.
	 * @param oNbValues
	 *     Number of values
	 * @return
	 *     Error code of function :
	 *     <dl>
	 *       <dt>S_OK</dt>
	 *       <dt>E_FAIL </dt>
	 *     </dl>
	 */
	HRESULT GetValues(CATPLMFacetValue **&oValues, int &oNbValues);

private:
	CATPLMFacet(CATUnicodeString &iId, CATPLMTypeId &iExtType);
	virtual ~CATPLMFacet();

	void AddValue(CATUnicodeString &iValue, int iCount);

	CATUnicodeString id;
	CATPLMTypeId     ext;
	CATOmxVector<CATPLMFacetValue> values;
};
#endif
#endif
