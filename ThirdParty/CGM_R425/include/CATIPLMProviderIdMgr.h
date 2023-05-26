#ifndef CATIPLMProviderIdMgr_H
#define CATIPLMProviderIdMgr_H

#include "CATBaseUnknown.h"

#include "CATPLMServicesItf.h"

#include "CATBSTR.h"
#include "CATIAdpPLMIdentificator.h"
#include "CATListPtrCATIAdpPLMIdentificator.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMProviderIdMgr;
#else
extern "C" const IID IID_CATIPLMProviderIdMgr;
#endif

/**
* This interface is the access point to convert obj ids into CATListPtrCATIAdpPLMIdentificator and conversely
*/
class ExportedByCATPLMServicesItf CATIPLMProviderIdMgr : public CATBaseUnknown
{
	CATDeclareInterface;

public:
	/**
	* Gets a CATListPtrCATIAdpPLMIdentificator from an object Id
	* @param iId the id of the object
	* @param oPLMIDs the CATListPtrCATIAdpPLMIdentificator of the object
	* @return S_OK on success
	*/
	virtual HRESULT GetPLMIDsFromProviderID(const CATBSTR &iId, CATLISTP(CATIAdpPLMIdentificator)&  oPLMIDs ) = 0;

	/**
	* Gets an object Id from a CATListPtrCATIAdpPLMIdentificator
	* @param iPLMIDs the CATListPtrCATIAdpPLMIdentificator of the object
	* @param oId the id of the object
	* @return S_OK on success
	*/
	virtual HRESULT GetProviderIDFromPLMIDs(CATLISTP(CATIAdpPLMIdentificator)&  iPLMIDs, CATBSTR& oId) = 0;


};

#endif
