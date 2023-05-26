//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATIPLMCacheData
//
//===================================================================
//
//
//===================================================================
//
// 2012 Creation FBN
// 
//===================================================================

/**
 * @level Private
 * @usage U1
 */

#ifndef CATIPLMCacheData_H
#define CATIPLMCacheData_H

#include "CATPLMIdentificationAccess.h"
#include "CATLISTV_CATPLMID.h"
#include "CATPLMID.h"

#include "CATBaseUnknown.h"
class CATPLMIDMap;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIdentificationAccess IID IID_CATIPLMCacheData;
#else
extern "C" const IID IID_CATIPLMCacheData ;
#endif

extern ExportedByCATPLMIdentificationAccess HRESULT CATIPLMCacheData_UseCache();

class ExportedByCATPLMIdentificationAccess CATIPLMCacheData: public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/*
	* Fastener and ImplementLinkCnx may be only used to associate a list of PLMID, which will be loaded
	* FastenerCnxAndPath and ImplementlinkCnxAndPath may be only used to associate the map of Cnx/path, cnx will
	* be loaded according to the path
	*/
	enum CATPLMAppli {Fastener=0,FastenerCnxAndPath=1,ImplementLinkCnx=2,ImplementLinkCnxAndPath=3};

	/**
	 * Get the list of PLMIDs associated to this object for a given application.
	 * @param iAppli
	 *    The application identifier.
	 * @param oPLMIDs
	 *    The list of associated PLMIDs.
	 *    Life cycle rule: the returned list must not be deallocated.
	 * @return
	 *    S_OK        : The returned list not NULL and not empty.
	 *    S_FALSE     : The returned list NULL or empty. 
	 *    E_INVALIDARG: The asked list is not recognized
	 *    E_FAIL      : Otherwise.
	 */
	virtual HRESULT GetCache(CATPLMAppli iAppli, CATLISTV(CATPLMID) *&oPLMIDs) =0;

	/**
	 * Get the map of PLMIDs associated to this object for a given application.
	 * @param iAppli
	 *    The application identifier.
	 * @param oPLMIDs
	 *    The list of associated PLMIDs.
	 *    Life cycle rule: the returned list must not be deallocated.
	 * @return
	 *    S_OK        : The returned list not NULL and not empty.
	 *    S_FALSE     : The returned list NULL or empty. 
	 *    E_INVALIDARG: The asked list is not recognized
	 *    E_FAIL      : Otherwise.
	 */
	virtual HRESULT GetCache(CATPLMAppli iAppli, CATPLMIDMap *&oPLMIDs) =0;

	/**
	 * Associate a relevant list of PLMIDs to this object for a given application.
	 * Each call replace the associated elements.
	 * @param iAppli
	 *    The application identifier.
	 * @param iPLMIDs
	 *    The list of PLMIDs to associate.
	 *    Life cycle rule: if not NULL, the list MUST have been allocated using a "new".
	 *                     Implementation will handle deletion.
	 *                     Is a previous list/map of PLMID exist on this object for that application, it will be deleted.
	 * @return
	 *    S_OK        : The association has been done.
	 *    E_INVALIDARG: The asked list is not recognized
	 *    E_FAIL      : Otherwise.
	 */
	virtual HRESULT SetCache(CATPLMAppli iAppli, CATLISTV(CATPLMID) *iPLMIDs) =0;

	/**
	 * Associate a relevant map of PLMIDs to this object for a given application.
	 * Each call replace the associated elements.
	 * @param iAppli
	 *    The application identifier.
	 * @param iPLMIDs
	 *    The list of PLMIDs to associate.
	 *    Life cycle rule: if not NULL, the list MUST have been allocated using a "new".
	 *                     Implementation will handle deletion.
	 *                     Is a previous list/map of PLMID exist on this object for that application, it will be deleted.
	 * @return
	 *    S_OK        : The association has been done.
	 *    E_INVALIDARG: The asked list is not recognized
	 *    E_FAIL      : Otherwise.
	 */
	virtual HRESULT SetCache(CATPLMAppli iAppli, CATPLMIDMap *iPLMIDs) =0;

	/**
	* Erase the cache for a given application.
	* This reset the state of the cache as the prior state from any invocation of SetCache on this particular application
	* @param iAppli
	*    The application identifier.
	* @return
	*    S_OK        : The association is gone
	*    E_INVALIDARG: The asked application is not recognized
	*    E_FAIL      : Otherwise
	*/
	virtual HRESULT ResetCache(CATPLMAppli iAppli) =0;

	/**
	* Erase the cache for every application.
	* This reset the state of caches as the prior state from any invocation of SetCache on any application
	* @param iAppli
	*    The application identifier.
	* @return
	*    S_OK        : The associations are gone
	*    E_FAIL      : Otherwise
	*/
	virtual HRESULT ResetAllCaches() =0;
};
#endif
