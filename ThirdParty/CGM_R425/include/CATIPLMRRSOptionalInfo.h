// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATIPLMRRSOptionalInfo.h
// Define the CATIPLMRRSOptionalInfo interface
//
//===================================================================
//
// Usage notes:
//   Optional informations that can be returned by repositories:
//   For FTS, global number of result....
//
//===================================================================
//
// May 2011  Creation: EPB
//===================================================================
/**
* @level Protected
* @usage U3
*/
#include "CATPLMFTSAvailable.h"
#include "CATIAV5Level.h"
#ifdef FTSAvailable

#ifndef CATIPLMRRSOptionalInfo_H
#define CATIPLMRRSOptionalInfo_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMRRSOptionalInfo;
#else
extern "C" const IID IID_CATIPLMRRSOptionalInfo ;
#endif

#include "CATOmxIter.h"

class CATPLMTaxonCategory;
class CATPLMFacet;

class CATPLMAdapterTag;

class ExportedByCATPLMServicesItf CATIPLMRRSOptionalInfo: public CATBaseUnknown
{
	CATDeclareInterface;

public:

	/**
	 * Returns the next Taxon Category.
	 *
	 * @param oTaxonCategory [out, CATBaseUnknown#Release]
	 *         next Taxon Category
	 * @return
	 *   Error code of function :
	 *   <dl>
	 *     <dt>S_OK</dt>
	 *     <dd>the new current Taxon Category is valid.</dd>
	 *     <dt>S_FALSE </dt>
	 *     <dd>there are no more Taxon Category</dd>
	 *     <dt>E_FAIL </dt>
	 *     <dd>A problem occurs during the operation.</dd>
	 *   </dl>
	 */	
	virtual HRESULT Next(CATPLMTaxonCategory ** oTaxonCategory) = 0;

	/**
	 * Return the number of objects found in repository (DB, Index..) that respect criterias defined in Query.
	 *
	 * <br><b>Role</b>: Return the number of objects found in repository (DB, Index..) that respect criterias defined in Query.
	 * eg: Suppose you have a query that returns 10000 objects. Suppose you have decided to display pages of 50 objects.
	 *     oNumberOfObjects returns 10000.
	 *
	 *
	 * @param oNumberOfObjects
	 *        number of objects found in repository (DB, Index..) that respect criterias defined in Query.
	 * @return
	 * <dl>
	 * <dt><code>S_OK</code> <dd>
	 * <dt><code>E_FAIL</code>oNumberOfObjects ==-1<dd>
	 * </dl>
	 */

	virtual HRESULT GetFetchGlobalCount(int& oNumberOfObjects) = 0;

	/**
	 * Returns the next Facet.
	 *
	 * @param oFacet [out, CATBaseUnknown#Release]
	 *         next Facet
	 * @return
	 *   Error code of function :
	 *   <dl>
	 *     <dt>S_OK</dt>
	 *     <dd>the new current Facet is valid.</dd>
	 *     <dt>S_FALSE </dt>
	 *     <dd>there are no more Facet</dd>
	 *     <dt>E_FAIL </dt>
	 *     <dd>A problem occurs during the operation.</dd>
	 *   </dl>
	 */	
	virtual HRESULT Next(CATPLMFacet **oFacet) = 0;

	/**
	 * Returns the list of suggestions.
	 *
	 * @param oSuggestions
	 *         list of suggestions
	 * @return
	 *   Error code of function :
	 *   <dl>
	 *     <dt>S_OK</dt>
	 *     <dd>Evrything is ok.</dd>
	 *     <dt>E_FAIL </dt>
	 *     <dd>No suggestions.</dd>
	 *   </dl>
	 */	
	virtual HRESULT GetSuggestions(CATListOfCATUnicodeString &oSuggestions) = 0;

	/**
	 * Returns an iterator on all tags returned by server.
	 */	
  virtual HRESULT GetTagIterator ( CATOmxIter <CATPLMAdapterTag> &oTagIterator) = 0;

};

#endif
#endif

