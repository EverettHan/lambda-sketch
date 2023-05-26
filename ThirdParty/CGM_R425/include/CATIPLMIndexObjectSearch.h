//===================================================================
// COPYRIGHT Dassault Systemes 2019/05/21
//===================================================================
// CATIPLMIndexObjectSearch.cpp
// Header definition of class CATIPLMIndexObjectSearch
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2019/05/21 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIPLMIndexObjectSearch_H
#define CATIPLMIndexObjectSearch_H

#include "GUIDCATPLMIndexInterfaces.h"
#include "CATBaseUnknown.h"

#include "CATLISTV_CATPLMID.h"
#include "CATListOfCATUnicodeString.h"
#include "CATUnicodeString.h"

extern ExportedByGUIDCATPLMIndexInterfaces  IID IID_CATIPLMIndexObjectSearch;

/**
* Solution replacing the Tactical Solution CATIPLMIndexTacticalObjectSearch
* Interface providing a c++ wrapper for some search services such as
* search_in_context.
*/
class ExportedByGUIDCATPLMIndexInterfaces CATIPLMIndexObjectSearch : public CATBaseUnknown
{
	CATDeclareInterface;

public:

	/**
	* HAS EFFECT ONLY IF CALLED BEFORE DoExpandQueryForGettingPLMObjects
	* Set the maximum expected objects. If there are more, they will be ignored. A number <= 0 means all parts have to be returned, note that this parameter does impact performance.
	* Default value is 40 (default nresults parameters for fed search)
	*/
	virtual void SetMaxExpectedResult(const int &iExpectedResult) = 0;

	/**
	* Do a query on objects inside a specific object using a search-in-context 
	* (a federatedSearch query within the scope of an Expand on a root)
	* Do not take into account if object is searchable or not,
	* non searchable object, only available normally to expand or expand3d,
	* will also be searched for (bypass searchable).
	* @param iusExpansionRootPhyid [in]
	* The physicalid of the root on which expand will be done (an "object containing" other objects)
	* @param iusQueryLabel [in]
	* The label to give to your query. Usefull for debugging (current date and time will be appended to it)
	* @param iusUQLQuery [in]
	* The query, in UQL format, to be applied to the objects. Ex:
	* "[bo.PLMEntity.PLM_ExternalID]:\"APLMEXTERNALID\"";
	* @param olFoundPLMIDs [out]
	* The list of PLMIDs returned by the query
	* @param iDepth [in]
	* The query depth, if you want to search inside the objects contained in the root one
	* @return
	*   S_OK in case of successful query (even if output object list is empty)
	*   E_FAIL otherwise
	*/
	virtual HRESULT DoExpandQueryForGettingPLMObjects(const CATUnicodeString &iusExpansionRootPhyid, const CATUnicodeString &iusQueryLabel, const CATUnicodeString &iusUQLQuery, CATListValCATPLMID &olFoundPLMIDs, const int &iDepth = 1) const = 0;
	
	/**
	* Do a query on objects inside a specific object using a search-in-context 
	* (a federatedSearch query within the scope of an Expand on a root)
	* Do not take into account if object is searchable or not,
	* non searchable object, only available normally to expand or expand3d,
	* will also be searched for (bypass searchable).
	* @param iusExpansionRootPhyid [in]
	* The physicalid of the root on which expand will be done (an "object containing" other objects)
	* @param iusQueryLabel [in]
	* The label to give to your query. Usefull for debugging (current date and time will be appended to it)
	* @param iusUQLQuery [in]
	* The query, in UQL format, to be applied to the objects. Ex:
	* "[bo.PLMEntity.PLM_ExternalID]:\"APLMEXTERNALID\"";
	* @param iWithSearchable [in]
	* TRUE : takes searchable into account (ignore non-searchable objects in the search part of the search in context)
	* FALSE : ignores searchable (retrieves any object in the search part of the search-in-context)
	* @param olFoundPLMIDs [out]
	* The list of PLMIDs returned by the query
	* @param iDepth [in]
	* The query depth, if you want to search inside the objects contained in the root one
	* @return
	*   S_OK in case of successful query (even if output object list is empty)
	*   E_FAIL otherwise
	*/
	virtual HRESULT DoExpandQueryForGettingPLMObjects(const CATUnicodeString &iusExpansionRoot, const CATUnicodeString &iusQueryLabel, const CATUnicodeString &iusUQLQuery, const CATBoolean &iWithSearchable, CATListValCATPLMID &olFoundPLMIDs, const int &iDepth = 1) const = 0;

	//same as above with an option to include relationships in the search

	virtual HRESULT DoExpandQueryForGettingPLMObjects(const CATUnicodeString& iusExpansionRoot, const CATUnicodeString& iusQueryLabel, const CATUnicodeString& iusUQLQuery, const CATBoolean& iWithSearchable, const CATBoolean& iWithRelationships, CATListValCATPLMID& olFoundPLMIDs, const int& iDepth = 1) const = 0;

};

//-----------------------------------------------------------------------
CATDeclareHandler(CATIPLMIndexObjectSearch, CATBaseUnknown);

CATIPLMIndexObjectSearch_var ExportedByGUIDCATPLMIndexInterfaces GetCATIPLMIndexObjectSearch();

#endif