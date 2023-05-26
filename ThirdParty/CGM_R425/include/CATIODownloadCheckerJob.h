#ifndef CATIODownloadCheckerJob_h_
#define CATIODownloadCheckerJob_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATIOJob.h"
#include "CATRep.h"
#include "CATCompModelIdentification.h"
#include "CATSGPLMHelper.h"

class CATIODownloadCheckerJob : public CATIOJob
{
public:
    CATIODownloadCheckerJob(CATCompModelIdentificationPtr iModelIdentification, CATIOJob* iContinuation = NULL) :
        _modelIdentification(iModelIdentification)
    {
        _SetContinuation(iContinuation);
    }

    virtual CATIOJob* GetContinuation()
    {
        return _continuation.GetContinuation();
    }

    void* GetResult(int& oSize)
    {
        oSize = 0;
        return nullptr;
    }

private:

    void _Reset()
    {
        ForceState(CATEIOJobStatePending);
    }

    void _Execute(CATIOJob* iParentJob)
    {
        CATSGPLMHelperPtr& plmHelper = CATSGContext::Get(0).GetSGPLMHelper();
        if (plmHelper.IsValid()) {
            if (FAILED(plmHelper->StreamTo(_modelIdentification, 1.0f))) { // <- We want to download this. Notify the CATSGPLMHelper
                _Reset(); // <- The StreamTo failed -> reset job
                return;
            }
            ForceState(CATEIOJobStateIdle);
        }
    }

    virtual HRESULT     _SetContinuation(CATIOJob* iJob) { return _continuation.SetContinuation(iJob); }
    virtual HRESULT     _SetDeleter(CATIOJob* iJob)  { return E_NOTIMPL; }
    virtual HRESULT     _SetScheduler(CATIOJob* iJob)  { return E_NOTIMPL; }

    CATIOJobContinuationPolicy      _continuation;
    CATCompModelIdentificationPtr   _modelIdentification;
};

#endif // end of #ifdef SG_COMPOSITES_MULTIOS

#endif // end of #ifndef CATIODownloadCheckerJob_h_
