#ifndef CATIPLMIndexQuery_h_
#define CATIPLMIndexQuery_h_


#include "CATBaseUnknown.h"
#include "GUIDCATPLMIndexInterfaces.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATBoolean.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDCATPLMIndexInterfaces const IID IID_CATIPLMIndexQuery;
#else
extern "C" const IID IID_CATIPLMIndexQuery;
#endif

/**
 * @level Private
 * @usage U3
 */

/**
 * This class supplies methods to manage queries.
 * <b>role</b>: This class enables to set all information related to the query definition
 */

// Forward references
class CATMathVector;
class CATMathPoint;
class CATMathTransformation;
class CATIPLMAsmGeo_var;
class CATIPLMIndexResultProcessor;
class CATIPLMViewpoint_var;
class CATIPLMValueList_var;
class CATPLMID;
class CATIPLMIndexAttributeFilter_var;
class CATIPLMMultiVolume_var;
// Includes

class ExportedByGUIDCATPLMIndexInterfaces CATIPLMIndexQuery : public CATBaseUnknown
{
    CATDeclareInterface;

public:

    struct Stats
    {
        int _cpu;
        int _elapsed;
        CATUnicodeString m_StartTime;
        CATUnicodeString m_QueryName;
    };

   	/** Write the 3DQL Query.
	 *  Question marks refer to binary values that are set by SetParam (in order of calls)
	 *  If another query has been defined but not runned or deleted, returns E_FAIL.
	 */
	virtual HRESULT SetQuery(const CATUnicodeString &iQuery) = 0;

	/** Do not use, use SetParam(const double iDoubleValue) instead.
	 */
	virtual HRESULT SetParam(const float iFloatValue) = 0;

	/** Set the value associated to a question mark in the 3DQL expression.
	 */
	virtual HRESULT SetParam(const CATUnicodeString &iStr) = 0;

	/** Set the value associated to a question mark in the 3DQL expression.
	 */
	virtual HRESULT SetParam(const double iDoubleValue) = 0;

	/** Set the value associated to a question mark in the 3DQL expression.
	 */
	virtual HRESULT SetParam(const int iIntValue) = 0;
	
	/** Set the value associated to a question mark in the 3DQL expression.
	 */
	virtual HRESULT SetParam(const CATMathVector & iVectorValue) = 0;

	/** Set the value associated to a question mark in the 3DQL expression.
	 */
	virtual HRESULT SetParam(const CATMathPoint & iPointValue) = 0;
	
	/** Set the value associated to a question mark in the 3DQL expression.
	 */
	virtual HRESULT SetParam(const CATMathTransformation & iMatrixValue) = 0;
	
	/** Set the value associated to a question mark in the 3DQL expression.
	 */
	virtual HRESULT SetParam(const CATIPLMAsmGeo_var &ihAsmGeo) = 0;

	/** Set the value associated to a question mark in the 3DQL expression.
	 */
	virtual HRESULT SetParam(const CATIPLMViewpoint_var &ihViewpoint) = 0;

	/** Set the value associated to a question mark in the 3DQL expression.
	 */
	virtual HRESULT SetParam(const CATIPLMValueList_var &ihValueList) = 0;

	/** Set the value associated to a question mark in the 3DQL expression.
	 */
	virtual HRESULT SetParam(const CATPLMID &iID) = 0;

	/** Set the value associated to a question mark in the 3DQL expression.
	 */
	virtual HRESULT SetParam(const CATIPLMMultiVolume_var &iVolumes) = 0;

	// ... others SetParam

	/** Write the 3DQL Query.
	 *  Question marks refer to binary values that are set by SetParam (in order of calls)
	 *  If another query has been defined but not runned or deleted, returns E_FAIL.
	 */
	virtual HRESULT SetAttributeFilter(const CATUnicodeString &iAttrFilter) = 0;

	virtual HRESULT SetAttributeFilter(CATIPLMIndexAttributeFilter_var& ihAttributeFilter) = 0;

	/** Execute the query.
	 *  Returns S_OK if the query runs correctly.
	 *  Returns E_FAIL if the query is not initialized properly or if an unexpected error occured.
	 *    Then, errors can be retrieved using GetErrorMsgs() or GetErrorTags();
	 */
	virtual HRESULT RunQuery(CATIPLMIndexResultProcessor &ioProcessor, CATBoolean iResetCnx=FALSE) = 0;

	/** DEPRECATED: method will be removed.
	 *  @nodoc
	 */
	//virtual HRESULT Reset() = 0;

	/** Deprecated
	  * Use CATPLMIndexError
      *
	  */
	/** Get list of error messages.
	 *  oListMsgs must not be deleted.
	 */
	virtual HRESULT GetErrorMsgs(const CATListOfCATUnicodeString *&oListMsgs) = 0;

	/** Deprecated
	  * Use CATPLMIndexError
      *
	  */
	/** Get list of error keys.
	 *  oListKeys must not be deleted.
	 */
	virtual HRESULT GetErrorKeys(const CATListOfCATUnicodeString *&oListKeys) = 0;

	/** Get 
	 *  oListKeys must not be deleted.
	 */
	virtual HRESULT GetStats(Stats& oStats) = 0;

};

CATDeclareHandler(CATIPLMIndexQuery,CATBaseUnknown);


#endif // CATIPLMIndexQuery_h_
