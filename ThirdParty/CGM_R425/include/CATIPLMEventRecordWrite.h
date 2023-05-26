//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATIPLMEventRecordWrite
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
* @level Protected
* @usage U3
*/

#ifndef CATIPLMEventRecordWrite_H
#define CATIPLMEventRecordWrite_H

#include "CATPLMServicesItf.h"//ExportedBy

#include "CATBaseUnknown.h"

class CATPLMTEvent;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMEventRecordWrite;
#else
extern "C" const IID IID_CATIPLMEventRecordWrite ;
#endif

class ExportedByCATPLMServicesItf CATIPLMEventRecordWrite: public CATBaseUnknown
{
    CATDeclareInterface;
public:
    /**
	* @nodoc
    */
    virtual HRESULT AddEvent(CATPLMTEvent *iEvent) =0;
};
#endif
