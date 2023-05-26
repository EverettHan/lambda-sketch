#ifndef CATIPLMViewpoint_H
#define CATIPLMViewpoint_H

// Includes
#include "GUIDCATPLMIndexInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDCATPLMIndexInterfaces const IID IID_CATIPLMViewpoint;
#else
extern "C" const IID IID_CATIPLMViewpoint ;
#endif

/**
 * @level Private
 * @usage U3
 */

class CAT3DViewer;
class CATMathPointf;
class CATMathDirectionf;
class CAT3DViewpoint;
class CATSupport;

/**
 * This class supplies CATIPLMViewpoint.
 * <b>role</b>: CATIPLMViewpoint defines the viewpoint parameters for Visu on Index Queries
 * WARNING: A single instance of a viewpoint must be used to perform visibility queries for a scene.
 * Then, to perform visu process, one should perform many visu queries (see CATIPLMIndex_TypeQuery::QueryVisu)
 * using <b>only one</b> CATIPLMViewpoint for all queries.
 * Else, using one CATIPLMViewpoint for each QueryVisu, objects will be missed.
 */
class ExportedByGUIDCATPLMIndexInterfaces CATIPLMViewpoint: public CATBaseUnknown
{
  CATDeclareInterface;

public:
	virtual CATUnicodeString ToJsonString() = 0;
	/** Sets VP parameters from 3DViewer */
    virtual HRESULT Reset(CAT3DViewer* iViewer) = 0;
	/** Sets VP parameters from 3DViewpoint and CATSupport */
	virtual HRESULT Reset(CAT3DViewpoint* iViewpoint, const CATSupport& iSupport) = 0;
    /** Tell if server can refine query. */
    virtual CATBoolean isVisuFinished() = 0;
	/** DO NOT USE: Will be removed soon
	 *  @nodoc */
	virtual void SetPass(int iPass) = 0;
	/** DO NOT USE: Will be removed soon
	 *  @nodoc */
	virtual int GetPass() = 0;
};

CATDeclareHandler(CATIPLMViewpoint, CATBaseUnknown);


//------------------------------------------------------------------

#endif //CATIPLMViewpoint
