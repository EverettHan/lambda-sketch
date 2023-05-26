// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMVersioningAdapter.h
// Define the CATPLMVersioningAdapter interface
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMVersioning
//
//===================================================================
//
// Feb 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMVersioningAdapter_H
#define CATPLMVersioningAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedBy

#include "CATIPLMVersioning.h"

class ExportedByCATPLMImplAdapterClass CATPLMVersioningAdapter : public CATIPLMVersioning
{
public:
    CATPLMVersioningAdapter();
    virtual ~CATPLMVersioningAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT RetrieveVersions (const CATLISTV(CATPLMID) &iInputList, CATIPLMCompVersioningService::QueryMode iQueryMode, CATIPLMCompVersioningService::StabilityMode iStabilityMode, CATIPLMCompVersioningService::OrderingMode iOrderingMode, CATLISTP (CATIPLMCompResultVersion)& oResultsVersion);

    /** 
    * @nodoc
    */
    virtual HRESULT CheckVersion (const CATLISTV(CATPLMID) &iPLMIDList, CATIPLMCompVersioningService::VersionState iState, CATListOfInt* oResultList);


    /** 
    * @nodoc
    */
    virtual HRESULT GetSpecialMinorModifiedAfter (const CATTime &iDate, CATIPLMRecordReadSet *&oResultsVersion);

private:
    CATPLMVersioningAdapter (CATPLMVersioningAdapter &);
    CATPLMVersioningAdapter& operator=(CATPLMVersioningAdapter&);
};

#endif
