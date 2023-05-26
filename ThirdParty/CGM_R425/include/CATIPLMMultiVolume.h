#ifndef __CATIPLMMultiVolume_H_
#define __CATIPLMMultiVolume_H_


#include "CATBaseUnknown.h"
#include "GUIDCATPLMIndexInterfaces.h"
#include "CATUnicodeString.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDCATPLMIndexInterfaces const IID IID_CATIPLMMultiVolume;
#else
extern "C" const IID CATIPLMMultiVolume;
#endif

/**
 * @level Private
 * @usage U3
 */

enum IDX_VOLUME_MODE
{
    /** STANDARD*/
    IDX_MODE_STANDARD = 0, 
    /** FULLY IN*/
    IDX_MODE_FULLYIN = 1, 
    /** FULLY OUT*/
    IDX_MODE_FULLYOUT = 2, 
    /** PARTLY IN*/
    IDX_MODE_PARTLYIN = 3, 
    /** PARTLY OUT*/
    IDX_MODE_PARTLYOUT = 4
};

enum VOLUME_CONDITION_TYPE 
{
    IDX_CONDITION_OR = 0,
	IDX_CONDITION_AND = 1
};

// Forward references
class CATMathPoint;
class CATMathTransformation;
class CATPLMID;

/**
 * This class supplies methods to manage queries.
 * <b>role</b>: This class enables to get all information related to the query d
efinition
 */

class ExportedByGUIDCATPLMIndexInterfaces CATIPLMMultiVolume : public CATBaseUnknown
{
    CATDeclareInterface;

public:
    virtual void    Reset() = 0;

	virtual CATUnicodeString ToJsonString() = 0;

	virtual CATUnicodeString handleIntersectionMode(IDX_VOLUME_MODE iMode) = 0;

    virtual HRESULT SetConditionType(VOLUME_CONDITION_TYPE iCond)  = 0;

    virtual HRESULT AddBox(const CATMathPoint& iMin, const CATMathPoint& iMax, const CATMathTransformation& iPos, IDX_VOLUME_MODE iMode, bool iIsInversed)  = 0;
    
    virtual HRESULT AddSphere(const CATMathPoint& iCenter, float iRadius, IDX_VOLUME_MODE iMode, bool iIsInversed)  = 0;
    
    virtual HRESULT AddShape(const CATPLMID& iObjectID, const CATMathTransformation& iPos, float iClearance, IDX_VOLUME_MODE iMode, bool iIsInversed)  = 0;

	virtual HRESULT AddShape(const CATPLMID& iObjectID, const CATMathTransformation& iPos, float iClearance, IDX_VOLUME_MODE iMode, bool iIsInversed, bool iPostFilterWithCoG, bool iEstimateIntersectionDepth)  = 0;

	/**
	 * Add an intermediate node for a multi-shape query.
	 *	All the representations under the input node will be retrieved and added to the filter.
	 *	If the input node belongs to the AsmGeo used for the query, the same filters (config,...) will be applied when
	 *	retrieving the shapes; otherwise, no filter will be applied.
	 * @param iObjectPath [IN]
	 *		RIII path of the intermediate node.
	 * @param iClearance [IN]
	 *		Multi-shape expansion (applied to each shape under the input node)
	 * @param iMode [IN]
	 *		Intersection mode : Only PARTLYIN is available in this case !
	 */
	virtual HRESULT AddMultiShape(const CATPLMID& iObjectPath, float iClearance, IDX_VOLUME_MODE iMode, bool iIsInversed) = 0;  
};

CATDeclareHandler(CATIPLMMultiVolume,CATBaseUnknown);

#endif // CATIPLMMultiVolume
