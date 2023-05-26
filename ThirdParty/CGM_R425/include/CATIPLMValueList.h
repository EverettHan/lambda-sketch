#ifndef CATIPLMValueList_h_
#define CATIPLMValueList_h_


#include "CATBaseUnknown.h"
#include "GUIDCATPLMIndexInterfaces.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDCATPLMIndexInterfaces const IID IID_CATIPLMValueList;
#else
extern "C" const IID IID_CATIPLMValueList;
#endif

/**
 * @level Private
 * @usage U3
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
class CATUnicodeString;
class CATIPLMMultiVolume_var;

// Includes

class ExportedByGUIDCATPLMIndexInterfaces CATIPLMValueList : public CATBaseUnknown
{
    CATDeclareInterface;

  public:
   	/** Do not use, use Add(const double iDoubleValue) instead.
	 */
	virtual HRESULT Add(const float iFloatValue) = 0;

	/** Set the value associated to a question mark in the 3DQL expression.
	 */
	virtual HRESULT Add(const double iDoubleValue) = 0;

	/** Set the value associated to a question mark in the 3DQL expression.
	 */
	virtual HRESULT Add(const int iIntValue) = 0;
	
	/** Set the value associated to a question mark in the 3DQL expression.
	 */
	virtual HRESULT Add(const CATMathVector & iVectorValue) = 0;

	/** Set the value associated to a question mark in the 3DQL expression.
	 */
	virtual HRESULT Add(const CATMathPoint & iPointValue) = 0;
	
	/** Set the value associated to a question mark in the 3DQL expression.
	 */
	virtual HRESULT Add(const CATMathTransformation & iMatrixValue) = 0;

	/** Set the value associated to a question mark in the 3DQL expression.
	 */
	virtual HRESULT Add(const CATIPLMValueList_var &ihValueList) = 0;

	/** Set the value associated to a question mark in the 3DQL expression.
	 */
	virtual HRESULT Add(const CATPLMID& iID) = 0;

	/** Set the value associated to a question mark in the 3DQL expression.
	 */
	virtual HRESULT Add(const CATUnicodeString &iStr) = 0;

	/** Set the value associated to a question mark in the 3DQL expression.
	 */
	virtual HRESULT Add(const CATIPLMMultiVolume_var& ihMultiVolume) = 0;

	/** Check if the ValueList is empty or not
	 *  Returns TRUE if it is empty
	 *  Returns FALSE if it is not empty
	 */
	virtual CATBoolean IsEmpty() = 0;
};

CATDeclareHandler(CATIPLMValueList,CATBaseUnknown);


#endif // CATIPLMValueList_h_
