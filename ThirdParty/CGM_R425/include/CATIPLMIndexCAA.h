#ifndef CATIPLMIndexCAA_h_
#define CATIPLMIndexCAA_h_

#include "CATBaseUnknown.h"
#include "GUIDCATPLMIndexInterfaces.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDCATPLMIndexInterfaces const IID IID_CATIPLMIndexCAA;
#else
extern "C" const IID IID_CATIPLMIndexCAA;
#endif

/**
 * @level Private
 * @usage U3
 */

/**
 * This class supplies methods to manage queries.
 * <b>role</b>: This class enables to get all information related to the query definition
 */

//---------------------------------------
// Includes
//---------------------------------------
#include "CATBaseUnknown.h"

#include  "CATListPtrCATIAdpPLMIdentificator.h" 
#include  "CATListPtrOfListPtrCATIAdpPLMIdentificator.h" 
#include  "CATListOfInt.h"


//---------------------------------------
// Forward declarations
//---------------------------------------
class CATIAdpPLMIdentificator; 


class ExportedByGUIDCATPLMIndexInterfaces CATIPLMIndexCAA : public CATBaseUnknown
{
    CATDeclareInterface;

public:
    /**
    * Apply a zone query.
    * <br><b>Role</b>: This method allows to retrieve all the occurrences matching a zone.
    * @param iRoot [in]
    *   Root of the product.
    * @param iZonePath [in]
    *   Path leading to the representation describing the zone. Expected format is Ref/Inst/Ref/Inst/../RepInst/Representation.
    * @param oListOfPaths [out]
    *   The list of occurrences matching the zone. The format is Ref/Inst/Ref/Inst/…/RepInst/Representation. Note that the first Ref of the path is the same as iRoot.
    *   Warning: QueryZone allocates memory to store oListOfPaths: Use ReleaseListOfList method  to free the memory once you no longer need oListOfPaths.
	* @param oAreCoGsIn [out]
    *   The list of ints that indicates if a result includes the input's center of gravity.
	* @param oIntersectionDepths [out]
    *   The list of ints that indicates the depth of the intersection between the input and the result path.
    * @param iPostFilterWithCoG [in]
    *   Whether the proximity query results will be tagged according to them including the center of gravity on the input, or not. Defaults to true.
	* @param iEstimateIntersectionDepth [in]
    *   Whether the proximity query results will be tagged according to the depth of intersection between them and the input. Defaults to true.
    * @return
    *   A HRESULT value.
    *   <br><b>Legal values</b>:
    *   <dl>
    *     <dt>S_OK</dt>
    *     <dd>All went well.</dd>
    *     <dt>E_FAIL</dt>
    *     <dd>An error occurred.</dd>
    *   </dl>
    */
    virtual HRESULT QueryZone(CATIAdpPLMIdentificator *iRoot, const CATListPtrCATIAdpPLMIdentificator &iZonePath, 
        CATListPtrOfListPtrCATIAdpPLMIdentificator& oListOfPaths, CATListOfInt& oAreCoGsIn, CATListOfInt& oIntersectionDepths,
		bool iPostFilterWithCoG=true, bool iEstimateIntersectionDepth=true) = 0;

	virtual HRESULT QueryZone(CATIAdpPLMIdentificator *iRoot, const CATListPtrCATIAdpPLMIdentificator &iZonePath, 
        CATListPtrOfListPtrCATIAdpPLMIdentificator& oListOfPaths) = 0;

	virtual HRESULT QueryZonePostFilterWithCoG(CATIAdpPLMIdentificator *iRoot, const CATListPtrCATIAdpPLMIdentificator &iZonePath, 
        CATListPtrOfListPtrCATIAdpPLMIdentificator& oListOfPaths, CATListOfInt& oAreCoGsIn) = 0;

	virtual HRESULT QueryZoneReturnIntersectionDepth(CATIAdpPLMIdentificator *iRoot, const CATListPtrCATIAdpPLMIdentificator &iZonePath, 
        CATListPtrOfListPtrCATIAdpPLMIdentificator& oListOfPaths, CATListOfInt& oIntersectionDepths) = 0;

    /**
    * Release memory for a list of list of CATIAdpPLMIdentificator.
    * <br><b>Role</b>: This has to be called when the list of paths is no longer necessary.
    * @param ioListOfPaths [in/out]
    *   List to clean.
    */
    virtual void ReleaseListOfList(CATListPtrOfListPtrCATIAdpPLMIdentificator &ioListOfPaths) = 0;

};

CATDeclareHandler(CATIPLMIndexCAA,CATBaseUnknown);

   /**
	 *  Create a CATIPLMIndexCAA object. If called severral times, this method returns the same object.
	 */
extern HRESULT ExportedByGUIDCATPLMIndexInterfaces Get3DIndexFactory(CATIPLMIndexCAA_var &oIndex);

#endif // CATIPLMIndexCAA_h_
