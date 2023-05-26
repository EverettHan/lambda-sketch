#ifndef CATIPLMIndex_h_
#define CATIPLMIndex_h_


#include "CATBaseUnknown.h"
#include "GUIDCATPLMIndexInterfaces.h"
#include "CATUnicodeString.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDCATPLMIndexInterfaces const IID IID_CATIPLMIndex;
#else
extern "C" const IID IID_CATIPLMIndex;
#endif

/**
 * @level Private
 * @usage U3
 */

/**
 * This class supplies methods to manage queries.
 * <b>role</b>: This class enables to get all information related to the query d
efinition
 */

// Forward references
class CATIPLMAsmGeo_var;
class CATIPLMViewpoint_var;
class CATIPLMIndexQuery_var;
class CATIPLMValueList_var;
class CATPLMID;
class CATIPLMIndexAttributeFilter_var;
class CATIPLMMultiVolume_var;
class CATIPLMIndexQueryServices_var;

// Includes
enum IndexServerAvailability
{
    NotInstalled=0,
    Installed,
    Available
};

class ExportedByGUIDCATPLMIndexInterfaces CATIPLMIndex : public CATBaseUnknown
{
    CATDeclareInterface;

public:
	/**
	 *  Create an AsmGeo object.
	 */
    virtual HRESULT CreateAsmGeo(CATIPLMAsmGeo_var &oAsmGeo)  = 0;

    /**
	 *  Create an Index Query object.
	 */
	virtual HRESULT CreateIndexQuery(CATIPLMIndexQuery_var &oQuery) = 0;

	/**
	 *  Create a Viewpoint object (for Visu on Index Query).
	 */
	virtual HRESULT CreateViewpoint(CATIPLMViewpoint_var &oViewpoint) = 0;

	/**
	 *  Create a List object.
	 */
	virtual HRESULT CreateList(CATIPLMValueList_var &oValueList) = 0;

	/**
	 *  Create an attribute filter object.
	 */
	virtual HRESULT CreateAttributeFilter(CATIPLMIndexAttributeFilter_var &oAttributeFilter) = 0;
	
    /**
	 *  Create a multi volume object.
	 */
	virtual HRESULT CreateMultiVolume(CATIPLMMultiVolume_var &oMultiVolume) = 0;

	/**
	 *	Check the existence of a query in the server
	 */
	virtual HRESULT TestQueryExistence(const CATUnicodeString &iQuery, bool &oExists) = 0;

	/**
	 * Check if the IndexBridgeProcessorTxt is used
	 */
	virtual HRESULT TestIndexBridgeProcessorTxt() = 0;

	/**
	 * Check if index server is installed
	 * IndexServerAvailability is an enmu: NotInstalled, Installed, Available
	 * RC : S_OK, query succeeded 
	 *      E_FAIL, failed to query index server
	 */
	virtual HRESULT TestIndexServerAvailability(IndexServerAvailability &oIndexServerStatus) = 0;

    /** @nodoc */
	virtual HRESULT StartSession() = 0;
    virtual HRESULT StopSession() = 0;
};

CATDeclareHandler(CATIPLMIndex,CATBaseUnknown);

   /**
	 *  Create a CATIPLMIndex object. If called severral times, this method returns the same object.
	 */
extern HRESULT ExportedByGUIDCATPLMIndexInterfaces GetPLMIndexFactory(CATIPLMIndex_var &oIndex);




#endif // CATIPLMIndex_h_
